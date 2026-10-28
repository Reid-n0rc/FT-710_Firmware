# Contributing

Thanks for helping. This project reverse-engineers the Yaesu FT-710's firmware: see the [illustrated guide](docs/guide/README.md) for the
big picture and [docs/getting-started.md](docs/getting-started.md) to set up a working copy.

## How changes get in

```mermaid
flowchart LR
  I["1. Open an issue<br/>(template)"] --> F["2. Fork or branch"]
  F --> C["3. Commit on your branch"]
  C --> P["4. Pull request<br/>'Closes #N'"]
  P --> K{"issue-link check<br/>+ owner review"}
  K -->|pass| M["5. Merged to main"]
  K -->|changes asked| C
```

1. **Every change starts with an issue.** Open one with a template (correction, new analysis or tool, question) before you write code
   or docs. Say what you want to change and the evidence for it.
2. **Every commit goes through a pull request.** Nobody pushes to `main` directly, except the repository owner and admins. Work on a
   branch (or a fork) and open a pull request.
3. **Link the issue in the PR description** with a closing keyword: `Closes #12`, `Fixes #12` or `Resolves #12`. The `issue-link`
   check fails without it.
4. **Review.** The repository owner reviews every pull request (`.github/CODEOWNERS`). Answer the review on the same branch.

The repository owner and admins may commit to `main` directly (the branch ruleset lets them bypass it). That includes AI agents working
on the owner's behalf with the owner's credentials.

## What a good change looks like

Read [AGENTS.md](AGENTS.md): it is the rule book for humans and AI agents alike. In short:

- **Evidence tags.** Mark claims **[fact]** (seen in code or data, with the address), **[inference]** or **[guess]**.
- **Figures.** Use Mermaid in Markdown, about 25 nodes or fewer, and hand-written SVG in `docs/guide/img/` for the guide.
- **Ghidra names.** Keep the names files in `tools/ghidra/` as the source of truth, and re-export `decomp/<image>/` with
  `tools/ghidra/ExportDecomp.java` when names change.
- **Don't commit third-party files.** Yaesu's firmware (`Firmware/`), decoded images (`build/`), manuals (`Manuals/`) and Ghidra projects
  (`ghidra/`) are gitignored. They are rebuilt from the official downloads by [tools/bootstrap.sh](tools/bootstrap.sh). Never force-add
  them.
- **Don't touch someone's radio without asking.** Anything that writes to a radio (flashing, EEPROM writes, untested CAT set-commands,
  JTAG loads) needs that radio owner's explicit approval each time. Read the risk ladder in chapter 8 of the guide first.
- **Licence conditions.** Changes that affect transmit (power, band limits, the TX path) must keep the radio within its operator's
  licence.
