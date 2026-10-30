# T12b — IFDSP M33 console / command link

**Status:** done (2026-10-27) · **Parent:** T12 · **Depends on:** T12a

## Goal
`docs/code/ifdsp/control-link.md`: FLEXCOMM0 USART driver, Command Task, console command grammar (interactive and machine mode), frame format, register file, MAIN-side register list, function table.

## Plan
1. Read M33 decomp of the FC0 driver, CommandTask, `console_rx_char` and the `console_cmd_*` handlers; list every command, argument and effect in both modes; confirm the frame grammar and checksum (`frame_checksum_ok`).
2. Register file: `regfile_*` functions and every M33 access (reg 0, 1, 10, 0x4000, 0x4005, ...). Codec: `aic3204_*` bit-banged SPI and the 67-write init table 0x00087A1C.
3. HiFi4: find every literal/offset into 0x20070000 (and 0x2006FF00/0x20077F00 bases), and dump `regfile_set_defaults` 0x0021BE80 to get the default table.
4. MAIN: read `decomp/main` around `FUN_fff9d06c`/`FUN_fffa0b4c` and the per-register setters to list registers MAIN writes/reads (and with what source value, as far as cheap).
5. Merge into one register map (address, writer, reader, default, meaning, tag). Write `docs/code/ifdsp/control-link.md` (function tables, sequence diagram of a frame, state diagram of the two modes, register map). Propose names in `tools/ghidra/names_ifdsp.T12b.tsv`. Commit.

See also the T12 plan. Starting notes from T12a below (all M33 names already applied in `IfdspM33Names.java`).

## Starting notes (from T12a)
- Driver: `uart0_init` 0x80D0C (FC0, 115200), `FLEXCOMM0_IRQHandler` 0x80E50 (RX ring 0x87EC8, TX ring 0x882D4, 1 KB each; sets event-group bit 0), `uart0_write` 0x80CA4, `uart0_tx_pending` 0x80F3C, `CommandTask` 0x80D78, `console_init` 0x813EC, `console_rx_char` 0x81430, `console_puts` 0x85FAE.
- Two modes: flag 0x88D2D (lower-case + table dispatch) / 0x88D2E (echo). Interactive: tokens (≤4 × 15 chars at 0x88D2F) lower-cased, table 0x8795C (4 × {name[16], handler}): `r` 0x813B4 `console_cmd_r`, `w` 0x812C4 `console_cmd_w`, `d` 0x812FC `console_cmd_d` (0x40-word dump), `i` 0x81274 `console_cmd_i` (`i db00` → machine mode, `i db01` → interactive). Line end CR/LF/NUL; Ctrl+C, BS/DEL, ESC handled.
- Machine mode (first char = command, rest hex, last 2 hex = 8-bit sum of the preceding chars, checked by `frame_checksum_ok` 0x86044): `rAAAACC` (7 chars) → reply `r` + `%04X` value + `%02X` sum; `dAAAACC`/`DAAAACC` → dump; `iDBxxCC` → mode; `wAAAADDDDCC` (11 chars) → `regfile_write`, reply 0x06 (ACK). Invalid → `?`.
- Register file: `regfile_clear/read/write/set_bits` 0x80C20/0x80C30/0x80C4C/0x80C78, 0x20070000..0x2007FFFF. Writing reg 10 also writes codec page 1 reg 0x37 (IN1R vs IN2R into the right MICPGA, low nibble == 1 → 0x40 else 0x10).
- MAIN side (T10 owns the names): frame builder `FUN_fffa0b4c(cmd)` with address `DAT_0001b6de`, data `DAT_0001b6e0`, checksum `FUN_fffa0c01`, reply wait `FUN_fffa0ad6`, generic access `FUN_fff9d8a4`, init `FUN_fff9d06c` (`i DB00`), transport `FUN_fffb1ab4` → `R_SCI4_Serial_Send`. Shadow copies at 0x1B62E + 2·reg. Registers MAIN reads: 0–4; writes: 6, 8, 9, 10, 0xC–0xF, 0x11–0x13, 0x20–0x22, 0x2E–0x38, 0x3A, 0x3B, 0x40–0x47, 0x51–0x53, 0x56, 0x5C, 0x5D, 0x61, 0x62, 0x66–0x68, 99, 0x400B, 0x400D, 0x4020, 0x4022, 0x4023, 0x4025, 0x4026 plus computed addresses in `FUN_fff9dd6a`, `FUN_fff9dee6`, `FUN_fff9dfd5`, `FUN_fff9ef34`, `FUN_fff9f291`, `FUN_fff9f0b1` (one setter function per register, e.g. `FUN_fff9db37` = reg 0xF).

