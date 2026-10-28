# Manuals and datasheets

Every manual and datasheet the project uses or cites, where to get it, and what it was used for. The 14 PDFs the project keeps are
**committed in `Manuals/`** (owner decision, 2026-10-28; Renesas files in `Manuals/Renesas/`), under the file names below, so the paths in
the docs work. The documents in the second list are cited but not kept; get them from the links. The SHA-256 values identify the exact revision the project read; a newer
revision from the vendor is fine for reading, but page numbers in the docs refer to these files.

Never read a whole PDF into an AI agent's context: use `pdftotext -f N -l M file.pdf -` for page ranges and `grep` (AGENTS.md).

## Yaesu FT-710

| File (in `Manuals/`) | What it is | Where to get it | Used for | SHA-256 |
|---|---|---|---|---|
| `FT-710_OM_ENG_EH080H201_2307N-GS.pdf` | Operating manual, English rev 2307N-GS | https://www.yaesu.com/Files/4CB893D7-1018-01AF-FA97E9E9AD48B50C/FT-710_OM_ENG_EH080H201_2307N-GS.pdf | SD-card save/load of memories and menus, front-panel resets: the backup steps in [cat-undocumented.md](cat-undocumented.md) | `e1afabe5f292c945d39e9e752b91dab1db2dccbb256c8f8a752c2fe5db4c61af` |
| `FT-710_CAT_OM_ENG_2306-C.pdf` | CAT Operation Reference Manual, English rev 2306-C (current) | https://www.yaesu.com/Files/4CB893D7-1018-01AF-FA97E9E9AD48B50C/FT-710_CAT_OM_ENG_2306-C.pdf (yaesu.com resets connections from some hosts; download it in a browser) | **The primary CAT reference.** "Documented" in [cat-commands.md](cat-commands.md) means listed in this revision; menu chart (Table 2) for `tools/main_menu_table.py` (T09, T10f) | `fdf62b8a5c89e321381d69c53292a6ded045f1ceeeaf04ae21ce856e8e2ff8c2` |
| `FT-710_CAT_OM_ENG_2211-A.pdf` | CAT manual, English rev 2211-A (older) | https://www.simarud.no/files/simarud/Documents/FT-710_CAT_OM_ENG_2211-A.pdf | Still lists `EO` and `VE` without a parameter; revision differences in [cat-commands.md](cat-commands.md) (T09) | `2b71bb61142186f4349f103d99aa439ce57202b16f00898a48c6ba266e7955c8` |
| `FT-710_CAT_OM_JPN_exseli.pdf` | CAT manual, Japanese rev 2212-B | https://www.exseli.com/pdf/uploaded/manual_trn_809495519.pdf | Cross-check of the English CAT tables (T09) | `173c3cb227df57bc953f49909dae12cece8ec07e847c56c682a25289418bd82f` |
| `FT-710_OM_JPN_exseli.pdf` | Operating manual, Japanese | https://www.exseli.com/pdf/uploaded/manual_trn_453178882.pdf | Menu items, front-panel behaviour, maintenance modes (T10f, T11) | `9808594792468719d654f0369e7c453992de3963d11e36de7019562c4c7b8fc7` |
| `FT-710_serv_2022.pdf` | Service manual / Technical Supplement 2022 (schematics, parts lists, block diagrams) | https://www.radiomanual.info/schemi/YAESU_HF/FT-710_serv_2022.pdf | **The hardware survey** ([hardware.md](hardware.md), T02): every CPU, DSP, FPGA, memory and bus; pin-level wiring for the GPIO, UART and SPI pages; debug header J1004 (T17) | `c257332cd85f74fec89954c608a3537ff1a6149cfc7d8ce34615db6c79c3f5c4` |
| `Firmware_Ver_Up_Manual_ENG_FT-710_2211-A.pdf` | Firmware update manual, English rev 2211-A | inside the firmware zip (see [getting-started.md](getting-started.md)); also on the yaesu.com FT-710 page, Files tab | The official SD-card update procedure behind [display/update.md](code/display/update.md) and the guide's chapter 3 (T11c, T19c) | `6880607aa210afad2989366610d3ba26d5cdc8a2781490945fd361a004677b57` |
| `FT-710_Test-Report_DC4KU_english.pdf` | Independent lab test report by Werner Schnorrenberg, DC4KU, 30 Oct 2022 (13 pages) | https://dc4ku.darc.de/FT-710_Test-Report_DC4KU_english.pdf | States the receiver is direct-sampling with a **dual-channel 14-bit ADC** (the same twin ADC as the FT-DX10) whose two channels the FPGA combines, with dither into both inputs; settles O7 together with p6 of the service manual (T20 follow-up) | `b924e181b5c31f39037ac9e07cf6d1236264126236e5c6ca6e1fb217983bf24a` |

