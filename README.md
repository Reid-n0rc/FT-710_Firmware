# FT-710_Firmware

An analysis of the Yaesu FT-710 firmware. The goals are to understand the radio, find undocumented CAT commands, and eventually build custom firmware.

**Agents and contributors: start with [AGENTS.md](AGENTS.md).** The task board is in [docs/tasks/README.md](docs/tasks/README.md).

## New here? Read the illustrated guide

**[docs/guide/README.md](docs/guide/README.md)** explains the whole radio in plain language, in one document with a table of contents,
74 pictures and diagrams, and a glossary. The project's website, **https://reid-n0rc.github.io/FT-710_Firmware/**, has the highlights and the undocumented CAT command
documentation. The guide is also published as the [wiki](https://github.com/Reid-n0rc/FT-710_Firmware/wiki), one page per
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

## Getting started: rebuild everything from the official downloads

**[docs/getting-started.md](docs/getting-started.md)** is the manual for newcomers: prerequisites per OS, getting the inputs, the
bootstrap, a tour of the repo, Ghidra (and optionally REA), the conventions and how to contribute. In short:

```sh
mkdir -p Firmware && curl -fL -o Firmware/FT-710_Firmware_updata_202402.zip \
  https://yaesu.com/Files/BB2B47AE-1018-01AF-FAE48FDCB1919193/FT-710_Firmware_updata_202402.zip
tools/bootstrap.sh            # decode, build the Ghidra projects with every name, re-export, diff against decomp/
```

The manuals (`Manuals/`) and the three canonical Ghidra projects (`ghidra/`) are in the repo. Only Yaesu's firmware download (`Firmware/`)
and the decoded images (`build/`) are fetched and rebuilt locally; `tools/bootstrap.sh` reproduces them byte for byte (hashes in
[docs/inputs.sha256](docs/inputs.sha256)) and can also rebuild the Ghidra projects from scratch. Full instructions:
[docs/getting-started.md](docs/getting-started.md). The manuals and datasheets, with their sources, are listed in
[docs/manuals.md](docs/manuals.md); the scripts in [tools/README.md](tools/README.md). Open questions are GitHub issues (see
[CONTRIBUTING.md](CONTRIBUTING.md)).
