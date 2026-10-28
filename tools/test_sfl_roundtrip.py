#!/usr/bin/env python3
"""Round-trip test: SFL -> sfl_decode -> sfl_encode -> identical SFL, for all shipped images.

Usage: python3 -I tools/test_sfl_roundtrip.py [-v]

Reads Firmware/FT-710_*.SFL (gitignored, see AGENTS.md) and writes all
intermediate and re-encoded files to build/t16/roundtrip/ (gitignored). Two
paths are tested per image:
  raw:       sfl_decode --raw  ->  sfl_encode --raw --header-from ORIG
  converted: sfl_decode        ->  sfl_encode --header-from ORIG
             (MAIN: binary + option-memory cluster -> S-records via the
              original record layout; SDR: bitstream -> ASCII hex)
plus a generic MAIN S-record layout test, a header-generation test (comment box rebuilt from fields, not copied)
and the acceptance check (sfl_encode --check) on every original.
Firmware-derived files stay in build/; never commit them.
"""
import contextlib
import glob
import io
import os
import sys
import unittest

TOOLS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(TOOLS)
sys.path.insert(0, TOOLS)
import sfl_decode  # noqa: E402
import sfl_encode  # noqa: E402
import sfl_header  # noqa: E402


def _find_root():
    # In a git worktree the gitignored Firmware/ and build/ live in the main checkout.
    for cand in (ROOT, os.path.join(ROOT.split("/.claude/worktrees/")[0])):
        if glob.glob(os.path.join(cand, "Firmware", "FT-710_*.SFL")):
            return cand
    return ROOT


DATA_ROOT = _find_root()
FIRMWARE = sorted(glob.glob(os.path.join(DATA_ROOT, "Firmware", "FT-710_*.SFL")))
OUT = os.path.join(DATA_ROOT, "build", "t16", "roundtrip")


def quiet(fn, *args):
    with contextlib.redirect_stdout(io.StringIO()):
        return fn(*args)


class RoundTrip(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        if not FIRMWARE:
            raise unittest.SkipTest("no Firmware/FT-710_*.SFL found")
        os.makedirs(OUT, exist_ok=True)

    def _orig(self, path):
        with open(path, "rb") as fh:
            return fh.read()

    def _read(self, path):
        with open(path, "rb") as fh:
            return fh.read()

    def test_raw_path(self):
        for src in FIRMWARE:
            with self.subTest(src=os.path.basename(src)):
                name = os.path.basename(src)[:-4]
                plain = os.path.join(OUT, name + ".raw")
                dst = os.path.join(OUT, "raw", os.path.basename(src))
                self.assertEqual(quiet(sfl_decode.main, ["--raw", src, plain]), 0)
                quiet(sfl_encode.main, ["--raw", "--header-from", src, plain, dst])
                self.assertEqual(self._read(dst), self._orig(src))

    def test_converted_path(self):
        for src in FIRMWARE:
            with self.subTest(src=os.path.basename(src)):
                name = os.path.basename(src)[:-4]
                binp = os.path.join(OUT, name + ".bin")
                dst = os.path.join(OUT, "conv", os.path.basename(src))
                self.assertEqual(quiet(sfl_decode.main, [src, binp]), 0)
                quiet(sfl_encode.main, ["--header-from", src, binp, dst])
                self.assertEqual(self._read(dst), self._orig(src))

    def test_generated_header(self):
        # Rebuild the comment box from its fields instead of copying it.
        for src in FIRMWARE:
            with self.subTest(src=os.path.basename(src)):
                orig = self._orig(src)
                h = sfl_header.parse(orig)
                f = h["fields"]
                plain = os.path.join(OUT, os.path.basename(src)[:-4] + ".raw")
                if not os.path.exists(plain):
                    quiet(sfl_decode.main, ["--raw", src, plain])
                cline = orig[6 * 64 + 1:7 * 64 - 3].decode().strip()
                dst = os.path.join(OUT, "gen", os.path.basename(src))
                quiet(sfl_encode.main, ["--raw", "--tag", h["tag"], "--title", h["title"],
                                        "--file-name", f["FILE NAME"], "--product", f["PRODUCT NAME"],
                                        "--version", f["FIRM VERSION"], "--date", f["DATE"],
                                        "--copyright", cline, plain, dst])
                self.assertEqual(self._read(dst), orig)

    def test_main_generic_layout(self):
        # Without a layout template the S-records differ from the original, but
        # they must decode to the same binary and option-setting memory.
        src = [f for f in FIRMWARE if "_MAIN_" in f]
        if not src:
            self.skipTest("no MAIN image")
        binp = os.path.join(OUT, "gen_main", "main.bin")
        quiet(sfl_decode.main, [src[0], binp])
        dst = os.path.join(OUT, "gen_main", "FT-710_MAIN_V9999.SFL")
        quiet(sfl_encode.main, ["--tag", "MC", "--layout-from", "", "--version", "V01-12", binp, dst])
        back = os.path.join(OUT, "gen_main", "back.bin")
        self.assertEqual(quiet(sfl_decode.main, [dst, back]), 0)
        self.assertEqual(self._read(back), self._read(binp))
        self.assertEqual(self._read(back + ".FE7F5D00.bin"), self._read(binp + ".FE7F5D00.bin"))

    def test_acceptance_on_originals(self):
        for src in FIRMWARE:
            with self.subTest(src=os.path.basename(src)):
                res = sfl_encode.check(self._orig(src), src)
                self.assertTrue(all(ok for ok, _ in res), [r for ok, r in res if not ok])

    def test_encode_decode_inverse(self):
        blob = bytes(range(256)) * 3 + b"\x00\xff" * 50
        self.assertEqual(sfl_decode.decode(sfl_encode.encode(blob)), blob)


if __name__ == "__main__":
    unittest.main()
