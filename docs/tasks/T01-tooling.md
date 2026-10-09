# T01 — Tooling

**Status:** todo · **Depends on:** —

## Goal
Install Ghidra 11.x and JDK 21 so that `analyzeHeadless` works.

## Deliverables
- `docs/tooling.md`: install method, versions, the path to `analyzeHeadless`, and how to run it.
- A smoke test: headless-import any small binary into a throwaway project under `ghidra/`.

## Notes / hints
- Homebrew is available: `brew install --cask temurin@21 ghidra` is likely the simplest route. The system Java is 11 (Corretto), which is too old.
- Don't change the global default JAVA_HOME. Point Ghidra at JDK 21 through its own config if you need to.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
