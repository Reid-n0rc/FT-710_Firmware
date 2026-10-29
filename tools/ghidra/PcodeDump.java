// Print the raw p-code of the instruction at each given address (T22c: bundle-parallel semantics check).
// Headless usage:
//   tools/ghidra-headless.sh <projdir> <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript PcodeDump.java <out.txt> <hexaddr> ...
// Undisassembled addresses are disassembled in the read-only session (not saved).
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.PcodeOp;

import java.io.PrintWriter;

public class PcodeDump extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        try (PrintWriter out = new PrintWriter(args[0], "UTF-8")) {
            for (int i = 1; i < args.length; i++) {
                Address a = toAddr(Long.parseLong(args[i].replaceFirst("^0x", ""), 16));
                Instruction ins = getInstructionAt(a);
                if (ins == null) {
                    disassemble(a);
                    ins = getInstructionAt(a);
                }
                if (ins == null) {
                    out.println("== " + a + " (no instruction)");
                    continue;
                }
                out.println("== " + a + " len " + ins.getLength() + "  " + ins);
                for (PcodeOp op : ins.getPcode()) {
                    out.println("   " + op);
                }
            }
        }
    }
}
