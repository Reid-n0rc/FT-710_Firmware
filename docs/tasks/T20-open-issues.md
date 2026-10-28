# T20 — Open work, as issues to create

**Created as GitHub issues #57–#101 on 2026-10-28** (labels as listed). Track and close them on GitHub; this file is the snapshot they came from.

Collected in T20 (2026-10-28) from [`docs/code/system.md` §8](../code/system.md#8-contradictions-and-open-questions) (C* and O* items),
every task file's `## Follow-ups`, the per-command "Open (needs disassembly)" notes in
[cat-commands-primary.md](../cat-commands-primary.md), and the items that wait for the owner's approval. Follow-ups that later tasks
already settled are left out (for example the RX `MOVU` decoder bug, fixed in T17; the CAT compound length tests and the EX `len>8` misprint, decoded in T20;
the J1004/J1005 and DISPLAY-bank wording, fixed in T14/T17).

The parent creates one GitHub issue per entry below (title, body, labels). Each body says where the evidence is and what would settle
it. Labels used:

| Label | Meaning |
|---|---|
| `analysis` | reverse-engineering work in the decomp / Ghidra / netlist |
| `docs` | a documentation fix or addition, no new analysis needed |
| `tooling` | scripts, Ghidra setup, bootstrap |
| `hardware` | needs the service manual schematics or a part identification |
| `needs-radio` | needs the physical radio (a capture, a photo, a measurement or a CAT read) and therefore the owner's explicit approval each time; never write to a radio without it |
| `needs-owner` | needs a decision by the repository owner |
| `good first issue` | small, self-contained, a good way to learn the repo |
| `main`, `display`, `ifdsp`, `sdr`, `cat` | the image or area |

---

## System-level contradictions and open questions (system.md §8)

### 1. C6: how does `PS1;` power the radio on?
- **Labels:** `analysis`, `main`, `display`, `cat`
- **Body:** MAIN's `PS1` only sets 0x20B9C / 0x1B3D0 ("power-on request to DISPLAY") and waits for the `F0` hello; the DISPLAY sets its
  radio-on flag 0x208003A0 from the power key or from a second `0x60` frame with byte 0xB3 = 1 while off. No page shows a frame MAIN
  sends while the link is down that would carry the request. Trace the readers of 0x20B9C in MAIN's power-off loop (`app_main`
  0xFFF94AFA) and the callers of `FUN_20117288` in DISPLAY. Pages: [system.md §4](../code/system.md#4-power-on-and-power-off),
  [main/display-link.md](../code/main/display-link.md), [display/mainlink.md](../code/display/mainlink.md).

### 2. C7: SDR configuration-flash layout (bitstream at 0 vs. update at 0x240000)
- **Labels:** `analysis`, `sdr`, `display`
- **Body:** The FPGA boots master-SPI x4 from flash address 0 ([sdr/bitstream.md](../code/sdr/bitstream.md)), but the DISPLAY update
  writes the bitstream to 0x240000 and its header to 0x480000 ([display/update.md §8](../code/display/update.md)). Either a golden image
  at 0 multiboots into 0x240000, or the fabric flash master maps the slots itself. Look for WBSTAR/IPROG use and the reg 0x32 commands
  in the netlist (T15 tools, Verilator model). Reading the module flash over J2001 would settle it but needs approval (separate issue).

### 3. C9: DSP 12 kHz audio blocks vs. 16 kHz REC/PLAY WAV
- **Labels:** `analysis`, `ifdsp`, `display`
- **Body:** [ifdsp/hifi4.md](../code/ifdsp/hifi4.md) infers 12 kHz audio blocks; [display/spi-links.md](../code/display/spi-links.md)
  shows REC WAV at 16 kHz stereo, 16 frames/s. Consistent only if `Thread_Spi` resamples or the WAV header is nominal. Read the HiFi4
  `Thread_Spi` packing of the 4000-byte PCM part in the FLIX listing (`tools/ifdsp_hifi4_dis.py`).

### 4. O1: how is `boot_error` 0x20B36 (missing FPGA / DSP) shown?
- **Labels:** `analysis`, `main`, `display`, `good first issue`
- **Body:** MAIN's `displink_build_60` reads `boot_error` (3 = FPGA missing, 2 = DSP missing). Trace the DISPLAY's handling of the
  `0x60` frame byte that carries it, and document the message the user sees. Pages: [main/display-link.md](../code/main/display-link.md),
  [display/mainlink.md](../code/display/mainlink.md).

### 5. O2: MAIN 0x43/0x44/0x45 and DISPLAY C3/C4/C5 frames (MemList/Menu backup?)
- **Labels:** `analysis`, `main`, `display`
- **Body:** MAIN treats them as SD/memory-list operations; DISPLAY has 'D'/'E' block read/write of a 32000-byte buffer (block ids
  'A'..'D', `FUN_2010f240`..`FUN_2010f300`). Map MAIN's 0x43 callers to the DISPLAY `sdmenu_*` code and document the payloads.

### 6. O3: scope frame header and rate
- **Labels:** `analysis`, `sdr`, `display`
- **Body:** The 25-byte scope header, the unused second 850 bytes of each SDR DMA frame and the frame rate are unknown
  ([display/spi-links.md](../code/display/spi-links.md)). Find the DISPLAY scope SPI slave among the bank 14/15 FPGA pins with the
  whole-netlist Verilator model (`hdl/sdr/sim/`) and read its framing. (A capture on a debug-enabled radio is the other route; it needs
  approval.)

### 7. O4: CM119B USB audio routing (hardware)
- **Labels:** `hardware`, `good first issue`
- **Body:** Trace the CM119B (Q2624) analog in/out on the service manual (p20) and add it to [hardware.md](../hardware.md).

### 8. O5: RZ/A1H USB0/USB1 lines through J6002 (hardware)
- **Labels:** `hardware`, `display`, `good first issue`
- **Body:** Follow the DISPLAY CPU's USB0/USB1 data lines through J6002 in the service manual and record where they end up
  ([hardware.md](../hardware.md)).

### 9. O6: MAIN main-loop tasks 10, 11 and 13
- **Labels:** `analysis`, `main`
- **Body:** `dispreq_e8_task`, `dispreq_e7_task` (DISPLAY frames 0xE7/0xE8 → 0x20F8C/0x20F90) and `FUN_fffd0582` (0x15DE3). E7/E8 look
  like SD-file operation status from the DISPLAY [inference]. Document them in [main/README.md](../code/main/README.md).

### 10. O7: ADC sample rate, 250 or 125 MSPS?
- **Labels:** `analysis`, `sdr`, `hardware`, `needs-radio`
- **Body:** The fabric runs at 125 MHz and the clock from the MAIN unit is 250 MHz; the 14 LVDS ADC pairs are captured DDR. Either decode
  the IDDR edge mode (prjxray has no bits for it) or identify the ADC from a photo of its marking on the SDR module (owner).
  [system.md §8](../code/system.md#8-contradictions-and-open-questions).

### 11. O8: `DSP_CLK` frequency (MMCM divider re-check)
- **Labels:** `analysis`, `sdr`
- **Body:** The RT685 code is built for 18.432 MHz; the netlist reading gives ~28.17 MHz on P14, which needs an out-of-range 1,440 MHz VCO,
  so a divider is probably misread (a multiplier of 22.25 would give 18.432 MHz). Re-check MMCM_X0Y0's CLKFBOUT/DIVCLK fields in the FASM
  ([sdr/netlist.md §3.2](../code/sdr/netlist.md)). A passive-probe measurement of J2002 pin 22 is the alternative (`needs-radio`).

### 12. O9: what does DISPLAY address 0x60000000 decode to?
- **Labels:** `analysis`, `display`, `docs`
- **Body:** The frame buffers at 0x60000000..0x602FF2FF cannot be a plain uncached mirror of 0x20000000 (`fb_clear_all` would wipe running
  code). Get the RZ/A1H hardware manual (R01UH0403, address-map chapter; see [manuals.md](../manuals.md)) and fix
  [memory-maps.md](../memory-maps.md) and [display/gui.md](../code/display/gui.md).

## MAIN

### 13. Resolve the 65 "Open (needs disassembly)" items in cat-commands-primary.md
- **Labels:** `analysis`, `main`, `cat`, `good first issue`
- **Body:** Most are `in_R14` artifacts in `FUN_fffb324c`/`FUN_fffb3196` (active vs. other VFO) and dropped digit weights. Each is a
  small, separate job: read the case in the disassembly (`tools/ghidra/DumpListing.java`) and replace the note with the real behaviour
  in [cat-commands-primary.md](../cat-commands-primary.md). Split into several issues if you take more than a few.

### 14. Create functions at the 507 key-handler targets and name the physical keys
- **Labels:** `analysis`, `main`, `tooling`
- **Body:** 507 of 536 handler addresses in the key tables are not function entries ([main/ui-keys.md](../code/main/ui-keys.md)). List
  them with `python3 -I tools/main_key_tables.py out.tsv`, add them as entries (a `FixFuncEntries`-style TSV for MAIN), re-export, and
  name each physical key 0x300..0x312 with the DISPLAY key-code table ([display/input.md](../code/display/input.md)).

### 15. The 4651-entry code-pointer table at 0xFFF89D94
- **Labels:** `analysis`, `main`
- **Body:** 863 distinct handlers, probably the menu/UI dispatch (T05). The dial encoder and key paths (`FUN_fffc5e0a`) were followed only
  to shared helpers (T10g). Identify the table's index and document it.

### 16. Payload layouts of the large MAIN → DISPLAY frames
- **Labels:** `analysis`, `main`, `display`
- **Body:** 0x20, 0x24, 0x30/0x31, 0x37, 0x39, 0x3A, 0x40, 0x41, 0x50, 0x62, 0x70, the 0x97-byte radio status block (field ranges in
  `mainlink_status_valid` 0x2015E354), and the senders of DISPLAY packets 0x64 (LCD test) and 0x34 (info). Also E2 and the E7/E8 result
  codes, boot codes 2/4/5, and the mode flags 0x20BBE/0x20B8A/0x20B98/0x20B7C. Pages: [main/display-link.md](../code/main/display-link.md),
  [display/mainlink.md](../code/display/mainlink.md).

### 17. EEPROM: the full 90-byte memory record and the menu-block field map
- **Labels:** `analysis`, `main`
- **Body:** Unknown record bytes (+0x04, +0x06..09, +0x47, FM block), the menu block 0x9A2A..0x9C34, message type 0 (0x93A7, 5 × 0x98 from
  0x120BC), the tuner-memory semantics of 0x1B3AD/0x1B3AF. Pages: [main/eeprom.md](../code/main/eeprom.md),
  [main/radio-control.md](../code/main/radio-control.md).

### 18. Menu: name the item callbacks and confirm the hidden values
- **Labels:** `analysis`, `main`
- **Body:** Name the per-item `on_draw`/`on_step` callbacks (labels today), look at the non-trivial steppers (LCUT/HCUT, KEYBOARD
  LANGUAGE, CAT-n RATE, MAX POWER, presets), find what "TTBF" (SSB TX BPF value 6) does in the DSP/TX path, which power-on option sets
  0x4760, and the CW WEIGHT display formula. Settings 0x9AA1, 0x9AD2, 0x9AD3, 0x9B14, 0x9B16/17 (SDR regs 0x0D, 0x1C, 0x1B, 0x23/0x27,
  0x26) still need names. [main/menu.md](../code/main/menu.md).

### 19. TX control: /SST2 register, PTT sources and TX inhibits
- **Labels:** `analysis`, `main`, `hardware`
- **Body:** `FUN_fffb5d68` (/SST2 12-bit register, 2322 bytes) and the BU2505 channel → PA net mapping (PA schematic pp. 56–57); who sets
  PTT sources 0x20B2A..0x20B2E and the acks 0x20B19/0x20B1A; the meaning of 0x9AF5, 0x20B97, 0x20F1C/0x20F70; the start-mode byte in
  `FUN_fff9546a` (0x01 reset, 0x05, 0x07 region swap, 0x10 auto power-on). [main/tx-protection.md](../code/main/tx-protection.md).

### 20. CAT: `ZZ` mode, restart codes and the `E9` binary framing
- **Labels:** `analysis`, `main`, `cat`
- **Body:** The meaning of `ZZ` mode 0x20BBE and of the restart codes 0x20B39 = 0x10/0x11; how the SCI receive path frames the 10 kB
  binary `E9` frame (how a `;` inside the data is handled; check the RXI/ERI ISRs); the SCI4 device and the `cfg105` table (0x4659) and
  ROM preset table 0xFFF88CD4. [main/cat.md](../code/main/cat.md), [cat-commands.md](../cat-commands.md).

### 21. DSP link: routing registers 8/9/10 and the settings bytes behind regs 0x2F–0x67
- **Labels:** `analysis`, `main`, `ifdsp`
- **Body:** Name MAIN's setters/getters in the register map, explain routing regs 8/9/10 and their constants (0x0C–0x13, 0x30–0x3B, 0x56,
  0x68) from the DSP readers, and who reads regs 0x2000–0x200F and 0x4001. [main/dsp-link.md](../code/main/dsp-link.md),
  [ifdsp/control-link.md](../code/ifdsp/control-link.md).

### 22. 244 bytes of undefined const data at 0xFFFEE1BE..0xFFFEE2B7
- **Labels:** `analysis`, `main`, `good first issue`
- **Body:** Look at the block (T05), say what it is, and define it in Ghidra (a names/label entry in `tools/ghidra/names_main.tsv`).

### 23. Board level of PC7/UB on the MAIN schematic
- **Labels:** `hardware`, `main`, `good first issue`
- **Body:** Read the level on the MAIN schematic (service manual p17) to turn the inference in T18 item 4 into a fact
  ([docs/tasks/T18-renesas-docs-check.md](T18-renesas-docs-check.md)).

## DISPLAY

### 24. How are the hidden DISPLAY debug commands entered?
- **Labels:** `analysis`, `display`
- **Body:** `sdrup`, `sdr1up`, `dsp1up`, `uptest2`, `reset`, `delta`, … (`sdr_debug_cmd` 0x20110C3C, `fwdbg_*`). Which input path (USB
  keyboard, FT4222 SPI, the debug console) reaches them, and is `task_keycode` trace/replay gated by `debug_enabled`?
  [display/input.md](../code/display/input.md), [display/update.md](../code/display/update.md).

### 25. Remaining DISPLAY code gaps (2.7 KB of fragments, thunk names)
- **Labels:** `analysis`, `display`, `tooling`
- **Body:** About 2.7 KB of switch-case fragments in `.text` remain undefined. `fwupdate_screen` (0x201322B4) and `FUN_201322AC`…0x201322F0
  are tail-call thunks into an update-UI object; the real `fwupdate_screen` is 0x20159714. The mouse task entry 0x2015FD60 is a late start.
  Add entries to `tools/ghidra/entries_display.tsv`, re-run `tools/bootstrap.sh --only ghidra,export` and commit the new export.

### 26. DISPLAY peripherals to confirm against the RZ/A1H manual
- **Labels:** `analysis`, `display`, `docs`
- **Body:** The STBCR bit map, TINT numbering and the IDs 78/303; the RSPI ↔ pin and GIC 535/449 ↔ TINT pin mapping; which pins TINT33 and
  TINT119 are; which of P10_0/P10_1/P9_0/P10_3 is TCLKA..D (encoder identity, C4). Needs R01UH0403 ([manuals.md](../manuals.md)).
  [display/peripherals.md](../code/display/peripherals.md), [display/spi-links.md](../code/display/spi-links.md).

### 27. GUI: screen layout from `.data2`, scope drawing, format vs. mount
- **Labels:** `analysis`, `display`
- **Body:** Decode the `.data2` coordinate tables into a full screen layout; drawing from the scope record / history ring (0x20134318,
  0x20134328); the per-command screen functions called by `gui_screen_update`; `FUN_2013f984`/`FUN_2013f83c` (format vs. mount); the
  0x183D0000 settings record. [display/gui.md](../code/display/gui.md).

### 28. Who checks the SDR header CRC-32/BZIP2?
- **Labels:** `analysis`, `display`, `sdr`
- **Body:** The SDR image starts with a big-endian CRC-32/BZIP2 over the bitstream ([decomp/sdr/README.md](../../decomp/sdr/README.md)), but
  no CPU image holds the MSB-first table or constant. Look for a bitwise CRC loop in the DISPLAY `sdr_*` code, or for a checker in the
  FPGA netlist (`sdrchk` path).

### 29. Where does DISPLAY report its own version to MAIN?
- **Labels:** `analysis`, `display`, `good first issue`
- **Body:** Needed for a visible, normal-mode version marker in custom firmware (T16). Find the frame and the string.

## IFDSP

### 30. Per-algorithm documentation of the HiFi4 RX/TX chains
- **Labels:** `analysis`, `ifdsp`
- **Body:** NR, NB, notch, AGC and demodulators from the FLIX-aware listing (`tools/ifdsp_hifi4_dis.py`); map the reg 6 values to modes with
  the MAIN setters; which FLEXCOMM gives SCK/WS to FC3 (RX IF) and FC4 (codec in), and the MCLK select; confirm the FLIX-hidden operands
  in the IPC code and `xthal_set_region_attribute` 0x233410 [inference]. [ifdsp/hifi4.md](../code/ifdsp/hifi4.md).

### 31. Commit the HiFi4 FLIX listing?
- **Labels:** `needs-owner`, `ifdsp`, `tooling`
- **Body:** T12e/T17 suggested committing `decomp/ifdsp/hifi4/flix.dis` (~53k lines; command in
  [decomp/ifdsp/INDEX.md](../../decomp/ifdsp/INDEX.md)). If yes, add it as a `bootstrap.sh` step (it needs the Zephyr SDK objdump).

### 32. IFDSP: the INPUTMUX selection in `app_main`
- **Labels:** `analysis`, `ifdsp`, `good first issue`
- **Body:** What `INPUTMUX_AttachSignal(1, 0x14000015)` in `app_main` selects (T12d), with the RT600 reference manual
  ([ifdsp/m33-platform.md](../code/ifdsp/m33-platform.md)).

## SDR (FPGA)

### 33. RTL for the debug console (UART A) and the `x` command
- **Labels:** `analysis`, `sdr`
- **Body:** Write behavioural RTL for UART A like `hdl/sdr/uart_link.v`; explain its echo/BS quirk and `#` → 0x06; find whether `x` is gated
  by an input pin (drive the remaining bank 14/15 inputs one at a time in the whole-design model). A CR during a running reply restarts it in
  the netlist; not modelled. [sdr/netlist.md §5](../code/sdr/netlist.md), [hdl/sdr/README.md](../../hdl/sdr/README.md).

### 34. Find the DISPLAY scope SPI slave and the I2S ports in the netlist
- **Labels:** `analysis`, `sdr`
- **Body:** Among the remaining bank 14/15 pins; also the J2002-to-FPGA pin path for the UARTs, `UART_DBG_TX`, the UART5 pins and the MRCC
  board clock. Use `tools/xc7_blocks.py io` and the Verilator model (`tools/bootstrap.sh --only sdr`).

### 35. DSP48E1 `USE_MULT` and OPMODE/ALUMODE polarity
- **Labels:** `analysis`, `sdr`, `tooling`
- **Body:** `USE_MULT` has no prjxray segbits (every DSP is written as `MULTIPLY`), and the OPMODE/ALUMODE pin polarity is unsettled
  ([sdr/netlist.md 3.5](../code/sdr/netlist.md)). Decide from routing or fuzz it before reading the DDC arithmetic. Also check whether a
  newer prjxray-db explains the 198 unexplained DSP bits and 86 RIOB33 bits.

### 36. Netlist fidelity: RAMB36 pairs and SRL/RAM32 DI2
- **Labels:** `tooling`, `sdr`
- **Body:** RAMB36 pairs are written as two RAMB18E1 halves; write true RAMB36E1 instances where T13's pairing is certain. Verify the
  assumed DI2 source of SRL16/RAM32 O5 halves against UG474. `tools/xc7_netlist_verilog.py`.

### 37. STARTUPE2 / fabric flash master
- **Labels:** `analysis`, `sdr`
- **Body:** The QSPI master on the configuration-flash pins needs STARTUPE2 `USRCCLKO`, which prjxray-db cannot decode
  (`CFG_CENTER_MID` has routing bits only). Find another way to confirm it (routing into the site, behaviour in simulation).

### 38. Routing-level BRAM/LVDS ties and the J2002 pins 14 and 37
- **Labels:** `analysis`, `sdr`, `hardware`
- **Body:** Tie the BRAM tables and LVDS pins to blocks through routing (T13), and read J2002 pins 14 and 37 from a higher-resolution
  scan of the service manual.

## Tooling and docs

### 39. Add the custom-firmware.md edits left over from T11c/T11f
- **Labels:** `docs`, `good first issue`
- **Body:** T17 did not apply: replace blocker 4 with the [display/update.md](../code/display/update.md) §1 check list; the SDR row of
  "Update and recovery paths" (DISPLAY sends the bitstream over RSPI2 while MAIN bridges registers; no CRC check at boot; key-6 maintenance
  mode and JTAG `loader_selfinstall` recovery); the 1-byte debug-console gate patch / options table from
  [display/input.md](../code/display/input.md). Check what [custom-firmware.md](../custom-firmware.md) already says first.

### 40. Test `tools/bootstrap.sh` on macOS and on a clean Debian/Ubuntu machine
- **Labels:** `tooling`, `good first issue`
- **Body:** T20 tested the bootstrap on the Linux container (Debian bookworm, x86_64) with Ghidra and the JDK already installed; the `deps`
  download step was run only from the local download cache. Run `tools/bootstrap.sh --only deps` then the default steps on a clean
  machine, and on macOS with Homebrew (`brew install ghidra`), and report the result (the decomp diff must be empty).

### 41. The HiFi4 decompile is low quality (FLIX bundles)
- **Labels:** `tooling`, `ifdsp`
- **Body:** Ghidra's Xtensa module decodes only the base ISA; 955 of 1148 HiFi4 functions hit FLIX bundles and `FUN_0020bb74` crashes the
  decompiler. A SLEIGH extension for the RT600 HiFi4 core configuration (from the Zephyr SDK overlay) would make `decomp/ifdsp/hifi4`
  usable. Large; check licensing of the core overlay first.

## Needs the radio or the owner's decision

These need the physical radio or an explicit owner decision. **Nothing here may be done without the owner's approval, each time.**

### 42. Which read-only undocumented CAT forms may be tried on the radio?
- **Labels:** `needs-owner`, `needs-radio`, `cat`
- **Body:** Safe candidates (read-only): `VE0;`..`VE3;`, `JP0710;` (read), `FD000;`/`FD001;`/`FD002;`, `PE000;`, `SPIR;`; `E8` is
  read-only but returns 10 kB. **Never** send `SPSW/SPDW/SPW/SPAWE/E9/ZZ/JP`-set. Also optional: `SPSR` reads of the unknown SDR
  registers (T10c), and the US 60 m behaviour (T10h). [cat-commands.md](../cat-commands.md).

### 43. Custom firmware: approve (or not) debug-console step 0/1 and FPGA stage 1
- **Labels:** `needs-owner`, `needs-radio`
- **Body:** The T16 plan ([custom-firmware.md](../custom-firmware.md), [patches/](../patches/README.md)): debug-console steps 0 and 1 and FPGA
  stage 1. Also optional patch 2b (blank chain-1 slot 0, `fwdbg_init`, so `up0`/`up1`/`up2`/`fw1up` cannot be typed by accident).

### 44. Physical facts only the owner can read off the radio
- **Labels:** `needs-radio`, `hardware`, `good first issue`
- **Body:** The FPGA package marking on the SDR module (settles the package, T13/T16), the ADC part marking (O7), and the FFC pitch of
  J1004/J6003/J2009/J2001 (before buying breakouts). Photos are enough; nothing is connected or written.

### 45. Read the SDR module's configuration flash over J2001
- **Labels:** `needs-owner`, `needs-radio`, `sdr`
- **Body:** Settles C7 (flash layout) for good. Read-only, but it needs opening the radio and a JTAG/SPI adapter, so the owner decides.
