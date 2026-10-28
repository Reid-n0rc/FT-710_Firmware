# CAT commands — FT-710 MAIN V01-12

Every CAT command that MAIN firmware V01-12 accepts, compared with Yaesu's CAT manual. Produced in T09 ([T09a](tasks/T09a-cat-core-ext.md), [T09b](tasks/T09b-cat-primary.md)).
How the parser, replies, AI and ports work is described in [code/main/cat.md](code/main/cat.md). Per-command firmware details for the 104 primary commands are in [cat-commands-primary.md](cat-commands-primary.md).

> **Safety.** Nothing here was sent to the radio. Commands marked high risk key the transmitter, power the radio off, or rewrite EEPROM, the region code or the factory settings. Do not try any undocumented **set** form without the owner's explicit approval for that specific test (AGENTS.md).

## Sources

| Source | Notes |
|---|---|
| Firmware | `FT-710_MAIN_V0112.SFL`, Ghidra project `ghidra/FT710_MAIN`, `decomp/main/` and `decomp/main/cat_dispatch.tsv` |
| Manual, primary | *FT-710 CAT Operation Reference Manual* rev **2306-C** (`Manuals/FT-710_CAT_OM_ENG_2306-C.pdf`, not in git). "Documented" refers to this revision. |
| Manual, history | Rev 2211-A (English, dealer mirror) and the Japanese rev 2212-B. 2306-C differs from 2211-A in three places: it drops `EO`, changes `VE` read from `VE;` to `VEP1;`, and rewords the `AC` P3 list. Otherwise the layout is the same. |

The manual parameter summaries below are short paraphrases. Ranges and digit counts are copied as printed.

## Tags and columns
- **[fact]**: seen in the code or data at the address given. **[inference]**: follows from the code but is not proven. **[guess]**: plausible, weakly supported.
- **FW lengths accepted**: total characters, including the 2-letter mnemonic and `;`, that the dispatch case accepts. The firmware checks the **length only**. Digits are validated inside the handler.
- **Class**:
  - `read-only`
  - `action`: a set with no stored value
  - `read+set`
  - `error-only`: the mnemonic is in the table but always answers `?;`
  - `none`: silently ignored
- **Risk**:
  - **low**: read or UI state
  - **medium**: persistent configuration, memory channels, TX-related settings
  - **high**: keys TX, powers off, changes EEPROM/region/factory data, service access

