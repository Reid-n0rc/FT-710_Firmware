// Recover ARM (A32) jump tables that auto-analysis left unresolved (T21e, issue #97 B6; DISPLAY, reusable for any ARM image).
// armcc emits two table forms after a bounds check `cmp rX,#k`:
//   ldr<cc> pc,[pc,rX,lsl #2]   then `b default`, then k words of case addresses        (encoding c79FF10x)
//   add<cc> pc,pc,rX,lsl #2     then `b default`, then k instructions (mostly `b case`) (encoding c08FF10x)
// The table length comes from the cmp and the condition: cc/lo -> k entries, ls -> k+1; with an unconditional
// computed jump the preceding b<cond> to the default decides (hi -> k+1, cs -> k).
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript DisplayJumpTables.java <mode> [report.tsv]
// Modes:
//   scan   (read only) list every site and its table, nothing changed
//   apply  decompiles every site; only sites the decompiler does not already turn into a switch with all cases are
//          touched: table words -> pointers (ldr form) or instructions (add form), case targets disassembled, stray
//          references (a table guessed one word early) and a RETURN flow override removed, COMPUTED_JUMP references
//          added, function body fixed up. A site that still fails gets a switch override (JumpTable). Functions that
//          DisplayFindCode's orphan pass had started at a case target (no call or data reference) are removed first,
//          so the cases join the switch's function. Idempotent (a second run touches nothing).
//   check  (read only) decompile every site's function; a site passes when the decompiler built a jump table at it
//          with all its cases. Prints FAIL lines and a summary.
// The report TSV (optional) has one row per site: site, form, cond, reg, entries, function, status, detail.
// @category FT710
import ghidra.app.cmd.disassemble.ArmDisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.JumpTable;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.SourceType;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;

