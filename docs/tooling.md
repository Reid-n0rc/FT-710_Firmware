# Tooling

Set up in task T01 (2026-10-09) on macOS (Apple Silicon, arm64), Homebrew 7.0.9.

## Installed

| Component | Version | Install method | Location |
|---|---|---|---|
| Ghidra | 12.1.4 (PUBLIC, build 2026-09-21) | Homebrew **formula** `ghidra` (`brew install ghidra`) | `/opt/homebrew/opt/ghidra` → `/opt/homebrew/Cellar/ghidra/12.1.4` |
| JDK 21 | OpenJDK 21.0.12.1 (Homebrew build) | Homebrew formula `openjdk@21` (installed automatically as a dependency of `ghidra`; keg-only) | `/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home` |

Notes:
- There is no `ghidra` Homebrew cask any more; Ghidra comes from the homebrew-core formula. The formula ships 12.x, not 11.x. Ghidra 12.1.4 requires Java 21 or newer (`application.java.min=21`), so the AGENTS.md "needs JDK 21" note still applies.
- The `temurin@21` cask was **not** installed. It is a `.pkg` installer that needs sudo, and the keg-only `openjdk@21` formula does the same job without it.
- The system default Java is still Amazon Corretto 11 (`/usr/libexec/java_home` → `amazon-corretto-11.jdk`). The keg-only `openjdk@21` is not registered with `java_home` and does not change the global default. No global `JAVA_HOME`, shell profile, or Ghidra `launch.properties` was changed.

## Running analyzeHeadless

Path: `/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless`

Homebrew links only `ghidraRun` and `pyghidraRun` into `/opt/homebrew/bin`. `analyzeHeadless` is **not** on `PATH`. Unlike the `ghidraRun` wrapper, it does not set `JAVA_HOME` itself, so always pass JDK 21 explicitly on the command line:

```sh
JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home \
  /opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless <project_dir> <project_name> [options]
```

If you leave `JAVA_HOME` unset, Ghidra's launcher may find Corretto 11, reject it, and prompt interactively for a JDK path. That hangs a headless run.

### Sample: import and auto-analyze a binary

Run this from the repo root. Projects go under `ghidra/`; only the three canonical projects are committed.

```sh
JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home \
  /opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless \
  "$PWD/ghidra" FT710_MAIN \
  -import build/main.bin \
  -processor ARM:LE:32:Cortex -loader BinaryLoader -loader-baseAddr 0x08000000
```

The processor, loader, and base address above are placeholders. Use the real values from `docs/memory-maps.md` once T02+ establish them. Other useful options:
- `-process <file>` re-runs on a program that is already imported. Add `-noanalysis` to skip auto-analysis.
- `-postScript <script> [args]` and `-scriptPath tools/ghidra` run a script after analysis, e.g. to export decompiled C.
- `-deleteProject` deletes the project after the run, which is good for throwaway tests.
- `-overwrite` replaces an existing program of the same name.

Full reference: `/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadlessREADME.md`.

### Smoke test (T01)

```sh
JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home \
  /opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless \
  "$PWD/ghidra" t01_smoke -import /bin/ls -deleteProject
```

Result: `REPORT: Analysis succeeded`, `Save succeeded`, `Import succeeded`. Auto-analysis took about 2 s, and the project was deleted afterwards.

## Renesas RX processor module (T05)

Ghidra 12.1.4 ships no Renesas RX language. T05 installed a **community SLEIGH module as data only**. The module's Java loader and analyzer stubs are not needed and were not installed.

