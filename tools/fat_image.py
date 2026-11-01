#!/usr/bin/env python3
"""T24 round 9: synthetic FAT12/16/32 disk images for the DISPLAY checks (tools/equiv_display_emu.py presets) and the
emulated boot with an SD card (tools/display_boot_emu.py --sd).

The image is built from the FAT specification (Microsoft "FAT: General Overview of On-Disk Format" 1.03): an MBR
with one partition (or none: a "superfloppy" whose sector 0 is the boot sector), the boot sector with its BPB, for
FAT32 the FSInfo sector and the backup boot sector, the FATs, the root directory (a fixed area for FAT12/16, a
cluster chain for FAT32) and files and directories with 8.3 names and long-name (LFN) entries. Nothing here comes
from the firmware: the content is ours, so the image may be committed or regenerated freely.

Usage (a file for inspection, e.g. with mtools):  python3 -I tools/fat_image.py OUT.img [--fat 32] [--sectors N]
"""
import argparse
import random
import struct
import sys

SECTOR = 512


def lfn_checksum(short11):
    s = 0
    for c in short11:
        s = (((s & 1) << 7) + (s >> 1) + c) & 0xFF
    return s


def short_name(name, used):
    """An 8.3 name for name (upper case; a ~1 tail when it does not fit or is taken) and whether an LFN is needed."""
    base, _, ext = name.rpartition('.') if '.' in name else (name, '', '')
    ok = set('ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$%\'-_@~`!(){}^#&')
    b = ''.join(c for c in base.upper() if c in ok)
    e = ''.join(c for c in ext.upper() if c in ok)[:3]
    plain = name == name.upper() and len(base) <= 8 and len(ext) <= 3 and b == base and e == ext
    if plain and (b, e) not in used:
        used.add((b, e))
        return (b.ljust(8) + e.ljust(3)).encode(), False
    for k in range(1, 100):
        t = f'~{k}'
        cand = (b[:8 - len(t)] + t, e)
        if cand not in used:
            used.add(cand)
            return (cand[0].ljust(8) + cand[1].ljust(3)).encode(), True
    raise ValueError(name)


def dir_entries(name, attr, cluster, size, used, stamp):
    """The 32-byte entries of one directory item: LFN entries (last first) and the short entry."""
    sn, need_lfn = short_name(name, used) if name not in ('.', '..') else (name.ljust(11).encode(), False)
    out = b''
    if need_lfn:
        chk = lfn_checksum(sn)
        units = [ord(c) for c in name] + [0]
        units += [0xFFFF] * (-len(units) % 13)
        parts = [units[i:i + 13] for i in range(0, len(units), 13)]
        for seq in range(len(parts), 0, -1):
            u = parts[seq - 1]
            e = bytearray(32)
            e[0] = seq | (0x40 if seq == len(parts) else 0)
            e[1:11] = struct.pack('<5H', *u[0:5])
            e[11], e[12], e[13] = 0x0F, 0, chk
            e[14:26] = struct.pack('<6H', *u[5:11])
            e[28:32] = struct.pack('<2H', *u[11:13])
            out += bytes(e)
    t, d = stamp
    out += sn + struct.pack('<BBBHHHHHHHI', attr, 0, 0, t, d, d, cluster >> 16, t, d, cluster & 0xFFFF, size)
    return out


