# tools/

Every script in this directory and in `tools/ghidra/`: what it does, what it reads and writes, and the task that made it (the task
files in [docs/tasks/](../docs/tasks/README.md) have the full story). Install notes and versions are in [docs/tooling.md](../docs/tooling.md);
the newcomer walk-through is [docs/getting-started.md](../docs/getting-started.md).

Conventions:
- Python tools are standard library only (except `xc7_fasm.py fasm`, which re-runs itself in the prjxray venv). Run them from the repo
  root with `python3 -I tools/<script>.py`; `-I` keeps a planted module next to the firmware data from being imported.
- Inputs come from the gitignored `Firmware/` and `build/` folders. Outputs that are derived from Yaesu's firmware go to `build/` and are
  never committed; only `decomp/`, the docs and the hand-written `hdl/` are.
- Only `cat_backup.py` talks to a radio, and it only sends reads. `t16_patches.py` and `sfl_encode.py` write SFL files into `build/`
  only; flashing them needs the radio owner's explicit approval each time (AGENTS.md).

## Setup and orchestration

| Script | What it does | Inputs → outputs | Task |
|---|---|---|---|
| `bootstrap.sh` | One command from the official downloads to the full working tree: input hashes, SFL decode, RX module install + fix, the four Ghidra programs with every name, re-export, the HiFi4 FLIX listing, and diff against `decomp/`, optional SDR netlist/Verilator chain. Steps run alone with `--only`; see `--help` | `Firmware/`, `docs/inputs.sha256`, `tools/ghidra/*` → `$BOOTSTRAP_OUT/{build,ghidra,decomp,logs}` | T20 |
| `ghidra-headless.sh` | Runs Ghidra's `analyzeHeadless` with JDK 21 (Homebrew paths if present, else `~/opt`); override with `GHIDRA_JAVA_HOME`, `GHIDRA_HEADLESS` | Ghidra args | T01 |
| `ghidra-cap.sh` | Owner's hardware cap for Ghidra/REA (AGENTS.md "Hardware use"): at most 3 jobs machine-wide (flock slots), pinned to 3/4 of the cores, nice 10, admitted through `memgate.py` with a 3 GB margin; exports `CAP_CPUS` and GC threads sized to the cap. Used by `bootstrap.sh` | `<reserve_mb> -- <command...>` | T21 |
| `memgate.py` | Memory-based admission for parallel Ghidra/REA runs (AGENTS.md "Hardware use"): starts a command as soon as `MemAvailable` covers its reservation plus a 3 GB margin (`MEMGATE_SAFETY_MB`), counting what running jobs can still grow into. State in `$MEMGATE_DIR` (default `~/.cache/ft710-memgate`) | `<reserve_mb> -- <command...>` | T21 |
| `issues_sync.py` | Mirrors `docs/tasks/` to GitHub issues (epic, sub-issues, labels, status comments) and keeps `docs/tasks/issues.json`. **The parent agent / owner runs it, nobody else** | `docs/tasks/` → GitHub | (board setup) |
| `cat_backup.py` | Read-only CAT backup: `ID`, `VE0..3`, `JP0710` and the `E8` memory image (tested on a radio), optional full EEPROM dump with `SPR` (`--eeprom`, about 2 minutes; tested on a radio). Logs to `backup.log`. Checks the `JP` complement bytes, the `E8` and `SPR` checksums and the region code in the dump; writes `SHA256SUMS`. `--verify` checks a backup folder against it, `--decode` checks a saved `E8` frame. See [docs/cat-undocumented.md](../docs/cat-undocumented.md) | radio (CAT port) → `backup-<date>/` | radio checks |
| `guide_to_wiki.py` | Splits `docs/guide/README.md` into GitHub-wiki pages (`Home`, one page per chapter, `_Sidebar`, `img/`) | guide → `build/wiki/` | T19 |

## Firmware container (SFL)