| Item | Value |
|---|---|
| Source | https://github.com/stefan00lpf/rx-proc-ghidra (a fork of https://github.com/redballoonsecurity/rx-proc-ghidra, the original by James Chambers, 2019) |
| Commit | `ea4cd20403c2e359f0de0cead2850d6be173b67a` (2026-04-29: "Fix STZ register encoding and tighten ADD/MUL operand semantics"). It is adapted to Ghidra 12.0.x and has MOVU/MUL/ADD/STNZ/STZ fixes over upstream. |
| Why this one | Searched GitHub (`gh search repos`): the upstream (39★, last push 2021, a 2019 SLEIGH), 15 forks, and `CharanVelavan/rxv2-ghidra` (whose "rx65n" spec is a byte-identical copy of the RX62T sinc). The stefan00lpf fork is the most recently maintained and the only one with semantic fixes. The spec covers the RXv1 set plus the RXv2 FPU/atomic ops used here (FSQRT, FTOU, UTOF, MOVCO/MOVLI). It lacks the RXv2 DSP accumulator ops (EMACA, EMSBA, MACLH, MVFACGU, RACL, RDACL), and the MAIN export has no bad-instruction or bad-data markers. |
| Inspection | Before installing I read `data/languages/*` (ldefs, pspec, cspec, slaspec, sinc) and diffed the sinc against upstream (5 small hunks, all SLEIGH semantics). No executable content was installed. |
| Install method | Per-user extension, **the Homebrew install is untouched**: `~/Library/ghidra/ghidra_12.1.4_PUBLIC/Extensions/RX/` containing `Module.manifest` (empty), `extension.properties` (`name=RX`, `version=12.1.4`, the source and commit noted in the description) and `data/languages/rx62t.{slaspec,sinc,ldefs,pspec,cspec,opinion}`. |
| Compile | `JAVA_HOME=…openjdk@21… /opt/homebrew/opt/ghidra/libexec/support/sleigh ~/Library/ghidra/ghidra_12.1.4_PUBLIC/Extensions/RX/data/languages/rx62t.slaspec` produces `rx62t.sla` (8 NOP-constructor warnings only). |
| Language ID | `rx62t:LE:32:default` (description "RX62T/RXv2 Language Module"). Calling convention in the cspec: args R1–R4, return R1, callee-saved R6–R13, which matches CC-RX. |
| Verified | The reset handler 0xFFF8FBDB disassembles as `MVTC #0x1004,USP; MVTC #0x1404,ISP; MOV.L #0xfff8e6dc,R14; MVTC R14,INTB; … MVTC R14,FPSW; BSR.A …` × 7; `MVTC #0x30000,PSW`; `BSR.A main`; `NOP; BRA`. Full auto-analysis found 2254 functions. The CC-RX switch idiom `MOV.W [Ri,Rt],R14; BRA.L R14` is recovered as a jump table, and the export of 2252 functions had 0 decompile failures. |
| Remove | `rm -rf ~/Library/ghidra/ghidra_12.1.4_PUBLIC/Extensions/RX` |
| Re-install | `git clone https://github.com/stefan00lpf/rx-proc-ghidra && git -C rx-proc-ghidra checkout ea4cd20403c2e359f0de0cead2850d6be173b67a`, then copy the six `data/languages/rx62t.*` files and create the two small files as above. |

Known module limitations: the string instructions (SCMPU, SMOVF, SSTR, SUNTIL, SWHILE) are modelled as p-code loops, so the decompiler renders them as loops instead of `strncmp`/`memcpy`/`memset`/`memchr`; the PSW flag bits are modelled as bit-ranges of PSW. Read those spots in the disassembly.

### Local SLEIGH fix (T17, 2026-10-27): `tools/ghidra/rx62t-movu-fix.patch`

Checked against the RXv2 software manual `Manuals/Renesas/REN_r01us0071ej0100_rxv2sm_MAS_20131112_1.pdf` (R01US0071EJ0100):

