#!/usr/bin/env python3
"""Look for CRC logic in the SDR FPGA (#84): CRC tables or the polynomial in BRAM, and XOR-linear register groups in the netlist.

Usage: python3 -I tools/xc7_crc_search.py build/sdr/FT-710_SDR_V0104.fasm build/sdr/netlist.json

1. BRAM: rebuilds every RAMB18 half from the FASM INIT_xx lines and searches for the first entries of the CRC-32 tables (MSB-first
   BZIP2 0x04C11DB7.., LSB-first 0x77073096..) as 32-bit words and as 16-bit halves, the CRC-16 tables (0xA001 / 0x8005), and the two
   CRC-32 polynomials at any bit offset.
2. Logic: groups flops that feed each other through LUT/MUXF/CARRY logic and scores each group by the share of its LUTs that are
   affine (XOR/XNOR of their inputs): CRC and LFSR next-state logic is linear over GF(2), counters and FSMs are not. Adders also
   score high (sum bits are XORs), so check a candidate's cone sizes: an adder's grow in steps (each bit depends on all lower bits).
Stdlib only.
"""
import json
import re
import sys
from collections import defaultdict


def bram_search(fasm_path):
    init = defaultdict(dict)
    for line in open(fasm_path):
        m = re.match(r"(\S+)\.INIT_([0-9A-F]{2})\[(\d+):0\] = \d+'b([01]+)", line)
        if m:
            init[m.group(1)][int(m.group(2), 16)] = int(m.group(4), 2)
    tables16 = {"CRC-32 MSB lo": [0x1DB7, 0x3B6E, 0x26D9], "CRC-32 MSB hi": [0x04C1, 0x0982, 0x0D43],
                "CRC-32 LSB lo": [0x3096, 0x612C, 0x51BA], "CRC-32 LSB hi": [0x7707, 0xEE0E, 0x9909],
                "CRC-16 A001": [0xC0C1, 0xC181, 0x0140], "CRC-16 8005": [0x8005, 0x800F, 0x000A]}
    tables32 = {"CRC-32 MSB": [0x04C11DB7, 0x09823B6E, 0x0D4326D9], "CRC-32 LSB": [0x77073096, 0xEE0E612C, 0x990951BA]}
    hits = []
    for b, t in init.items():
        v = 0
        for k in range(64):
            v |= t.get(k, 0) << (256 * k)
        w16 = [(v >> (16 * i)) & 0xFFFF for i in range(1024)]
        w32 = [(v >> (32 * i)) & 0xFFFFFFFF for i in range(512)]
        for name, p in tables16.items():
            hits += [(b, name, i) for i in range(len(w16) - 2) if w16[i:i + 3] == p]
        for name, p in tables32.items():
            hits += [(b, name, i) for i in range(len(w32) - 2) if w32[i:i + 3] == p]
        for c in (0x04C11DB7, 0xEDB88320):
            hits += [(b, "const %08X" % c, off) for off in range(16384 - 32) if (v >> off) & 0xFFFFFFFF == c][:1]
    return len(init), hits


def linear_groups(netlist_path):
    d = json.load(open(netlist_path))
    cells = {c['name']: c for c in d['cells']}
    drv = {}
    for c in d['cells']:
        for pin, (net, io) in c['pins'].items():
            if io == 'O': drv[net] = (c['name'], pin)
    FF = {n for n, c in cells.items() if c['type'] in ('FDRE', 'FDCE', 'FDSE', 'FDPE')}
    def table(cell, pin):
        c = cells[cell]; init = c['params'].get('INIT', 0)
        if c['type'] == 'LUT6_2' and pin == 'O5': return init & 0xFFFFFFFF, 5
        n = int(c['type'][3]) if c['type'][3].isdigit() else 6
        return init, n
    def affine(init, n):
        """True if the n-input truth table is c ^ sum(a_i x_i) over the inputs it depends on."""
        size = 1 << n
        f = [(init >> i) & 1 for i in range(size)]
        c0 = f[0]
        a = [f[1 << i] ^ c0 for i in range(n)]
        return all(f[x] == c0 ^ (sum(a[i] for i in range(n) if x >> i & 1) & 1) for x in range(size))
    lutaff = {}
    def cone(net, depth, acc_ff, acc_lut):
        s = drv.get(net)
        if s is None or depth > 6: return
        cell, pin = s
        if cell in FF: acc_ff.add(cell); return
        t = cells[cell]['type']
        if t.startswith('LUT'):
            key = (cell, pin)
            if key not in lutaff: lutaff[key] = affine(*table(cell, pin))
            acc_lut.add(key)
        elif not t.startswith(('MUXF', 'CARRY')): return
        for p, (n2, io) in cells[cell]['pins'].items():
            if io == 'I' and not n2.startswith("1'b"):
                if t == 'LUT6_2' and pin == 'O5' and p == 'I5': continue
                cone(n2, depth + 1, acc_ff, acc_lut)
    dep, luts = {}, {}
    for f in FF:
        a, b = set(), set(); cone(cells[f]['pins']['D'][0], 0, a, b); dep[f], luts[f] = a, b
    parent = {f: f for f in FF}
    def find(x):
        while parent[x] != x: parent[x] = parent[parent[x]]; x = parent[x]
        return x
    for f in FF:
        for g in dep[f]:
            if g != f and (f in dep[g] or any(f in dep.get(h, ()) for h in dep[g])):
                parent[find(f)] = find(g)
    groups = defaultdict(list)
    for f in FF: groups[find(f)].append(f)
    rows = []
    for k, fs in groups.items():
        if not 6 <= len(fs) <= 64: continue
        L = set().union(*(luts[f] for f in fs))
        if not L: continue
        aff = sum(lutaff[l] for l in L) / len(L)
        s = set(fs); inner = sum(len(dep[f] & s) for f in fs)
        rows.append((round(aff, 2), len(fs), inner, len(L), sorted(fs)[0]))
    return rows


if __name__ == "__main__":
    n, hits = bram_search(sys.argv[1])
    print("BRAM: %d RAMB18 halves with INIT, %d CRC table/polynomial hits" % (n, len(hits)))
    for h in hits:
        print("  ", *h)
    print("XOR-linear register groups (affine LUT share, flops, in-group dependencies, LUTs, first flop):")
    for r in sorted(linear_groups(sys.argv[2]), reverse=True)[:15]:
        print("  ", r)
