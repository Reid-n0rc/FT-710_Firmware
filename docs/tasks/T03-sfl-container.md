# T03 — SFL container header

**Status:** todo · **Depends on:** —

## Goal
Fully specify the SFL file wrapper: the comment box, the tag/length/checksum line, and where the payload starts.

## Deliverables
- `docs/sfl-format.md` (container section).
- Verify: does the header length equal the file size or the payload size? Which checksum algorithm matches (sum32, CRC32 variants), and over which byte range?

## Notes / hints
- Each header line is CRLF-terminated. Tags seen: MC, PC, ID, SR. The length field seems to equal the file size (e.g. DISPLAY: 3325520), so check this.
- Also skim `Manuals/Firmware_Ver_Up_Manual_ENG_FT-710_2211-A.pdf` for update-process hints.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
