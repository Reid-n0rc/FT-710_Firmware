# T09b — CAT primary 104-command table, Ghidra names, re-export

**Status:** done · **Parent:** [T09](T09-cat-commands.md) · **Depends on:** T09a (conventions)

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
- All 104 primary handlers are documented in [cat-commands-primary.md](../cat-commands-primary.md). Four parallel read-only passes over `decomp/main` did the reading, and the results were merged with the manual rev 2306-C.
- I spot-checked TX, PS, ID, EX and VE against the decompile and the disassembly.
- **Not implemented in V01-12** [fact]:
  - `XT` is documented in the manual but goes to the switch default.
  - `BY ED EK EU RC RD RS RT RU` also go to the switch default.
  - `EN FS QS` are stubs.
- **Hidden forms** [fact]: `VM0;` reads a state code and `VM000;` forces VFO mode. `MT` accepts set lengths 8..19. The manual draws `VD` as 4 digits, but the firmware uses 2.
- **Undocumented primary command:** `EM` holds five 50-character text slots in RAM.
- **TX keying:** `TX1`, `MX1`, `KY`, `PB`, `LM` and `AC` tune [fact/inference per row]. `TX1` bypasses the key-event filter.
- **EEPROM writes:** `AM BM MW MT CH KM`. `EX` reaches about 300 menu items.
- **Quirks** [fact, from the decompile]:
  - `AG` and `RG` store values mod 256.
  - `AI` accepts characters below '0'.
  - Uninitialized pointers or bytes appear in `CN OS PE MR PR` when a selector is invalid.
- **Ghidra:** 49 function names and 5 labels were added to `names_main.tsv`. `decomp/main` was re-exported (2252 functions, 0 failed) and `cat_dispatch.tsv` refreshed.

## Follow-ups
- Resolve the per-command `Open (needs disassembly)` items in cat-commands-primary.md. Most of them are `in_R14` artifacts in `FUN_fffb324c`/`FUN_fffb3196` (active vs other VFO) and dropped digit weights.
- Enumerate the firmware's EX menu table (`FUN_fffe61e7`/`FUN_fffd4ffe`) and diff it against the manual's 296 items, to look for hidden menu items (T10 menu page).
- Trace the consumers of 0x20B28 (TX1) and 0x20F4B/0x20B39 (PS0 / restart) in the TX and power state machines (T10).
