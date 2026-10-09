# T09 — CAT command recovery

**Status:** todo · **Depends on:** T05

## Goal
Recover the full CAT command table from MAIN and diff it against the CAT manual to find undocumented commands.

## Deliverables
- `docs/cat-commands.md`: a table of every command the firmware accepts, with documented yes/no, parameters, handler address, and the inferred behaviour.
- For undocumented commands: classify each as read-only or set, and note any risk.

## Notes / hints
- Source of documented commands: `Manuals/FT-710_CAT_OM_ENG_2306-C.pdf`. Extract the command list to a temp file and don't load the whole manual into context.
- Look for a table of 2-letter mnemonics (e.g. "FA","FB","MD"...) with function pointers.
- **Don't send any undocumented command to the radio** without the owner's explicit approval.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
