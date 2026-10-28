# T20 — Onboarding: rebuild everything from the official downloads, plus a getting-started manual

**Status:** done · **Depends on:** T01–T19

## Goal
The owner wants "everything someone will need to pick up the project and run with it". A newcomer must be able to go from a clean
Linux (or macOS) machine to the same working state as the owner's: decoded images, the four Ghidra projects with every name applied,
re-exported decomps identical to `decomp/`, the SDR netlist/Verilog/Verilator model, and the docs. Deliverables:
1. `tools/bootstrap.sh`: one command, idempotent, with steps that can run alone. It checks the inputs against SHA-256 values
   (`docs/inputs.sha256`), decodes the SFLs, builds the four Ghidra projects with the committed scripts and names, re-exports the
   decomps and diffs them against `decomp/`, and builds the SDR netlist/Verilog/Verilator model (optional, slow).
2. `docs/getting-started.md`: the manual. It covers prerequisites and install commands per OS, getting the inputs (with links), running
   the bootstrap, a tour of the repo, how to work with Ghidra and REA, the evidence and figure conventions, how to contribute (issue → PR),
   and where the open questions are.
3. `tools/README.md`: a catalogue of every script in `tools/` and `tools/ghidra/` (what it does, inputs, outputs, which task made it).
4. `docs/manuals.md`: every manual and datasheet the project uses, with source links and what it was used for.
   The PDFs themselves are committed in `Manuals/` (owner decision, 2026-10-28).
5. Open work as GitHub issues: one issue per open question and follow-up, labelled, so newcomers can pick one up.

**Committed by the owner's decision (2026-10-28):** the manual PDFs in `Manuals/` and the three canonical Ghidra projects
(`ghidra/FT710_{MAIN,DISPLAY,IFDSP}`). Not committed: the firmware download and the decoded binaries (`build/`), which the bootstrap
rebuilds and checks against `docs/inputs.sha256`. The bootstrap must still be able to rebuild the Ghidra projects from scratch.

## Plan
Owner: T20 agent (worktree branch), 2026-10-28. Scratch output only (`$BOOTSTRAP_OUT`); the main checkout's `build/` and `ghidra/` are
never written. One commit per step.
1. **Inputs.** SHA-256 of the Yaesu zip, the four SFLs and every decoded `build/*.bin` (from the main checkout) into
   `docs/inputs.sha256` (`sha256sum -c` format, paths relative to the repo / output root).
2. **`tools/bootstrap.sh`** (bash, `set -euo pipefail`), steps `deps`, `inputs`, `decode`, `rx`, `ghidra`, `export`, `verify`, `sdr`,
   selectable with `--only` / `--skip`; every path from the environment (`BOOTSTRAP_OUT`, `GHIDRA_INSTALL_DIR`, `JAVA_HOME`, `OPT_DIR`,
   `PRJXRAY*`, `FT710_VENV`), all CPUs (`nproc`, Ghidra `-max-cpu`), heap from `GHIDRA_HEADLESS_MAXMEM`. It reproduces exactly the
   commands of T05/T17 (MAIN: `rx62t:LE:32:default`, base 0xFFF80000, `SetupRX651.java` with the three copy-downs, `ApplyNames.java
   names_main.tsv`, `CatDispatch.java`), T06/T11/T17 (DISPLAY: `ARM:LE:32:v7` at 0x20100000, `DisplaySetup.java`, `DisplayFindCode.java`
   twice, `FixFuncEntries.java entries_display.tsv`, `ApplyNames.java names_display.tsv`) and T07/T17 (IFDSP: two programs in one project,
   M33 `ARM:LE:32:v8-m` at 0x08000000 and HiFi4 `Xtensa:LE:32:default` at 0 with their setup/find/names scripts). Hand steps become
   scripted: the RX SLEIGH module install + `rx62t-movu-fix.patch` + `sleigh` compile (T05/T17), the Ghidra/JDK download with SHA-256
   checks, the prjxray/prjxray-db checkouts and the venv (T13/T15), and the SDR chain (T15a–e: FASM, netlist, Verilog/XDC, Verilator).
3. **Test for real** into scratch: hashes of the decoded images, `diff -r` of the re-exported decomps against `decomp/` (document any
   nondeterminism), the SDR chain against the main checkout's `build/sdr/` files if time allows (else mark untested).
4. **Fix the T19h follow-up:** `CatDispatch.java` records the branch after `CMP #N` and prints `len>8` etc. instead of `len==8`;
   regenerate `decomp/main/cat_dispatch.tsv` and recheck `docs/cat-commands-primary.md`.
5. **Docs:** `docs/getting-started.md` (Mermaid download → working tree, Debian/Ubuntu + Homebrew commands, Ghidra/REA, conventions,
   contributing, open questions), `tools/README.md` (every script), `docs/manuals.md` (every manual/datasheet referenced, URL, use, SHA-256).
6. **Open work:** collect `system.md` §8 O-items and C-items, every task file's Follow-ups and the owner-approval items into
   `docs/tasks/T20-open-issues.md` (title, body, labels) for the parent to create as issues.
7. Findings, follow-ups, status.

