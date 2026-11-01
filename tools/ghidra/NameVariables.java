// Give decompiler variables and parameters names by fixed rules that the code itself shows (T23h).
// Headless usage (from the repo root; run after every other apply script, it reads the names they set):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -scriptPath tools/ghidra \
//     -postScript NameVariables.java log=logs/namevars_<image>.tsv [sfr=tools/ghidra/sfr_<chip>.tsv] [params=all|locked|none] [dry] [debug=<function>]
// Rules, in priority order (docs/tasks/T23-readability.md, T23h, gives each rule's evidence tag):
//   a  a variable or parameter whose name is not a Ghidra default (param_N, xVarN, local_xx, xStack_xx, stack0xNN) keeps it
//   b  a parameter that the function never changes and passes as an argument to a callee whose prototype is locked and whose
//      parameter in that slot has a non-default name gets that name; iterated over the call graph until stable; when the
//      callee parameters it reaches disagree, it keeps its default name
//   c  a local whose only definition is a read of a peripheral register (a label from the sfr= table, ApplySfr.java) gets the
//      register label in lower case
//   d  a local whose only definition is a read of a whole named global (a non-default label on undefined bytes or on
//      non-composite data of the read's size) gets <global>_val (the plain global name would shadow the global); a read of
//      a whole named field of a labelled structure (printed g.a.b) gets <g>_<a>_<b>_val
//   e  a local whose only definition is the return value of a named function with a locked, non-void return type (directly,
//      or through a cast or zero/sign extension of a value used nowhere else) gets <callee>_ret
//   f  a variable typed as a pointer to a named structure or union gets p_<struct>
//   g  a simple loop counter (set from a constant, stepped by +1 or -1, compared in a loop condition) gets i, j, k in the
//      order the counters are first set
// Never touched: in_*, unaff_*, extraout_* (they are decompile-quality signals counted by ExportDecomp.java).
// A name that is already used in the function, names a global, function, label or data type, or is a C keyword gets a
// numeric suffix (_2, _3, ...). Names are committed with SourceType.ANALYSIS (so they can be told apart from the
// USER_DEFINED/IMPORTED names of the TSVs); a local is committed with an undefined data type of its size (name lock only,
// no type lock), as the decompiler's own rename does. Parameters: params=all (default) commits, where the database has no
// parameter list matching the decompiler's, that list with undefined types and the function's current signature source
// (exactly what the decompiler's rename action does: a DEFAULT signature stays unlocked); checked on copies of all four
// programs with tools/rename_check.py (no function changed structure) and decomp_quality.py (nothing worse), T23h.
// params=locked renames only parameters already in the database (ApplySignatures/ApplyStructs); params=none skips
// rules b and f for parameters. dry = log only, change nothing. debug=<function> prints each local's definitions.
// Deterministic (functions in address order, variables in storage/first-use order) and idempotent (a second run finds
// only non-default names). Log: TSV function, entry, old, new, rule (only the renames made).
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.pcode.HighFunctionDBUtil.ReturnCommitOption;
import ghidra.program.model.symbol.*;

import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.regex.Pattern;

public class NameVariables extends GhidraScript {
    static final Pattern AUTO = Pattern.compile(
            "^(param_\\d+|[a-z]*Var\\d+|local_(res)?[0-9a-f]+|[a-z]*StackX?_[0-9a-f]+|stack0x[0-9a-f]+)(_[0-9a-f]+)?$");
    static final Pattern NEVER = Pattern.compile("^(in_|unaff_|extraout_).*");
    static final Pattern IDENT = Pattern.compile("^[A-Za-z_][A-Za-z0-9_]*$");
    static final Pattern DEFAULT_FUNC = Pattern.compile("^(thunk_)?FUN_[0-9a-fA-F]+$");
    static final Pattern AUTO_STRUCT = Pattern.compile("^(astruct|struct|anon_struct|union)(_\\d+)?$");
    static final Set<String> RESERVED = new HashSet<>(Arrays.asList(
            "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern",
            "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed",
            "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "bool",
            "true", "false", "byte", "sbyte", "word", "dword", "qword", "uint", "ushort", "ulong", "uchar", "longlong",
            "ulonglong", "undefined", "undefined1", "undefined2", "undefined3", "undefined4", "undefined5", "undefined6",
            "undefined7", "undefined8", "wchar_t", "code", "string", "pointer", "float10", "NULL"));

