// Short inline comments in the decompiled C (T23i): PRE comments at instruction addresses, which the decompiler prints
// above the statement of that instruction, so every export (ExportDecomp.java) and the readable view keep them.
// Headless usage (from the repo root), after every other apply script (names, signatures, enums, structs, registers):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -scriptPath tools/ghidra \
//     -postScript CommentCode.java tools/ghidra/sfr_rx651.tsv tools/ghidra/purposes_main.tsv tools/ghidra/comments_main.tsv [out.tsv]
// Any of the three tables may be "-". out.tsv (optional) lists every comment the script owns: address, function, rule, text.
//
// Two sources, each comment one short line ending in its evidence tag:
//   curated   tools/ghidra/comments_<image>.tsv: address<TAB>comment<TAB>evidence, evidence "[fact: <addr>...]" or
//             "[inference: <reason>]" / "[inference]". Printed as "<comment> <evidence>". The address must be an
//             instruction inside a function, not its entry (a PRE comment at the entry prints in the function header).
//   generated from one decompile of each function (high p-code, so a rule sees what the C prints):
//     [sfr]   first read or write of a peripheral register in the function: the register's name from the SFR table
//             (column 10, without the word "register"), e.g. "Protect [sfr]" above SYSTEM_PRCR = 0xa50b.
//     [doc]   first call of a documented function: its short purpose from purposes_<image>.tsv (made by
//             tools/code_comments.py from the docs/code/ function tables; rows tagged [inference] there print
//             "[doc, inference]"). The table already leaves out purposes the callee's name says.
//     [enum]  equality tests of a constant against a value returned by a function whose return type is an enum (ApplyEnums)
//             that the decompiler printed as a plain number (the local lost the type), e.g. "7 MODE_FM_N, 0xb MODE_DATA_U [enum]".
// A curated row at a call replaces that call's [doc] line. Generated comments skip places where a comment would print
// above an "else if" condition (the decompiler would then write "else { if" and change the shape of the C).
// Ownership: a PRE comment line that ends in one of these tags belongs to this script and is replaced on every run;
// other lines (hand-written comments) are kept above it. Idempotent and deterministic: a second run changes nothing.
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.address.AddressIterator;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.Enum;
import ghidra.program.model.data.TypeDef;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.PcodeBlockBasic;
import ghidra.program.model.pcode.PcodeOpAST;
import ghidra.program.model.pcode.Varnode;

import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.regex.Pattern;

public class CommentCode extends GhidraScript {
    /** A line this script owns: ends in a generated tag or a curated evidence tag. */
    static final Pattern OWNED = Pattern.compile(".* \\[(sfr|enum|doc|doc, inference|fact: [^\\]]+|inference(: [^\\]]+)?)\\]$");
    static final Pattern EVIDENCE = Pattern.compile("\\[(fact: [^\\]]+|inference(: [^\\]]+)?)\\]");
    static final int MAX_LEN = 110, SFR_LEN = 50;

    static final int CURATED = 0, SFR = 1, DOC = 2, ENUM = 3;
    static final String[] RULE = {"curated", "sfr", "doc", "enum"};

    /** address -> (rule order, text); TreeMap keeps the output deterministic. */
    final TreeMap<Address, TreeMap<String, String>> want = new TreeMap<>();
    final int[] perRule = new int[4];
    final List<String[]> outRows = new ArrayList<>();
    int failed = 0;

    void add(Address a, int rule, String text, Function f) {
        text = text.replace("*/", "* /").replace("/*", "/ *").replaceAll("\\s+", " ").trim();
        if (text.length() > MAX_LEN) {
            printerr("CommentCode: comment longer than " + MAX_LEN + " at " + a + ": " + text);
            failed++;
            return;
        }
        TreeMap<String, String> m = want.computeIfAbsent(a, k -> new TreeMap<>());
        // a curated note at a call already says what the call does: no [doc] line under it
        if (rule == DOC && m.keySet().stream().anyMatch(k -> k.startsWith(CURATED + ":"))) return;
        String key = rule + ":" + text;
        if (m.containsKey(key)) return;
        m.put(key, text);
        perRule[rule]++;
        outRows.add(new String[] {a.toString(), f == null ? "" : f.getName(), RULE[rule], text});
    }

    static List<String[]> readTsv(String path) throws Exception {
        List<String[]> rows = new ArrayList<>();
        if (path == null || path.equals("-")) return rows;
        for (String line : Files.readAllLines(Paths.get(path))) {
            if (line.isBlank() || line.startsWith("#")) continue;
            rows.add(line.split("\t", -1));
        }
        return rows;
    }

