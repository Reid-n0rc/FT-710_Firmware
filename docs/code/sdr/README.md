# SDR module image (SR) — code documentation

**Image:** `FT-710_SDR_V0104.SFL` (tag SR, V01-04, 2023-03-24), decoded to `build/FT-710_SDR_V0104.bin`.
**What it is:** a Xilinx Artix-7 **XC7A50T** configuration bitstream (uncompressed, unencrypted, master-SPI x4 boot)
behind a 4 KiB header whose first word is a CRC-32/BZIP2 of the bitstream **[fact]** (T08). **There is no CPU code and
no soft CPU** **[inference, high]**, so there are no functions to name and `decomp/sdr/` holds only a summary.
The "code" documented here is the FPGA design, at the level of placed resources, configured features and block-RAM
contents (T13).

## Pages

| Page | Contents |
|---|---|
| [bitstream.md](bitstream.md) | Image layout, FAR/frame map verified against prjxray (5,420 frames), bit addressing |
| [bram-tables.md](bram-tables.md) | BRAM modes, RAMB36 bit order, catalogue of all 35 initialized memories, MicroBlaze verdict |
| [resources.md](resources.md) | LUT/FF/DSP/BRAM use, 2 MMCMs and their dividers, LVDS/single-ended I/O counts, special blocks |
| [interfaces.md](interfaces.md) | J2002 60-pin map (service manual p19), data-path figure, config/update sequence, open questions |
| [`decomp/sdr/README.md`](../../../decomp/sdr/README.md) | T08: packet stream, leading CRC word, first BRAM evidence |

Tools: `tools/xbit_parse.py` (packets, CRCs), `tools/xc7_db.py` (prjxray mapping: `frames`, `bram`, `bramcfg`,
`usage`, `sites`, `config`, `tilebits`), `tools/xc7_bram_tables.py` (logical BRAM tables, `selftest`). They need the
prjxray-db checkout described in [`docs/tooling.md`](../../tooling.md).

## Key findings

- The FPGA is nearly full: about 26,600 LUTs (82 %), 31,400 FFs (48 %), **119 of 120 DSP48E1** (all fully pipelined),
  70 of 75 RAMB36 sites, 2 MMCMs **[fact for counts]**. ([resources.md](resources.md))
- Block RAM holds **DSP tables only**: an exact 0.5-degree cosine (720 per cycle, 16-bit), an exact 720-step
  raised-cosine ramp, six symmetric low-pass FIRs with 36-bit coefficients, a 1024-tap symmetric filter, quadratic
  ("chirp") and product ("twiddle") phase tables, four of them replicated x4 **[fact for the shapes]**.
  ([bram-tables.md](bram-tables.md))
- I/O: about 9 LVDS input pairs (ADC) and 9 LVDS output pairs (DAC?) plus ~66 single-ended pins **[inference]**.
- J2002: the DISPLAY's SDR SPI goes to the module's **FFT/scope data port**, and MAIN's `SDR_UPDATE` drives the module
  pin labelled **WP** (flash write-protect) **[fact, p19]**; so the FPGA most likely reprograms its own config flash
  during an update **[inference]**. ([interfaces.md](interfaces.md))

## Block diagram

```mermaid
flowchart LR
  subgraph MOD["SDR module"]
    ADC["ADC (unknown part)<br/>~250 MSPS"]
    Q["QSPI config flash<br/>WP = SDR_UPDATE"]
    subgraph F["XC7A50T"]
      DDC["RX DDC<br/>NCO + FIR bank<br/>DSP48 x ~119"]
      SC["scope / FFT<br/>phase tables x4"]
      TX["TX path<br/>keying ramp"]
      CR["control UART<br/>+ debug UART"]
      CK["2 x MMCM"]
    end
    DAC["TX DAC? (unknown)"]
  end
  ADC -- LVDS --> DDC
  ADC -- LVDS --> SC
  TX -- LVDS --> DAC
  Q -- "SPI x4 boot" --> F
  DDC -- "I2S RX_IF" --> RT["RT685 IF DSP"]
  RT -- "I2S TX_AF" --> TX
  CK -- DSP_CLK --> RT
  SC -- "SPI FFT/FRM" --> DI["DISPLAY RZ/A1H"]
  MA["MAIN RX651"] -- "UART5, TX/SEND/FSK,<br/>SDR_UPDATE, SDR_RESET" --> CR
```

Blocks inside the FPGA are **[inference]** from BRAM contents, DSP/IO counts and the J2002 signal names; routing is not
decoded. Connector signals are **[fact]** (service manual p19, [interfaces.md](interfaces.md)).

## Boot / configuration flow

```mermaid
sequenceDiagram
  participant M as MAIN RX651
  participant Q as QSPI flash
  participant F as XC7A50T
  participant R as RT685 / DISPLAY
  Note over F: power-on, PROGRAM_B released (SDR_RESET high) [inference]
  F->>Q: master SPI x4 read, opcode 0x6B, address 0 [fact: BSPI 0x26B]
  Q-->>F: 4 KiB header (skipped, no sync) + bitstream
  F->>F: IDCODE check 0x0362C093, 5,420 frames, CRC ok [fact]
  F->>F: startup: GTS/GWE/DONE cycles 4/5/3 (COR0) [fact]
  F-->>R: DSP_CLK, I2S RX_IF, scope SPI [inference]
  M->>F: UART5: version query, settings [inference]
```

For the update sequence (SD card to flash) see [interfaces.md](interfaces.md#configuration-and-update-sequence).

## Subsystems

| Subsystem | Evidence | Page |
|---|---|---|
| Configuration / boot | packet stream, BSPI, header CRC | [bitstream.md](bitstream.md), T08 |
| RX down-conversion (NCO + filters) | cosine table, FIR bank, 119 DSP48 | [bram-tables.md](bram-tables.md), [resources.md](resources.md) |
| Scope / FFT | x4 phase tables, twiddle table, FFT SPI port | [bram-tables.md](bram-tables.md), [interfaces.md](interfaces.md) |
| TX path | raised-cosine ramp, TX_AF I2S, LVDS outputs | [bram-tables.md](bram-tables.md), [interfaces.md](interfaces.md) |
| Control / debug | UART5 to MAIN, UART_DBG, JTAG J2001 | [interfaces.md](interfaces.md) |
| Clocking | 2 MMCMs, 125 MHz fabric (p6) | [resources.md](resources.md#clocking) |
