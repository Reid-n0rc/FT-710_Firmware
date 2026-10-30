#!/usr/bin/env python3
"""SDR FPGA progress figures (T23): how much of the recovered netlist is recognized and re-implemented. Stdlib only.

The FPGA has no functions, so it is measured in cells of the netlist that tools/xc7_netlist.py recovers from the bitstream
(build/sdr/netlist.json, derived from Yaesu's bitstream: never committed). A small committed block map,
tools/sdr_blocks.tsv, names the documented blocks (docs/code/sdr/netlist.md) by seed cells, and this tool grows each block
from its seeds through fan-in / fan-out cones and writes the per-block cell counts to decomp/sdr/progress.tsv (committed:
counts only, no netlist data). tools/readability_stats.py turns that file into the SDR line of the README progress block.

Usage:
  python3 -I tools/sdr_progress.py [NETLIST.json] [--map tools/sdr_blocks.tsv] [--out decomp/sdr/progress.tsv]
  python3 -I tools/sdr_progress.py NETLIST.json --show BLOCK      also list the block's cells (stdout only)
  python3 -I tools/sdr_progress.py selftest

Block map columns (tab-separated, '#' comments, rows in priority order: a cell belongs to the first row that claims it):
  block     short name, unique
  seeds     comma-separated: a cell (SLICE_X1Y92/AFF), a site (SLICE_X1Y93, DSP48_X1Y26: every cell in it), a site
            rectangle (SLICE_X0..X2Y107..Y111, SLICE_X14Y50..X14Y54, RAMB18_X0Y50..Y59), optionally with /BEL, or
            type:IDDR (every cell of a type)
  back      fan-in depth in register stages: '-' = seeds only; 'slice:N' = exactly the sub-netlist that
            `tools/xc7_netlist_verilog.py slice --depth N` cuts (the slice an RTL file was verified against); a number N =
            fan-in through LUT/CARRY/MUX logic and at most N fabric registers (clock pins and register-driven resets are not
            followed; DSP/BRAM/MMCM/clock buffers end the cone and are only counted when they are seeds)
  fwd       fan-out depth in register stages ('-' = none), same rules, from the seeds' outputs
  stop      comma-separated cells/sites/rectangles the cones do not enter ('-' = none)
  within    comma-separated cells/sites/rectangles/types the cones stay inside ('-' = anywhere); seeds always count
  doc       the documentation section (path#anchor, relative to the repo root)
  rtl       hand-written RTL in hdl/sdr/ that re-implements the block ('-' = none)
  verified  yes when that RTL is checked against the netlist (cycle by cycle against a slice or the whole netlist, or
            byte for byte against the whole netlist); only verified blocks count as re-implemented

Figures: recovered = every cell of the netlist (100 %); recognized = cells claimed by a block of the map; re-implemented =
cells of blocks with verified RTL.
"""
import collections
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import xc7_blocks  # noqa: E402

REPO = os.path.dirname(HERE)
NETLIST = os.path.join(REPO, 'build/sdr/netlist.json')
MAP = os.path.join(REPO, 'tools/sdr_blocks.tsv')
OUT = os.path.join(REPO, 'decomp/sdr/progress.tsv')
COLS = ('block', 'seeds', 'back', 'fwd', 'stop', 'within', 'doc', 'rtl', 'verified')

SEQ = ('FDRE', 'FDSE', 'FDCE', 'FDPE', 'LDCE', 'LDPE', 'SRLC32E', 'RAMD64E', 'RAMD32')
HARD = ('DSP48E1', 'RAMB18E1', 'MMCME2_ADV', 'BUFGCTRL', 'BUFHCE', 'BUFR', 'BUFIO')
CLK_PINS = ('C', 'CLK', 'CLKARDCLK', 'CLKBWRCLK', 'RDCLK', 'WRCLK', 'RDRCLK', 'REGCLKARDRCLK', 'REGCLKB')
RST_PINS = ('R', 'S', 'CLR', 'PRE')
RANGE = re.compile(r'^([A-Z0-9_]+?)_X(\d+)(?:\.\.X?(\d+))?Y(\d+)(?:\.\.(?:X(\d+))?Y?(\d+))?(/\w+)?$')


