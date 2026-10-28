// Export decompiled C for every function into small files, plus a TSV index and decompile-quality counts.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis \
//     -scriptPath tools/ghidra -postScript ExportDecomp.java decomp/<image> [funcsPerFile]
// Output: <outdir>/<addrStart>_<addrEnd>.c (default 50 functions each),
//         <outdir>/functions.tsv (entry, name, size, callers, file) and
//         <outdir>/quality.tsv (metric, value; T21f/#97 B11). The quality counts come from the same decompile pass;
//         tools/decomp_quality.py compares two of them (tools/bootstrap.sh verify) and renders them into INDEX.md.
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Bookmark;
import ghidra.program.model.listing.BookmarkType;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ExportDecomp extends GhidraScript {
    private static final Pattern WARNING = Pattern.compile("WARNING: (.*?)(?:\\*/|$)", Pattern.MULTILINE);
    private static final Pattern HALT_BADDATA = Pattern.compile("\\bhalt_baddata\\(");
    private static final Pattern IN_VAR = Pattern.compile("\\bin_[A-Za-z0-9_]+");
    private static final Pattern UNAFF_VAR = Pattern.compile("\\bunaff_[A-Za-z0-9_]+");
    private static final Pattern EXTRAOUT_VAR = Pattern.compile("\\bextraout_[A-Za-z0-9_]+");

    private static int count(Pattern p, String s) {
        int n = 0;
        for (Matcher m = p.matcher(s); m.find();) n++;
        return n;
    }

    /** Warning text without addresses and numbers, so that one kind is one key. */
    private static String warningKind(String w) {
        return w.trim().replaceAll("\\((?:ram|rom|code|register|stack|unique|const)[^)]*\\)", "(#)")
                .replaceAll("0x[0-9A-Fa-f]+", "#").replaceAll("\\b[0-9]+\\b", "#")
                .replaceAll("[\\t\\r\\n]", " ").replaceAll(" +", " ");
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            printerr("usage: ExportDecomp.java <outdir> [funcsPerFile]");
            return;
        }
        File outDir = new File(args[0]);
        int perFile = args.length > 1 ? Integer.parseInt(args[1]) : 50;
        outDir.mkdirs();
        for (File f : outDir.listFiles()) {
            if (f.getName().endsWith(".c") || f.getName().equals("functions.tsv") || f.getName().equals("quality.tsv")) {
                f.delete();
            }
        }

        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);

        List<Function> funcs = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (!f.isExternal() && !f.isThunk()) {
                funcs.add(f);
            }
        }
        monitor.initialize(funcs.size());
        int failed = 0;
        long warnings = 0, haltBaddata = 0;
        int fWarn = 0, fHalt = 0, fIn = 0, fUnaff = 0, fExtraout = 0, fAnyVar = 0;
        Map<String, Long> kinds = new TreeMap<>();
        try (PrintWriter index = new PrintWriter(new File(outDir, "functions.tsv"), "UTF-8")) {
            index.println("entry\tname\tsize\tcallers\tfile");
            for (int i = 0; i < funcs.size(); i += perFile) {
                List<Function> chunk = funcs.subList(i, Math.min(i + perFile, funcs.size()));
                String name = chunk.get(0).getEntryPoint().toString() + "_"
                        + chunk.get(chunk.size() - 1).getEntryPoint().toString() + ".c";
                try (PrintWriter out = new PrintWriter(new File(outDir, name), "UTF-8")) {
                    out.println("// " + currentProgram.getName() + " — Ghidra decompile, "
                            + chunk.size() + " functions");
                    for (Function f : chunk) {
                        monitor.checkCancelled();
                        monitor.incrementProgress(1);
                        out.println();
                        out.println("// ===== " + f.getName() + " @ " + f.getEntryPoint()
                                + " (" + f.getBody().getNumAddresses() + " bytes)");
                        DecompileResults r = ifc.decompileFunction(f, 60, monitor);
                        if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
                            String c = r.getDecompiledFunction().getC();
                            out.print(c);
                            int nw = 0;
                            for (Matcher m = WARNING.matcher(c); m.find();) {
                                kinds.merge(warningKind(m.group(1)), 1L, Long::sum);
                                nw++;
                            }
                            warnings += nw;
                            if (nw > 0) fWarn++;
                            int nh = count(HALT_BADDATA, c);
                            haltBaddata += nh;
                            if (nh > 0) fHalt++;
                            boolean a = IN_VAR.matcher(c).find(), b = UNAFF_VAR.matcher(c).find(),
                                    e = EXTRAOUT_VAR.matcher(c).find();
                            if (a) fIn++;
                            if (b) fUnaff++;
                            if (e) fExtraout++;
                            if (a || b || e) fAnyVar++;
                        } else {
                            failed++;
                            out.println("// decompile failed: "
                                    + (r == null ? "null" : r.getErrorMessage()));
                        }
                        index.println(f.getEntryPoint() + "\t" + f.getName() + "\t"
                                + f.getBody().getNumAddresses() + "\t"
                                + f.getSymbol().getReferenceCount() + "\t" + name);
                    }
                }
            }
        }
        ifc.dispose();

        // Listing-side counts: undefined non-0xFF bytes in initialized executable blocks, error bookmarks.
        Map<String, Long> undefByBlock = new LinkedHashMap<>();
        long undef = 0;
        for (MemoryBlock blk : currentProgram.getMemory().getBlocks()) {
            if (!blk.isInitialized() || !blk.isExecute()) continue;
            AddressSet und = new AddressSet(blk.getStart(), blk.getEnd());
            for (Instruction ins : currentProgram.getListing().getInstructions(blk.getStart(), true)) {
                if (ins.getMinAddress().compareTo(blk.getEnd()) > 0) break;
                und.delete(ins.getMinAddress(), ins.getMaxAddress());
            }
            for (Data d : currentProgram.getListing().getDefinedData(blk.getStart(), true)) {
                if (d.getMinAddress().compareTo(blk.getEnd()) > 0) break;
                und.delete(d.getMinAddress(), d.getMaxAddress());
            }
            long n = 0;
            for (AddressRange r : und) {
                byte[] buf = new byte[(int) r.getLength()];
                currentProgram.getMemory().getBytes(r.getMinAddress(), buf);
                for (byte x : buf) if (x != (byte) 0xFF) n++;
            }
            undefByBlock.put(blk.getName().replaceAll("\\s", "_"), n);
            undef += n;
        }
        long bmError = 0, bmBadIns = 0;
        Iterator<Bookmark> it = currentProgram.getBookmarkManager().getBookmarksIterator(BookmarkType.ERROR);
        while (it.hasNext()) {
            Bookmark bm = it.next();
            bmError++;
            if ("Bad Instruction".equals(bm.getCategory())) bmBadIns++;
        }

        try (PrintWriter q = new PrintWriter(new File(outDir, "quality.tsv"), "UTF-8")) {
            q.println("metric\tvalue");
            q.println("functions\t" + funcs.size());
            q.println("decompile_failures\t" + failed);
            q.println("warnings\t" + warnings);
            q.println("functions_with_warnings\t" + fWarn);
            q.println("spacebase_warnings\t" + kinds.getOrDefault("Unable to track spacebase fully for stack", 0L));
            q.println("unreachable_block_warnings\t" + kinds.getOrDefault("Removing unreachable block (#)", 0L));
            q.println("halt_baddata\t" + haltBaddata);
            q.println("functions_with_halt_baddata\t" + fHalt);
            q.println("functions_with_in_vars\t" + fIn);
            q.println("functions_with_unaff_vars\t" + fUnaff);
            q.println("functions_with_extraout_vars\t" + fExtraout);
            q.println("functions_with_in_unaff_extraout\t" + fAnyVar);
            q.println("undefined_nonff_bytes\t" + undef);
            for (Map.Entry<String, Long> e : undefByBlock.entrySet()) {
                q.println("undefined_nonff_bytes:" + e.getKey() + "\t" + e.getValue());
            }
            q.println("bookmarks_error\t" + bmError);
            q.println("bookmarks_bad_instruction\t" + bmBadIns);
            for (Map.Entry<String, Long> e : kinds.entrySet()) {
                q.println("warning:" + e.getKey() + "\t" + e.getValue());
            }
        }
        println("ExportDecomp: " + funcs.size() + " functions, " + failed + " failed, " + warnings + " warnings, "
                + haltBaddata + " halt_baddata, " + undef + " undefined non-0xFF bytes -> " + outDir);
    }
}
