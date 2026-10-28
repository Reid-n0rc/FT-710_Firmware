# FT-710_Firmware

An analysis of the Yaesu FT-710 firmware, done for the owner's own radio. The goals are to understand the radio, find undocumented CAT commands, and eventually build custom firmware.

**Agents and contributors: start with [AGENTS.md](AGENTS.md).** The task board is in [docs/tasks/README.md](docs/tasks/README.md).

## New here? Read the illustrated guide

**[docs/guide/README.md](docs/guide/README.md)** explains the whole radio in plain language, in one document with a table of contents,
74 pictures and diagrams, and a glossary. It is also published as the [wiki](https://github.com/Reid-n0rc/FT-710_Firmware/wiki), one page per
chapter. Start there; the reference pages below hold the detail and the evidence.

## How the radio is built

The FT-710 runs four firmware images on four devices. The DISPLAY CPU owns the front panel and the SD card, wakes the MAIN CPU and updates
every other image. The MAIN CPU owns the radio state and CAT, and drives the SDR FPGA and the IF DSP over register-style UART links. Start with
**[docs/code/system.md](docs/code/system.md)**: block diagrams, the inter-CPU protocols, and the power-on, update, CAT, tuning, transmit and
scope flows across all four images.

| Image (SFL tag) | Device | Role | Code documentation |
|---|---|---|---|
| MAIN (`MC`) | Renesas RX651, MAIN unit | control CPU: radio state, CAT, EEPROM, TX/RX sequencing, links to the other CPUs | [docs/code/main/README.md](docs/code/main/README.md) |
| DISPLAY (`PC`) | Renesas RZ/A1H, DISPLAY unit | touch GUI, keys and encoders, SD card, firmware updates, USB scope stream | [docs/code/display/README.md](docs/code/display/README.md) |
| IFDSP (`ID`) | NXP i.MX RT685 (Cortex-M33 + HiFi4), MAIN unit | IF/AF signal processing, codec | [docs/code/ifdsp/README.md](docs/code/ifdsp/README.md) |
| SDR (`SR`) | Xilinx Artix-7 XC7A50T, SDR module | ADC, down-/up-conversion, scope data (bitstream, no CPU) | [docs/code/sdr/README.md](docs/code/sdr/README.md) |

Other references: [hardware survey](docs/hardware.md), [memory maps](docs/memory-maps.md), [CAT commands](docs/cat-commands.md),
[SFL file format](docs/sfl-format.md), [custom-firmware feasibility](docs/custom-firmware.md), [tooling](docs/tooling.md).
Decompiled code is in `decomp/<image>/`.

## Getting the inputs (not stored in this repo)

- **Firmware:** download https://yaesu.com/Files/BB2B47AE-1018-01AF-FAE48FDCB1919193/FT-710_Firmware_updata_202402.zip and unzip it into `Firmware/`.
- **Manuals:** get them from https://yaesu.com/product-detail.aspx?Model=FT-710&CatName=HF%20Transceivers/Amplifiers (Files tab) and save them into `Manuals/`.
- **Service manual (Technical Supplement):** download https://www.radiomanual.info/schemi/YAESU_HF/FT-710_serv_2022.pdf into `Manuals/`.

`Firmware/` and `Manuals/` are gitignored and must never be committed.