| Instruction | Defect in `ea4cd204` | Manual | Fix |
|---|---|---|---|
| `MOVU.B/W Rs,Rd` (bytes `5B`/`5F` + `rs rd`, format (2), ld = 11) | decoded as the memory load `MOVU.x [Rs],Rd` (the module's comment even says "when ld=3 it should be [Rs]"). Found by T10e: 107 sites in 49 MAIN functions, including the CAT `SP` checksum length | p. 124 (function table: register → register zero-extend), p. 259 (format (2): ld 11b = Rs, 00b = [Rs], 01b = dsp:8, 10b = dsp:16) | `movu_ldu_src` with `mode_ld = 3` exports `zext(Rs:1)` / `zext(Rs:2)` |
| `SCMPU` | set Z = 0 when both strings ended in NUL together (a match), C used a signed byte difference, and R3 = 0 cleared Z/C | p. 184: Z = strings matched, C = unsigned `*R1 − *R2 ≥ 0`, R3 = 0 has no effect | flags from the last compared pair, loop skipped when R3 = 0 |
| `SUNTIL.B/W/L` | never set Z/C (code that branches on Z after it was mis-decoded) | p. 196: flags from `*R1 − R2`, Z = match found | Z/C from the last compare |
| `SWHILE.B/W/L` | compared the pointer `R1` (not `*R1`) with R2, and stepped R1 by 1 for .W/.L | p. 198 | compare `*R1`, step by the size, Z/C from the last compare |
| `SMOVF`, `SMOVB`, `SSTR` | none (correct p-code, rendered as loops) | pp. 190, 192 | unchanged |

Apply / rebuild (the REA MCP server and the REA CLI use the same installed module, so they get the fix too):
```sh
cd ~/opt/ghidra_12.1.4_PUBLIC/Ghidra/Processors/RX
cp data/languages/rx62t.sinc data/languages/rx62t.sinc.orig-ea4cd204     # original kept next to it (also rx62t.sla.orig-ea4cd204)
patch -p1 < /workspace/FT-710_Firmware/tools/ghidra/rx62t-movu-fix.patch
JAVA_HOME=~/opt/jdk-21.0.13+9 ~/opt/ghidra_12.1.4_PUBLIC/support/sleigh data/languages/rx62t.slaspec   # 8 NOP warnings, as before
```
SHA-256 of `rx62t.sinc`: original `42f51c2c…0f12`, patched `d32178a9…011b`. Programs analysed before the fix keep the old
instructions until they are re-disassembled, so MAIN was re-imported (T17). Undo: copy the two `.orig-ea4cd204` files back.
The fix is local; it is not sent upstream.

GNU binutils `rx-elf` (the fallback route) was **not** needed and not built.

## Bootstrap (T20)

`tools/bootstrap.sh` scripts every install and build step above that was done by hand: the Ghidra 12.1.4 + Temurin JDK 21.0.13+9
download with SHA-256 checks (`--only deps`, Linux x86_64), the RX module install from `stefan00lpf/rx-proc-ghidra` @ `ea4cd204` plus the
T17 patch and `sleigh` compile (`--only rx`), the four Ghidra programs, the decomp re-export and diff, and the Project X-Ray checkouts +
venv + SDR netlist/Verilator chain (`--only sdr`). Newcomer walk-through: [getting-started.md](getting-started.md); catalogue of all
scripts: [tools/README.md](../tools/README.md). `hdl/sdr/sim/build_full.sh` takes `JOBS` (default 16) and `tools/xc7_fasm.py` takes
`FT710_VENV` (default `~/.local/share/ft710-tools/venv`) since T20.

## Ghidra helper scripts (tools/ghidra/)

| Script | Purpose |
|---|---|
| `ExportDecomp.java` | shared export: decompiled C in 50-function files plus `functions.tsv` (T01/T05) |
| `SetupRX651.java` | pre-script for RX651 raw images: RAM/IO/data-flash blocks, `.data` copy-down (`copy=SRC:END:DST`), fixed and relocatable vectors → functions (T05) |
| `ApplyNames.java` + `names_main.tsv` | reproducible function names and labels for MAIN (T05) |
| `CatDispatch.java` | dumps the MAIN CAT mnemonic → switch case → handler table (T05) |
| `PeriphRefs.java` | lists the functions that touch given peripheral register ranges (T05) |
| `DumpListing.java` | dumps disassembly (and optionally the decompile) for addresses or functions (T05) |
| `ProgramStats.java` | function/instruction/data coverage and the largest undefined ROM gaps (T05) |
| `DumpFuncs.java` | decompiles a few functions (by address or name) into one text file, without a full export (T07) |
| `IfdspM33Setup.java` | pre-script for the IFDSP Cortex-M33 image: RT685 memory map, MCUXpresso copy-down block, .bss, vector table → Thumb functions (T07) |
| `IfdspFindFuncs.java` | post-script: finds missed Thumb `push {…,lr}` prologues in the M33 code ranges and defines rodata strings (T07) |
| `IfdspM33Names.java` | reproducible function names for the IFDSP M33 program (T07) |
| `IfdspHifi4Setup.java` | pre-script for the carved HiFi4 images: maps each one at its DSP load address and seeds the vectors (T07) |
| `IfdspHifi4FindFuncs.java` | post-script: creates functions at 4-aligned `entry a1,N` prologues and drops artifacts in uninitialized memory (T07) |
| `IfdspHifi4Names.java` | reproducible function names (+ plate comments) for the IFDSP HiFi4 program (T12e, merged in T17) |
| `DisplaySetup.java` / `DisplayFindCode.java` / `DisplayReport.java` | DISPLAY (RZ/A1H) pre-script memory map + seeding, second code-discovery pass (pointer tables, prologues, orphans), read-only report (T06) |
| `FixFuncEntries.java` + `entries_display.tsv` | creates function entries that analysis missed or started late (T11); run before ApplyNames |
| `XrefsList.java`, `T10eXrefs.java`, `XrefsT10d.java` | print references to addresses or ranges with the containing function (T10 helpers; one would do, the others are kept for the task logs) |
| `T10eMovuRegCount.java` | lists every `MOVU.B/W Rs,Rd` (0x5B/0x5F, ld=11); after the T17 SLEIGH fix all 107 print as register forms |
| `rx62t-movu-fix.patch` | the T17 SLEIGH fix for the RX module (see above) |
| `names_*.picks.tsv` | T17 resolutions of name conflicts between sub-task proposals (input of `tools/names_merge.py`) |

Python helpers in `tools/` (stdlib only; run with `python3 -I`):

| Script | Purpose |
|---|---|
| `sfl_decode.py` / `sfl_header.py` | decode an `.SFL` file to the raw image / parse and check its header (T03/T04) |
| `sfl_encode.py`, `test_sfl_roundtrip.py` | inverse of `sfl_decode.py`; round-trip test SFL → decode → encode → identical SFL for all shipped images (T16) |
| `t16_patches.py` | builds and verifies the T16 DISPLAY patch SFLs into `build/` (never flashed) |
| `xbit_parse.py`, `xc7_db.py`, `xc7_bram_tables.py`, `xc7_package_fit.py` | SDR XC7A50T bitstream: config packets, Project X-Ray frame/tile/BRAM decode, BRAM tables, which packages bond every used IOB (T13/T16) |
| `main_key_tables.py` | dumps the MAIN front-panel key handler tables (T10b, `docs/code/main/ui-keys.md`) |
| `main_menu_table.py` | dumps (and diffs) the MAIN EX/setup-menu item table (T10f, `docs/code/main/menu.md`) |
| `display_assets.py` | lists the DISPLAY GUI sprites/fonts (T11e; lists only, extracts nothing) |
| `t11g_pinmux_decode.py` | decodes DISPLAY `pinmux_init` 0x20101190 into a port/pin → mode table (T11g) |
| `ifdsp_xtdis.py` | minimal Xtensa base-ISA linear disassembler for the HiFi4 SRAM image (T12c) |
| `ifdsp_hifi4_dis.py` | per-function FLIX-aware HiFi4 listing with the Zephyr RT600 objdump, names from `IfdspHifi4Names.java` (T12e) |
| `ifdsp_hifi4_regscan.py` | register-file accesses in a HiFi4 objdump listing (T12b) |
| `ifdsp_coef_tables.py` | finds and classifies numeric tables (filters, windows, sin/cos) in the HiFi4 image (T12e) |
| `names_merge.py` | merges/reports per-sub-task name TSVs into the shared ones; conflicts resolved with `--picks` (T17) |
| `ifdsp_names_java.py` | converts the IFDSP name scripts (`IfdspM33Names.java`, `IfdspHifi4Names.java`) to/from TSV (T17) |
| `pages_final_names.py` | switches code pages from proposed (italic) names to the applied Ghidra names (T17) |
| `index_refresh.py` | refreshes the export-file column of a `decomp/*/INDEX.md` from `functions.tsv` (T17) |
| `issues_sync.py` | mirrors `docs/tasks/` into GitHub issues (run by the parent agent only) |

`tools/ifdsp_dsp_images.py` (stdlib) carves the three HiFi4 images out of the decoded IFDSP image. `tools/ifdsp_l32r.py` (heuristic L32R literal scan per HiFi4 function) and `tools/ifdsp_regscan.py` (HiFi4 accesses to the shared register file) work around the missing FLIX decode (T12). The IFDSP rebuild commands are in `decomp/ifdsp/INDEX.md`. The IFDSP programs use only stock Ghidra languages (`ARM:LE:32:v8-m`, `Xtensa:LE:32:default`). The Xtensa module decodes only the base ISA, not HiFi4 FLIX bundles (see T07).

MAIN full rebuild (from the repo root; ~1 minute in total):
```sh
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -import build/FT-710_MAIN_V0112.bin -overwrite \
  -processor rx62t:LE:32:default -loader BinaryLoader -loader-baseAddr 0xFFF80000 -analysisTimeoutPerFile 3600 \
  -scriptPath tools/ghidra -preScript SetupRX651.java \
    copy=0xFFF8EADC:0xFFF8EC1C:0x25D20 copy=0xFFF8EE4C:0xFFF8EEA4:0x1FF1A copy=0xFFF8EC1C:0xFFF8EE4C:0x1B3CC \
  -postScript ApplyNames.java tools/ghidra/names_main.tsv -postScript ExportDecomp.java decomp/main 50
tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
  -scriptPath tools/ghidra -postScript CatDispatch.java decomp/main/cat_dispatch.tsv \
  0xFFF805EC 104 0xFFF8F014 0xFFFA3B8A 0xFFF806BC 10 0xFFFA3A2A
```

## Side effects outside the repo

Ghidra writes per-user state to `~/Library/ghidra/ghidra_12.1.4_PUBLIC/` (settings, logs) and `/var/tmp/<user>-ghidra/` (caches). Both are safe to delete. T05 also added the per-user RX extension in `~/Library/ghidra/ghidra_12.1.4_PUBLIC/Extensions/RX/` (see above).

## Linux container setup (2026-10-27)

The repo moved to a Docker container on Tower (Unraid, x86_64). Everything is installed under the persistent home, so nothing here needs a container-image change.

| Component | Version | Source / verification | Location |
|---|---|---|---|
| Ghidra | 12.1.4 PUBLIC 20260921 | GitHub release `Ghidra_12.1.4_build`; SHA-256 `ddac49f9…d4db` matches the release notes | `~/opt/ghidra_12.1.4_PUBLIC` |
| JDK 21 | Temurin 21.0.13+9 | Adoptium API; SHA-256 matches Adoptium's published checksum | `~/opt/jdk-21.0.13+9` |
| RX module | stefan00lpf/rx-proc-ghidra `ea4cd204` (same commit as T05) | six `data/languages/rx62t.*` files only, plus an empty `Module.manifest`; `sleigh` compile shows the same 8 NOP warnings | `~/opt/ghidra_12.1.4_PUBLIC/Ghidra/Processors/RX/` (inside this Ghidra copy, so the REA MCP server sees it too) |
| REA MCP | **Fork** github.com/Reid-n0rc/rea, branch `feat-ghidra-rx-raw` at `db2bfd303` (based on upstream morluto/rea `baec375c3` = `rea-agents` 6.8.0) | `npm pack` in `~/opt/rea`, then `npm install --global --prefix ~/.local ~/opt/rea-dist/rea-agents-6.8.0-rx-db2bfd303.tgz`; `rea setup --client claude_code --skill-client claude_code --skill --yes` refreshed the skill; the user-scope MCP entry runs `/usr/local/bin/node ~/.local/bin/rea mcp` with `env` `GHIDRA_INSTALL_DIR`, `JAVA_HOME`, `GHIDRA_HEADLESS_MAXMEM=10G` | `~/.local/bin/rea`, `~/.claude.json` (`mcpServers.rea`), `~/.claude/skills/reverse-engineer-anything`; source clone `~/opt/rea` (remotes `origin` = fork, `upstream` = morluto/rea) |

- `binutils-arm-none-eabi` 2.40 (Debian, `persist-apt binutils-arm-none-eabi`, 2026-10-27, T11): `arm-none-eabi-objdump -D -b binary -m arm --adjust-vma=0x20100000` for quick DISPLAY disassembly checks outside Ghidra.
- `tools/ghidra-headless.sh` uses the Homebrew paths when `/opt/homebrew/opt/ghidra` exists, else the `~/opt` paths above.
- Ghidra's per-user state on Linux is `~/.config/ghidra/ghidra_12.1.4_PUBLIC/`.
- The first JVM start after install takes over 10 s while it reads files from the array share for the first time, which can trip REA's doctor timeout. Re-run it.
- **REA and MAIN (Renesas RX).** [fact] Stock rea-agents 6.8.0 cannot take RX: its ELF machines and raw-binary families are hard-coded, and raw-binary cannot reuse a Ghidra project. The fork adds (1) a raw-binary `rx` family bound to the installed `rx62t:LE:32:default` module, refused with `capability_unavailable` if the module is missing, and (2) an optional `base_address` separate from `entry_point`, because MAIN's ROM starts with data, not code. Open MAIN with `open_binary {path: "/workspace/FT-710_Firmware/build/FT-710_MAIN_V0112.bin", format: "raw-binary", architecture: "rx", base_address: "0xFFF80000", entry_point: "0xFFF8FBDB", provider_id: "ghidra"}` (CLI: `--target-format raw-binary --architecture rx --base-address 0xFFF80000 --entry-point 0xFFF8FBDB --provider ghidra`). Checked 2026-10-27: the load image is `verified`, and `cat_parse` @ 0xFFFA347C decompiles the same as the committed `decomp/main`, apart from names. Limits: REA re-imports from scratch, so the RAM/IO blocks, `.data` copy-down, named vectors and `names_main.tsv` names from `SetupRX651.java`/`ApplyNames.java` are absent; RAM globals show as unmapped `DAT_`/`_DAT_`. `REA_GHIDRA_SEED_FILE` works for raw imports (function/label seeds). Keep using `tools/ghidra-headless.sh` and the scripts in `tools/ghidra/` for the canonical, named MAIN project and `decomp/main` exports. Upstream context: morluto/rea#4246 (a generic comment was posted 2026-10-27; it does not mention the fork). Upstream's `src/gpu/GpuPayloadCodec.test.ts` zstd test fails on unmodified `baec375c3` too; it is not caused by the fork. REA hard-codes Ghidra `-XX:ParallelGCThreads=2`, and its vitest config caps workers at 2: pass `--maxWorkers=$(nproc)` to vitest directly.
- Remove REA: `claude mcp remove --scope user rea; rm -rf ~/.claude/skills/reverse-engineer-anything; npm uninstall -g --prefix ~/.local rea-agents`. Back to stock npm: `npm install -g --prefix ~/.local rea-agents@6.8.0`, then `rea setup --client claude_code --skill-client claude_code --skill --yes`. Update the fork: `git -C ~/opt/rea fetch upstream && git -C ~/opt/rea rebase upstream/main`, rerun the checks and `npm run verify:ghidra:rx`, then repack and reinstall as above.

## Zephyr SDK RT600 HiFi4 toolchain (T12e)

| Item | Value |
|---|---|
| What | Zephyr SDK 0.17.0 `xtensa-nxp_rt600_adsp_zephyr-elf` toolchain (GNU binutils 2.38 built with the NXP RT600 HiFi4 core overlay). Its objdump decodes the IFDSP HiFi4 FLIX bundles that Ghidra's Xtensa module cannot |
| Source | https://github.com/zephyrproject-rtos/sdk-ng/releases/tag/v0.17.0, asset `toolchain_<platform>_xtensa-nxp_rt600_adsp_zephyr-elf.tar.xz` |
| SHA-256 | from the release `sha256.sum`: linux-x86_64 `2e0a54e20056b82cae12593e5d936d1e22cdb3f90cb9e77d59c500a5ad4abdc2`, linux-aarch64 `c099e411daec57b6c4e4824d1a1e3ebf2ed607103dc04b66919ae19c14bbfbfa`, macos-aarch64 `31b6072b911d2324443d58ec0176bd560eba3b3095c9aba18c3f40c2de8f5785`, macos-x86_64 `f95f8a3fa5fc864a5f731f492dfe8bb96e1c3b3a1ae5455dc68ffddb04c609cd` (pinned in `tools/bootstrap.sh`) |
| Install | `tools/bootstrap.sh --only deps`, or by hand: extract only (no `setup.sh`, no sudo) to `~/opt/zephyr-sdk-0.17.0/`; objdump at `~/opt/zephyr-sdk-0.17.0/xtensa-nxp_rt600_adsp_zephyr-elf/bin/xtensa-nxp_rt600_adsp_zephyr-elf-objdump`. Installed on macOS arm64 on 2026-10-28 (issue #87); `objdump --version`: GNU objdump (Zephyr SDK 0.17.0) 2.38 |
| Used by | `tools/ifdsp_hifi4_dis.py` (bootstrap step `flix` → committed `decomp/ifdsp/hifi4/flix.dis`), `tools/ifdsp_hifi4_regscan.py` (command in `decomp/ifdsp/INDEX.md`) |
| Not tried | Espressif overlays (ESP32 cores): different core configuration |
| Remove | `rm -rf ~/opt/zephyr-sdk-0.17.0` |

## Python

Use the system `python3` for the tools in `tools/`. Run scripts that read firmware data with `python3 -I`.

## Project X-Ray (T13, Xilinx 7-series bitstream database)

Used by `tools/xc7_db.py` (stdlib) to map the SDR bitstream (XC7A50T) onto tiles, decode BRAM INIT contents and find used
sites. Nothing is built or installed system-wide; both are plain git checkouts read as data files.

| Item | Source | Version | Method | Location |
|---|---|---|---|---|
| prjxray (Python utilities, docs) | https://github.com/f4pga/prjxray | commit `c9f02d8` (2025-06-05) | `git clone` (no C++ build, no pip install) | `~/.local/share/ft710-tools/prjxray/` |
| prjxray-db | https://github.com/f4pga/prjxray-db | commit `0a0adde` (2021-12-14) | `git clone --filter=blob:none` + sparse checkout of `artix7/*.db`, `*.json`, `*.yaml`, `mask_*`, `xc7a50t*/` (~78 MB) | `~/.local/share/ft710-tools/prjxray-db/` |

`tools/xc7_db.py` defaults to `~/.local/share/ft710-tools/prjxray-db/artix7` (override with `--db` or `$PRJXRAY_DB`) and
part `xc7a50tcpg236-1` (the frame layout is the same for every XC7A50T package; only IOB bonding differs).

**Linux container (T13, 2026-10-27).** Re-installed the same two checkouts on Tower, at the same commits:
`git clone https://github.com/f4pga/prjxray ~/.local/share/ft710-tools/prjxray` + `checkout c9f02d8576042325425824647ab5555b1bc77833`
(2025-06-05, 29 MB); `git clone --filter=blob:none --no-checkout https://github.com/f4pga/prjxray-db ~/.local/share/ft710-tools/prjxray-db`,
`sparse-checkout set --no-cone '/artix7/*.db' '/artix7/*.json' '/artix7/*.yaml' '/artix7/mask_*' '/artix7/xc7a50t*/'`,
`checkout 0a0addedd73e7e4139d52a6d8db4258763e0f1f3` (2021-12-14, 79 MB). Nothing built, no pip, no sudo; the home is
persistent, so they survive container rebuilds. Check: `python3 -I tools/xc7_db.py build/FT-710_SDR_V0104.bin frames`
prints `MATCH`. Remove: `rm -rf ~/.local/share/ft710-tools/prjxray ~/.local/share/ft710-tools/prjxray-db`.
Tools using them: `tools/xc7_db.py` (`frames`, `bram`, `bramcfg`, `usage`, `sites`, `config`, `tilebits`) and
`tools/xc7_bram_tables.py` (`tables`, `show`, `lanes`, `halfsym`, `selftest`).

### FPGA netlist tools (T15)

**T15 (2026-10-27).** prjxray-db sparse checkout extended with `git -C ~/.local/share/ft710-tools/prjxray-db
sparse-checkout add '/artix7/mapping/'` (prjxray's `Database` reads `mapping/devices.yaml`). New venv
`python3 -m venv ~/.local/share/ft710-tools/venv` (Python 3.11.2) + `pip install fasm simplejson intervaltree pyyaml`
from PyPI: `fasm 0.0.2.post88` (pure-Python textX parser; the Antlr fast path is not built), `textX 4.4.0`,
`Arpeggio 2.0.3`, `simplejson 4.2.0`, `intervaltree 3.2.1`, `sortedcontainers 2.4.0`, `PyYAML 6.0.3`. No sudo, nothing
built. Used only by `tools/xc7_fasm.py fasm` (which re-runs itself under that venv). Remove:
`rm -rf ~/.local/share/ft710-tools/venv`.

**T15d (2026-10-28).** `persist-apt iverilog yosys` (the container's sanctioned Debian install, see the global
CLAUDE.md): Debian bookworm **iverilog 11.0-1.1+b1** and **yosys 0.23-6** (+ dependencies such as xdot), recorded in
`~/.config/claude-container/apt-packages.txt` so they survive rebuilds. Used for the T15d smoke test
(`yosys -s ...` with `+/xilinx/cells_sim.v`, `cells_xtra.v`) and the T15d/T15e simulations (`iverilog -g2012`).

**T15e (2026-10-28).** `persist-apt verilator`: Debian bookworm **verilator 5.006-3**, used by `hdl/sdr/sim/build_full.sh` for the whole-netlist simulation (`-j 16`, about 2.5 min build, about 15,000 clocks/s). Yosys' cell models crash it on CARRY4, so `hdl/sdr/sim/xc7_prims_vl.v` has its own primitive models.

## Guide figures and wiki (T19)

- `librsvg2-bin` 2.54.7 (`rsvg-convert`), `libxml2-utils` 2.9.14 (`xmllint`) and `fonts-dejavu-core`, installed 2026-10-28 with
  `persist-apt`. Used to validate the guide's SVG figures and render them to PNG for checking.
- `tools/guide_to_wiki.py` splits `docs/guide/README.md` into GitHub-wiki pages (`Home`, one page per chapter, `_Sidebar` as the table of
  contents, `img/`) under `build/wiki/`. Standard library only.
- `@mermaid-js/mermaid-cli` 11.4.2 (`mmdc`), installed 2026-10-28 with `npm install -g --prefix ~/.local`. Its headless Chrome is
  in `~/.cache/puppeteer`. Browser libraries were installed with `persist-apt` (libgbm1 libnss3 libatk1.0-0 libatk-bridge2.0-0
  libcups2 libxkbcommon0 libxcomposite1 libxdamage1 libxrandr2 libpango-1.0-0 libcairo2 libasound2). Run it as `mmdc -p pp.json`
  with `{"args":["--no-sandbox"]}`, because the container has no user namespaces. Used to check that every Mermaid block renders.

## Commit signing (2026-10-28)

The owner wants commits signed, but not required. `ssh-keygen -t ed25519` created `~/.ssh/ft710_signing_ed25519` (no passphrase, so
agents can sign unattended). The repo-local git config sets `gpg.format ssh`, `user.signingkey ~/.ssh/ft710_signing_ed25519.pub`,
`commit.gpgsign true` and `gpg.ssh.allowedSignersFile ~/.ssh/allowed_signers`, and the wiki clone uses the same settings. For GitHub to
show "Verified", the public key must be added to the owner's account as a **signing** key (`gh ssh-key add --type signing`, which needs
the `admin:ssh_signing_key` scope).