def read_map(path):
    rows = []
    with open(path, encoding='utf-8') as f:
        for n, ln in enumerate(f, 1):
            if not ln.strip() or ln.startswith('#'):
                continue
            parts = ln.rstrip('\n').split('\t')
            if parts[0] == 'block':
                continue
            if len(parts) != len(COLS):
                sys.exit(f'{path}:{n}: {len(parts)} columns, expected {len(COLS)} ({", ".join(COLS)})')
            rows.append(dict(zip(COLS, parts)))
    names = [r['block'] for r in rows]
    dup = {b for b in names if names.count(b) > 1}
    if dup:
        sys.exit(f'{path}: duplicate block names {sorted(dup)}')
    return rows


class Index:
    """Cells by site and by type, for resolving seed specs."""

    def __init__(self, g):
        self.g = g
        self.by_site = collections.defaultdict(list)
        self.by_type = collections.defaultdict(list)
        self.sites = collections.defaultdict(list)     # prefix -> [(x, y, site)]
        for name, c in g.cells.items():
            self.by_site[c['site']].append(name)
            self.by_type[c['type']].append(name)
        for site in self.by_site:
            m = re.match(r'^([A-Z0-9_]+?)_X(\d+)Y(\d+)$', site)
            if m:
                self.sites[m.group(1)].append((int(m.group(2)), int(m.group(3)), site))

    def resolve(self, spec, where=''):
        """Cell names for one comma-separated spec list."""
        out = []
        for s in [x.strip() for x in spec.split(',') if x.strip() and x.strip() != '-']:
            if s.startswith('type:'):
                got = list(self.by_type.get(s[5:], []))
            elif s in self.g.cells:
                got = [s]
            elif s in self.by_site:
                got = list(self.by_site[s])
            else:
                m = RANGE.match(s)
                got = []
                if m:
                    pre, x0, x1, y0, x1b, y1 = m.group(1), int(m.group(2)), m.group(3), int(m.group(4)), m.group(5), m.group(6)
                    x1 = int(x1b) if x1b else int(x1) if x1 else x0
                    y1 = int(y1) if y1 else y0
                    bel = m.group(7)
                    for x, y, site in self.sites.get(pre, []):
                        if min(x0, x1) <= x <= max(x0, x1) and min(y0, y1) <= y <= max(y0, y1):
                            got += [c for c in self.by_site[site] if not bel or c == site + bel]
            if not got:
                sys.exit(f'sdr_progress: {where}: seed {s!r} matches no cell')
            out += got
        return out


def cone(g, seeds, depth, forward, stop):
    """Cells reached from `seeds` through LUT/CARRY/MUX logic and at most `depth` fabric registers.

    Backward: from input pins to drivers, never through clock pins or a reset driven by a register (a global reset).
    Forward: from output pins to sinks, not into clock/reset/enable pins. Hard blocks (DSP, BRAM, MMCM, clock buffers)
    end the walk and are not included; IOBs and ILOGIC/OLOGIC/IDDR/ODDR are included as leaves."""
    best = {c: 0 for c in seeds}
    work = collections.deque((c, 0) for c in seeds)
    while work:
        c, d = work.popleft()
        if d > best.get(c, 1 << 30):
            continue
        cc = g.cells[c]
        if cc['type'] == 'IOB' and c not in seeds:
            continue
        for p, v in cc['pins'].items():
            if forward:
                if v[1] != 'O':
                    continue
                nxt = [(x, y) for x, y in g.sinks(v[0])]
            else:
                if v[1] != 'I' or p in CLK_PINS:
                    continue
                dr = g.driver(v[0])
                if not dr:
                    continue
                if p in RST_PINS and g.ctype(dr[0]) in xc7_blocks.FF:
                    continue
                nxt = [dr]
            for x, y in nxt:
                t = g.ctype(x)
                if x in stop or t in HARD:
                    continue
                if forward and (y in CLK_PINS or y in RST_PINS or y == 'CE') and t in SEQ:
                    continue
                nd = d + (1 if t in SEQ else 0)
                if nd > depth or best.get(x, 1 << 30) <= nd:
                    continue
                best[x] = nd
                work.append((x, nd))
    return set(best)


def block_cells(g, idx, row):
    where = 'block ' + row['block']
    seeds = idx.resolve(row['seeds'], where)
    stop = set(idx.resolve(row['stop'], where + ' stop')) if row['stop'].strip() not in ('', '-') else set()
    if row['within'].strip() not in ('', '-'):
        stop |= set(g.cells) - set(idx.resolve(row['within'], where + ' within'))
    cells = set(seeds)
    back, fwd = row['back'].strip(), row['fwd'].strip()
    if back.startswith('slice:'):
        import xc7_netlist_verilog
        cells |= xc7_netlist_verilog.slice_cells({'cells': list(g.cells.values()), 'nets': g.nets}, seeds,
                                                 int(back[6:]), stop)
    elif back != '-':
        cells |= cone(g, seeds, int(back), False, stop)
    if fwd != '-':
        cells |= cone(g, seeds, int(fwd), True, stop)
    return cells


