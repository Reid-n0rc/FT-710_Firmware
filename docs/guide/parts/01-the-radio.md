## 1. The radio at a glance

**In short.** The FT-710 is not one computer but four. A Renesas RX651 on the MAIN unit is the boss: it keeps the radio's state and answers
[CAT](#glossary) commands. A Renesas RZ/A1H on the DISPLAY unit runs the touch screen, the knobs and the SD card. An NXP i.MX RT685 does
the audio [DSP](#glossary). A Xilinx Artix-7 [FPGA](#glossary) on a plug-in [SDR](#glossary) module turns the antenna signal into numbers
and back. Each of the four gets its own firmware file. This chapter shows where these chips sit and what each one does. It then follows a
signal from the antenna to the speaker and from the microphone back to the antenna, and ends with what the PC sees on the USB port.

### 1.1 The boards and where the chips sit

![Sketch of the FT-710 units: DISPLAY unit on top, MAIN unit with the plug-in SDR module, PA unit and JACK unit](img/01-units.svg)

*Figure 1.1 — The units of the FT-710 and the four programmable chips (coloured). The placement is a sketch, not the real board layout.*

Yaesu's service manual lists four boards: **MAIN**, **PA**, **DISPLAY** and **JACK**. A fifth part, the **SDR module**, plugs into the
MAIN unit through two connectors: a 60-pin board-to-board connector for the digital signals and a small one for RF. The manual draws the
SDR module only as a box. None of its parts are in the parts list, so everything we know about its insides comes from its firmware.

- The **DISPLAY unit** is the front panel. It holds the RZ/A1H, a 16 MB [SPI](#glossary) flash with the DISPLAY program, the SD card
  slot, the touch controller, the keys and encoders, a clock chip with a backup battery, and an FT4222H USB bridge.
- The **MAIN unit** holds most of the radio. The RX651 sits here with its settings [EEPROM](#glossary). So do the RT685 with its own
  16 MB [QSPI](#glossary) flash and the audio [codec](#glossary), the receive front end, the USB hub and its chips, and the DVI/HDMI output.
  The SDR module, with its fast ADC, the FPGA and the FPGA's own flash chip, plugs in here.
- The **PA unit** has the power amplifier and no processor. Shift registers, a small DAC and some sensors let the MAIN CPU control it
  over a serial bus.
- The **JACK unit** carries the front phones and mic jacks and has no processor either.

A ribbon cable joins the DISPLAY unit to the MAIN unit. It carries one [UART](#glossary), two SPI links, power and the wires that let the
DISPLAY reset the MAIN CPU and put it into its boot mode (chapter 2).

There is a fifth programmable part: a small controller in the DVI/HDMI chain (EPF021M). None of the four firmware files is for it, so it
probably has fixed firmware *(guess)*.

### 1.2 Four brains

![Four cards, one per programmable chip, with core, operating system, job and firmware file](img/01-four-brains.svg)

*Figure 1.2 — The four "brains" of the radio: what each chip is, what it runs and what it does.*

The four chips split the work cleanly:

- **MAIN (RX651)** is the control CPU. It runs at 120 MHz from 512 KB of on-chip flash. It has no operating system. One loop calls 16 small
  tasks in turn, over and over. MAIN owns everything that defines "the radio": [VFO](#glossary) frequencies, modes, filters, menus and
  memories. It keeps all settings in a 32 KB EEPROM and answers CAT commands on three serial ports. It also switches the radio between
  receive and transmit, and it tells the FPGA and the DSP what to do. It does not process the radio signal itself.
- **DISPLAY (RZ/A1H)** is an ARM Cortex-A9 with 10 MB of on-chip RAM. It runs a small [real-time OS](#glossary) (µITRON, about 32 tasks). It draws the
  touch screen and reads the keys, the knobs and the power button. It owns the SD card and the real-time clock. Because it has the SD card,
  it is also the chip that **updates the firmware of all four chips**. It switches the MAIN CPU on and off.
- **IFDSP (i.MX RT685)** holds two different processors in one chip. A Cortex-M33 (198 MHz, FreeRTOS) is the helper: it starts the DSP,
  sets up the codec and listens to MAIN on a serial port. A Cadence HiFi4 DSP does the heavy audio maths. It demodulates and filters, and
  it runs the [AGC](#glossary), noise reduction and notch. On transmit it runs the mic EQ and the speech processor. Its clock (18.432 MHz)
  comes from the SDR module.
- **SDR (Artix-7 XC7A50T)** is an FPGA, not a CPU. Its "firmware" is a configuration [bitstream](#glossary) that wires up logic at
  power-on. There is no processor inside it, not even a soft one *(inference, high confidence)*. It takes the samples from the fast ADC,
  picks out the wanted frequency, computes the data for the spectrum scope, and on transmit moves the audio up to the RF frequency. The
  FPGA is nearly full: it uses 119 of its 120 multiplier blocks.

### 1.3 Four firmware files

![SD card with four SFL files, the DISPLAY CPU reading them and writing them into each chip's memory](img/01-firmware-files.svg)

*Figure 1.3 — Each [SFL](#glossary) file feeds one chip. The DISPLAY reads them from the SD card and writes them, sometimes through MAIN.*

Yaesu ships the firmware as four `.SFL` files, one per chip. The two-letter tag in each file's header names the image:

| File | Tag | Chip | Where it lives in the radio |
|---|---|---|---|
| `FT-710_MAIN_V0112.SFL` | MC | RX651 | the CPU's own 512 KB flash |
| `FT-710_DISPLAY_V0108.SFL` | PC | RZ/A1H | 16 MB SPI flash with two program banks, copied into RAM at boot |
| `FT-710_IFDSP_V0101.SFL` | ID | RT685 | 16 MB QSPI flash; the code runs straight from it |
| `FT-710_SDR_V0104.SFL` | SR | XC7A50T | the SDR module's flash; the FPGA loads it at power-on |

The files are lightly scrambled and carry a checksum, nothing more. The MAIN file is a text format (Motorola S-records), which is why it
is about 2.6 times bigger than the 512 KB it fills. The DISPLAY is the only chip with the SD card, so it runs every update. It writes the
MAIN CPU directly through the RX651's serial boot mode, and its own flash itself. For the DSP and the FPGA it goes through MAIN, and the
FPGA data also travels over an SPI link. Chapter 4 tells that story; this chapter only needs the mapping.

### 1.4 The receive path

![Receive chain: antenna, RF front end, ADC, FPGA tuner, HiFi4 DSP, audio codec, AF amplifier, speaker, with side branches to the DISPLAY](img/01-rx-path.svg)

*Figure 1.4 — Receive: the signal goes from left to right on the top row, then right to left on the bottom row. Stages marked M are set up by MAIN.*

Follow a signal from the antenna to your ears:

1. **RF front end.** The signal passes the band-pass filters and the preamp or attenuator. MAIN picks the filter and switches the preamp
   and attenuator through a chain of serial shift registers.
2. **ADC.** On the SDR module a fast ADC turns the RF into a stream of numbers. A 35.7 MHz oscillator on the MAIN unit feeds the 250 MHz
   sampling clock, and the FPGA runs at half that, 125 MHz.
3. **FPGA "tuner".** The FPGA multiplies the samples with a digital oscillator ([NCO](#glossary)) set to your frequency. That moves the
   wanted signal down to near zero, where a bank of filters cuts out a narrow slice and drops the sample rate. This is the classic
   digital down-converter ([DDC](#glossary)). The blocks inside the FPGA are recognised from its lookup tables and multiplier use *(inference)*.
   The FPGA also has the noise blanker controls *(inference)* and computes the spectrum-scope data. The scope data goes **straight to the
   DISPLAY** over its own SPI link and never passes through MAIN.
4. **HiFi4 DSP.** The narrow, slow stream reaches the RT685 over [I2S](#glossary), a standard serial audio bus. The HiFi4 demodulates
   (SSB, CW, AM, FM, data) and runs the filters, AGC, noise reduction, notch and contour. It works at a sample rate of about 12 kHz
   *(inference, strong)*. It also sends an audio spectrum ("AF-FFT") and the voice-recorder audio to the DISPLAY over a second SPI link.
5. **Audio codec.** A TI TLV320AIC3204 turns the numbers back into an analog voltage.
6. **AF amplifier and speaker.** The audio is amplified and sent to the speaker or phones.

MAIN does not process the signal. It only programs each stage: frequency, filter, scope span and noise blanker go to the FPGA; mode, AGC,
noise reduction and notch go to the DSP. Chapter 2 shows how it sends those settings.

### 1.5 The transmit path

![Transmit chain: microphone, codec, HiFi4 DSP, FPGA up-converter, DAC, PA unit, antenna](img/01-tx-path.svg)

*Figure 1.5 — Transmit: the same chips work in the other direction. Stages marked M are set up by MAIN.*

On transmit the chain runs backwards:

1. **Codec.** Audio from the microphone or the rear DATA input reaches the codec, which turns it into numbers.
2. **HiFi4 DSP.** The DSP applies the mic equaliser, the speech processor, the automatic mic level control (AMC) and the TX filter. It
   also detects VOX and generates CTCSS tones for FM.
3. **FPGA up-converter.** The audio goes back over I2S to the FPGA. A second digital oscillator, set to the transmit frequency, moves it up
   to RF. The FPGA also sets the drive level and shapes the start and end of each CW element with a smooth "raised-cosine" ramp
   *(inference from the FPGA's tables)*.
4. **DAC.** The FPGA drives a fast [LVDS](#glossary) output bus, which most likely feeds a DAC on the SDR module *(inference; the part is unknown)*.
5. **PA unit.** The low-level RF goes to the PA unit. MAIN selects the band relays there and keys the amplifier.

MAIN decides *when* the radio transmits. A [PTT](#glossary) can come from the mic key, the [MOX](#glossary) button, a CAT `TX1;` command, the rear DATA
jack, or the RTS/DTR lines of the USB serial port. MAIN then checks that the frequency is allowed for the radio's region, re-programs the FPGA and
the DSP for transmit, switches the RX/TX lines and keys the amplifier last. Chapter 3 walks through that sequence step by step.

### 1.6 The USB side

![USB tree: PC, USB-B jack, four-port hub, CP2105 with two COM ports, CM119B sound card, FT4222H to the DISPLAY](img/01-usb-tree.svg)

*Figure 1.6 — What the PC sees: a hub with three devices behind it.*

Plug a USB cable into the rear USB-B jack and the PC finds a 4-port hub (Cypress CY7C65631) with three devices behind it:

- **[CP2105](#glossary)**, a dual USB-to-serial bridge. It shows up as **two COM ports**. The "Enhanced" port goes to MAIN's CAT port 1 (38400 baud
  after a reset), the "Standard" port to CAT port 2 (4800 baud after a reset). You can change both rates in the menu. The RTS and DTR lines
  of the Standard port can key the radio (PTT) or key CW/RTTY, if the PC KEYING menu setting says so.
- **CM119B**, a USB sound card. A menu setting (MOD SOURCE) can select USB audio as the transmit audio. How its analog side is wired was
  not traced in the schematic, and no firmware touches the chip.
- **[FT4222H](#glossary)**, a USB-to-SPI bridge on the DISPLAY unit. Through it the DISPLAY streams 4 KB frames to the PC: a copy of the spectrum
  scope, the audio spectrum and a 151-byte status block. The DISPLAY holds the bridge in reset until a setting from MAIN switches it on.
  Which PC program reads this stream is not known.

The fourth hub port is not used. A third CAT port, not on USB, sits on the rear TUNER/LINEAR jack at 5 V logic levels. The RX651 and
the RZ/A1H have USB ports of their own, but neither is used for the PC: the RX651's pins go to test points, and the RZ/A1H's USB host only
serves a USB keyboard or mouse.

### 1.7 Where to look

- Whole-radio overview, block diagrams and the signal path: [../code/system.md](../code/system.md) §1–2.
- Chips, boards, connectors and debug headers from the service manual: [../hardware.md](../hardware.md).
- MAIN's role and peripherals: [../code/main/README.md](../code/main/README.md); the SDR module's pins: [../code/sdr/interfaces.md](../code/sdr/interfaces.md);
  what is inside the FPGA: [../code/sdr/README.md](../code/sdr/README.md).
- The SFL file format: [../sfl-format.md](../sfl-format.md).
- Part numbers used in this chapter: MAIN CPU Q1001 R5F56514ADFB; DISPLAY CPU Q6009 R7S721001VCBG; IF DSP Q2002 MIMXRT685SFVKB; codec
  Q2001 TLV320AIC3204; EEPROM Q1008 BR25G256; USB hub Q2607 CY7C65631; CP2105 Q2614; CM119B Q2624; FT4222HQ Q6020; SDR module on
  J2002/J3003; DVI controller Q1805 EPF021M.
- CAT ports: SCI3 = port 1 (CP2105 Enhanced), SCI0 = port 2 (CP2105 Standard), SCI2 = port 3 (TUNER/LINEAR jack), see
  [../code/main/sci.md](../code/main/sci.md). Front-end and PA control words: `rf_bpf_update`, `pa_relay_update` in
  [../code/main/tx-protection.md](../code/main/tx-protection.md).
