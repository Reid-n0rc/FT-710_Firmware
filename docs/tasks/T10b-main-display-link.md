# T10b — MAIN SCI drivers, DISPLAY link (SCI1) and front-panel key events

**Status:** in progress · **Depends on:** T05 · **Parent:** [T10](T10-docs-main.md)

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
_(fill in as you go)_

## Follow-ups
