// T24 (MAIN): run functions of the RX651 image in Ghidra's p-code emulator for tools/equiv_main_emu.py.
//
// Unicorn has no RX, so the MAIN equivalence check runs in Ghidra's p-code emulator (ghidra.pcode.emu.PcodeEmulator)
// on the rx62t SLEIGH module (docs/tooling.md, "Renesas RX processor module"). This script is a server: it reads
// one JSON request per line from stdin and answers each with one line "@@EQ <json>" on stdout, so that the Python
// side (tools/equiv_main_emu.py) keeps one Ghidra process for a whole check instead of paying Ghidra's start-up for
// every trial. It only reads the program: run it with -readOnly on a copy of the MAIN project.
//
// Headless usage (tools/equiv_main_emu.py starts it; by hand for a test):
//   tools/ghidra-headless.sh <projdir> FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript EquivMainEmu.java
//
// Requests (one JSON object per line):
//   {"op":"base","name":N,"segs":[[addr,"hex"],...]}   define a named memory image (later runs layer bases)
//   {"op":"blocks","entries":[addr,...]}               basic-block starts (SimpleBlockModel) of the Ghidra
//                                                      function at each address, and whether it ends in RTE
//                                                      -> {"blocks":{addr:{"blocks":[...],"isr":b,"found":b}}}
//   {"op":"run", "bases":[N,...], "loads":[[addr,"hex"]], "entry":A, "regs":{"R1":v,...}, "sp":S,
//    "stack":[w,...] (words at SP+4.., [SP] = the return address), "seed":s, "budget":n,
//    "stubs":{addr:[name,nargs(,ptr_arg,len_arg)]}, "cover":[addr,...], "snap":[[lo,hi],...], "track":[[lo,hi],...],
//    "mmio_fixed":{addr:value}, "trace":true (PC and R1..R15 before each of the first 400 instructions),
//    "module_fp":true (FTOI/ROUND/FTOU by the module's p-code instead of fpConv)}
//     -> {"end":"return"|"budget"|"fault", "why":..., "r1":v, "r2":v, "regs":[R1..R15], "psw":v, "steps":n,
//         "mmio":[["r"|"w",addr,size,value],...], "calls":[[name,arg...],...], "userops":[name,...],
//         "diff":[[addr,"hex"],...] (snap ranges that differ from the start state), "hits":[addr,...] (cover
//         addresses executed), "reads":[addr,...] (bytes in the track ranges read before any write)}
//   {"op":"quit"}
//
// Memory model: RAM 0x0..0x3FFFF, the image 0xFFF80000..0xFFFFFFFF, the recreated code at 0xFFF00000..0xFFF7FFFF,
// peripheral I/O 0x80000..0xFFFFF and 0x7FC000..0x7FFFFF. A load from I/O returns a value from a seeded sequence
// (java.util.Random(seed), or "mmio_fixed") and is recorded with every I/O store; any access elsewhere ends the run
// as a fault. A call to a stub address records (name, R1..R4 and stack arguments), sets R1 from the same seeded
// sequence and returns (RX BSR/JSR push the return address; the caller pops stack arguments). With ptr_arg and
// len_arg (0-based argument numbers), the call also records the bytes the pointer argument points to, at most
// 0x6000 (a buffer on the stack has an address that depends on the callers' frames; its content does not). The string compare
// pcodeops of the module (scmpu, suntil, swhile) are implemented here after the RXv2 software manual R01US0071EJ0100
// (SCMPU p. 184, SUNTIL p. 196, SWHILE p. 198), because the module leaves them as named operations (T21c), and
// JMP Rs is executed here, because the module's "PC = Rs" does not branch in the emulator (T22a listed it as not
// fixed: MAIN has no JMP Rs; GCC's switch tables use it). tools/ghidra/rx62t-gccforms-fix.patch (T24 round 2) fixes the
// module ("goto [Rs]"); the override stays, so a module without that patch gives the same results. FTOI, ROUND and
// FTOU are executed here after the manual too (T24 MAIN round 4: the module computed a float for all three;
// tools/ghidra/rx62t-fpconv-fix.patch fixes it for the decompiler).
// @category FT710
import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import ghidra.app.script.GhidraScript;
import ghidra.pcode.emu.PcodeEmulationCallbacks;
import ghidra.pcode.emu.PcodeEmulator;
import ghidra.pcode.emu.PcodeThread;
import ghidra.pcode.exec.PcodeArithmetic;
import ghidra.pcode.exec.PcodeExecutorState;
import ghidra.pcode.exec.PcodeExecutorStatePiece;
import ghidra.pcode.exec.PcodeFrame;
import ghidra.pcode.exec.PcodeUseropLibrary;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.block.CodeBlock;
import ghidra.program.model.block.CodeBlockIterator;
import ghidra.program.model.block.SimpleBlockModel;
import ghidra.program.model.lang.Language;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.Varnode;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.FileDescriptor;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class EquivMainEmu extends GhidraScript {
    static final long STACK_LO = 0x0, RAM_HI = 0x40000;
    static final long IO_LO = 0x80000, IO_HI = 0x100000, IO2_LO = 0x7FC000, IO2_HI = 0x800000;
    static final long ROM_LO = 0xFFF80000L, SCRATCH_LO = 0xFFF00000L, TOP = 0x100000000L;
    static final long STOP = 0xFFFFF000L;

    static class Fault extends RuntimeException {
        Fault(String m) { super(m); }
    }

    static class Stop extends RuntimeException {
        Stop(String m) { super(m); }
    }

    final Map<String, List<Object[]>> bases = new HashMap<>();
    Language lang;
    AddressSpace ram;
    PrintStream out;

    static byte[] unhex(String s) {
        byte[] b = new byte[s.length() / 2];
        for (int i = 0; i < b.length; i++) b[i] = (byte) Integer.parseInt(s.substring(2 * i, 2 * i + 2), 16);
        return b;
    }

    static String hex(byte[] b, int off, int len) {
        StringBuilder sb = new StringBuilder(2 * len);
        for (int i = off; i < off + len; i++) sb.append(String.format("%02x", b[i] & 0xff));
        return sb.toString();
    }

    static long lv(JsonElement e) {
        return e.getAsLong() & 0xFFFFFFFFL;
    }

    /** One emulation run: the callbacks see every load, store and instruction. */
    class Run implements PcodeEmulationCallbacks<byte[]> {
        final Random rng;
        final Map<Long, Long> fixed = new HashMap<>();
        final List<Object[]> mmio = new ArrayList<>();
        final List<String> userops = new ArrayList<>();
        final List<long[]> trackRanges = new ArrayList<>();
        final BitSet written = new BitSet((int) RAM_HI);
        final TreeSet<Long> reads = new TreeSet<>();
        PcodeArithmetic<byte[]> arith;
        PcodeThread<byte[]> thread;

        Run(long seed) {
            rng = new Random(seed);
        }

        long val(byte[] v) {
            return arith.toLong(v, PcodeArithmetic.Purpose.OTHER) & 0xFFFFFFFFL;
        }

        boolean inTrack(long a) {
            for (long[] r : trackRanges) if (a >= r[0] && a < r[1]) return true;
            return false;
        }

        void check(long a, int size, boolean store) {
            long e = a + size;
            if (e <= RAM_HI) return;
            if (a >= IO_LO && e <= IO_HI || a >= IO2_LO && e <= IO2_HI) return;
            if (!store && a >= SCRATCH_LO && e <= TOP) return;
            throw new Fault(String.format("%s of %d bytes at 0x%x", store ? "store" : "load", size, a));
        }

        boolean isIo(long a) {
            return a >= IO_LO && a < IO_HI || a >= IO2_LO && a < IO2_HI;
        }

        @Override
        public void beforeLoad(PcodeThread<byte[]> t, PcodeOp op, AddressSpace space, byte[] offset, int size) {
            if (space != ram) return;
            long a = val(offset);
            check(a, size, false);
            if (isIo(a)) {
                long v;
                Long f = fixed.get(a);
                if (f != null) v = f;
                else v = rng.nextLong() & (size >= 8 ? -1L : ((1L << (8 * size)) - 1));
                t.getState().setVar(ram, a, size, true, arith.fromConst(v, size));
                mmio.add(new Object[]{"r", a, size, v});
            } else if (a < RAM_HI) {
                for (long b = a; b < a + size && b < RAM_HI; b++)
                    if (!written.get((int) b) && inTrack(b)) reads.add(b);
            }
        }

        @Override
        public void afterStore(PcodeThread<byte[]> t, PcodeOp op, AddressSpace space, byte[] offset, int size,
                               byte[] value) {
            if (space != ram) return;
            long a = val(offset);
            if (isIo(a)) {
                long v = arith.toLong(value, PcodeArithmetic.Purpose.OTHER);
                if (size < 8) v &= (1L << (8 * size)) - 1;
                mmio.add(new Object[]{"w", a, size, v});
            } else if (a < RAM_HI) {
                written.set((int) a, (int) Math.min(a + size, RAM_HI));
            }
        }

        @Override
        public void beforeStore(PcodeThread<byte[]> t, PcodeOp op, AddressSpace space, byte[] offset, int size,
                                byte[] value) {
            if (space != ram) return;
            long a = val(offset);
            check(a, size, true);
        }

        byte rd(long a) {
            check(a, 1, false);
            if (a < RAM_HI && !written.get((int) a) && inTrack(a)) reads.add(a);
            return thread.getState().inspectConcrete(ram.getAddress(a), 1)[0];
        }

        long reg(String n) {
            return val(thread.getState().getVar(lang.getRegister(n), PcodeExecutorStatePiece.Reason.INSPECT));
        }

        void setReg(String n, long v) {
            Register r = lang.getRegister(n);
            thread.getState().setVar(r, arith.fromConst(v, r.getMinimumByteSize()));
        }

        @Override
        public boolean handleMissingUserop(PcodeThread<byte[]> t, PcodeOp op, PcodeFrame frame, String name,
                                           PcodeUseropLibrary<byte[]> library) {
            PcodeExecutorState<byte[]> st = t.getState();
            long[] in = new long[op.getNumInputs()];
            for (int i = 1; i < op.getNumInputs(); i++)
                in[i] = val(st.getVar(op.getInput(i), PcodeExecutorStatePiece.Reason.INSPECT));
            long res;
            userops.add(name);
            if (name.equals("scmpu")) {
                // compare bytes *R1, *R2 until they differ, a NUL or R3 bytes; result *R1 - *R2 of the last pair
                long a = in[1], b = in[2], n = in[3];
                int x = 0, y = 0;
                while (n-- > 0) {
                    x = rd(a++) & 0xff;
                    y = rd(b++) & 0xff;
                    if (x != y || x == 0) break;
                }
                res = (x - y) & 0xFFFFFFFFL;
            } else if (name.equals("suntil") || name.equals("swhile")) {
                // R1 = pointer, R2 = value, R3 = count, size: until (stop on ==) / while (stop on !=)
                long a = in[1], v = in[2], n = in[3];
                int sz = (int) in[4];
                if (sz != 1 && sz != 2 && sz != 4) sz = 1;
                long mask = sz == 4 ? 0xFFFFFFFFL : (1L << (8 * sz)) - 1;
                boolean until = name.equals("suntil");
                long cur = 0;
                while (n > 0) {
                    cur = 0;
                    for (int k = 0; k < sz; k++) cur |= (rd(a + k) & 0xffL) << (8 * k);
                    a += sz;
                    n--;
                    if (until ? (cur == (v & mask)) : (cur != (v & mask))) break;
                }
                setReg("R3", n);
                res = a;
            } else {
                throw new Fault("unimplemented pcodeop " + name);
            }
            Varnode o = op.getOutput();
            if (o != null) st.setVar(o, arith.fromConst(res, o.getSize()));
            return true;
        }
    }

    JsonObject doRun(JsonObject q) {
        long seed = q.has("seed") ? q.get("seed").getAsLong() : 1;
        Run r = new Run(seed);
        PcodeEmulator emu = new PcodeEmulator(lang, r);
        r.arith = emu.getArithmetic();
        PcodeExecutorState<byte[]> shared = emu.getSharedState();
        // start state: the bases in order, then the loads; remember the start bytes of the snap ranges
        for (JsonElement b : q.getAsJsonArray("bases")) {
            List<Object[]> segs = bases.get(b.getAsString());
            if (segs == null) throw new IllegalArgumentException("no base " + b.getAsString());
            for (Object[] s : segs) shared.setConcrete(ram.getAddress((Long) s[0]), (byte[]) s[1]);
        }
        if (q.has("loads"))
            for (JsonElement e : q.getAsJsonArray("loads")) {
                JsonArray a = e.getAsJsonArray();
                shared.setConcrete(ram.getAddress(lv(a.get(0))), unhex(a.get(1).getAsString()));
            }
        if (q.has("mmio_fixed"))
            for (Map.Entry<String, JsonElement> e : q.getAsJsonObject("mmio_fixed").entrySet())
                r.fixed.put(Long.decode(e.getKey()), lv(e.getValue()));
        if (q.has("track"))
            for (JsonElement e : q.getAsJsonArray("track")) {
                JsonArray a = e.getAsJsonArray();
                r.trackRanges.add(new long[]{lv(a.get(0)), lv(a.get(1))});
            }
        List<long[]> snap = new ArrayList<>();
        List<byte[]> before = new ArrayList<>();
        if (q.has("snap"))
            for (JsonElement e : q.getAsJsonArray("snap")) {
                JsonArray a = e.getAsJsonArray();
                long lo = lv(a.get(0)), hi = lv(a.get(1));
                snap.add(new long[]{lo, hi});
                before.add(shared.inspectConcrete(ram.getAddress(lo), (int) (hi - lo)));
            }
        Map<Long, String[]> stubs = new HashMap<>();
        if (q.has("stubs"))
            for (Map.Entry<String, JsonElement> e : q.getAsJsonObject("stubs").entrySet()) {
                JsonArray a = e.getValue().getAsJsonArray();
                stubs.put(Long.decode(e.getKey()), a.size() >= 4
                        ? new String[]{a.get(0).getAsString(), a.get(1).getAsString(), a.get(2).getAsString(), a.get(3).getAsString()}
                        : new String[]{a.get(0).getAsString(), a.get(1).getAsString()});
            }
        Set<Long> cover = new HashSet<>();
        if (q.has("cover")) for (JsonElement e : q.getAsJsonArray("cover")) cover.add(lv(e));
        Set<Long> hits = new TreeSet<>();

        PcodeThread<byte[]> t = emu.newThread();
        r.thread = t;
        // registers: everything 0 except what the request gives; SP and the return address
        long sp = q.has("sp") ? lv(q.get("sp")) : 0xF00;
        if (q.has("regs"))
            for (Map.Entry<String, JsonElement> e : q.getAsJsonObject("regs").entrySet())
                r.setReg(e.getKey(), lv(e.getValue()));
        r.setReg("SP", sp);
        r.setReg("PSW", q.has("psw") ? lv(q.get("psw")) : 0x00030000L);
        r.setReg("FPSW", 0x100);
        r.setReg("INTB", 0xFFF8E6DCL);
        r.setReg("EXTB", 0xFFFFFF80L);
        writeLE(shared, sp, STOP);
        if (q.has("stack")) {
            int k = 1;
            for (JsonElement e : q.getAsJsonArray("stack")) writeLE(shared, sp + 4L * k++, lv(e));
        }
        long entry = lv(q.get("entry"));
        t.overrideCounter(ram.getAddress(entry));
        long budget = q.has("budget") ? q.get("budget").getAsLong() : 2000000;
        // "module_fp": true runs FTOI/ROUND/FTOU on the module's own p-code (to test a SLEIGH change)
        boolean moduleFp = q.has("module_fp") && q.get("module_fp").getAsBoolean();
        List<JsonArray> calls = new ArrayList<>();
        JsonArray trace = q.has("trace") && q.get("trace").getAsBoolean() ? new JsonArray() : null;
        String end = "budget", why = "";
        long steps = 0;
        try {
            while (steps < budget) {
                long pc = t.getCounter().getOffset();
                if (pc == STOP) {
                    end = "return";
                    break;
                }
                if (cover.contains(pc)) hits.add(pc);
                String[] stub = stubs.get(pc);
                if (stub != null) {
                    int n = Integer.parseInt(stub[1]);
                    JsonArray c = new JsonArray();
                    c.add(stub[0]);
                    long csp = r.reg("SP");
                    for (int k = 0; k < n; k++) {
                        if (k < 4) c.add(r.reg("R" + (k + 1)));
                        else c.add(readLE(shared, csp + 4L * (k - 3)));
                    }
                    if (stub.length >= 4) {
                        int pi = Integer.parseInt(stub[2]), li = Integer.parseInt(stub[3]);
                        long ptr = c.get(1 + pi).getAsLong(), len = c.get(1 + li).getAsLong() & 0xFFFF;
                        if (len > 0x6000) len = 0x6000;
                        if (ptr >= 0 && ptr + len <= 0x40000)
                            c.add(hex(shared.inspectConcrete(ram.getAddress(ptr), (int) len), 0, (int) len));
                    }
                    calls.add(c);
                    long ret = new long[]{0, 0, 0, 1, 0xFFFFFFFFL, r.rng.nextInt() & 0xFFFFFFFFL}[r.rng.nextInt(6)];
                    r.setReg("R1", ret);
                    long ra = readLE(shared, csp);
                    r.setReg("SP", csp + 4);
                    t.overrideCounter(ram.getAddress(ra));
                    steps++;
                    continue;
                }
                if (!(pc >= ROM_LO || pc >= SCRATCH_LO && pc < ROM_LO)) throw new Fault(String.format("execute at 0x%x", pc));
                if (trace != null && trace.size() < 400) {
                    JsonArray st = new JsonArray();
                    st.add(pc);
                    for (int k = 1; k <= 15; k++) st.add(r.reg("R" + k));
                    trace.add(st);
                }
                // JMP Rs (7F 0s): the module's p-code is "PC = Rs" without a branch, so the emulator falls through
                // (found here: GCC emits JMP for switch tables, CC-RX never does). Executed here instead.
                byte[] op2 = shared.inspectConcrete(ram.getAddress(pc), 2);
                if ((op2[0] & 0xff) == 0x7F && (op2[1] & 0xF0) == 0x00) {
                    int rs = op2[1] & 0x0F;
                    t.overrideCounter(ram.getAddress(r.reg(rs == 0 ? "SP" : "R" + rs)));
                    steps++;
                    continue;
                }
                // FTOI (FC 94..97), ROUND (FC 98..9B), FTOU (FC A4..A7): the module's p-code for all three is
                // "Rd = round(src)", the float bits of src rounded half away from zero (T24 MAIN round 4: FTOU of 50.7
                // gave 0x424C0000). The instruction is stepped (so its memory load is seen as usual), then Rd and the
                // Z/S flags are set after the manual: fpConv.
                if (!moduleFp && (op2[0] & 0xff) == 0xFC && ((op2[1] & 0xff) >= 0x94 && (op2[1] & 0xff) <= 0x9B
                        || (op2[1] & 0xff) >= 0xA4 && (op2[1] & 0xff) <= 0xA7)) {
                    byte[] ins = shared.inspectConcrete(ram.getAddress(pc), 5);
                    int b1 = ins[1] & 0xff, ld = b1 & 3, rs = (ins[2] >> 4) & 15, rd = ins[2] & 15;
                    long src;
                    if (ld == 3) src = r.reg(rs == 0 ? "SP" : "R" + rs);
                    else {
                        long dsp = ld == 0 ? 0 : ld == 1 ? (ins[3] & 0xffL) * 4 : ((ins[3] & 0xffL) | (ins[4] & 0xffL) << 8) * 4;
                        long a = (r.reg(rs == 0 ? "SP" : "R" + rs) + dsp) & 0xFFFFFFFFL;
                        src = (a < RAM_HI || a >= SCRATCH_LO) ? readLE(shared, a) : 0;   // the step below faults on others
                    }
                    long psw0 = r.reg("PSW");
                    t.stepInstruction();
                    steps++;
                    long[] v = fpConv(b1 >= 0xA4 ? 2 : b1 >= 0x98 ? 1 : 0, (int) src);
                    r.setReg(rd == 0 ? "SP" : "R" + rd, v[0]);
                    r.setReg("PSW", v[1] == 0 ? psw0 : (psw0 & ~6L) | (v[0] == 0 ? 2 : 0) | ((v[0] >>> 31) & 1) << 2);
                    continue;
                }
                t.stepInstruction();
                steps++;
            }
        } catch (Fault f) {
            end = "fault";
            why = f.getMessage();
        } catch (Exception e) {
            Throwable c = e;
            while (c.getCause() != null && !(c instanceof Fault)) c = c.getCause();
            end = "fault";
            why = (c instanceof Fault) ? c.getMessage() : (e.getClass().getSimpleName() + ": " + e.getMessage());
        }
        JsonObject res = new JsonObject();
        res.addProperty("end", end);
        res.addProperty("why", why);
        res.addProperty("steps", steps);
        res.addProperty("r1", r.reg("R1"));
        res.addProperty("r2", r.reg("R2"));
        res.addProperty("sp", r.reg("SP"));
        res.addProperty("psw", r.reg("PSW"));
        JsonArray regs = new JsonArray();
        for (int k = 1; k <= 15; k++) regs.add(r.reg("R" + k));
        res.add("regs", regs);
        JsonArray mm = new JsonArray();
        for (Object[] m : r.mmio) {
            JsonArray a = new JsonArray();
            a.add((String) m[0]);
            a.add((Long) m[1]);
            a.add((Integer) m[2]);
            a.add((Long) m[3]);
            mm.add(a);
        }
        res.add("mmio", mm);
        JsonArray ca = new JsonArray();
        for (JsonArray c : calls) ca.add(c);
        res.add("calls", ca);
        JsonArray uo = new JsonArray();
        for (String u : r.userops) uo.add(u);
        res.add("userops", uo);
        JsonArray diff = new JsonArray();
        for (int i = 0; i < snap.size(); i++) {
            long lo = snap.get(i)[0], hi = snap.get(i)[1];
            byte[] now = shared.inspectConcrete(ram.getAddress(lo), (int) (hi - lo));
            byte[] was = before.get(i);
            int k = 0;
            while (k < now.length) {
                if (now[k] == was[k]) {
                    k++;
                    continue;
                }
                int s = k;
                while (k < now.length && now[k] != was[k]) k++;
                JsonArray d = new JsonArray();
                d.add(lo + s);
                d.add(hex(now, s, k - s));
                diff.add(d);
            }
        }
        res.add("diff", diff);
        JsonArray ha = new JsonArray();
        for (Long h : hits) ha.add(h);
        res.add("hits", ha);
        JsonArray ra = new JsonArray();
        for (Long a : r.reads) ra.add(a);
        res.add("reads", ra);
        if (trace != null) res.add("trace", trace);
        return res;
    }

    static void writeLE(PcodeExecutorState<byte[]> st, long a, long v) {
        byte[] b = {(byte) v, (byte) (v >> 8), (byte) (v >> 16), (byte) (v >> 24)};
        st.setConcrete(st.getLanguage().getDefaultSpace().getAddress(a), b);
    }

    /**
     * Float to integer after the RXv2 software manual R01US0071EJ0100: kind 0 FTOI (p. 103) and 2 FTOU (p. 106) round
     * towards 0 whatever FPSW.RM says; kind 1 ROUND (p. 171) rounds by FPSW.RM, taken as 0 (round to nearest, ties to
     * even: MAIN sets FPSW = 0x100 at 0xFFF8FBFF and never another RM). NaN or out of range is the invalid operation
     * exception; with it disabled (FPSW.EV = 0) the result is 7FFFFFFFh / 80000000h by the sign for FTOI and ROUND,
     * FFFFFFFFh / 0 for FTOU (Table 1.5, p. 26), and the S and Z flags do not change (p. 106 note). Returns {result, flags
     * changed}. FPSW's own flags are not modelled (nor are they by the module).
     */
    static long[] fpConv(int kind, int bits) {
        float f = Float.intBitsToFloat(bits);
        boolean neg = bits < 0;
        if (kind == 2) {
            if (Float.isNaN(f) || f >= 4294967296f || f <= -1f) return new long[]{neg ? 0 : 0xFFFFFFFFL, 0};
            return new long[]{((long) f) & 0xFFFFFFFFL, 1};      // (long) truncates towards 0: -0.5 gives 0
        }
        double v = kind == 1 ? Math.rint(f) : (f >= 0 ? Math.floor(f) : Math.ceil(f));
        if (Float.isNaN(f) || v >= 2147483648.0 || v < -2147483648.0) return new long[]{neg ? 0x80000000L : 0x7FFFFFFFL, 0};
        return new long[]{((long) v) & 0xFFFFFFFFL, 1};
    }

    static long readLE(PcodeExecutorState<byte[]> st, long a) {
        byte[] b = st.inspectConcrete(st.getLanguage().getDefaultSpace().getAddress(a), 4);
        return (b[0] & 0xffL) | (b[1] & 0xffL) << 8 | (b[2] & 0xffL) << 16 | (b[3] & 0xffL) << 24;
    }

    JsonObject doBlocks(JsonObject q) throws Exception {
        SimpleBlockModel model = new SimpleBlockModel(currentProgram);
        JsonObject blocks = new JsonObject();
        for (JsonElement e : q.getAsJsonArray("entries")) {
            long a = lv(e);
            Function f = currentProgram.getFunctionManager().getFunctionAt(ram.getAddress(a));
            JsonArray arr = new JsonArray();
            boolean isr = false;
            if (f != null) {
                CodeBlockIterator it = model.getCodeBlocksContaining(f.getBody(), monitor);
                while (it.hasNext()) {
                    CodeBlock b = it.next();
                    arr.add(b.getFirstStartAddress().getOffset());
                }
                for (Instruction ins : currentProgram.getListing().getInstructions(f.getBody(), true))
                    if (ins.getMnemonicString().equalsIgnoreCase("RTE")) isr = true;
            }
            JsonObject o = new JsonObject();
            o.add("blocks", arr);
            o.addProperty("isr", isr);
            o.addProperty("found", f != null);
            blocks.add(String.valueOf(a), o);
        }
        JsonObject res = new JsonObject();
        res.add("blocks", blocks);
        return res;
    }

    @Override
    protected void run() throws Exception {
        lang = currentProgram.getLanguage();
        ram = currentProgram.getAddressFactory().getDefaultAddressSpace();
        out = new PrintStream(new FileOutputStream(FileDescriptor.out), true, "UTF-8");
        Gson gson = new Gson();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in, "UTF-8"));
        out.println("@@EQ {\"ready\":true}");
        String line;
        while ((line = in.readLine()) != null) {
            if (line.isBlank()) continue;
            JsonObject q = JsonParser.parseString(line).getAsJsonObject();
            String op = q.get("op").getAsString();
            JsonObject res;
            try {
                switch (op) {
                    case "quit":
                        out.println("@@EQ {\"bye\":true}");
                        return;
                    case "base": {
                        List<Object[]> segs = new ArrayList<>();
                        for (JsonElement e : q.getAsJsonArray("segs")) {
                            JsonArray a = e.getAsJsonArray();
                            segs.add(new Object[]{lv(a.get(0)), unhex(a.get(1).getAsString())});
                        }
                        bases.put(q.get("name").getAsString(), segs);
                        res = new JsonObject();
                        res.addProperty("ok", true);
                        break;
                    }
                    case "blocks":
                        res = doBlocks(q);
                        break;
                    case "run":
                        res = doRun(q);
                        break;
                    default:
                        throw new IllegalArgumentException("unknown op " + op);
                }
            } catch (Exception e) {
                res = new JsonObject();
                res.addProperty("error", e.toString());
            }
            out.println("@@EQ " + gson.toJson(res));
        }
    }
}