    static final long VOLATILE_READ = 0x10000001L;
    DecompInterface ifc;
    SymbolTable st;
    DataTypeManager dtm;
    Set<String> sfr = new HashSet<>();
    String paramsMode = "all";
    boolean dry = false;
    String debugFunc = null;
    PrintWriter log;
    Map<String, Integer> counts = new TreeMap<>();
    int failed = 0, decompFailed = 0;

    // ------------------------------------------------------------------ helpers
    static boolean isAuto(String n) { return AUTO.matcher(n).matches(); }

    HighFunction decompile(Function f) {
        DecompileResults r = ifc.decompileFunction(f, 60, monitor);
        if (r == null || !r.decompileCompleted() || r.getHighFunction() == null) { decompFailed++; return null; }
        return r.getHighFunction();
    }

    /** True if n would clash with a global name (label, function, namespace), a data type or a C/Ghidra keyword. */
    boolean globalClash(String n) {
        if (RESERVED.contains(n)) return true;
        SymbolIterator it = st.getSymbols(n);
        while (it.hasNext()) {
            SymbolType t = it.next().getSymbolType();
            if (t != SymbolType.PARAMETER && t != SymbolType.LOCAL_VAR) return true;
        }
        List<DataType> l = new ArrayList<>();
        dtm.findDataTypes(n, l);
        return !l.isEmpty();
    }

    String unique(String base, Set<String> used) {
        String n = base;
        for (int k = 2; used.contains(n) || globalClash(n); k++) n = base + "_" + k;
        return n;
    }

    /** Names in use in this function: decompiler symbols and database variables. */
    Set<String> usedNames(HighFunction hf) {
        Set<String> used = new HashSet<>();
        Iterator<HighSymbol> it = hf.getLocalSymbolMap().getSymbols();
        while (it.hasNext()) used.add(it.next().getName());
        for (Variable v : hf.getFunction().getAllVariables()) used.add(v.getName());
        return used;
    }

    static Function resolveThunk(Function c) {
        if (c != null && c.isThunk()) { Function t = c.getThunkedFunction(true); if (t != null) return t; }
        return c;
    }

    static boolean namedFunction(Function c) {
        return c != null && c.getSymbol().getSource() != SourceType.DEFAULT && !DEFAULT_FUNC.matcher(c.getName()).matches()
                && IDENT.matcher(c.getName()).matches();
    }

    /** The callee's return value is part of its locked prototype (as FunctionPrototype decides outputlock), so the
     *  value is a real return and not a register the decompiler guessed to be one. */
    static boolean outputLocked(Function c) {
        if (c.getSignatureSource() == SourceType.DEFAULT) return false;
        DataType rt = c.getReturnType();
        return rt != null && rt != DataType.DEFAULT && !(rt instanceof VoidDataType) && rt.getLength() > 0;
    }

    static Varnode stripCast(Varnode v) {
        PcodeOp d = v.getDef();
        if (d != null && (d.getOpcode() == PcodeOp.CAST || d.getOpcode() == PcodeOp.COPY)) return d.getInput(0);
        return v;
    }

    static boolean sameHigh(Varnode v, HighVariable h) { return v != null && v.getHigh() == h; }

    /** The defining ops of a variable that set its value (joins and self-copies left out); null if one is an INDIRECT. */
    static List<PcodeOp> realDefs(HighVariable h) {
        List<PcodeOp> defs = new ArrayList<>();
        Set<PcodeOp> seen = new HashSet<>();
        for (Varnode v : h.getInstances()) {
            PcodeOp d = v.getDef();
            if (d == null) { if (v.isInput()) defs.add(null); continue; }
            if (!seen.add(d)) continue;
            int oc = d.getOpcode();
            if (oc == PcodeOp.MULTIEQUAL) continue;
            if (oc == PcodeOp.INDIRECT) return null;
            if (oc == PcodeOp.COPY && sameHigh(d.getInput(0), h)) continue;
            defs.add(d);
        }
        return defs;
    }

