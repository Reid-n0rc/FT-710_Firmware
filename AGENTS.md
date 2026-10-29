# AGENTS.md — FT-710 Firmware Analysis

Instructions for any agent (Claude, Codex, etc.) working in this repo. `CLAUDE.md` points here.

## Goals (in order)

1. Understand how the owner's Yaesu FT-710 works internally.
2. Find undocumented remote-control (CAT) commands and settings.
3. Eventually build custom firmware that extends the radio.

The first milestone is decoding every firmware image and committing Ghidra's decompiled output to `decomp/`.

## Ground rules

- **Analyze and plan before acting.** Before you change anything, read the task file, check what the previous tasks produced, and write your approach into the task file's `## Plan` section.
- **Tasks and sub-tasks.** A session may work through as many tasks and sub-tasks as needed, but plan first: write the approach into the task file before executing. Split any task that won't fit in one context window into sub-task files (`T13a`, `T13b`, ...), and add each one as a row on the board so it is tracked as a GitHub sub-issue. Finish, document and commit each (sub-)task before starting the next.
- **Record findings as you go.** Facts go in `docs/` (hardware, formats, memory maps). Status goes in the task file. Never leave a finding only in chat.
- **Repo visibility: public, by the owner's decision (2026-10-28).** The owner made `origin` public and said "Leave it public". The repo holds output derived from Yaesu's copyrighted firmware (`decomp/`, `hdl/sdr/`, the docs), which the owner accepts. Still never commit raw firmware, decoded binaries, manuals or Ghidra projects (`Firmware/`, `build/`, `Manuals/`, `ghidra/` stay gitignored), and never publish anything from this project anywhere other than `origin`, its wiki and its GitHub Pages site.
- **Git:** make incremental commits with clear messages. The owner has authorized pushing `main` to `origin` (github.com/Reid-n0rc/FT-710_Firmware) after commits, and the guide's generated pages (`tools/guide_to_wiki.py`) to its wiki (`FT-710_Firmware.wiki.git`). **GitHub Pages (owner's decision, 2026-10-28):** https://reid-n0rc.github.io/FT-710_Firmware/ is a landing page with the project highlights, pointing to the wiki, plus the CAT documents (`cat-undocumented.md`, `cat-commands.md`, `cat-commands-primary.md`) rendered from `docs/`. `site/` holds the landing page, layout and `build.py`, and `.github/workflows/pages.yml` deploys on every push to `main` that touches them. Edit the Markdown in `docs/`, never the generated pages. Never change the repo's visibility, and never tag, release, or push to any other remote.
- **Contributions (owner rule, 2026-10-28).** Anyone other than the repository owner or an admin must start every change with a GitHub issue and get it in through a pull request that links the issue (`Closes #N`). Nobody but the owner or an admin commits to `main` directly. This is enforced by the `main` branch ruleset (id 26043135, created 2026-10-28; the admin role bypasses it, and the owner holds that role) and the `issue-link` workflow; details in [CONTRIBUTING.md](CONTRIBUTING.md). Agents running with the owner's credentials (`gh` as Reid-n0rc) act as the owner.
- **Signed commits (owner rule, 2026-10-28): sign, but it is not enforced.** In the owner's container, the repo and the wiki clone sign with the SSH key `~/.ssh/ft710_signing_ed25519` (`gpg.format ssh`, `commit.gpgsign true`, repo-local config). The ruleset does not require signatures.
- **Don't touch the radio.** Anything that writes to the radio (flashing, EEPROM writes, untested CAT set-commands) needs the owner's explicit approval each time.

## Sources (not in git)

| Folder | Contents | Where to get it |
|---|---|---|
| `Firmware/` | `FT-710_{MAIN,DISPLAY,IFDSP,SDR}_V*.SFL` + update manual | https://yaesu.com/Files/BB2B47AE-1018-01AF-FAE48FDCB1919193/FT-710_Firmware_updata_202402.zip (unzip into `Firmware/`) |
| `Manuals/` | Operating manual, CAT manual, firmware update manual | https://yaesu.com/product-detail.aspx?Model=FT-710&CatName=HF%20Transceivers/Amplifiers ("Files" tab) |
| `Manuals/FT-710_CAT_OM_ENG_2306-C.pdf` | CAT manual, English rev 2306-C (current; the primary reference). yaesu.com resets connections from the Linux container, so the owner downloads it in a browser | https://www.yaesu.com/Files/4CB893D7-1018-01AF-FA97E9E9AD48B50C/FT-710_CAT_OM_ENG_2306-C.pdf |
| `Manuals/FT-710_CAT_OM_ENG_2211-A.pdf` | CAT manual, English rev 2211-A (older; still lists `EO`, and `VE` without a parameter) | https://www.simarud.no/files/simarud/Documents/FT-710_CAT_OM_ENG_2211-A.pdf |
| `Manuals/FT-710_CAT_OM_JPN_exseli.pdf`, `Manuals/FT-710_OM_JPN_exseli.pdf` | CAT manual (Japanese rev 2212-B) and operating manual (Japanese) | https://www.exseli.com/pdf/uploaded/manual_trn_809495519.pdf, https://www.exseli.com/pdf/uploaded/manual_trn_453178882.pdf |
| `Manuals/Renesas/` | Renesas RX651/RX65N hardware manual (r01uh0590), datasheet, handbook, RXv2 software manual (instruction set, r01us0071), technical updates | supplied by the owner (renesas.com) |
| `Manuals/FT-710_serv_2022.pdf` | Service manual / Technical Supplement (schematics, ICs) | https://www.radiomanual.info/schemi/YAESU_HF/FT-710_serv_2022.pdf |

