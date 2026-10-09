# MAIN (RX651) decompile index — FT-710_MAIN_V0112

Produced in T05. Source: `build/FT-710_MAIN_V0112.bin` (0xFFF80000..0xFFFFFFFF, flattened from the SFL S-records).
Ghidra project `ghidra/FT710_MAIN` (not in git), language `rx62t:LE:32:default` from the community RX SLEIGH module
(see `docs/tooling.md`), memory map in `docs/memory-maps.md` (MAIN section).

## Files
- `<first>_<last>.c`: decompiled C, 50 functions per file in address order (`tools/ghidra/ExportDecomp.java`).
- `functions.tsv`: entry, name, size, reference count, file for every function.
- `cat_dispatch.tsv`: the CAT mnemonic → case → handler table (`tools/ghidra/CatDispatch.java`).
- Function names come from `tools/ghidra/names_main.tsv` (applied with `tools/ghidra/ApplyNames.java`). Everything else is `FUN_<addr>`.

## Numbers
- 2252 functions exported (non-thunk), **0 decompile failures**. 188 are named so far.
- About 384 KB of the ~451 KB non-0xFF ROM bytes are disassembled as code (129,938 instructions), and about 50 KB are defined data. About 20 KB of non-0xFF bytes remain undefined, mostly string/const areas in 0xFFF80000..0xFFF8FFFF.
- Decompiler warnings: 1224 "Removing unreachable block" (harmless, from the `-O0`-style code) and 8 "Unable to track spacebase".
- Known decompiler artifacts **[fact]**:
  - `SCMPU`/`SMOVF`/`SSTR` string instructions decompile poorly (`cat_parse` shows them as odd loops). The underlying code is `strncmp(cmd, table+2*i, 2)`.
  - Some call arguments are dropped, e.g. the middle `eeprom_spi_tx()` in `eeprom_read` really sends the address high byte. Check the disassembly when an argument count looks wrong.

## Boot and main loop  [fact unless marked]
| Address | Name | Role |
|---|---|---|
| 0xFFF8FBDB | `PowerON_Reset` | USP=0x1004, ISP=0x1404, INTB=0xFFF8E6DC, EXTB=0xFFFFFF80, FPSW=0x100. Then `hw_init_clock`, `_INITSCT`, RAM clear, `_INIT_IOLIB`, …, PSW=0x30000 (user mode, I=1), `main`, `_CLOSEALL`, `nop; bra` |
| 0xFFF913D7 | `hw_init_clock` | SYSTEM register setup (PRCR=0xA50B…) **[inference]** |
| 0xFFFEDEDA | `_INITSCT` | CC-RX runtime: BTBL zero-fill, DTBL ROM→RAM copy |
| 0xFFF8F658 | `main` | → `app_main` |
| 0xFFF94AFA | `app_main` | Init. While power is off (flag `0x20B3A`==0) it loops `FUN_fff94d6f`/`cat_parse` so that `PS1;` can power the radio on, then initializes the subsystems and enters `main_loop` |
| 0xFFF94B8B | `main_loop` | Super-loop with no RTOS: ~16 polled tasks per pass, including `cat_parse` |

The vector tables are seeded by `tools/ghidra/SetupRX651.java`. Relocatable vectors are named `vecNNN_<source>` (names from the RX651 vector table **[inference]**; the SCI ones are confirmed by the registers they touch). The fixed vectors are at 0xFFFFFFD0.

## CAT (remote control)  [fact]
- **Parser**: `cat_parse` @ **0xFFFA347C**. It runs from `main_loop` and from `app_main` (power-off loop). It takes a received command buffer (port id byte at +0, length at +2, text at +4), compares the 2-char mnemonic linearly against
  - `cat_mnemonics` @ **0xFFF805EC**: 104 entries `AB AC AG … VX XT ZI`. The index is the switch case.
  - `cat_ext_mnemonics` @ **0xFFF806BC**: 10 entries `SP EO E8 E9 FD KT PE ZZ VE JP`, tried only when the primary lookup fails. **These are not in the primary table, which makes them the prime candidates for undocumented/service commands (T09).**
  - While power is off, only index 71 (`PS`) with parameter `1` is accepted.
