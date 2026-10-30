# T19h — Fix reference-page issues found while writing the guide

**Status:** done · **Depends on:** T19a–T19g

## Goal
While writing the guide, the chapter writers found 26 issues in the reference pages: two pages disagreeing, stale text superseded by
later tasks, and small slips. They are listed under `## Reference issues` in T19a–T19g. For each one, check the code or data, fix the
reference page(s) with the correct [fact]/[inference] (or an open question; the former guess tag is retired) tag and evidence, and correct the guide (`docs/guide/README.md`) wherever
it states, or deliberately avoids, the point.

## Plan
26 issues (T19a 3, T19b 4, T19c 4, T19d 4, T19e 3, T19f 6, T19g 2), numbered here as a1-a3, b1-b4, c1-c4, d1-d4, e1-e3, f1-f6, g1-g2.
Duplicates: b1 = e1 (supply ADC channel).
For each issue, in order of topic:
1. Settle it from evidence: decomp `decomp/<image>/*.c` (grep, targeted reads), the reference pages, the task files of the producing
   tasks (T15/T15b/T15e supersede T10c/T13), the service manual (`pdftotext -f N -l M`), and `build/renesas/*.txt` for RX651 registers.
   Ghidra only if the decompiles cannot settle a point (copy to `<PROJ>_T19h`).
2. Edit only the sentences concerned in the reference page(s): correct the claim with a tag and evidence, or mark superseded text
   ("superseded by T15e: ...") with a pointer; leave both views marked open where the evidence does not settle it.
3. Fix `docs/guide/README.md` where it states or avoided the point (plain language, addresses only in "Where to look").
4. Commit per issue or small group (`T19h: ...`), heartbeat after each group.
Groups: (1) MAIN ADC/power/encoder (b1/e1, b2, b3, b4); (2) SDR link + clocks (a1, a2, f1, f2, f6, g1, g2); (3) DSP link (a3, f3, f4, f5);
(4) DISPLAY (c1, c2, c4, e2, e3); (5) SFL + CAT (c3, d1-d4). Finish with Findings (one line each) and Follow-ups.

## Findings
26 issues: **21 settled**, **3 left open** with both views marked (a2, e2, f1; new rows O7, O8, O9 in `code/system.md` §8), **2 needed no
fix** beyond a cross-reference (e3, g2). Guide text changed for b1, b2 (incl. figure 3.2), b3, a2, f1, f4, c2, d3 and f3 ("Where to look").

