// Count (and list) MOVU.B/MOVU.W Rs,Rd instructions (opcode bytes 0x5B/0x5F, ld=11 = register source).
// The community RX SLEIGH module decodes these as memory loads [Rs], which the decompiler then shows
// as bogus pointer dereferences. Output: one line per instruction (address, function, text) + a total.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript T10eMovuRegCount.java <out.txt>
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;

import java.io.PrintWriter;

public class T10eMovuRegCount extends GhidraScript {
    @Override
    protected void run() throws Exception {
        int n = 0;
        try (PrintWriter w = new PrintWriter(getScriptArgs()[0])) {
            for (Instruction ins : currentProgram.getListing().getInstructions(true)) {
                byte[] b = ins.getBytes();
                if (b.length == 2 && ((b[0] & 0xFF) == 0x5B || (b[0] & 0xFF) == 0x5F)
                        && ins.getMnemonicString().toUpperCase().startsWith("MOVU")) {
                    Function f = getFunctionContaining(ins.getAddress());
                    w.printf("%s\t%s\t%s%n", ins.getAddress(), f == null ? "-" : f.getName(), ins);
                    n++;
                }
            }
            w.printf("total\t%d%n", n);
        }
    }
}