    /** The address a read reads: a COPY of a memory varnode, a volatile read of one, or a LOAD through a constant pointer. */
    Address readAddress(PcodeOp d) {
        if (d.getOpcode() == PcodeOp.COPY) {
            Varnode in = d.getInput(0);
            if (in.isAddress() && in.getAddress().isMemoryAddress() && !in.getAddress().isStackAddress()) return in.getAddress();
            return null;
        }
        if (d.getOpcode() == PcodeOp.CALLOTHER) {
            // a read of volatile memory (peripheral registers): the decompiler's built-in user op read_volatile
            // (BUILTIN_VOLATILE_READ = 0x10000001 in the decompiler's userop.hh), whose second input marks the address read
            if (d.getNumInputs() != 2 || !d.getInput(0).isConstant() || d.getInput(0).getOffset() != VOLATILE_READ) return null;
            Varnode in = d.getInput(1);
            if (!in.isAddress() || !in.getAddress().isMemoryAddress() || in.getAddress().isStackAddress()) return null;
            return in.getAddress();
        }
        if (d.getOpcode() != PcodeOp.LOAD) return null;
        AddressSpace sp = currentProgram.getAddressFactory().getAddressSpace((int) d.getInput(0).getOffset());
        if (sp == null) return null;
        Varnode p = d.getInput(1);
        for (int depth = 0; depth < 3 && p != null; depth++) {
            if (p.isConstant()) return sp.getAddress(p.getOffset(), true);
            PcodeOp pd = p.getDef();
            if (pd == null) return null;
            if (pd.getOpcode() == PcodeOp.PTRSUB && pd.getInput(0).isConstant() && pd.getInput(0).getOffset() == 0
                    && pd.getInput(1).isConstant()) return sp.getAddress(pd.getInput(1).getOffset(), true);
            if (pd.getOpcode() != PcodeOp.CAST && pd.getOpcode() != PcodeOp.COPY) return null;
            p = pd.getInput(0);
        }
        return null;
    }

    static final Pattern DEFAULT_FIELD = Pattern.compile("^field\\d*_0x[0-9a-fA-F]+$");

    /** Rule c/d: the name of the whole datum read at a (size bytes), if it has a non-default name: a label on undefined
     *  bytes or on non-composite data of that size, or a whole primitive field of a labelled structure (as the decompiler
     *  prints it, g.field). Returns {name, rule}. */
    String[] globalName(Address a, int size) {
        Data dc = getDataContaining(a);
        if (dc != null && !dc.isDefined()) dc = null;
        if (dc == null || (dc.getAddress().equals(a) && !(base(dc.getDataType()) instanceof Composite)
                && !(base(dc.getDataType()) instanceof Array))) {
            if (dc != null && dc.getLength() != size) return null;
            Symbol s = st.getPrimarySymbol(a);
            if (!namedLabel(s)) return null;
            if (sfr.contains(s.getName())) return new String[] {s.getName().toLowerCase(Locale.ROOT), "c"};
            return new String[] {s.getName() + "_val", "d"};
        }
        if (!(base(dc.getDataType()) instanceof Structure)) return null;
        Symbol root = st.getPrimarySymbol(dc.getAddress());
        if (!namedLabel(root)) return null;
        Data prim = dc.getPrimitiveAt((int) a.subtract(dc.getAddress()));
        if (prim == null || !prim.getAddress().equals(a) || prim.getLength() != size) return null;
        StringBuilder name = new StringBuilder();
        for (Data x = prim; x != dc; x = x.getParent()) {
            String fn = x.getFieldName();
            if (fn == null || DEFAULT_FIELD.matcher(fn).matches() || !IDENT.matcher(fn).matches()
                    || !(base(x.getParent().getDataType()) instanceof Structure)) return null; // array elements: no
            name.insert(0, "_" + fn);
        }
        return new String[] {root.getName() + name + "_val", "d"};
    }

    static DataType base(DataType t) { return t instanceof TypeDef ? ((TypeDef) t).getBaseDataType() : t; }

    static boolean namedLabel(Symbol s) {
        return s != null && s.getSource() != SourceType.DEFAULT && s.getSymbolType() == SymbolType.LABEL
                && IDENT.matcher(s.getName()).matches();
    }