class Volume:
    def __init__(self, fat=32, sectors=4096, spc=1, rsv=None, nfats=2, root_entries=None, start=0, rng=None):
        self.fat, self.spc, self.nfats = fat, spc, nfats
        self.rsv = rsv if rsv is not None else (32 if fat == 32 else 1)
        self.root_entries = 0 if fat == 32 else (root_entries or 512)
        self.start, self.sectors = start, sectors
        self.rng = rng or random.Random(0)
        root_secs = self.root_entries * 32 // SECTOR
        # FAT size: enough entries for every cluster the volume could hold
        fatsz = 1
        while True:
            data = sectors - self.rsv - nfats * fatsz - root_secs
            ncl = data // spc
            need = {12: (ncl + 2) * 3 // 2 + 1, 16: (ncl + 2) * 2, 32: (ncl + 2) * 4}[fat]
            if need <= fatsz * SECTOR:
                break
            fatsz += 1
        self.fatsz, self.root_secs, self.nclusters = fatsz, root_secs, ncl
        self.data_start = self.rsv + nfats * fatsz + root_secs
        self.fat_table = [0] * (ncl + 2)
        self.fat_table[0] = {12: 0xFF8, 16: 0xFFF8, 32: 0x0FFFFFF8}[fat]
        self.fat_table[1] = {12: 0xFFF, 16: 0xFFFF, 32: 0x0FFFFFFF}[fat]
        self.eoc = {12: 0xFFF, 16: 0xFFFF, 32: 0x0FFFFFFF}[fat]
        self.clusters = {}
        self.next_free = 2
        self.root_cluster = self.alloc(1) if fat == 32 else 0
        self.root = []        # (name, attr, cluster, size)
        self.dirs = {}        # cluster -> list of items

    def alloc(self, n):
        first = self.next_free
        if first + n > self.nclusters + 2:
            raise ValueError('volume full')
        for k in range(n):
            self.fat_table[first + k] = first + k + 1 if k < n - 1 else self.eoc
        self.next_free += n
        return first

    def add_file(self, path, data):
        parts = path.split('/')
        items = self._dir_items(parts[:-1])
        csize = self.spc * SECTOR
        n = max(1, -(-len(data) // csize)) if data else 0
        c = self.alloc(n) if n else 0
        for k in range(n):
            self.clusters[c + k] = data[k * csize:(k + 1) * csize]
        items.append((parts[-1], 0x20, c, len(data)))

    def add_dir(self, path):
        parts = path.split('/')
        items = self._dir_items(parts[:-1])
        c = self.alloc(1)
        parent = 0 if len(parts) == 1 or self.fat != 32 and len(parts) == 1 else self._dir_cluster(parts[:-1])
        self.dirs[c] = [('.', 0x10, c, 0), ('..', 0x10, parent, 0)]
        items.append((parts[-1], 0x10, c, 0))

    def _dir_cluster(self, parts):
        items = self.root
        c = 0
        for p in parts:
            c = next(i[2] for i in items if i[0] == p and i[1] & 0x10)
            items = self.dirs[c]
        return c

    def _dir_items(self, parts):
        return self.dirs[self._dir_cluster(parts)] if parts else self.root

    def _dir_bytes(self, items):
        used, out = set(), b''
        stamp = ((12 << 11) | (34 << 5) | 28, ((2024 - 1980) << 9) | (2 << 5) | 16)
        for name, attr, c, size in items:
            out += dir_entries(name, attr, c, size, used, stamp)
        return out

    def boot_sector(self):
        b = bytearray(SECTOR)
        b[0:3] = b'\xEB\x58\x90' if self.fat == 32 else b'\xEB\x3C\x90'
        b[3:11] = b'T24 FAT '
        total16 = self.sectors if self.sectors < 0x10000 and self.fat != 32 else 0
        struct.pack_into('<HBHBHHBHHHII', b, 11, SECTOR, self.spc, self.rsv, self.nfats, self.root_entries,
                         total16, 0xF8, self.fatsz if self.fat != 32 else 0, 63, 255, self.start,
                         0 if total16 else self.sectors)
        label = b'T24 VOLUME '
        if self.fat == 32:
            struct.pack_into('<IHHIHH', b, 36, self.fatsz, 0, 0, self.root_cluster, 1, 6)
            struct.pack_into('<BBBI', b, 64, 0x80, 0, 0x29, 0x710C0DE)
            b[71:82] = label
            b[82:90] = b'FAT32   '
        else:
            struct.pack_into('<BBBI', b, 36, 0x80, 0, 0x29, 0x710C0DE)
            b[43:54] = label
            b[54:62] = b'FAT12   ' if self.fat == 12 else b'FAT16   '
        b[510:512] = b'\x55\xAA'
        return bytes(b)

    def fsinfo(self):
        b = bytearray(SECTOR)
        b[0:4] = b'RRaA'
        b[484:488] = b'rrAa'
        struct.pack_into('<II', b, 488, self.nclusters + 2 - self.next_free, self.next_free)
        b[510:512] = b'\x55\xAA'
        return bytes(b)

    def fat_bytes(self):
        if self.fat == 12:
            out = bytearray()
            t = self.fat_table + [0] * (len(self.fat_table) % 2)
            for k in range(0, len(t), 2):
                v = t[k] | t[k + 1] << 12
                out += bytes([v & 0xFF, v >> 8 & 0xFF, v >> 16 & 0xFF])
        else:
            out = b''.join(struct.pack('<H' if self.fat == 16 else '<I', v) for v in self.fat_table)
        return bytes(out).ljust(self.fatsz * SECTOR, b'\0')

    def image(self):
        """The partition's sectors (boot sector at sector 0 of the partition)."""
        img = bytearray(self.sectors * SECTOR)
        img[0:SECTOR] = self.boot_sector()
        if self.fat == 32:
            img[SECTOR:2 * SECTOR] = self.fsinfo()
            img[6 * SECTOR:7 * SECTOR] = self.boot_sector()
            img[7 * SECTOR:8 * SECTOR] = self.fsinfo()
        fb = self.fat_bytes()
        for k in range(self.nfats):
            o = (self.rsv + k * self.fatsz) * SECTOR
            img[o:o + len(fb)] = fb
        csize = self.spc * SECTOR
        if self.fat == 32:
            self.clusters[self.root_cluster] = self._dir_bytes(self.root)
        else:
            rd = self._dir_bytes(self.root)
            o = (self.rsv + self.nfats * self.fatsz) * SECTOR
            img[o:o + len(rd)] = rd[:self.root_secs * SECTOR]
        for c, items in self.dirs.items():
            self.clusters[c] = self._dir_bytes(items)[:csize]
        for c, data in self.clusters.items():
            o = (self.data_start + (c - 2) * self.spc) * SECTOR
            img[o:o + len(data)] = data
        return bytes(img)


def mbr(start, sectors, ptype):
    b = bytearray(SECTOR)
    b[446:462] = struct.pack('<B3sB3sII', 0, b'\x01\x01\x00', ptype, b'\xFE\xFF\xFF', start, sectors)
    b[510:512] = b'\x55\xAA'
    return bytes(b)


def card(fat=32, sectors=4096, start=63, spc=1, files=None, dirs=None, superfloppy=False, rng=None):
    """A whole card: MBR (unless superfloppy) and one partition from sector start."""
    if superfloppy:
        start = 0
    vol = Volume(fat=fat, sectors=sectors - start, spc=spc, start=start, rng=rng)
    for d in dirs or ():
        vol.add_dir(d)
    for path, data in files or ():
        vol.add_file(path, data)
    img = bytearray(sectors * SECTOR)
    part = vol.image()
    img[start * SECTOR:start * SECTOR + len(part)] = part
    if not superfloppy:
        ptype = {12: 0x01, 16: 0x06, 32: 0x0C}[fat]
        img[0:SECTOR] = mbr(start, sectors - start, ptype)
    return bytes(img), vol


DEFAULT_FILES = [('README.TXT', b'FT-710 T24 synthetic card\r\n'),
                 ('FT-710/MemList/MemList_0001.dat', bytes(range(256)) * 3),
                 ('FT-710/Capture/Long capture name.bmp', b'BM' + bytes(1500))]
DEFAULT_DIRS = ['FT-710', 'FT-710/Capture', 'FT-710/MemList', 'FT-710/Menu', 'FT-710/PlayList']


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('out')
    ap.add_argument('--fat', type=int, default=32, choices=(12, 16, 32))
    ap.add_argument('--sectors', type=int, default=8192)
    ap.add_argument('--spc', type=int, default=1)
    ap.add_argument('--superfloppy', action='store_true')
    a = ap.parse_args()
    img, vol = card(a.fat, a.sectors, spc=a.spc, files=DEFAULT_FILES, dirs=DEFAULT_DIRS, superfloppy=a.superfloppy)
    with open(a.out, 'wb') as f:
        f.write(img)
    print(f'fat_image: FAT{a.fat}, {a.sectors} sectors, {vol.nclusters} clusters, FAT {vol.fatsz} sectors, data from '
          f'sector {vol.data_start} of the partition; wrote {a.out}', file=sys.stderr)


if __name__ == '__main__':
    main()
