// Export decompiled C for every function into small files, plus a TSV index.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis \
//     -scriptPath tools/ghidra -postScript ExportDecomp.java decomp/<image> [funcsPerFile]
// Output: <outdir>/<addrStart>_<addrEnd>.c (default 50 functions each) and
//         <outdir>/functions.tsv (entry, name, size, callers, file).
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ExportDecomp extends GhidraScript {
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
            if (f.getName().endsWith(".c") || f.getName().equals("functions.tsv")) {
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
                            out.print(r.getDecompiledFunction().getC());
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
        println("ExportDecomp: " + funcs.size() + " functions, " + failed + " failed -> " + outDir);
    }
}