def attribute(g, rows):
    """{block: set(cells)}, each cell in the first block (map order) that reaches it."""
    idx = Index(g)
    owner, claim = {}, collections.OrderedDict()
    for row in rows:
        mine = set()
        for c in block_cells(g, idx, row):
            if c not in owner:
                owner[c] = row['block']
                mine.add(c)
        claim[row['block']] = mine
    return claim


def summarize(g, rows, claim):
    total = len(g.cells)
    out = []
    for row in rows:
        cells = claim[row['block']]
        types = collections.Counter(g.ctype(c) for c in cells)
        reimpl = row['rtl'].strip() not in ('', '-') and row['verified'].strip().lower() == 'yes'
        out.append({'block': row['block'], 'cells': len(cells),
                    'luts': types['LUT6'] + types['LUT6_2'],
                    'ffs': sum(types[t] for t in xc7_blocks.FF),
                    'dsp': types['DSP48E1'], 'bram': types['RAMB18E1'],
                    'recognized': 'yes', 'reimplemented': 'yes' if reimpl else 'no',
                    'rtl': row['rtl'] if row['rtl'].strip() else '-', 'doc': row['doc']})
    seen = set().union(*claim.values()) if claim else set()
    rest = [c for c in g.cells if c not in seen]
    types = collections.Counter(g.ctype(c) for c in rest)
    out.append({'block': '(not attributed)', 'cells': len(rest), 'luts': types['LUT6'] + types['LUT6_2'],
                'ffs': sum(types[t] for t in xc7_blocks.FF), 'dsp': types['DSP48E1'], 'bram': types['RAMB18E1'],
                'recognized': 'no', 'reimplemented': 'no', 'rtl': '-', 'doc': '-'})
    return total, out


FIELDS = ('block', 'cells', 'luts', 'ffs', 'dsp', 'bram', 'recognized', 'reimplemented', 'rtl', 'doc')


def write_tsv(path, total, out):
    rec = sum(r['cells'] for r in out if r['recognized'] == 'yes')
    rei = sum(r['cells'] for r in out if r['reimplemented'] == 'yes')
    lines = [
        '# SDR FPGA progress by netlist cells (T23). Generated by tools/sdr_progress.py from build/sdr/netlist.json and',
        '# tools/sdr_blocks.tsv; counts only. Read by tools/readability_stats.py for the README progress block.',
        f'# total_cells\t{total}',
        f'# recognized_cells\t{rec}',
        f'# reimplemented_cells\t{rei}',
        '\t'.join(FIELDS),
    ] + ['\t'.join(str(r[k]) for k in FIELDS) for r in out]
    os.makedirs(os.path.dirname(path) or '.', exist_ok=True)
    with open(path, 'w', encoding='utf-8') as f:
        f.write('\n'.join(lines) + '\n')
    return rec, rei