The other language editions and Yaesu documents are on the FT-710 product page:
https://yaesu.com/product-detail.aspx?Model=FT-710&CatName=HF%20Transceivers/Amplifiers (Files tab).

## Renesas RX651 (MAIN CPU, R5F56514ADFB)

Supplied by the owner from renesas.com (search the document number on https://www.renesas.com, product page
https://www.renesas.com/en/products/rx651). Checked against the docs in T17 and T18.

| File (in `Manuals/Renesas/`) | Document | Used for | SHA-256 |
|---|---|---|---|
| `r01uh0590ej0240-rx651.pdf` | RX651/RX65N Group User's Manual: Hardware, R01UH0590EJ0240 Rev.2.40 | Clocks (§9), ICU and vector table (§15, Table 15.3/15.5), I/O registers, SCI, TPU, S12AD, memory map (Figure 4.1); every `[fact: RX651 HWM ...]` in [code/main/](code/main/README.md) and [memory-maps.md](memory-maps.md) (T17, T18) | `e064d8ef981c63229db77072f9c25f093636a2360e53833f6cbbcf7a6dd0d205` |
| `r01ds0276ej0240-rx651.pdf` | RX651 Group Datasheet, R01DS0276EJ0240 Rev.2.40 | Part number decode: 512 KB code flash, 256 KB RAM, **no data flash**, 144-pin LFQFP (Table 1.2, 1.3) (T18) | `74f4287fc310762cbe2ef047fccfe3a2e5a25793669dfc53b481cf840a7b6c80` |
| `REN_r01us0071ej0100_rxv2sm_MAS_20131112_1.pdf` | RX Family RXv2 Instruction Set Architecture, Software manual R01US0071EJ0100 | The T17 SLEIGH fix (`tools/ghidra/rx62t-movu-fix.patch`): `MOVU` format (2) pp. 124/259, `SCMPU`/`SUNTIL`/`SWHILE` pp. 184–198 | `c12fc8d16adf1530f2cad3f75974d2a29062580a984a71fd9461417b66bba18a` |
| `r01tb0140ej0100-rx651-handbook.pdf` | RX651 Group handbook, R01TB0140EJ0100 | Background for T18's check of the peripheral pages | `57a84f524b35ae9b53f726469e261d89689bca1f078ec2de6977eb85cba6217f` |
| `REN_tnrxa0267ae.pdf_TCU_20230628_1.pdf` | Technical update TN-RX*-A0267A | Errata check (T18) | `36d7a942637972e5ada8713e243467408888560a9f23ad38d0f49550510eda2a` |
| `REN_tnrxa0276be.pdf_TCU_20240531_1.pdf` | Technical update TN-RX*-A0276B | Errata check (T18) | `dbe4afc88e9fc9d230ab752bad7d3f2f55ec4bb95c8ba921f4caf76ad58d27ca` |
| `REN_tnrxa0280ae.pdf_TCU_20240903.pdf` | Technical update TN-RX*-A0280A | Deletes the RCKSEL write in the clock setup ([main/peripherals.md](code/main/peripherals.md)) (T18) | `eb68ff4dd7a7c52c61e92f046988b303f2ecf6737179a85e6d72377fc8667396` |
| `REN_tnrxa0291ae.pdf_TCU_20251215.pdf` | Technical update TN-RX*-A0291A | Errata check (T18) | `bc1d3683348beea72e75b79ad6262472f6ce22fbc54f22c2f6acfbe676f5c240` |

## Cited but not in `Manuals/` (read online or from general knowledge)

These are cited in the docs for register meanings, formats or encodings. The project did not keep a copy, so claims that rest on them
are tagged **[inference]** unless the code confirms them. Getting a copy and checking those claims is open work
([T20-open-issues.md](tasks/T20-open-issues.md)).

| Part / document | Vendor (where to get it) | Used for |
|---|---|---|
| **RZ/A1H** Group User's Manual: Hardware (R01UH0403EJ) | Renesas, https://www.renesas.com (search "RZ/A1H hardware manual") | DISPLAY register names, STBCR bits, INTC IDs, SCIF/RSPI/RIIC/VDC5/SPIBSC ([code/display/](code/display/README.md)). The address-map chapter is needed for open item O9 (what 0x60000000 decodes to) |
| **i.MX RT600** (RT685) reference manual UM11147 and datasheet | NXP, https://www.nxp.com (search "RT685"; the reference manual needs a free account) | IFDSP memory map, boot ROM / FlexSPI boot header, PLL formula, FLEXCOMM/MU/DMA request map ([code/ifdsp/](code/ifdsp/README.md), [memory-maps.md](memory-maps.md)) |
| **UG470** 7 Series FPGAs Configuration User Guide | AMD/Xilinx, https://docs.amd.com/v/u/en-US/ug470_7Series_Config | Bitstream packets, registers, frame/ECC layout, XC7A50T length and IDCODE ([decomp/sdr/README.md](../decomp/sdr/README.md), [code/sdr/bitstream.md](code/sdr/bitstream.md)) |
| **UG473** 7 Series FPGAs Memory Resources | AMD/Xilinx, https://docs.amd.com/v/u/en-US/ug473_7Series_Memory_Resources | BRAM widths and parity layout ([code/sdr/bram-tables.md](code/sdr/bram-tables.md)) |
| **UG474** 7 Series FPGAs CLB User Guide | AMD/Xilinx, https://docs.amd.com/v/u/en-US/ug474_7Series_CLB | SLICE model, LUT/MUXF7/CARRY4 ([code/sdr/netlist.md](code/sdr/netlist.md)) |
| **XAPP888** MMCM and PLL Dynamic Reconfiguration | AMD/Xilinx, https://docs.amd.com/v/u/en-US/xapp888_7Series_DynamicRecon | MMCM divider encoding ([code/sdr/resources.md](code/sdr/resources.md), [netlist.md](code/sdr/netlist.md)) |
| Project X-Ray documentation and database | https://github.com/f4pga/prjxray, https://github.com/f4pga/prjxray-db | Frame/tile/bit mapping behind every `xc7_*` tool (pinned commits in [tooling.md](tooling.md)) |
| **TLV320AIC3204** audio codec datasheet | TI, https://www.ti.com/product/TLV320AIC3204 | Register meanings of the 67-entry `aic3204_init` table ([ifdsp/control-link.md](code/ifdsp/control-link.md)) |
| **TSC2003** / **TSC2007** touch controller datasheets | TI, https://www.ti.com/product/TSC2003, https://www.ti.com/product/TSC2007 | DISPLAY touch driver (the code calls it `tsc2007`; the parts list has a TSC2003) ([display/input.md](code/display/input.md)) |
| **S-35190A** 3-wire RTC datasheet | ABLIC, https://www.ablic.com (search "S-35190A") | DISPLAY RTC command bytes ([display/peripherals.md](code/display/peripherals.md)) |
| **BR25G256** SPI EEPROM datasheet | ROHM, https://www.rohm.com/products/memory/serial-eeprom/spi-bus/br25g256fj-3-product | MAIN settings EEPROM: 32 KB, 64-byte pages, RDSR/WREN/WRITE ([main/eeprom.md](code/main/eeprom.md)) |
| **W25Q128** SPI NOR flash datasheet | Winbond, https://www.winbond.com (search "W25Q128JV") | DISPLAY boot flash layout, SDR config flash commands ([display/update.md](code/display/update.md)) |
| Cadence Xtensa / HiFi4 ISA and the RT600 core overlay | via the Zephyr SDK 0.17.0 toolchain (https://github.com/zephyrproject-rtos/sdk-ng/releases/tag/v0.17.0) | FLIX-aware HiFi4 disassembly ([ifdsp/hifi4.md](code/ifdsp/hifi4.md), [tooling.md](tooling.md)) |

The USB parts on the MAIN unit (CY7C65631 hub, CP2105 dual UART, CM119B audio, FT4222H) are identified from the service manual only; no
datasheet was needed so far.
