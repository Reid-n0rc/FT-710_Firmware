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
   The PDFs themselves are committed in `Manuals/` (owner decision, 2026-10-28).
5. Open work as GitHub issues: one issue per open question and follow-up, labelled, so newcomers can pick one up.

**Committed by the owner's decision (2026-10-28):** the manual PDFs in `Manuals/` and the three canonical Ghidra projects
(`ghidra/FT710_{MAIN,DISPLAY,IFDSP}`). Not committed: the firmware download and the decoded binaries (`build/`), which the bootstrap
rebuilds and checks against `docs/inputs.sha256`. The bootstrap must still be able to rebuild the Ghidra projects from scratch.

## Plan
(written by the agent)

## Findings

## Follow-ups
