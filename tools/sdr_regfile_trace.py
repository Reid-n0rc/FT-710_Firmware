#!/usr/bin/env python3
"""Register-file sweep logs (T24 SDR round 2): write-enable summary and the trace for tb_regfile.v -DTRACE.

Reads the log of hdl/sdr/sim/regmap_main.cpp (lines "F", "S", "P", "B", "N") and the probe list written by
tools/xc7_probe_netlist.py (OUT.names: index, cell.pin, net). Stdlib only; inputs and outputs are derived files
(build/, never commit).

Usage:
    python3 -I tools/sdr_regfile_trace.py enables NAMES LOG      per frame: the write-enable drivers that pulsed, the
                                                                register flip-flops that changed, the UART B reply
    python3 -I tools/sdr_regfile_trace.py trace NAMES LOG MAP OUT  trace for tb_regfile.v -DTRACE=OUT: the bus value
                                                                (strobe, address, data) and the 598 register flip-flops
                                                                of hdl/sdr/tb_regfile_map.vh (MAP) at every clock with a
                                                                change, starting with the full state at the S line
The bus is decoded from its flip-flops (netlist.md 5.2): strobe SLICE_X13Y86/A5FF, address bits a0..a15 and data
bits d0..d15 as in BUS_A / BUS_D below.
"""
import re
import sys

WE = 'SLICE_X13Y86/A5FF'
# one flip-flop per address bit (the netlist keeps 1-4 copies; one is enough to decode). a6..a15: the order of the
# netlist's upper address flip-flops is not settled bit by bit; every register decodes them as all-zero.
BUS_A = ['SLICE_X13Y86/AFF', 'SLICE_X14Y86/DFF', 'SLICE_X15Y85/A5FF', 'SLICE_X8Y83/AFF', 'SLICE_X10Y87/CFF',
         'SLICE_X12Y89/BFF', 'SLICE_X11Y85/BFF', 'SLICE_X12Y89/CFF', 'SLICE_X10Y87/AFF', 'SLICE_X13Y86/BFF',
         'SLICE_X13Y83/AFF', 'SLICE_X13Y84/DFF', 'SLICE_X12Y89/AFF', 'SLICE_X11Y85/CFF', 'SLICE_X12Y89/DFF',
         'SLICE_X11Y89/AFF']
BUS_D = ['SLICE_X11Y89/BFF', 'SLICE_X11Y89/B5FF', 'SLICE_X13Y86/B5FF', 'SLICE_X13Y84/D5FF', 'SLICE_X10Y87/A5FF',
         'SLICE_X8Y94/AFF', 'SLICE_X12Y89/A5FF', 'SLICE_X11Y89/A5FF', 'SLICE_X11Y85/C5FF', 'SLICE_X12Y89/D5FF',
         'SLICE_X12Y89/C5FF', 'SLICE_X11Y85/B5FF', 'SLICE_X12Y89/B5FF', 'SLICE_X15Y85/D5FF', 'SLICE_X10Y87/C5FF',
         'SLICE_X8Y94/BFF']


def read_names(path):
    names = {}
    for ln in open(path):
        i, cp, _ = ln.rstrip('\n').split('\t')
        names[int(i)] = cp
    return names


def events(log):
    """Yield ('F', clock, frame), ('S', clock, {index: bit}), ('P', clock, index, value), ('B', clock, byte)."""
    for ln in open(log):
        p = ln.split()
        if not p:
            continue
        try:
            if p[0] == 'F' and len(p) == 3:
                yield 'F', int(p[1]), p[2]
            elif p[0] == 'S':
                ws = [int(x, 16) for x in p[2:]]
                yield 'S', int(p[1]), {i: (ws[i // 32] >> (i % 32)) & 1 for i in range(32 * len(ws))}
            elif p[0] == 'P' and len(p) == 4:
                yield 'P', int(p[1]), int(p[2]), int(p[3])
            elif p[0] == 'B' and len(p) == 3:
                yield 'B', int(p[1]), p[2]
        except ValueError:          # a line cut off at the end of an unfinished log
            return


def cmd_enables(names, log):
    ffs = {i for i, n in names.items() if n.endswith('FF.Q')}
    cur = None
    out = []
    for ev in events(log):
        if ev[0] == 'F':
            cur = [ev[2], set(), set(), []]
            out.append(cur)
        elif ev[0] == 'P' and cur is not None:
            i = ev[2]
            if i not in ffs and ev[3] == 1:
                cur[1].add(names[i].rsplit('.', 1)[0])
            elif i in ffs:
                cur[2].add(names[i].rsplit('.', 1)[0])
        elif ev[0] == 'B' and cur is not None:
            cur[3].append(ev[2])
    for fr, en, ch, rep in out:
        print(fr, 'reply', ''.join(rep) or '-', 'enables', ','.join(sorted(en)) or '-', 'changed', len(ch))
    return 0


def cmd_trace(names, log, mapf, outp):
    idx = {v.rsplit('.', 1)[0]: k for k, v in names.items() if v.endswith('.Q')}
    order = []
    for ln in open(mapf):
        m = re.match(r'`RB\((\S+), r[0-9a-f]+, \d+, (\d+)\)', ln)
        if m:
            order.append(re.sub(r'^(SLICE_X\d+Y\d+)_', r'\1/', m.group(1)))
    need = [idx[c] for c in order]
    wi, ai, di = idx[WE], [idx[c] for c in BUS_A], [idx[c] for c in BUS_D]
    state, last, n = None, None, 0
    with open(outp, 'w') as f:
        def emit(clk):
            nonlocal n
            we = state[wi]
            a = sum(state[i] << k for k, i in enumerate(ai))
            d = sum(state[i] << k for k, i in enumerate(di))
            v = 0
            for k, i in enumerate(need):
                v |= state[i] << k
            f.write('%d %x %04x %04x %x\n' % (clk, we, a, d, v))
            n += 1
        for ev in events(log):
            if ev[0] == 'S':
                state = dict(ev[2])
                last = ev[1]
            elif ev[0] == 'P' and state is not None:
                if ev[1] != last:
                    emit(last)
                    last = ev[1]
                state[ev[2]] = ev[3]
        if state is not None:
            emit(last)
    print('%d trace lines -> %s' % (n, outp))
    return 0


def main(argv):
    if len(argv) == 3 and argv[0] == 'enables':
        return cmd_enables(read_names(argv[1]), argv[2])
    if len(argv) == 5 and argv[0] == 'trace':
        return cmd_trace(read_names(argv[1]), argv[2], argv[3], argv[4])
    sys.exit(__doc__)


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
