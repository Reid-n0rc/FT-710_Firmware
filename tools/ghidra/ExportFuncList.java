// Write every function of the current program as TSV: entry (8 hex digits), name, body size in bytes, block name.
// Used by tools/flix_oracle.sh to compare the HiFi4 function list with flix.dis (issue #97, B10).
// Headless: -postScript ExportFuncList.java <out.tsv>
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;

import java.io.PrintWriter;

public class ExportFuncList extends GhidraScript {
    @Override
    protected void run() throws Exception {
        int n = 0;
        try (PrintWriter out = new PrintWriter(getScriptArgs()[0], "UTF-8")) {
            out.println("entry\tname\tsize\tblock");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                MemoryBlock b = currentProgram.getMemory().getBlock(f.getEntryPoint());
                out.println(String.format("%08x\t%s\t%d\t%s", f.getEntryPoint().getOffset(), f.getName(),
                        f.getBody().getNumAddresses(), b == null ? "" : b.getName()));
                n++;
            }
        }
        println("ExportFuncList: " + n + " functions");
    }
}