    static String shortRegName(String name) {
        String s = name.replaceAll("\\s*\\[[^\\]]*\\]", "")      // source notes of EXTRA rows
                .replaceFirst("^\\w+ \\+0x[0-9A-Fa-f]+: ", "")             // "PMC +0x20: " prefix of EXTRA rows
                .replaceAll("(?i)\\bregister(?=\\b|_)", "").replaceAll("\\s+", " ").trim();
        s = s.replaceAll("^_+|_+$", "").replaceAll(" _", "_").trim();
        if (s.isEmpty()) return name;
        // long SVD descriptions: cut at the first clause break, then at a word boundary
        if (s.length() > SFR_LEN) {
            java.util.regex.Matcher m = Pattern.compile(", | to | that | used | when | for | which |; |: ").matcher(s);
            while (m.find()) {
                if (m.start() >= 12 && m.start() <= SFR_LEN) { s = s.substring(0, m.start()); break; }
            }
        }
        if (s.length() > SFR_LEN) s = s.substring(0, s.lastIndexOf(' ', SFR_LEN)) + " ...";
        return s;
    }

    /** Address a LOAD/STORE pointer or a RAM varnode stands for, or null. */
    Address ramAddress(Varnode v, int depth) {
        if (v == null || depth > 3) return null;
        if (v.isAddress() && v.getAddress().isMemoryAddress()) return v.getAddress();
        if (v.isConstant()) return null;
        PcodeOp d = v.getDef();
        if (d == null) return null;
        switch (d.getOpcode()) {
            case PcodeOp.PTRSUB:
                if (d.getInput(0).isConstant() && d.getInput(0).getOffset() == 0 && d.getInput(1).isConstant()) {
                    return toAddrSafe(d.getInput(1).getOffset());
                }
                return null;
            case PcodeOp.COPY:
            case PcodeOp.CAST:
                if (d.getInput(0).isConstant()) return toAddrSafe(d.getInput(0).getOffset());
                return ramAddress(d.getInput(0), depth + 1);
            default:
                return null;
        }
    }

    Address toAddrSafe(long off) {
        try {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(off);
            return currentProgram.getMemory().contains(a) ? a : null;
        } catch (Exception e) {
            return null;
        }
    }

    Address pointerArg(PcodeOp op) {
        Varnode p = op.getInput(1);
        if (p.isConstant()) {
            AddressSpace sp = currentProgram.getAddressFactory().getAddressSpace((int) op.getInput(0).getOffset());
            if (sp == null) return null;
            try {
                Address a = sp.getAddress(p.getOffset());
                return currentProgram.getMemory().contains(a) ? a : null;
            } catch (Exception e) {
                return null;
            }
        }
        return ramAddress(p, 0);
    }

    static Enum enumOf(DataType t) {
        while (t instanceof TypeDef) t = ((TypeDef) t).getBaseDataType();
        return t instanceof Enum ? (Enum) t : null;
    }

    /** The CALL whose (enum-typed) return value v carries, through copies, extensions and casts; or null. */
    Function enumCallee(Varnode v, int depth) {
        if (v == null || depth > 4) return null;
        PcodeOp d = v.getDef();
        if (d == null) return null;
        switch (d.getOpcode()) {
            case PcodeOp.CALL: {
                Function g = getFunctionAt(d.getInput(0).getAddress());
                return g != null && enumOf(g.getReturnType()) != null ? g : null;
            }
            case PcodeOp.COPY:
            case PcodeOp.CAST:
            case PcodeOp.INT_ZEXT:
            case PcodeOp.INT_SEXT:
                return enumCallee(d.getInput(0), depth + 1);
            case PcodeOp.SUBPIECE:
                return d.getInput(1).isConstant() && d.getInput(1).getOffset() == 0 ? enumCallee(d.getInput(0), depth + 1) : null;
            default:
                return null;
        }
    }

    /**
     * True when a comment at {@code at} would print right above the condition of a block that is the only successor
     * of another conditional branch: the decompiler then writes "else { (comment) if (...)" instead of "else if (...)",
     * so the comment would change the shape of the C. The comment prints before the first statement at or after its
     * address in its block; when no statement-like op (call, store, write to memory) comes before the block's
     * CBRANCH, that is the condition.
     */
    static boolean elseIfHeader(HighFunction hf, Address at) {
        for (PcodeBlockBasic b : hf.getBasicBlocks()) {
            if (!b.contains(at)) continue;
            boolean cond = false;
            for (Iterator<PcodeOp> it = b.getIterator(); it.hasNext();) {
                PcodeOp o = it.next();
                if (o.getSeqnum().getTarget().compareTo(at) < 0) continue;
                int oc = o.getOpcode();
                if (oc == PcodeOp.CBRANCH) { cond = true; break; }
                if (oc == PcodeOp.CALL || oc == PcodeOp.CALLIND || oc == PcodeOp.STORE || oc == PcodeOp.RETURN
                        || oc == PcodeOp.BRANCH || oc == PcodeOp.BRANCHIND) break;
                Varnode out = o.getOutput();
                if (out != null && out.isAddress() && out.getAddress().isMemoryAddress()) break;
            }
            if (!cond) continue;
            if (b.getInSize() == 1 && b.getIn(0) instanceof PcodeBlockBasic) {
                PcodeOp last = ((PcodeBlockBasic) b.getIn(0)).getLastOp();
                if (last != null && last.getOpcode() == PcodeOp.CBRANCH) return true;
            }
        }
        return false;
    }

