// Writes one row per function: entry address, name, body size in bytes, instruction set (arm or thumb, from the TMode
// context register at the entry). Read-only. T24 (DISPLAY): tools/equiv_display_emu.py needs the instruction set of the
// original function to enter it, because armcc mixes ARM and Thumb code in the DISPLAY image.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript ExportFuncModes.java src/display/modes.tsv
// @category FT710
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;

public class ExportFuncModes extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String out = getScriptArgs()[0];
        Register tmode = currentProgram.getProgramContext().getRegister("TMode");
        int n = 0, thumb = 0;
        try (PrintWriter w = new PrintWriter(out, "UTF-8")) {
            w.println("# Instruction set of every function of the DISPLAY image (Ghidra TMode at the entry), written by");
            w.println("# tools/ghidra/ExportFuncModes.java; read by tools/equiv_display_emu.py (T24). Do not edit.");
            w.println("entry\tname\tsize\tmode");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (f.isExternal() || f.isThunk() && f.getBody().getNumAddresses() == 0) continue;
                boolean t = false;
                if (tmode != null) {
                    java.math.BigInteger v = currentProgram.getProgramContext().getValue(tmode, f.getEntryPoint(), false);
                    t = v != null && v.signum() != 0;
                }
                w.printf("%08x\t%s\t%d\t%s%n", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses(),
                         t ? "thumb" : "arm");
                n++;
                if (t) thumb++;
            }
        }
        println("ExportFuncModes: " + n + " functions, " + thumb + " thumb");
    }
}