def selftest():
    nl = {'cells': [
        {'name': 'S_X0Y0/AFF', 'type': 'FDRE', 'site': 'S_X0Y0', 'params': {},
         'pins': {'C': ['clk', 'I'], 'D': ['n1', 'I'], 'Q': ['n2', 'O']}},
        {'name': 'S_X0Y0/ALUT', 'type': 'LUT6', 'site': 'S_X0Y0', 'params': {'INIT': 1},
         'pins': {'A1': ['n3', 'I'], 'O6': ['n1', 'O']}},
        {'name': 'S_X1Y0/AFF', 'type': 'FDRE', 'site': 'S_X1Y0', 'params': {},
         'pins': {'C': ['clk', 'I'], 'D': ['n4', 'I'], 'Q': ['n3', 'O']}},
        {'name': 'S_X2Y0/AFF', 'type': 'FDRE', 'site': 'S_X2Y0', 'params': {},
         'pins': {'C': ['clk', 'I'], 'D': ['n2', 'I'], 'Q': ['n5', 'O']}},
        {'name': 'B_X0Y0', 'type': 'BUFHCE', 'site': 'B_X0Y0', 'params': {}, 'pins': {'O': ['clk', 'O']}},
    ], 'nets': {
        'clk': {'drivers': ['B_X0Y0.O'], 'sinks': ['S_X0Y0/AFF.C', 'S_X1Y0/AFF.C', 'S_X2Y0/AFF.C']},
        'n1': {'drivers': ['S_X0Y0/ALUT.O6'], 'sinks': ['S_X0Y0/AFF.D']},
        'n2': {'drivers': ['S_X0Y0/AFF.Q'], 'sinks': ['S_X2Y0/AFF.D']},
        'n3': {'drivers': ['S_X1Y0/AFF.Q'], 'sinks': ['S_X0Y0/ALUT.A1']},
        'n4': {'drivers': [], 'sinks': ['S_X1Y0/AFF.D']},
        'n5': {'drivers': ['S_X2Y0/AFF.Q'], 'sinks': []},
    }}
    g = xc7_blocks.G(nl)
    idx = Index(g)
    assert sorted(idx.resolve('S_X0..X1Y0', 't')) == ['S_X0Y0/AFF', 'S_X0Y0/ALUT', 'S_X1Y0/AFF'], idx.resolve('S_X0..X1Y0', 't')
    assert idx.resolve('S_X0Y0/AFF', 't') == ['S_X0Y0/AFF']
    assert sorted(idx.resolve('S_X0Y0..X2Y0/AFF', 't')) == ['S_X0Y0/AFF', 'S_X1Y0/AFF', 'S_X2Y0/AFF']
    assert cone(g, ['S_X0Y0/AFF'], 0, False, set()) == {'S_X0Y0/AFF', 'S_X0Y0/ALUT'}
    assert cone(g, ['S_X0Y0/AFF'], 1, False, set()) == {'S_X0Y0/AFF', 'S_X0Y0/ALUT', 'S_X1Y0/AFF'}
    assert cone(g, ['S_X0Y0/AFF'], 1, True, set()) == {'S_X0Y0/AFF', 'S_X2Y0/AFF'}
    assert 'B_X0Y0' not in cone(g, ['S_X0Y0/AFF'], 3, False, set())
    rows = [dict(zip(COLS, r)) for r in (
        ('a', 'S_X2Y0/AFF', '1', '-', '-', '-', 'd', 'x.v', 'yes'),
        ('b', 'S_X0Y0', '1', '-', '-', 'S_X0..X1Y0', 'd', '-', 'no'))]
    claim = attribute(g, rows)
    assert claim['a'] == {'S_X2Y0/AFF', 'S_X0Y0/AFF', 'S_X0Y0/ALUT'}, claim
    assert claim['b'] == {'S_X1Y0/AFF'}, claim
    total, out = summarize(g, rows, claim)
    assert total == 5 and out[-1]['cells'] == 1 and out[0]['reimplemented'] == 'yes' and out[1]['reimplemented'] == 'no'
    print('sdr_progress selftest: OK')
    return 0


def main(argv):
    if argv[:1] == ['selftest']:
        return selftest()
    opts, pos = {}, []
    it = iter(argv)
    for a in it:
        if a in ('--map', '--out', '--show'):
            opts[a] = next(it, None)
        elif a.startswith('-'):
            sys.exit(__doc__)
        else:
            pos.append(a)
    path = pos[0] if pos else NETLIST
    if not os.path.exists(path):
        sys.exit(f'sdr_progress: no {path} (tools/bootstrap.sh --only sdr builds it)')
    rows = read_map(opts.get('--map') or MAP)
    g = xc7_blocks.load(path)
    claim = attribute(g, rows)
    total, out = summarize(g, rows, claim)
    if opts.get('--show'):
        if opts['--show'] not in claim:
            sys.exit(f'sdr_progress: no block {opts["--show"]!r}')
        for c in sorted(claim[opts['--show']]):
            print(c, g.ctype(c))
        return 0
    rec, rei = write_tsv(opts.get('--out') or OUT, total, out)
    for r in out:
        print(f"{r['block']:<28} {r['cells']:>6}  {r['luts']:>5} LUT {r['ffs']:>5} FF {r['dsp']:>3} DSP {r['bram']:>3} BRAM"
              f"{'  RTL ' + r['rtl'] if r['reimplemented'] == 'yes' else ''}")
    print(f'sdr_progress: {total:,} cells; recognized {rec:,} ({100.0 * rec / total:.1f} %), '
          f're-implemented {rei:,} ({100.0 * rei / total:.1f} %) -> {opts.get("--out") or OUT}')
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
