#!/bin/sh
# Run Ghidra analyzeHeadless with the JDK 21 it needs (see docs/tooling.md).
# Usage: tools/ghidra-headless.sh <projdir> <projname> [analyzeHeadless args...]
# Override paths with GHIDRA_JAVA_HOME / GHIDRA_HEADLESS if installed elsewhere.
JAVA_HOME="${GHIDRA_JAVA_HOME:-/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home}"
export JAVA_HOME
exec "${GHIDRA_HEADLESS:-/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless}" "$@"
