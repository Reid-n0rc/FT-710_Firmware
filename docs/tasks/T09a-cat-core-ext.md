# T09a — CAT core, reply/AI path, extended + hidden commands

**Status:** in progress · **Parent:** [T09](T09-cat-commands.md) · **Depends on:** T05

## Goal
Document how MAIN receives, parses, dispatches and answers CAT commands, and recover every extended/hidden command.

## Deliverables
- `docs/code/main/cat.md`: parser/dispatch `flowchart`, request/reply `sequenceDiagram`, function table, data structures and globals.
- `docs/cat-commands.md`: extended table (`SP EO E8 E9 FD KT PE ZZ VE JP`) and SP sub-commands, each classified read-only vs set with risk notes; reply templates, error reply, AI path, per-port behaviour.

## Plan
1. Core: receive ring (0x11FEB/0x11FEC), port id byte, `cat_parse`, `cat_dispatch`, `cat_dispatch_ext`, reply buffer 0x1C8E + length 0x1B788, error `?;`, send by port (`FUN_fffb1d12`), AI flags and the post-command AI hook, APO reset.
2. The second input path in `cat_parse` (ring at `FUN_fffb1d06`, only `E9`), via disassembly.
3. Each extended handler and the SP sub-command helpers (`FUN_fffa4e31 4e8f 4eed 50f9 520b 5284`, `FUN_fffb0532`), checksum helpers, SDR binary bridge (`FUN_fffa3226`).
4. Templates 0xFFF8F480..0xFFF8F5E4 and the small string tables after `cat_ext_mnemonics`.
5. Write the docs; commit.

## Findings
_(fill in as you go)_

## Follow-ups