- **Dispatch**: `cat_dispatch` @ **0xFFFA3B6E**. This is a switch, not a pointer table: `MOV.W [idx, 0xFFF8F014], R14 ; BRA.L R14` at 0xFFFA3B8A. **`cat_switch_table` @ 0xFFF8F014 holds 104 × int16 offsets** relative to 0xFFFA3B8A. Each case checks the total command length (e.g. `FA;` = 3 → read, `FA014250000;` = 12 → set) and calls the handler with `(cmd+4, is_set)`. Wrong lengths and the default case set the error flag `0x464A`, which makes the parser send an error reply.
- **Extended dispatch**: `cat_dispatch_ext` @ 0xFFFA3A2A is a compare chain. `SP` is special-cased in `cat_ext_SP` @ 0xFFFA36F2. `E9` is handled only on a second input path in `cat_parse` (`cat_ext_E9` @ 0xFFFA5985). `KT` has no case.
- **Reply templates**: 55 `;`-terminated templates at **0xFFF8F480..0xFFF8F5E4** (`AC000;AG0000;…FA000000000;…IF000…;…VX0;`).
- `cat_mode_codes` @ 0xFFF806D0 (`12735D4B8CAF69EF01253F11…`) is used by `cat_IF_OI`, probably the mode→code map **[inference]**. It is followed by other small string tables (`FP1LP1U…P9U`, `501…515`, `EMG`).
- Mnemonics present in the table but routed to the **switch default (error)**: `BY ED EK EU RC RD RS RT RU XT`.
- Shared handlers: `FA`/`FB` → `cat_FA_FB`, `IF`/`OI` → `cat_IF_OI`.
- CAT ports: `sci_tx_end(port)` maps port id 1 → SCI3, 2 → SCI0, else → SCI2. `cat_rx_complete` @ 0xFFFB1B50 is the receive-end callback. So CAT is served on SCI0 (USB Standard), SCI3 (USB Enhanced) and SCI2 **[inference for SCI2]**.