By the owner's decision (2026-10-28), the PDFs in `Manuals/` and the three canonical Ghidra projects (`ghidra/FT710_{MAIN,DISPLAY,IFDSP}`) are committed. `Firmware/`, `build/` (decoded binaries), per-task Ghidra copies (`ghidra/FT710_*_T*`) and lock files stay gitignored. Close Ghidra before committing a project, and commit project changes together with the `decomp/` re-export they produce.

## Repo layout

```
AGENTS.md            this file
docs/
  hardware.md        CPUs, DSPs, FPGA, flash, buses per board (from service manual)
  sfl-format.md      .SFL container + payload encoding
  memory-maps.md     load addresses / memory maps per image
  cat-commands.md    documented vs firmware-discovered CAT commands
  custom-firmware.md feasibility of custom code/HDL: protections, recovery paths, toolchains, blockers
  getting-started.md newcomer manual: install, inputs, tools/bootstrap.sh, repo tour, conventions
  manuals.md         every manual/datasheet used, with source links (the PDFs are in Manuals/)
  inputs.sha256      SHA-256 of the firmware download and the decoded images (checked by bootstrap.sh)
  tasks/             one file per task; README.md is the index/status board
tools/               scripts (Python 3, stdlib preferred), catalogued in tools/README.md; bootstrap.sh rebuilds everything
decomp/<image>/      committed Ghidra decompiled C output per image
hdl/<image>/         hand-written HDL reconstructions (T15e)
build/               (ignored) decoded .bin images
ghidra/              canonical Ghidra projects FT710_{MAIN,DISPLAY,IFDSP} (committed; per-task copies ignored)
```

## Firmware images (package 2024-02)

| File | Header tag | Version | Date | Role (to confirm in T02) |
|---|---|---|---|---|
| FT-710_MAIN_V0112.SFL | MC | V01-12 | 2024-02-16 | Main CPU: control, CAT |
| FT-710_DISPLAY_V0108.SFL | PC | V01-08 | 2023-06-29 | Front-panel/display CPU |
| FT-710_IFDSP_V0101.SFL | ID | V01-01 | 2023-03-23 | IF DSP |
| FT-710_SDR_V0104.SFL | SR | V01-04 | 2023-03-24 | SDR unit (may include an FPGA bitstream) |

What we know so far about the SFL format: an ASCII `*` comment box, then one line with `<tag> <length> <hex checksum>`, then the payload. The payload is obfuscated by byte-wise subtraction of a fixed 43-byte key, with a salted CRC-32 in the header. It is fully decoded by `tools/sfl_decode.py` (T04). Full details live in `docs/sfl-format.md`.

## Tooling

