# T10d — MAIN DSP link (SCI4 console protocol, SCI7)

**Status:** done · **Depends on:** T05 T12a · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): dsp-link.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10d.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
The MAIN side of the IFDSP register-poke protocol (T12a: `FUN_fff9d06c` sends `i DB00`, `FUN_fffa0b4c` builds `rAAAACC`/`wAAAADDDDCC`): which registers MAIN writes for which radio functions, timing, error handling; what SCI7 ("C4") carries. Cross-reference `docs/code/ifdsp/` (T12b owns the DSP side).

## Plan
1. Read the SCI4 transport (`R_SCI4_*`, `FUN_fffb1ab4`), the frame builder/checksum/reply wait (`FUN_fffa0b4c`, `FUN_fffa0c01`,
   `FUN_fffa0ad6`), the generic accessor `FUN_fff9d8a4` and init `FUN_fff9d06c` in `decomp/main/`; get timing/retry from them.
2. Enumerate every caller of the frame builder / accessor (Ghidra xrefs on my project copy `FT710_MAIN_T10d`), and for each
   setter record register address, value source (RAM global → setting/menu/CAT command, via xrefs to that global from
   `cat_XX` handlers and the menu tables), and trigger (boot, mode change, CAT set, periodic).
3. SCI7: read `R_SCI7_Create` and its ISRs/callers, find what is sent and received.
4. Write `docs/code/main/dsp-link.md` (function table, register table, globals, sequence + flow figures), names TSV, findings.

## Findings
Page: [docs/code/main/dsp-link.md](../code/main/dsp-link.md). Names: `tools/ghidra/names_main.T10d.tsv` (102 proposals).
- SCI4 (PB0/PB1, 115200 8N1) carries the RT685 console protocol. One transaction at a time, at most one frame per
  `main_loop` pass, 6 ms reply timeout (timer 3). A shadow copy per register (0x1B634..0x1B6DD, preset 0xFFFF) and one
  setter per register: a write is sent only when the computed value differs from the shadow, and the shadow is updated
  only on ACK, so failures retry implicitly. No retry limit or error counter after boot. [fact]
- Boot (`FUN_fff9d06c`): P71=1, 100 ms, `i DB00\r`, 2 ms, read reg 0 (version -> 0x1444 "V01-01", CAT VE) and reg 1
  (bit0 ready), each tried once; failure sets 0x20B36=2. [fact]
- About 75 registers written (6, 8-0x13, 0x20-0x38, 0x3A-0x53, 0x56, 0x5C, 0x5D, 0x61-0x63, 0x66-0x68, 0x400B, 0x400D,
  0x4020-0x4026), mapped to modes, VFO record bits (BC, CO, BP, GT, NR/RL, CT), CAT globals (PL, PR, AO, VG, AV, AG, RG,
  KP, AS, SS07) and menu bytes (per-mode blocks from 0x9A2A, RX DSP group from 0x9AD1, PRMTRC EQ 0x9ADA). DNR levels
  1-7 / 8-15 select two parameter tables at 0xFFF87F1A..0xFFF87FFA. [fact for encodings; menu names inference]
- Status regs 1-4 polled every 20 ms in TX/RX steady states: reg1 = ready/VOX/tone-detect/FM noise, reg2 = COMP meter,
  reg3 = S meter, reg4 = ZIN tuning offset. [inference]
- `FUN_fffb4219` = audio-route state 0..14 (decompile broken; decoded from disassembly).
- DSP firmware update: DISPLAY sub-command 2 -> `FUN_fffa0c79` holds P71/P72 for RT685 serial ISP and bridges NXP
  MCUBoot (0x5A-framed) packets between SCI1 and SCI4 until `F1 82`. [fact bytes; MCUBoot inference high]
- SCI7 is configured (P90/P92, ~9600 baud) but never enabled and never used. [fact]
- CAT `SPD W` writes bypass the shadow, so the value stays until the managing setting changes. [inference from code]
- Low-address loads in the setter decompiles are the SLEIGH `MOVU.B/W Rs,Rd` bug (T10e), not firmware bugs.

## Proposed shared-file edits
- `docs/hardware.md` (MAIN UART table): add `SCI4 | PB0 RXD4 / PB1 TXD4 | RT685 FLEXCOMM0 console (DSP_UMISO/UMOSI)`
  [fact: R_SCI4_Create PFS 0x8C198/0x8C199], SCI7 pins P90 TXD7 / P92 RXD7 [fact], and "SCI7 unused in V01-12";
  P71 = DSP reset, P72 = DSP update/ISP select [inference].
- `docs/code/main/README.md` (T10a): subsystem row for dsp-link.md; `dsp_link_poll` 0xFFF9D1B9 is a main_loop task.
- `docs/memory-maps.md` (MAIN RAM): 0x1B634..0x1B6DD DSP register shadows; 0xA0AB SCI4 RX buffer.

## Follow-ups
- T10f: confirm the menu-byte identities (0x9A2A.. blocks, 0x9AD1..0x9AD9, 0x9DC6 alternative set 0x20B5B..0x20B67, 0x9DC2).
- T12b/T12e: meaning of routing regs 8/9/10 and the constants (0x0C-0x13, 0x30-0x3B, 0x56, 0x68) from the DSP readers.
- After the SLEIGH fix and re-export, re-check `FUN_fff9dc8a`, `FUN_fff9eae7`, `FUN_fff9ed0e`, `FUN_fff9f638`.
