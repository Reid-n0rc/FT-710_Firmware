#!/usr/bin/env python3
"""Decode an FT-710 EEPROM dump (MAIN V01-12 layout) into the fields documented in docs/code/main/eeprom.md.

Usage: python3 -I tools/eeprom_decode.py EEPROM.BIN [--main build/FT-710_MAIN_V0112.bin] [--private] [--all-cal]

EEPROM.BIN is the 22,583-byte dump that `tools/cat_backup.py --eeprom` writes (EEPROM 0x0000..0x5836; the radio keeps a RAM
mirror of it at RAM = 0x464F + EEPROM address, and this script names fields by their RAM address, as the docs do).

What it prints:
  - the header (date stamp, save counter, clean/dirty flag) and the destination (region) code;
  - the calibration table cfg105 (EEPROM 0x000A, RAM 0x4659): the 261 factory-alignment items with the names the firmware's
    alignment menu shows (`SPN` index = item number), grouped; reserved items are only listed when they are not 0xFF;
  - band stacks, memory-channel header, QMB, keyer/text slots and tuner memory as counts and checks;
  - selected operating-state values (front-panel block 0x9BC9.., VFO records, active VFO, bands).
Every section ends with the checks it ran ("ok" or what disagreed with the documented layout).

Privacy: frequencies, memory tags, keyer/text messages and tuner-memory frequencies are personal data. They are printed only
with --private. Without it the output is meant to be safe to paste into an issue.

--main  also reads the MAIN image: checks the alignment-name table at 0xFFF817C3 against the names built in here, and prints
        the ROM default (cfg105_defaults 0xFFF8074F) next to each calibration value, marking the items the factory changed.
--all-cal  prints every cfg105 item, including reserved ones.

Read-only; standard library only. Run with python3 -I (the dump is untrusted data).
"""
import argparse
import struct
import sys

RAM0 = 0x464F
EE_LEN = 0x5837
ROM_BASE = 0xFFF80000
ROM_LEN = 0x80000
ROM_CAL_DEFAULTS = 0xFFF8074F
ROM_CAL_NAMES = 0xFFF817C3      # 261 x 25 chars: " 001 [GN] VDD MTR        "

BANDS = ["1.8", "3.5", "5", "7", "10", "14", "18", "21", "24", "28", "50", "GEN"]
BAND_LIMITS = [(1800000, 2000000), (3500000, 4000000), (5000000, 5500000), (7000000, 7500000), (10000000, 10500000),
               (14000000, 14500000), (18000000, 18500000), (21000000, 21500000), (24500000, 25000000),
               (28000000, 30000000), (50000000, 54000000), (30000, 75000001)]
# FUN_fffb3371: TX range index (upper limits at ROM 0xFFF8870C), used by the tuner and the power tables.
TUNER_RANGES = [2100000, 4700000, 7500000, 11500000, 14500000, 20900000, 22000000, 25500000, 41500000, 60000000, 75000001]
TUNER_NAMES = ["1.8", "3.5", "5-7", "10", "14", "18", "21", "24", "28", "50", "70"]
MODES = ["LSB", "USB", "CW-L", "CW-U", "AM", "AM-N", "FM", "FM-N", "DATA-L", "DATA-U", "DATA-FM", "DATA-FM-N",
         "RTTY-L", "RTTY-U", "PSK", "(15)"]


