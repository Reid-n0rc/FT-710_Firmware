# T09b — CAT primary 104-command table, Ghidra names, re-export

**Status:** in progress · **Parent:** [T09](T09-cat-commands.md) · **Depends on:** T09a (conventions)

## Goal
For every primary command (`cat_mnemonics` @ 0xFFF805EC) record read/set lengths, parameter format and ranges, read-only vs set, inferred behaviour and risk; make the Ghidra project carry the names used in the docs.

## Deliverables
- Primary table in `docs/cat-commands.md`.
- `tools/ghidra/names_main.tsv` additions applied with `ApplyNames.java`, `decomp/main/` re-exported, `cat_dispatch.tsv` refreshed (separate commit).

## Plan
1. Fan the 104 handlers out to three read-only helper agents over disjoint address ranges (0xFFFA646D..0xFFFA9281, 0xFFFA9648..0xFFFADCD6, 0xFFFADD9A..0xFFFB006E), each returning one TSV row per mnemonic using the conventions found in T09a (reply buffer 0x1C8E, length 0x1B788, error flag 0x464A, `FUN_fffb2e9c` nibble→ASCII, `FUN_fffb2f07` ASCII→nibble). Cases use the switch length tests from `cat_dispatch.tsv`.
2. Merge, spot-check a sample of rows against decomp/disassembly, tag claims.
3. Add names for the CAT helpers to `names_main.tsv`, apply, re-export, refresh `cat_dispatch.tsv`; commit decomp separately from docs.

## Findings
_(fill in as you go)_

## Follow-ups