### CAT dispatch table (from `cat_dispatch.tsv`)
| Table | # | Mnemonic | Case | Length test → handler |
|---|---|---|---|---|
| primary | 0 | `AB` | fffa3b8c | len==3:cat_AB (fffa646d) |
| primary | 1 | `AC` | fffa3ba1 | len==3:cat_AC (fffa65d4) ; len==6:cat_AC (fffa65d4) |
| primary | 2 | `AG` | fffa3bd9 | len==4:cat_AG (fffa6867) ; len==7:cat_AG (fffa6867) |
| primary | 3 | `AI` | fffa3c15 | len==3:cat_AI (fffa6946) ; len==4:cat_AI (fffa6946) |
| primary | 4 | `AM` | fffa3c4d | len==3:cat_AM (fffa6a26) |
| primary | 5 | `AO` | fffa3c62 | len==3:cat_AO (fffa6b6f) ; len==6:cat_AO (fffa6b6f) |
| primary | 6 | `AS` | fffa3c9a | len==4:cat_AS (fffa6c9d) ; len==7:cat_AS (fffa6c9d) |
| primary | 7 | `AV` | fffa3cd6 | len==3:cat_AV (fffa6edc) ; len==6:cat_AV (fffa6edc) |
| primary | 8 | `BA` | fffa3d0e | len==3:cat_BA (fffa7018) |
| primary | 9 | `BC` | fffa3d23 | len==4:cat_BC (fffa717f) ; len==5:cat_BC (fffa717f) |
| primary | 10 | `BD` | fffa3d5f | len==4:cat_BD (fffa72d9) |
| primary | 11 | `BI` | fffa3da7 | len==3:cat_BI (fffa77ec) ; len==4:cat_BI (fffa77ec) |
| primary | 12 | `BM` | fffa3ddf | len==3:cat_BM (fffa7928) |
| primary | 13 | `BP` | fffa3df4 | len==5:cat_BP (fffa7a71) ; len==8:cat_BP (fffa7a71) |
| primary | 14 | `BS` | fffa3e2c | len==5:cat_BS (fffa7db5) |
| primary | 15 | `BU` | fffa3d83 | len==4:cat_BU (fffa756c) |
| primary | 16 | `BY` | fffa4e26 | *(switch default: error reply)* |
| primary | 17 | `CF` | fffa3e50 | len==6:cat_CF (fffa7fa1) ; len==11:cat_CF (fffa7fa1) |
| primary | 18 | `CH` | fffa3e88 | len==4:cat_CH (fffa8375) |
| primary | 19 | `CN` | fffa3ea1 | len==5:cat_CN (fffa8513) ; len==8:cat_CN (fffa8513) |
| primary | 20 | `CO` | fffa3ed9 | len==5:cat_CO (fffa8698) ; len==9:cat_CO (fffa8698) |
| primary | 21 | `CS` | fffa3f15 | len==3:cat_CS (fffa8b98) ; len==4:cat_CS (fffa8b98) |
| primary | 22 | `CT` | fffa3f4d | len==4:cat_CT (fffa8c79) ; len==5:cat_CT (fffa8c79) |
| primary | 23 | `DA` | fffa3f89 | len==3:cat_DA (fffa8d8a) ; len==11:cat_DA (fffa8d8a) |
| primary | 24 | `DN` | fffa3fc1 | len==3:cat_DN (fffa9029) |
| primary | 25 | `DT` | fffa3fd6 | len==4:cat_DT (fffa9281) ; len==0:cat_DT (fffa9281) |
| primary | 26 | `ED` | fffa4e26 | *(switch default: error reply)* |
| primary | 27 | `EK` | fffa4e26 | *(switch default: error reply)* |
| primary | 28 | `EM` | fffa4023 | len==5:cat_EM (fffa9648) ; len==0:cat_EM (fffa9648) |
| primary | 29 | `EN` | fffa406f | len==5:cat_EN (fffa9928) |
| primary | 30 | `EU` | fffa4e26 | *(switch default: error reply)* |
| primary | 31 | `EX` | fffa4097 | len==9:cat_EX (fffa9937) ; len==8:cat_EX (fffa9937) |
| primary | 32 | `FA` | fffa40d7 | len==3:cat_FA_FB (fffa99bd) ; len==12:cat_FA_FB (fffa99bd) |
| primary | 33 | `FB` | fffa40d7 | len==3:cat_FA_FB (fffa99bd) ; len==12:cat_FA_FB (fffa99bd) |
| primary | 34 | `FN` | fffa4120 | len==3:cat_FN (fffa9c96) ; len==4:cat_FN (fffa9c96) |
| primary | 35 | `FS` | fffa4158 | len==3:cat_FS (fffa9d3d) ; len==4:cat_FS (fffa9d3d) |
| primary | 36 | `FT` | fffa4190 | len==3:cat_FT (fffa9d4e) ; len==4:cat_FT (fffa9d4e) |
| primary | 37 | `GT` | fffa41c8 | len==4:cat_GT (fffa9f23) ; len==5:cat_GT (fffa9f23) |
| primary | 38 | `GP` | fffa4204 | len==3:cat_GP (fffaa21f) ; len==7:cat_GP (fffaa21f) |
| primary | 39 | `ID` | fffa423c | len==3:cat_ID (fffaa365) |
| primary | 40 | `IF` | fffa4260 | len==3:cat_IF_OI (fffaa39c) |
| primary | 41 | `IS` | fffa428f | len==4:cat_IS (fffaa6e3) ; len==10:cat_IS (fffaa6e3) |
| primary | 42 | `KM` | fffa42c7 | len==4:cat_KM (fffaa905) ; len==0:cat_KM (fffaa905) |
| primary | 43 | `KP` | fffa431b | len==3:cat_KP (fffaac36) ; len==5:cat_KP (fffaac36) |
| primary | 44 | `KR` | fffa4353 | len==3:cat_KR (fffaad52) ; len==4:cat_KR (fffaad52) |
| primary | 45 | `KS` | fffa438b | len==3:cat_KS (fffaadea) ; len==6:cat_KS (fffaadea) |
| primary | 46 | `KY` | fffa43c3 | len==5:cat_KY (fffaaf19) |
| primary | 47 | `LK` | fffa43dc | len==3:cat_LK (fffab09f) ; len==4:cat_LK (fffab09f) |
| primary | 48 | `LM` | fffa4414 | len==4:cat_LM (fffab16f) ; len==5:cat_LM (fffab16f) |
| primary | 49 | `MA` | fffa4450 | len==3:cat_MA (fffab3fd) |
| primary | 50 | `MB` | fffa4465 | len==3:cat_MB (fffab478) |
| primary | 51 | `MC` | fffa447a | len==3:cat_MC (fffab4f3) ; len==6:cat_MC (fffab4f3) |
| primary | 52 | `MD` | fffa44b2 | len==4:cat_MD (fffab7d1) ; len==5:cat_MD (fffab7d1) |
| primary | 53 | `MG` | fffa44ee | len==3:cat_MG (fffaba64) ; len==6:cat_MG (fffaba64) |
| primary | 54 | `ML` | fffa4526 | len==4:cat_ML (fffabbfa) ; len==7:cat_ML (fffabbfa) |
| primary | 55 | `MR` | fffa4562 | len==6:cat_MR (fffabea5) |
| primary | 56 | `MS` | fffa4606 | len==3:cat_MS (fffac4b6) ; len==5:cat_MS (fffac4b6) |
| primary | 57 | `MT` | fffa4589 | len==6:cat_MT (fffac285) ; len==0:cat_MT (fffac285) |
| primary | 58 | `MW` | fffa45dd | len==28:cat_MW (fffac534) |
| primary | 59 | `MX` | fffa4640 | len==3:cat_MX (fffac9ad) ; len==4:cat_MX (fffac9ad) |
| primary | 60 | `NA` | fffa467a | len==4:cat_NA (fffaca47) ; len==5:cat_NA (fffaca47) |
| primary | 61 | `NB` | fffa46b8 | len==4:cat_NB (fffacc65) ; len==5:cat_NB (fffacc65) |
| primary | 62 | `NL` | fffa46f6 | len==4:cat_NL (fffacce8) ; len==7:cat_NL (fffacce8) |
| primary | 63 | `NR` | fffa4734 | len==4:cat_NR (ffface21) ; len==5:cat_NR (ffface21) |
| primary | 64 | `OI` | fffa4260 | len==3:cat_IF_OI (fffaa39c) |
| primary | 65 | `OS` | fffa4772 | len==4:cat_OS (fffacebe) ; len==5:cat_OS (fffacebe) |
| primary | 66 | `PA` | fffa47b0 | len==4:cat_PA (fffad001) ; len==5:cat_PA (fffad001) |
| primary | 67 | `PB` | fffa47ea | len==4:cat_PB (fffad0a2) ; len==5:cat_PB (fffad0a2) |
| primary | 68 | `PC` | fffa4828 | len==3:cat_PC (fffad241) ; len==6:cat_PC (fffad241) |
| primary | 69 | `PL` | fffa4862 | len==3:cat_PL (fffad467) ; len==6:cat_PL (fffad467) |
| primary | 70 | `PR` | fffa48a0 | len==4:cat_PR (fffad595) ; len==5:cat_PR (fffad595) |
| primary | 71 | `PS` | fffa48de | len==3:cat_PS (fffad696) ; len==4:cat_PS (fffad696) |
| primary | 72 | `QI` | fffa4918 | len==3:cat_QI (fffad704) |
| primary | 73 | `QR` | fffa492e | len==3:cat_QR (fffad709) |
| primary | 74 | `QS` | fffa4944 | len==3:cat_QS (fffad70e) |
| primary | 75 | `RA` | fffa495a | len==4:cat_RA (fffad718) ; len==5:cat_RA (fffad718) |
| primary | 76 | `RC` | fffa4e26 | *(switch default: error reply)* |
| primary | 77 | `RD` | fffa4e26 | *(switch default: error reply)* |
| primary | 78 | `RG` | fffa4998 | len==4:cat_RG (fffad7ae) ; len==7:cat_RG (fffad7ae) |
| primary | 79 | `RI` | fffa49d6 | len==4:cat_RI (fffad8e3) |
| primary | 80 | `RL` | fffa4a00 | len==4:cat_RL (fffada46) ; len==6:cat_RL (fffada46) |
| primary | 81 | `RM` | fffa4a3e | len==4:cat_RM (fffadb7d) |
| primary | 82 | `RS` | fffa4e26 | *(switch default: error reply)* |
| primary | 83 | `RT` | fffa4e26 | *(switch default: error reply)* |
| primary | 84 | `RU` | fffa4e26 | *(switch default: error reply)* |
| primary | 85 | `SC` | fffa4a68 | len==3:cat_SC (fffadcd6) ; len==4:cat_SC (fffadcd6) |
| primary | 86 | `SD` | fffa4aa2 | len==3:cat_SD (fffadd9a) ; len==5:cat_SD (fffadd9a) |
| primary | 87 | `SF` | fffa4adc | len==4:cat_SF (fffadeb6) ; len==5:cat_SF (fffadeb6) |
| primary | 88 | `SH` | fffa4b1a | len==4:cat_SH (fffae2ca) ; len==7:cat_SH (fffae2ca) |
| primary | 89 | `SM` | fffa4b54 | len==4:cat_SM (fffae64b) |
| primary | 90 | `SQ` | fffa4b7a | len==4:cat_SQ (fffae6cc) ; len==7:cat_SQ (fffae6cc) |
| primary | 91 | `SS` | fffa4bb4 | len==5:cat_SS (fffae850) ; len==10:cat_SS (fffae850) |
| primary | 92 | `ST` | fffa4bee | len==3:cat_ST (fffaf3b5) ; len==4:cat_ST (fffaf3b5) |
| primary | 93 | `SV` | fffa4c28 | len==3:cat_SV (fffaf46e) |
| primary | 94 | `TS` | fffa4c50 | len==3:cat_TS (fffaf5c7) ; len==4:cat_TS (fffaf5c7) |
| primary | 95 | `TX` | fffa4c8a | len==3:cat_TX (fffaf7b8) ; len==4:cat_TX (fffaf7b8) |
| primary | 96 | `UP` | fffa4cc4 | len==3:cat_UP (fffa9155) |
| primary | 97 | `VD` | fffa4cd9 | len==3:cat_VD (fffaf874) ; len==5:cat_VD (fffaf874) |
| primary | 98 | `VG` | fffa4d13 | len==3:cat_VG (fffaf9c0) ; len==6:cat_VG (fffaf9c0) |
| primary | 99 | `VM` | fffa4d4d | len==0:cat_VM (fffafadb) |
| primary | 100 | `VS` | fffa4d97 | len==3:cat_VS (fffafdbd) ; len==4:cat_VS (fffafdbd) |
| primary | 101 | `VX` | fffa4dd1 | len==3:cat_VX (fffaffa0) ; len==4:cat_VX (fffaffa0) |
| primary | 102 | `XT` | fffa4e26 | *(switch default: error reply)* |
| primary | 103 | `ZI` | fffa4e0b | len==4:cat_ZI (fffb006e) |
| secondary | 0 | `SP` | - | special-cased by caller (FUN_fffa36f2) |
| secondary | 1 | `EO` | fffa3b05 | len==10:cat_ext_EO (fffa5c90) |
| secondary | 2 | `E8` | fffa3a54 | cat_ext_E8 (fffa53a4) |
| secondary | 3 | `E9` | - | no case |
| secondary | 4 | `FD` | fffa3ac9 | len==6:cat_ext_FD (fffa5a51) ; len==15:cat_ext_FD (fffa5a51) |
| secondary | 5 | `KT` | - | no case |
| secondary | 6 | `PE` | fffa3b30 | len==6:cat_ext_PE (fffa5fdf) ; len==9:cat_ext_PE (fffa5fdf) |
| secondary | 7 | `ZZ` | fffa3ac0 | cat_ext_ZZ (fffa58a1) |
| secondary | 8 | `VE` | fffa3a64 | FUN_fffb2f07 (fffb2f07) ; cat_ext_VE (fffa54b3) |
| secondary | 9 | `JP` | fffa3a84 | len==7:cat_ext_JP (fffa556b) ; len==15:cat_ext_JP (fffa556b) |