    /** Rule e: <callee>_ret when the value is a named function's return (possibly cast/extended, used only here). */
    String returnName(PcodeOp d) {
        int oc = d.getOpcode();
        if (oc == PcodeOp.CAST || oc == PcodeOp.INT_ZEXT || oc == PcodeOp.INT_SEXT || oc == PcodeOp.COPY) {
            Varnode in = d.getInput(0);
            PcodeOp cd = in.getDef();
            if (cd == null || cd.getOpcode() != PcodeOp.CALL) return null;
            Iterator<PcodeOp> u = in.getDescendants();
            int n = 0;
            while (u.hasNext()) { u.next(); n++; }
            if (n != 1) return null;
            d = cd;
        }
        if (d.getOpcode() != PcodeOp.CALL) return null;
        Function c = resolveThunk(getFunctionAt(d.getInput(0).getAddress()));
        if (!namedFunction(c) || !outputLocked(c)) return null;
        return c.getName() + "_ret";
    }

    /** Rule f: p_<struct> for a pointer to a named structure/union. */
    static String structName(DataType t) {
        if (t instanceof TypeDef) t = ((TypeDef) t).getBaseDataType();
        if (!(t instanceof Pointer)) return null;
        DataType s = ((Pointer) t).getDataType();
        if (s == null) return null;
        String sn = s.getName();
        if (s instanceof TypeDef) s = ((TypeDef) s).getBaseDataType();
        if (!(s instanceof Structure || s instanceof Union)) return null;
        if (AUTO_STRUCT.matcher(sn).matches() || !IDENT.matcher(sn).matches()) return null;
        return "p_" + sn;
    }

    static boolean isOne(Varnode c, int size) {
        if (!c.isConstant()) return false;
        long mask = size >= 8 ? -1L : (1L << (8 * size)) - 1;
        long v = c.getOffset() & mask;
        return v == 1 || v == mask;
    }

    /** Rule g: the op that sets the counter's start value, or null if h is not a simple loop counter. */
    static PcodeOp loopInit(HighVariable h, List<PcodeOp> defs) {
        if (defs == null || defs.size() != 2) return null;
        DataType t = h.getDataType();
        if (t instanceof TypeDef) t = ((TypeDef) t).getBaseDataType();
        if (!(t instanceof AbstractIntegerDataType) && !Undefined.isUndefined(t)) return null;
        PcodeOp init = null, step = null;
        for (PcodeOp d : defs) {
            if (d == null) return null;
            if (d.getOpcode() == PcodeOp.COPY && d.getInput(0).isConstant()) init = d;
            else if ((d.getOpcode() == PcodeOp.INT_ADD || d.getOpcode() == PcodeOp.INT_SUB)
                    && ((sameHigh(d.getInput(0), h) && isOne(d.getInput(1), h.getSize()))
                        || (d.getOpcode() == PcodeOp.INT_ADD && sameHigh(d.getInput(1), h) && isOne(d.getInput(0), h.getSize()))))
                step = d;
        }
        if (init == null || step == null) return null;
        boolean join = false, cond = false;
        for (Varnode v : h.getInstances()) {
            PcodeOp d = v.getDef();
            if (d != null && d.getOpcode() == PcodeOp.MULTIEQUAL) join = true;
            Iterator<PcodeOp> it = v.getDescendants();
            while (it.hasNext()) {
                PcodeOp u = it.next();
                int oc = u.getOpcode();
                if (oc != PcodeOp.INT_LESS && oc != PcodeOp.INT_SLESS && oc != PcodeOp.INT_LESSEQUAL
                        && oc != PcodeOp.INT_SLESSEQUAL && oc != PcodeOp.INT_EQUAL && oc != PcodeOp.INT_NOTEQUAL) continue;
                Varnode out = u.getOutput();
                for (int k = 0; k < 2 && out != null && !cond; k++) {
                    Iterator<PcodeOp> ui = out.getDescendants();
                    Varnode next = null;
                    while (ui.hasNext()) {
                        PcodeOp w = ui.next();
                        if (w.getOpcode() == PcodeOp.CBRANCH) cond = true;
                        else if (w.getOpcode() == PcodeOp.BOOL_NEGATE) next = w.getOutput();
                    }
                    out = next;
                }
            }
        }
        return join && cond ? init : null;
    }

