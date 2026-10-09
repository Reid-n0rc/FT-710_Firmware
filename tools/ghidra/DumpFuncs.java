// Decompile the functions containing the given addresses (or named functions) into one text file.
// Handy for inspecting a few functions without a full export.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript DumpFuncs.java <outfile> <addr|name> [...]
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

import java.io.File;
import java.io.PrintWriter;

public class DumpFuncs extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);
        try (PrintWriter out = new PrintWriter(new File(args[0]), "UTF-8")) {
            for (int i = 1; i < args.length; i++) {
                Function f = null;
                Address ad = null;
                try { ad = toAddr(args[i]); } catch (Exception e) { ad = null; }
                if (ad != null) f = getFunctionContaining(ad);
                if (f == null) {
                    for (Function g : currentProgram.getFunctionManager().getFunctions(true)) {
                        if (g.getName().equals(args[i])) { f = g; break; }
                    }
                }
                if (f == null) { out.println("// no function at " + args[i]); continue; }
                out.println("// ===== " + f.getName() + " @ " + f.getEntryPoint());
                DecompileResults r = ifc.decompileFunction(f, 60, monitor);
                out.println(r != null && r.decompileCompleted()
                        ? r.getDecompiledFunction().getC() : "// decompile failed");
            }
        }
        ifc.dispose();
    }
}
