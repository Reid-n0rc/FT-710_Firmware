# T20 — Onboarding: rebuild everything from the official downloads, plus a getting-started manual

**Status:** in progress · **Depends on:** T01–T19

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
   No PDFs are committed.
5. Open work as GitHub issues: one issue per open question and follow-up, labelled, so newcomers can pick one up.

**Not committed, by decision (2026-10-28):** Yaesu's firmware, the decoded binaries, the Ghidra project databases (which embed the full
binaries) and third-party manuals. They are complete copyrighted works; the bootstrap reproduces them byte for byte from the official
downloads instead. The decompiled C in `decomp/` is already committed.

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

## Follow-ups