def cal_names():
    """The 261 cfg105 item names, in the form the alignment menu (ROM 0xFFF817C3) shows them."""
    n = []
    n += [("GN", s) for s in ["VDD MTR", "FAN", "REF FREQ", "TX INH", None, None, None, "DBG MODE ENABLE"]]
    n += [("MT", "PO MTR %3dW POS" % w) for w in (100, 50, 20, 10, 5)]
    n += [("MT", s) for s in ["ALC MTR POS", "VDD MTR POS", "IDD MTR POS", "SWR 1.5 MTR POS", "SWR 2.0 MTR POS",
                              "SWR 3.0 MTR POS", None, None, None]]
    n += [("RX", "RF-AGC %2s" % b) for b in ("7", "14", "21", "28", "50")]
    n += [("RX", "IF-AGC %2s" % b) for b in ("7", "14", "21", "28", "50")]
    n += [("RX", "S-MTR %s" % s) for s in ("0", "2", "5", "7", "9", "+10", "+20", "+30", "+40", "+50", "+60")]
    n += [("RX", None), ("RX", None), ("RX", "FM SQL THW"), ("RX", "FM SQL THN"), ("RX", "FM SQL TI"),
          ("RX", "SCOPE SDR REF")]
    n += [("TX", "%s %s BIAS" % (g, s)) for g in ("MF", "HF", "VHF") for s in ("PREDR", "DRIVE", "FINAL")]
    n += [("TX", "I-ALC %s" % b) for b in ("1.8", "3.5", "7", "10", "14", "18", "21", "24", "28", "50", "70")]
    for b in ("1.8", "3.5", "7", "10", "14", "18", "21", "24", "28", "50"):
        for w in (100, 50, 20, 10, 5):
            n += [("TX", "%3dW %-4s %s" % (w, k, b)) for k in ("FALC", "MTR", "TXG")]
    n += [("TX", None)] * 3
    for w in (50, 20, 10, 5):
        n += [("TX", "%3dW %-4s 70" % (w, k)) for k in ("FALC", "MTR", "TXG")]
    n += [("TX", "REV ALC %s" % b) for b in ("1.8", "3.5", "7", "10", "14", "18", "21", "24", "28", "50", "70")]
    n += [("TX", "ALC MTR")] + [("TX", None)] * 14 + [("TX", "IDD MTR")]
    assert len(n) == 0x105, len(n)
    return n


# What reads each item, from decomp/main (docs/code/main/eeprom.md, "cfg105").
CAL_USERS = {
    0: "vdd_scale_calc (VDD meter); align: AN003 PA_VDD >> 4",
    1: "pa_dac_update: fan on below this PA_HF_TH reading, off above it + 10",
    2: "main_dac_update: BU2505 Q1005 ch3 FADJ = (value - REF FREQ menu) * 4",
    3: "tx_freq_allowed: TX refused when non-zero",
    7: "displink_build_60, menu_m4_18_0_draw",
    13: "meter_alc", 14: "vdd_scale_calc", 15: "meter_idd",
    16: "swr_meter_protect", 17: "swr_meter_protect", 18: "swr_meter_protect",
    40: "meter_s reference, FUN_fffb7e61",
    45: "FUN_fffb7cec (FM squelch)", 46: "FUN_fffb7cec (FM squelch)", 47: "FUN_fffb7cec (FM squelch)",
    48: "sdr_upd_r27_scope_level",
    245: "meter_alc divisor; align: AN005 x ALC MTR POS / 137",
    260: "meter_idd divisor",
}


def cal_user(i):
    if i in CAL_USERS:
        return CAL_USERS[i]
    if 22 <= i <= 26:
        return "main_dac_update: Q1005 ch5 by RX band"
    if 27 <= i <= 31:
        return "dsp_set_freq_range_param: IFDSP reg 0x63 (IF AGC gain ceiling)"
    if 49 <= i <= 57:
        return "pa_dac_update: Q4041 ch5/ch4/ch3 (PBIAS/DBIAS/FBIAS) by band group"
    if 58 <= i <= 68:
        return "pa_dac_update: Q4041 ch10 IALC"
    if 234 <= i <= 244:
        return "pa_dac_update: Q4041 ch1 RALC"
    if 69 <= i <= 233:
        k = (i - 69) % 3
        if 219 <= i <= 221:
            return ""
        if k == 0:
            return "FUN_fffb667a -> pa_dac_update Q4041 ch2 FALC (interpolated by power)"
        if k == 2:
            return "sdr_upd_r25_tx_drive: SDR reg 0x25 (interpolated by power)"
        return "100 W item: PO meter scale 0x20B1E" if (i - 69) % 15 == 1 or i == 223 else "stored only"
    return ""


def u16(b, o):
    return struct.unpack(">H", b[o:o + 2])[0]