    static int storageOrder(HighSymbol a, HighSymbol b) {
        int c = a.getStorage().compareTo(b.getStorage());
        if (c != 0) return c;
        Address pa = a.getPCAddress(), pb = b.getPCAddress();
        if (pa != null && pb != null && (c = pa.compareTo(pb)) != 0) return c;
        if (pa == null && pb != null) return -1;
        if (pb == null && pa != null) return 1;
        return a.getName().compareTo(b.getName());
    }

    void logRename(Function f, String old, String nu, String rule) {
        counts.merge(rule, 1, Integer::sum);
        if (log != null) log.println(f.getName() + "\t" + f.getEntryPoint() + "\t" + old + "\t" + nu + "\t" + rule);
    }

    boolean commit(HighSymbol s, String name) {
        if (dry) return true;
        try {
            HighFunctionDBUtil.updateDBVariable(s, name, null, SourceType.ANALYSIS);
            return true;
        } catch (Exception e) {
            failed++;
            printerr("NameVariables: " + s.getHighFunction().getFunction().getName() + " " + s.getName() + " -> " + name
                    + ": " + e.getMessage());
            return false;
        }
    }

    // ------------------------------------------------------------------ parameter facts (rule b)
    static final class Param {
        Function f;
        int slot;
        List<long[]> targets = new ArrayList<>(); // {callee entry offset, callee slot}
        String structName;
        boolean decided;
        String name; // final name (null = keep default)
        String rule; // b or f
    }
    Map<String, Param> params = new TreeMap<>();

    static String key(Function f, int slot) { return f.getEntryPoint().toString() + "#" + slot; }

    /** The name of callee parameter (entry, slot): its database name, or the one this run gives it; "?" while pending. */
    String calleeName(long entry, int slot) {
        Function c = getFunctionAt(toAddr(entry));
        if (c == null || slot >= c.getParameterCount()) return null;
        Parameter p = c.getParameter(slot);
        if (!isAuto(p.getName()) && IDENT.matcher(p.getName()).matches()) return p.getName();
        Param q = params.get(key(c, slot));
        if (q == null) return null;
        return q.decided ? q.name : "?";
    }

    void collectParams(HighFunction hf) {
        Function f = hf.getFunction();
        LocalSymbolMap lsm = hf.getLocalSymbolMap();
        for (int i = 0; i < lsm.getNumParams(); i++) {
            HighSymbol s = lsm.getParamSymbol(i);
            if (s == null || !isAuto(s.getName()) || NEVER.matcher(s.getName()).matches()) continue;
            if (paramsMode.equals("locked") && !(i < f.getParameterCount() && f.getSignatureSource() != SourceType.DEFAULT))
                continue;
            HighVariable h = s.getHighVariable();
            Param p = new Param();
            p.f = f;
            p.slot = s.getCategoryIndex();
            p.structName = structName(s.getDataType());
            List<PcodeOp> defs = h == null ? null : realDefs(h);
            boolean unchanged = defs != null && defs.size() == 1 && defs.get(0) == null;
            if (unchanged) {
                Set<String> seen = new TreeSet<>();
                Iterator<PcodeOpAST> ops = hf.getPcodeOps();
                while (ops.hasNext()) {
                    PcodeOpAST op = ops.next();
                    if (op.getOpcode() != PcodeOp.CALL) continue;
                    Function c = resolveThunk(getFunctionAt(op.getInput(0).getAddress()));
                    if (c == null || c.getSignatureSource() == SourceType.DEFAULT) continue;
                    if (op.getNumInputs() - 1 != c.getParameterCount()) continue;
                    for (int k = 1; k < op.getNumInputs(); k++) {
                        Varnode a = op.getInput(k);
                        if (sameHigh(a, h) || sameHigh(stripCast(a), h)) {
                            if (seen.add(c.getEntryPoint().getOffset() + "#" + (k - 1)))
                                p.targets.add(new long[] {c.getEntryPoint().getOffset(), k - 1});
                        }
                    }
                }
            }
            if (!p.targets.isEmpty() || p.structName != null) params.put(key(f, p.slot), p);
        }
    }

