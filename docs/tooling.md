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

Run this from the repo root. Projects go under `ghidra/`, which is gitignored.

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

## Side effects outside the repo

Ghidra writes per-user state to `~/Library/ghidra/ghidra_12.1.4_PUBLIC/` (settings, logs) and `/var/tmp/<user>-ghidra/` (caches). Both are safe to delete.

## Python

Use the system `python3` for the tools in `tools/`. Run scripts that read firmware data with `python3 -I`.
