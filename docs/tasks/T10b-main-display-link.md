# T10b — MAIN SCI drivers, DISPLAY link (SCI1) and front-panel key events

**Status:** done · **Depends on:** T05 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): sci.md, display-link.md, ui-keys.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10b.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
SCI0–SCI7 driver layer (create/start/stop, ISRs, ring buffers, baud tables); the SCI1 protocol to the DISPLAY CPU (frame format, commands both ways, retries; cross-check with T11b `mainlink_*` on the DISPLAY side); how key/encoder/touch events from DISPLAY are turned into radio actions.

## Plan
1. SCI layer: read the r_cg_sci functions (decomp `fff90d85..`, `fff9340d..fff94535`, `fff94536..`, `fffc9...`) and the
   SCI wrappers around 0xFFFB16xx..0xFFFB1Dxx; record per channel: SMR/BRR/SCR values, buffers, callbacks, group-interrupt
   TEI/ERI handlers, baud tables. Page `docs/code/main/sci.md`.
2. DISPLAY link: follow `R_SCI1_Serial_Receive/Send` callers and the SCI1 receive-end callback; find the frame parser
   (`FUN_fff957e6` is known to have a sub-command switch), the TX queue/formatter and the retry/ack logic; enumerate every
   command both directions. Cross-read DISPLAY `mainlink_*` (0x201163A0, 0x20116560, table 0x20450074, 0x20115494) in
   `decomp/display/` and the DISPLAY binary's .data. Page `docs/code/main/display-link.md` with a sequenceDiagram.
3. Key events: from the RX dispatch, follow key/encoder/touch codes into radio actions (the 0xFFF89D94 pointer table is a
   candidate). Page `docs/code/main/ui-keys.md`.
4. Propose names in `tools/ghidra/names_main.T10b.tsv`; use my own Ghidra copy `FT710_MAIN_T10b` for xrefs/listings.
5. Update Findings/Follow-ups, proposed shared-file edits; commit.

## Findings
Pages: [sci.md](../code/main/sci.md), [display-link.md](../code/main/display-link.md), [ui-keys.md](../code/main/ui-keys.md).
169 names proposed in `tools/ghidra/names_main.T10b.tsv`; helper `tools/main_key_tables.py` dumps the key handler tables.

- **SCI layer** [fact]: Code Generator drivers, single-buffer receive with a per-channel *rx byte hook* that sets the frame length from the header.
  TEI/ERI are GROUPBL0 callbacks registered in `FUN_fff8f65e` (labels, not functions, in T05). SCI1 = 340.9 kbit/s 8N2 at PCLKB 60 MHz
  [inference on the clock]. SCI7 is created but never started (unused). `sci_baud_table` field order is {BGDM, ABCS, CKS, BRR}.
  SCI4 rx framing is the NXP ISP (blhost) packet format.
- **DISPLAY link** [fact]: binary frames `type payload sum8`, ACK 0x06 / NAK 0x15 stop-and-wait, 30-unit ACK window, 3 retries; MAIN→DISPLAY
  types 0x20..0x7F (24 frame types, priority scheduler `FUN_fff95f58`, sent only when changed), DISPLAY→MAIN 0xC3..0xC5, 0xE0..0xE8, 0xF0, 0xF1.
  Every length matches the DISPLAY's 43-entry table at 0x20450074 (read from the decompressed `.data`). DISPLAY `0xF0` hello powers the radio
  on (UI state 0x20B04+0x36 = 0x20B3A) and carries a power-on key code (1 = full reset, 7 = destination-code swap, 6 = link down, …).
  `F1 01`/`F1 02` start the SDR register bridge and a transparent DISPLAY↔SCI4 RT685 ISP tunnel (so DISPLAY updates the IF-DSP through MAIN);
  `F1 03` disables CAT. `0x7F` carries the power command (0x10 off, 0x11 restart, 0x90 low-voltage off).
- **Keys** [fact]: `E0` events (source/action nibble + 16-bit code) go through `key_event_filter` into a one-slot mailbox; `key_task`
  `FUN_fffbbd58` dispatches through five 863-entry handler tables (press/short/long/repeat/release, the T05 "large pointer table") by a key class.
  Codes 0x300..0x312 are the physical keys, six codes are user-assignable via settings 0x9AC8..0x9ACD; source 4 is touch-to-tune on the
  790-px scope. `E1` encoder ids 1/6 tune the main dial, 2/3 drive the knobs.

## Follow-ups
- Create functions at the 507 key-handler targets that are not function entries (list: `python3 -I tools/main_key_tables.py out.tsv`), then name
  each physical key 0x300..0x312 with the DISPLAY key-code table (T11f).
- T11b: confirm the DISPLAY SCIF5 baud (MAIN side is ≈340.9 kbit/s 8N2) and that the 0xAA/length header is internal to the DISPLAY TX mailbox.
- Payload layouts of the large MAIN→DISPLAY frames (0x20, 0x24, 0x30/0x31, 0x37, 0x39, 0x3A, 0x40, 0x41, 0x50, 0x62, 0x70) and of 0x43/0x44/0x45
  ↔ C3/C4/C5 (likely SD file operations): T10f/T10g with T11b.
- Meaning of E2, E7/E8 result codes, boot codes 2/4/5, mode flags 0x20BBE/0x20B8A/0x20B98/0x20B7C in `key_event_filter`.
- Verify the soft-timer unit (1 ms assumed) from the CMT tick ISR.
- Decompiler: `FUN_fff98bcd` and `FUN_fffa0c79` show the MOVU.B/W register-extend SLEIGH bug as low-address loads (`len-1`, `len+3`).

## Proposed shared-file edits
- `tools/ghidra/names_main.tsv`: fix the comment of `@sci_baud_table` (0xFFF80FF4) to `{SEMR.BGDM, SEMR.ABCS, SMR.CKS, BRR}` (byte 0 → SEMR bit 6,
  byte 1 → bit 4 in `sci0_set_baud`); merge `names_main.T10b.tsv`.
- `decomp/main/INDEX.md` UART table: SCI1 baud ≈340.9 kbit/s 8N2; SCI7 never started (unused); SCI4 = RT685 UART with NXP ISP framing; the
  "large code-pointer table at 0xFFF89D94" is five 863-entry key handler tables ending at 0xFFF8E100 (link ui-keys.md).
- `docs/code/main/README.md` (T10a): subsystem rows for sci.md, display-link.md, ui-keys.md; boot flow note that power-on is triggered by the
  DISPLAY `F0` frame (0x20B3A = UI state +0x36).
- `docs/hardware.md` SCI table: SCI7 unused in V01-12; SCI4 pins PB0/PB1; SCI6 pins P00/P01 (simple I2C).
