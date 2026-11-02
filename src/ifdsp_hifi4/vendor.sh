#!/bin/sh
# Fetch the unmodified vendor sources listed in vendor.tsv into vendor/<repo>/<path> and check their SHA-256.
# (newlib, rpmsg-lite. They are not committed:
# they are public, pinned here by commit and hash, and fetched from raw.githubusercontent.com.)
# Usage: ./vendor.sh            (from src/ifdsp_hifi4; `make vendor` runs it)
set -eu
cd "$(dirname "$0")"
fail=0
grep -v '^#' vendor.tsv | tail -n +2 | while IFS="$(printf '\t')" read -r repo ref commit path sha; do
  out="vendor/${repo#*/}/$path"
  if [ -f "$out" ] && echo "$sha  $out" | sha256sum -c --quiet - 2>/dev/null; then continue; fi
  mkdir -p "$(dirname "$out")"
  curl -fsSL --retry 3 -o "$out" "https://raw.githubusercontent.com/$repo/$commit/$path"
  echo "$sha  $out" | sha256sum -c --quiet - || { echo "vendor.sh: hash mismatch for $out" >&2; exit 1; }
done
echo "vendor.sh: $(grep -v '^#' vendor.tsv | tail -n +2 | wc -l) files present and verified"
