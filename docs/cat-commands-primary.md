# CAT primary commands — firmware details (MAIN V01-12)

Per-command firmware analysis of the 104 entries in `cat_mnemonics` @ 0xFFF805EC (T09b). Overview, the extended/service commands and the manual comparison are in [cat-commands.md](cat-commands.md); parser, reply buffer and AI are in [code/main/cat.md](code/main/cat.md).

Conventions [fact]: handler(text, is_set) where text[0..1] is the mnemonic and text[2] the first parameter; replies are built at 0x1C8E with length in 0x1B788; `?;` = error flag 0x464A. Rows were produced by reading `decomp/main` (four parallel read-only passes) and spot-checked against the disassembly where marked; behaviour sentences carry their own [fact]/[inference]/[guess] tags. The manual line is a paraphrase of rev 2306-C (2211-A for EO). Open points needing disassembly are listed per command. "Dirty flag" in the rows below means 0x20F10. T10g showed it is a **frequency-cache refresh request** for `freq_cache_update` (set by about 90 functions), not a settings-dirty flag [fact] (see [code/main/radio-control.md](code/main/radio-control.md)); EEPROM saving is described in [code/main/eeprom.md](code/main/eeprom.md).

### AB

- **Index / handler:** 0, cat_AB @ fffa646d; switch case fffa3b8c; length tests `len==3:cat_AB@fffa646d` [fact]
- **Manual 2306-C:** VFO-A TO VFO-B. Set `AB;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Set parameters (firmware):** none
- **Class:** action
- **Behaviour:** Copies the VFO-A data block (0x5A bytes at 0x9D09) into the VFO-B block (0x9D63), sets VFO-B state 0x9DBF=1 and applies it; i.e. A=>B copy [fact for copy, name inference].
- **Globals / callees:** R: guard flags (busy/lockout guard (any true -> '?;'): DAT_20f0c!=0, 20b8a==1, 20b3d!=0, 20cce==1, 20f1b==1, 20ccd==1, 20b7c!=0, 20cd0==1, 20cd1==1, 20f11==1, 20b98==1); `vfo_tune_locked`(1) (error if B is in a special state); W: 0x9D63..+0x5A, 0x9DBF=1, 0x20F10=1 (frequency-cache refresh request, see [radio-control.md](code/main/radio-control.md)); callees `vfo_mark_edited`(1), `vfo_store_back`(1)
- **Risk:** low-medium: changes VFO-B contents (RAM + dirty flag)
- **Resolved in part (#157):** `vfo_store_back` stores the operating record back to where it came from, by state: the band stack (`FUN_fffc17df`), a pending copy (+0x443/+0x43D), or the memory-tune backup for states 3/4 (memory tune, PMS) **[fact]**.
- **Resolved (#173):** `vfo_store_back` does **not** retune. Every path ends in a store: `bandstack_save` @ fffc1927 (record → band-stack slot, `eeprom_save_bandstack` only if the 0x5A bytes differ), the memory-tune backup (`FUN_fffc18e1` → `memtune_backup_b` @ fffc1913, 0x9D63 → 0x9E28, UI +0x440/+0x442 = 1; or `FUN_fffc1a35` @ fffc1a35, a partial copy to 0x9E28 and UI +0x43F = 1), or nothing in state 2; none of `FUN_fffc184f`, `FUN_fffc18bf`, `FUN_fffc18e1` calls `vfo_reload`/`vfo_retune` **[fact]**. `cat_AB` itself also calls no retune; the new B frequency reaches the hardware only through the 0x20F10 frequency-cache refresh request it sets **[fact for the code, inference that this is the retune path]**. Quirk: `bandstack_save` takes no side argument and saves the record of the **active** VFO (0x9DBD), so `vfo_store_back(1)` from `AB` while VFO-A is active rewrites A's band-stack slot (a no-op unless A changed), not B's **[fact, current decompile]**; B's slot then follows on the next store with B active **[inference]**.

### AC

- **Index / handler:** 1, cat_AC @ fffa65d4; switch case fffa3ba1; length tests `len==3:cat_AC@fffa65d4 \| len==6:cat_AC@fffa65d4` [fact]
- **Manual 2306-C:** ANTENNA TUNER CONTROL. Set `ACP1P2P3;` (6), read `AC;` (3), answer `ACP1P2P3;` (6), AI O. P1 0 fixed; P2 0 int/ext tuner,1 -,2 ATAS; P3 (P2=0) 0 off (tuning stop),1 on,2 -,3 tuning start (2306-C; 2211-A had 2=start); (P2=2 ATAS) 0 stop,1 freq up 50ms,2 freq down 50ms,3 start
- **Read / answer (firmware):** AC0<P2><P3>; (len 6). P2='2' if DAT_9AB8==3 else '0'. If 9AB8==3: P3 '0' when 0x20F0C==0; 0x20F0C==2 -> '1' if 0x20B3C==2 / '2' if ==3; 0x20F0C==1 -> '3'. Else P3='3' if 0x20B41==2 else hexdigit(FUN_fffec55a = bit2 of byte+1 of VFO block)
- **Set parameters (firmware):** P1 must be '0' (else error). Pre-check key_event_filter(0x301,0) must allow else error. Case 9AB8 in 0,1 and P2 '0': P3 '0'-> FUN_fffec537(0), 20B3F=3; '1'-> fffec537(1), 20B3F=1; '3'-> if 20B3D==0 then 20B41=1. Case 9AB8==2 and P2 '0': P3 '0'->20B3F=6,fffec537(0); '1'->20B3F=4,fffec537(1); '3'->20B40=1. P2 '2' only if 9AB8==3: P3 '0'->FUN_fffed24e(0); '1'->fffed206(2)+fffed24e(1); '2'->fffed206(2)+fffed24e(2); '3'->fffed206(1). P2 '1' accepted silently (no effect). Anything else -> error. Then FUN_fffe6e26 (timer 0x32/200 + flag 0x1B299)
- **Class:** read+set
- **Behaviour:** Antenna-tuner style control: P3=0/1 clear/set a tuner-enable bit, P3=3 requests a tune cycle (0x20B41=1 / 0x20B40=1 / 0x20F0C=1) [inference, from state vars 20F0C/20B3C/20B41]; key-event gate 0x301 [fact].
- **Globals / callees:** R/W 0x9AB8, 0x20F0C, 0x20B3C, 0x20B3D, 0x20B3F, 0x20B40, 0x20B41, VFO block+1 bit2; callees fffb44f7(0x301), fffec537, fffed24e, fffed206, fffec55a, fffe6e26
- **Risk:** high: P3=3 (and P2=2 P3=1/2/3) can start an antenna-tune cycle which keys the transmitter [inference]
- **Resolved (#69):** the tuner code keys TX through PTT source 10 (0x20B2D, set by `FUN_fffec7f9`/`FUN_fffed48f`/`FUN_fffed8ab`; [code/main/tx-protection.md](code/main/tx-protection.md)) **[fact]**. 0x9AB8 is the menu item **TUNER TYPE SELECT** (`EX030104`, 0..3) **[fact]**; the meaning of each value is in the operating manual's menu chart.

### AG

- **Index / handler:** 2, cat_AG @ fffa6867; switch case fffa3bd9; length tests `len==4:cat_AG@fffa6867 \| len==7:cat_AG@fffa6867` [fact]
- **Manual 2306-C:** AF GAIN. Set `AGP1P2P2P2;` (7), read `AGP1;` (4), answer `AGP1P2P2P2;` (7), AI O. P1 0 fixed; P2 000-255
- **Read / answer (firmware):** AG0nnn; (len 7). 1c90=P1 echoed from command; nnn = byte 0x20BA8 as 3-digit decimal 000-255
- **Set parameters (firmware):** P1 (1 char, echoed, not validated), nnn 3 decimal digits 000-999 -> low 8 bits (wraps mod 256) -> 0x20BA8. Non-digit in nnn -> error (value not stored). No range check.
- **Class:** read+set
- **Behaviour:** Gets/sets an 8-bit level held in 0x20BA8 [fact]; no apply call here so just a RAM variable [inference: consumed by another task; AF-gain-like level unknown].
- **Globals / callees:** R/W 0x20BA8
- **Risk:** low: single RAM byte, no dirty flag
- **Resolved (#69):** 0x20BA8 is UI-state +0xA4, the **AF GAIN** value (encoder/pot id 5 from the DISPLAY). `FUN_fffb5d68` turns it into the speaker/phones levels on /SST2 channels 1 and 5 through table 0xFFF81362 ([code/main/tx-protection.md](code/main/tx-protection.md), #143) **[fact]**.

### AI

- **Index / handler:** 3, cat_AI @ fffa6946; switch case fffa3c15; length tests `len==3:cat_AI@fffa6946 \| len==4:cat_AI@fffa6946` [fact]
- **Manual 2306-C:** AUTO INFORMATION. Set `AIP1;` (4), read `AI;` (3), answer `AIP1;` (4), AI X. P1 0 off,1 on (per CAT-1/2/3; reset to 0 at power off)
- **Read / answer (firmware):** AIn; (len 4). n = hexdigit of the per-port AI flag: port id (0x464C) 3->0x20B22, 2->0x20B21, 1->0x20B20
- **Set parameters (firmware):** P1 one char: if char > '1' (0x31) -> error (so '0' or '1' and also any char below '0', which would store 0xFF from hex2nib). Stored value = hex2nib(char). Only the port that sent the command is changed. If P1=='1' then cat_ai_holdoff (timer 0x32/200 + flag 0x187C2=1 -> auto-information refresh).
- **Class:** read+set
- **Behaviour:** Per-port Auto-Information on/off flag [fact]; setting 1 triggers an immediate AI update push [inference].
- **Globals / callees:** R/W 0x20B20/21/22; 0x464C port id; callee fffddb6a
- **Risk:** low: transport/UI state only

### AM

- **Index / handler:** 4, cat_AM @ fffa6a26; switch case fffa3c4d; length tests `len==3:cat_AM@fffa6a26` [fact]
- **Manual 2306-C:** VFO-A TO MEMORY CHANNEL. Set `AM;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Set parameters (firmware):** none
- **Class:** action
- **Behaviour:** Stores the VFO-A data block into memory channel (number 0x60C9) in RAM (0x6150+ch*0x5A) and writes it to EEPROM; A=>Memory [name inference; copy and EEPROM write are facts].
- **Globals / callees:** R: 0x60C9 (error if in 0x75..0x84), 0x9DBE state (1,3,4,5,else), 0x9DC3, 0x60B1[], 0x9D09; W: 0x6150+ch*0x5A (0x5A), 0x9D09 (states 1? no: 4 and default), 0x20F10; callees `vm_toggle` (state 4), `vfo_mark_edited`/fffc16f6(0x9DBD), eeprom_save_memch(ch) = eeprom_write(0x1A7A,&0x60C9,0x87) + eeprom_write(slot,0x5A)
- **Risk:** medium: overwrites a memory channel in EEPROM (user data)
- **Resolved (#157, #173):** the band-stack records are at 0x4761 + level·0x438 + band·0x5A for VFO A and 0x5409 + … for VFO B, with the current stack level per band in 0x60B1[band] / 0x60BD[band] (the same addressing `align_load_preset` and `bandstack_save` @ fffc1927 use; the #157 note had band and level swapped) **[fact]**. `vm_toggle` @ fffbf41f is the V/M key: unless UI +0x97 (0x20B9B) is 1 (then it only clears +0x97/+0x90, `FUN_fffc2794`), it cancels a keyer/message send (`FUN_fffe3d24`), runs `vm_toggle_core` @ fffc27ad and re-arms the tuner (`FUN_fffec578`) **[fact]**. For state 4 (PMS) `vm_toggle_core` stores the record back (`vfo_store_back`), sets state 2 (`vfo_enter_mem_state` @ fffc28fb), clears the memory-tune flags (`FUN_fffc2937`) and reloads (`vfo_reload`) **[fact]**. So `AM` in PMS first drops back to the memory channel, then stores VFO-A's band-stack record (not the PMS-tuned frequency) into the channel and into 0x9D09 **[fact for the copies; reading as "leave PMS first" is inference]**. By state: 1 (VFO) stores the live record 0x9D09; 3 (memory tune) stores the band-stack slot into the channel only; 2 and every other state store the slot into the channel and also load it into 0x9D09; 5 (QMB) stores the slot and writes EEPROM at once, skipping `vfo_mark_edited`/`vfo_store_back`/0x20F10 **[fact]**. `vm_toggle` works on the **active** side (0x9DBD), see `BM`.

### AO

- **Index / handler:** 5, cat_AO @ fffa6b6f; switch case fffa3c62; length tests `len==3:cat_AO@fffa6b6f \| len==6:cat_AO@fffa6b6f` [fact]
- **Manual 2306-C:** AMC OUTPUT LEVEL. Set `AOP1P1P1;` (6), read `AO;` (3), answer `AOP1P1P1;` (6), AI O. P1 001-100
- **Read / answer (firmware):** AOnnn; (len 6). nnn = byte 0x9BF2 as 3-digit decimal
- **Set parameters (firmware):** nnn 3 decimal digits, valid 001-100 (0 or >100 -> error, nothing stored). Stores 0x9BF2; if 0x9ACE==0: 0x20CC6=0x28, FUN_fffc8cbb(0x28)+FUN_fffc8d8c() queue parameter update (`swtimer_start`(0x39,val)).
- **Class:** read+set
- **Behaviour:** Level 1-100 stored at 0x9BF2 and pushed to a peripheral/DSP as parameter id 0x28 [fact for plumbing; function unknown].
- **Globals / callees:** R/W 0x9BF2; 0x9ACE gate; 0x20CC6; fffc8cbb, fffc8d8c, fffb237a(0x39)
- **Risk:** low: level setting
- **Resolved (#157):** `FUN_fffc8cbb(id)` is the **pop-up duration** lookup: it returns the display time of on-screen pop-up `id` for the DISPLAY SETTING **POP-UP TIME** (0x9B0E, 0..2); for ids 0x28, 0x29, 0x2A and 0x32 that is 800 / 1000 / 1200 (timer units) **[fact, ROM tables at 0xFFF834D6]**. So the "menu id" is the id of the level pop-up the DISPLAY shows (0x28 for this command).

### AS

- **Index / handler:** 6, cat_AS @ fffa6c9d; switch case fffa3c9a; length tests `len==4:cat_AS@fffa6c9d \| len==7:cat_AS@fffa6c9d` [fact]
- **Manual 2306-C:** AESS. Set `ASP1P2P2P2;` (7), read `ASP1;` (4), answer `ASP1P2P2P2;` (7), AI X. P1 1 AESS level,2 AESS-CF; P2 (P1=1) 000-100; (P1=2) 001=700Hz,002=1000Hz
- **Read / answer (firmware):** AS1nnn; nnn = (byte at *FUN_fffb54a0)*5 as 3 decimals; AS2001; or AS2002; (001 if *FUN_fffb552c==0, 002 if ==1). 1c90=P1 echoed. len 7
- **Set parameters (firmware):** P1 '1': nnn 3 decimal digits (idx3..5) <=100 else error; stored nnn/5 into *FUN_fffb54a0; if 0x9ACE==0 queue param 0x33. P1 '2': idx3,4 must be '0','0' else error; idx5 '1' -> *FUN_fffb552c=0, '2' -> =1, else error; if 0x9ACE==0 queue param 0x58. Other P1 -> error (read and set).
- **Class:** read+set
- **Behaviour:** Two parameters selected by P1: P1=1 a 0-100 level in steps of 5, P1=2 a 2-state selector (1/2) [fact]; meaning unknown.
- **Globals / callees:** FUN_fffb54a0, fffb552c (return pointers; decompiler lost them), fffb3196(0), 0x9ACE, 0x20CC6, fffc8cbb(0x33/0x58)
- **Risk:** low: DSP/audio-style setting
- **Resolved (#157):** `FUN_fffb54a0` / `FUN_fffb552c` return a **pointer to the active mode's AESS byte** (by `vfo_mode`(0)): level at 0x9C06 (SSB), 0x9C09 (CW), 0x9C0A (DATA-L/U), 0x9C0B (RTTY), 0x9C0C (DATA-FM), 0x9C0D (PSK), 0x9C0E (AM), 0x9C0F (FM); centre at 0x9C07 (SSB), 0x9C10 (CW), 0x9C11, 0x9C12, 0x9C13, 0x9C14 (PSK), 0x9C15 (AM), 0x9C16 (FM) **[fact]**. They sit in the front-panel block 0x9BC9..0x9C34 ([code/main/eeprom.md](code/main/eeprom.md)). The level is applied on the analog side, not in the DSP: 0 selects the external speaker alone, non-zero both speakers and sets R2A20178 channel 8 from it (`speaker_route`, [code/main/peripherals.md](code/main/peripherals.md#speaker-routing-speaker_route-0x20fcc-fact)) **[fact, #203]**. ROM defaults: SSB, AM and FM 10 (`AS1050`), the other modes 0.

### AV

- **Index / handler:** 7, cat_AV @ fffa6edc; switch case fffa3cd6; length tests `len==3:cat_AV@fffa6edc \| len==6:cat_AV@fffa6edc` [fact]
- **Manual 2306-C:** ANTI VOX LEVEL. Set `AVP1P1P1;` (6), read `AV;` (3), answer `AVP1P1P1;` (6), AI O. P1 001-100
- **Read / answer (firmware):** AVnnn; (len 6). nnn = 0x9BF6 if 0x9AF3==0 else 0x9BF7, 3-digit decimal
- **Set parameters (firmware):** nnn 3 decimal digits 000-100 (>100 -> error); stored to 0x9BF6 (9AF3==0) or 0x9BF7; if 0x9ACE==0 queue param 0x2B.
- **Class:** read+set
- **Behaviour:** Level 0-100 stored in one of two bytes chosen by flag 0x9AF3 and pushed as parameter 0x2B [fact]; meaning unknown.
- **Globals / callees:** R/W 0x9BF6/0x9BF7, 0x9AF3, 0x9ACE, 0x20CC6
- **Risk:** low: level setting

### BA

- **Index / handler:** 8, cat_BA @ fffa7018; switch case fffa3d0e; length tests `len==3:cat_BA@fffa7018` [fact]
- **Manual 2306-C:** VFO-B TO VFO-A. Set `BA;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Set parameters (firmware):** none
- **Class:** action
- **Behaviour:** Copies VFO-B data block (0x9D63) into VFO-A block (0x9D09), sets A state 0x9DBE=1 and applies it; B=>A [fact for copy].
- **Globals / callees:** Guard flags (busy/lockout guard (any true -> '?;'): DAT_20f0c!=0, 20b8a==1, 20b3d!=0, 20cce==1, 20f1b==1, 20ccd==1, 20b7c!=0, 20cd0==1, 20cd1==1, 20f11==1, 20b98==1); `vfo_tune_locked`(0)==1 -> error; W 0x9D09..+0x5A, 0x9DBE=1, 0x20F10=1; fffc2fde(0), fffc16f6(0)
- **Risk:** low-medium: changes VFO-A contents

### BC

- **Index / handler:** 9, cat_BC @ fffa717f; switch case fffa3d23; length tests `len==4:cat_BC@fffa717f \| len==5:cat_BC@fffa717f` [fact]
- **Manual 2306-C:** AUTO NOTCH (DNF). Set `BCP1P2;` (5), read `BCP1;` (4), answer `BCP1P2;` (5), AI O. P1 0 fixed; P2 0 off,1 on
- **Read / answer (firmware):** BC0n; (len 5). n = bit7 of a per-mode byte in the VFO block (offset by mode index m=`vfo_mode`(0)&0xF: m2-3 ->+0x15; m4-5 ->+0x33; m12-13 ->+0x1F; m8-9,14 ->+0x29; m0-1 ->+0x0B); m6-7,10-11 -> error
- **Set parameters (firmware):** P1 must be '0'; n via hex-parse: '0' clears bit7, '1' sets bit7, other -> error; same per-mode offsets; modes 6-7 and 10-11 -> error. No dirty flag / no apply call.
- **Class:** read+set
- **Behaviour:** Per-mode on/off flag (bit 7) in the VFO data block [fact]; specific feature unknown (supported in modes 0-5,8,9,12-14).
- **Globals / callees:** `vfo_rec_ptr`(0) (VFO block ptr), fffb3196(0) (mode)
- **Risk:** low: UI/DSP flag bit
- **Resolved (#157):** `vfo_rec_ptr`/`vfo_mode`(0) return the **active** VFO (0x9DBD: 0 = A record 0x9D09, 1 = B 0x9D63); with argument 1 they return the **TX** VFO, i.e. the other VFO while split (0x9C5E) is on. `vfo_mode` returns 2 (CW-L) during tune/EXT-PA cycles (0x20F0C, 0x20B40, 0x20B41, 0x20B25) **[fact, current decompile]**. Mode index = LSB, USB, CW-L, CW-U, AM, AM-N, FM, FM-N, DATA-L, DATA-U, DATA-FM, D-FM-N, RTTY-L, RTTY-U, PSK (0..14; the DISPLAY's mode name table and the `cat_NA` cases) **[fact]**.

### BD

- **Index / handler:** 10, cat_BD @ fffa72d9; switch case fffa3d5f; length tests `len==4:cat_BD@fffa72d9` [fact]
- **Manual 2306-C:** BAND DOWN. Set `BDP1;` (4), read `-` (-), answer `-` (-), AI X. P1 0 main,1 sub
- **Read / answer (firmware):** none
- **Set parameters (firmware):** P1 '0' or '1' (len 4 only; no read form)
- **Class:** action
- **Behaviour:** Steps the band down one (wraps 0 -> 11) on VFO selected by P1: '0' = currently selected VFO (0x9DBD), '1' = the other VFO [inference]; band index from band_of_freq(freq) (12-entry table) then `band_select_on`(newBand,vfo) changes band.
- **Globals / callees:** Guard: busy/lockout guard (any true -> '?;'): DAT_20f0c!=0, 20b8a==1, 20b3d!=0, 20cce==1, 20f1b==1, 20ccd==1, 20b7c!=0, 20cd0==1, 20cd1==1, 20f11==1, plus 20f1c==1 or 20f70==1. W 0x9C5E=0, 0x9DBE/0x9DBF=1 (VFO state) or restored from 0x20F88/89; callees fffb357c, fffb33e5, fffc4c4e
- **Risk:** medium: changes band/frequency of the radio
- **Resolved (#157, #173):** `vfo_freq`(which, side) (fffb357c) returns the big-endian u32 frequency in Hz at record +0x4A (side 0 = A, 1 = B, 2 = `vfo_rec_ptr`(which)) **[fact]**. P1 is relative to the active VFO: the side is 0x9DBD XOR P1, so `0` = the active (operating) VFO and `1` = the other one; any other P1 answers `?;` **[fact]** (`cat_BD` @ fffa72d9). The manual's "main/sub" therefore means active/inactive VFO, not A/B **[inference]**. Side effects: with split on (0x9C5E = 1) split is cleared and, for P1 `0`, both states are forced to 1 (VFO), for P1 `1` both are restored from 0x20F88/0x20F89 (UI +0x484/+0x485, saved by `split_toggle` @ fffbeca5 when split was turned on); with split off, P1 `0` forces the active side to state 1, while P1 `1` leaves the other side's state as it is **[fact]**. The band is stepped with `band_select_on`(band, side) @ fffc4c4e, which sets 0x9DBD to the side for one `band_select` call, clears split and re-arms the tuner (`FUN_fffec578`) **[fact]**.

### BI

- **Index / handler:** 11, cat_BI @ fffa77ec; switch case fffa3da7; length tests `len==3:cat_BI@fffa77ec \| len==4:cat_BI@fffa77ec` [fact]
- **Manual 2306-C:** BREAK-IN. Set `BIP1;` (4), read `BI;` (3), answer `BIP1;` (4), AI O. P1 0 off,1 on
- **Read / answer (firmware):** BIn; (len 4). n = bit1 (0x02) of a per-mode byte on VFO block fffb324c(1): m(fffb3196(1)) 2-3 ->+0x14; 4-5 ->+0x32; 6-7,10-11 ->+0x3C; 0-1 ->+0x0A; modes 8-9,12-13,14 -> error
- **Set parameters (firmware):** n via hex-parse: '0' clears bit1, '1' sets bit1, other -> error. Modes 8,9,12,13,14 -> error. No dirty flag, no apply call.
- **Class:** read+set
- **Behaviour:** Per-mode on/off flag (bit 1) in the VFO data block [fact]; feature unknown.
- **Globals / callees:** `vfo_rec_ptr`(1), fffb3196(1)
- **Risk:** low: UI/DSP flag
- **Resolved (#157):** `vfo_rec_ptr`/`vfo_mode`(0) return the **active** VFO (0x9DBD: 0 = A record 0x9D09, 1 = B 0x9D63); with argument 1 they return the **TX** VFO, i.e. the other VFO while split (0x9C5E) is on. `vfo_mode` returns 2 (CW-L) during tune/EXT-PA cycles (0x20F0C, 0x20B40, 0x20B41, 0x20B25) **[fact, current decompile]**.

### BM

- **Index / handler:** 12, cat_BM @ fffa7928; switch case fffa3ddf; length tests `len==3:cat_BM@fffa7928` [fact]
- **Manual 2306-C:** VFO-B TO MEMORY CHANNEL. Set `BM;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Set parameters (firmware):** none
- **Class:** action
- **Behaviour:** Stores the VFO-B data block into memory channel (number 0x60CA) in RAM and EEPROM; twin of AM using B state 0x9DBF and block 0x9D63 [name inference; copy and EEPROM write are facts].
- **Globals / callees:** R 0x60CA (error if 0x75..0x84), 0x9DBF, 0x9DC4, 0x60BD[]; W 0x6150+ch*0x5A, 0x9D63, 0x20F10; fffbf41f, fffc2fde/16f6, eeprom_save_memch(ch) (EEPROM)
- **Risk:** medium: overwrites a memory channel in EEPROM
- **Resolved (#157, #173):** as AM (B side: 0x5409 + level·0x438 + band·0x5A, level 0x60BD[band], band 0x9DC4) **[fact]**. Quirk: in B state 4 `cat_BM` calls the same `vm_toggle`, which acts on the **active** VFO (0x9DBD), so with VFO-A active it toggles A, not B **[fact, current decompile]**; `vfo_mark_edited`/`vfo_store_back` are also called with 0x9DBD, not 1 **[fact]**.

### BP

- **Index / handler:** 13, cat_BP @ fffa7a71; switch case fffa3df4; length tests `len==5:cat_BP@fffa7a71 \| len==8:cat_BP@fffa7a71` [fact]
- **Manual 2306-C:** MANUAL NOTCH. Set `BPP1P2P3P3P3;` (8), read `BPP1P2;` (5), answer `BPP1P2P3P3P3;` (8), AI O. P1 0 fixed; P2 0 notch on/off,1 notch freq; P3 (P2=0) 000 off,001 on; (P2=1) 001-320 (x10 Hz)
- **Read / answer (firmware):** BP0<P2>...; P2='0': 'BP00' '00' b (b=bit7 of per-mode byte), len 8; P2 any other char: 3-digit decimal of the 16-bit value (hi,lo bytes), len 8
- **Set parameters (firmware):** P1 must be '0' else error. P2 '0': idx4,5 must be '0','0' (else silently ignored, no error), idx6 '0' clears bit7, '1' sets bit7, else error. P2 '1': idx4-6 3 decimal digits 001-320 (0 or >320 error) stored big-endian. Other P2 -> error. Then 0x20F10=1 and fffc2fde/fffc16f6 apply. Per-mode block offsets (flag byte): m2-3 0x14; m4-5 0x32; m6-7,10-11 0x3C; m12-13 0x1E; m8-9,14 0x28; m0-1 0x0A; value bytes at flag+4,+5.
- **Class:** read+set
- **Behaviour:** Per-mode enable bit 7 plus a 1-320 value (16-bit) in VFO block [fact]; feature unknown (value may be x10 Hz) [guess].
- **Globals / callees:** `vfo_rec_ptr`(0), fffb3196(0); block bytes; 0x20F10; fffc2fde, fffc16f6
- **Risk:** low-medium: VFO setting, dirty flag set
- **Resolved (#69):** the current decompile (T21i string/loop fixes) shows the weights 100/10/1 in both the read and the set loop **[fact]**.

### BS

- **Index / handler:** 14, cat_BS @ fffa7db5; switch case fffa3e2c; length tests `len==5:cat_BS@fffa7db5` [fact]
- **Manual 2306-C:** BAND SELECT. Set `BSP1P1;` (5), read `-` (-), answer `-` (-), AI X. P1 00 1.8M,01 3.5,02 5,03 7,04 10,05 14,06 18,07 21,08 24.5,09 28,10 50,11 70/GEN (MHz)
- **Read / answer (firmware):** none (len 5 only: BSnn;)
- **Set parameters (firmware):** nn 2 decimal digits: first '0'/'1', second '0'-'9', value <=12 (else error)
- **Class:** action
- **Behaviour:** Selects band number nn (0-12) on the selected VFO via `band_select_on`(nn,0x9DBD) and puts both VFO states to 1 (VFO mode) [fact].
- **Globals / callees:** Guard: busy/lockout guard (any true -> '?;'): DAT_20f0c!=0, 20b8a==1, 20b3d!=0, 20cce==1, 20f1b==1, 20ccd==1, 20b7c!=0, 20cd0==1, 20cd1==1, 20f11==1, plus 20f1c==1 or 20f70==1. W 0x9C5E=0, 0x9DBE=0x9DBF=1; fffc4c4e
- **Risk:** medium: changes band/frequency

### BU

- **Index / handler:** 15, cat_BU @ fffa756c; switch case fffa3d83; length tests `len==4:cat_BU@fffa756c` [fact]
- **Manual 2306-C:** BAND UP. Set `BUP1;` (4), read `-` (-), answer `-` (-), AI X. P1 0 main,1 sub
- **Read / answer (firmware):** none
- **Set parameters (firmware):** P1 '0' or '1' (len 4 only)
- **Class:** action
- **Behaviour:** Steps the band up one (wraps after 11 to 0) on VFO selected by P1 ('0' = selected VFO 0x9DBD, '1' = other) via `band_select_on`; twin of BD.
- **Globals / callees:** Guard: busy/lockout guard (any true -> '?;'): DAT_20f0c!=0, 20b8a==1, 20b3d!=0, 20cce==1, 20f1b==1, 20ccd==1, 20b7c!=0, 20cd0==1, 20cd1==1, 20f11==1, plus 20f1c==1 or 20f70==1. Same state writes as BD; fffb357c, fffb33e5, fffc4c4e
- **Risk:** medium: changes band/frequency
- **Resolved (#157, #173):** as BD: same P1 = 0x9DBD XOR P1 side selection and split handling in `cat_BU` @ fffa756c; it steps band+1 with 11 (GEN) wrapping to 0 **[fact]**.

### BY

- **Index / handler:** 16, switch default (fffa4e26); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Read / answer (firmware):** error '?;'
- **Class:** error-only
- **Behaviour:** No handler: dispatch default sets error flag DAT_0000464A=1 [fact].
- **Globals / callees:** 0x464A
- **Risk:** low

### CF

- **Index / handler:** 17, cat_CF @ fffa7fa1; switch case fffa3e50; length tests `len==6:cat_CF@fffa7fa1 \| len==11:cat_CF@fffa7fa1` [fact]
- **Manual 2306-C:** CLAR (Clarifier). Set `CFP1P2P3P4P5P6P7P8;` (11), read `CFP1P2P3;` (6), answer `CFP1P2P3P4P5P6P7P8;` (11), AI O. P1 0 main,1 sub; P2 0 fixed; P3 0 clar setting,1 clar freq; P3=0: P4 RX clar 0/1, P5 TX clar 0/1, P6-P8 000 fixed; P3=1: P4 +/-, P5-P8 0000-9999 Hz (read has only P1-P3)
- **Read / answer (firmware):** CF<P1>0<P3>...; P3=0: CF<P1>00<rx><tx>000; rx=bit0, tx=bit1 of flag byte 0x20F29 (or 0x20F2A); P3=1: CF<P1>01<sign><dddd>; sign '+'/'-' from bit7 of VFO-block byte+0x48, dddd = \|16-bit signed value at +0x48/+0x49\|, 4 decimal digits. len 11
- **Set parameters (firmware):** P1 '0' = currently selected VFO (0x9DBD), '1' = the other, else error. idx3 ignored (reply shows '0'). P3 (idx4) hex char must be 0 or 1 else error. Set needs key_event_filter(0x306,0)!=0, 0x9C5E!=1, `vfo_tune_locked`(vfo)!=1, else error. P3=0 set: idx5 '0'/'1' = flag bit0, idx6 '0'/'1' = flag bit1, idx7-9 must be '000' else error; also sets bits 0x10/0x08 in VFO block byte+1. P3=1 set: idx5 '+' or '-', idx6-9 4 digits (0000-9999, no range check) stored as 16-bit two's complement at block+0x48/+0x49. Sets 0x20F10=1.
- **Class:** read+set
- **Behaviour:** Clarifier-style RX/TX on-off flags (P3=0) and signed offset (P3=1, 4 digits) per VFO [inference from sign+4-digit structure; flags are fact].
- **Globals / callees:** R/W 0x20F29/0x20F2A, block 0x9D09/0x9D63 +1,+0x48,+0x49; 0x9C5E; fffb44f7(0x306,0), fffb4bba; 0x20F10
- **Risk:** medium: changes RX/TX clarifier offsets (affects tuning, not TX keying)
- **Resolved in part (#69):** the weights are 1000/100/10/1 in the current decompile **[fact]**.
- **Resolved (#159):** the offset is in **Hz**: `vfo_freq_clar` (0xFFFB35D7) adds the s16 at +0x48 directly to the Hz frequency from `vfo_freq` when the RX or TX clarifier bit is set **[fact]**.

### CH

- **Index / handler:** 18, cat_CH @ fffa8375; switch case fffa3e88; length tests `len==4:cat_CH@fffa8375` [fact]
- **Manual 2306-C:** CHANNEL UP/DOWN. Set `CHP1;` (4), read `-` (-), answer `-` (-), AI X. P1 0 memory ch up,1 down
- **Read / answer (firmware):** none (len 4 only: CHn;)
- **Set parameters (firmware):** n '0' -> 0x20F80=0; '1' -> 0x20F80=1; other error
- **Class:** action
- **Behaviour:** Steps the memory channel of the selected VFO by one in direction n via FUN_fffc54cc(1,vfo); only valid when that VFO's state (0x9DBE/0x9DBF) is 2 (memory mode), else error [fact].
- **Globals / callees:** Guard flags (busy/lockout guard (any true -> '?;'): DAT_20f0c!=0, 20b8a==1, 20b3d!=0, 20cce==1, 20f1b==1, 20ccd==1, 20b7c!=0, 20cd0==1, 20cd1==1, 20f11==1, 20b98==1); R 0x9DBD, 0x9DBE/0x9DBF==2; W 0x20F80; fffc54cc (fffc5541/fffc55d7 and eeprom_save_memch = EEPROM write)
- **Risk:** medium: changes channel (fffb0376 writes EEPROM channel state)
- **Resolved (#157):** 0x20F80 is UI-state +0x47C. `FUN_fffc54cc` calls `FUN_fffc5541` (channel +1, wrapping to the first) when it is 0 and `FUN_fffc55d7` (−1) when it is 1, so `CH0;` = up and `CH1;` = down, as in the manual **[fact]**.

### CN

- **Index / handler:** 19, cat_CN @ fffa8513; switch case fffa3ea1; length tests `len==5:cat_CN@fffa8513 \| len==8:cat_CN@fffa8513` [fact]
- **Manual 2306-C:** CTCSS NUMBER. Set `CNP1P2P3P3P3;` (8), read `CNP1P2;` (5), answer `CNP1P2P3P3P3;` (8), AI O. P1 0 main,1 sub; P2 0 fixed; P3 000-049 tone number (Table 1: 000=67.0Hz..049=254.1Hz)
- **Read / answer (firmware):** CN<P1>0nnn; (len 8). nnn = byte at VFO block+0x46 (decimal 000-049 expected)
- **Set parameters (firmware):** P1 '0' = selected VFO (0x9DBD), '1' = other (other values leave pointer uninitialised: undefined behaviour). P2 (idx3) must be '0' else error. nnn 3 decimal digits; value must be <50 (0x32) else error (nothing stored); stored to block+0x46; then 0x20F10=1 and fffc2fde/fffc16f6 apply.
- **Class:** read+set
- **Behaviour:** Per-VFO 0-49 index [fact for range]; likely a 50-entry tone table index [inference].
- **Globals / callees:** block+0x46 of 0x9D09/0x9D63; 0x20F10; fffc2fde, fffc16f6
- **Risk:** low-medium: VFO setting

### CO

- **Index / handler:** 20, cat_CO @ fffa8698; switch case fffa3ed9; length tests `len==5:cat_CO@fffa8698 \| len==9:cat_CO@fffa8698` [fact]
- **Manual 2306-C:** CONTOUR/APF. Set `COP1P2P3P3P3P3;` (9), read `COP1P2;` (5), answer `COP1P2P3P3P3P3;` (9), AI O. P1 0 fixed; P2 0 contour on/off,1 contour freq,2 APF on/off,3 APF freq; P3 (P2=0/2) 0000 off,0001 on; (P2=1) 0010-3200 Hz; (P2=3) 0000-0050 (-250..+250 Hz)
- **Read / answer (firmware):** CO<P1><P2>....; (len 9; P1 echoed). P2=0: CO00 000b (b=bit6 of per-mode byte); P2=1: CO01 dddd (16-bit value *10, last digit always 0); P2=2: CO02 000b (b=bit5 of per-mode byte); P2=3: CO03 00dd (dd = DAT_9C5F+25)
- **Set parameters (firmware):** P1 idx2 not checked. P2 (idx3): '0': idx7 '0'/'1' -> clear/set bit6 (idx4-6 not validated). '1': idx4-7 4 decimal digits 0010-3200 (else error), stored value/10 as 16-bit at per-mode offset; sets 0x20F10. '2': if per-mode flag pointer is the 0xFF sentinel (modes 4-7,10-11,0-1) -> error, else idx7 '0'/'1' -> clear/set bit5. '3': idx4,5 must be '00', idx6-7 2 digits <=50 -> 0x9C5F = v-25 (signed), 0x20F10=1. else error. Per-mode offsets (flag/value): m2-3 +0x14/+0x16; m4-5 +0x32/+0x34; m6-7,10-11 +0x3C/+0x3E; m12-13 +0x1E/+0x20; m8-9,14 +0x28/+0x2A; m0-1 +0x0A/+0x0C.
- **Class:** read+set
- **Behaviour:** Four parameters: two on/off bits (P2=0,2), a 10-3200 value in steps of 10 (P2=1), a global signed -25..+25 value (P2=3) [fact]; feature unknown (resembles contour/APF controls) [guess].
- **Globals / callees:** `vfo_rec_ptr`(0), fffb3196(0); 0x9C5F; 0x20F10
- **Risk:** low-medium: DSP shaping parameters
- **Resolved (#69, #173):** the loops use 1000/100/10/1 and 10/1 in the current decompile **[fact]**. The P2=2 sentinel: `cat_CO` @ fffa8698 keeps three pointers per mode (contour flag byte, APF flag byte, contour frequency). For SSB (0/1), AM (4/5), FM (6/7) and DATA-FM (10/11) the APF pointer is aimed at a local byte preset to 0xFF instead of the record, so `CO0P2`=`2…` set answers `?;` in those modes; for CW (2/3, +0x14), RTTY (12/13, +0x1E) and DATA-L/U/PSK (8/9/14, +0x28) it points at the same record byte as the contour flag, and bit 5 of it is the APF on/off **[fact]**. Side effect: in those three groups a record byte that is itself 0xFF also refuses the set **[fact]**, which a valid record never holds **[inference]**. The read form has no such check and always reports bit 5 of the mode's contour byte, so `CO02` reads `0000` in SSB/AM/FM rather than erroring **[fact]**. The APF frequency (P2=3) is one global byte 0x9C5F for all modes **[fact]**. So CAT can switch APF in CW, RTTY, DATA-L/U and PSK; the CAT manual names no mode restriction **[fact]**.

### CS

- **Index / handler:** 21, cat_CS @ fffa8b98; switch case fffa3f15; length tests `len==3:cat_CS@fffa8b98 \| len==4:cat_CS@fffa8b98` [fact]
- **Manual 2306-C:** CW SPOT. Set `CSP1;` (4), read `CS;` (3), answer `CSP1;` (4), AI O. P1 0 off,1 on
- **Read / answer (firmware):** CSn; (len 4). n='1' if 0x20F0B==1 else '0'
- **Set parameters (firmware):** n '1' -> 0x20F0B=1 and `beep_request`(4); n '0' -> if 0x20F0B==1: =0 and `beep_stop`(); other -> error. Gates (error): key_event_filter(0x307,2)==0; 0x9C5E==1; FUN_fffc3e3c(fffb324c(1))==0 (needs mode index 2/3, or the 0x9A3C special case).
- **Class:** read+set
- **Behaviour:** On/off flag with a UI state-machine kick (0x12041=4 start, 0x12040=3 stop), valid only for mode index 2 or 3 [fact]; likely a CW-related function [guess].
- **Globals / callees:** 0x20F0B, 0x12040/0x12041, 0x9A3C, 0x9C5E; fffb44f7(0x307,2), fffc3e3c, fffb2da6, fffb2df4
- **Risk:** low-medium: UI state; effect of 0x12041=4 unknown
- **Resolved (#157):** `beep_request`(4) is pattern 4 of `beep_task`: a tone at **0x9C04 × 10 + 300 Hz** (the CW pitch), re-triggered every 100 ms until `beep_stop`, i.e. the **CW SPOT** tone **[fact]**.

### CT

- **Index / handler:** 22, cat_CT @ fffa8c79; switch case fffa3f4d; length tests `len==4:cat_CT@fffa8c79 \| len==5:cat_CT@fffa8c79` [fact]
- **Manual 2306-C:** CTCSS. Set `CTP1P2;` (5), read `CTP1;` (4), answer `CTP1P2;` (5), AI O. P1 0 main,1 sub; P2 0 off,1 ENC+DEC on,2 ENC on/DEC off
- **Read / answer (firmware):** CT0n; (len 5). field=(byte3 of active VFO block & 0x38)>>3: 0->'0', 1->'2', 2->'1', else error
- **Set parameters (firmware):** P1 must be '0' else error. n '0' -> field 0; '2' -> field 1; '1' -> field 2; other error. Acts on VFO selected by 0x9DBD. Sets 0x20F10=1 only (no apply call).
- **Class:** read+set
- **Behaviour:** Selects a 3-valued mode in bits 3-5 of byte 3 of the VFO block [fact]; with CN likely a tone squelch/encode selector [guess].
- **Globals / callees:** 0x9D09/0x9D63 +3; 0x20F10
- **Risk:** low: VFO setting

### DA

- **Index / handler:** 23, cat_DA @ fffa8d8a; switch case fffa3f89; length tests `len==3:cat_DA@fffa8d8a \| len==11:cat_DA@fffa8d8a` [fact]
- **Manual 2306-C:** LCD CONTRAST/DIMMER. Set `DAP1P1P2P2P3P3P4P4;` (11), read `DA;` (3), answer `DAP1P1P2P2P3P3P4P4;` (11), AI X. P1 00 fixed; P2 00-20 TFT contrast; P3 00-20 TFT brightness; P4 00-20 LED brightness (each 2 digits)
- **Read / answer (firmware):** DA00aabbcc; (len 11). aa=0x9BE9, bb=0x9BEA, cc=0x9B10 as 2-digit decimals; 1c90/1c91 forced '0','0'
- **Set parameters (firmware):** idx2-3 ignored; idx4-5 aa, idx6-7 bb, idx8-9 cc: each 2 decimal digits, each <=20 else error (nothing stored). Stores 0x9BE9,0x9BEA,0x9B10 and sets 0x20F04=1.
- **Class:** read+set
- **Behaviour:** Three 0-20 values [fact]; display/brightness-style settings [guess].
- **Globals / callees:** R/W 0x9BE9, 0x9BEA, 0x9B10; 0x20F04=1
- **Risk:** low: UI levels

### DN

- **Index / handler:** 24, cat_DN @ fffa9029; switch case fffa3fc1; length tests `len==3:cat_DN@fffa9029` [fact]
- **Manual 2306-C:** MIC DOWN. Set `DN;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Set parameters (firmware):** none
- **Class:** action
- **Behaviour:** Executes the configured DOWN action (like a mic DOWN key): FUN_fffc037b -> FUN_fffc40d7(DAT_9ACD) jump-table dispatch by setting 0x9ACD [inference].
- **Globals / callees:** Gates: key_event_filter(0x34E,0)==0 -> error; guard flags (busy/lockout guard (any true -> '?;'): DAT_20f0c!=0, 20b8a==1, 20b3d!=0, 20cce==1, 20f1b==1, 20ccd==1, 20b7c!=0, 20cd0==1, 20cd1==1, 20f11==1). W 0x20F6F=0. Callee FUN_fffc037b
- **Risk:** medium: moves frequency/channel as configured
- **Resolved (#69):** 0x9ACD is the menu item **MIC DOWN** (`EX030125`, 0..20). Values 0..12 act as the front-panel keys LOCK, QMB, A/B, V/M, TUNER, VOX/MOX, MODE, ZIN/SPOT, SPLIT, FINE, NAR, NB, DNR (key codes from the u16 list 0xFFF88534); 13..20 are FREQ UP, FREQ DOWN, BAND UP, BAND DOWN, ATT, IPO, DNF, AGC, whose handlers are in the 8-entry tables at 0xFFF8E100 (labels from the menu text at 0xFFF84753) **[fact]**. See [code/main/ui-keys.md](code/main/ui-keys.md).

### DT

- **Index / handler:** 25, cat_DT @ fffa9281; switch case fffa3fd6; length tests `len==4:cat_DT@fffa9281 \| len==10\|\|len==12:cat_DT@fffa9281` [fact]
- **Manual 2306-C:** DATE AND TIME. Set `DTP1P2x8; (P2 x6 for time)` (12/10), read `DTP1;` (4), answer `DTP1P2x8; (P2 x6 for time)` (12/10), AI X. P1 0 date,1 time(UTC); P2 (P1=0) yyyymmdd 8 digits; (P1=1) hhmmss 6 digits. Len 12 for date, 10 for time
- **Read / answer (firmware):** P1 '0': DT0 20yymmdd; (len 12) '20'+yy mm dd from 0x20BB1,B2,B3 (2 chars each via FUN_fffb311d; non-decimal nibbles shown as ' '); P1 '1': DT1hhmm00; (len 10) hh=0x20BB4, mm=0x20BB5, seconds '00'. Other P1 on read -> error
- **Set parameters (firmware):** P1 '0' (needs 12 chars): idx3-10 all digits; idx3-4 must be '20'; month idx7-8 01-12; day idx9-10 1..days(month; Feb 29 if yy%4==0 else 28; 30 for 4,6,9,11; else 31) else error; stores yy,mm,dd (FUN_fffb30b5) into 0x20BB1..B3 and mirrors 0x20BB6..B8, sets 0x20B91=1. P1 '1' (len 10): idx3-8 digits, hh<24, mm<60 (seconds idx7-8 digit-checked but ignored) -> 0x20BB4,0x20BB5, mirrors 0x20BB9/BA, 0x20B91=1. Other P1 -> error. P1 vs length not cross-checked.
- **Class:** read+set
- **Behaviour:** Reads/sets the real-time clock date (P1=0) and time (P1=1) [fact for fields; 0x20B91 as RTC-write-pending flag is inference].
- **Globals / callees:** 0x20BB1-B8, 0x20BB9/BA, 0x20B91; fffb311d, fffb30b5
- **Risk:** medium: sets clock
- **Resolved (#157):** the date set loop checks indices 3..10 for digits; a 10-byte `DT0yyyymm;` has `;` at index 9, so it is refused with `?;` **[fact]**.

### ED

- **Index / handler:** 26, switch default (fffa4e26); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Read / answer (firmware):** error '?;'
- **Class:** error-only
- **Behaviour:** No handler: dispatch default sets error flag [fact].
- **Globals / callees:** 0x464A
- **Risk:** low

### EK

- **Index / handler:** 27, switch default (fffa4e26); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Read / answer (firmware):** error '?;'
- **Class:** error-only
- **Behaviour:** No handler: dispatch default sets error flag [fact].
- **Globals / callees:** 0x464A
- **Risk:** low

### EM

- **Index / handler:** 28, cat_EM @ fffa9648; switch case fffa4023; length tests `len==5:cat_EM@fffa9648 \| len>=6&&len<=55:cat_EM@fffa9648` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Read / answer (firmware):** EM0n<text>; (len = textlen+5): text from 5 RAM slots (n=1..5) at 0x979E,0x97D0,0x9802,0x9834,0x9866 (0x32 apart), terminated by 0xFE; max 50 chars
- **Set parameters (firmware):** P1 must be '0'; n '1'-'5' else error. Set: text = bytes idx4 .. before ';' (len-5 = 1..50 chars), no content validation; copied into slot, terminated with 0xFE (a 50-char text spills the terminator into the next slot's first byte).
- **Class:** read+set
- **Behaviour:** Reads/writes five user text strings (50 chars max) in RAM; FUN_fff9baa0 mirrors the first/5th bytes of each to 0x1801..0x1825 [fact]; purpose unknown (message/label slots) [guess].
- **Globals / callees:** 0x979E-0x9897; fffb012c
- **Risk:** low: text in RAM; no dirty flag seen
- **Resolved in part (#69):** 0x979E is the 5 × 0x32 text-slot block at EEPROM 0x514F. `eeprom_save_msg(2, n)` has no caller, so it is saved only by the full save ([code/main/eeprom.md](code/main/eeprom.md)) **[fact]**.
- **Resolved (#173):** `FUN_fff9baa0` is called only from `displink_build_39` @ fff9b6c8 (MAIN → DISPLAY frame `0x39`, built at 0x1741) when UI +0x1C7 (0x20CCB) = 2. It copies the first 8 bytes of each of the five slots (0x979E, 0x97D0, 0x9802, 0x9834, 0x9866) into frame bytes 0xC0..0xE7 (0x1801..0x1828), five 8-character labels **[fact]**. +0x1C7 is the message type that `FUN_fffe4407` @ fffe4407 sets from the TX mode (`vfo_mode`(1)): 1 for CW (2/3), 2 for RTTY (12/13), 3 for PSK (14), 0 for the voice modes; for type 1 the sibling `FUN_fff9ba18` @ fff9ba18 copies the five KM keyer texts (0x96A0 + n·0x33) instead **[fact]**. So the `EM` slots are the **RTTY text memories** and `FUN_fff9baa0` shows their names on the DISPLAY's message screen **[inference]**; no other MAIN code reads 0x979E, so the text is sent from the DISPLAY/DSP side or not by MAIN **[fact for the readers; the rest inference]**. Still open: as decompiled, `displink_build_39` overwrites 0x1801..0x1828 from UI +0xC2.. right after the call, which would make these stores dead; this needs the disassembly (Ghidra hold) to settle **[fact for the decompile]**.

### EN

- **Index / handler:** 29, cat_EN @ fffa9928; switch case fffa406f; length tests `len==5:cat_EN@fffa9928` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Read / answer (firmware):** error '?;' always
- **Class:** error-only
- **Behaviour:** Handler is a stub that only sets the error flag (EN always returns '?;') [fact]; dispatch requires len 5 and errors for other lengths too.
- **Globals / callees:** 0x464A
- **Risk:** low

### EU

- **Index / handler:** 30, switch default (fffa4e26); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Read / answer (firmware):** error '?;'
- **Class:** error-only
- **Behaviour:** No handler: dispatch default sets error flag [fact].
- **Globals / callees:** 0x464A
- **Risk:** low

### EX

- **Index / handler:** 31, cat_EX @ fffa9937; switch case fffa4097; length tests `len==9:cat_EX@fffa9937 \| len>8:cat_EX@fffa9937` [fact]. (Before T20 the tsv printed the second test as `len==8`; T19h found it is `len > 8`) (case code at 0xFFFA4097, `decomp/main/fffa20af_fffa7928.c`: `len == 9` → read, `8 < len` → set), so read is 9 characters and set ≥ 10, as [cat-commands.md](cat-commands.md) says; `ex_write_value` 0xFFFE6550 then wants exactly 9 + the item's digit count
- **Manual 2306-C:** MENU. Set `EXP1P1P2P2P3P3P4xn;` (10-21), read `EXP1P1P2P2P3P3;` (9), answer `EXP1P1P2P2P3P3P4xn;` (10-21), AI O. P1 2 digits group 01-04,06 (manual header says 01-04,05; table shows 06 EXTENSION SETTING); P2 2 digits subgroup 01-05; P3 2 digits item 01-26; P4 value 1-4 digits (12 chars for MY CALL/PRESET NAME), see EX TSV. Set/answer len = 9+len(P4)
- **Read / answer (firmware):** EX<gg><mm><ii><value>; reply = copy of the 8 command chars + value text (up to 12 chars from `menu_string_get`) + ';', length value+9 (buffer 0x18878)
- **Set parameters (firmware):** Menu access by 6-digit address gg mm ii (digits else error): gg 01,02,03,04,06 (others incl. 05 and 00 -> error) maps to menu number = mm + offset (g1 -1, g2 +4, g3 +6, g4 +11, g6 +21), item index = ii-1; looked up via `menu_get_limits` table. Set: len>=10, value formatted by `ex_write_value` (x10 / x20+20 / raw scaling) or `ex_read_value`; on success `menu_apply_from_cat` applies (0x15DFC=1, `menu_call_step`, 0x25D60[0x40B]=1). Read needs exactly len 9. Len<9 -> error. After set, if any AI flag (0x20B20-22)==1 -> cat_ai_holdoff.
- **Class:** read+set
- **Behaviour:** Generic setup-menu get/set by menu number across groups 1-4 and 6 [fact for decode; 'menu' is inference].
- **Globals / callees:** `ex_command`, fffe6c27, fffe6299, fffd4ffe, fffd4795, fffe6335/63fb/646c/6550, fffcdddb; buffers 0x18878, 0x1FF10, 0x1B234
- **Risk:** medium-high: menu items include persistent config and probably TX-related settings and port/baud settings
- **Resolved (#69):** the descriptor layout, value formats and all 314 items are in [code/main/menu.md](code/main/menu.md) and `tools/main_menu_table.py` **[fact]**.

### FA

- **Index / handler:** 32, cat_FA_FB @ fffa99bd (side 0); switch case fffa40d7; length tests `len==3:cat_FA_FB@fffa99bd \| len==12:cat_FA_FB@fffa99bd` [fact]
- **Manual 2306-C:** FREQUENCY VFO-A. Set `FAP1x9;` (12), read `FA;` (3), answer `FAP1x9;` (12), AI O. P1 000030000-075000000 Hz (9 digits)
- **Read / answer (firmware):** FAnnnnnnnnn; (12 bytes) 9 decimal digits zero padded = VFO-A frequency in Hz from 0x20F54; if DAT_00020B6B==1 and side==DAT_00009DBD the value comes from 0x20F50 instead. Digits at 0x1C90..0x1C98, ';' at 0x1C99
- **Set parameters (firmware):** FAnnnnnnnnn; 9 digits '0'..'9' at cmd[2..10] (Hz). Non-digit -> '?;'. Value must satisfy `freq_in_range`: 29999 < f < 75000001 (30000..75000000 Hz) else '?;'. Also '?;' while DAT_00020B8A==1 or DAT_00020F11==1, if `vfo_tune_locked`(side)==1 (side state is 7/8, or state 2 with memory-channel byte 117..132 = 501-515/EMG), or if DAT_00020F6D==1 after the tune attempt (state restored)
- **Class:** read+set
- **Behaviour:** Reads/sets the VFO-A frequency in Hz; set stores the 32-bit value big-endian into side-0 record bytes +0x4A..+0x4D of 0x9D09, zeroes +0x48/+0x49 (clarifier offset cleared) and retunes via `freq_clamp` [fact]
- **Globals / callees:** R: 0x20F54,0x20F50,0x20B6B,0x9DBD. W: 0x9D09[0x48..0x4D],0x9DBE/0x9DBF (restored, or from 0x9DC7 if 0x9C5E==1),0x20F10 (frequency-cache refresh request=1),0x20F68. callees: `freq_in_range` range, `vfo_tune_locked` lock, `freq_clamp` tune, `vfo_mem_to_memtune`, `vfo_mark_edited`+`vfo_store_back` UI refresh
- **Risk:** medium: changes operating frequency (persisted via dirty flag), no direct TX
- **Resolved (#157):** `freq_clamp(side, f)`: in PMS state (0x9DBE/0x9DBF = 4) it loads the PMS limits 0x20F74/0x20F78 if needed and clamps to them (`freq_clamp_pms`); otherwise it checks f against `tune_limits` 0xFFF89D4C = **30,000 .. 75,000,000 Hz** and either clamps to the limit (0x1B4E1 = 1) or wraps to the other end (`freq_fix_below`/`freq_fix_above`, the wrap used while scanning). The result is written to the VFO record and applied by `vfo_mark_edited`/`vfo_store_back` **[fact]**.

### FB

- **Index / handler:** 33, cat_FA_FB @ fffa99bd (side 1); switch case fffa40d7; length tests `len==3:cat_FA_FB@fffa99bd \| len==12:cat_FA_FB@fffa99bd` [fact]
- **Manual 2306-C:** FREQUENCY VFO-B. Set `FBP1x9;` (12), read `FB;` (3), answer `FBP1x9;` (12), AI O. P1 000030000-075000000 Hz (9 digits)
- **Read / answer (firmware):** FBnnnnnnnnn; same as FA but VFO-B frequency from 0x20F58; the 0x20F50 override applies if DAT_00020B6B==1 and DAT_00009DBD==1
- **Set parameters (firmware):** same as FA with side=1: record 0x9D63 (+0x4A..0x4D freq, +0x48/49 cleared); state byte tested is 0x9DBF (==2 -> `vfo_mem_to_memtune`(1))
- **Class:** read+set
- **Behaviour:** Reads/sets the VFO-B frequency (same validation as FA) [fact]
- **Globals / callees:** R: 0x20F58,0x20F50,0x20B6B,0x9DBD. W: 0x9D63[0x48..0x4D],0x20F10. callees as FA with side=1
- **Risk:** medium: changes frequency
- **Resolved (#157):** as FA.

### FN

- **Index / handler:** 34, cat_FN @ fffa9c96; switch case fffa4120; length tests `len==3:cat_FN@fffa9c96 \| len==4:cat_FN@fffa9c96` [fact]
- **Manual 2306-C:** FINE TUNING. Set `FNP1;` (4), read `FN;` (3), answer `FNP1;` (4), AI O. P1 0 off,1 fine tuning on,2 fast tuning on
- **Read / answer (firmware):** FNn; (4 bytes) n = DAT_00009C61 -> '0','1','2' (any other stored value reads as '0')
- **Set parameters (firmware):** FNn; n '0'/'1'/'2' -> DAT_00009C61 = 0/1/2; any other char -> '?;'. No busy checks, no other side effects
- **Class:** read+set
- **Behaviour:** Stores a 3-state selector byte at 0x9C61 [fact]; meaning not determinable from this handler [guess]
- **Globals / callees:** RW 0x9C61
- **Risk:** low: single RAM byte, no call
- **Resolved (#157):** 0x9C61 is the **FINE/FAST tuning state**: `key_fine_fast_short` toggles 0 ↔ 1 and `key_fine_fast_long` toggles 0 ↔ 2, the dial-step code (`FUN_fffc62ae`, `FUN_fffc648c`) reads it, and the AI reporter `FUN_fffdee2c` sends it. So `FN` 0 = off, 1 = FINE, 2 = FAST **[fact for the code, inference for which of 1/2 is FINE from the key's short/long roles]**.

### FS

- **Index / handler:** 35, cat_FS @ fffa9d3d; switch case fffa4158; length tests `len==3:cat_FS@fffa9d3d \| len==4:cat_FS@fffa9d3d` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Read / answer (firmware):** none
- **Set parameters (firmware):** none (FS; or FSn; with the right length)
- **Class:** error-only
- **Behaviour:** Handler always sets the error flag: recognised by length but always answers '?;' [fact]
- **Globals / callees:** W 0x464A=1
- **Risk:** low: stub

### FT

- **Index / handler:** 36, cat_FT @ fffa9d4e; switch case fffa4190; length tests `len==3:cat_FT@fffa9d4e \| len==4:cat_FT@fffa9d4e` [fact]
- **Manual 2306-C:** FUNCTION TX. Set `FTP1;` (4), read `FT;` (3), answer `FTP1;` (4), AI O. P1 0 main band TX,1 sub band TX
- **Read / answer (firmware):** FTn; n='1' if DAT_00009C5E==1 else '0'
- **Set parameters (firmware):** FTn; n '0' or '1' else '?;'. '?;' if any busy flag: 0x20F1C==1, 0x20F70==1, 0x20F0C!=0, 0x20B8A==1, 0x20B3D!=0, 0x20CCE==1, 0x20F1B==1, 0x20CCD==1, 0x20B7C!=0, 0x20CD0==1, 0x20CD1==1, 0x20F11==1, 0x20B98==1. If requested value differs from current 0x9C5E calls `split_toggle`() (toggle); if same, does nothing
- **Class:** read+set
- **Behaviour:** Turns split (0x9C5E) off/on, the same flag as `ST`: `split_toggle` @ fffbeca5 toggles 0x9C5E, saves/restores VFO states (0x9DBE/0x9DBF vs 0x9DC7/0x9DC8) and refreshes UI [fact] (T10g, [radio-control.md](code/main/radio-control.md#split-clarifier-ab)). While split is on, `vfo_rec_ptr`(1) selects the other VFO as TX [fact]
- **Globals / callees:** RW 0x9C5E; callee `split_toggle` (also writes 0x9DBE,0x9DBF,0x9DC7,0x9DC8,0x20F09, PTR_DAT_00025d54 fields)
- **Risk:** medium: changes TX/RX VFO configuration (no direct key-down)
- **Resolved in part (#69):** 0x20F1C = scan running (UI +0x418); 0x20F70 = UI +0x46C, a timed flag of the MIC slot/remote-keypad handlers ([code/main/tx-protection.md](code/main/tx-protection.md), #144) **[fact]**. 0x20B8A and the others are still open.
- **Resolved (#159):** the other guard flags are all named under `SV` (0x20B8A = +0x86 message pop-up, 0x20B3D = TX lamp state, 0x20CCE = armed DVS recording, …) **[fact]**.

### GT

- **Index / handler:** 37, cat_GT @ fffa9f23; switch case fffa41c8; length tests `len==4:cat_GT@fffa9f23 \| len==5:cat_GT@fffa9f23` [fact]
- **Manual 2306-C:** AGC FUNCTION. Set `GTP1P2;` (5), read `GTP1;` (4), answer `GTP1P3;` (5), AI O. Set: P1 0 fixed; P2 0 off,1 fast,2 mid,3 slow,4 auto. Answer: P1 0 fixed; P3 0 off,1 fast,2 mid,3 slow,4 auto-fast,5 auto-mid,6 auto-slow
- **Read / answer (firmware):** GT0n; (5 bytes) n digit 0..6 derived from a per-mode byte (bit6 = enabled, bits4-5 = field): disabled -> 0; enabled: field 1,2,3 -> 1,2,3; field 0 -> 4, 5 or 6 depending on mode class (see needs_disasm). Digit at 0x1C91
- **Set parameters (firmware):** GT0n; P1 must be '0' (else '?;'), n = hex-digit value 0..4 (>4 or bad char -> '?;'). Clears bits4..6 of the per-mode byte; n=4 sets bit6 only (field 0); n=1..3 sets bit6 and n<<4; n=0 leaves cleared. Then 0x20F10=1 and `vfo_mark_edited`/`vfo_store_back` refresh for side DAT_00009DBD
- **Class:** read+set
- **Behaviour:** Per-mode 5-state setting stored in a byte of the main-side record, indexed by mode class `vfo_mode`(0): {0,1}->rec+0x0B, {2,3}->+0x15, {4,5}->+0x33, {6,7}->+0x3D, {8,9}->+0x29, {10,11}->+0x3D, {12,13}->+0x1F, {14}->+0x29 (read and set use the same map) [fact]; AGC-like selector [guess]
- **Globals / callees:** R/W record(`vfo_rec_ptr`(0))+{0x0B,0x15,0x1F,0x29,0x33,0x3D}; W 0x20F10; callees `vfo_mode`(0), `vfo_rec_ptr`(0), hex2nib, `vfo_mark_edited`, `vfo_store_back`
- **Risk:** medium: changes per-mode radio setting (persisted)
- **Note (#157):** READ/SET MISMATCH [fact]: set accepts 0..4 but read can return 5 or 6: field 0 reads 4 in classes {2,3,6,7,10,11}, 5 in {8,9,12,13,14}, 6 in {0,1,4,5}. The record is the active VFO's (`vfo_rec_ptr`(0) = 0x9D09 or 0x9D63 by 0x9DBD; the decompile is clean now) **[fact]**.

### GP

- **Index / handler:** 38, cat_GP @ fffaa21f; switch case fffa4204; length tests `len==3:cat_GP@fffaa21f \| len==7:cat_GP@fffaa21f` [fact]
- **Manual 2306-C:** GP OUT A/B/C/D. Set `GPP1P2P3P4;` (7), read `GP;` (3), answer `GPP1P2P3P4;` (7), AI X. P1 GP OUT A 0 low,1 high; P2 B; P3 C; P4 D (each 0/1). Requires menu TUN/LIN PORT SELECT = GPO
- **Read / answer (firmware):** GPabcd; (7 bytes) four chars '0'/'1': a=bit3 of port reg 0x8C021, b=bit2 of 0x8C021, c=bit0 of 0x8C025, d=bit2 of 0x8C022. Answered only if DAT_00009AB7==3 (`tunlin_port_mode`), else '?;'
- **Set parameters (firmware):** GPabcd; four chars at cmd[2..5], each must be < 0x32 ('0'/'1'; lower bound NOT checked: chars below '0' give 0xFF from hex2nib and the setter masks bit0 -> 1). '?;' if 0x20F1C==1, 0x20F70==1, 0x20F0C!=0 or DAT_00009AB7!=3. Each value written to one port-data bit: a->0x8C021 b3, b->0x8C021 b2, c->0x8C025 b0, d->0x8C022 b2
- **Class:** read+set
- **Behaviour:** Reads/drives four general purpose output pins directly (MCU port data registers 0x8C021/0x8C025/0x8C022), enabled only when config byte 0x9AB7==3 [fact]; 'GP OUT' naming [inference]
- **Globals / callees:** R/W MMIO 0x8C021 (bits3,2), 0x8C025 (bit0), 0x8C022 (bit2); R 0x9AB7; getters `gpo_a_get`/be/d1/e2, setters `gpo_a_set`/65/7d/93
- **Risk:** medium: toggles hardware output pins (external equipment), no EEPROM
- **Resolved in part (#69):** 0x9AB7 is **TUN/LIN PORT SELECT** (`EX030103`, 0..3) **[fact]**; the pins are still open.

### ID

- **Index / handler:** 39, cat_ID @ fffaa365; switch case fffa423c; length tests `len==3:cat_ID@fffaa365` [fact]
- **Manual 2306-C:** IDENTIFICATION. Set `-` (-), read `ID;` (3), answer `IDP1P1P1P1;` (7), AI X. P1 0800 fixed (4 digits)
- **Read / answer (firmware):** ID0800; fixed reply, 7 bytes ('0','8','0','0' written at 0x1C90..0x1C93)
- **Set parameters (firmware):** none
- **Class:** read-only
- **Behaviour:** Returns the constant radio ID 0800 [fact]
- **Globals / callees:** W reply buffer only
- **Risk:** low: constant

### IF

- **Index / handler:** 40, cat_IF_OI @ fffaa39c (arg 0, side 0 = record 0x9D09); switch case fffa4260; length tests `len==3:cat_IF_OI@fffaa39c` [fact]
- **Manual 2306-C:** INFORMATION (VFO-A). Set `-` (-), read `IF;` (3), answer `IFP1P1P1P2x9P3x5P4P5P6P7P8P9P9P10;` (28), AI O. Answer: P1 3 chars mem ch (000 VFO/MT/QMB,001-099,P1L-P9U PMS,5xx,EMG); P2 9 digit freq Hz; P3 clar dir +/- then 4 digit offset 0000-9990 (5 chars); P4 RX clar 0/1; P5 TX clar 0/1; P6 mode 0-9,A-F; P7 0 VFO,1 mem,2 mem tune,3 QMB,4 -,5 PMS; P8 0 off,1 CTCSS ENC/DEC,2 ENC; P9 00 fixed; P10 0 simplex,1 plus,2 minus. Total 28
- **Read / answer (firmware):** IF + 26 chars + ';' = 28 bytes (len 0x1C). [0x1C90..92] P1 3 chars memory channel: if chan byte 0x60C9 <99: 3-digit decimal (byte+1, 001..099); else 3-char name from table @0xFFF806E9 (3 bytes/entry, index = byte-99): 99..116 = P1L P1U P2L P2U P3L P3U P4L P4U P5L P5U P6L P6U P7L P7U P8L P8U P9L P9U; 117..131 = 501..515; 132 = EMG; forced to '000' when VFO state 0x9DBE is 1, 3 or 5. [0x1C93..9B] P2 9 digits frequency Hz (from `vfo_freq`(0,side); see needs_disasm). [0x1C9C] P3 sign: '-' if record byte +0x48 bit7 else '+'; [0x1C9D..A0] 4 digits \|offset\| of 16-bit two's complement value at record +0x48:+0x49 (clarifier offset, no clamp). [0x1CA1] P4 = '1' if DAT_00020F29 in {1,3} else '0'; [0x1CA2] P5 = '1' if 0x20F29 in {2,3} else '0' (0x20F29 0->'00', 1->'10', 2->'01', 3->'11'; other values leave stale bytes). [0x1CA3] P6 mode = cat_mode_codes[rec[0]&0xF] (table @0xFFF806D0, 16 bytes: 0'1',1'2',2'7',3'3',4'5',5'D',6'4',7'B',8'8',9'C',10'A',11'F',12'6',13'9',14'E',15'F'). [0x1CA4] P7 = byte table @0xFFF806DF indexed by VFO state 0x9DBE: 0'F',1'0',2'1',3'2',4'5',5'3',6'F',7'1',8'1',9'F'. [0x1CA5] P8 from rec[3] bits3-5: 1->'2', 2->'1', else '0'. [0x1CA6][0x1CA7] P9 constant '0','0'. [0x1CA8] P10 from rec[2] bits2-3: 0->'2', 2->'1', else '0'. [0x1CA9] ';'
- **Set parameters (firmware):** none
- **Class:** read-only
- **Behaviour:** Answers with the whole state of the VFO-A record 0x9D09 (channel, frequency, clarifier offset and flags, mode, VFO/memory state, two small selectors); always side 0 regardless of the selected VFO [fact]
- **Globals / callees:** R: 0x60C9,0x9DBE,0x20F29,0x9D09[0,2,3,0x48,0x49,0x4A..0x4D], tables @0xFFF806D0/DF/E9; callees `vfo_freq`(0,0), nib2hex
- **Risk:** low: read-only
- **Resolved in part (#157):** `vfo_freq`(which, side) (fffb357c) returns the big-endian u32 frequency in Hz at record +0x4A (side 0 = A, 1 = B, 2 = `vfo_rec_ptr`(which)) **[fact]**. Still open: meaning of P7 for states 4, 6–9.
- **Resolved (#159):** rec[2] bits 2–3 are the repeater shift (0 minus, 1 simplex, 2 plus) and rec[3] bits 3–5 the tone mode (`CT`); see [the record table](code/main/radio-control.md#the-0x5a-byte-channel-record) **[fact]**.

### IS

- **Index / handler:** 41, cat_IS @ fffaa6e3; switch case fffa428f; length tests `len==4:cat_IS@fffaa6e3 \| len==10:cat_IS@fffaa6e3` [fact]
- **Manual 2306-C:** IF SHIFT. Set `ISP1P2P3P4P4P4P4;` (10), read `ISP1;` (4), answer `ISP1P2P3P4P4P4P4;` (10), AI O. P1 0 fixed; P2 0 fixed; P3 +/-; P4 0000-1200 Hz (20 Hz steps, 4 digits)
- **Read / answer (firmware):** IS00sNNNN; (10 bytes): 0x1C90..91 constant '0','0'; 0x1C92 sign '+'/'-' (bit15); 0x1C93..96 four digits \|value\| of a signed 16-bit big-endian value in the main-side record
- **Set parameters (firmware):** ISxxsNNNN; cmd[2..3] ignored, cmd[4] sign '+' or '-' (else '?;'), cmd[5..8] four digits (non-digit -> '?;'); magnitude must be <= 12000 (0x2EE0; unreachable with 4 digits). Stored as signed 16-bit BE; then 0x20F10=1 and refresh for side DAT_00009DBD
- **Class:** read+set
- **Behaviour:** Per-mode-class signed 16-bit value in the main-side record at offset by `vfo_mode`(0): {0,1}->+0x12, {2,3}->+0x1C, {4,5}->+0x3A, {6,7}->+0x44, {8,9}->+0x30, {10,11}->+0x44, {12,13}->+0x26, {14}->+0x30 [fact]; probably IF shift in Hz [guess]
- **Globals / callees:** R/W record(`vfo_rec_ptr`(0)) offsets above (2 bytes); W 0x20F10; `vfo_mode`(0), `vfo_mark_edited`, `vfo_store_back`
- **Risk:** medium: changes per-mode DSP setting (persisted)
- **Resolved in part (#69):** the weights are 1000/100/10/1 in the current decompile **[fact]**; the side selection of `vfo_rec_ptr`/fffb3196 is still open.

### KM

- **Index / handler:** 42, cat_KM @ fffaa905; switch case fffa42c7; length tests `len==4:cat_KM@fffaa905 \| len>=5&&len<=54:cat_KM@fffaa905` [fact]
- **Manual 2306-C:** KEYER MEMORY. Set `KMP1P2xn;` (5-54), read `KMP1;` (4), answer `KMP1P2xn;` (5-54), AI X. P1 1-5 memory ch; P2 message characters up to 50 (set/answer len 5-54)
- **Read / answer (firmware):** KMn<text>; n=1..5: reply 'KMn' + stored text (length N from 0x969F/0x96D2/0x9705/0x9738/0x976B, text follows) + ';' = N+4 bytes; if N==0 the reply is 'KM;' (3 bytes, the ';' overwrites n). Other n -> '?;'
- **Set parameters (firmware):** KMn<text>; n '1'..'5' (else '?;'), text = len-4 bytes (1..50) copied verbatim (NO character validation) after the slot is filled with 0x20 x50. '?;' if DAT_00020B94==1 && DAT_00020BC2==2 && n==DAT_00020BC3+1 (slot in use). If FUN_fffb012c finds '}' (0x7D) at start of text, '}' is appended after the text. Stores length byte then `eeprom_save_msg`(1,n) = EEPROM write of 0x33 bytes
- **Class:** read+set
- **Behaviour:** Reads/writes five 50-char text message memories (CW keyer text, [inference] from KY/LM using the same slots) and saves slot n to EEPROM [fact: eeprom_write in `eeprom_save_msg`]
- **Globals / callees:** RW 0x969F+0x33*(n-1) (len), +1 (text); R 0x20B94,0x20BC2,0x20BC3; callees FUN_fffb012c, `eeprom_save_msg` -> eeprom_write (addr table @0x5050+0x33*i, 0x33 bytes)
- **Risk:** medium: EEPROM write of message memory on every set
- **Resolved in part (#157):** `FUN_fffb012c(buf, c, n)` is a bounded search: it returns (in R1; the decompiler's `void` signature drops it) the index of the first byte equal to `c` in `buf[0..n)`, or `n`. `cat_EM` uses it with c = 0xFE as a text-length function **[fact]**. The off-by-one check in `cat_KM` is still open.

### KP

- **Index / handler:** 43, cat_KP @ fffaac36; switch case fffa431b; length tests `len==3:cat_KP@fffaac36 \| len==5:cat_KP@fffaac36` [fact]
- **Manual 2306-C:** KEY PITCH. Set `KPP1P1;` (5), read `KP;` (3), answer `KPP1P1;` (5), AI O. P1 00-75 (300-1050 Hz, 10 Hz steps)
- **Read / answer (firmware):** KPnn; (5 bytes) 2 decimal digits from DAT_00009C04
- **Set parameters (firmware):** KPnn; cmd[2..3] digits (non-digit -> '?;'), weights 10/1 (dropped by decompiler), value <= 75 (0x4B) else '?;' -> DAT_00009C04. If DAT_00009ACE==0: DAT_00020CC6=0x31, FUN_fffc8cbb(0x31), FUN_fffc8d8c() (UI popup)
- **Class:** read+set
- **Behaviour:** Stores a 0..75 byte at 0x9C04 (CW pitch-like setting, [guess] by range and UI popup pattern shared with KS)
- **Globals / callees:** RW 0x9C04; W 0x20CC6; R 0x9ACE; FUN_fffc8cbb/8d8c (UI popup)
- **Risk:** low: RAM byte (persistence not shown here)
- **Resolved (#157):** 0x9ACE is **SCU-LAN10** (`EX030126`). 0x9C04 is the CW pitch index: `beep_task` plays 0x9C04 × 10 + 300 Hz, so `KP` 00..75 = 300..1050 Hz **[fact]**.

### KR

- **Index / handler:** 44, cat_KR @ fffaad52; switch case fffa4353; length tests `len==3:cat_KR@fffaad52 \| len==4:cat_KR@fffaad52` [fact]
- **Manual 2306-C:** KEYER. Set `KRP1;` (4), read `KR;` (3), answer `KRP1;` (4), AI O. P1 0 off,1 on
- **Read / answer (firmware):** KRn; n = DAT_00009C02 as hex digit (0/1)
- **Set parameters (firmware):** KRn; first requires key_event_filter(0xE0,0)!=0 (key 0xE0 filter) and FUN_fffe5690()!=0 (mode class `vfo_mode`(1) is 2 or 3) else '?;'. n '1'->1, '0'->0, else '?;'
- **Class:** read+set
- **Behaviour:** On/off flag at 0x9C02, set gated to mode class 2/3 (the CW-like pair, [inference]) and key 0xE0 allowed [fact for gating]
- **Globals / callees:** RW 0x9C02; key_event_filter(0xE0,0), FUN_fffe5690 (`vfo_mode`(1) in {2,3})
- **Risk:** low: RAM flag
- **Note (#157):** the read is ungated and only the write is gated **[fact]**; nothing left to check.

### KS

- **Index / handler:** 45, cat_KS @ fffaadea; switch case fffa438b; length tests `len==3:cat_KS@fffaadea \| len==6:cat_KS@fffaadea` [fact]
- **Manual 2306-C:** KEY SPEED. Set `KSP1P1P1;` (6), read `KS;` (3), answer `KSP1P1P1;` (6), AI O. P1 004-060 WPM
- **Read / answer (firmware):** KSnnn; (6 bytes) 3 decimal digits from DAT_00009C03
- **Set parameters (firmware):** KSnnn; cmd[2..4] digits (non-digit -> '?;'), weights 100/10/1 (dropped by decompiler), accepted 4..60 (0x04..0x3C) else '?;' -> DAT_00009C03. If DAT_00009ACE==0: DAT_00020CC6=0x30, FUN_fffc8cbb(0x30), FUN_fffc8d8c() (UI popup)
- **Class:** read+set
- **Behaviour:** Stores a 4..60 value at 0x9C03 (keying speed in wpm, [inference] from range and siblings KP/KY)
- **Globals / callees:** RW 0x9C03; W 0x20CC6; R 0x9ACE; FUN_fffc8cbb, FUN_fffc8d8c
- **Risk:** low: RAM byte

### KY

- **Index / handler:** 46, cat_KY @ fffaaf19; switch case fffa43c3; length tests `len==5:cat_KY@fffaaf19` [fact]
- **Manual 2306-C:** CW KEYING. Set `KYP1P2;` (5), read `-` (-), answer `-` (-), AI X. P1 0 CW text memory,1 CW message memory; P2 0 stop,1-5 playback memory 1-5
- **Read / answer (firmware):** none (read length not accepted)
- **Set parameters (firmware):** KYab; a=cmd[2] must be <= '1' (0x31) else '?;'; b=cmd[3] hex digit: '0' -> DAT_00020B2F=7 and return (stop/cancel [inference]); 1..5 -> message slot (>5 -> '?;'); a stored into DAT_00009AAC[b]; a=='0' -> DAT_00020CD0=1, a=='1' -> DAT_00020CD1=1. Preconditions: key_event_filter(0x87,0)!=0, FUN_fffe5690()==1 (mode class 2/3), DAT_00020B97 != 1, FUN_fffe564b()!=0 (not busy), FUN_fffe5401(b) nonzero (message non-empty) else flags cleared and '?;' (beep `beep_request`(3) when empty). If DAT_00020B2F==1 it becomes 5 (queued) else FUN_fffe53c0() and DAT_00020CD6=1
- **Class:** set-only
- **Behaviour:** Starts playback of message slot b (1..5) (source set chosen by a, KM text slots are one source), b=0 stops: selects slot via FUN_fffe538f then FUN_fffe53c0 sets state byte (PTR 0x25D78)+0x2B = 7 [fact]; that this transmits CW is [inference] from slots, CW-class gating and TX-state flags
- **Globals / callees:** W 0x20CCB=1 (even on early error), 0x9AAC[1..5], 0x20CD0/CD1, 0x20B2F, 0x20CD6; R 0x20B97; PTR 0x25D78 fields (+0x1C8,+0xBF,+0x1CE,+0x1CC,+0x1CD,+0x417,+0x1D1,+0x2B); callees key_event_filter(0x87), FUN_fffe5690, FUN_fffe564b, FUN_fffe5401, FUN_fffe538f, FUN_fffe53c0
- **Risk:** high: starts keyed CW message transmission (keys TX)
- **Resolved in part (#157):** +0x2B = 7 is what `FUN_fffe3d24` sets when it cancels a running playback/keyer send, so 7 is the idle/stopped keyer state **[inference]**. The invalid-`a` quirk (0xFF stored into 0x9AAC[b] before the error) is real code **[fact]**.

### LK

- **Index / handler:** 47, cat_LK @ fffab09f; switch case fffa43dc; length tests `len==3:cat_LK@fffab09f \| len==4:cat_LK@fffab09f` [fact]
- **Manual 2306-C:** LOCK. Set `LKP1;` (4), read `LK;` (3), answer `LKP1;` (4), AI O. P1 0 off,1 on
- **Read / answer (firmware):** LKn; n = DAT_00009C62 as hex digit (0/1)
- **Set parameters (firmware):** LKn; requires key_event_filter(0x300,0)!=0 else '?;'; '1' -> DAT_00009C62=1, '0' -> 0, else '?;'. If DAT_00009ACE==0 UI popup: DAT_00020CC6=0x47 (on) / 0x48 (off) via FUN_fffc8cbb/FUN_fffc8d8c
- **Class:** read+set
- **Behaviour:** Lock flag at 0x9C62 with paired on/off popup codes [inference: front-panel lock]
- **Globals / callees:** RW 0x9C62; W 0x20CC6; R 0x9ACE; key_event_filter(0x300,0)
- **Risk:** low: UI lock flag

### LM

- **Index / handler:** 48, cat_LM @ fffab16f; switch case fffa4414; length tests `len==4:cat_LM@fffab16f \| len==5:cat_LM@fffab16f` [fact]
- **Manual 2306-C:** LOAD MESSAGE. Set `LMP1P2;` (5), read `LMP1;` (4), answer `LMP1P2;` (5), AI X. P1 0 message (DVS),1 record; P2 (P1=0) 0 stop,1-5 select ch; (P1=1) 0 rec stop,1 rec start
- **Read / answer (firmware):** LMpn; (5 bytes; 'LMp' copied from the request) p='0': n=(DAT_00020B7D value)+1 as hex digit if DAT_00020B7C==2 else '0'; p='1': n=DAT_00020B96 as hex digit; other p: n byte left stale from previous reply
- **Set parameters (firmware):** LMpn; first needs key_event_filter(0x87,0)!=0 else '?;'. p='0': '?;' if 0x20B96==1 or 0x20CCD==1 or 0x20CD0==1 or 0x20CD1==1; n=='0' clears 0x20B7C,0x20F1B,0x20CCE; n<0x36 non-'0' (intended '1'..'5', lower bound unchecked) needs FUN_fffe56bf()==1 (mode class 0,1 or 4..7) and 0x20B7C==0, then DAT_00020CCC=hex2nib(n), 0x20CCB=0, 0x20F1B=1, 0x20CCE=1, 0x20B7D=n-1, FUN_fffe4efc() (start); n>='6' -> '?;'. p='1': '?;' if 0x20B7C in {1,2} or 0x20CCD==1 or 0x20CD0==1 or 0x20CD1==1; n '0'/'1' -> DAT_00020B96 (else '?;'), then 0x20B95=1. other p: silent no-op (no error, no reply)
- **Class:** read+set
- **Behaviour:** Message-memory job control: LM0n starts slot n (1..5) / stops (0), state 0x20B7C, slot in 0x20B7D, flags 0x20F1B/0x20CCE (also block FT/MD); LM1n sets a 0/1 flag 0x20B96 [fact for flags; record/playback meaning is inference]
- **Globals / callees:** RW 0x20B7C,0x20B7D,0x20B96,0x20B95,0x20F1B,0x20CCE,0x20CCC,0x20CCB; R 0x20CCD,0x20CD0,0x20CD1; callees key_event_filter(0x87,0), FUN_fffe56bf, FUN_fffe4efc
- **Risk:** high: may start message/recorder operation (possibly TX), same key filter 0x87 as KY
- **Resolved in part (#157):** `FUN_fffe4efc` only sets UI +0x1CB = 1 and starts timer 0x37 (10,000 units); it does not key TX itself **[fact]**. +0x1CB is one of the message states that `FUN_fffe3d24` and the E8 status clear, so it arms a message recording **[inference]**. 0x20B7C (+0x78) is the voice-message playback state (see `SV`). Still open: the chars-below-'0' quirk (real code).
- **Resolved (#159):** **0x20B96** is the DVS **RECORD** flag of `LM1`: `LM11;` sets it, `LM10;` clears it, `LM1;` reads it, and `RI` P3 reports it as 1 (recording) **[fact, `cat_LM` 0xFFFAB16F]**. `LM0n;` (n = 1..5) sets 0x20F1B and **0x20CCE (UI +0x1CA) = 1** (record armed for channel n, 0x20B7D = n−1); `LM00;` clears both. When the record starts, `FUN_fffc0210` clears +0x1CA and sets +0x78 = 2 **[fact]**.

### MA

- **Index / handler:** 49, cat_MA @ fffab3fd; switch case fffa4450; length tests `len==3:cat_MA@fffab3fd` [fact]
- **Manual 2306-C:** MEMORY CHANNEL TO VFO-A. Set `MA;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Read / answer (firmware):** none
- **Set parameters (firmware):** MA; (no params): requires key_event_filter(0x308,0)!=0 and DAT_00020B3D==0 else '?;'. Copies 0x5A-byte memory record #DAT_000060C9 from 0x6150+0x5A*ch into VFO-A record 0x9D09, then `vfo_mark_edited`(0)+`vfo_store_back`(0) refresh, 0x20F10=1
- **Class:** action
- **Behaviour:** Loads the memory channel currently referenced by VFO-A (0x60C9) into the VFO-A working record (memory-to-VFO copy) [fact: 0x5A-byte copy; naming inference]
- **Globals / callees:** R 0x6150+0x5A*0x60C9; W 0x9D09 (0x5A bytes); 0x20F10; R 0x20B3D; key_event_filter(0x308,0)
- **Risk:** medium: overwrites VFO-A frequency/mode (persisted)

### MB

- **Index / handler:** 50, cat_MB @ fffab478; switch case fffa4465; length tests `len==3:cat_MB@fffab478` [fact]
- **Manual 2306-C:** MEMORY CHANNEL TO VFO-B. Set `MB;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Read / answer (firmware):** none
- **Set parameters (firmware):** MB; same as MA for side B: record 0x6150+0x5A*DAT_000060CA -> 0x9D63, refresh side 1, key filter 0x308, DAT_00020B3D==0
- **Class:** action
- **Behaviour:** Memory-to-VFO-B copy [fact: 0x5A-byte copy]
- **Globals / callees:** R 0x6150+0x5A*0x60CA; W 0x9D63 (0x5A bytes); 0x20F10
- **Risk:** medium: overwrites VFO-B (persisted)

### MC

- **Index / handler:** 51, cat_MC @ fffab4f3; switch case fffa447a; length tests `len==3:cat_MC@fffab4f3 \| len==6:cat_MC@fffab4f3` [fact]
- **Manual 2306-C:** MEMORY CHANNEL. Set `MCP1P1P1;` (6), read `MC;` (3), answer `MCP1P1P1;` (6), AI X. P1 001-099, P1L-P9U (PMS), 5xx (5MHz band), EMG (3 chars)
- **Read / answer (firmware):** MCnnn; (6 bytes) memory channel of the selected side (DAT_00009DBD): byte<99 -> 3-digit decimal byte+1 (001..099); byte>=99 -> 3-char name from table @0xFFF806E9 (P1L..P9U, 501..515, EMG as in IF). No forced '000' for VFO states
- **Set parameters (firmware):** MCnnn; '?;' if DAT_00020B3D!=0. cmd[2]=='0': three digits cmd[2..4] weights 100/10/1, value must be 1..99 -> idx=v-1. cmd[2]!='0': cmd[2..4] matched (FUN_fffede1d 3-byte compare, after 3x toupper_inplace toupper) against the 34-entry name table (P1L,P1U..P9L,P9U,501..515,EMG) -> idx=99+k; no match -> '?;'. idx 117..131 (501-515) also need FUN_fff9c2cd()==1 and `memch_dest_blocked`(idx)!=1; idx 132 (EMG) needs DAT_00009AF4!=0; then `memch_valid`(idx) must be nonzero. Result: DAT_000060C9 (or 0x60CA for side 1)=idx, state 0x9DBE (0x9DBF)=2, working record `vfo_rec_ptr`(0) backed up 0x5A bytes to 0x9DCE (0x9E28) then overwritten with memory record 0x6150+0x5A*idx; eeprom_save_memch(1); 0x20F10=1
- **Class:** read+set
- **Behaviour:** Selects/recalls a memory channel into the selected VFO (memory state) [fact]
- **Globals / callees:** R/W 0x60C9,0x60CA,0x9DBD,0x9DBE,0x9DBF,0x9DCE[0x5A],0x9E28[0x5A], record `vfo_rec_ptr`(0) (0x5A), table 0x6150; R 0x20B3D,0x9AF4; callees `memch_valid`,`memch_dest_blocked`,FUN_fff9c2cd,eeprom_save_memch,FUN_fffede1d,toupper_inplace
- **Risk:** medium: changes current VFO contents (persisted), no TX
- **Resolved in part (#157):** `vfo_rec_ptr`/`vfo_mode`(0) return the **active** VFO (0x9DBD: 0 = A record 0x9D09, 1 = B 0x9D63); with argument 1 they return the **TX** VFO, i.e. the other VFO while split (0x9C5E) is on. `vfo_mode` returns 2 (CW-L) during tune/EXT-PA cycles (0x20F0C, 0x20B40, 0x20B41, 0x20B25) **[fact, current decompile]**. The `memch_valid` test is still open.

### MD

- **Index / handler:** 52, cat_MD @ fffab7d1; switch case fffa44b2; length tests `len==4:cat_MD@fffab7d1 \| len==5:cat_MD@fffab7d1` [fact]
- **Manual 2306-C:** MODE. Set `MDP1P2;` (5), read `MDP1;` (4), answer `MDP1P2;` (5), AI O. P1 0 main,1 sub; P2 mode 0 -,1 LSB,2 USB,3 CW-U,4 FM,5 AM,6 RTTY-L,7 CW-L,8 DATA-L,9 RTTY-U,A DATA-FM,B FM-N,C DATA-U,D AM-N,E PSK,F DATA-FM-N
- **Read / answer (firmware):** MDpm; (5 bytes, 'MDp' copied) m = cat_mode_codes[rec[0]&0xF]; p='0' -> selected side record (0x9D09 if DAT_00009DBD==0 else 0x9D63), p='1' -> the other side; other p -> '?;' (read and set)
- **Set parameters (firmware):** MDpm; p '0'/'1' else '?;'. Requires key_event_filter(0x30C,0)!=0 and none of busy flags 0x20F1C==1,0x20F70==1,0x20F0C!=0,0x20B8A==1,0x20B3D!=0,0x20CCE==1,0x20F1B==1,0x20CCD==1,0x20B7C!=0,0x20CD0==1,0x20CD1==1,0x20F11==1,0x20B98==1 else '?;'. Sets DAT_00020CD5=0. m (toupper_inplace toupper) searched in cat_mode_codes[0..14] ('1','2','7','3','5','D','4','B','8','C','A','F','6','9','E' = mode 0..14); no match -> '?;'. p='0': FUN_fffc4bd5(idx) (full mode change); p='1': only low nibble of the other side's record byte 0 = idx
- **Class:** read+set
- **Behaviour:** Reads/changes operating mode of the selected (p=0) or other (p=1) side via cat_mode_codes @0xFFF806D0 [fact]; p=1 writes the nibble without calling the mode-change routine (no retune/refresh) [fact]
- **Globals / callees:** R/W record byte0 low nibble of 0x9D09/0x9D63; R 0x9DBD; busy flags above; FUN_fffc4bd5 -> FUN_fffc0d33/0e31/0e3e/...; table @0xFFF806D0
- **Risk:** medium: changes operating mode (persisted)
- **Resolved (#157):** `cat_mode_codes` (0xFFF806D0) maps the mode nibble 0..14 to `1 2 7 3 5 D 4 B 8 C A F 6 9 E`, so the letters are 1 LSB, 2 USB, 3 CW-U, 4 FM, 5 AM, 6 RTTY-L, 7 CW-L, 8 DATA-L, 9 RTTY-U, A DATA-FM, B FM-N, C DATA-U, D AM-N, E PSK, F DATA-FM-N, as in the CAT manual **[fact]**.

### MG

- **Index / handler:** 53, cat_MG @ fffaba64; switch case fffa44ee; length tests `len==3:cat_MG@fffaba64 \| len==6:cat_MG@fffaba64` [fact]
- **Manual 2306-C:** MIC GAIN. Set `MGP1P1P1;` (6), read `MG;` (3), answer `MGP1P1P1;` (6), AI O. P1 000-100
- **Read / answer (firmware):** MGnnn; nnn=per-mode level byte, 3-digit dec 000-100
- **Set parameters (firmware):** P1 nnn = 3 dec digits [2..4], each must be '0'..'9' and value <=100 else error; stored as byte into the per-mode variable; also sets 0x20F10=1 and (if 0x9ACE==0) notifies display/panel with param id 0x25 (FUN_fffc8cbb/8d8c) [inference]
- **Class:** read+set
- **Behaviour:** Mic-gain-like per-mode TX audio level 0-100 [guess for label]: variable chosen by current mode m=`vfo_mode`(0): m=0,1->0x9BEC; m=2,3->0x9BEE; m=4,6->0x9BEF; m=5,14->0x9BED; any other m -> error '?;' [fact from C, but decompiler removed 7 unreachable blocks]. Mode m is an index into cat_mode_codes @fff806d0.
- **Globals / callees:** 0x9BEC-0x9BEF (per-mode level), 0x9ACE, 0x20F10, 0x20CC6=0x25; callees `vfo_mode` (current VFO mode), FUN_fffc8cbb, FUN_fffc8d8c
- **Risk:** medium - TX-related audio level, RAM only in handler (no EEPROM call)
- **Resolved in part (#157):** the TX audio code `FUN_fffb5d68` uses MIC GAIN 0x9BEC for SSB (0/1), 0x9BED for DATA-L/U and PSK (8/9/14), 0x9BEE for AM (4/5), 0x9BEF for FM and DATA-FM (6/7/10/11) **[fact]**; that `cat_MG`'s branch tree uses the same split is **[inference]**.

### ML

- **Index / handler:** 54, cat_ML @ fffabbfa; switch case fffa4526; length tests `len==4:cat_ML@fffabbfa \| len==7:cat_ML@fffabbfa` [fact]
- **Manual 2306-C:** MONITOR LEVEL. Set `MLP1P2P2P2;` (7), read `MLP1;` (4), answer `MLP1P2P2P2;` (7), AI O. P1 0 monitor on/off,1 monitor level; P2 (P1=0) 000 off,001 on; (P1=1) 000-100
- **Read / answer (firmware):** ML0: 'ML000x;' x='0' if level==0 else '1'. ML1: 'ML1nnn;' nnn=level dec 000-100. Other P1: error
- **Set parameters (firmware):** P1='0' -> [3][4] must be '00', P4 '0' -> level=0, '1' -> level=0x32 (50), else error; P1='1' -> nnn at [3..5] decimal digits, <=100 else error, stores byte, if 0x9ACE==0 notifies display param 0x2d. Set is REFUSED (error) when mode m in {6,7,10,11}; P1 other than 0/1 -> error
- **Class:** read+set
- **Behaviour:** Per-mode monitor-level-like variable: ML0 = on/off view of it (set maps to 0 or 50), ML1 = 0-100 level. Variable by mode m: 0,1->0x9BFC; 2,3->0x9BFD; 4,5->0x9C00; 8,9,14->0x9BFF; 12,13->0x9BFE; 6,7,10,11->0x9C01 (read only, set rejected); other m -> error [fact from C; label 'monitor' is guess].
- **Globals / callees:** 0x9BFC-0x9C01, 0x9ACE, 0x20CC6=0x2d; `vfo_mode`, FUN_fffc8cbb/8d8c
- **Risk:** medium - audio/monitor setting; RAM only in handler
- **Resolved in part (#157):** the current decompile (T21 fixes, no `in_`/`unaff_` variables in this handler) shows a plain `P1 == '0'` test; the garbled `{1,0,0,0}` store was an artifact **[fact]**.
- **Resolved (#159):** confirmed in the C: for modes 6/7/10/11 `cat_ML` selects 0x9C01 and returns `?;` when it is a set (`param_2 == 1`); the read works **[fact]**.

### MR

- **Index / handler:** 55, cat_MR @ fffabea5; switch case fffa4562; length tests `len==6:cat_MR@fffabea5` [fact]
- **Manual 2306-C:** MEMORY READ. Set `-` (-), read `MRP0P0P0;` (6), answer `MRP1P1P1P2x9P3x5P4P5P6P7P8P9P9P10;` (28), AI X. Read: P0 3 chars mem ch (001-099,P1L-P9U,5xx,EMG). Answer (same layout as IF): P1 mem ch 3 chars; P2 freq 9 digits; P3 clar +/- and 4 digits; P4 RX clar; P5 TX clar; P6 mode; P7 0-5; P8 CTCSS; P9 00; P10 shift. Answer 28
- **Read / answer (firmware):** MRcccFFFFFFFFFsOOOOabMvkhhS; (28 chars): ccc=3-digit channel or 3-char name, F=9-digit freq Hz (rec+0x4A..4D BE), s=+/- and OOOO=4-digit clarifier offset (rec+0x48/49), a=rec[1]b4, b=rec[1]b3, M=cat_mode_codes[rec[0]&0xF], v=table fff806df[0x9DBE or 0x9DBF if 0x9DBD!=0], k=tone '2' if (rec[3]>>3&7)==1,'1' if ==2 else '0', hh='00', S=shift '2' if (rec[2]>>2&3)==0,'1' if ==2 else '0'
- **Set parameters (firmware):** none (read only, len 6 only). Argument ccc: if [2]=='0' digits 001-099 -> idx ccc-1. Else 3 chars (after toupper) matched against the 34-entry name table @fff806e9: P1L P1U P2L P2U ... P9L P9U 501..515 EMG -> idx 99+i. Channel must be flagged valid (`memch_valid`) and have nonzero freq, else error
- **Class:** read-only
- **Behaviour:** Reads one memory channel record (0x5A bytes at 0x6150+idx*0x5A) in the same 28-char layout that MW accepts. No state change.
- **Globals / callees:** rec 0x6150+idx*0x5A, valid flags 0x60CB+idx, 0x9DBD/9DBE/9DBF, names fff806e9, cat_mode_codes fff806d0; `memch_valid`, toupper_inplace
- **Risk:** low - read-only
- **Note (#157):** the current decompile (T21 fixes, no `in_`/`unaff_` variables in this handler) confirms that `MR000` and numeric channels ≥ 100 leave the channel index uninitialised before `memch_valid`. This is a firmware bug, not a decompiler artifact **[fact]**; what it does depends on the stack contents.

### MS

- **Index / handler:** 56, cat_MS @ fffac4b6; switch case fffa4606; length tests `len==3:cat_MS@fffac4b6 \| len==5:cat_MS@fffac4b6` [fact]
- **Manual 2306-C:** METER SW. Set `MSP1P2;` (5), read `MS;` (3), answer `MSP1P2;` (5), AI O. P1 0 PO,1 COMP,2 ALC,3 VDD,4 ID,5 SWR; P2 0 fixed. Read row printed as MS; (3) though answer has P1P2
- **Read / answer (firmware):** MSn0; n=hex digit of 0x9C5B (0-5)
- **Set parameters (firmware):** P1 hex digit via hex2nib, must be 0..5 else error; P2 must be '0' else error; stores 0x9C5B
- **Class:** read+set
- **Behaviour:** Meter selection (0x9C5B 0..5); consumed by RM when 0x20B3D==1 to choose the default meter [inference].
- **Globals / callees:** 0x9C5B; hex2nib
- **Risk:** low - UI meter selection, RAM only

### MT

- **Index / handler:** 57, cat_MT @ fffac285; switch case fffa4589; length tests `len==6:cat_MT@fffac285 \| len>=8&&len<=19:cat_MT@fffac285` [fact]
- **Manual 2306-C:** MEMORY CHANNEL TAG WRITE. Set `MTP0P0P0P1P2x12;` (19), read `MTP0P0P0;` (6), answer `MTP0P0P0P1P2x12;` (19), AI X. P0 3 chars mem ch (001-099,P1L-P9U,5xx,EMG); P1 0 tag off,1 tag on; P2 12 tag ASCII chars
- **Read / answer (firmware):** MTcccf<12 name chars>; (19 chars): ccc echoed from command, f='1' if rec+5 bit7 set else '0', 12 name bytes from rec+0x4E
- **Set parameters (firmware):** ccc as MR/MW: [2]=='0' -> 001-099 -> idx-1, else 3-char name from table fff806e9 but only idx 99..117 accepted (P1L..P9U and 501); channel must already be valid (`memch_valid`) else error. [5] f must be '0' (clears rec+5 bit7) or '1' (sets it) else error. Name = chars [6..len-2], each 0x20..0x7D else error, padded with 0x20 to 12; name length 1..12 (len 8..19)
- **Class:** read+set
- **Behaviour:** Writes/reads the name tag of an existing memory channel (12 chars + flag bit) and PERSISTS to EEPROM via eeprom_save_memch [fact].
- **Globals / callees:** rec 0x6150+idx*0x5A (+5 flag bit7, +0x4E name[12]), valid flags 0x60CB; eeprom_save_memch -> eeprom_write(0x1A7A,&0x60C9,0x87) + eeprom_write(chanaddr,rec,0x5A), wrapped by eeprom_hdr_update (EEPROM header write counter @0); skipped if `supply_undervolt_check`()==1 (power-fail shutdown state)
- **Risk:** medium - EEPROM write of channel record on every successful set; RAM flag/name chars already changed if a later name char is invalid
- **Resolved (#157):** `eeprom_save_memch(ch)` writes the 0x87-byte memory header (EEPROM 0x1A7A ← RAM 0x60C9) and then EEPROM `0x1B01 + ch·0x5A` ← RAM `0x6150 + ch·0x5A`, 0x5A bytes, between two header updates; there is no u16 table, the multiplier is visible in the current decompile **[fact]**.

### MW

- **Index / handler:** 58, cat_MW @ fffac534; switch case fffa45dd; length tests `len==28:cat_MW@fffac534` [fact]
- **Manual 2306-C:** MEMORY CHANNEL WRITE. Set `MWP1P1P1P2x9P3x5P4P5P6P7P8P9P9P10;` (28), read `-` (-), answer `-` (-), AI X. Set: P1 000 or 001-099 or P1L-P9U (3 chars); P2 freq 9 digits Hz; P3 clar +/- and 4 digits (5 chars); P4 RX clar 0/1; P5 TX clar 0/1; P6 mode 0-F; P7 0-5; P8 0-2; P9 00; P10 0-2. Set only
- **Read / answer (firmware):** none (set-only)
- **Set parameters (firmware):** MWcccFFFFFFFFFsOOOOabMpTzzS (28): ccc chan as MT (001-099 or names idx<=117: P1L..P9U,501); F 9 dec digits Hz, must be 30000..75000000 (`freq_in_range`); s '+' or '-' required; OOOO 4 digits (validated numeric, VALUE DISCARDED, offset stored 0); a,b '0'/'1' (RX/TX clarifier, validated but DISCARDED: rec+1 bits3-4 cleared); M mode char must be in cat_mode_codes[0..14] else error; p ([22]) must be '1' else error; T tone mode '2'->1,'1'->2,'0'->0 (rec+3 bits3-5) else error; zz ([24][25]) must be '00'; S shift '2'->0,'1'->2,'0'->1 (rec+2 bits2-3) else error
- **Class:** set-only
- **Behaviour:** Programs a memory channel (freq, mode, tone mode, shift) and writes it to EEPROM. Unlike MT it does NOT require the channel to exist: it marks it valid (0x60CB+idx=1) [fact]. Also makes it the current memory channel of the active VFO (0x60C9/0x60CA) and re-applies it (`vfo_mark_edited`/16f6).
- **Globals / callees:** 0x60C9/0x60CA (current mem ch per VFO, written BEFORE later fields validated), rec 0x6150+idx*0x5A (+0..3 flags, +0x48/49=0, +0x4A..4D freq BE), 0x60CB+idx valid; FUN_fffb01df, eeprom_save_memch (EEPROM), `vfo_mark_edited`, `vfo_store_back`, `freq_in_range`
- **Risk:** medium - EEPROM memory-channel write and changes active memory channel; a late validation error still leaves 0x60C9/0x60CA changed
- **Resolved in part (#69):** the frequency loop uses 100,000,000 down to 1 (and 100/10/1, 1000..1 for the other fields) in the current decompile **[fact]**; the meaning of [22]=='1' is still open.

### MX

- **Index / handler:** 59, cat_MX @ fffac9ad; switch case fffa4640; length tests `len==3:cat_MX@fffac9ad \| len==4:cat_MX@fffac9ad` [fact]
- **Manual 2306-C:** MOX SET. Set `?` (?), read `?` (?), answer `?` (?), AI O. NO PAGE in manual (only in command list: Set/Read/Ans = O)
- **Read / answer (firmware):** MXn; n=0x20B2C as hex digit (0/1)
- **Set parameters (firmware):** First key_event_filter(0x302,2) must return nonzero else error; P1 hex digit: 0 -> if 0x20B2C!=0 then FUN_fffbe7e7+FUN_fffbe83f; 1 -> if 0x20B2C==0 then FUN_fffbe8d2; other -> error. No-op if already in requested state
- **Class:** read+set
- **Behaviour:** [inference] MOX-style transmit on/off from CAT: MX1 sets 0x1B4D9=2 and flag PTR_DAT_00025d54[0x28]=1 (transmit request), MX0 ends it. Key event 0x302 gate.
- **Globals / callees:** 0x20B2C (state), 0x1B4D9, 0x9C5D (toggled by FUN_fffbe83f), PTR_DAT_00025d54[0x28]; key_event_filter(0x302,2), FUN_fffbe8d2, FUN_fffbe7e7, FUN_fffbe83f
- **Risk:** high - MX1 keys the transmitter
- **Resolved (#69):** UI +0x28 (0x20B2C) is **PTT source 9 (MOX)**, read by `ptt_inputs_read`/`ptt_source_select`; 0x1B4D9 = 2 marks MOX on. `FUN_fffbe83f` (`key_mox_vox_short`) toggles **VOX** (0x9C5D) **[fact]** ([code/main/tx-protection.md](code/main/tx-protection.md), #144).

### NA

- **Index / handler:** 60, cat_NA @ fffaca47; switch case fffa467a; length tests `len==4:cat_NA@fffaca47 \| len==5:cat_NA@fffaca47` [fact]
- **Manual 2306-C:** NARROW. Set `NAP1P2;` (5), read `NAP1;` (4), answer `NAP1P2;` (5), AI O. P1 0 fixed; P2 0 off,1 on
- **Read / answer (firmware):** NA0n; n='0'/'1' narrow flag for current mode (see set)
- **Set parameters (firmware):** P1 must be '0' else error. Set: key_event_filter(0x30d,0) must pass else error; P2 char must be <=0x31 else error; '0' clears, anything else (incl. chars <'0') sets. By mode m of the active VFO (0x9DBD): m=0,1 -> bit 0x80 of mode-struct byte (struct 0x9D0D or 0x9D67 by VFO); m=2,3 -> bit 0x20; m=8,9,14 -> bit 0x04; m=12,13 -> bit 0x08; m=4,6,10 set '1' -> FUN_fffc4bd5(5/7/0xB) (switch to paired mode), m=5,7,11 set '0' -> FUN_fffc4bd5(4/6/10); read gives 0 for even m / 1 for odd pairs. Then `vfo_mark_edited`/16f6 apply and 0x20F10=1
- **Class:** read+set
- **Behaviour:** Narrow/wide filter selector: toggles a per-mode narrow bit or swaps between paired modes 4/5, 6/7, 10/11 [inference].
- **Globals / callees:** 0x9D0D/0x9D67, 0x9DBD, 0x20F10; `vfo_mode`, key_event_filter(0x30d), FUN_fffc4bd5, `vfo_mark_edited`, `vfo_store_back`
- **Risk:** medium - changes receive filter and may change operating mode
- **Resolved (#157):** the current decompile (T21 fixes, no `in_`/`unaff_` variables in this handler) initialises the flag to false; for a mode with no case (only 15, which no mode uses) nothing is read or written **[fact]**.

### NB

- **Index / handler:** 61, cat_NB @ fffacc65; switch case fffa46b8; length tests `len==4:cat_NB@fffacc65 \| len==5:cat_NB@fffacc65` [fact]
- **Manual 2306-C:** NOISE BLANKER. Set `NBP1P2;` (5), read `NBP1;` (4), answer `NBP1P2;` (5), AI O. P1 0 fixed; P2 0 off,1 on
- **Read / answer (firmware):** NBPn; P1 echoed, n=(struct+2 & 2)>>1
- **Set parameters (firmware):** Gate key_event_filter(0x303,0) else error; P2 '0' clears / '1' sets bit1 of struct+2 (struct=`vfo_rec_ptr`(0)); other -> error. P1 NOT checked
- **Class:** read+set
- **Behaviour:** Noise blanker on/off bit in current per-band/mode settings struct [inference].
- **Globals / callees:** struct from `vfo_rec_ptr`(0) +2 bit1; key_event_filter(0x303,0)
- **Risk:** low - DSP setting in RAM

### NL

- **Index / handler:** 62, cat_NL @ fffacce8; switch case fffa46f6; length tests `len==4:cat_NL@fffacce8 \| len==7:cat_NL@fffacce8` [fact]
- **Manual 2306-C:** NOISE BLANKER LEVEL. Set `NLP1P2P2P2;` (7), read `NLP1;` (4), answer `NLP1P2P2P2;` (7), AI O. P1 0 fixed; P2 000-010
- **Read / answer (firmware):** NL00nn; nn=0x9DC0 2-digit dec 00-10 (1c91 fixed '0')
- **Set parameters (firmware):** P1 must be '0' else error; [3] ignored (not checked); nn at [4..5] two digits, value <=10 else error; stores 0x9DC0; if 0x9ACE==0 notifies display param 0x38
- **Class:** read+set
- **Behaviour:** Level 0-10 (neighbour of NB so likely noise-blanker level) [inference].
- **Globals / callees:** 0x9DC0, 0x9ACE, 0x20CC6=0x38; FUN_fffc8cbb
- **Risk:** low - level in RAM

### NR

- **Index / handler:** 63, cat_NR @ ffface21; switch case fffa4734; length tests `len==4:cat_NR@ffface21 \| len==5:cat_NR@ffface21` [fact]
- **Manual 2306-C:** NOISE REDUCTION (DNR). Set `NRP1P2;` (5), read `NRP1;` (4), answer `NRP1P2;` (5), AI O. P1 0 fixed; P2 0 off,1 on
- **Read / answer (firmware):** NR0n; n=(struct+6 & 0x10)!=0
- **Set parameters (firmware):** P1 must be '0' else error; gate key_event_filter(0x304,0) else error; P2 '0' clears / '1' sets bit4 of struct+6 else error
- **Class:** read+set
- **Behaviour:** Noise reduction on/off bit (same struct byte as RL level) [inference].
- **Globals / callees:** struct `vfo_rec_ptr`(0)+6 bit4; key_event_filter(0x304,0)
- **Risk:** low - DSP setting in RAM

### OI

- **Index / handler:** 64, cat_IF_OI @ fffaa39c (arg 1, side 1 = record 0x9D63); switch case fffa4260; length tests `len==3:cat_IF_OI@fffaa39c` [fact]
- **Manual 2306-C:** OPPOSITE BAND (VFO-B) INFORMATION. Set `-` (-), read `OI;` (3), answer `OIP1P1P1P2x9P3x5P4P5P6P7P8P9P9P10;` (28), AI O. Answer same layout as IF but P2 = VFO-B freq: P1 mem ch 3; P2 9 digits; P3 clar +/- and 4 digits; P4 RX clar; P5 TX clar; P6 mode; P7; P8; P9 00; P10. Total 28
- **Read / answer (firmware):** OI + same 26-char body as IF but for the VFO-B record: chan byte 0x60CA, state 0x9DBF, clarifier flags 0x20F2A, record 0x9D63. Layout identical to IF: [0x1C90..92] chan 3 chars (001-099 / P1L..P9U / 501..515 / EMG, '000' if 0x9DBF in {1,3,5}); [93..9B] 9-digit Hz; [9C] sign; [9D..A0] 4-digit \|clarifier\|; [A1] RX-clar flag; [A2] TX-clar flag; [A3] mode via cat_mode_codes[rec[0]&0xF]; [A4] state char via table @0xFFF806DF[0x9DBF]; [A5] from rec[3] bits3-5 (1->'2',2->'1',else '0'); [A6][A7] '0','0'; [A8] from rec[2] bits2-3 (0->'2',2->'1',else '0'); [A9] ';'. Total 28 bytes
- **Set parameters (firmware):** none
- **Class:** read-only
- **Behaviour:** Same as IF but reports VFO-B (side 1) [fact: dispatch calls cat_IF_OI(1) for table idx 64 '@']
- **Globals / callees:** R 0x60CA,0x9DBF,0x20F2A,0x9D63[...]; `vfo_freq`(0,1)
- **Risk:** low: read-only
- **Resolved in part (#157):** as IF.

### OS

- **Index / handler:** 65, cat_OS @ fffacebe; switch case fffa4772; length tests `len==4:cat_OS@fffacebe \| len==5:cat_OS@fffacebe` [fact]
- **Manual 2306-C:** OFFSET (Repeater Shift). Set `OSP1P2;` (5), read `OSP1;` (4), answer `OSP1P2;` (5), AI O. P1 0 main,1 sub; P2 0 simplex,1 plus,2 minus (FM mode only)
- **Read / answer (firmware):** OSPn; P1 echoed; n='2' if (rec+2>>2&3)==0, '1' if ==2, else '0'
- **Set parameters (firmware):** P1 '0' -> active-VFO mode struct (0x9D09 or 0x9D63 by 0x9DBD), '1' -> the other one; P1 other -> pointer uninitialised (no error check!). Set errors if 0x9C5E==1, or current mode m not in {6,7,10,11}; P2 '2'->0, '1'->2, '0'->1 into bits2-3 of struct+2; other -> error; 0x20F10=1
- **Class:** read+set
- **Behaviour:** Repeater shift direction of the mode struct (set allowed only in modes 6,7,10,11); same bit coding as the shift field of MR/MW [inference].
- **Globals / callees:** 0x9D09/0x9D63, 0x9DBD, 0x9C5E, 0x20F10; `vfo_mode`
- **Risk:** medium - changes TX offset direction (FM-type modes only)
- **Note (#157):** the current decompile (T21 fixes, no `in_`/`unaff_` variables in this handler) confirms there is **no P1 check**: with P1 other than '0'/'1' the record pointer is left uninitialised and the handler uses a stale stack value. This is a firmware bug, not a decompiler artifact **[fact]**.

### PA

- **Index / handler:** 66, cat_PA @ fffad001; switch case fffa47b0; length tests `len==4:cat_PA@fffad001 \| len==5:cat_PA@fffad001` [fact]
- **Manual 2306-C:** PRE-AMP (IPO). Set `PAP1P2;` (5), read `PAP1;` (4), answer `PAP1P2;` (5), AI O. P1 0 fixed; P2 0 IPO,1 AMP1,2 AMP2
- **Read / answer (firmware):** PA0n; n='1' if (struct+5&3)==2, '2' if ==3, else '0'
- **Set parameters (firmware):** P1 NOT checked; P2 '0'->0, '1'->2, '2'->3 into low 2 bits of struct+5; other -> error
- **Class:** read+set
- **Behaviour:** Front-end selector (IPO/preamp-like) in per-band struct [inference].
- **Globals / callees:** struct `vfo_rec_ptr`(0)+5 &3
- **Risk:** low - RF front-end setting in RAM

### PB

- **Index / handler:** 67, cat_PB @ fffad0a2; switch case fffa47ea; length tests `len==4:cat_PB@fffad0a2 \| len==5:cat_PB@fffad0a2` [fact]
- **Manual 2306-C:** PLAY BACK. Set `PBP1P2;` (5), read `PBP1;` (4), answer `PBP1P2;` (5), AI X. P1 0 fixed; P2 0 stop,1-5 message ch playback
- **Read / answer (firmware):** PB0n; n = hex(0x20B7D+1) while 0x20B7C==1 (playing), else '0'
- **Set parameters (firmware):** P1 must be '0'. Set gate: key_event_filter(0x87,0) else error; FUN_fffe56bf()==1 (mode idx<2 or 4..7) else error; 0x20B97==1 -> error. P2 '0' -> stop; P2 >'5' -> error; otherwise: if idle start slot n (0x20B7C=1, 0x20CCC=hex(n), 0x20B7D=n-1; if FUN_fffb521a() then 0x20B2E=1), if already playing stop
- **Class:** read+set
- **Behaviour:** [inference] Plays/stops a stored voice message (slots 1-5); starts audio playback and, when the mode's TX bit is set (FUN_fffb521a), flags 0x20B2E which most likely transmits the message.
- **Globals / callees:** 0x20B7C,0x20B7D,0x20CCC,0x20B2E,0x20CD3,0x20CD4,0x20F1B,0x20CCE,0x20B97; key_event_filter(0x87), FUN_fffe56bf, FUN_fffb521a
- **Risk:** high - may key the transmitter to play a voice message
- **Resolved in part (#69):** 0x20B2E is **PTT source 11** (voice message on the air), cleared by the E8 status and the MIC PTT release ([code/main/tx-protection.md](code/main/tx-protection.md), #144) **[fact]**. Still open: the chars-below-'0' quirk (still true).
- **Resolved (#159):** **0x20B7C (UI +0x78)**: 0 = idle, 1 = playback (`PB0n;` sets it with the channel in 0x20B7D; a second `PB0n;` or `PB00;` stops it), 2 = recording (set by `FUN_fffc0210` from the armed `LM0n` state +0x1CA). `LM0;` answers the channel only while it is 2, and `RI` P3 maps it to 1/2 **[fact for the writers; the names follow the manual's RI P3]**.

### PC

- **Index / handler:** 68, cat_PC @ fffad241; switch case fffa4828; length tests `len==3:cat_PC@fffad241 \| len==6:cat_PC@fffad241` [fact]
- **Manual 2306-C:** POWER CONTROL. Set `PCP1P1P1;` (6), read `PC;` (3), answer `PCP1P1P1;` (6), AI O. P1 005-100
- **Read / answer (firmware):** PCnnn; nnn=per-mode-group power setting 000-100 dec
- **Set parameters (firmware):** 3 digits [2..4]; for modes 4,5 range 0..25 else error; other modes 0..100; value clamped to per-group max (0x9AEE/9AEF/9AF0/9AF1); stores per-group byte; if 0x9ACE==0 notifies display param 0x2C. Group by mode m: 4,5->0x9BFB (max 0x9AF1); 9->0x9BF9 (max 0x9AEF); 10->0x9BFA (max 0x9AF0); else 0x9BF8 (max 0x9AEE)
- **Class:** read+set
- **Behaviour:** TX output power setting per mode group (0-25 for modes 4/5) [inference].
- **Globals / callees:** 0x9BF8-0x9BFB, 0x9AEE-0x9AF1, 0x9ACE, 0x20CC6=0x2C; `vfo_freq`, FUN_fffb3371, `vfo_mode`
- **Risk:** medium - TX power setting (RAM; does not transmit)
- **Resolved (#157):** the current decompile (T21 fixes, no `in_`/`unaff_` variables in this handler) has no write through the `FUN_fffb3371` result; the `*puVar7 = (4<val)` store was a decompiler artifact **[fact]**.

### PL

- **Index / handler:** 69, cat_PL @ fffad467; switch case fffa4862; length tests `len==3:cat_PL@fffad467 \| len==6:cat_PL@fffad467` [fact]
- **Manual 2306-C:** SPEECH PROCESSOR LEVEL. Set `PLP1P1P1;` (6), read `PL;` (3), answer `PLP2P2P2;` (6), AI O. Set P1 001-100; Answer labelled P2 000 off,001-100 (3 digits)
- **Read / answer (firmware):** PLnnn; nnn=0x9BF1 dec 000-100
- **Set parameters (firmware):** 3 digits [2..4], must be 1..100 else error; stores 0x9BF1; if 0x9ACE==0 notifies display param 0x27
- **Class:** read+set
- **Behaviour:** Level of the feature whose on/off is PR0 (both share 0x9BF1: PR0 write 0 turns it off, 1 sets 50) [fact for sharing; label guess: speech-processor level].
- **Globals / callees:** 0x9BF1, 0x9ACE, 0x20CC6=0x27
- **Risk:** medium - TX audio processing level

### PR

- **Index / handler:** 70, cat_PR @ fffad595; switch case fffa48a0; length tests `len==4:cat_PR@fffad595 \| len==5:cat_PR@fffad595` [fact]
- **Manual 2306-C:** SPEECH PROCESSOR. Set `PRP1P2;` (5), read `PRP1;` (4), answer `PRP1P2;` (5), AI O. P1 0 speech processor,1 parametric mic EQ; P2 1 off,2 on
- **Read / answer (firmware):** PRPn; P echoed; P='0': n='0' if 0x9BF1==0 else '1'; P='1': n='0' if 0x9BF0==0 else '1'; other P: length 5 reply but n byte NOT written (stale buffer)
- **Set parameters (firmware):** P1 '0': P2 '0' -> 0x9BF1=0, '1' -> 0x9BF1=0x32 (50), else error. P1 '1': P2 '0' -> 0x9BF0=0, '1' -> 0x9BF0=1, else error. P1 other: silently ignored (no error)
- **Class:** read+set
- **Behaviour:** Two TX-audio feature on/off switches: PR0 acts on level variable 0x9BF1 (shared with PL), PR1 on flag 0x9BF0 [inference: processor / equalizer].
- **Globals / callees:** 0x9BF0, 0x9BF1
- **Risk:** medium - TX audio config
- **Resolved (#157):** the current decompile (T21 fixes, no `in_`/`unaff_` variables in this handler) computes the flag as `cmd[2] == '0'`; P1 '0' = 0x9BF1 (processor, set to 50 or 0), '1' = 0x9BF0 (parametric EQ on/off) **[fact]**.

### PS

- **Index / handler:** 71, cat_PS @ fffad696; switch case fffa48de; length tests `len==3:cat_PS@fffad696 \| len==4:cat_PS@fffad696` [fact]
- **Manual 2306-C:** POWER SWITCH. Set `PSP1;` (4), read `PS;` (3), answer `PSP1;` (4), AI X. P1 0 off,1 on
- **Read / answer (firmware):** PS1;  (constant)
- **Set parameters (firmware):** P1 '0' -> 0x20F4B=1, 0x20B39=0x10 (power-off request). P1 '1' -> 0x9DC5=1, `power_on_request` (sets PTR_DAT_00025d38[0x98]=1 and 0x1B3D0=1). other -> error
- **Class:** read+set
- **Behaviour:** PS0 requests radio power OFF [inference: the same 0x20F4B/0x20B39 pair is used by the low-voltage shutdown `supply_undervolt_check` after power_off_io(), with code 0x90]. PS1 only sets flags (power-on style notice) [guess]; read always answers PS1.
- **Globals / callees:** 0x20F4B, 0x20B39, 0x9DC5, 0x1B3D0, PTR_DAT_00025d38[0x98]; `power_on_request`
- **Risk:** high - PS0 switches the radio off (remote loses control)
- **Resolved (#69):** 0x20F4B makes `displink_tx_schedule` call `power_down_save` (frame `0x7F`, EEPROM save, `sw_reset`); code 0x10 stores 0x9DC5 = 0, so the radio stays off ([cat-commands.md](cat-commands.md#ext-zz), #142). `PS1` sends frame `0x60` with byte 0xB3 = 1, which makes the DISPLAY switch the radio on ([code/system.md](code/system.md) C6, #140) **[fact]**.

### QI

- **Index / handler:** 72, cat_QI @ fffad704; switch case fffa4918; length tests `len==3:cat_QI@fffad704` [fact]
- **Manual 2306-C:** QMB STORE. Set `QI;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Read / answer (firmware):** none (no reply)
- **Set parameters (firmware):** none (command is the action)
- **Class:** action
- **Behaviour:** Quick-memory store: pushes the active VFO's 0x5A-byte settings into a ring of up to 10 slots (0x9023+slot*0x5A, bitmask 0x9012/0x9013, count 0x9014, last slot 0x9015); if the memory-type-mode checks both hold it just beeps/aborts (`beep_request`(3)) [inference].
- **Globals / callees:** 0x9012-0x9015, 0x9023.., 0x9D09/0x9D63, 0x9DBD; `qmb_store`
- **Risk:** medium - overwrites a quick-memory slot in RAM (no EEPROM call seen in handler chain)

### QR

- **Index / handler:** 73, cat_QR @ fffad709; switch case fffa492e; length tests `len==3:cat_QR@fffad709` [fact]
- **Manual 2306-C:** QMB RECALL. Set `QR;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Read / answer (firmware):** none (no reply)
- **Set parameters (firmware):** none (command is the action)
- **Class:** action
- **Behaviour:** Quick-memory recall: if any slot is occupied (mask 0x9012/13 & 0x3FF != 0) leaves split/dual state, forces the VFO into recall mode and re-applies it; otherwise error beep `beep_request`(3) [inference].
- **Globals / callees:** 0x9012/13, 0x9C5E, 0x9DBE/9DBF; `qmb_recall`
- **Risk:** medium - changes active VFO/memory state and frequency

### QS

- **Index / handler:** 74, cat_QS @ fffad70e; switch case fffa4944; length tests `len==3:cat_QS@fffad70e` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Read / answer (firmware):** none
- **Set parameters (firmware):** none
- **Class:** error-only
- **Behaviour:** Accepted length 3 but the handler only sets the error flag: always answers '?;' [fact].
- **Globals / callees:** 0x464A=1
- **Risk:** low - no function

### RA

- **Index / handler:** 75, cat_RA @ fffad718; switch case fffa495a; length tests `len==4:cat_RA@fffad718 \| len==5:cat_RA@fffad718` [fact]
- **Manual 2306-C:** RF ATTENUATOR. Set `RAP1P2;` (5), read `RAP1;` (4), answer `RAP1P2;` (5), AI O. P1 0 fixed; P2 0 off,1 6dB,2 12dB,3 18dB
- **Read / answer (firmware):** RA0n; n=hex(struct+3 & 3) 0-3
- **Set parameters (firmware):** P1 must be '0' else error; P2 hex digit 0..3 into low 2 bits of struct+3 (else error flag, but 0x20F10 still set); 0x20F10=1
- **Class:** read+set
- **Behaviour:** Attenuator-like 2-bit RF front-end selector in per-band struct [inference].
- **Globals / callees:** struct `vfo_rec_ptr`(0)+3 &3, 0x20F10
- **Risk:** low - RF front-end setting in RAM

### RC

- **Index / handler:** 76, (switch default); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Class:** error-only
- **Behaviour:** No case in cat_dispatch: always '?;' [fact].
- **Risk:** low -

### RD

- **Index / handler:** 77, (switch default); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Class:** error-only
- **Behaviour:** No case in cat_dispatch: always '?;' [fact].
- **Risk:** low -

### RG

- **Index / handler:** 78, cat_RG @ fffad7ae; switch case fffa4998; length tests `len==4:cat_RG@fffad7ae \| len==7:cat_RG@fffad7ae` [fact]
- **Manual 2306-C:** RF GAIN. Set `RGP1P2P2P2;` (7), read `RGP1;` (4), answer `RGP1P2P2P2;` (7), AI O. P1 0 fixed; P2 000-255
- **Read / answer (firmware):** RG0nnn; nnn dec of 0x20BA7 (or 0x464D when 0x9AB6!=0)
- **Set parameters (firmware):** P1 must be '0'; 3 digits [3..5] byte-accumulated (weights 100/10/1, value wraps mod 256 if >255); stores 0x464D always and 0x20BA7 only when 0x9AB6==0
- **Class:** read+set
- **Behaviour:** RF gain 000-255 (single global byte).
- **Globals / callees:** 0x20BA7, 0x464D, 0x9AB6
- **Risk:** low - RX gain in RAM

### RI

- **Index / handler:** 79, cat_RI @ fffad8e3; switch case fffa49d6; length tests `len==4:cat_RI@fffad8e3` [fact]
- **Manual 2306-C:** RADIO INFORMATION. Set `-` (-), read `RIP1;` (4), answer `RIP1P2P3P4P5P6P7P8;` (11), AI O. Read RIP1; Answer: P1 0 fixed; P2 0 normal,1 Hi-SWR; P3 0 stop,1 recording,2 playing; P4 0 RX,1 TX,2 TX inhibit; P5 0 fixed; P6 tuner 0 stopped,1 tuning; P7 scan 0 stop,1 scanning,2 pause; P8 0 SQL closed,1 open
- **Read / answer (firmware):** RI0abc0def; (11 chars): a=0x20B6D!=0; b=hex(FUN_fffe0755()) 0/1/2 (1 if 0x20CCD==1\|\|0x20B7C==2\|\|0x20B96==1; 2 if 0x20CD0/20CD1/20F01/20B7C==1 cases); c=0x20B3D ('0','1', else '2'); literal '0'; d='1' if 0x20B40==2\|\|0x20B41==2\|\|0x20F0C!=0; e=0x20F1C ('0', else '1', or '2' if 0x20F1D==1 && `af_mute_get`()!=1); f=(0x20B38&0x10)!=0
- **Set parameters (firmware):** none (read only; P1 must be '0' else error)
- **Class:** read-only
- **Behaviour:** Status snapshot of the radio (TX state, scan state, voice playback, etc.) [inference from the flags]. No state change.
- **Globals / callees:** 0x20B6D,0x20B3D,0x20B40,0x20B41,0x20F0C,0x20F1C,0x20F1D,0x20B38,0x20CCD,0x20B7C,0x20B96,0x20CD0/1,0x20F01; FUN_fffe0755, `af_mute_get`
- **Risk:** low - read-only
- **Resolved in part (#157):** the flags shared with the busy guard are explained under `SV` (scan +0x418, tune cycle +0x408, voice-message playback +0x78, keyer/message states +0x1C9/+0x1CC/+0x1CD) **[fact]**; 0x20B6D, 0x20B38, 0x20B96 and 0x20F1D are still open.
- **Resolved (#159)** (each matches the manual's RI field) **[fact for the writers]**:
  - **0x20B6D** (P2) = **HI-SWR**: `swr_meter_protect` (0xFFFB7545) sets it to 1/2 (blink phase) after 9 TX passes with SWR outside [1, 5) and clears it after 9 good passes or on RX.
  - **P3** comes from `FUN_fffe0755`: 1 (recording) when 0x20B96 (`LM1`), 0x20B7C = 2 or +0x1C9 is set; the keyer/message send states and 0x20F01 lead to the other values.
  - **0x20B38** (P8 = bit 4) is the **status-LED byte** that `FUN_fffb8d77` (an `io_task` sub-task) builds every pass: bit 4 = BUSY (0x20B48, squelch open), bit 5 = TX lamp (on while 0x20B6B = 1, blinking when the TX frequency is not allowed), bit 7 = VOX on (0x9C5D, not in CW/RTTY).
  - **0x20F1D** (P7 = 2) = UI +0x419, **scan paused** (read only while scan +0x418 runs and the audio is not muted). It has no direct writer in the decompile; it is written through the UI-state pointer **[inference]**.

### RL

- **Index / handler:** 80, cat_RL @ fffada46; switch case fffa4a00; length tests `len==4:cat_RL@fffada46 \| len==6:cat_RL@fffada46` [fact]
- **Manual 2306-C:** NOISE REDUCTION (DNR) LEVEL. Set `RLP1P2P2;` (6), read `RLP1;` (4), answer `RLP1P2P2;` (6), AI O. P1 0 fixed; P2 01-15
- **Read / answer (firmware):** RL0nn; nn=(struct+6 & 0xF) 2-digit dec
- **Set parameters (firmware):** P1 must be '0'; nn digits [3..4], value must be 1..15 else error; writes low nibble of struct+6; if 0x9ACE==0 notifies display param 0x39; 0x20F10=1
- **Class:** read+set
- **Behaviour:** Level of the feature whose on/off is NR0 (shares byte struct+6: level low nibble, NR bit4) -> noise-reduction level 1-15 [inference].
- **Globals / callees:** struct `vfo_rec_ptr`(0)+6, 0x9ACE, 0x20CC6=0x39, 0x20F10
- **Risk:** low - DSP setting in RAM

### RM

- **Index / handler:** 81, cat_RM @ fffadb7d; switch case fffa4a3e; length tests `len==4:cat_RM@fffadb7d` [fact]
- **Manual 2306-C:** READ METER. Set `-` (-), read `RMP1;` (4), answer `RMP1P2P2P2P3P3P3;` (10), AI O. Read P1 meter select 1 S(main),2 -,3 COMP,4 ALC,5 PO,6 SWR,7 IDD,8 VDD (text also says P1=0 for set row, unclear); Answer P1 same, P2 000-255, P3 000 fixed
- **Read / answer (firmware):** RMPnnn000; P echoed, nnn=meter byte (3 dec digits), then literal '000'
- **Set parameters (firmware):** none (read only). P1 hex digit: 0 -> auto (0x20B3D==1: by 0x9C5B MS value 1->3,2->4,3->8,4->7,5->6, else 5; not TX: 1); valid 1,3,4,5,6,7,8 else error. Sources: 1->0x1204A, 3->0x12049, 4->0x12045, 5->(0x9AF6==0?0x12048:0x1204B), 6->0x12046, 7->0x12044, 8->0x12043. Value forced to 0 for all except 1/8 when 0x20B3D==0, and for P1==1 while 0x20B3D!=0
- **Class:** read-only
- **Behaviour:** Reads a live meter value (S-meter / TX meters) [inference].
- **Globals / callees:** 0x12043-0x1204B, 0x20B3D, 0x9C5B, 0x9AF6; `meter_get_vdd`/6e98/6e21/6e6a/6e30/6e12/6ea7
- **Risk:** low - read-only

### RS

- **Index / handler:** 82, (switch default); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Class:** error-only
- **Behaviour:** No case in cat_dispatch: always '?;' [fact].
- **Risk:** low -

### RT

- **Index / handler:** 83, (switch default); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Class:** error-only
- **Behaviour:** No case in cat_dispatch: always '?;' [fact].
- **Risk:** low -

### RU

- **Index / handler:** 84, (switch default); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual:** not documented (absent from 2211-A and 2306-C).
- **Class:** error-only
- **Behaviour:** No case in cat_dispatch: always '?;' [fact].
- **Risk:** low -

### SC

- **Index / handler:** 85, cat_SC @ fffadcd6; switch case fffa4a68; length tests `len==3:cat_SC@fffadcd6 \| len==4:cat_SC@fffadcd6` [fact]
- **Manual 2306-C:** SCAN. Set `SCP1;` (4), read `SC;` (3), answer `SCP1;` (4), AI O. P1 0 off,1 on up,2 on down
- **Read / answer (firmware):** SCn; n='0' not scanning (0x20F1C!=1), '1' if direction flag 0x18876==0, '2' if !=0
- **Set parameters (firmware):** Set errors if 0x20B3D!=0 (TX). P1 '0': if 0x20F1C==1 stop scan (`scan_stop`). P1 '1': if `scan_allowed`()==1 start scan dir 0 (`scan_start_up`: 0x18876=0, flag [0x418]=1). P1 '2': same with dir 1 (`scan_start_down`). Otherwise silently ignored; other P1 -> error
- **Class:** read+set
- **Behaviour:** Starts/stops scanning, with a direction flag [inference].
- **Globals / callees:** 0x20F1C, 0x18876, 0x18877, 0x9AC4, 0x20B3D, PTR_DAT_00025d7c[0x418]; `scan_allowed`, `scan_stop`/5c7e/5caf
- **Risk:** low - scan, no TX

### SD

- **Index / handler:** 86, cat_SD @ fffadd9a; switch case fffa4aa2; length tests `len==3:cat_SD@fffadd9a \| len==5:cat_SD@fffadd9a` [fact]
- **Manual 2306-C:** SEMI BREAK-IN DELAY TIME. Set `SDP1P1;` (5), read `SD;` (3), answer `SDP1P1;` (5), AI O. P1 00-33: 00=30,01=50,02=100,03=150,04=200,05=250 ms; 06-33 = 300-3000 ms in 100 ms steps
- **Read / answer (firmware):** SDnn; nn=DAT_00009c05 as 2 dec digits (00-33)
- **Set parameters (firmware):** nn 2 dec digits (non-digit -> error), value 00-33 (>0x21 -> error) -> DAT_00009c05
- **Class:** read+set
- **Behaviour:** Stores a 0-33 setting; if DAT_00009ace==0 also sets DAT_00020cc6=0x32, calls FUN_fffc8cbb(0x32) (menu-item table lookup) and FUN_fffc8d8c (display refresh/value popup). Same shape as VD and VG. [fact] Which radio parameter it is cannot be derived from this code alone; adjacency with VD/VG makes a break-in/VOX-style timing setting plausible [guess]
- **Globals / callees:** DAT_00009c05 (rw); DAT_00009ace (r); DAT_00020cc6 (w=0x32); FUN_fffc8cbb@fffc8cbb; FUN_fffc8d8c@fffc8d8c; nib2hex
- **Risk:** medium: persistent-looking radio setting, no key/TX action
- **Resolved (#157):** 0x9C05 is the CW break-in delay, read by the keyer's TX function `FUN_fffbaa81` **[fact]**. `FUN_fffc8cbb(id)` is the **pop-up duration** lookup: it returns the display time of on-screen pop-up `id` for the DISPLAY SETTING **POP-UP TIME** (0x9B0E, 0..2); for ids 0x28, 0x29, 0x2A and 0x32 that is 800 / 1000 / 1200 (timer units) **[fact, ROM tables at 0xFFF834D6]**. So the "menu id" is the id of the level pop-up the DISPLAY shows (0x32 for this command).

### SF

- **Index / handler:** 87, cat_SF @ fffadeb6; switch case fffa4adc; length tests `len==4:cat_SF@fffadeb6 \| len==5:cat_SF@fffadeb6` [fact]
- **Manual 2306-C:** SUB DIAL. Set `SFP1P2;` (5), read `SFP1;` (4), answer `SFP1P2;` (5), AI O. P1 0 FUNC knob,1 DSP knob; P2 (P1=0) 0 -,1 SCOPE LEVEL,2 PEAK,3 COLOR,4 CONTRAST,5 DIMMER,6 M-GROUP,7 MIC GAIN,8 PROC LEVEL,9 AMC LEVEL,A VOX GAIN,B VOX DELAY,C ANTI VOX,D RF POWER,E MONI LEVEL,F CW SPEED,G CW PITCH,H BK-DELAY; (P1=1) 0 -,1 SHIFT,2 WIDTH,3 NOTCH,4 CONTOUR,5 APF
- **Read / answer (firmware):** SFPx; P=P1 echoed from request (1c90, '0' or '1'); x=1 char. P1='0': from DAT_00009dc9 via map 0->'1',1->'2',3->'3',4->'4',5->'5',6->'6',7->'7',9->'8',10->'9',11->'A',12->'B',13->'C',14->'D',15->'E',0x12->'F',0x13->'G',0x14->'H', anything else (2,8,0x10,0x11,>0x14)->'0'. P1='1': from DAT_00020b7e via 0x1d->'1',0x1e->'2',0x1f->'3',0x20->'4',0x21->'5', else '0'. P1 other than 0/1 writes no x (stale 1c91 byte) [quirk]
- **Set parameters (firmware):** P1 '0' or '1' (selector); P2 x. For P1='0': x one of '1'-'9','A'-'H' (reverse of the read map) -> DAT_00009dc9 AND DAT_00009c08 (same value); other chars incl '0' -> error. For P1='1': x '1'-'5' -> DAT_00020b7e=0x1d/0x1e/0x1f/0x20/0x21 and DAT_00020b77=0/1/2/3/3, then FUN_fffc89b0(); other x -> error. P1 other than 0/1 on set is silently ignored (no error)
- **Class:** read+set
- **Behaviour:** Two-part selector: P1='0' picks one of 17 values (letters up to H) kept in DAT_00009dc9/DAT_00009c08; P1='1' picks one of 5 items (0x1d-0x21) of a DSP/IF-filter style selector (SH also writes DAT_00020b7e=0x1e / DAT_00020b77=1 and calls the same FUN_fffc89b0, so item '2' is the width item) [inference]. Exact UI meaning unknown. Decompiler lost the 'P1==0' flag (in_R14) so the P1 split is reconstructed from control flow [inference]
- **Globals / callees:** DAT_00009dc9 (rw), DAT_00009c08 (w), DAT_00020b7e (rw), DAT_00020b77 (w), FUN_fffc89b0@fffc89b0
- **Risk:** medium: changes selector state that probably feeds RX DSP/filter menus; no TX
- **Resolved in part (#157):** the current decompile (T21 fixes, no `in_`/`unaff_` variables in this handler) computes the flag as `cmd[2] != '0'` **[fact]**. `FUN_fffc89b0` opens the FUNC-knob function display (UI +0x70 = 1, 5 s timer 0x44) **[fact]**. 0x9C08 (read by `displink_build_37`) and 0x9DC9 (read by the status block and `FUN_fffc6c20`) are the stored function selections **[inference]**.

### SH

- **Index / handler:** 88, cat_SH @ fffae2ca; switch case fffa4b1a; length tests `len==4:cat_SH@fffae2ca \| len==7:cat_SH@fffae2ca` [fact]
- **Manual 2306-C:** WIDTH. Set `SHP1P2P3P3;` (7), read `SHP1;` (4), answer `SHP1P2P3P3;` (7), AI O. P1 0 fixed; P2 0 fixed; P3 00-23 bandwidth index (Table 3, mode dependent; 00 default)
- **Read / answer (firmware):** SH00nn; nn = 2 dec digits: index+1 of the stored width in the per-mode table (wraps to 00 if >23 for modes 0/1, >21 for others); fixed by mode for modes 5->01, 4/7/11->02, 6/10->03. Mode = `vfo_mode`(0) (active VFO mode). Read only checks P1=='0'
- **Set parameters (firmware):** P1 '0' required (else error); P2 '0' required on set; nn 2 dec digits at [4..5]. nn=00 -> per-mode default (modes 0/1: 3000 stored at +0x10; modes 2,3: 500 at +0x1a; modes 12,13: 500 at +0x24; modes 8,9,14: 0xc80=3200 at +0x2e); nn>=1 -> u16 = FUN_fffb3775(mode,nn-1) (max nn 23 for modes 0/1, 21 for the others; above max or 0xffff -> error); modes 4-7,10,11 (fixed) -> error on set
- **Class:** read+set
- **Behaviour:** Selects a width/bandwidth entry by index for the active VFO's mode; stores the u16 in the per-VFO struct (`vfo_rec_ptr` base), sets DAT_00020b7e=0x1e, DAT_00020b77=1, FUN_fffc89b0(), DAT_00020f10=1, then `vfo_mark_edited` and `vfo_store_back` (apply) [inference: IF/DSP width]. Mode numbering unknown; 0/1 have 23 steps, 2,3,8,9,12-14 have 21 [fact]
- **Globals / callees:** `vfo_rec_ptr`, `vfo_mode`(0), FUN_fffb36ff@fffb36ff (value->index; tables fff882ba (23 entries) / fff882e8 (21 entries)), FUN_fffb3775@fffb3775 (index->value), DAT_00020b7e/b77/20f10 (w), DAT_00009dbd (active VFO), FUN_fffc89b0, `vfo_mark_edited`, `vfo_store_back`
- **Risk:** medium: changes RX filter/width setting and applies it live
- **Resolved (#157):** width tables in Hz **[fact, ROM]**. SSB (modes 0/1), 23 entries at 0xFFF882BA: 300, 400, 600, 850, 1100, 1200, 1500, 1650, 1800, 1950, 2100, 2250, 2400, 2450, 2500, 2600, 2700, 2800, 2900, 3000, 3200, 3500, 4000. Other modes, 21 entries at 0xFFF882E8: 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 600, 800, 1200, 1400, 1700, 2000, 2400, 3000, 3200, 3500, 4000. So `SH0nn` index nn−1 is the width in Hz, matching the manual's Table 3.

### SM

- **Index / handler:** 89, cat_SM @ fffae64b; switch case fffa4b54; length tests `len==4:cat_SM@fffae64b` [fact]
- **Manual 2306-C:** S METER. Set `-` (-), read `SMP1;` (4), answer `SMP1P2P2P2;` (7), AI X. P1 0 fixed; P2 000-255
- **Read / answer (firmware):** SM0nnn; nnn = DAT_0001204a (via `meter_get_s`) as 3 dec digits 000-255 (meter value; computed in fffb7128 file from ADC with slope 1.95/offset 177, clamped 0-255, forced 0 when DAT_00020b3d!=0)
- **Set parameters (firmware):** none: P1 must be '0' else error (len 4 only, no set form)
- **Class:** read-only
- **Behaviour:** Returns the current meter reading as 3 digits; 0 while DAT_00020b3d!=0 so it is the RX signal meter [inference]
- **Globals / callees:** DAT_0001204a (r), `meter_get_s`@fffb6ea7; reply 0x1C8E len 7
- **Risk:** low: read-only

### SQ

- **Index / handler:** 90, cat_SQ @ fffae6cc; switch case fffa4b7a; length tests `len==4:cat_SQ@fffae6cc \| len==7:cat_SQ@fffae6cc` [fact]
- **Manual 2306-C:** SQUELCH LEVEL. Set `SQP1P2P2P2;` (7), read `SQP1;` (4), answer `SQP1P2P2P2;` (7), AI O. P1 0 fixed; P2 000-100
- **Read / answer (firmware):** SQ0nnn; nnn=round(level*100/255) 3 dec digits 000-100, level = DAT_00020ba7 if DAT_00009ab6!=0 else DAT_0000464e. P1 not checked on read; '0' hard-coded in reply
- **Set parameters (firmware):** SQ P1 nnn: nnn at [3..5], P1 NOT validated; nnn 3 dec digits, >100 -> error; stored level=round(nnn*255/100) -> DAT_0000464e, and also -> DAT_00020ba7 if DAT_00009ab6!=0
- **Class:** read+set
- **Behaviour:** Squelch-type level 0-100%, stored as 0-255 byte in one of two RAM cells selected by DAT_00009ab6 [inference]
- **Globals / callees:** DAT_0000464e (rw), DAT_00020ba7 (rw), DAT_00009ab6 (r)
- **Risk:** low: level setting, RAM cells only (no EEPROM call seen here)
- **Resolved in part (#69):** 0x9AB6 is **RF/SQL VR** (`EX030102`, 0..2: what the RF/SQL knob controls) **[fact]**. 0x464E lies just below the EEPROM mirror (0x464F..), so it is not saved; 0x20BA7 is RAM-only UI state **[fact for the addresses]**.

### SS

- **Index / handler:** 91, cat_SS @ fffae850; switch case fffa4bb4; length tests `len==5:cat_SS@fffae850 \| len==10:cat_SS@fffae850` [fact]
- **Manual 2306-C:** SPECTRUM SCOPE. Set `SSP1P2P3P4P5P6P7;` (10), read `SSP1P2;` (5), answer `SSP1P2P3P4P5P6P7;` (10), AI O. P1 0 fixed; P2 0 speed,1 peak,2 marker,3 color,4 level,5 span,6 mode,7 AF-FFT/osc; P3-P7 per P2: 0 speed 0-5; 1 peak 0-4; 2 marker 0/1; 3 color 0-9,A; 4 level P3-P7 = 5 chars +/-nn.n (0.5dB); 5 span 0-9; 6 mode 0-A; 7 P3 AF-FFT att, P4 osc level, P5 osc time 0-5; unused P = 0
- **Read / answer (firmware):** SS0Sv0000; (len 10): 1c8e..1c91 = 'S','S','0',S copied from request; S=selector hex char 0-8; v=1 char then '0000' filler, except sel 4 = sign + nn.d and sel 7 = four digits + '0'. Sel 0: v=5 if FUN_fffc4f8f()==1 (DAT_0001b4df) else DAT_00009c5a. Sel 1: DAT_00009be6. Sel 2: DAT_00009be7. Sel 3: DAT_00009be8. Sel 4: byte b=*`scope_level_ptr`(`vfo_freq`(DAT_00020b6b,2),DAT_00020b6b): if b<0x3c '-' and (0x3c-b) else '+' and (b-0x3c), halved, printed as 'nn.d' with .0/.5, i.e. -30.0..+30.0 in 0.5 steps (SS04+05.5;). Sel 5: *`scope_span_ptr`(`vfo_freq`(0,2)) (0-9). Sel 6: composed from DAT_00009c35/c36/c38 (see Resolved below). Sel 7: DAT_00009c39,DAT_00009c3b,DAT_00009c3c,DAT_00009c3a then '0'. Sel 8: DAT_00020f1f
- **Set parameters (firmware):** P1 must be '0' else error; P2 selector = hex digit (hex2nib), valid 0-8 else error. Set len 10 = 'SS0S' + 5 chars + ';'. Sel 0: [4]=0-5 (5 -> FUN_fffc4f9e(1) sets DAT_0001b4df=1; 0-4 -> DAT_00009c5a=v then FUN_fffc4f9e(0) copies to DAT_0001b4e0 and clears DAT_0001b4df), [5..8] must be '0000'. Sel 1: v 0-4 -> DAT_00009be6. Sel 2: v 0-1 -> DAT_00009be7. Sel 3: v 0-10 (0xA) -> DAT_00009be8. Sel 4: [4] '+'/'-', [5..6] 2 dec digits <=30, [7] '.', [8] '0' or '5'; stored byte=(30+nn)*2 (+1 if .5) for '+', (30-nn)*2 (-1 if .5) for '-', must be <=0x78 -> *`scope_level_ptr`(...). Sel 5: v 0-9 -> *`scope_span_ptr`(`vfo_freq`(0,2)), [5..8]=0000. Sel 6: v 0-0xB: 0,1,2 -> DAT_00009c36=1,DAT_00009c35=v; 3 -> c36=0,c35=0,c38=2,c3d=1; 4 -> c36=0,c35=0,c38=1,c3d=0; 6 -> c36=0,c35=1,c38=2,c3d=1; 7 -> c36=0,c35=1,c38=1,c3d=0; 9 -> c36=0,c35=2,c38=2,c3d=1; 10 -> c36=0,c35=2,c38=1,c3d=0; 5,8,11 and >11 -> error; [5..8]=0000. Sel 7: [8] must be '0'; [4],[5] each '0'-'2', [6] '0'-'5', [7] '0'-'2' -> DAT_00009c39,c3b,c3c,c3a. Sel 8: v 0-1 -> DAT_00020f1f, [5..8]=0000. Any [5..8] mismatch for sels 0,1,2,3,5,6,8 -> error
- **Class:** read+set
- **Behaviour:** Multi-selector settings block: 9 sub-parameters (sel 0..8) in one command, all RAM variables (sel 4 a signed +/-30.0 in 0.5 steps, sel 6 a combo of three fields, sel 7 four small digits). Sel 0 value 5 goes through a separate flag DAT_0001b4df. Parameter shapes suggest spectrum/waterfall-scope style display settings [guess]; no TX, no frequency change, no key event, no EEPROM call in this function [fact]
- **Globals / callees:** DAT_00009c5a, DAT_0001b4df/b4e0 (FUN_fffc4f9e@fffc4f9e, FUN_fffc4f8f@fffc4f8f), DAT_00009be6/be7/be8, DAT_00020b6b (selects per-VFO row), `vfo_freq`, `scope_level_ptr`@fffa150c, `scope_span_ptr`@fffa1541, DAT_00009c35/c36/c38/c3d, DAT_00009c39/c3a/c3b/c3c, DAT_00020f1f
- **Risk:** low: display-type settings stored in RAM, no TX/key/EEPROM call here
- **Resolved (#159): sel 6.** The current decompile (T21g rebuild) has no junk stores in this arm, and the same tree appears in two more functions, `FUN_fff96dde` (the scope-mode byte of the DISPLAY status frame, `DAT_000016a2` in `displink_build_status`) and the `SS` AI reporter `FUN_fffe0fe6` (its `param_1 == 6` arm) **[fact]**. The fields match the manual's P3 list: **0x9C36** = 1 for 3DSS, 0 for waterfall; **0x9C35** = CENTER 0 / CURSOR 1 / FIX 2; **0x9C38** = waterfall size, 1 NORMAL, 2 EXPAND; **0x9C3D** = the EXPAND flag (the front-panel toggle `FUN_fffbc91a` flips 0x9C3D and 0x9C38 together: 0/1 or 1/2). Defaults (ROM 0xFFF80E22 → 0x9C35..): c35 0, c36 1, c38 1, c3d 0 (3DSS CENTER) **[fact]**.
  - Read: 3DSS → c35 (0..2). Waterfall → 3 + 3·c35 + {c38 = 0: 0, 1: 1, else 2}, so NORMAL reads 4/7/A and **EXPAND reads 5/8/B** **[fact]**.
  - Set: 3/6/9 (EXPAND) store c38 = 2; 4/7/A (NORMAL) store c38 = 1; 5, 8, B are refused **[fact]**.
  - So NORMAL round-trips, and EXPAND set as `SS0630000;` reads back as `SS0650000;` (5/8/B are "-" in the manual). Nothing writes c38 = 0, so the read codes 3/6/9 are dead. This is a firmware inconsistency in V01-12, not a decompiler artifact **[fact for the code; radio check not done]**. The DISPLAY frame uses the same 3..B coding as the read path, so the display side is consistent with itself **[inference]**.
- **Resolved (#159): the other sel details.** `puVar9` is gone from the current decompile. `vfo_freq` (0xFFFB357C) returns the record frequency in Hz. `scope_level_ptr` picks a byte through the per-frequency-range pointer tables 0xFFF88648 (side 0) / 0xFFF88680 (side 1), indexed by `freq_range_index`; `scope_span_ptr` uses the 8-byte-stride table at 0xFFF885AC, or the second pointer of each pair (0xFFF885B0..) in FIX mode (c35 = 2), so FIX has its own span per range **[fact]**.

### ST

- **Index / handler:** 92, cat_ST @ fffaf3b5; switch case fffa4bee; length tests `len==3:cat_ST@fffaf3b5 \| len==4:cat_ST@fffaf3b5` [fact]
- **Manual 2306-C:** SPLIT. Set `STP1;` (4), read `ST;` (3), answer `STP1;` (4), AI O. P1 0 off,1 on
- **Read / answer (firmware):** STn; n='0' if DAT_00009c5e==0 else '1'
- **Set parameters (firmware):** P1 '0' or '1' else error; key_event_filter(0x305,0) must pass and DAT_00020b3d must be 0 else error. '0': if DAT_00009c5e==1 call `split_toggle`() (toggle off); '1': if DAT_00009c5e==0 call `split_toggle`() (toggle on). No-op if already in that state
- **Class:** read+set
- **Behaviour:** Turns split (0x9C5E) on/off, the same flag as `FT` [fact] (T10g, [radio-control.md](code/main/radio-control.md#split-clarifier-ab)). `split_toggle` saves/restores DAT_00009dbe/dbf (per-VFO state bytes, mirrored to UI struct offsets 0x484/0x485) and sets DAT_00009dc7/c8 [fact]. Emulates front-panel key code 0x305
- **Globals / callees:** DAT_00009c5e (rw), DAT_00020b3d (r, TX flag, see [tx-protection.md](code/main/tx-protection.md)), key_event_filter(0x305), `split_toggle`@fffbeca5 (calls FUN_fffe3d24, `vm_toggle_core`, FUN_fff9cdb0, FUN_fffc2794 if DAT_00020b9b==1), UI struct PTR_DAT_00025d54
- **Risk:** medium: changes operating state (VFO routing), blocked while DAT_00020b3d!=0
- **Resolved (#157):** `FUN_fffe3d24` stops any running message playback or keyer send before the split change: if UI +0x94, +0x1C9, +0x1CC, +0x1CD or +0x1D1 is set it clears them and +0x417 and sets the keyer state +0x2B = 7 **[fact]**.

### SV

- **Index / handler:** 93, cat_SV @ fffaf46e; switch case fffa4c28; length tests `len==3:cat_SV@fffaf46e` [fact]
- **Manual 2306-C:** SWAP VFO. Set `SV;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Read / answer (firmware):** (no reply)
- **Set parameters (firmware):** none ('SV;' only, dispatched with is_set=1)
- **Class:** action
- **Behaviour:** Front-panel key 0x30a action: toggles active VFO A/B (`vfo_ab_toggle`: clears DAT_00009c5e, if active-VFO mode is 1 flips DAT_00009dbd, else steps the mode toward 1 first via `vm_toggle` / `vfo_reload`) [inference]. Error if key filter or any busy flag below blocks it
- **Globals / callees:** key_event_filter(0x30a,0); key_event_filter key-filter; error if DAT_00020f1c==1 or DAT_00020f70==1 or DAT_00020f0c!=0 or DAT_00020b8a==1 or DAT_00020b3d!=0 or DAT_00020cce==1 or DAT_00020f1b==1 or DAT_00020ccd==1 or DAT_00020b7c!=0 or DAT_00020cd0==1 or DAT_00020cd1==1 or DAT_00020f11==1; `vfo_ab_toggle`@fffbf4bb; DAT_00009c5e, DAT_00009dbd, DAT_00009dbe/dbf
- **Risk:** medium: changes active VFO / operating state; refused while TX-style flags are set
- **Resolved in part (#157):** The guard flags are UI-state (0x20B04) fields **[fact for the offsets and writers]**: 0x20F1C = +0x418 scan running; 0x20F70 = +0x46C timed MIC-slot/remote-keypad flag; 0x20F0C = +0x408 tune cycle (`vfo_mode` reports CW-L while it is 1 or 2); 0x20B8A = +0x86 message pop-up shown (`FUN_fffcfa3d`, with the message code in +0xBB); 0x20B7C = +0x78 voice-message playback (E8 status, cleared by the MIC PTT release); 0x20CCD/0x20CD0/0x20CD1/0x20F1B = +0x1C9/+0x1CC/+0x1CD/+0x417 keyer/message send states (all cleared by `FUN_fffe3d24`); 0x20B3D = +0x39 and 0x20CCE = +0x1CA not traced.
- **Resolved (#159):** **0x20B3D (+0x39)** is the TX-lamp state from `FUN_fffb8d77`: 1 while transmitting (0x20B6B = 1), 2 when TX is blocked because the frequency is outside the TX bands (`tx_freq_allowed`, lamp blinks), else 0; `RI` P4 reports it (0 RX, 1 TX, 2 TX INHIBIT) **[fact]**. **0x20CCE (+0x1CA)** is the armed DVS recording of `LM0n` (see `LM`) **[fact]**. In short: no key-like command runs while a scan, a tune cycle, a message pop-up or a message/keyer playback is active.

### TS

- **Index / handler:** 94, cat_TS @ fffaf5c7; switch case fffa4c50; length tests `len==3:cat_TS@fffaf5c7 \| len==4:cat_TS@fffaf5c7` [fact]
- **Manual 2306-C:** TXW. Set `TSP1;` (4), read `TS;` (3), answer `TSP1;` (4), AI O. P1 0 off,1 on
- **Read / answer (firmware):** TSn; n='1' if DAT_00020f09==1 else '0'
- **Set parameters (firmware):** P1 '0': DAT_00020f87=0; if DAT_00020f09==1 clear it and swap the two 90-byte blocks DAT_00009d09 and DAT_00009d63, DAT_00020f0f=1; if it was already 0 -> error. P1 '1': key_event_filter(0xec,0) must pass, no busy flag (DAT_00020f1c==1, DAT_00020f70==1, DAT_00020f0c!=0, DAT_00020b8a==1, DAT_00020f11==1) else error; requires DAT_00009c5e==1 else error; sets DAT_00020f87=1; if DAT_00020f09==0 set it to 1 and swap the blocks, DAT_00020f0f=1 (if already 1 silent no-op). Other P1 -> error
- **Class:** read+set
- **Behaviour:** While DAT_00009c5e is on, swaps the two 90-byte per-VFO blocks DAT_00009d09/DAT_00009d63 so the other VFO's data becomes the visible/edit one, tracked in DAT_00020f09 [inference: temporary 'look at TX VFO' toggle]. Key code 0xec
- **Globals / callees:** DAT_00020f09 (rw), DAT_00020f87 (w), DAT_00020f0f (w), DAT_00009d09/d63 blocks (0x5a bytes each, swapped), DAT_00009c5e (r), key_event_filter(0xec)
- **Risk:** medium: swaps live VFO data blocks; refused in TX-flag states
- **Note (#157):** asymmetry **[fact]**: TS0 with 0x20F09 == 0 is an error, while TS1 with 1 is a silent no-op.

### TX

- **Index / handler:** 95, cat_TX @ fffaf7b8; switch case fffa4c8a; length tests `len==3:cat_TX@fffaf7b8 \| len==4:cat_TX@fffaf7b8` [fact]
- **Manual 2306-C:** TX SET. Set `TXP1;` (4), read `TX;` (3), answer `TXP1;` (4), AI O. P1 0 radio TX off/CAT TX off,1 radio TX off/CAT TX on,2 radio TX on/CAT TX off (answer)
- **Read / answer (firmware):** TXn; n='0' if `ptt_source_get`()==0 (DAT_0001204d, TX-source byte), '1' if ==5, else '2'. DAT_0001204d is produced by `ptt_source_select` (fffb7128 file): 5 = CAT TX flag DAT_00020b28 is the source; other nonzero codes (1,2,3,4,7,8,9 from DAT_00020b24..2c flags) read as '2'
- **Set parameters (firmware):** P1 hex char via hex2nib: '0' -> DAT_00020b28=0 (CAT TX release); '1' -> DAT_00020b28=1 (CAT TX request); other -> error. Error if DAT_00020f1c==1 or DAT_00020f70==1. NO key-filter call (key_event_filter not used)
- **Class:** read+set
- **Behaviour:** TX1 raises the CAT transmit flag DAT_00020b28; the TX-source resolver `ptt_source_select` (line ~1397) checks DAT_00020b28==1 first (when DAT_00020b97==0) and yields source code 5, so the radio goes to transmit; TX0 clears it. DAT_00020b28 is also cleared by the periodic task in the fffb2fc0 file (~line 698) when DAT_00020b8c==1 or DAT_00020b9e==1 (protection/fault style conditions) [inference]. The handler has no timeout or confirmation [fact]
- **Globals / callees:** DAT_00020b28 (w; read in `ptt_source_select`, cleared ~fffb2fc0:698), DAT_0001204d (r via `ptt_source_get`@fffb6ec5), DAT_00020f1c, DAT_00020f70 (guards), hex2nib
- **Risk:** high: keys the transmitter via CAT; not routed through the key-event filter
- **Resolved (#69):** priority order and all 11 sources are in [code/main/tx-protection.md](code/main/tx-protection.md); 0x20B97 blocks every source. 0x20F1C = scan running, 0x20F70 = UI +0x46C timed flag (#144) **[fact]**.

### UP

- **Index / handler:** 96, cat_UP @ fffa9155; switch case fffa4cc4; length tests `len==3:cat_UP@fffa9155` [fact]
- **Manual 2306-C:** MIC UP. Set `UP;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Set parameters (firmware):** none
- **Class:** action
- **Behaviour:** Executes the configured UP action (like a mic UP key): FUN_fffc0335 -> FUN_fffc40d7(DAT_9ACC) jump-table dispatch by setting 0x9ACC [inference].
- **Globals / callees:** Gates: key_event_filter(0x348,0)==0 -> error; guard flags (busy/lockout guard (any true -> '?;'): DAT_20f0c!=0, 20b8a==1, 20b3d!=0, 20cce==1, 20f1b==1, 20ccd==1, 20b7c!=0, 20cd0==1, 20cd1==1, 20f11==1). W 0x20F6F=0. Callee FUN_fffc0335
- **Risk:** medium: moves frequency/channel as configured
- **Resolved (#69):** 0x9ACC is **MIC UP** (`EX030124`); the same 21 functions as `DN` (0x9ACD) **[fact]**.

### VD

- **Index / handler:** 97, cat_VD @ fffaf874; switch case fffa4cd9; length tests `len==3:cat_VD@fffaf874 \| len==5:cat_VD@fffaf874` [fact]
- **Manual 2306-C:** VOX DELAY TIME. Set `VDP1P1P1P1;` (7), read `VD;` (3), answer `VDP1P1P1P1;` (7), AI O. P1 drawn as 4 cells but values listed as 2-digit codes 00-33: 00=30,01=50,02=100,03=150,04=200,05=250 ms, 06-33 300-3000 ms (10 ms multiples). AMBIGUOUS digit count
- **Read / answer (firmware):** VDnn; nn=2 dec digits: DAT_00009bf4 if DAT_00009af3==0 else DAT_00009bf5
- **Set parameters (firmware):** nn 2 dec digits 00-33 (>0x21 or non-digit -> error) -> DAT_00009bf4 (DAT_00009af3==0) or DAT_00009bf5; if DAT_00009ace==0: DAT_00020cc6=0x2a, FUN_fffc8cbb(0x2a), FUN_fffc8d8c() (menu/display refresh)
- **Class:** read+set
- **Behaviour:** Stores a 0-33 setting in one of two cells chosen by DAT_00009af3 (meaning unknown). Adjacent to VG (0-100), VM, VX; looks like a VOX-family setting (delay) [guess]
- **Globals / callees:** DAT_00009bf4/bf5 (rw), DAT_00009af3 (r), DAT_00009ace (r), DAT_00020cc6 (w=0x2a), FUN_fffc8cbb@fffc8cbb, FUN_fffc8d8c
- **Risk:** medium: probably TX-related setting [guess], RAM only here
- **Resolved (#157):** 0x9AF3 is **VOX SELECT** (`EX030405`, 0..2), which picks the VOX source and the anti-VOX value (0x9BF6/0x9BF7) **[fact]**. `FUN_fffc8cbb(id)` is the **pop-up duration** lookup: it returns the display time of on-screen pop-up `id` for the DISPLAY SETTING **POP-UP TIME** (0x9B0E, 0..2); for ids 0x28, 0x29, 0x2A and 0x32 that is 800 / 1000 / 1200 (timer units) **[fact, ROM tables at 0xFFF834D6]**. So the "menu id" is the id of the level pop-up the DISPLAY shows (0x2A for this command).

### VG

- **Index / handler:** 98, cat_VG @ fffaf9c0; switch case fffa4d13; length tests `len==3:cat_VG@fffaf9c0 \| len==6:cat_VG@fffaf9c0` [fact]
- **Manual 2306-C:** VOX GAIN. Set `VGP1P1P1;` (6), read `VG;` (3), answer `VGP1P1P1;` (6), AI O. P1 000-100
- **Read / answer (firmware):** VGnnn; nnn = DAT_00009bf3 3 dec digits 000-100
- **Set parameters (firmware):** nnn 3 dec digits, >100 or non-digit -> error -> DAT_00009bf3; if DAT_00009ace==0: DAT_00020cc6=0x29, FUN_fffc8cbb(0x29), FUN_fffc8d8c()
- **Class:** read+set
- **Behaviour:** Stores a 0-100 level; likely a VOX-style gain [guess, from adjacency with VX/VD]
- **Globals / callees:** DAT_00009bf3 (rw), DAT_00009ace (r), DAT_00020cc6 (w=0x29), FUN_fffc8cbb, FUN_fffc8d8c
- **Risk:** medium: probably TX-related level [guess]
- **Resolved (#157):** `FUN_fffc8cbb(id)` is the **pop-up duration** lookup: it returns the display time of on-screen pop-up `id` for the DISPLAY SETTING **POP-UP TIME** (0x9B0E, 0..2); for ids 0x28, 0x29, 0x2A and 0x32 that is 800 / 1000 / 1200 (timer units) **[fact, ROM tables at 0xFFF834D6]**. So the "menu id" is the id of the level pop-up the DISPLAY shows (0x29 for this command).

### VM

- **Index / handler:** 99, cat_VM @ fffafadb; switch case fffa4d4d; length tests `len==4\|\|len==3\|\|len==6:cat_VM@fffafadb` [fact]
- **Manual 2306-C:** [V/M] KEY FUNCTION. Set `VM;` (3), read `-` (-), answer `-` (-), AI X. no parameters
- **Read / answer (firmware):** VM0hh; (len 6): hh = byte2hex two hex chars of a code from m = active VFO mode byte (DAT_00009dbe if DAT_00009dbd==0 else DAT_00009dbf) and b = DAT_000060c9/ca: m==2: b<0x63 -> 11, b<0x75 -> 21, b<0x84 -> 51, else 91; m==3 -> 10; m==4 -> 20; else 00
- **Set parameters (firmware):** Dispatch compound test: len 3, 4 or 6 else error; handler errors if len!=3 and P1!='0'. Set path (len 3 or 6): key_event_filter(0x309,0) + same 12-flag busy guard as SV else error. len 3 'VM;' -> `vm_toggle`() (cycle active VFO mode state). len 6: [3],[4] must be '00' else error; if m!=1 -> `vm_toggle`(), re-read m, if still !=1 -> `vm_toggle`() again (force back to mode 1)
- **Class:** read+set
- **Behaviour:** Read returns a hex code describing the VFO/memory-mode state; 'VM;' cycles the mode; 'VM000;' forces mode 1 (probably VFO) [inference: VFO/memory mode control, key code 0x309]
- **Globals / callees:** DAT_00009dbd (active VFO), DAT_00009dbe/dbf (mode bytes), DAT_000060c9/ca, key_event_filter(0x309), `vm_toggle`@fffbf41f (-> FUN_fffe3d24, `vm_toggle_core`, FUN_fffec578 or FUN_fffc2794 when DAT_00020b9b==1), guard flags as SV
- **Risk:** medium: changes VFO/memory operating mode
- **Resolved (#157):** 0x9DBE/0x9DBF are the VFO/memory states of A/B: 1 VFO, 2 memory, 3 memory tune, 4 PMS, 5 QMB, 7/8 locked memory ([code/main/radio-control.md](code/main/radio-control.md)) **[fact for the variables, inference for the names]**. The set form accepts only `00` **[fact]**.

### VS

- **Index / handler:** 100, cat_VS @ fffafdbd; switch case fffa4d97; length tests `len==3:cat_VS@fffafdbd \| len==4:cat_VS@fffafdbd` [fact]
- **Manual 2306-C:** VFO SELECT. Set `VSP1;` (4), read `VS;` (3), answer `VSP1;` (4), AI O. P1 0 main=VFO-A/sub=VFO-B,1 main=VFO-B/sub=VFO-A
- **Read / answer (firmware):** VSn; n=nib2hex(DAT_00009dbd) ('0'/'1' active VFO)
- **Set parameters (firmware):** P1 '0' or '1' else error (checked after the guard). key_event_filter(0x30a,0) + 12-flag busy guard (see SV) else error. Clears DAT_00009c5e=0 first, then if requested VFO != DAT_00009dbd calls `vfo_ab_toggle`() (swap); sets DAT_00020f10=1
- **Class:** read+set
- **Behaviour:** Selects active VFO 0/1 (A/B) [inference from the DAT_00009dbd flip in `vfo_ab_toggle`], also drops split state. Key code 0x30a
- **Globals / callees:** DAT_00009dbd (rw), DAT_00009c5e (w=0), DAT_00020f10 (w=1), `vfo_ab_toggle`@fffbf4bb, key_event_filter(0x30a)
- **Risk:** medium: changes active VFO; clears DAT_00009c5e without `split_toggle` bookkeeping when target equals current
- **Resolved (#159).** Every accepted `VS` set (also `VS0;` when A is already active) clears split 0x9C5E first; `vfo_ab_toggle` (0xFFFBF4BB) does the same on `SV`/A-B **[fact]**. Compared with `split_toggle` (0xFFFBECA5) turning split off, this skips four steps **[fact]**:
  1. **0x9DBE/0x9DBF are not restored** from UI +0x484/+0x485. Turning split on moves the active side from memory, PMS or QMB state to VFO (`vm_toggle_core`, or state 4 → 1), so after `VS` that side stays in VFO mode instead of returning to the memory.
  2. **TXW stays on.** 0x20F09 (the `TS` swap flag) and UI +0x483 are not cleared. If TXW was on, the A/B records stay swapped; `TS;` still answers 1, `TS0;` still swaps them back (it does not check split), and `TS1;` is refused because split is off. `key_func_long` tests +0x483 only together with 0x9C5E, so it treats TXW as off, but `displink_build_status` tests +0x483 alone, so the DISPLAY status frame keeps its TXW form (0x2D in place of the `FUN_fff97c74` byte).
  3. **`FUN_fff9cdb0` is not called.** It pre-fills the 20-sample history 0x20824 of the VFO frequency (the active VFO, or the TX VFO while split) that `FUN_fff9ccd3` checks every 100 ms in `displink_task` (UI +0x6A/+0x6B = "frequency settled"). Without the pre-fill the settled flags drop for up to 2 s after the change **[inference for the visible effect]**.
  4. `vfo_ab_toggle` itself calls `FUN_fffe3d24` (stop message/keyer playback) and sets the refresh flag +0x40C, so those happen only when the VFO really changes.
  `split_toggle` turning split off does not swap the TXW records back either; it only clears 0x20F09 **[fact]**.

### VX

- **Index / handler:** 101, cat_VX @ fffaffa0; switch case fffa4dd1; length tests `len==3:cat_VX@fffaffa0 \| len==4:cat_VX@fffaffa0` [fact]
- **Manual 2306-C:** VOX. Set `VXP1;` (4), read `VX;` (3), answer `VXP1;` (4), AI O. P1 0 off,1 on
- **Read / answer (firmware):** VXn; n='0' if mode (`vfo_mode`(1)) is 2,3,12 or 13, else hex(DAT_00009c5d)
- **Set parameters (firmware):** P1 '0' -> DAT_00009c5d=0, '1' -> DAT_00009c5d=1, else error; key_event_filter(0x302,0) must pass; error if mode in {2,3,12,13}
- **Class:** read+set
- **Behaviour:** On/off flag DAT_00009c5d, forced off/refused in modes 2,3,12,13 (the 500 Hz class in SH); looks like VOX on/off [inference]. Key code 0x302
- **Globals / callees:** DAT_00009c5d (rw), `vfo_mode`(1)@fffb3196, key_event_filter(0x302)
- **Risk:** medium: probably TX-related enable [inference]
- **Resolved (#157):** `vfo_rec_ptr`/`vfo_mode`(0) return the **active** VFO (0x9DBD: 0 = A record 0x9D09, 1 = B 0x9D63); with argument 1 they return the **TX** VFO, i.e. the other VFO while split (0x9C5E) is on. `vfo_mode` returns 2 (CW-L) during tune/EXT-PA cycles (0x20F0C, 0x20B40, 0x20B41, 0x20B25) **[fact, current decompile]**; so `vfo_mode`(1) is the TX VFO's mode.

### XT

- **Index / handler:** 102, (none, switch default); switch case fffa4e26; length tests `none (error reply)` [fact]
- **Manual 2306-C:** TX CLAR. Set `XTP1;` (4), read `XT;` (3), answer `XTP1;` (4), AI ?. P1 0 off,1 on. Page exists but XT is NOT in command list table (ai unknown)
- **Read / answer (firmware):** ?; (error)
- **Set parameters (firmware):** none
- **Class:** error-only
- **Behaviour:** No handler: dispatch default arm sets DAT_0000464a=1 -> '?;'. Mnemonic is in the table but never serviced [fact]
- **Globals / callees:** DAT_0000464a
- **Risk:** low: no effect

### ZI

- **Index / handler:** 103, cat_ZI @ fffb006e; switch case fffa4e0b; length tests `len==4:cat_ZI@fffb006e` [fact]
- **Manual 2306-C:** ZERO IN. Set `ZIP1;` (4), read `-` (-), answer `-` (-), AI X. P1 0 fixed
- **Read / answer (firmware):** (no reply)
- **Set parameters (firmware):** P1 must be '0' else error. key_event_filter(0x307,0) must pass; error if DAT_00020f1c==1 or DAT_00020f70==1 or DAT_00020f0c!=0; error unless low nibble of the current VFO block byte (`vfo_rec_ptr`(DAT_00020b6b)) is 2 or 3
- **Class:** action
- **Behaviour:** Zero-in style action for modes 2/3: FUN_fffbf0b6 reads an offset `dsp_tune_offset`() (short, must be within +/-35), multiplies by 10, adds (subtracts in mode 2) to the stored VFO frequency (bytes +0x4a..0x4d), applies via `freq_clamp` and refreshes (FUN_fffc2efb, `vfo_mark_edited`, `vfo_store_back`). Changes the operating frequency [inference: CW-style zero-in/auto-tune]. Key code 0x307
- **Globals / callees:** key_event_filter(0x307), `vfo_rec_ptr`, DAT_00020b6b, FUN_fffbf0b6@fffbf0b6, `dsp_tune_offset`, `freq_clamp` (freq set), VFO block DAT_00009d09/d63 (+0x4a..0x4d)
- **Risk:** medium: retunes the VFO (up to +/-350 Hz) but does not key TX
- **Resolved in part (#157):** `dsp_tune_offset` returns 0x1B6E4, the mode (most frequent of the last 8 samples) of DSP status register 4, the measured CW tuning error; `FUN_fffbf0b6` applies it × 10 Hz ([code/main/dsp-link.md](code/main/dsp-link.md)) **[fact]**. How the HiFi4 computes reg 4 is not traced.
