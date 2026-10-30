// List the access width of every RAM global access in the decompiler's p-code (T23c, input for tools/struct_offsets.py).
// The C text does not show widths for absolute globals (`DAT_00020b08` may be a u16), so this script decompiles every
// function and records, from the high p-code:
//   abs   a RAM varnode (a global read or written directly): address, size
//   ptr   LOAD/STORE through a RAM pointer global plus a constant (`PTR_DAT_00025d54[0x86]`): pointer, offset, size
//   cptr  LOAD/STORE through a constant address
// Headless usage (from the repo root; read-only):
//   tools/ghidra-headless.sh <projdir> FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript StructAccessDump.java build/t23c/access.tsv [maxram]
// Output: function<TAB>kind<TAB>pointer<TAB>address<TAB>size<TAB>rw  (pointer "-" for abs/cptr; address = target for ptr
// accesses is pointer value + offset, read from the program's memory). RAM is [minram, maxram): maxram defaults to
// 0x40000 and minram to 0 (MAIN). DISPLAY (RZ/A1H, code and data in on-chip RAM from 0x20000000):
//   ... -postScript StructAccessDump.java build/t23c/display_access.tsv 0x20A00000 0x20000000
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.PcodeOpAST;
import ghidra.program.model.pcode.Varnode;

import java.io.PrintWriter;
import java.util.Iterator;
import java.util.TreeMap;

public class StructAccessDump extends GhidraScript {
    long maxRam = 0x40000, minRam = 0;

    boolean ram(Varnode v) {
        return v != null && v.isAddress() && v.getAddress().getAddressSpace().isMemorySpace()
                && v.getOffset() >= minRam && v.getOffset() < maxRam;
    }

    /** Pointer expression -> {pointer global address, constant offset}, or null. */
    long[] base(Varnode p, int depth) {
        if (p == null || depth > 4) return null;
        if (ram(p) && p.getSize() == 4) return new long[] {p.getOffset(), 0};
        PcodeOp d = p.getDef();
        if (d == null) return null;
        int op = d.getOpcode();
        if (op == PcodeOp.COPY || op == PcodeOp.CAST) return base(d.getInput(0), depth + 1);
        if (op == PcodeOp.INT_ADD || op == PcodeOp.PTRSUB) {
            Varnode a = d.getInput(0), b = d.getInput(1);
            if (b.isConstant()) { long[] r = base(a, depth + 1); if (r != null) r[1] += b.getOffset(); return r; }
            if (a.isConstant()) { long[] r = base(b, depth + 1); if (r != null) r[1] += a.getOffset(); return r; }
            return null;
        }
        if (op == PcodeOp.PTRADD) {
            Varnode a = d.getInput(0), i = d.getInput(1), s = d.getInput(2);
            if (i.isConstant() && s.isConstant()) {
                long[] r = base(a, depth + 1);
                if (r != null) r[1] += i.getOffset() * s.getOffset();
                return r;
            }
        }
        return null;
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length > 1) maxRam = Long.decode(args[1]);
        if (args.length > 2) minRam = Long.decode(args[2]);
        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);
        TreeMap<Long, Long> ptrValue = new TreeMap<>();
        int nf = 0, nrows = 0;
        try (PrintWriter w = new PrintWriter(args[0], "UTF-8")) {
            w.println("function\tkind\tpointer\taddress\tsize\trw");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (f.isExternal() || f.isThunk()) continue;
                monitor.checkCancelled();
                DecompileResults r = ifc.decompileFunction(f, 60, monitor);
                HighFunction h = r == null ? null : r.getHighFunction();
                if (h == null) continue;
                nf++;
                String fn = f.getName() + "@" + f.getEntryPoint();
                for (Iterator<PcodeOpAST> it = h.getPcodeOps(); it.hasNext();) {
                    PcodeOpAST op = it.next();
                    int oc = op.getOpcode();
                    if (oc == PcodeOp.LOAD || oc == PcodeOp.STORE) {
                        Varnode p = op.getInput(1);
                        int size = oc == PcodeOp.LOAD ? op.getOutput().getSize() : op.getInput(2).getSize();
                        String rw = oc == PcodeOp.LOAD ? "r" : "w";
                        if (p.isConstant()) {
                            if (p.getOffset() >= minRam && p.getOffset() < maxRam) {
                                w.printf("%s\tcptr\t-\t0x%05X\t%d\t%s%n", fn, p.getOffset(), size, rw);
                                nrows++;
                            }
                            continue;
                        }
                        long[] b = base(p, 0);
                        if (b == null) continue;
                        Long v = ptrValue.get(b[0]);
                        if (v == null) {
                            try { v = currentProgram.getMemory().getInt(toAddr(b[0])) & 0xFFFFFFFFL; }
                            catch (Exception e) { v = -1L; }
                            ptrValue.put(b[0], v);
                        }
                        if (v < minRam || v >= maxRam) continue;
                        w.printf("%s\tptr\t0x%05X\t0x%05X\t%d\t%s%n", fn, b[0], v + b[1], size, rw);
                        nrows++;
                        continue;
                    }
                    // INDIRECT (a call may change the global) and MULTIEQUAL (a merge) are not accesses in the source
                    if (oc == PcodeOp.INDIRECT || oc == PcodeOp.MULTIEQUAL) continue;
                    Varnode out = op.getOutput();
                    if (ram(out)) {
                        w.printf("%s\tabs\t-\t0x%05X\t%d\tw%n", fn, out.getOffset(), out.getSize());
                        nrows++;
                    }
                    for (Varnode in : op.getInputs()) {
                        if (ram(in)) {
                            w.printf("%s\tabs\t-\t0x%05X\t%d\tr%n", fn, in.getOffset(), in.getSize());
                            nrows++;
                        }
                    }
                }
            }
        }
        ifc.dispose();
        println("StructAccessDump: " + nf + " functions, " + nrows + " accesses");
    }
}