- a1 SDR reply format: **settled**, 1 byte (0x06 or `?`) for a write, 7 bytes `r`+value+sum for a read. MAIN's `sci5_rx_byte_hook` 0xFFF94962 sets the SCI5 receive length from byte 0 (agrees with T15e). Fixed system.md §3, main/sdr-link.md (overview, figure, reply table, sequence, function table, T15e note), sdr/netlist.md §5.2, main/cat.md. Guide already right.
- a2 ADC 250 vs 125 MSPS: **open** (O7). Fabric 125 MHz [inference, high], 250 MHz clock [fact, SM p6]; ADC rate not decidable (no part number, IDDR edge mode undecoded); reg 0x03's 62.5 MHz limit (settled later in O7 / #172: it is fs/2 of two 125 MSPS ADC channels, the Nyquist boundary [inference, strong; docs/code/system.md §8 O7], not a DAC limit). Diagram labels, hardware.md, sdr-link.md reg 0x03 marked; guide says it is not known.
- a3 DSP boot retry: **settled**, reg 1 is read once, bit 0 clear → boot_error 2 (`dsp_link_init` 0xFFF9D06C; `dsp_check_reply` clears 0x1C5F). ifdsp/control-link.md diagram fixed. Guide already right.
- b1/e1 supply ADC channel: **settled**, AN003 `PA_VDD` (`adc0_store` 0xFFFB27FB: `R_S12AD0_Get_ValueResult(3, 0x20B08)`). Fixed main/eeprom.md and main/README.md; guide now says "13.8 V supply on one ADC input".
- b2 PS0 power-off path: **settled**, 0x20F4B is read only by `displink_tx_schedule` 0xFFF95F58 → `power_down_save` 0xFFF98797 (0x7F frame, `eeprom_save_all`, 2 s wait for 0x90, `sw_reset`); the power key (0x20B30 = 2) exits in `io_task` with no 0x7F frame. Fixed peripherals.md diagram + bullet, system.md §4.2, main/README.md. **Guide changed:** the 0x7F frame is sent on the PS0 and low-voltage paths only (text, caption and figure 03-power-off.svg).
- b3 encoder id 6: **settled**, USB mouse wheel on the main screen (`mouse_wheel_event` 0x2015FAC4 sends id 6 when screen 0x208F0B2A = 0x20). Fixed main/ui-keys.md, tagged display/input.md; one sentence added to the guide.
- b4 E1 wording: **settled**, AA/length is the in-memory buffer header only; display/input.md clarified.
- c1 `display_flash_write_bank`: **settled**, 0x2015F1F0 is `fwdbg_verify_bank1` (decomp); custom-firmware.md now names `fwobj_display_run` 0x201607E8.
- c2 SDR header block: **settled**, address = 0x240000 + index × 0x1000; blocks 0..0x217 (536) then index 0x240 → 0x480000, 537 writes (`sdr_spi_xfer_block` 0x20110834, `sdr_flash_write` 0x20110AB8). update.md §1/§8 and custom-firmware.md reworded; guide adds "536 blocks, header as 537th".
- c3 SFL SDR key run: **settled**, SDR plaintext starts `993966c2` then `ffff…`; the key+0x66 run starts at offset 8 (checked bytes 0..95). sfl-format.md fixed.
- c4 update.md cosmetic: **settled**, 7 duplicated names / stray backticks removed.
- d1 do-nothing count: **settled**, 13 (9 + 3 + KT). cat-commands.md and T09 findings fixed. Guide already said 13.
- d2 menu.md EX example: **settled**, `EX0101040300;` (ex_write_value requires 9 + 4 characters, `ex_parse_4digits` 0xFFFE6869 compares). Fixed.
- d3 EX length rules: **settled**, read len 9, set len > 8 (case code 0xFFFA4097); `cat_dispatch.tsv`'s "len==8" is a misread of `8 < len`. cat-commands-primary.md corrected, cat-commands.md given the exact-digit rule. **Guide** now states the exact-digit rule for a set.
- d4 XT manual revision: **settled**, documented in both 2211-A and 2306-C (p. 23, pdftotext). main/cat.md updated.
- e2 frame buffers at 0x60000000: **open** (O9). A plain alias of 0x20000000 is ruled out [inference from fact]: `task_root` runs `fb_clear_all` (memclr 0x60000000, 0x2FF300; literals at 0x20132B30/0x20132FD0) while executing from 0x20100000+, and the MMU table at 0x2044C000 is flat (0x20100D48). Needs the RZ/A1H address map. memory-maps.md and display/gui.md marked. Guide unaffected (it never placed them).
- e3 debug-console gate wording: **no fix**, reference is right (32-bit word 0xA0B9C8E7); guide follows it.
- f1 DSP_CLK: **open** (O8). 18.432 MHz is what the M33 code assumes [fact]; T13's 16.6 MHz superseded by T15's cascade; T15's 28.17 MHz needs a 1,440 MHz VCO; a feedback multiplier of 22.25 instead of 34 would have given 18.4323 MHz (ruled out in #67: the LKTABLE and counter bits decode to M = 34 and 36 [fact], so P14 is 28.17 MHz; `DSP_CLK` stays open, O8). netlist.md, resources.md marked; guide mentions the possible misread.
- f2 DSP48 counts: **settled**, T15b supersedes T13 ("all fully pipelined", "no pre-adder"); sdr/README.md and resources.md body marked.
- f3 `dev4_reg_access`: **settled**, Ghidra name is `dsp_reg_access` (decomp); control-link.md renamed and its FUN_ names given current names; guide "Where to look" updated.
- f4 IFDSP register count: **settled**, 113 registers listed (0x0000–0x4026 rows, excluding the 0x2000–0x200F block and the two capture blocks), 98 with a known access. control-link.md and ifdsp/README.md fixed; **guide** caption changed from "about 110 live".
- f5 reg 6 mapping: **settled**, hifi4.md now links MAIN's mapping (0 CW-U … 9 FM).
- f6 bitstream.md Limits: **settled**, marked superseded by T15 (routing decoded; package narrowed to CSG324/FGG484).
- g1 stale T15 future work: **settled**, fpga-jtag-hello.md (pins section, stage 2, out of scope, follow-ups) and custom-firmware.md (blocker 3, next steps) updated with T15/T15e results.
- g2 package counts: **no fix needed** (they agree); a cross-reference "lack 59, 34 and 19" added.

## Follow-ups
- O7: identify the ADC (module photo or part marking, owner) or decode the IDDR edge mode to settle 250 vs 125 MSPS.
- O8: re-check MMCM_X0Y0's CLKFBOUT/DIVCLK fields in the FASM, or measure J2002 pin 22 with a passive probe (owner approval).
- O9: obtain the RZ/A1H hardware manual (address map chapter) to say what 0x60000000 decodes to.
- `decomp/main/cat_dispatch.tsv` prints `8 < len` tests as `len==8` (EX, maybe others); fix the generator and re-check the length columns in cat-commands-primary.md.
- Pre-existing Mermaid render errors (mmdc 11.4.2) in blocks not touched by this task: main/sdr-link.md blocks 1 and 3 and main/menu.md block 3 (backtick markdown-string labels), display/update.md write sequence (`;` inside a Note), sdr/interfaces.md block 2.
