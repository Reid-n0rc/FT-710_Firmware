# T10f — MAIN menu engine (EX) and hidden menu items

**Status:** done · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): menu.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10f.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
The EX menu table and engine: item descriptors (ranges, defaults, storage), diff against the manual's MENU chart (2306-C Table 2 / EX command, 296 items) to find hidden or undocumented items, and how menu values reach the DSP/SDR/DISPLAY.

## Plan
1. Start from `cat_EX` (0xFFFA9937) → `FUN_fffe61e7` and follow the chain to the menu item lookup and descriptor table.
2. Decode the descriptor layout (P1P2P3 key, min/max, default, RAM/EEPROM storage address, digit count, type) from the
   code that reads it plus raw bytes in `build/FT-710_MAIN_V0112.bin`.
3. Write `tools/main_menu_table.py` (stdlib, `python3 -I`) to dump the table to stdout/build.
4. Extract the 2306-C MENU chart (Table 2, EX command) with `pdftotext -layout`, parse it, and diff (missing, hidden,
   range/digit differences).
5. Trace the set path: what runs after a value changes (DSP/SDR/DISPLAY notifications).
6. Write `docs/code/main/menu.md` (tables, figures, tags), `names_main.T10f.tsv`, update this file, commit.

## Findings
Full write-up: [docs/code/main/menu.md](../code/main/menu.md). Tool: `tools/main_menu_table.py`. Names (57 engine + 314
item functions): `tools/ghidra/names_main.T10f.tsv`.
- The menu table is built at boot, not stored in ROM. `menu_build_all` 0xFFFD4C30 makes 314 BSRs to per-item functions,
  which register 0x38-byte descriptors into RAM 0x2105C (350 slots) through `menu_register` 0xFFFD442F. The descriptor
  layout (P1/P2/P3, name, draw/step/enter callbacks, min/max, store pointer, string/word/signed/digits/scale/accessor
  flags, destination mask) is decoded. **[fact]**
- EX key mapping is in `ex_parse_key` 0xFFFE6C27. CAT P1 05 (internal "EXTENSION SETTING": date/time, SD card, soft
  version, calibration, reset, certification; 18 items) is refused. The 296 EX-reachable items match the manual's 296
  rows one to one. **[fact]**
- Differences from the manual: SSB TX BPF SEL is 0..6 (5 = 50-4000Hz, refused by EX; 6 = "TTBF", accepted by EX on
  any destination, while the front panel allows it only for 3 destination codes with hidden flag 0x4760). FM TONE FREQ
  answers 3 digits. CW WEIGHT is 00..20 on the wire. There are manual typos in the RTTY MARK/SHIFT codes and 4 cosmetic
  name differences. **[fact]**
- Values: RAM 0x9A2A..0x9E85 = EEPROM 0x53DB.. (RAM = EEPROM + 0x464F), saved by FUN_fffb02cf. Defaults are a linear
  copy of ROM 0xFFF80E4A.., with destination-dependent MAX POWER, KEYBOARD LANGUAGE and TX TOT. **[fact]**
- Propagation: EX set = RAM write + `on_step` hook with 0x15DFC = 1 (a no-op for nearly every item) + state+0x40B
  flag. The DSP gets values from the polled sync chain FUN_fff9d1b9 (shadow compare → FUN_fffa0b4c). The DISPLAY gets a
  rendered menu page (FUN_fffc98f9 → frame type 0x40). **[fact]** for the paths read.

## Proposed shared-file edits
- `docs/cat-commands.md`, EX row: add "Key = decimal P1P2P3. P1 05 refused (internal EXTENSION SETTING group, 18
  front-panel-only items). P4 length must be exact (digits + sign). SSB TX BPF SEL (EX010113) also accepts 6 = TTBF
  (5 = 50-4000Hz refused). TONE FREQ answers 3 digits. CW WEIGHT P4 = 00..20. See docs/code/main/menu.md".
- `docs/code/main/README.md` (T10a): subsystem link "Setup menu / EX engine → menu.md".
- `docs/memory-maps.md` (MAIN RAM): 0x2105C menu item table (350 × 0x38); 0x1FA50 per-P1 index lists; 0x9A2A..0x9E85
  menu values (EEPROM 0x53DB.., 0x45C bytes); ROM 0xFFF80E4A.. menu defaults; ROM 0xFFF83514/0xFFF8358C menu titles.
- `names_main.tsv`: merge `names_main.T10f.tsv`. The per-item functions are named `menuitem_EX<key>` (EX-reachable) or
  `menuitem_int<P1>_<P2>_<P3>`.

## Follow-ups
- After the rename and re-export, switch the italic proposed names in menu.md to plain Ghidra names.
- Name the per-item `on_draw`/`on_step` callbacks (labels, not function entries in Ghidra), or let a FixFuncEntries pass
  create them. Non-trivial steppers worth a look: LCUT/HCUT, KEYBOARD LANGUAGE, CAT-n RATE, MAX POWER, preset items.
- What "TTBF" does in the DSP/TX path (T10d/T12), and which power-on option sets 0x4760 (`FUN_fff9546a` case 5, T10a/T10b).
- Confirm the CW WEIGHT display formula and the meaning of `menu_draw_flags` bit 7 against the DISPLAY side (T11).