    void solveParams() {
        boolean changed = true;
        while (changed) {
            changed = false;
            for (Param p : params.values()) {
                if (p.decided) continue;
                Set<String> names = new TreeSet<>();
                boolean pending = false;
                for (long[] t : p.targets) {
                    String n = calleeName(t[0], (int) t[1]);
                    if ("?".equals(n)) {
                        if (t[0] == p.f.getEntryPoint().getOffset() && t[1] == p.slot) continue; // passes itself on
                        pending = true;
                    } else if (n != null) names.add(n);
                }
                if (pending) continue;
                p.decided = true;
                changed = true;
                if (names.size() == 1) { p.name = names.iterator().next(); p.rule = "b"; }
                else if (names.isEmpty() && p.structName != null) { p.name = p.structName; p.rule = "f"; }
            }
        }
        // still pending: a cycle through recursion; keep the default names (no rule can decide them)
        for (Param p : params.values()) if (!p.decided) { p.decided = true; p.name = null; }
    }

    // ------------------------------------------------------------------ main
    @Override
    protected void run() throws Exception {
        String logPath = null;
        for (String a : getScriptArgs()) {
            if (a.startsWith("log=")) logPath = a.substring(4);
            else if (a.startsWith("sfr=")) {
                for (String ln : Files.readAllLines(Paths.get(a.substring(4)))) {
                    if (ln.isBlank() || ln.startsWith("#")) continue;
                    String[] p = ln.split("\t");
                    if (p.length > 1) sfr.add(p[1]);
                }
            } else if (a.startsWith("params=")) paramsMode = a.substring(7);
            else if (a.equals("dry")) dry = true;
            else if (a.startsWith("debug=")) debugFunc = a.substring(6);
            else throw new IllegalArgumentException("unknown argument " + a);
        }
        if (!Set.of("all", "locked", "none").contains(paramsMode)) throw new IllegalArgumentException("params=" + paramsMode);
        st = currentProgram.getSymbolTable();
        dtm = currentProgram.getDataTypeManager();
        if (logPath != null) {
            if (Paths.get(logPath).getParent() != null) Files.createDirectories(Paths.get(logPath).getParent());
            log = new PrintWriter(logPath, "UTF-8");
            log.println("function\tentry\told\tnew\trule");
        }
        ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.toggleCCode(false);
        ifc.openProgram(currentProgram);

        List<Function> funcs = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            if (!f.isExternal() && !f.isThunk()) funcs.add(f);
        monitor.initialize(funcs.size() * 2L);

        // Pass 1: locals (rules c-g), committed at once; parameter facts for rule b.
        for (Function f : funcs) {
            monitor.checkCancelled();
            monitor.incrementProgress(1);
            HighFunction hf = decompile(f);
            if (hf == null) continue;
            if (!paramsMode.equals("none")) collectParams(hf);
            Set<String> used = usedNames(hf);
            List<HighSymbol> locals = new ArrayList<>();
            Iterator<HighSymbol> it = hf.getLocalSymbolMap().getSymbols();
            while (it.hasNext()) {
                HighSymbol s = it.next();
                if (s.isParameter() || s.isGlobal() || !isAuto(s.getName()) || NEVER.matcher(s.getName()).matches()) continue;
                if (s.getHighVariable() == null) continue;
                locals.add(s);
            }
            locals.sort(NameVariables::storageOrder);
            List<Object[]> counters = new ArrayList<>();
            for (HighSymbol s : locals) {
                HighVariable h = s.getHighVariable();
                List<PcodeOp> defs = realDefs(h);
                String base = null, rule = null;
                if (f.getName().equals(debugFunc)) {
                    StringBuilder db = new StringBuilder("NameVariables debug: " + s.getName() + " " + h.getDataType() + " defs:");
                    if (defs != null) for (PcodeOp d : defs) {
                        db.append(' ').append(d == null ? "input" : d.toString());
                        if (d != null) { Address ra = readAddress(d); db.append(" read=").append(ra);
                            if (ra != null) { Symbol sy = st.getPrimarySymbol(ra); Data da = getDataAt(ra);
                                db.append(" sym=").append(sy == null ? null : sy.getName() + "/" + sy.getSource()).append(" data=").append(da == null ? null : da.getDataType().getName() + "/" + da.getLength()); } }
                    }
                    println(db.toString());
                }
                if (defs != null && defs.size() == 1 && defs.get(0) != null) {
                    PcodeOp d = defs.get(0);
                    Address a = readAddress(d);
                    if (a != null) {
                        String[] g = globalName(a, h.getSize());
                        if (g != null) { base = g[0]; rule = g[1]; }
                    }
                    if (base == null && (base = returnName(d)) != null) rule = "e";
                }
                if (base == null && (base = structName(h.getDataType())) != null) rule = "f";
                if (base == null) {
                    PcodeOp init = loopInit(h, defs);
                    if (init != null) counters.add(new Object[] {init.getSeqnum(), s});
                    continue;
                }
                String n = unique(base, used);
                if (commit(s, n)) { used.add(n); logRename(f, s.getName(), n, rule); }
            }
            counters.sort((x, y) -> ((SequenceNumber) x[0]).compareTo((SequenceNumber) y[0]));
            String[] ijk = {"i", "j", "k"};
            for (int k = 0; k < counters.size() && k < ijk.length; k++) {
                HighSymbol s = (HighSymbol) counters.get(k)[1];
                String n = unique(ijk[k], used);
                if (commit(s, n)) { used.add(n); logRename(f, s.getName(), n, "g"); }
            }
        }

        // Rule b over the call graph, then f for the parameters b leaves default; commit per function.
        if (!paramsMode.equals("none")) {
            solveParams();
            Map<Function, List<Param>> byFunc = new TreeMap<>(Comparator.comparing(Function::getEntryPoint));
            for (Param p : params.values()) if (p.name != null) byFunc.computeIfAbsent(p.f, x -> new ArrayList<>()).add(p);
            for (Map.Entry<Function, List<Param>> e : byFunc.entrySet()) {
                monitor.checkCancelled();
                Function f = e.getKey();
                HighFunction hf = decompile(f);
                if (hf == null) continue;
                LocalSymbolMap lsm = hf.getLocalSymbolMap();
                boolean full = lsm.getNumParams() != f.getParameterCount();
                for (int i = 0; !full && i < lsm.getNumParams(); i++) {
                    HighSymbol s = lsm.getParamSymbol(i);
                    full = s.getCategoryIndex() != i || s.getStorage().compareTo(f.getParameter(i).getVariableStorage()) != 0;
                }
                if (full) {
                    if (!paramsMode.equals("all")) continue;
                    if (!dry) {
                        try {
                            HighFunctionDBUtil.commitParamsToDatabase(hf, false, ReturnCommitOption.NO_COMMIT,
                                    f.getSignatureSource());
                        } catch (Exception ex) {
                            failed++;
                            printerr("NameVariables: " + f.getName() + ": parameter commit failed: " + ex.getMessage());
                            continue;
                        }
                    }
                }
                Set<String> used = usedNames(hf);
                e.getValue().sort(Comparator.comparingInt(p -> p.slot));
                for (Param p : e.getValue()) {
                    HighSymbol s = null;
                    for (int i = 0; i < lsm.getNumParams(); i++)
                        if (lsm.getParamSymbol(i).getCategoryIndex() == p.slot) s = lsm.getParamSymbol(i);
                    if (s == null || !isAuto(s.getName())) continue;
                    String n = unique(p.name, used);
                    if (commit(s, n)) { used.add(n); logRename(f, s.getName(), n, p.rule); }
                }
            }
        }
        ifc.dispose();
        if (log != null) log.close();
        StringBuilder sb = new StringBuilder();
        int total = 0;
        for (Map.Entry<String, Integer> e : counts.entrySet()) { sb.append(' ').append(e.getKey()).append('=').append(e.getValue()); total += e.getValue(); }
        println("NameVariables: " + total + " renamed (" + sb.toString().trim() + "), " + failed + " failed, " + decompFailed
                + " decompile failures, params=" + paramsMode + (dry ? " (dry run)" : "") + (logPath != null ? " -> " + logPath : ""));
    }
}