def u32(b, o):
    return struct.unpack(">I", b[o:o + 4])[0]


class Dump:
    def __init__(self, data):
        self.d = data

    def ram(self, a, n=1):
        o = a - RAM0
        return self.d[o:o + n]

    def b(self, a):
        return self.d[a - RAM0]


def fmt_hz(f):
    return "%d.%06d MHz" % (f // 1000000, f % 1000000)


def record(x):
    """The 90-byte VFO/memory record (docs/code/main/radio-control.md)."""
    return {
        "mode": x[0] & 15, "b0hi": x[0] >> 4, "b1": x[1], "b2": x[2], "b3": x[3], "nar": x[4], "b5": x[5], "dnr": x[6],
        "u7": x[7], "u8": x[8], "u9": x[9], "tone": x[0x46], "u47": x[0x47],
        "clar": struct.unpack(">h", x[0x48:0x4A])[0], "f": u32(x, 0x4A), "tag": x[0x4E:0x5A],
    }


def record_checks(r, where, band=None):
    p = []
    if r["dnr"] & 0xE0:
        p.append("%s: +0x06 bits 5-7 set (%02X)" % (where, r["dnr"]))
    if r["u7"] or r["u9"] or r["u47"]:
        p.append("%s: +0x07/+0x09/+0x47 not 0 (%02X %02X %02X)" % (where, r["u7"], r["u9"], r["u47"]))
    if r["u8"] and not (band == 10 and r["u8"] == 1):
        p.append("%s: +0x08 = %d (the defaults write 1 only for the 50 MHz band stack)" % (where, r["u8"]))
    if r["tone"] > 49:
        p.append("%s: tone number %d > 49" % (where, r["tone"]))
    if not -9999 <= r["clar"] <= 9999:
        p.append("%s: clarifier %d out of range" % (where, r["clar"]))
    if not 30000 <= r["f"] <= 75000000:
        p.append("%s: frequency outside 30 kHz..75 MHz" % where)
    elif band is not None and not BAND_LIMITS[band][0] <= r["f"] < BAND_LIMITS[band][1] and band != 11:
        p.append("%s: frequency outside its band" % where)
    if not all(0x20 <= c <= 0x7D for c in r["tag"]):
        p.append("%s: tag has bytes outside 0x20..0x7D" % where)
    return p


def show_checks(p):
    print("  checks: " + ("ok" if not p else "%d finding(s)" % len(p)))
    for s in p:
        print("    - " + s)


def section(t):
    print("\n== " + t)


def do_header(m):
    section("Header (EEPROM 0x0000, RAM 0x464F)")
    h = m.ram(0x464F, 10)
    print("  date/time stamp (BCD yy mm dd hh mm, set by JP): %02X-%02X-%02X %02X:%02X" % tuple(h[:5]))
    print("  save counter: %d (+2 per block save)" % u32(h, 5))
    print("  state flag: %d (%s)" % (h[9], {0: "save was interrupted", 1: "clean"}.get(h[9], "unexpected")))
    dest = u16(m.ram(0x475E, 2), 0)
    print("  destination code (0x475E): 0x%04X, flag 0x4760 = %d" % (dest, m.b(0x4760)))
    p = []
    if h[9] != 1:
        p.append("state flag is not 1: the next boot would load defaults except calibration and destination")
    if m.b(0x4760) not in (0, 1):
        p.append("flag 0x4760 is not 0/1")
    show_checks(p)


def do_cal(m, rom, all_cal):
    section("cfg105 calibration / alignment table (EEPROM 0x000A, RAM 0x4659); item n = SPN index n = menu number n")
    names = cal_names()
    cal = m.ram(0x4659, 0x105)
    dflt = None
    p = []
    if rom:
        dflt = rom[ROM_CAL_DEFAULTS - ROM_BASE:ROM_CAL_DEFAULTS - ROM_BASE + 0x105]
        bad = 0
        for i, (g, s) in enumerate(names):
            o = ROM_CAL_NAMES - ROM_BASE + 25 * i
            want = " %03d [%s] %-15s" % (i + 1, g, s if s else "--RESERVED--")
            got = rom[o:o + 25].decode("latin-1")
            if got.rstrip() != want.rstrip():
                bad += 1
        print("  ROM name table 0xFFF817C3: %s" % ("matches" if not bad else "%d names differ" % bad))
    changed = 0
    for i, (g, s) in enumerate(names):
        v = cal[i]
        if s is None:
            if v != 0xFF:
                p.append("reserved item %03d is %d, not 0xFF" % (i + 1, v))
            if not all_cal:
                continue
        mark = ""
        if dflt is not None:
            mark = " (ROM %3d)%s" % (dflt[i], " *" if dflt[i] != v else "  ")
            changed += dflt[i] != v
        print("  %03d 0x%04X [%s] %-16s %3d%s  %s" % (i + 1, 0x4659 + i, g, s or "--RESERVED--", v, mark, cal_user(i)))
    if dflt is not None:
        print("  %d of 261 items differ from the ROM defaults (* = factory-aligned or user-changed)" % changed)
    if cal[3]:
        p.append("TX INH (item 004) is non-zero: TX is disabled")
    if cal[7]:
        p.append("DBG MODE ENABLE (item 008) is non-zero")
    show_checks(p)


def do_bandstack(m, private):
    section("Band stacks (EEPROM 0x0112 / 0x0DBA; RAM 0x4761 / 0x5409)")
    p = []
    for side, base, cur in (("A", 0x4761, 0x60B1), ("B", 0x5409, 0x60BD)):
        lv = list(m.ram(cur, 12))
        print("  VFO-%s current level per band: %s" % (side, " ".join(str(x) for x in lv)))
        p += ["VFO-%s band %s: level %d > 2" % (side, BANDS[i], x) for i, x in enumerate(lv) if x > 2]
        for lvl in range(3):
            row = []
            for band in range(12):
                r = record(m.ram(base + lvl * 0x438 + band * 0x5A, 0x5A))
                p += record_checks(r, "VFO-%s level %d band %s" % (side, lvl, BANDS[band]), band)
                row.append("%s%s" % (MODES[r["mode"]], ("@" + fmt_hz(r["f"])) if private else ""))
            print("    level %d: %s" % (lvl, ", ".join(row)))
    show_checks(p)


def do_memories(m, private):
    section("Memory channels (header EEPROM 0x1A7A / RAM 0x60C9, records 0x6150)")
    def chname(i):
        if i < 99:
            return "%03d" % (i + 1)
        if i < 117:
            return "P%d%s" % ((i - 99) // 2 + 1, "LU"[(i - 99) % 2])
        if i < 132:
            return "%03d" % (501 + i - 117)
        return "EMG" if i == 132 else "?%d" % i
    print("  VFO-A channel %s, VFO-B channel %s" % (chname(m.b(0x60C9)), chname(m.b(0x60CA))))
    valid = m.ram(0x60CB, 133)
    groups = [("001-099", 0, 99), ("P1L-P9U", 99, 117), ("501-515 (60 m)", 117, 132), ("EMG", 132, 133)]
    print("  valid: " + ", ".join("%s %d" % (g, sum(1 for i in range(a, b) if valid[i])) for g, a, b in groups))
    p = ["valid flag %d of channel %s is not 0/1" % (v, chname(i)) for i, v in enumerate(valid) if v > 1]
    for i in range(133):
        x = m.ram(0x6150 + i * 0x5A, 0x5A)
        if not valid[i] or x == bytes(0x5A):
            continue
        r = record(x)
        p += record_checks(r, "channel " + chname(i))
        if private:
            print("    %s %-9s %s %r" % (chname(i), MODES[r["mode"]], fmt_hz(r["f"]), r["tag"].decode("latin-1")))
    show_checks(p)


def do_qmb_msgs(m, private):
    section("QMB (RAM 0x9012), messages (0x93A7 / 0x969F / 0x979E)")
    used = [n for n in range(10) if m.ram(0x9023 + n * 0x5A, 0x5A) != bytes(0x5A)]
    print("  QMB header count 0x9014 = %d, records in use: %d" % (m.b(0x9014), len(used)))
    p = []
    for n in used:
        p += record_checks(record(m.ram(0x9023 + n * 0x5A, 0x5A)), "QMB %d" % (n + 1))
    lens = [u16(m.ram(0x93A7 + n * 0x98, 2), 0) for n in range(5)]
    print("  CW message memories (type 0, bitstream): lengths %s" % lens)
    p += ["CW message %d length %d > 1200 bits" % (n + 1, x) for n, x in enumerate(lens) if x > 1200]
    km = [m.ram(0x969F + n * 0x33, 0x33) for n in range(5)]
    print("  keyer texts (KM, length + 50 chars): lengths %s" % [x[0] for x in km])
    p += ["KM %d length %d > 50" % (n + 1, x[0]) for n, x in enumerate(km) if x[0] > 50]
    em = [m.ram(0x979E + n * 0x32, 0x32) for n in range(5)]
    eml = [x.find(b"\xfe") for x in em]
    print("  text slots (EM, 50 chars, 0xFE ends the text): lengths %s" % eml)
    p += ["EM %d has no 0xFE terminator" % (n + 1) for n, x in enumerate(eml) if x < 0]
    if private:
        for n, x in enumerate(km):
            print("    KM%d %r" % (n + 1, x[1:1 + x[0]].decode("latin-1")))
        for n, x in enumerate(em):
            print("    EM%d %r" % (n + 1, x[:max(eml[n], 0)].decode("latin-1")))
    show_checks(p)


def do_tuner(m, private, rom):
    section("Tuner memory (EEPROM 0x5249, RAM 0x9898)")
    widx, cnt = m.b(0x9898), m.b(0x9899)
    print("  write index %d, entries %d" % (widx, cnt))
    p = []
    if cnt > 100 or widx > 99:
        p.append("index/count out of range")
    ents = []
    for i in range(min(cnt, 100)):
        x = m.ram(0x989A + 4 * i, 4)
        key = u16(x, 0)
        try:
            mhz = int("%04x" % key) / 100.0
        except ValueError:
            p.append("entry %d: key %04X is not BCD" % (i, key))
            continue
        ents.append((mhz, x[2], x[3]))
    print("  entry = {u16 BCD frequency key (10 kHz), TC byte 0x1B3AF -> C8..CF, AC byte 0x1B3AD -> C0..C7}")
    print("  (TC/AC are the two capacitor banks of the internal tuner; the L bank is set per band, see eeprom.md)")
    limits = None
    if rom:
        o = 0xFFF87BFC - ROM_BASE
        limits = [rom[o + 4 * k] for k in range(11)]
    lo = 0
    for k, hi in enumerate(TUNER_RANGES):
        e = [x for x in ents if lo <= x[0] * 1e6 < hi]
        lo = hi
        if not e:
            continue
        z = sum(1 for x in e if x[1] == 0 and x[2] == 0)
        print("  %-5s MHz: %3d entries (%d with both banks 0), TC %3d..%3d, AC %3d..%3d%s" % (
            TUNER_NAMES[k], len(e), z, min(x[1] for x in e), max(x[1] for x in e), min(x[2] for x in e),
            max(x[2] for x in e), "  (search max %d)" % limits[k] if limits else ""))
        if limits and max(max(x[1], x[2]) for x in e) > limits[k]:
            p.append("%s MHz: a stored value is above the search maximum" % TUNER_NAMES[k])
    if private:
        for mhz, tc, ac in sorted(ents):
            print("    %7.2f MHz TC %3d AC %3d" % (mhz, tc, ac))
    show_checks(p)


def do_opstate(m, private):
    section("Operating state (EEPROM 0x53DB, RAM 0x9A2A..0x9E85): selected fields")
    b = m.b
    print("  MIC GAIN 0x9BEC..0x9BEF: %s" % list(m.ram(0x9BEC, 4)))
    print("  processor 0x9BF0/0x9BF1: %d / %d, AMC level 0x9BF2: %d" % (b(0x9BF0), b(0x9BF1), b(0x9BF2)))
    print("  VOX gain 0x9BF3: %d, VOX delay 0x9BF4/0x9BF5: %d %d, anti-VOX 0x9BF6/0x9BF7: %d %d" % (
        b(0x9BF3), b(0x9BF4), b(0x9BF5), b(0x9BF6), b(0x9BF7)))
    print("  RF power 0x9BF8..0x9BFB: %s" % list(m.ram(0x9BF8, 4)))
    print("  keyer 0x9C02: %d, key speed 0x9C03: %d, CW pitch 0x9C04: %d (%d Hz), break-in delay 0x9C05: %d" % (
        b(0x9C02), b(0x9C03), b(0x9C04), b(0x9C04) * 10 + 300, b(0x9C05)))
    lv = [("SSB", 0x9C06, 0x9C07), ("CW", 0x9C09, 0x9C10), ("DATA", 0x9C0A, 0x9C11), ("RTTY", 0x9C0B, 0x9C12),
          ("DATA-FM", 0x9C0C, 0x9C13), ("PSK", 0x9C0D, 0x9C14), ("AM", 0x9C0E, 0x9C15), ("FM", 0x9C0F, 0x9C16)]
    print("  AESS per mode (AS1 = byte x 5, AS2 centre 0 = 700 Hz, 1 = 1000 Hz): " + ", ".join(
        "%s %d/%s" % (n, b(a) * 5, {0: "700", 1: "1000"}.get(b(c), "?%d" % b(c))) for n, a, c in lv))
    p = ["AESS level of %s is %d (> 20)" % (n, b(a)) for n, a, c in lv if b(a) > 20]
    p += ["AESS centre of %s is %d (not 0/1)" % (n, b(c)) for n, a, c in lv if b(c) > 1]
    print("  sub-dial function 0x9C08: %d" % b(0x9C08))
    tail = m.ram(0x9C17, 0x1E)
    if any(tail):
        p.append("0x9C17..0x9C34 not all 0 (ROM default 0xFFF80FD6 is 30 zero bytes)")
    print("  active VFO 0x9DBD: %s, states 0x9DBE/0x9DBF: %d/%d, bands 0x9DC3/0x9DC4: %s/%s, power on after reset 0x9DC5: %d"
          % ("AB"[b(0x9DBD) & 1], b(0x9DBE), b(0x9DBF), BANDS[min(b(0x9DC3), 11)], BANDS[min(b(0x9DC4), 11)], b(0x9DC5)))
    for side, a in (("A", 0x9D09), ("B", 0x9D63)):
        r = record(m.ram(a, 0x5A))
        p += record_checks(r, "VFO-" + side)
        print("  VFO-%s record 0x%04X: %s, DNR %s level %d, NAR flags %02X%s" % (
            side, a, MODES[r["mode"]], "on" if r["dnr"] & 0x10 else "off", r["dnr"] & 15, r["nar"],
            (", " + fmt_hz(r["f"])) if private else ""))
    show_checks(p)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("dump")
    ap.add_argument("--main", help="MAIN image (build/FT-710_MAIN_V0112.bin) for the ROM defaults and the name check")
    ap.add_argument("--private", action="store_true", help="also print frequencies, tags, messages")
    ap.add_argument("--all-cal", action="store_true", help="print reserved cfg105 items too")
    a = ap.parse_args()
    with open(a.dump, "rb") as f:
        data = f.read()
    if len(data) != EE_LEN:
        sys.exit("%s: %d bytes, expected %d (EEPROM 0x0000..0x5836)" % (a.dump, len(data), EE_LEN))
    rom = None
    if a.main:
        with open(a.main, "rb") as f:
            rom = f.read()
        if len(rom) != ROM_LEN:
            sys.exit("%s: %d bytes, expected the 512 KB MAIN image" % (a.main, len(rom)))
    m = Dump(data)
    do_header(m)
    do_cal(m, rom, a.all_cal)
    do_bandstack(m, a.private)
    do_memories(m, a.private)
    do_qmb_msgs(m, a.private)
    do_tuner(m, a.private, rom)
    do_opstate(m, a.private)


if __name__ == "__main__":
    main()