| Script | What it does | Inputs → outputs | Task |
|---|---|---|---|
| `sfl_header.py` | Parses and checks the SFL header (comment box, tag line, length, CRC) | `Firmware/*.SFL` → stdout | T03 |
| `sfl_decode.py` | Decodes an SFL (43-byte subtraction key, salted CRC-32 check) and converts the payload: MAIN S-records → flat binary (+ `.FE7F5D00.bin` option-setting cluster), SDR hex → bitstream; `--raw` keeps the plaintext | `Firmware/X.SFL` → `build/X.bin` | T04 |
| `sfl_encode.py` | Inverse of `sfl_decode.py`; `--check` validates SFLs | image → `.SFL` | T16 |
| `test_sfl_roundtrip.py` | SFL → decode → encode → identical SFL for all four shipped images | `Firmware/` → `build/t16/roundtrip/` | T16 |
| `t16_patches.py` | Builds and verifies the T16 DISPLAY patch SFLs ([docs/patches/](../docs/patches/README.md)); never flashed | `Firmware/` → `build/t16/` | T16 |

## MAIN (Renesas RX651)

| Script | What it does | Inputs → outputs | Task |
|---|---|---|---|
| `main_key_tables.py` | Dumps the front-panel key handler tables | `build/FT-710_MAIN_V0112.bin`, `decomp/main/functions.tsv` → stdout / TSV | T10b |
| `main_menu_table.py` | Dumps the EX/setup-menu item table and diffs it against the CAT manual's menu chart | MAIN image → stdout | T10f |

## DISPLAY (Renesas RZ/A1H)

| Script | What it does | Inputs → outputs | Task |
|---|---|---|---|
| `display_assets.py` | Lists the GUI sprites, fonts, tables and strings (lists only; `--render` is an ASCII preview) | DISPLAY image → stdout | T11e |
| `t11g_pinmux_decode.py` | Decodes `pinmux_init` 0x20101190 into a port/pin → mode table (needs `arm-none-eabi-objdump`) | DISPLAY image → TSV on stdout | T11g |
| `arm_recover.py` | Independent code recovery for DISPLAY, stdlib only (no Ghidra/rizin/T21e input): own A32 + Thumb-2 control-flow decoder (ARM ARM DDI 0406C), recursive descent from the vectors, BL/BLX targets, code pointers in .rodata/.data and push prologues; the four jump-table idioms (A32 `ldr pc,[pc,rX,lsl #2]`, `add pc,pc,rX,lsl #2`, Thumb `tbb/tbh`, `add pc` after `adr`) with the bound read from the `cmp` and the condition (`--bound SITE=N` for guards it cannot read, e.g. `20164f68=4`); byte classes for everything else. `--objdump` cross-checks every recovered instruction | DISPLAY image → `OUTDIR/{jumptables,starts,coverage,xrefs,conflicts}.tsv`, `summary.txt` | T22b |
| `arm_recover_compare.py` | Lines up `arm_recover.py`, rizin (`aflj`, `afbj` with `switch_op`) and Ghidra (`functions.tsv`, `DisplayJumpTables.java check`, `CodeUnitMap.java`) results: per-site case counts, function-start membership per analyser pair, own-vs-Ghidra differences by class, bytes no analyser covers | outputs above → `jt_compare.tsv`, `starts_compare.tsv`, `starts_diff.tsv`, `gaps_compare.tsv`, `compare.txt` | T22b |

## IFDSP (NXP i.MX RT685: Cortex-M33 + HiFi4)

