# T12b — IFDSP M33 console / command link

**Status:** todo · **Parent:** T12 · **Depends on:** T12a

## Goal
`docs/code/ifdsp/control-link.md`: FLEXCOMM0 USART driver, Command Task, console command grammar (interactive and machine mode), frame format, register file, MAIN-side register list, function table.

## Plan
See T12 plan. Starting notes from T12a below (all M33 names already applied in `IfdspM33Names.java`).

## Starting notes (from T12a)
- Driver: `uart0_init` 0x80D0C (FC0, 115200), `FLEXCOMM0_IRQHandler` 0x80E50 (RX ring 0x87EC8, TX ring 0x882D4, 1 KB each; sets event-group bit 0), `uart0_write` 0x80CA4, `uart0_tx_pending` 0x80F3C, `CommandTask` 0x80D78, `console_init` 0x813EC, `console_rx_char` 0x81430, `console_puts` 0x85FAE.
- Two modes: flag 0x88D2D (lower-case + table dispatch) / 0x88D2E (echo). Interactive: tokens (≤4 × 15 chars at 0x88D2F) lower-cased, table 0x8795C (4 × {name[16], handler}): `r` 0x813B4 `console_cmd_r`, `w` 0x812C4 `console_cmd_w`, `d` 0x812FC `console_cmd_d` (0x40-word dump), `i` 0x81274 `console_cmd_i` (`i db00` → machine mode, `i db01` → interactive). Line end CR/LF/NUL; Ctrl+C, BS/DEL, ESC handled.
- Machine mode (first char = command, rest hex, last 2 hex = 8-bit sum of the preceding chars, checked by `frame_checksum_ok` 0x86044): `rAAAACC` (7 chars) → reply `r` + `%04X` value + `%02X` sum; `dAAAACC`/`DAAAACC` → dump; `iDBxxCC` → mode; `wAAAADDDDCC` (11 chars) → `regfile_write`, reply 0x06 (ACK). Invalid → `?`.
- Register file: `regfile_clear/read/write/set_bits` 0x80C20/0x80C30/0x80C4C/0x80C78, 0x20070000..0x2007FFFF. Writing reg 10 also writes codec page 1 reg 0x37 (IN1R vs IN2R into the right MICPGA, low nibble == 1 → 0x40 else 0x10).
- MAIN side (T10 owns the names): frame builder `FUN_fffa0b4c(cmd)` with address `DAT_0001b6de`, data `DAT_0001b6e0`, checksum `FUN_fffa0c01`, reply wait `FUN_fffa0ad6`, generic access `FUN_fff9d8a4`, init `FUN_fff9d06c` (`i DB00`), transport `FUN_fffb1ab4` → `R_SCI4_Serial_Send`. Shadow copies at 0x1B62E + 2·reg. Registers MAIN reads: 0–4; writes: 6, 8, 9, 10, 0xC–0xF, 0x11–0x13, 0x20–0x22, 0x2E–0x38, 0x3A, 0x3B, 0x40–0x47, 0x51–0x53, 0x56, 0x5C, 0x5D, 0x61, 0x62, 0x66–0x68, 99, 0x400B, 0x400D, 0x4020, 0x4022, 0x4023, 0x4025, 0x4026 plus computed addresses in `FUN_fff9dd6a`, `FUN_fff9dee6`, `FUN_fff9dfd5`, `FUN_fff9ef34`, `FUN_fff9f291`, `FUN_fff9f0b1` (one setter function per register, e.g. `FUN_fff9db37` = reg 0xF).

## Findings

## Status
