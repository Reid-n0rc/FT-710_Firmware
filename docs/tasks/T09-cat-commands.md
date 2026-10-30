# T09 — CAT command recovery

**Status:** done · **Depends on:** T05

## Goal
Recover the full CAT command table from MAIN and diff it against the CAT manual to find undocumented commands.

## Deliverables
- `docs/cat-commands.md`: a table of every command the firmware accepts, with documented yes/no, parameters, handler address, and the inferred behaviour.
- For undocumented commands: classify each as read-only or set, and note any risk.

## Notes / hints
- Source of documented commands: `Manuals/FT-710_CAT_OM_ENG_2306-C.pdf`. Extract the command list to a temp file and don't load the whole manual into context.
- Look for a table of 2-letter mnemonics (e.g. "FA","FB","MD"...) with function pointers.
- **Don't send any undocumented command to the radio** without the owner's explicit approval.

## Plan
Inputs: committed `decomp/main` (named handlers from T05), `cat_dispatch.tsv`, Ghidra project `ghidra/FT710_MAIN` (owned by T09 for the duration), REA CLI for xrefs/string searches.
The CAT manual is **not available** (yaesu.com blocks the container; `Manuals/` absent), so the "Documented" column is `pending (manual)` everywhere; the diff against the manual is a follow-up.

Split into two sub-tasks (each fits one context):
- **[T09a](T09a-cat-core-ext.md)** — CAT core and hidden commands: receive ring/port model, `cat_parse` → `cat_dispatch`/`cat_dispatch_ext`, reply buffer and length, error reply, auto-information (AI) path, reply templates at 0xFFF8F480, the second input path (E9), and every extended command (`SP` with its sub-commands, `EO E8 E9 FD KT PE ZZ VE JP`) plus any service/test/EEPROM/debug hooks reachable from CAT. Deliverables: `docs/code/main/cat.md` (flowchart, sequenceDiagram, function table, globals) and the extended/hidden section of `docs/cat-commands.md`.
- **[T09b](T09b-cat-primary.md)** — the 104 primary commands: per handler read/set lengths, parameter format and ranges, read-only vs set, inferred behaviour, risk. Handler reading is fanned out to helper agents over disjoint address ranges (they only read `decomp/main`); results are merged and spot-checked. Then Ghidra names for newly identified helpers (`names_main.tsv` + `ApplyNames.java`), re-export `decomp/main` with `ExportDecomp.java`, refresh `cat_dispatch.tsv` (separate decomp commit).

Method: read decomp first, drop to disassembly (`DumpListing.java`) where the decompiler drops arguments (string ops, stack multipliers). Every claim tagged [fact]/[inference] (or an open question; the former guess tag is retired) with addresses. Nothing is sent to the radio.

## Findings
Delivered: [cat-commands.md](../cat-commands.md) (all 114 mnemonics, documented column, manual diff, extended and service commands, risk), [cat-commands-primary.md](../cat-commands-primary.md) (per-command firmware details), [code/main/cat.md](../code/main/cat.md) (parser, reply, AI, ports, function table, globals). Sub-tasks [T09a](T09a-cat-core-ext.md) and [T09b](T09b-cat-primary.md) are done.

**Manual sources** (gitignored; arrived mid-task from the parent):
- `Manuals/FT-710_CAT_OM_ENG_2306-C.pdf` is the primary reference.
- `Manuals/FT-710_CAT_OM_ENG_2211-A.pdf` (dealer mirror, simarud.no) and the Japanese 2212-B are kept for history.
- **Caveat:** 2306-C drops `EO` (2211-A has it), changes `VE` read to `VEP1;`, and rewords the `AC` P3 list. The 2306-C parameter text was not re-extracted for every command. The per-command manual lines come from 2211-A, with those three differences applied. The parent diffed the two and reports layout-only differences elsewhere.

**Headline findings:**
- **22 mnemonics are not in 2306-C:** `BY E8 E9 ED EK EM EN EU EO FD FS JP KT PE QS RC RD RS RT RU SP ZZ`.
- **13 of them do nothing** (corrected from "12" by T19h: 9 switch-default + 3 stubs + `KT`). Real functions [fact]:
  - `SP*`: a service family covering SDR and SCI4 register access, an ADC dump, raw EEPROM bytes and the 0x4659 table.
  - `E8`/`E9`: settings image dump and restore.
  - `ZZPE0710xx`: factory reset.
  - `JP0710`: destination (region) code read/write.
  - `FD`: band-memory frequencies.
  - `PE`: 18 EQ-like parameters.
  - `EO`: encoder offset.
  - `EM`: text slots.
- **`XT` is documented but not implemented** in V01-12 [fact].

**REA:** not needed for this task. The named Ghidra project plus the committed decomp and `DumpListing.java` answered every question. REA's raw import has no names or RAM blocks, so its output would have needed re-mapping.

## Follow-ups
- The T09a/T09b follow-ups: SCI4 device, the `cfg105` table, the EX menu-table diff for hidden menu items, the RAM[len-2] checksum bug, the restart codes, and the E9 framing.
- Owner decision needed before any on-air test: which read-only undocumented forms may be tried. Safe candidates are `VE0;`..`VE3;`, `JP0710;` (read), `FD000;`/`FD001;`/`FD002;`, `PE000;` and `SPIR;`. `E8` is read-only but produces a 10 kB reply. **Never** send `SPSW/SPDW/SPW/SPAWE/E9/ZZ/JP-set`.
