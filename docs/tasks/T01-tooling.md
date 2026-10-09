# T01 — Tooling

**Status:** done · **Depends on:** —

## Goal
Install Ghidra 11.x and JDK 21 so that `analyzeHeadless` works.

## Deliverables
- `docs/tooling.md`: install method, versions, the path to `analyzeHeadless`, and how to run it.
- A smoke test: headless-import any small binary into a throwaway project under `ghidra/`.

## Notes / hints
- Homebrew is available: `brew install --cask temurin@21 ghidra` is likely the simplest route. The system Java is 11 (Corretto), which is too old.
- Don't change the global default JAVA_HOME. Point Ghidra at JDK 21 through its own config if you need to.

## Plan
1. Check what is already installed: Java VMs (`/usr/libexec/java_home -V`) and the Homebrew Ghidra/JDK packages.
2. Install Ghidra and JDK 21 through Homebrew without sudo or interactive prompts. Leave the global JAVA_HOME and shell profile alone.
3. Smoke test: run `analyzeHeadless` with an explicit `JAVA_HOME` (JDK 21) to import `/bin/ls` into a throwaway project under `ghidra/`, with `-deleteProject`.
4. Write `docs/tooling.md` with the versions, paths, and command lines.

## Findings
- No `ghidra` cask exists in Homebrew. Ghidra is a homebrew-core **formula**. **Ghidra 12.1.4** (formula, depends on `openjdk@21`) was already installed at `/opt/homebrew/Cellar/ghidra/12.1.4` (dated 2026-10-09 08:34) when this task started, so no new install was needed. It is 12.x rather than 11.x, and it still requires Java ≥ 21.
- JDK: **OpenJDK 21.0.12.1** (Homebrew `openjdk@21`, keg-only), at `/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home`. The `temurin@21` cask was not installed because it is a `.pkg` that would need sudo.
- The system default Java is still Corretto 11. `JAVA_HOME` is unset globally, and no profile or Ghidra config was changed.
- `analyzeHeadless` lives at `/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless`. It is not on PATH and does not set JAVA_HOME itself, so pass `JAVA_HOME=<jdk21>` on the command line.
- Smoke test (`-import /bin/ls -deleteProject` into `ghidra/t01_smoke`): import, auto-analysis (~2 s), and save all succeeded. The project was deleted afterwards.
- Full details are in `docs/tooling.md`.

## Follow-ups
- Consider a small wrapper script, `tools/ghidra-headless.sh`, that sets JAVA_HOME and calls analyzeHeadless, so later tasks don't repeat the long command line.
- AGENTS.md says "Ghidra 11.x". The installed version is 12.1.4, so the coordinator may want to update that line.