    static String hex(long v) {
        return v < 10 ? Long.toString(v) : "0x" + Long.toHexString(v);
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 3) {
            printerr("usage: CommentCode.java <sfr.tsv|-> <purposes.tsv|-> <comments.tsv|-> [out.tsv]");
            return;
        }
        Listing listing = currentProgram.getListing();

        // ---- inputs
        Map<Address, String> sfr = new HashMap<>();
        for (String[] p : readTsv(args[0])) {
            if (p.length < 10 || !p[6].equals("1")) continue;
            Address a = toAddrSafe(Long.parseLong(p[0], 16));
            if (a != null) sfr.put(a, shortRegName(p[9]));
        }
        Map<Address, String> purpose = new HashMap<>();
        for (String[] p : readTsv(args[1])) {
            if (p.length < 4) continue;
            Address a = toAddrSafe(Long.parseLong(p[0], 16));
            if (a == null) continue;
            purpose.put(a, p[2] + (p[3].equals("inference") ? " [doc, inference]" : " [doc]"));
        }

        // ---- curated rows
        int curatedRows = 0;
        for (String[] p : readTsv(args[2])) {
            curatedRows++;
            if (p.length < 3 || p[1].isBlank() || !EVIDENCE.matcher(p[2].trim()).matches()) {
                printerr("CommentCode: bad curated row (need address, comment, [fact: ...] or [inference...]): " + String.join("\t", p));
                failed++;
                continue;
            }
            Address a = toAddrSafe(Long.parseLong(p[0].replaceFirst("^0x", ""), 16));
            Instruction ins = a == null ? null : listing.getInstructionAt(a);
            Function f = a == null ? null : getFunctionContaining(a);
            if (ins == null || f == null || f.getEntryPoint().equals(a)) {
                printerr("CommentCode: curated row not at an instruction inside a function (or at its entry): " + p[0]);
                failed++;
                continue;
            }
            add(a, CURATED, p[1].trim() + " " + p[2].trim(), f);
        }

