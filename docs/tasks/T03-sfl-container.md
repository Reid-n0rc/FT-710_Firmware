# T03 — SFL container header

**Status:** done (checksum algorithm deferred to T04) · **Depends on:** —

## Goal
Fully specify the SFL file wrapper: the comment box, the tag/length/checksum line, and where the payload starts.

## Deliverables
- `docs/sfl-format.md` (container section).
- Verify: does the header length equal the file size or the payload size? Which checksum algorithm matches (sum32, CRC32 variants), and over which byte range?

## Notes / hints
- Each header line is CRLF-terminated. Tags seen: MC, PC, ID, SR. The length field seems to equal the file size (e.g. DISPLAY: 3325520), so check this.
- Also skim `Manuals/Firmware_Ver_Up_Manual_ENG_FT-710_2211-A.pdf` for update-process hints.

## Plan
1. Dump the ASCII header of each SFL. Measure the line lengths and the exact offset where the payload starts.
2. Compare the length field with the file size and the payload size.
3. Brute-force the common 32-bit checksum/CRC variants over the plausible byte ranges (scratchpad script).
4. Grep the update manual for process hints.
5. Write `tools/sfl_header.py` (parser + length check) and `docs/sfl-format.md` (container section).

## Findings
- Fixed layout: a 512-byte comment box (8 x 64-byte lines), a 64-byte tag line, and the payload at **0x240** in all four files. Details are in `docs/sfl-format.md`.
- The length field = **total file size** (all four verified).
- The checksum does **not** match any CRC-32 variant (7 polys, all init/ref/xorout combos) or any 8/16/32-bit sum over any encoded byte range we tried. Most likely it covers the decoded payload, so it is retested in T04.
- The payload lengths are not block-aligned (SDR isn't even 4-aligned), so the encoding is byte-granular.
- Updates come from an SD card via the DISPLAY CPU, which then forwards MAIN/DSP/SDR. The DISPLAY image holds the decoder and checksum code.
- `tools/sfl_header.py` parses and validates all four headers (exit 0).

## Follow-ups
- T04: test the checksum against the decoded payload (repeat the brute-force set from docs/sfl-format.md).
- T04 fallback: once DISPLAY is decoded, find the SFL loader (look for "SFL", the tags "MC"/"ID"/"SR", and SD/FAT code) to confirm the checksum algorithm.