| Script | What it does | Inputs → outputs | Task |
|---|---|---|---|
| `ifdsp_dsp_images.py` | Carves the three HiFi4 images out of the decoded IFDSP image (and the contiguous `_hifi4.bin` Ghidra imports) | `build/FT-710_IFDSP_V0101.bin` → `build/FT-710_IFDSP_V0101_hifi4*.bin` | T07 |
| `ifdsp_xtdis.py` | Minimal Xtensa base-ISA linear disassembler | HiFi4 SRAM image → stdout | T12c |
| `ifdsp_l32r.py` | Heuristic per-function L32R literal scan | SRAM image + `functions.tsv` → stdout | T12a |
| `ifdsp_regscan.py` | Heuristic HiFi4 accesses to the shared register file (base ISA only) | SRAM image + `functions.tsv` → stdout | T12a |
| `ifdsp_hifi4_dis.py` | Per-function FLIX-aware HiFi4 listing with the Zephyr SDK RT600 objdump, names from `IfdspHifi4Names.java` | objdump + SRAM image + `functions.tsv` → `decomp/ifdsp/hifi4/flix.dis` (committed; bootstrap step `flix`) | T12e |
| `flix_compare.py` | FLIX test oracle: compares a Ghidra instruction export with `flix.dis` (length, mnemonic, operands per slot; normalisation rules N1–N8 in the docstring), compares function lists (`funcs`), writes the address list (`addrs`) and `entries_hifi4.tsv` (`entries`) | `ExportListing.java` TSV + `flix.dis` → `summary.txt`, `mismatches.tsv`, `by_mnemonic.tsv` | T21b (#97) |
| `flix_oracle.sh` | End-to-end oracle for one Xtensa language id: scratch import with the HiFi4 setup and function pass, listing + decode export, B9 decompile of `FUN_0020bb74`, all comparisons; env `IMAGE`, `PROJDIR`, `HEADLESS`, `TIMEOUT` | language id → `build/oracle/<lang>/` | T21b (#97) |
| `flix_stats.py` | Counts what Ghidra cannot represent in the HiFi4 code: functions with FLIX bundles, bundle sizes and slots, branch slots, unknown and wrong-register ops | `decomp/ifdsp/hifi4/flix.dis` (+ Ghidra's Xtensa `.sinc` files) → stdout | #97 |
| `xtensa_sleigh_gen.py` | Generates the Ghidra language `Xtensa:LE:32:rt600hifi4` from Cadence's `xtensa-modules.c` (`extract`, `check`, `selftest` = its own model vs `flix.dis`, `generate`); compiles the probe `xtensa_isa_dump.c` with `cc` | `xtensa-modules.c` + Ghidra stock Xtensa `.sinc` → `tools/ghidra/xtensa-rt600hifi4/` (committed; bootstrap step `hifi4`) | T21a (#97) |
| `xtensa_isa_dump.c` | C probe for `xtensa_sleigh_gen.py`: includes `xtensa-modules.c` and dumps slot/field bit maps, opcode encodings, operand decode tables and reloc samples as JSON | built and run by the generator | T21a (#97) |
| `ifdsp_hifi4_regscan.py` | Register-file accesses in a FLIX-aware objdump listing | listing + `functions.tsv` → stdout | T12b |
| `ifdsp_coef_tables.py` | Finds and classifies numeric tables (filters, windows, sin/cos, gain curves) | SRAM image → stdout | T12e |
| `ifdsp_names_java.py` | Converts the IFDSP name scripts (`IfdspM33Names.java`, `IfdspHifi4Names.java`) to/from TSV, splits proposals by program | Java ↔ TSV | T17 |

## SDR (Xilinx Artix-7 XC7A50T bitstream)

The `xc7_*` tools need the Project X-Ray checkouts (`~/.local/share/ft710-tools/`, set up by `bootstrap.sh --only sdr`). Most have a
`selftest` command.

| Script | What it does | Inputs → outputs | Task |
|---|---|---|---|
| `xbit_parse.py` | Config packet log, register decode, CRC check, leading-word CRC (`--lead`), FDRI and BRAM frame statistics | `build/FT-710_SDR_V0104.bin` → stdout | T08 |
| `xc7_db.py` | Maps the bitstream onto prjxray tiles: `frames` (prints `MATCH`), `bram`, `bramcfg`, `usage`, `sites`, `config`, `tilebits` | SDR image + prjxray-db → stdout | T13 |
| `xc7_bram_tables.py` | Rebuilds and characterises the logical BRAM tables (`tables`, `show`, `lanes`, `halfsym`, `selftest`) | SDR image → stdout | T13 |
| `xc7_package_fit.py` | Which XC7A50T packages bond every used IOB | FASM → stdout | T16 |
| `xc7_fasm.py` | Bitstream → prjxray `.bits` → FASM (prjxray's `FasmDisassembler`, in the venv), `summary` per tile type | SDR image → `build/sdr/FT-710_SDR_V0104.fasm` | T15a |
| `xc7_netlist.py` | FASM → cell-level netlist (LUT, FF, CARRY4, DSP48E1, BRAM, IOB, MMCM, BUFG) with nets from active PIPs; `stats`, `net` | FASM → `build/sdr/netlist.json` | T15b |
| `xc7_blocks.py` | Block recognition: `clocks`, `io`, `package`, `dsp`, `bram`, `logic` (LUT equations around a cell) | netlist → stdout | T15c |
| `xc7_netlist_verilog.py` | Structural Verilog + XDC (`verilog`), Yosys/sim primitive models (`prims`, `simprims`), sub-netlists (`slice`) | netlist → `build/sdr/ft710_sdr.{v,xdc}` | T15d |
| `xc7_probe_netlist.py` | Adds a `probe` output port to the netlist to watch internal nets in Verilator | netlist + `.v` → probed `.v` | T15e |
| `sdr_uart_sim.py` | Drives the Verilator model with MAIN-style UART frames (`b:r0000`) or console text (`a:=...`); `--bin` picks the model | `build/sdr/vl/obj_full/Vft710_sdr` → replies | T15e |
| `sdr_cosim_check.py` | Compares netlist and RTL TX edges in the co-simulation | co-sim output → stdout | T15e |

The Verilator harness and build scripts are in [`hdl/sdr/sim/`](../hdl/sdr/README.md) (`build_full.sh`, `cosim_directed.sh`,
`cosim_random.sh`).

## Integration helpers (T17)

| Script | What it does | Inputs → outputs | Task |
|---|---|---|---|
| `signatures_draft.py` | drafts `signatures_main.tsv` from `CallArgCheck.java`'s `protos.tsv` (keeps the reviewed `doc` rows; rules in its docstring) | `protos.tsv`, `names_main.tsv`, [`mismatch.tsv`] → `tools/ghidra/signatures_main.tsv` | T21d |
| `names_merge.py` | `report`/`merge` per-sub-task name and entry TSVs into the shared ones, conflicts resolved with `--picks` | `tools/ghidra/names_*.T*.tsv` → `names_*.tsv` | T17 |
| `pages_final_names.py` | Switches code pages from proposed (italic) names to the applied Ghidra names | config JSON + pages | T17 |
| `index_refresh.py` | Refreshes the export-file column of a `decomp/*/INDEX.md` after a re-export | `INDEX.md` + `functions.tsv` | T17 |
| `decomp_quality.py` | Decompile-quality regression check (#97 B11): `compare old new` exits 1 if any count in `quality.tsv` went up (run by `bootstrap.sh verify`); `index INDEX.md LABEL=quality.tsv ...` renders the counts as a table between `<!-- quality:begin/end -->` | `decomp/*/quality.tsv` → exit code / `INDEX.md` | T21f |
| `decomp_behavior_diff.py` | Function-level before/after diff of two `decomp/<image>` exports (#104 T22e): splits the `.c` chunks at the `// =====` markers, keys by entry address, maps names to addresses, classifies each changed function (renamed/moved, bundles, insn, jumptable, stack, boundary, signature, callee_new, data, other) and flags lost calls, dropped results, fewer arguments and lost string literals; `--marked` (functions with a fixed instruction), `--locked` (`signatures_main.tsv`) | two export dirs (e.g. from `git archive`) → class TSV + summary | T22e |
| `hifi4_rizin_compare.py` | Re-decodes every non-FLIX HiFi4 instruction of `flix.dis` with rizin's Capstone Xtensa decoder, driven from `flix.dis`'s own addresses, and classifies each (agree / rizin illegal / mnemonic / operands / standard-FPU layout) | rizin + `build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin` + `decomp/ifdsp/hifi4/flix.dis` → stdout summary, per-instruction TSV | T22c |
| `hifi4_isa_decode.c` | Stand-alone HiFi4 decoder: compiled with Cadence's `xtensa-modules.c`, it uses only that file's tables and generated functions (format decode, slot get, opcode decode, fields, operand decode/undo_reloc, iclass in/out); own driver, no libisa, nothing shared with `xtensa_sleigh_gen.py`. Prints length, format, flow flags, PC-relative targets, objdump-like text and the slot/field breakdown | image + base, addresses on stdin (or every byte) → TSV | T22c |
| `hifi4_hand_decode.py` | Drives `hifi4_isa_decode.c`: `flix` (vs `flix.dis`), `ghidra` (vs an `ExportListing.java` TSV), `sample N` (bundles of different format/slot mixes, field by field), `parallel N` (bundles where one slot writes what another reads), `regions` (settles `flix_compare.py`'s listing conflict regions with an own recursive-descent flow decode plus objdump at Ghidra's starts) | `build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin`, `flix.dis`, oracle TSVs → stdout, TSVs | T22c |
| `undefined_classify.py` | Classifies the undefined non-0xFF bytes of an image's executable blocks from the raw bytes only (Ghidra gives just the range list): padding, ASCII/UTF-16/Shift-JIS strings, pointers, float32/int/struct tables, code (decoded with `rx-elf-objdump`, `arm-none-eabi-objdump` A32/T32 or the Zephyr RT600 Xtensa objdump; HiFi4 also `flix.dis`), unknown (with entropy); inbound branches and image words as evidence. `summary` prints bytes per class, `compare` matches the classes against another classification | `main`/`display`/`m33`/`hifi4` + `UndefinedRanges.java` TSV (+ `--flix`) → per-sub-run TSV (`docs/tasks/T22d-undefined-classes.tsv` is the committed non-padding part) | T22d |
| `rx_compare.py` | Diffs Ghidra's MAIN (RX) listing against GNU binutils `rx-elf-objdump` per instruction (length, mnemonic, operands; normalisation rules N1-N11 in the docstring); exit 1 on any difference | `ListingExport.java` TSV + `build/FT-710_MAIN_V0112.bin` (+ `~/opt/rx-binutils-2.47`) → stdout, `--diffs` TSV | T21c |

## tools/ghidra/ (Ghidra scripts and their data)

Run through `tools/ghidra-headless.sh ... -scriptPath tools/ghidra -preScript|-postScript <Script>.java [args]`. `bootstrap.sh` has
the exact command line for every program.

| Script / file | Kind | What it does | Used by | Task |
|---|---|---|---|---|
| `SetupRX651.java` | preScript | RX651 memory map (RAM, I/O, option-setting), `.data` copy-downs (`copy=SRC:END:DST`), fixed and relocatable vectors → named functions | MAIN | T05 |
| `ApplyNames.java` | postScript | Applies `address<TAB>name[<TAB>comment]`; `@name` = data label; creates missing functions | MAIN, DISPLAY | T05 |
| `names_main.tsv` | data | 1147 MAIN names (T05, T09, T10a–h merged in T17) | ApplyNames | T05/T17 |
| `names_display.tsv` | data | 768 DISPLAY names (T06, T11a–g merged in T17) | ApplyNames | T06/T17 |
| `entries_display.tsv` | data | 205 DISPLAY function entries analysis missed or started late (`drop` = old entry was data, `thumb` = Thumb entry): 68 from T11/T17, 137 from T21e (`DisplayGaps.java` kinds) | FixFuncEntries | T11/T17/T21e |
| `DefineRomData.java` | postScript | MAIN ROM bytes analysis left undefined: strings, pointer runs, zero runs; unreferenced code after a return → functions; leftover const-area runs → `float`/`uint16`/`byte` arrays (plate comment: layout guess). The code area is data-scanned only after the code pass; a called run also becomes a function (T21h). `[report.tsv] [code=0xFFF8F658] [dry]`; run after ApplyNames | MAIN | T21d, T21h |
| `ApplySignatures.java` | postScript | Applies `signatures_main.tsv` as locked (USER_DEFINED) prototypes, cspec `__fastcall`, stack purge 0; `type name@stack:N` and 64-bit returns get custom storage; run last | MAIN | T21d |
| `signatures_main.tsv` | data | 1212 MAIN prototypes: 33 reviewed (`doc`), the rest drafted from the disassembly (`asm`, `tools/signatures_draft.py`) | ApplySignatures | T21d |
| `CallArgCheck.java` | postScript | Read-only: every call site's R1–R4 set-up and R1/R2 use in the disassembly vs the decompiled CALL → `mismatch.tsv` (dropped_arg / lost_ret / wide_ret + counts); optional `protos.tsv` (per-function asm prototype evidence for `signatures_draft.py`) | MAIN | T21d |
| `names_*.T*.tsv`, `entries_display.T*.tsv` | data | the per-sub-task proposals, kept as the merge inputs | names_merge.py | T10/T11/T12 |
| `names_{main,display,ifdsp}.picks.tsv` | data | T17 resolutions of name conflicts | names_merge.py | T17 |
| `CatDispatch.java` | postScript | Dumps the CAT mnemonic → switch case → handler table with each length test (`len==N`, `len>N`, ...) | `decomp/main/cat_dispatch.tsv` | T05, fixed T20 |
| `UndefinedRanges.java` | postScript | Writes the undefined byte ranges of every initialized executable block (the set `ExportDecomp.java` counts as `undefined_nonff_bytes`) as TSV: block, start, end, length, non-0xFF bytes, references in, containing function, the code units before/after; works on `-readOnly` copies | `undefined_classify.py` | T22d |
| `ExportDecomp.java` | postScript | Decompiled C in 50-function files + `functions.tsv` (60 s per-function limit) + `quality.tsv` (decompile-quality counts from the same pass, T21f) | all | T01/T05 |
| `DisplaySetup.java` | preScript | DISPLAY RZ/A1H map: `.text`/`.rodata`/scatter area split, armcc LZ decompression of RW data, ZI blocks, I/O, vectors | DISPLAY | T06 |
| `DisplayFindCode.java` | postScript | Second code-discovery pass: pointer tables, `push {..,lr}` prologues, orphan code (run twice; the 2nd finds nothing new) | DISPLAY | T06 |
| `FixFuncEntries.java` | postScript | Creates or moves function entries from `entries_display.tsv` (run before ApplyNames); the late-start walk stops at a call and keeps called functions (T21e) | DISPLAY | T11 |
| `DisplayJumpTables.java` | postScript | ARM jump tables (`ldr pc,[pc,rX,lsl #2]`, `add pc,pc,rX,lsl #2`): `scan` lists every site with its length from the `cmp rX,#n`; `apply` repairs the sites the decompiler does not turn into a full switch (stray references, RETURN flow override, table data, case code; switch override as last resort); `check` = the test (every site a switch with all cases) | DISPLAY (any ARM image) | T21e |
| `DisplayGaps.java` | postScript | Missed function starts (call targets that are no entry, code after a return that nothing reaches, address-taken code, tail-branch targets merged into another function) and undefined fragments in `.text`; `define` defines the non-code fragments as data and disassembles dead code. Prints the B7 test (no call target inside a body) | DISPLAY (any ARM image) | T21e |
| `DisplayReport.java` | postScript | Read-only report: blocks, strings, I/O references as TSVs | DISPLAY | T06 |
| `IfdspM33Setup.java` | preScript | RT685 map for the M33 image, MCUXpresso copy-down block, `.bss`, vectors → Thumb functions | IFDSP M33 | T07 |
| `IfdspFindFuncs.java` | postScript | Missed Thumb `push {…,lr}` prologues in the M33 code ranges; rodata strings | IFDSP M33 | T07 |
| `IfdspM33Names.java` | postScript | M33 names + plate comments, creates/removes entries (`MERGE_INTO`) | IFDSP M33 | T07/T12/T17 |
| `IfdspHifi4Setup.java` | preScript | Maps the three carved HiFi4 images at their DSP load addresses, seeds the vectors | IFDSP HiFi4 | T07 |
| `IfdspHifi4FindFuncs.java` | postScript | Makes the SRAM function list exactly `entries_hifi4.tsv` (creates missing entries, clears instructions overlapping them, removes every other function outside the ITCM vectors) | IFDSP HiFi4 | T07, T21b |
| `entries_hifi4.tsv` | data | 1,067 HiFi4 function entries: the 1,065 `flix.dis` functions + 2 real entries without `entry` (`source` = `extra`); regenerate with `flix_compare.py entries` | IfdspHifi4FindFuncs | T21b |
| `ExportListing.java` | postScript | Every instruction as TSV (addr, len, mnemonic, operands, bytes): `listing` = analysed listing, `decode <addrs>` = flow-independent decode at each address | FLIX oracle | T21b |
| `ExportFuncList.java` | postScript | Function entries, names, sizes, blocks as TSV | any | T21b |
| `DecompileBisect.java` | postScript | Finds the instruction that kills a function's decompile: patches `retw.n` from the end backwards, then confirms the candidate alone with a `nop` (read-only session) | any | T21b |
| `IfdspHifi4Names.java` | postScript | HiFi4 names + plate comments | IFDSP HiFi4 | T12e/T17 |
| `DumpFuncs.java` | postScript | Decompiles a few functions (by address or name) into one text file | any | T07 |
| `DumpListing.java` | postScript | Disassembly (optionally the decompile) for addresses or functions | any | T05 |
| `ListingExport.java` | postScript | Every instruction as TSV (addr, len, bytes, mnemonic, operands, function) plus undefined holes in function bodies; prints Error bookmarks (input of `rx_compare.py`) | any | T21c |
| `PcodeDump.java` | postScript | Raw p-code of the instruction at each given address (bundle-parallel semantics check) | any | T22c |
| `CodeUnitMap.java` | postScript | Read-only: code (A32/T32 by `TMode`) / data / undefined runs of an address range with the containing function, as TSV (`arm_recover_compare.py --ghidra-map`) | DISPLAY | T22b |
| `PeriphRefs.java` | postScript | Functions touching given peripheral register ranges | any | T05 |
| `ProgramStats.java` | postScript | Function/instruction/data coverage and the largest undefined ROM gaps | any | T05 |
| `XrefsList.java`, `T10eXrefs.java`, `XrefsT10d.java` | postScript | References to addresses/ranges with the containing function (one would do; the others are kept for the task logs) | MAIN | T10 |
| `T10eMovuRegCount.java` | postScript | Lists every `MOVU.B/W Rs,Rd`; after the T17 fix all 107 print as register forms | MAIN | T10e/T17 |
| `rx62t-movu-fix.patch` | patch | T17 SLEIGH fix for the RX module (`MOVU` ld=11, `SCMPU`, `SUNTIL`, `SWHILE`); applied by `bootstrap.sh --only rx` | RX module | T17 |
| `rx62t-rxv2-fix.patch` | patch | T21c SLEIGH fix on top of the T17 patch: `MUL` memory forms (.UB scaling, memex), `XCHG` memory forms (were unimplemented), `SCCnd` (always written; .L Rd went to memory), string ops as named pcodeops (`scmpu`, `smovf`, `smovb`, `smovu`, `sstr`, `suntil`, `swhile`); applied by `bootstrap.sh --only rx` | RX module | T21c |
| `rx62t-rtsd-fix.patch` | patch | T21d SLEIGH fix: `RTSD #imm,Rd-Rd2` frame size from the register numbers (was the register values; the 8 "Unable to track spacebase" warnings). One line, applies after the T21c patch; applied by `bootstrap.sh --only rx` (T21g) | RX module | T21d |
| `rx62t-mvfac-fix.patch` | patch | T21h SLEIGH fix: RXv2 `MVFACHI`/`MVFACMI`/`MVFACLO #imm,A0,Rd` (no constructor existed; MAIN 0xFFF9129B, 0xFFF912AE). Applies after the RTSD patch; fourth stage of `bootstrap.sh --only rx` | RX module | T21h |
| `rx62t-semantics-fix.patch` | patch | T22a SLEIGH semantics fix (21 hunks, each backed by an `rx_semcheck.py` failure and a manual page): `ld_src` ld=11 = full Rs (SUB/CMP/AND/OR/DIV/DIVU/ITOF Rs,Rd), DIV/DIVU O flag, ITOF Z/S, `JSR Rs` as `call`, SHLL O, BSET/BCLR/BNOT Rs,[Rd] byte access, ROLC/RORC, ADC/SBB, SHAR flags. Applies on `618938bb` (and on T21h's module, offsets only). **Not** in `bootstrap.sh` yet (folded in after T21h) | RX module | T22a |
