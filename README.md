# FT-710_Firmware

A private analysis of the Yaesu FT-710 firmware, done for the owner's own radio. The goals are to understand the radio, find undocumented CAT commands, and eventually build custom firmware.

**Agents and contributors: start with [AGENTS.md](AGENTS.md).** The task board is in [docs/tasks/README.md](docs/tasks/README.md).

## Getting the inputs (not stored in this repo)

- **Firmware:** download https://yaesu.com/Files/BB2B47AE-1018-01AF-FAE48FDCB1919193/FT-710_Firmware_updata_202402.zip and unzip it into `Firmware/`.
- **Manuals:** get them from https://yaesu.com/product-detail.aspx?Model=FT-710&CatName=HF%20Transceivers/Amplifiers (Files tab) and save them into `Manuals/`.
- **Service manual (Technical Supplement):** download https://www.radiomanual.info/schemi/YAESU_HF/FT-710_serv_2022.pdf into `Manuals/`.

`Firmware/` and `Manuals/` are gitignored and must never be committed.