- Ghidra 12.1.4 (Homebrew formula) + `openjdk@21`. Always run headless through `tools/ghidra-headless.sh`, which sets the JAVA_HOME Ghidra needs (the system default Java 11 won't work). Put projects under `ghidra/`. Details are in `docs/tooling.md`.
- Python 3 for the decoding tools. Run scripts that read firmware data with `python3 -I`.
- Record installed versions in `docs/tooling.md`.
- The owner authorizes installing community tooling (Ghidra extensions/processor modules, Homebrew/pip packages, source builds) when a task needs it. Prefer reputable sources, avoid sudo and system-wide default changes, and record each install (source, version, method, location) in `docs/tooling.md`.

## Task sizing

- One task has one clear deliverable that you can verify (a doc section, a script plus a test, or one image's decompile export).
- Never read a whole PDF or a whole decompile dump into context. Use `pdftotext` with page ranges, `grep`, and targeted reads.
- Process one firmware image per task. For huge output (decomp), commit it file by file and summarize it in docs. Don't paste it into chat.
- Finish each task with: the task file updated (status, findings, follow-ups), docs updated, and a local commit.

## Documentation standard (owner requirement)

The owner wants **full documentation of all the code**, with figures wherever they show how things connect. Raw decomp output alone is not a deliverable.

- Code documentation lives in `docs/code/<image>/` (`main`, `display`, `ifdsp`, `sdr`) plus `docs/code/system.md` for the whole radio.
- Each image has an `README.md` overview (purpose, boot flow, memory map summary, task/main-loop structure, subsystem list with links) and one page per subsystem (for example CAT parser, band/VFO control, SD/update loader, UI, inter-CPU link, audio path). Each subsystem page has function tables (address, Ghidra name, inferred name, purpose), data structures and globals.
- **Figures:** use Mermaid in Markdown (it renders on GitHub). Use `flowchart` for module and call structure, `sequenceDiagram` for protocols and boot/update flows, and `stateDiagram-v2` for modes. Every overview needs at least a block diagram and a boot/control-flow figure. Keep each figure readable (around 25 nodes or fewer); split it rather than cram.
- Mark each claim **[fact]** (seen in code/data, cite the address), **[inference]** or **[guess]**.
- When you name functions in Ghidra, keep the project as the source of truth, re-export `decomp/<image>/` with `tools/ghidra/ExportDecomp.java`, and use the same names in the docs.

## Issue tracking (owner requirement)

Every task is mirrored as a GitHub issue in the repo: epic #1, one issue per task, and sub-tasks (`T10a`...) as sub-issues of their parent. `docs/tasks/` stays the source of truth. After any change to the board or a task file's status/findings, the parent agent runs `python3 -I tools/issues_sync.py`. It updates titles, bodies and status labels, comments on status changes, closes done tasks, and keeps `docs/tasks/issues.json`, which is committed along with the change. Background task agents don't run it, because the parent does. When you split a task, add the sub-task rows to the board (`T10a`, `T10b`, ...) so the sync creates the sub-issues.

## Hardware use (owner rule, 2026-10-27 and 2026-10-28)

Always use the most the hardware will support ("always do the max the hardware will support").

**Ghidra/REA cap (owner rule, 2026-10-28, raised from 50 % to 75 % the same day, then cut to one job at a time because 3 jobs hung the host; overrides the "max" rule above for Ghidra and REA):** Ghidra and REA may use only about 75 % of the hardware, and must leave RAM headroom. Start every Ghidra headless or REA run through `tools/ghidra-cap.sh <reserve_mb> -- <command>`. It allows only 1 such job at a time machine-wide, pins it to 3/4 of the cores (`taskset`) at nice 10, sizes GC threads to the cap, and admits it through `memgate.py` with a 3 GB free-RAM margin. `tools/bootstrap.sh` already does this and defaults `JOBS` to 3/4 of `nproc`. All agents on the machine must share one `CAP_DIR` (default `~/.cache/ft710-ghidra-cap`) and one `MEMGATE_DIR`.

- **CPU:** for Ghidra, pass `-max-cpu $CAP_CPUS` (3/4 of `nproc`, exported by `ghidra-cap.sh`), never `$(nproc)`. REA's vitest takes `--maxWorkers` of 3/4 of `nproc` too. Other builds may use `-j$(nproc)`. Run independent agents in parallel, but their Ghidra/REA jobs queue for the single slot.
- **RAM:** `memgate.py` (called by `ghidra-cap.sh`) starts a job as soon as `MemAvailable` covers its reservation plus a 3 GB margin (`MEMGATE_SAFETY_MB`, default 3072). It counts the memory that jobs already running can still grow into, so a burst of starts can't over-commit. All agents on the machine must share one `MEMGATE_DIR` (default `~/.cache/ft710-memgate`).
- **Heap size:** pick the heap per image: 2 GB for DISPLAY and IFDSP, 3 GB for MAIN, via `GHIDRA_HEADLESS_MAXMEM` (never more than 3 GB). Reserve the heap plus about 700 MB. On the owner's container, `free` shows the whole Unraid host and there is no swap, so running out of memory kills processes instead of slowing them down.
- **Health log:** `ghidra-cap.sh` starts `tools/healthlog.py` beside every job. Every 10 s it records CPU, board, NVMe and GPU temperatures, fan speeds, CPU clock and thermal-throttle events, load, I/O wait, free RAM, major page faults per second (thrashing), OOM kills and the job's RSS. It also flags late samples (`GAP`, meaning the host stalled), matching kernel messages, and a previous log with no `END` line (the run was cut off by a hang or reset). Logs go to `$HEALTH_DIR` (default `~/.cache/ft710-health`), newest at `health-latest.log`, fsynced per line so they survive a reset. Set `HEALTH_LOG=0` to turn it off. After a hang, read the last lines of the cut-off log first.
- **Overrides:** override tool caps with command-line flags or environment variables, never by editing upstream config files that would land in commits.

## Watchdog / long-running work

- Give every long command a hard timeout. Ghidra headless runs take `-analysisTimeoutPerFile <sec>`, and the decompiler has a 60 s per-function limit inside `ExportDecomp.java`.
- Background agents write a heartbeat: append `<ISO time> <task> <step>` to `$HB_DIR/<task>` (the parent gives you `HB_DIR`) after each major step, at least every ~10 minutes of work. The parent's watchdog treats a heartbeat older than 30 minutes as stalled.
- If a tool or connection fails, retry with backoff before giving up. Record unrecoverable failures in the task file.