## UART (SCI) drivers  [fact: register use; role per docs/hardware.md]
Renesas Code Generator style (`R_SCIn_Create/Start/Stop/Serial_Send/Serial_Receive` + RXI/TXI ISRs). TEI/ERI go through group interrupts.

| SCI | Regs | Create | Send / Receive | ISRs (RXI / TXI) | Role |
|---|---|---|---|---|---|
| SCI0 | 0x8A000 | `R_SCI0_Create` 0xFFF9321F (Start 0xFFF932C2, Stop 0xFFF93302) | 0xFFF933AE / 0xFFF9336A | 0xFFF9347F / 0xFFF9340E | CP2105 "Standard" CAT. Baud: `sci0_set_baud` 0xFFFB1645, table 0xFFF80FF4 |
| SCI1 | 0x8A020 | `R_SCI1_Create` 0xFFF9354E | 0xFFF936DB / 0xFFF93697 | 0xFFF937AC / 0xFFF9373B | DISPLAY CPU link |
| SCI2 | 0x8A040 | `R_SCI2_Create` 0xFFF93A86 (Stop 0xFFF93B69) | 0xFFF93C15 / 0xFFF93BD1 | 0xFFF93CED / 0xFFF93C7C | external tuner port. `sci2_configure` 0xFFFB177E switches mode/pins |
| SCI3 | 0x8A060 | `R_SCI3_Create` 0xFFF93F0D (Stop 0xFFF93FF0) | 0xFFF9409C / 0xFFF94058 | 0xFFF9416D / 0xFFF940FC | CP2105 "Enhanced" CAT. Baud: `sci3_set_baud` 0xFFFB198F |
| SCI4 | 0x8A080 | `R_SCI4_Create` 0xFFF9423C | 0xFFF943CB / 0xFFF94387 | 0xFFF9449C / 0xFFF9442B | not in docs/hardware.md, so the role is unknown |
| SCI5 | 0x8A0A0 | `R_SCI5_Create` 0xFFF94662 (Stop 0xFFF94745) | 0xFFF947F1 / 0xFFF947AD | 0xFFF948C2 / 0xFFF94851 | SDR FPGA link. `sdr_send_cmd` 0xFFFB1B2B sends and then arms a 7-byte reply into 0xA2AC |
| SCI6 | 0x8A0C0 | `R_SCI6_Create_IIC` 0xFFFC91B3 | `sci6_iic_condition` 0xFFFC9311 | 0xFFFC9467 / 0xFFFC93A4 | **simple-I2C mode** (SIMR3/SISR); the device is unknown |
| SCI7 | 0x8A0E0 | `R_SCI7_Create` 0xFFFC95B1 | (no separate send/receive functions found) | 0xFFFC9811 / 0xFFFC97A0 | "C4" link, probably the RT685 DSP |