## Findings
All runs on the Linux container (Debian bookworm, x86_64, 20 cores, 15 GB), Ghidra 12.1.4 + Temurin 21.0.13+9, into a scratch
`BOOTSTRAP_OUT`; the main checkout's `build/` and `ghidra/` were only read (the SFLs) and hashed.

- **Deliverables:** [`tools/bootstrap.sh`](../../tools/bootstrap.sh) (steps `deps inputs decode rx ghidra export verify sdr`),
  [`docs/inputs.sha256`](../inputs.sha256) (zip, 4 SFLs, update-manual PDF, 9 decoded/carved `build/*.bin`),
  [`docs/getting-started.md`](../getting-started.md), [`tools/README.md`](../../tools/README.md), [`docs/manuals.md`](../manuals.md) (14 PDFs
  with SHA-256 + 13 cited-but-not-kept documents), [`T20-open-issues.md`](T20-open-issues.md) (45 issues for the parent to create).
- **Inputs/decode [fact]:** all 6 `Firmware/` files and all 9 decoded images match `docs/inputs.sha256`.
- **RX module [fact]:** `--only rx` into an empty `RX_MODULE_DIR` cloned `stefan00lpf/rx-proc-ghidra`, checked out `ea4cd204`, verified the
  original `rx62t.sinc` (`42f51c2c…`), applied `rx62t-movu-fix.patch` (→ `d32178a9…`) and compiled: the new `rx62t.sla` is byte-identical
  to the installed one (`0cdefede…`). A second run detects the installed module and skips.
- **Ghidra + export [fact]:** from an empty project directory, `ghidra` + `export` take about 4 minutes in total (export about
  1 minute of it) and the re-export is **byte-identical** to the committed `decomp/` for all four programs (MAIN 2268
  functions, DISPLAY 2087, IFDSP M33 426, HiFi4 1148 with the known 1 failure) and `cat_dispatch.tsv`. A second full rebuild with `FORCE=1`
  was identical again, so there is **no nondeterminism** to document. Exporting in a separate `-readOnly` run (MAIN historically exported
  as a post-script of the import run) makes no difference. The only files not compared are the hand-written `INDEX.md` / `README.md`.
- **Reproduction recipe [fact]:** exactly the commands recorded in T05/T17 (MAIN), T06/T11/T17 (DISPLAY: import with `DisplaySetup`,
  `DisplayFindCode` twice, `FixFuncEntries entries_display.tsv`, `ApplyNames names_display.tsv`) and `decomp/ifdsp/INDEX.md` (IFDSP);
  nothing in the shared projects was done by hand that the names files and scripts do not reproduce.
- **SDR chain [fact]:** `--only sdr` with an empty `FT710_TOOLS` cloned prjxray @ `c9f02d8` and prjxray-db @ `0a0adde` (sparse), built the
  venv with the pinned versions, and produced FASM, `unknown_bits.txt`, `netlist.json`, `ft710_sdr.v`/`.xdc`, `prims.v`, `simprims.v`
  **byte-identical** to the main checkout's `build/sdr/` (T15). The Verilator model built (`JOBS=8`) and the smoke test answered the MAIN
  frame `r0000` with `r010437` (reg 0 = 0x0104, the V01-04 version) and the console prompt `[IF]>`. Whole step: 191 s.
- **deps [fact]:** tested from the local download cache (`DL_DIR=~/opt/dl`) into an empty `OPT_DIR`: SHA-256 checks pass, Ghidra and the
  JDK unpack and run. The two pinned URLs answer 200 (range GET 206); a full download over the network was not repeated.
- **CatDispatch fix (T19h follow-up) [fact]:** the generator now reads the branch after `CMP #N` and prints the relation under which the
  handler runs (`len>8` for EX, from `CMP #8,R1; BGT`), and rebuilds the six compound tests from the compares that set the 0/1 flag:
  DT `len==10||len==12`, EM `len>=6&&len<=55`, KM `len>=5&&len<=54`, MT `len>=8&&len<=19`, VM `len==4||len==3||len==6`. All other 98
  rows are unchanged; the new values agree with the hand-read lengths already in `cat-commands.md`. `decomp/main/cat_dispatch.tsv`,
  `decomp/main/INDEX.md` and `cat-commands-primary.md` updated.
- Small tool changes for the bootstrap: `hdl/sdr/sim/build_full.sh` takes `JOBS`, `tools/xc7_fasm.py` takes `FT710_VENV`.

## Follow-ups
- Parent: create the 45 issues in [T20-open-issues.md](T20-open-issues.md) (labels listed there; the labels `analysis`, `docs`,
  `tooling`, `hardware`, `needs-radio`, `needs-owner`, `good first issue`, `main`, `display`, `ifdsp`, `sdr`, `cat` may need creating).
- Untested: `bootstrap.sh` on macOS/Homebrew and on a clean Debian/Ubuntu machine (issue 40 in the list), and the network download in
  `deps` (only the cached files and the URLs were checked).
- The `rx` step installs into the Ghidra tree (as the container does). On macOS, T05 used a per-user extension directory instead; both
  work, `RX_MODULE_DIR` selects.