        // ---- generated rules: one decompile per function
        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);
        List<Function> funcs = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (!f.isExternal() && !f.isThunk()) funcs.add(f);
        }
        monitor.initialize(funcs.size());
        int decompFailed = 0;
        for (Function f : funcs) {
            monitor.checkCancelled();
            monitor.incrementProgress(1);
            DecompileResults r = ifc.decompileFunction(f, 60, monitor);
            HighFunction hf = r == null ? null : r.getHighFunction();
            if (hf == null) {
                decompFailed++;
                continue;
            }
            Address entry = f.getEntryPoint();
            // collect per rule, ordered by address, then keep the first per register / callee / call
            TreeMap<Address, TreeSet<Address>> regAt = new TreeMap<>();
            TreeMap<Address, Address> callAt = new TreeMap<>();
            TreeMap<Address, TreeMap<Address, TreeSet<Long>>> enumAt = new TreeMap<>(); // callsite def -> cmp addr -> consts
            Map<Address, Address> enumFirst = new TreeMap<>();
            Map<Address, Function> enumFunc = new HashMap<>();
            for (Iterator<PcodeOpAST> it = hf.getPcodeOps(); it.hasNext();) {
                PcodeOpAST op = it.next();
                Address at = op.getSeqnum().getTarget();
                if (at == null || !f.getBody().contains(at)) continue;
                int oc = op.getOpcode();
                // [sfr]
                List<Address> regs = new ArrayList<>();
                if (oc == PcodeOp.LOAD || oc == PcodeOp.STORE) {
                    Address a = pointerArg(op);
                    if (a != null && sfr.containsKey(a)) regs.add(a);
                }
                Varnode out = op.getOutput();
                if (out != null && out.isAddress() && sfr.containsKey(out.getAddress())) regs.add(out.getAddress());
                for (int i = 0; i < op.getNumInputs(); i++) {
                    Varnode in = op.getInput(i);
                    if (in.isAddress() && sfr.containsKey(in.getAddress())) regs.add(in.getAddress());
                }
                for (Address a : regs) regAt.computeIfAbsent(at, k -> new TreeSet<>()).add(a);
                // [doc]
                if (oc == PcodeOp.CALL && op.getInput(0).isAddress()) {
                    Address tgt = op.getInput(0).getAddress();
                    if (purpose.containsKey(tgt) && !tgt.equals(entry)) callAt.put(at, tgt);
                }
                // [enum]
                if (oc == PcodeOp.INT_EQUAL || oc == PcodeOp.INT_NOTEQUAL) {
                    for (int k = 0; k < 2; k++) {
                        Varnode c = op.getInput(k), v = op.getInput(1 - k);
                        if (!c.isConstant() || v.isConstant()) continue;
                        Function g = enumCallee(v, 0);
                        if (g == null) continue;
                        Enum e = enumOf(g.getReturnType());
                        if (e.getName(c.getOffset()) == null) continue;
                        PcodeOp def = v.getDef();
                        while (def != null && def.getOpcode() != PcodeOp.CALL) def = def.getInput(0).getDef();
                        if (def == null) continue;
                        Address key = def.getSeqnum().getTarget();
                        enumAt.computeIfAbsent(key, x -> new TreeMap<>()).computeIfAbsent(at, x -> new TreeSet<>()).add(c.getOffset());
                        enumFunc.put(key, g);
                    }
                }
            }
            Set<Address> seenReg = new HashSet<>();
            for (Map.Entry<Address, TreeSet<Address>> e : regAt.entrySet()) {
                if (e.getKey().equals(entry) || elseIfHeader(hf, e.getKey())) continue;
                List<String> names = new ArrayList<>();
                for (Address a : e.getValue()) if (seenReg.add(a)) names.add(sfr.get(a));
                if (!names.isEmpty()) add(e.getKey(), SFR, String.join("; ", names) + " [sfr]", f);
            }
            Set<Address> seenCall = new HashSet<>();
            for (Map.Entry<Address, Address> e : callAt.entrySet()) {
                if (e.getKey().equals(entry) || elseIfHeader(hf, e.getKey()) || !seenCall.add(e.getValue())) continue;
                add(e.getKey(), DOC, purpose.get(e.getValue()), f);
            }
            for (Map.Entry<Address, TreeMap<Address, TreeSet<Long>>> e : enumAt.entrySet()) {
                Enum en = enumOf(enumFunc.get(e.getKey()).getReturnType());
                TreeSet<Long> all = new TreeSet<>();
                for (TreeSet<Long> s : e.getValue().values()) all.addAll(s);
                Address first = e.getValue().firstKey();
                if (first.equals(entry) || elseIfHeader(hf, first)) continue;
                List<String> parts = new ArrayList<>();
                for (long v : all) parts.add(hex(v) + " " + en.getName(v));
                add(first, ENUM, String.join(", ", parts) + " [enum]", f);
            }
        }
        ifc.dispose();

        // ---- apply: replace the owned lines, keep the others
        Set<Address> touch = new TreeSet<>(want.keySet());
        AddressIterator ai = listing.getCommentAddressIterator(CodeUnit.PRE_COMMENT, currentProgram.getMemory(), true);
        while (ai.hasNext()) touch.add(ai.next());
        int changed = 0, removed = 0, kept = 0;
        for (Address a : touch) {
            String cur = listing.getComment(CodeUnit.PRE_COMMENT, a);
            List<String> lines = new ArrayList<>();
            if (cur != null) {
                for (String l : cur.split("\n")) {
                    if (OWNED.matcher(l).matches()) continue;
                    lines.add(l);
                }
            }
            if (!lines.isEmpty()) kept++;
            TreeMap<String, String> m = want.get(a);
            if (m != null) lines.addAll(m.values());
            String next = lines.isEmpty() ? null : String.join("\n", lines);
            if (Objects.equals(cur, next)) continue;
            listing.setComment(a, CodeUnit.PRE_COMMENT, next);
            if (next == null) removed++;
            else changed++;
        }
        if (args.length > 3) {
            try (PrintWriter w = new PrintWriter(args[3], "UTF-8")) {
                w.println("address\tfunction\trule\tcomment");
                outRows.sort(Comparator.comparing((String[] x) -> x[0]).thenComparing(x -> x[2]).thenComparing(x -> x[3]));
                for (String[] r : outRows) w.println(String.join("\t", r));
            }
        }
        println("CommentCode: " + want.size() + " addresses: " + perRule[CURATED] + " curated (of " + curatedRows + " rows), "
                + perRule[SFR] + " sfr, " + perRule[DOC] + " doc, " + perRule[ENUM] + " enum; " + changed + " set, " + removed
                + " removed, " + kept + " with hand-written lines kept; " + decompFailed + " functions not decompiled, "
                + failed + " failed");
    }
}
