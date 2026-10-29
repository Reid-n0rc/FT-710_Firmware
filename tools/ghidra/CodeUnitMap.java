// Write the code/data/undefined map of one address range as TSV runs (T22b, #104): for comparing Ghidra's
// coverage with an independent recovery (tools/arm_recover_compare.py).
// Headless usage (read only):
//   tools/ghidra-headless.sh <projdir> <proj> -process <prog> -noanalysis -readOnly -scriptPath tools/ghidra \
//     -postScript CodeUnitMap.java <out.tsv> [start end]      (default 0x20100000 0x20165178, DISPLAY .text)
// Columns: start  end(exclusive)  kind  detail  function (entry of the containing function, '-' if none)
//   kind = code_a32 | code_t32 (ARM TMode context) | code (other languages) | data (detail = data type) | undefined
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Instruction;

import java.io.PrintWriter;
import java.math.BigInteger;

public class CodeUnitMap extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        long s = args.length > 1 ? Long.decode(args[1]) : 0x20100000L;
        long e = args.length > 2 ? Long.decode(args[2]) : 0x20165178L;
        var listing = currentProgram.getListing();
        Register tmode = currentProgram.getRegister("TMode");
        long runS = -1, runE = -1;
        String runK = null, runD = null, runF = null;
        var fm = currentProgram.getFunctionManager();
        try (PrintWriter out = new PrintWriter(args[0], "UTF-8")) {
            out.println("start\tend\tkind\tdetail\tfunction");
            var it = listing.getCodeUnits(toAddr(s), true);
            while (it.hasNext()) {
                CodeUnit cu = it.next();
                long a = cu.getAddress().getOffset();
                if (a >= e) break;
                long b = cu.getMaxAddress().getOffset() + 1;
                String k, d = "";
                if (cu instanceof Instruction) {
                    Instruction ins = (Instruction) cu;
                    k = "code";
                    if (tmode != null) {
                        BigInteger v = ins.getValue(tmode, false);
                        k = (v != null && v.signum() != 0) ? "code_t32" : "code_a32";
                    }
                } else {
                    Data dd = (Data) cu;
                    if (dd.isDefined()) { k = "data"; d = dd.getDataType().getName(); }
                    else k = "undefined";
                }
                var fn = fm.getFunctionContaining(cu.getAddress());
                String f = fn == null ? "-" : String.format("%08x", fn.getEntryPoint().getOffset());
                boolean merge = k.equals(runK) && a == runE && f.equals(runF) && (k.startsWith("code") || k.equals("undefined"));
                if (merge) { runE = b; continue; }
                if (runK != null) out.printf("%08x\t%08x\t%s\t%s\t%s%n", runS, runE, runK, runD, runF);
                runS = a; runE = b; runK = k; runD = d; runF = f;
            }
            if (runK != null) out.printf("%08x\t%08x\t%s\t%s\t%s%n", runS, runE, runK, runD, runF);
        }
    }
}
