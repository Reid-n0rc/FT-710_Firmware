#!/bin/sh
# Run Ghidra analyzeHeadless with the JDK 21 it needs (see docs/tooling.md).
# Usage: tools/ghidra-headless.sh <projdir> <projname> [analyzeHeadless args...]
# Override paths with GHIDRA_JAVA_HOME / GHIDRA_HEADLESS if installed elsewhere.
# Defaults: macOS Homebrew install if present, else the Linux container install under ~/opt.
if [ -d /opt/homebrew/opt/ghidra ]; then
  def_java=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home
  def_headless=/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless
else
  def_java="$HOME/opt/jdk-21.0.13+9"
  def_headless="$HOME/opt/ghidra_12.1.4_PUBLIC/support/analyzeHeadless"
fi
JAVA_HOME="${GHIDRA_JAVA_HOME:-$def_java}"
export JAVA_HOME
exec "${GHIDRA_HEADLESS:-$def_headless}" "$@"