## Findings
Page: [`docs/code/ifdsp/control-link.md`](../code/ifdsp/control-link.md).
- Console grammar fully decoded (both modes, every command, error replies, line editor keys) **[fact]**. Machine mode: `rAAAACC`/`RAAAACC`,
  `wAAAADDDDCC`/`W…`, `dAAAACC`/`D…`, `iDB0xCC`/`idb0xCC`; CC = 8-bit ASCII sum; read reply `r%04X%02X` without CR, write reply 0x06,
  bad length/checksum `?`, non-hex silently dropped.
- Register map: 113 registers with DSP defaults (HiFi4 `regfile_set_defaults` 0x0021BE80) cross-checked against 72 MAIN-written registers
  (all have defaults) and the M33 (0, 1, 10, 0x4000, 0x4005). Identified by MAIN formulas: reg 6 demod class, regs 0x25–0x2D TX 3-band
  parametric EQ, 0x48–0x50 RX EQ, reg 4 CW zero-in offset, regs 1–3 squelch/meter status **[inference]**.
- The HiFi4 code decodes correctly with the Zephyr SDK `xtensa-nxp_rt600_adsp_zephyr-elf-objdump` (FLIX bundles included); new helper
  `tools/ifdsp_hifi4_regscan.py` scans it for register-file accesses.
- CAT `SPDRaaaa;`/`SPDWaaaavvvv;` (`cat_SP_dev4_reg` → `dev4_reg_access` 0xFFF9D8A4) is raw access to this register file **[fact]**.
- Two unused 4 KB capture blocks at regs 0x7000/0x7800 (append helper has no caller) **[fact]**.
- Codec init table (67 writes) decoded; reg 10 switches the right MICPGA input IN1R/IN2R **[fact]**.
- 13 names proposed in `tools/ghidra/names_ifdsp.T12b.tsv` (2 M33 that need function creation, 11 HiFi4).

## Follow-ups
- T10d: names for the MAIN setters/getters listed in the register map; meanings of settings bytes 0x9Axx feeding regs 0x2F–0x67.
- T12e: per-register DSP reader semantics (HiFi4 functions listed in the map), bands 1–2 EQ readers (indirect access), `FUN_0021c498` init.
- Who reads regs 0x2000–0x200F, 0x4001 (only zeroed/defaulted).
- Use the RT600 objdump in T12e (much better than Ghidra's base-ISA decode).

## Proposed shared-file edits
- `docs/cat-commands.md` row `SPDRaaaa;`/`SPDWaaaavvvv;`: replace the old guessed text ("device unknown; perhaps the IF-DSP") with "IFDSP register file
  (see docs/code/ifdsp/control-link.md) [fact]".
- `tools/ghidra/names_main.tsv` (T10 owners): `fff9d8a4 ifdsp_reg_access`, `fffa4e8f cat_SP_ifdsp_reg`, `fffa0b4c ifdsp_send_frame`,
  `fffa0ad6 ifdsp_wait_reply`, `fffa0c01 ifdsp_checksum`, `fffa037a ifdsp_store_shadow`, `fff9d06c ifdsp_link_init`, `fff9d1b9 ifdsp_link_poll`,
  `fffa0e3a ifdsp_mode_reg_value`.
- `tools/ghidra/IfdspM33Names.java`: add 0x0008138C `console_printf`, 0x00085F88 `aic3204_select_right_input` (create functions).
- `docs/tooling.md`: record the Zephyr SDK 0.17.0 `xtensa-nxp_rt600_adsp_zephyr-elf` toolchain in `~/opt/zephyr-sdk-0.17.0` if not yet listed.
- `docs/code/ifdsp/README.md`: subsystem index row for control-link.md can say "register map (113 regs)".

## Status
Done.