The SDR side (T08: SDR_UPDATE/SDR_RESET GPIOs): `power_off_io` 0xFFFB73A6 stops SCI5 and clears PC4/PC3/P67/PB5/PA7. The SDR reset/update pins are not yet identified, but the small port-bit helpers 0xFFFB70C9..0xFFFB71A7 (PC/P8/P1/P5/P2 bits) are the place to look **[inference]**.

## EEPROM (Q1008 BR25G256, 32 KB SPI)  [fact]
Bit-banged SPI on **port E**: PE0 = /CS, PE5 = SCK, PE6 = MOSI (PODR 0x8C02E), PE7 = MISO (PIDR 0x8C04E). The RSPI peripherals are not used.
| Address | Name | Role |
|---|---|---|
| 0xFFFB14A4 | `eeprom_read(addr, buf, n)` | 0x03 READ + 16-bit address, n bytes |
| 0xFFFB14ED | `eeprom_write(addr, buf, n)` | 64-byte pages. Per page: 0x05 RDSR poll until WIP=0, 0x06 WREN, 0x02 WRITE + address + data |
| 0xFFFB15AA | `eeprom_spi_tx` | one byte out, MSB first |
| 0xFFFB15EF | `eeprom_spi_rx` | one byte in |

## Other notable items
- `cat_switch_table`, `DTBL` (0xFFF8E6A0) and `BTBL` (0xFFF8E6C4) are labelled.
- A **large code-pointer table at 0xFFF89D94**: 4651 dwords with 863 distinct targets in 0xFFFBC5F9..0xFFFEC2DF. It is probably a menu/UI or DISPLAY-link command handler table. Analyse it in T10 **[inference]**.
- `V01-12` version string at 0xFFFFFF00.
- Peripherals used (by register address): ICU, CMT, TPU, S12AD/S12AD1 (ADC), DA (0x88040), ports and MPC, SCI0–7, data flash (0x100000), FLASH registers. There is no RSPI, RIIC, USB or Ethernet use.
