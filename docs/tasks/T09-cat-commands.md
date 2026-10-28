# T09 — CAT command recovery

**Status:** in progress · **Depends on:** T05

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

Method: read decomp first, drop to disassembly (`DumpListing.java`) where the decompiler drops arguments (string ops, stack multipliers). Every claim tagged [fact]/[inference]/[guess] with addresses. Nothing is sent to the radio.

## Findings
_(fill in as you go)_

## Follow-ups
