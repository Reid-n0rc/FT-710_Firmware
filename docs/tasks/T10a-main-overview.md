# T10a — MAIN overview, boot, main loop and memory map

**Status:** done · **Depends on:** T05 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): README.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10a.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
Overview per the documentation standard: purpose, reset/boot flow (reset handler 0xFFF8FBDB, `app_main` 0xFFF94AFA, power-off CAT loop), `main_loop` 0xFFF94B8B task list (~16 polled tasks), memory map summary, block diagram, interrupt/vector summary, subsystem index linking every T10 page and `cat.md`.

## Plan
1. Read the boot chain from the committed decomp (`PowerON_Reset` → `hw_init_clock`, `_INITSCT`, BSP init helpers → `main` →
   `app_main`) and classify every callee of `app_main` (init + power-off loop) and of `main_loop` (16 polled tasks) by
   reading each function and its callees, peripheral registers and globals (decomp first, Ghidra copy `FT710_MAIN_T10a`
   for xrefs only if needed).
2. Summarize the relocatable vector table (0xFFF8E6DC): which vectors have real handlers vs. the default
   `Undefined_0xD8`, and the timer tick that drives the soft timers.
3. Write `docs/code/main/README.md`: purpose, block diagram, boot sequence figure, power-off loop, main-loop table,
   memory map summary (link `docs/memory-maps.md`), interrupt summary, subsystem index linking `cat.md` and the planned
   T10b–T10h pages, function table, globals.
4. Propose names for the boot/main-loop functions in `tools/ghidra/names_main.T10a.tsv`, kept consistent with the
   subsystem owners (prefer leaving the task functions' subsystem-internal names to them; mark mine as proposals).
5. Update this file (findings, follow-ups), commit.

## Findings
Page: [docs/code/main/README.md](../code/main/README.md). Proposed names: 75 in `tools/ghidra/names_main.T10a.tsv`.
- **Boot** [fact]: `PowerON_Reset` → `hw_init_clock`, `_INITSCT`, BSP callback tables (0x1FFC4, 0x20194 = FIT_NO_FUNC),
  ICU selectable-source init 0xFFF92014, `hardware_setup` 0xFFF8F7EC → `R_Systeminit` 0xFFF8F65E (all peripheral
  Create calls + 17 callback registrations) → `main` → `app_main`.
- **app_main** [fact]: timers/TPU start, EEPROM WRSR, `settings_load` 0xFFFB0229 (3-way on header byte 0x4658),
  SCI start, then the **power-off loop** (`display_link_task` 0xFFF94D6F + `cat_parse` + IWDT kick) until 0x20B3A = 1,
  then 12 init calls and `main_loop`.
- **Power on/off** [fact; handshake inference]: `PS1` only requests power-on (0x20B9C); 0x20B3A is set by DISPLAY frame
  0xF0 (`FUN_fff9546a`, also stores the DISPLAY version). Power-off (power key 0x300 / CAT PS0 / low supply ADC
  0x20B08 < 0x7DD) saves the EEPROM and ends in a **software reset** (`FUN_fffb3e55`: SWRR = 0xA501).
- **main_loop** 0xFFF94B8B: 16 tasks, each identified by role (watchdog, TX/RX+power, SDR link, DSP link, port control,
  tone, CAT, ladder keys, scan, two DISPLAY-request tasks, keyer, an unknown 0x15DE3 task, DISPLAY link, event
  dispatcher, tuner). Most init/poll functions come in pairs (`*_init` in app_main, `*_task` in main_loop).
- **Soft timers** [fact]: 75 one-shot timers (`sw_timer_start(id, ms)` → ms × 10 ticks) on TPU0 = 100 µs (TCR 0x2A,
  TGRA 0x176 at PCLK 60 MHz), 2 on/off timers, 4 slow timers on TPU3 (100 ms, inference).
- **Vectors** [fact]: 31 of 256 relocatable vectors populated; the selectable ones map to TPU0/1/2/3 TGIA and
  S12ADI0/1 (source numbers from `icu_select_init`, decode inference). TPU1 + DAC = tone generator (36 samples/cycle).
- **Global state block 0x20B04** [fact]: eleven `.data` pointer constants (0x25D38, 0x25D4C … 0x25D7C) all point to
  0x20B04, so `PTR_DAT_00025d38[0x36]` == `DAT_00020b3a`. Search both forms when tracing a field.
- **Event handler table 0xFFF89D94** [fact]: indexed by event code 0x1FA40 in `FUN_fffbc35f` (`event_task`), so the
  T05 "large code-pointer table" is the key/event → handler table.

## Follow-ups
- Purpose of main-loop tasks 10/11 (DISPLAY frames 0xE7/0xE8 → 0x20F8C/0x20F90), 13 (`FUN_fffd0582`, 0x15DE3) and of
  TPU2 / vector 138 (port pulse train) — for T10b/T10g/T10h.
- Cross-check the power-on handshake (PS1 → 0x20B9C, frame 0xF0) with the DISPLAY side (T11b).
- After the rename pass, switch the README's italic proposals to the applied names.

## Proposed shared-file edits
- `docs/memory-maps.md` (MAIN section): add a short "Global state block 0x20B04" note (eleven pointer constants at
  0x25D38..0x25D7C → 0x20B04; `PTR_DAT_00025d38[off]` == 0x20B04 + off) and a link to `code/main/README.md`.
- `docs/memory-maps.md` MAIN map row 0xFFF80000..: describe 0xFFF89D94 as "event handler table (indexed by event code)".
- `decomp/main/INDEX.md` (on re-export): boot section → link `docs/code/main/README.md`; replace "~16 polled tasks"
  with "16 polled tasks".
- `docs/code/main/cat.md` header: `README.md` is no longer TODO.