## Protocol facts that apply to every command [fact]
- **Mnemonic and case.** The mnemonic is 2 letters. Only those two are case-insensitive. Parameters are case-sensitive unless noted.
- **Error reply.** Any error answers `?;` (`cat_reply_error` @ 0xFFFB0166). This covers an unknown mnemonic, a wrong length, a bad digit or a refused key event. There is no other error code.
- **Set commands do not answer.** Except where noted, sets give no reply on success.
- **Power-off.** While the radio is off, everything except `PS1;` is dropped silently.
- **Ports.** Port 1 = SCI3 (USB Enhanced), port 2 = SCI0 (USB Standard), port 3 = SCI2 (TUNER/LINEAR jack in CAT-3 mode). The answer goes to the port that sent the command. `AI` is stored per port (0x20B20..0x20B22).
- **AI broadcasts.** These come from `cat_ai_poll` @ 0xFFFDD797. Its detectors cover the manual's AI=O commands, and also **`FD`**, which is undocumented (detector `cat_ai_FD` @ 0xFFFDDB7E).
- **Hidden forms.** Some commands accept more forms than the manual shows. See [Firmware vs manual](#firmware-vs-manual-differences).

## All commands

`P` = primary table `cat_mnemonics` @ 0xFFF805EC (104 entries), `X` = extended table `cat_ext_mnemonics` @ 0xFFF806BC (10 entries; tried only when the primary lookup fails).

| Table | # | Mnemonic | Handler | FW lengths accepted | Manual function (2306-C) | Documented | Class | Risk |
|---|---|---|---|---|---|---|---|---|
| P | 0 | [`AB`](cat-commands-primary.md#ab) | cat_AB @ fffa646d | 3 | VFO-A TO VFO-B | yes (2306-C) | action | low |
| P | 1 | [`AC`](cat-commands-primary.md#ac) | cat_AC @ fffa65d4 | 3/6 | ANTENNA TUNER CONTROL | yes (2306-C) | read+set | high |
| P | 2 | [`AG`](cat-commands-primary.md#ag) | cat_AG @ fffa6867 | 4/7 | AF GAIN | yes (2306-C) | read+set | low |
| P | 3 | [`AI`](cat-commands-primary.md#ai) | cat_AI @ fffa6946 | 3/4 | AUTO INFORMATION | yes (2306-C) | read+set | low |
| P | 4 | [`AM`](cat-commands-primary.md#am) | cat_AM @ fffa6a26 | 3 | VFO-A TO MEMORY CHANNEL | yes (2306-C) | action | medium |
| P | 5 | [`AO`](cat-commands-primary.md#ao) | cat_AO @ fffa6b6f | 3/6 | AMC OUTPUT LEVEL | yes (2306-C) | read+set | low |
| P | 6 | [`AS`](cat-commands-primary.md#as) | cat_AS @ fffa6c9d | 4/7 | AESS | yes (2306-C) | read+set | low |
| P | 7 | [`AV`](cat-commands-primary.md#av) | cat_AV @ fffa6edc | 3/6 | ANTI VOX LEVEL | yes (2306-C) | read+set | low |
| P | 8 | [`BA`](cat-commands-primary.md#ba) | cat_BA @ fffa7018 | 3 | VFO-B TO VFO-A | yes (2306-C) | action | low |
| P | 9 | [`BC`](cat-commands-primary.md#bc) | cat_BC @ fffa717f | 4/5 | AUTO NOTCH (DNF) | yes (2306-C) | read+set | low |
| P | 10 | [`BD`](cat-commands-primary.md#bd) | cat_BD @ fffa72d9 | 4 | BAND DOWN | yes (2306-C) | action | medium |
| P | 11 | [`BI`](cat-commands-primary.md#bi) | cat_BI @ fffa77ec | 3/4 | BREAK-IN | yes (2306-C) | read+set | low |
| P | 12 | [`BM`](cat-commands-primary.md#bm) | cat_BM @ fffa7928 | 3 | VFO-B TO MEMORY CHANNEL | yes (2306-C) | action | medium |
| P | 13 | [`BP`](cat-commands-primary.md#bp) | cat_BP @ fffa7a71 | 5/8 | MANUAL NOTCH | yes (2306-C) | read+set | low |
| P | 14 | [`BS`](cat-commands-primary.md#bs) | cat_BS @ fffa7db5 | 5 | BAND SELECT | yes (2306-C) | action | medium |
| P | 15 | [`BU`](cat-commands-primary.md#bu) | cat_BU @ fffa756c | 4 | BAND UP | yes (2306-C) | action | medium |
| P | 16 | [`BY`](cat-commands-primary.md#by) | switch default (fffa4e26) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 17 | [`CF`](cat-commands-primary.md#cf) | cat_CF @ fffa7fa1 | 6/11 | CLAR (Clarifier) | yes (2306-C) | read+set | medium |
| P | 18 | [`CH`](cat-commands-primary.md#ch) | cat_CH @ fffa8375 | 4 | CHANNEL UP/DOWN | yes (2306-C) | action | medium |
| P | 19 | [`CN`](cat-commands-primary.md#cn) | cat_CN @ fffa8513 | 5/8 | CTCSS NUMBER | yes (2306-C) | read+set | low |
| P | 20 | [`CO`](cat-commands-primary.md#co) | cat_CO @ fffa8698 | 5/9 | CONTOUR/APF | yes (2306-C) | read+set | low |
| P | 21 | [`CS`](cat-commands-primary.md#cs) | cat_CS @ fffa8b98 | 3/4 | CW SPOT | yes (2306-C) | read+set | low |
| P | 22 | [`CT`](cat-commands-primary.md#ct) | cat_CT @ fffa8c79 | 4/5 | CTCSS | yes (2306-C) | read+set | low |
| P | 23 | [`DA`](cat-commands-primary.md#da) | cat_DA @ fffa8d8a | 3/11 | LCD CONTRAST/DIMMER | yes (2306-C) | read+set | low |
| P | 24 | [`DN`](cat-commands-primary.md#dn) | cat_DN @ fffa9029 | 3 | MIC DOWN | yes (2306-C) | action | medium |
| P | 25 | [`DT`](cat-commands-primary.md#dt) | cat_DT @ fffa9281 | compound: 4 / 10 or 12 | DATE AND TIME | yes (2306-C) | read+set | medium |
| P | 26 | [`ED`](cat-commands-primary.md#ed) | switch default (fffa4e26) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 27 | [`EK`](cat-commands-primary.md#ek) | switch default (fffa4e26) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 28 | [`EM`](cat-commands-primary.md#em) | cat_EM @ fffa9648 | compound: 5 / 6..55 | – | **no** (not in 2211-A or 2306-C) | read+set | low |
| P | 29 | [`EN`](cat-commands-primary.md#en) | cat_EN @ fffa9928 | 5 | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 30 | [`EU`](cat-commands-primary.md#eu) | switch default (fffa4e26) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 31 | [`EX`](cat-commands-primary.md#ex) | cat_EX @ fffa9937 | 9 (read) / >=10 (set) | MENU | yes (2306-C) | read+set | medium-high |
| P | 32 | [`FA`](cat-commands-primary.md#fa) | cat_FA_FB @ fffa99bd (side 0) | 3/12 | FREQUENCY VFO-A | yes (2306-C) | read+set | medium |
| P | 33 | [`FB`](cat-commands-primary.md#fb) | cat_FA_FB @ fffa99bd (side 1) | 3/12 | FREQUENCY VFO-B | yes (2306-C) | read+set | medium |
| P | 34 | [`FN`](cat-commands-primary.md#fn) | cat_FN @ fffa9c96 | 3/4 | FINE TUNING | yes (2306-C) | read+set | low |
| P | 35 | [`FS`](cat-commands-primary.md#fs) | cat_FS @ fffa9d3d | 3/4 | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 36 | [`FT`](cat-commands-primary.md#ft) | cat_FT @ fffa9d4e | 3/4 | FUNCTION TX | yes (2306-C) | read+set | medium |
| P | 37 | [`GT`](cat-commands-primary.md#gt) | cat_GT @ fffa9f23 | 4/5 | AGC FUNCTION | yes (2306-C) | read+set | medium |
| P | 38 | [`GP`](cat-commands-primary.md#gp) | cat_GP @ fffaa21f | 3/7 | GP OUT A/B/C/D | yes (2306-C) | read+set | medium |
| P | 39 | [`ID`](cat-commands-primary.md#id) | cat_ID @ fffaa365 | 3 | IDENTIFICATION | yes (2306-C) | read-only | low |
| P | 40 | [`IF`](cat-commands-primary.md#if) | cat_IF_OI @ fffaa39c (arg 0, side 0 = record 0x9D09) | 3 | INFORMATION (VFO-A) | yes (2306-C) | read-only | low |
| P | 41 | [`IS`](cat-commands-primary.md#is) | cat_IS @ fffaa6e3 | 4/10 | IF SHIFT | yes (2306-C) | read+set | medium |
| P | 42 | [`KM`](cat-commands-primary.md#km) | cat_KM @ fffaa905 | compound: 4 / 5..54 (0x36; compound test len>=5 && len<=0x36) | KEYER MEMORY | yes (2306-C) | read+set | medium |
| P | 43 | [`KP`](cat-commands-primary.md#kp) | cat_KP @ fffaac36 | 3/5 | KEY PITCH | yes (2306-C) | read+set | low |
| P | 44 | [`KR`](cat-commands-primary.md#kr) | cat_KR @ fffaad52 | 3/4 | KEYER | yes (2306-C) | read+set | low |
| P | 45 | [`KS`](cat-commands-primary.md#ks) | cat_KS @ fffaadea | 3/6 | KEY SPEED | yes (2306-C) | read+set | low |
| P | 46 | [`KY`](cat-commands-primary.md#ky) | cat_KY @ fffaaf19 | 5 | CW KEYING | yes (2306-C) | set-only | high |
| P | 47 | [`LK`](cat-commands-primary.md#lk) | cat_LK @ fffab09f | 3/4 | LOCK | yes (2306-C) | read+set | low |
| P | 48 | [`LM`](cat-commands-primary.md#lm) | cat_LM @ fffab16f | 4/5 | LOAD MESSAGE | yes (2306-C) | read+set | high |
| P | 49 | [`MA`](cat-commands-primary.md#ma) | cat_MA @ fffab3fd | 3 | MEMORY CHANNEL TO VFO-A | yes (2306-C) | action | medium |
| P | 50 | [`MB`](cat-commands-primary.md#mb) | cat_MB @ fffab478 | 3 | MEMORY CHANNEL TO VFO-B | yes (2306-C) | action | medium |
| P | 51 | [`MC`](cat-commands-primary.md#mc) | cat_MC @ fffab4f3 | 3/6 | MEMORY CHANNEL | yes (2306-C) | read+set | medium |
| P | 52 | [`MD`](cat-commands-primary.md#md) | cat_MD @ fffab7d1 | 4/5 | MODE | yes (2306-C) | read+set | medium |
| P | 53 | [`MG`](cat-commands-primary.md#mg) | cat_MG @ fffaba64 | 3/6 | MIC GAIN | yes (2306-C) | read+set | medium |
| P | 54 | [`ML`](cat-commands-primary.md#ml) | cat_ML @ fffabbfa | 4/7 | MONITOR LEVEL | yes (2306-C) | read+set | medium |
| P | 55 | [`MR`](cat-commands-primary.md#mr) | cat_MR @ fffabea5 | 6 | MEMORY READ | yes (2306-C) | read-only | low |
| P | 56 | [`MS`](cat-commands-primary.md#ms) | cat_MS @ fffac4b6 | 3/5 | METER SW | yes (2306-C) | read+set | low |
| P | 57 | [`MT`](cat-commands-primary.md#mt) | cat_MT @ fffac285 | compound: 6 / 8..19 (compound: len==6 read, 8<=len<=0x13 set) | MEMORY CHANNEL TAG WRITE | yes (2306-C) | read+set | medium |
| P | 58 | [`MW`](cat-commands-primary.md#mw) | cat_MW @ fffac534 | 28 | MEMORY CHANNEL WRITE | yes (2306-C) | set-only | medium |
| P | 59 | [`MX`](cat-commands-primary.md#mx) | cat_MX @ fffac9ad | 3/4 | MOX SET | yes (2306-C) | read+set | high |
| P | 60 | [`NA`](cat-commands-primary.md#na) | cat_NA @ fffaca47 | 4/5 | NARROW | yes (2306-C) | read+set | medium |
| P | 61 | [`NB`](cat-commands-primary.md#nb) | cat_NB @ fffacc65 | 4/5 | NOISE BLANKER | yes (2306-C) | read+set | low |
| P | 62 | [`NL`](cat-commands-primary.md#nl) | cat_NL @ fffacce8 | 4/7 | NOISE BLANKER LEVEL | yes (2306-C) | read+set | low |
| P | 63 | [`NR`](cat-commands-primary.md#nr) | cat_NR @ ffface21 | 4/5 | NOISE REDUCTION (DNR) | yes (2306-C) | read+set | low |
| P | 64 | [`OI`](cat-commands-primary.md#oi) | cat_IF_OI @ fffaa39c (arg 1, side 1 = record 0x9D63) | 3 | OPPOSITE BAND (VFO-B) INFORMATION | yes (2306-C) | read-only | low |
| P | 65 | [`OS`](cat-commands-primary.md#os) | cat_OS @ fffacebe | 4/5 | OFFSET (Repeater Shift) | yes (2306-C) | read+set | medium |
| P | 66 | [`PA`](cat-commands-primary.md#pa) | cat_PA @ fffad001 | 4/5 | PRE-AMP (IPO) | yes (2306-C) | read+set | low |
| P | 67 | [`PB`](cat-commands-primary.md#pb) | cat_PB @ fffad0a2 | 4/5 | PLAY BACK | yes (2306-C) | read+set | high |
| P | 68 | [`PC`](cat-commands-primary.md#pc) | cat_PC @ fffad241 | 3/6 | POWER CONTROL | yes (2306-C) | read+set | medium |
| P | 69 | [`PL`](cat-commands-primary.md#pl) | cat_PL @ fffad467 | 3/6 | SPEECH PROCESSOR LEVEL | yes (2306-C) | read+set | medium |
| P | 70 | [`PR`](cat-commands-primary.md#pr) | cat_PR @ fffad595 | 4/5 | SPEECH PROCESSOR | yes (2306-C) | read+set | medium |
| P | 71 | [`PS`](cat-commands-primary.md#ps) | cat_PS @ fffad696 | 3/4 | POWER SWITCH | yes (2306-C) | read+set | high |
| P | 72 | [`QI`](cat-commands-primary.md#qi) | cat_QI @ fffad704 | 3 | QMB STORE | yes (2306-C) | action | medium |
| P | 73 | [`QR`](cat-commands-primary.md#qr) | cat_QR @ fffad709 | 3 | QMB RECALL | yes (2306-C) | action | medium |
| P | 74 | [`QS`](cat-commands-primary.md#qs) | cat_QS @ fffad70e | 3 | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 75 | [`RA`](cat-commands-primary.md#ra) | cat_RA @ fffad718 | 4/5 | RF ATTENUATOR | yes (2306-C) | read+set | low |
| P | 76 | [`RC`](cat-commands-primary.md#rc) | (switch default) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 77 | [`RD`](cat-commands-primary.md#rd) | (switch default) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 78 | [`RG`](cat-commands-primary.md#rg) | cat_RG @ fffad7ae | 4/7 | RF GAIN | yes (2306-C) | read+set | low |
| P | 79 | [`RI`](cat-commands-primary.md#ri) | cat_RI @ fffad8e3 | 4 | RADIO INFORMATION | yes (2306-C) | read-only | low |
| P | 80 | [`RL`](cat-commands-primary.md#rl) | cat_RL @ fffada46 | 4/6 | NOISE REDUCTION (DNR) LEVEL | yes (2306-C) | read+set | low |
| P | 81 | [`RM`](cat-commands-primary.md#rm) | cat_RM @ fffadb7d | 4 | READ METER | yes (2306-C) | read-only | low |
| P | 82 | [`RS`](cat-commands-primary.md#rs) | (switch default) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 83 | [`RT`](cat-commands-primary.md#rt) | (switch default) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 84 | [`RU`](cat-commands-primary.md#ru) | (switch default) | – | – | **no** (not in 2211-A or 2306-C) | error-only | low |
| P | 85 | [`SC`](cat-commands-primary.md#sc) | cat_SC @ fffadcd6 | 3/4 | SCAN | yes (2306-C) | read+set | low |
| P | 86 | [`SD`](cat-commands-primary.md#sd) | cat_SD @ fffadd9a | 3/5 | SEMI BREAK-IN DELAY TIME | yes (2306-C) | read+set | medium |
| P | 87 | [`SF`](cat-commands-primary.md#sf) | cat_SF @ fffadeb6 | 4/5 | SUB DIAL | yes (2306-C) | read+set | medium |
| P | 88 | [`SH`](cat-commands-primary.md#sh) | cat_SH @ fffae2ca | 4/7 | WIDTH | yes (2306-C) | read+set | medium |
| P | 89 | [`SM`](cat-commands-primary.md#sm) | cat_SM @ fffae64b | 4 | S METER | yes (2306-C) | read-only | low |
| P | 90 | [`SQ`](cat-commands-primary.md#sq) | cat_SQ @ fffae6cc | 4/7 | SQUELCH LEVEL | yes (2306-C) | read+set | low |
| P | 91 | [`SS`](cat-commands-primary.md#ss) | cat_SS @ fffae850 | 5/10 | SPECTRUM SCOPE | yes (2306-C) | read+set | low |
| P | 92 | [`ST`](cat-commands-primary.md#st) | cat_ST @ fffaf3b5 | 3/4 | SPLIT | yes (2306-C) | read+set | medium |
| P | 93 | [`SV`](cat-commands-primary.md#sv) | cat_SV @ fffaf46e | 3 | SWAP VFO | yes (2306-C) | action | medium |
| P | 94 | [`TS`](cat-commands-primary.md#ts) | cat_TS @ fffaf5c7 | 3/4 | TXW | yes (2306-C) | read+set | medium |
| P | 95 | [`TX`](cat-commands-primary.md#tx) | cat_TX @ fffaf7b8 | 3/4 | TX SET | yes (2306-C) | read+set | high |
| P | 96 | [`UP`](cat-commands-primary.md#up) | cat_UP @ fffa9155 | 3 | MIC UP | yes (2306-C) | action | medium |
| P | 97 | [`VD`](cat-commands-primary.md#vd) | cat_VD @ fffaf874 | 3/5 | VOX DELAY TIME | yes (2306-C) | read+set | medium |
| P | 98 | [`VG`](cat-commands-primary.md#vg) | cat_VG @ fffaf9c0 | 3/6 | VOX GAIN | yes (2306-C) | read+set | medium |
| P | 99 | [`VM`](cat-commands-primary.md#vm) | cat_VM @ fffafadb | compound: 4 ('VM0;') / 3 ('VM;', action) \| 6 ('VM0nn;') | [V/M] KEY FUNCTION | yes (2306-C) | read+set | medium |
| P | 100 | [`VS`](cat-commands-primary.md#vs) | cat_VS @ fffafdbd | 3/4 | VFO SELECT | yes (2306-C) | read+set | medium |
| P | 101 | [`VX`](cat-commands-primary.md#vx) | cat_VX @ fffaffa0 | 3/4 | VOX | yes (2306-C) | read+set | medium |
| P | 102 | [`XT`](cat-commands-primary.md#xt) | (none, switch default) | – | TX CLAR | yes (2306-C) – **not implemented in V01-12** | error-only | low |
| P | 103 | [`ZI`](cat-commands-primary.md#zi) | cat_ZI @ fffb006e | 4 | ZERO IN | yes (2306-C) | action | medium |
| X | 0 | [`SP`](#ext-sp) | cat_ext_SP @ fffa36f2 | see SP table | – | **no** (not in 2211-A or 2306-C) | read+set (service) | high |
| X | 1 | [`EO`](#ext-eo) | cat_ext_EO @ fffa5c90 | 10 | ENCODER OFFSET (2211-A only) | removed in 2306-C (was in 2211-A) | action | medium |
| X | 2 | [`E8`](#ext-e8) | cat_ext_E8 @ fffa53a4 | any | – | **no** (not in 2211-A or 2306-C) | read-only | low (read) / large reply |
| X | 3 | [`E9`](#ext-e9) | cat_ext_E9 @ fffa5985 | binary (fast path) | – | **no** (not in 2211-A or 2306-C) | set (restore) | high |
| X | 4 | [`FD`](#ext-fd) | cat_ext_FD @ fffa5a51 | 6/15 | – | **no** (not in 2211-A or 2306-C) | read+set | medium |
| X | 5 | [`KT`](#ext-kt) | – | any (ignored) | – | **no** (not in 2211-A or 2306-C) | none | low |
| X | 6 | [`PE`](#ext-pe) | cat_ext_PE @ fffa5fdf | 6/9 | – | **no** (not in 2211-A or 2306-C) | read+set | medium |
| X | 7 | [`ZZ`](#ext-zz) | cat_ext_ZZ @ fffa58a1 | any (11 used) | – | **no** (not in 2211-A or 2306-C) | action | high |
| X | 8 | [`VE`](#ext-ve) | cat_ext_VE @ fffa54b3 | any (4 used) | FIRMWARE VERSION | yes (2306-C) | read-only | low |
| X | 9 | [`JP`](#ext-jp) | cat_ext_JP @ fffa556b | 7/15 | – | **no** (not in 2211-A or 2306-C) | read+set | high |

**Counts.**
- 114 mnemonics in total: 104 primary and 10 extended. 92 are documented in 2306-C, and `XT` is one of them.
- 22 are **not** documented in 2306-C: `BY E8 E9 ED EK EM EN EU EO FD FS JP KT PE QS RC RD RS RT RU SP ZZ`. `EO` was still in 2211-A.
- Of the undocumented ones, 12 do nothing: they answer `?;` or are ignored.
  - Switch default: `BY ED EK EU RC RD RS RT RU`.
  - Stubs that only set the error flag: `EN FS QS`.
  - In the table but no case: `KT`.
- The rest (`EM EO E8 E9 FD JP PE SP ZZ`) are real functions, described below.

## Firmware vs manual differences

Found by comparing the dispatch length tests and the handlers against the manual's Set/Read/Answer rows. Only the differences are listed here.

| Command | Manual 2306-C | Firmware V01-12 | Tag |
|---|---|---|---|
| `XT` (TX CLAR) | Documented `XTP1;` / `XT;` | **No case**: always `?;`. The clarifier RX/TX flags are set through `CF` P3=0 instead. | [fact] 0xFFFA4E26 |
| `VE` | Read `VEP1;` (P1 0 MAIN, 1 DISPLAY, 2 SDR, 3 DSP), answer `VEP1P2P2P2P2;` | No length check. P1 0..3 selects version strings at 0xFFFFFF00 (`V01-12`), 0x1436, 0x144A and 0x1444. The answer is `VE` + P1 + 4 chars, e.g. `VE00112;`. **`VE;` (the 2211-A form) answers `?;`**: P1=';' fails `hex2nib`. | [fact] 0xFFFA54B3, 0xFFF94BCD..0xFFF94C4B |
| `EO` | Removed in 2306-C (2211-A: set-only `EOP1P2P3P4P5P5P5;`) | Still implemented, see [EO](#ext-eo). The firmware accepts P1 0..2, while 2211-A says P1 is fixed at 0, and P1 is otherwise ignored. | [fact] 0xFFFA5C90 |
| `VM` | Set `VM;` only | `VM;` toggles V/M. **Hidden:** `VM0;` reads a 2-hex-digit state code (`00`, `10`, `11`, `20`, `21`, `51`, `91`: VFO / memory / PMS / 5 MHz-channel ranges). `VM000;` forces the mode back to state 1 (VFO). | [fact] 0xFFFAFADB; meanings [inference] |
| `VD` | Drawn as `VDP1P1P1P1;` (7) with values 00–33 | Read `VD;`, set `VDnn;` (5): **2 digits**, 00–33. The manual drawing is wrong. | [fact] dispatch case 0xFFFA4CD9 |
| `MT` | Set length 19 (tag of up to 12 characters, padded) | Set accepts lengths 8..19, so shorter, unpadded tags work too. | [fact] dispatch case 0xFFFA4589 |
| `EX` | Read 9, set 10..21 | Read 9, set any length ≥ 10 (no upper bound in the case; the menu engine limits the value). Menu groups `01 02 03 04 06` are accepted, while `05` and `00` give `?;`. | [fact] 0xFFFA4097, `ex_command` |
| `ID` | `ID0800;` | Constant `ID0800;` | [fact] |
| `AI` | P1 0/1 | Accepts any character ≤ `'1'`. A character below `'0'` stores 0xFF ("on" for some tests, "off" for others) | [fact] 0xFFFA6946 |
| `PS` | Read answers `PS0`/`PS1` | Read always answers `PS1;`. While the radio is off, the parser drops `PS;` before the handler runs. | [fact] 0xFFFAD696 |
| `GT` | Set P2 0..4 | Set accepts 0..4, but read can return 5 or 6 (AUTO-x reported per mode class) | [fact], see primary details |
| `MX` | Listed (MOX SET), no detail page | `MX;` / `MX0;` / `MX1;`. `MX1` keys TX through the key-event gate 0x302 | [fact] |
| `AG RG` | 000–255 | 3 digits stored **mod 256** with no range check (`AG300` → 44) | [fact] |
| `PE`/`FD`/`JP`/`ZZ`/`SP`/`E8`/`E9`/`EM` | not documented | see below | |

Several handlers also leave a pointer or reply byte uninitialized when a selector digit is out of range (`CN`, `OS`, `PE`, `MR`, `PR`; see the details). An invalid selector can therefore write to an arbitrary RAM address. **Never fuzz set commands on the radio.** [inference from decompile, flagged for disassembly]

## Extended table

Dispatch: `cat_dispatch_ext` @ 0xFFFA3A2A (compare chain); `SP` is decoded in `cat_ext_SP` @ 0xFFFA36F2, and `E9` is reached only through the E9 fast path. Text positions below count from the first letter of the mnemonic (position 0).

<a id="ext-sp"></a>
### SP — service / debug command family (undocumented, high risk)

The sub-command letter is at position 2. The read/write letter is at position 3, in either case unless noted. All of these are **[fact]** from `cat_ext_SP` and its helpers. The meanings of the targets are tagged separately.

| Form | Class | Handler | What it does |
|---|---|---|---|
| `SPSRaaaa;` → `SPSRvvvv;` | read | `cat_SP_sdr_reg` 0xFFFA4E31 → `sdr_reg_access` 0xFFFA1485 | Reads 16-bit register `aaaa` (hex) of the **SDR unit** over SCI5. The SDR link frame is `r` + 4 hex + 2-hex sum + CR. **[fact]** for SCI5; SCI5 = SDR link per T05. |
| `SPSWaaaavvvv;` | set | same | Writes `vvvv` to SDR register `aaaa`. No reply on success; `?;` if the SDR does not ACK. **High risk**: it writes SDR/FPGA registers directly. |
| `SPDRaaaa;` / `SPDWaaaavvvv;` | read / set | `cat_SP_dev4_reg` 0xFFFA4E8F → `dsp_reg_access` 0xFFF9D8A4 | Same protocol on **SCI4** (device unknown; perhaps the IF-DSP **[guess]**). High risk for the write. |
| `SPIR;` → `SPIR` + 12×3 hex + `;` (41 chars) | read | `cat_SP_adc_dump` 0xFFFA4EED | Raw 12-bit ADC results from 0x20B04..0x20B16 in the order 0, AN001, AN002, AN003, 0, AN005, 0, AN007, AN115, AN117, AN108, AN109 (S12AD/S12AD1). Low risk. |
| `SPR<aH><aL><x><sum>;` (binary) | read | `cat_SP_eeprom_byte` 0xFFFA520B | Reads one **EEPROM** byte at 16-bit address aH:aL and answers `SPR aH aL <byte> <sum>;` (8 bytes). Upper-case `R` only. |
| `SPW<aH><aL><byte><sum>;` (binary) | set | same | **Writes one EEPROM byte** and the RAM mirror 0x464F[addr]. Upper-case `W` only. **High risk** (raw EEPROM write, no bounds). |
| `SPN{R\|W\|S}<iH><iL>[<byte>]<sum>;` (binary) | read / set | `cat_SP_table` 0xFFFA50F9 | Index 1..0x105 into the 261-byte table `cfg105` @ 0x4659 (EEPROM 0x000A..0x010E). `W` sets an entry in RAM. `S` schedules `FUN_fffbff93` (a re-apply) 500 ms later. `R` also sets 0x20CE2 = idx-1 and calls `FUN_fffbb567`, which loads ROM preset idx-1 (12-byte records at 0xFFF88CD4) into the active VFO. Answer: `SPN <byte> <sum>;`. Meaning of the table: not known **[guess: per-preset/per-channel flags]**. |
| `SPM...<sum>;` (binary) | read | `cat_SP_meters` 0xFFFA5284 | Answers `SPM` + 8 binary bytes (0x1204A, 0x12048/0x1204B, and four more meter getters 0xFFFB6E03..0xFFFB6E98) + 3 zero bytes + sum + `;` (16 bytes). These are meter readings **[inference]**. |
| `SPAWE<sum>;` (binary) | set | `eeprom_save_cfg105` 0xFFFB0532 | Writes the whole 0x4659 table to EEPROM 0x000A. **High risk.** |

- **Checksum.** The binary forms use `cat_checksum_ok` (8-bit additive sum of the preceding bytes, compared with the next byte).
- **Checksum length bug.** In V01-12 the length argument is read from RAM address `len-2` instead of being `len-2`.
  - Evidence (disassembly): 0xFFFA3861..0xFFFA3869, 0xFFFA38BE..0xFFFA38C4, 0xFFFA39B5..0xFFFA39BB, 0xFFFA5104..0xFFFA510A.
  - Consequence: these five sub-commands **probably always answer `?;`** **[inference]**. See [cat.md](code/main/cat.md#extended-and-service-commands-summary).
- **Not affected.** The ASCII forms `SPS`, `SPD` and `SPIR` have no checksum and are fully functional **[fact]**.

<a id="ext-eo"></a>
### EO — encoder offset (in 2211-A, removed in 2306-C; medium)
`EO P1 P2 P3 P4 P5P5P5;` (length 10 exactly), handled by `cat_ext_EO` 0xFFFA5C90. **[fact]**
- **P1:** 0..2. It is checked, but its value is not used.
- **P2 = 0, MAIN dial:** retunes the active VFO by ±P5 (000–999) × 1 Hz, 1 kHz or 1 MHz (P4 = 0, 1, 2). The result is clamped to 30 kHz..75 MHz, the same limits as `FD`.
- **P2 = 1, FUNC knob:** turns it by ±P5 steps (`enc2_step`, ±127 max).
- **P2 = 2, STEP/MCH knob:** turns it by ±P5 steps (`enc3_step`) and sets 0x20B74 = 1.
- **Side effect:** before acting, it **clears eight mode flags**: 0x20F3B, 0x20B8A, 0x20B99, 0x20BBE, 0x20B97, 0x20B98, 0x20B9A, 0x20B9B. One of them is the `ZZ` mode flag 0x20BBE, so `EO` also leaves that mode.
- **No reply.** Medium risk: it changes the frequency, and it can move menu or knob values.

<a id="ext-e8"></a>
### E8 — settings-image dump (undocumented; read-only, large)
`E8…;` with any length. `cat_ext_E8` 0xFFFA53A4 answers in one frame of **10674 bytes**: **[fact]**

`E8` k, k+7, k+0x90, k, k, then 10665 data bytes, then the sum, then `;`.
- **k:** a pseudo-random key, `cat_rand8` = timer counter 0x88116 mod 255.
- **Data bytes:** each is `settings_image[i] + k`, taken from 0x60C9..0x8A71 (the EEPROM-backed settings and memory-channel image).
- **Sum:** the 8-bit sum of the plain bytes, plus k.

This is the obfuscated **clone/backup** export: header bytes 07 90 after removing k. It does not change the radio, but it floods the port. Low risk. Note that the reply overwrites RAM 0x1C8E..0x463F, which is the reply buffer.

<a id="ext-e9"></a>
### E9 — settings-image restore (undocumented; high risk)
Only frames that start with `E9` (or `E1`, which is then ignored) received into the fast-path slot 0x1B78C reach `cat_ext_E9` 0xFFFA5985. **[fact]**
1. It subtracts the key byte from every data byte.
2. It checks the 0x07 0x90 signature and the sum.
3. It copies 10665 bytes to 0x60C9 and calls `eeprom_save_image` (EEPROM 0x1A7A, 0x2F49 bytes).

- **Errors:** a bad signature or checksum answers `?;`.
- **Risk:** **high**. It overwrites all settings and memory channels in EEPROM, and a malformed image can corrupt the configuration.
- **Normal path:** `E9` received through the normal ring (impossible in practice) has no case and is ignored.

<a id="ext-fd"></a>
### FD — band/selector frequency (undocumented; medium)
`cat_ext_FD` 0xFFFA5A51. Positions 2–3 must be `00`, and position 4 is the selector n. **[fact]**
- **Read `FD00n;` (6):** answers `FD00n` + 9 decimal digits.
  - n = 0: u32 at 0x20F5C.
  - n = 1: u32 at 0x20F60.
  - n = 2: band-memory frequency of the band that contains the active VFO frequency. Bands come from `band_of_freq` 0xFFFB33E5 (12 ranges at 0xFFF8876C). The value is from 0x9C99 + 4·band, with sub-slots at 0x9CC9 for band 11.
- **Set `FD002ddddddddd;` (15):** only n = 2. The 9-digit Hz value must satisfy 30000 < f < 75,000,001. It is written into the band memory of the band that contains the active frequency (`bandmem_set`).
- **AI:** `cat_ai_FD` broadcasts `FD00n<9 digits>;`, with n from 0x9C35, when the value changes. This is the only undocumented AI message.
- **Meaning:** not known. A per-band "last frequency"/band-stack slot used by `BS` is plausible **[guess]**.
- **Risk:** medium (persistent band memory).

<a id="ext-kt"></a>
### KT (undocumented; none)
`KT` is in the table, but `cat_dispatch_ext` has no case for index 5, so it gets no reply and no error. **[fact]** It may be a leftover from another model **[guess]**.

<a id="ext-pe"></a>
### PE — 18 byte parameters, probably parametric EQ (undocumented; medium)
`cat_ext_PE` 0xFFFA5FDF. **[fact]**
- **Read `PEabc;` (6) and set `PEabcddd;` (9):** a ∈ {0, 2}, b ∈ {0, 1, 2}, c ∈ {0, 1, 2}. These select bytes 0x9ADA..0x9AE2 (a = 0) and 0x9AE3..0x9AEB (a = 2).
- **c = 0 or 2:** unsigned 3 digits (`PEabcnnn`).
- **c = 1:** signed, `PEab1±nn`, with the reply `PEab1±nn;`.
- **No range check:** digits are stored mod 256.
- **Invalid selectors:** if a or b is outside the sets above, the target pointer is uninitialized. **A set can then write to an arbitrary RAM address.**
- **AI:** if AI is on, the AI holdoff is armed.
- **Meaning:** the 2 sets × 3 bands × (frequency, ±level, bandwidth) shape matches the 3-band parametric MIC EQ, normal and processor-on **[inference]**. The manual exposes these values only through `EX` menu items.
- **Risk:** medium, high for invalid selectors.

<a id="ext-zz"></a>
### ZZ — factory reset / mode (undocumented; high risk)
`cat_ext_ZZ` 0xFFFA58A1, form `ZZPE0710xx;`. **[fact]**
- **Format:** positions 2–3 must be `PE`. Positions 4–7 must be hex `0710`, the model number. xx (hex) selects the action:
  - **`99`:** `settings_defaults(1)`, which loads ROM defaults including the 0x4659 table and destination 0x8043. Then it writes the 0x105 table (`eeprom_save_cfg105`) and the destination (`eeprom_save_dest`) to EEPROM, and sets the restart request 0x20F4B = 1, 0x20B39 = 0x11. **This is a full factory reset.**
  - **`01`:** `settings_defaults(0)` plus the restart request. This resets VFO, memory and menu RAM to defaults (a "reset" without the 0x105 table).
  - **`00`:** sets 0x20BBE = 1. In that mode `key_event_filter` refuses key codes < 8 and 0x16..0x19. It is cleared by `EO`. The purpose of this mode is not known **[guess: test/demo or lock mode]**.
- **Errors:** anything else answers `?;`. No reply on success.
- **Restart request:** 0x20B39 = 0x10 is what `PS0` uses, so 0x11 is a related power-off/restart code **[inference]**.

<a id="ext-ve"></a>
### VE — firmware version (documented)
See the differences table. `VE0;` → `VE00112;` on V01-12 **[inference from the string at 0xFFFFFF00; chars 1, 2, 4, 5 of "V01-12"]**.

<a id="ext-jp"></a>
### JP — destination (region) code (undocumented; high risk)
`cat_ext_JP` 0xFFFA556B. Positions 2–5 must be hex `0710`. **[fact]**
- **Read `JP0710;` (7):** answers `JP0710` + `HHLL` (destination code from 0x475E/0x475F, EEPROM 0x010F) + two inverted bytes (check bytes, ~HH ~LL **[inference: disassembly to confirm]**) + 10 hex digits of the EEPROM header 0x464F..0x4653. Total 25 characters.
- **Set `JP0710hhll~h~l;` (15):**
  - The two bytes must be followed by their complements.
  - Codes 0x306F, 0xB5A7, 0x9CF7, 0xA4C5 and 0x50E2 are remapped to 0xD32D, 0xA983, 0x7753, 0xD950 and 0x315B. Other codes are used as they are.
  - It then copies 0x20BB1..5 into the header and calls `dest_code_set`. That writes EEPROM 0x010F, reloads the defaults (`settings_defaults(0)`) and requests a restart.
- **Where the code matters:**
  - `FUN_fffb0779` tests the code for 0x020B, 0x4380 and 0x60E6 when it builds per-band tables.
  - The default is 0x8043.
  - A DISPLAY-link message can set 0xA983 (`displink_rx_F1_sys`).
- **Meaning:** the destination/version code selects the market version. Most likely it sets band limits and TX coverage **[inference]**.
- **Risk: high.** It changes the radio's region, and with it, likely, its legal TX coverage. It also resets the settings.

## Undocumented primary-table commands
| Command | What the firmware does | Risk |
|---|---|---|
| `EM` | `EM0n;` reads and `EM0n<text>;` (≤ 50 characters) writes one of five text slots at 0x979E + 0x32·(n-1) (n = 1..5), terminated by 0xFE. A 50-character text spills its terminator into the next slot. No EEPROM write was seen. These are user text or message slots **[guess]**. | low |
| `EN`, `FS`, `QS` | Stubs: the case accepts a length (EN 5, FS 3/4, QS 3), but the handler only sets the error flag, so they always answer `?;` | none |
| `BY ED EK EU RC RD RS RT RU` | In the table, but routed to the switch default, so they answer `?;` | none |

## High-risk commands (documented ones included)
The rows below are summaries. The evidence is in the primary details and in the extended sections above.
- **Keys the transmitter.**
  - `TX1`: flag 0x20B28, TX source 5. It is not gated by the key filter and has no timeout.
  - `MX1`.
  - `KY` (CW message playback) and `PB` (voice message playback).
  - `LM` (message start).
  - `AC` tune start (P3 = 3), and ATAS tuning.
- **Powers off.** `PS0`.
- **Persistent or service data.**
  - Memory channel EEPROM writes: `AM`, `BM`, `MW`, `MT`, `CH`. They go through `eeprom_save_memch`.
  - `KM`: EEPROM on every set.
  - `EX`: about 300 menu items.
  - `DT`: RTC.
  - `GP`: drives MCU output ports 0x8C021, 0x8C022 and 0x8C025 directly when 0x9AB7 == 3.
  - Undocumented: `SP*`, `E9`, `ZZ`, `JP`.