public class DisplayJumpTables extends GhidraScript {
    static final String[] COND = {"eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "", "nv"};

    static class Site {
        Address at;
        boolean ldr;          // ldr pc,[pc,...] (address table) vs add pc,pc,... (branch table)
        int cond, reg, k = -1, n = -1;
        String status = "", detail = "", action = "";
        List<Address> targets = new ArrayList<>();
    }

    int word(Address a) throws Exception { return getInt(a); }

    static long armImm(int w) {
        int rot = ((w >>> 8) & 0xF) * 2;
        long v = w & 0xFF;
        return ((v >>> rot) | (v << (32 - rot))) & 0xFFFFFFFFL;
    }

    boolean isArm(Address a) {
        Register t = currentProgram.getRegister("TMode");
        if (t == null) return true;
        java.math.BigInteger v = currentProgram.getProgramContext().getValue(t, a, false);
        return v == null || v.signum() == 0;
    }

    boolean writes(Instruction ins, String regName) {
        for (Object o : ins.getResultObjects()) {
            if (o instanceof Register r && r.getName().equalsIgnoreCase(regName)) return true;
        }
        return false;
    }

    boolean writesFlags(Instruction ins) {
        for (Object o : ins.getResultObjects()) {
            if (o instanceof Register r) {
                String n = r.getName();
                if (n.equals("NG") || n.equals("ZR") || n.equals("CY") || n.equals("OV")) return true;
            }
        }
        return false;
    }

    /** Find the bounds check before the site and compute the table length. */
    void bound(Site s) throws Exception {
        Instruction cur = getInstructionAt(s.at);
        int branchCond = -1;
        String rn = "r" + s.reg;
        for (int i = 0; i < 64; i++) {
            Instruction p = getInstructionBefore(cur.getAddress());
            if (p == null || !p.getMaxAddress().next().equals(cur.getAddress()) || p.getLength() != 4) break;
            int w = word(p.getAddress());
            int c = w >>> 28;
            if ((w & 0x0FF0F000) == 0x03500000 && c == 0xE) {             // cmp Rn,#imm
                if (((w >>> 16) & 0xF) == s.reg) { s.k = (int) armImm(w); break; }
                s.detail = "flags set by cmp on another register at " + p.getAddress();
                return;
            }
            if ((w & 0x0F000000) == 0x0A000000 && c != 0xE) {            // b<cond> (bounds branch)
                if (branchCond < 0) branchCond = c;
            } else if (writesFlags(p)) {
                s.detail = "flags set at " + p.getAddress() + " before any cmp " + rn;
                return;
            }
            if (writes(p, rn)) { s.detail = rn + " written at " + p.getAddress() + " after the bound"; return; }
            cur = p;
        }
        if (s.k < 0) { if (s.detail.isEmpty()) s.detail = "no cmp " + rn + ",#imm within 64 instructions"; return; }
        int c = s.cond == 0xE ? branchCond : s.cond;
        if (s.cond == 0xE) {
            // unconditional jump guarded by an earlier branch to the default: hi -> k+1 entries, cs -> k
            if (c == 8) s.n = s.k + 1; else if (c == 2) s.n = s.k;
        } else if (c == 3) s.n = s.k;                                     // cc/lo
        else if (c == 9) s.n = s.k + 1;                                   // ls
        if (s.n <= 0 || s.n > 1024) { s.n = -1; s.detail = "condition " + COND[s.cond] + "/" + (c < 0 ? "?" : COND[c]) + " not a bound"; }
    }

    void targets(Site s) throws Exception {
        Address t0 = s.at.add(8);
        for (int i = 0; i < s.n; i++) {
            Address e = t0.add(4L * i);
            if (s.ldr) {
                long v = word(e) & 0xFFFFFFFFL;
                Address t = toAddr(v & ~1L);
                MemoryBlock b = getMemoryBlock(t);
                if (b == null || !b.isExecute() || ((v & 1) == 0 && (v & 3) != 0)) {
                    s.detail = "entry " + i + " = 0x" + Long.toHexString(v) + " is not code";
                    s.targets.clear(); s.n = -1; return;
                }
                s.targets.add(t);
            } else {
                s.targets.add(e);
            }
        }
    }

    List<Site> scan() throws Exception {
        List<Site> out = new ArrayList<>();
        for (Instruction ins : currentProgram.getListing().getInstructions(true)) {
            monitor.checkCancelled();
            if (ins.getLength() != 4 || !isArm(ins.getAddress())) continue;
            int w = word(ins.getAddress());
            int m = w & 0x0FFFFFF0;
            if (m != 0x079FF100 && m != 0x008FF100) continue;
            Site s = new Site();
            s.at = ins.getAddress();
            s.ldr = m == 0x079FF100;
            s.cond = w >>> 28;
            s.reg = w & 0xF;
            bound(s);
            if (s.n > 0) targets(s);
            out.add(s);
        }
        return out;
    }

    boolean onlyJumpRefs(Function f) {
        for (Reference r : getReferencesTo(f.getEntryPoint())) {
            RefType t = r.getReferenceType();
            if (t.isCall() || t.isData() || r.getReferenceType() == RefType.DATA) return false;
            if (!t.isJump() && !t.isFlow()) return false;
        }
        return true;
    }

    void disasm(Address a, boolean thumb) {
        if (getInstructionAt(a) != null) return;
        Data d = getDataContaining(a);
        if (d != null) {
            if (d.isDefined()) return;      // never overwrite defined data
        }
        new ArmDisassembleCommand(a, null, thumb).applyTo(currentProgram, monitor);
    }

    int removedFuncs = 0, flowCleared = 0, overrides = 0, repaired = 0;

    /** Repair one site: table, cases, references, flow override, body; with override=true also write a JumpTable override. */
    void apply(Site s, boolean override) throws Exception {
        Address t0 = s.at.add(8);
        Address tEnd = t0.add(4L * s.n - 1);
        if (s.ldr) {
            Instruction in = getInstructionContaining(t0);
            Address firstIns = null;
            for (Address a = t0; a.compareTo(tEnd) <= 0; a = a.add(4)) {
                if (getInstructionContaining(a) != null) { firstIns = a; break; }
            }
            if (firstIns != null) {
                // table words were disassembled as code: clear them (and only them)
                clearListing(t0, tEnd);
            }
            for (int i = 0; i < s.n; i++) {
                Address e = t0.add(4L * i);
                Data d = getDataAt(e);
                if (d != null && d.isPointer()) continue;
                clearListing(e, e.add(3));
                createData(e, PointerDataType.dataType);
            }
        } else {
            for (int i = 0; i < s.n; i++) disasm(t0.add(4L * i), false);
        }
        disasm(s.at.add(4), false);
        // remove functions that the orphan pass started at a case target (not called, not referenced as data)
        for (Address t : new LinkedHashSet<>(s.targets)) {
            Function f = getFunctionAt(t);
            if (f != null && !f.getEntryPoint().equals(getFunctionContaining(s.at) == null ? null : getFunctionContaining(s.at).getEntryPoint())
                    && onlyJumpRefs(f)) {
                removeFunction(f);
                removedFuncs++;
            }
        }
        for (Address t : s.targets) {
            long v = s.ldr ? (word(t0.add(4L * s.targets.indexOf(t))) & 0xFFFFFFFFL) : 0;
            disasm(t, s.ldr && (v & 1) != 0);
        }
        Instruction ins = getInstructionAt(s.at);
        Function f = getFunctionContaining(s.at);
        if (f == null) { s.status = "nofunc"; s.detail = "site is in no function"; return; }
        ArrayList<Address> dest = new ArrayList<>(new LinkedHashSet<>(s.targets));
        // Drop every reference that is not a case or the table read. Auto-analysis sometimes guesses the table one word
        // early (from site+4): its references to the `b default` word and to that word read as an address
        // (0xEA00xxxx, unmapped) make the decompiler process die on the function.
        for (Reference r : ins.getReferencesFrom()) {
            Address to = r.getToAddress();
            boolean keep = r.getReferenceType() == RefType.COMPUTED_JUMP ? dest.contains(to)
                    : !r.getReferenceType().isFlow() && s.ldr && to.equals(t0);
            if (!keep) currentProgram.getReferenceManager().delete(r);
        }
        // Auto-analysis marks some sites (the RSPI helpers, which bound-check twice) with a RETURN flow override; the
        // decompiler then treats the jump as a return, and dies on the switch override. Clear it.
        if (ins.getFlowOverride() != ghidra.program.model.listing.FlowOverride.NONE) {
            s.action += "flow override " + ins.getFlowOverride() + " cleared; ";
            ins.setFlowOverride(ghidra.program.model.listing.FlowOverride.NONE);
            flowCleared++;
        }
        for (Address t : dest) ins.addOperandReference(0, t, RefType.COMPUTED_JUMP, SourceType.USER_DEFINED);
        if (override) { new JumpTable(s.at, dest, true, 0).writeOverride(f); overrides++; }
        CreateFunctionCmd.fixupFunctionBody(currentProgram, f, monitor);
        s.status = "applied";
        if (!override) repaired++;
        s.action += (override ? "switch override" : "references fixed") + " (" + dest.size() + " cases); ";
    }

    /** apply mode: repair only the sites the decompiler does not already turn into a full switch. */
    void applyAll(List<Site> sites) throws Exception {
        List<Site> todo = new ArrayList<>();
        for (Site s : sites) if (s.n > 0) todo.add(s);
        check(todo);
        List<Site> bad = new ArrayList<>();
        for (Site s : todo) if (!s.status.equals("ok")) bad.add(s);
        for (Site s : bad) apply(s, false);
        check(bad);
        List<Site> still = new ArrayList<>();
        for (Site s : bad) if (!s.status.equals("ok")) still.add(s);
        for (Site s : still) apply(s, true);
        check(still);
    }

    void check(List<Site> sites) throws Exception {
        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);
        java.util.Map<Function, HighFunction> cache = new java.util.HashMap<>();
        java.util.Map<Function, String> ccache = new java.util.HashMap<>();
        for (Site s : sites) {
            if (s.n <= 0) { s.status = "unresolved"; continue; }
            Function f = getFunctionContaining(s.at);
            if (f == null) { s.status = "FAIL"; s.detail = "site in no function"; continue; }
            if (!cache.containsKey(f)) {
                DecompileResults r = ifc.decompileFunction(f, 60, monitor);
                cache.put(f, r != null && r.decompileCompleted() ? r.getHighFunction() : null);
                ccache.put(f, r != null && r.getDecompiledFunction() != null ? r.getDecompiledFunction().getC()
                        : "ERR " + (r == null ? "null" : r.getErrorMessage()));
            }
            HighFunction h = cache.get(f);
            if (h == null) { s.status = "FAIL"; s.detail = f.getName() + ": decompile failed: " + ccache.get(f).trim(); continue; }
            JumpTable hit = null;
            for (JumpTable jt : h.getJumpTables()) if (jt.getSwitchAddress().equals(s.at)) hit = jt;
            int want = new LinkedHashSet<>(s.targets).size();
            if (hit == null) { s.status = "FAIL"; s.detail = f.getName() + ": no switch at site"; continue; }
            LinkedHashSet<Address> got = new LinkedHashSet<>(java.util.Arrays.asList(hit.getCases()));
            boolean all = got.containsAll(new LinkedHashSet<>(s.targets));
            boolean inC = ccache.get(f).contains("switch(");
            s.status = all && inC ? "ok" : "FAIL";
            s.detail = f.getName() + ": switch cases " + got.size() + "/" + want + (inC ? "" : ", no switch( in C");
        }
        ifc.dispose();
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        String mode = args.length > 0 ? args[0] : "scan";
        List<Site> sites = scan();
        int resolved = 0, ldr = 0;
        for (Site s : sites) { if (s.n > 0) resolved++; if (s.ldr) ldr++; }
        println("DisplayJumpTables: " + sites.size() + " sites (" + ldr + " ldr pc, " + (sites.size() - ldr)
                + " add pc), " + resolved + " with a table length");
        if (mode.equals("apply")) {
            applyAll(sites);
            // second pass: sites inside code that the first pass disassembled (cases of nested switches)
            List<Site> fresh = new ArrayList<>();
            for (Site s : scan()) {
                boolean seen = false;
                for (Site o : sites) if (o.at.equals(s.at)) seen = true;
                if (!seen) fresh.add(s);
            }
            applyAll(fresh);
            sites.addAll(fresh);
            println("DisplayJumpTables apply: " + repaired + " sites repaired by references alone, " + overrides
                    + " switch overrides written, " + removedFuncs + " case-target functions removed, " + flowCleared
                    + " flow overrides cleared, " + fresh.size() + " new sites in the second pass");
        }
        if (mode.equals("check") || mode.equals("apply")) {
            if (mode.equals("check")) check(sites);
            int ok = 0, fail = 0;
            for (Site s : sites) {
                if (s.status.equals("ok")) ok++;
                if (s.status.equals("FAIL")) { fail++; println("FAIL " + s.at + " " + s.detail); }
            }
            println("DisplayJumpTables check: " + ok + " ok, " + fail + " FAIL, " + (sites.size() - ok - fail) + " unresolved");
        } else {
            for (Site s : sites) s.status = s.n > 0 ? "found" : "unresolved";
        }
        for (Site s : sites) if (s.status.equals("unresolved")) println("unresolved " + s.at + " " + s.detail);
        if (args.length > 1) {
            try (PrintWriter pw = new PrintWriter(args[1], "UTF-8")) {
                pw.println("site\tform\tcond\treg\tentries\tfunction\tstatus\tdetail\taction");
                for (Site s : sites) {
                    Function f = getFunctionContaining(s.at);
                    pw.println(s.at + "\t" + (s.ldr ? "ldr" : "add") + "\t" + COND[s.cond] + "\tr" + s.reg + "\t" + s.n
                            + "\t" + (f == null ? "" : f.getEntryPoint() + " " + f.getName()) + "\t" + s.status + "\t" + s.detail + "\t" + s.action);
                }
            }
        }
    }
}
