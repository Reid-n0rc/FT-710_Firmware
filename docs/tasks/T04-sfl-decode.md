# T04 — SFL payload decoding

**Status:** todo · **Depends on:** T03

## Goal
Recover the payload encoding, and write `tools/sfl_decode.py` to turn each SFL into a raw binary under `build/`.

## Deliverables
- `docs/sfl-format.md` (encoding section) explaining the method and how it was derived.
- `tools/sfl_decode.py` (stdlib only), usage: `python3 -I tools/sfl_decode.py Firmware/X.SFL build/X.bin`.
- Validate: the decoded output must show plausible code (a vector table, readable strings like CAT command mnemonics, version strings).

## Notes / hints
- Repeating 32-byte blocks in long runs suggest a fixed XOR keystream with period 32 (or a per-position substitution). Known-plaintext from erased flash (likely 0xFF or 0x00) should reveal the key. Test both.
- The keystream may differ per image, so check all four.
- Decoded binaries stay in `build/` (gitignored). Never commit them.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
