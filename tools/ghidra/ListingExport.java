// Export every instruction of the program (and the undefined holes inside function bodies) as TSV, for comparison
// with a reference disassembler (tools/rx_compare.py, T21c).
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript ListingExport.java <out.tsv>
// Columns: addr  len  bytes(hex)  mnemonic  operands  function-entry ("-" when outside every function)
// Holes: lines "addr  len  bytes  ?UNDEF  -  entry" for bytes inside a function body that are not an instruction
//        (data or not disassembled). Operands are the comma-joined default operand representations,
//        exactly as the listing prints them.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

import java.io.PrintWriter;

public class ListingExport extends GhidraScript {
    private static String hex(byte[] b) {
        StringBuilder sb = new StringBuilder();
        for (byte x : b) sb.append(String.format("%02x", x & 0xff));
        return sb.toString();
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        var listing = currentProgram.getListing();
        var fm = currentProgram.getFunctionManager();
        AddressSet bodies = new AddressSet();
        long nIns = 0, nHole = 0;
        try (PrintWriter out = new PrintWriter(args[0], "UTF-8")) {
            InstructionIterator it = listing.getInstructions(true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                Function f = fm.getFunctionContaining(ins.getAddress());
                StringBuilder ops = new StringBuilder();
                for (int i = 0; i < ins.getNumOperands(); i++) {
                    if (i > 0) ops.append(',');
                    ops.append(ins.getDefaultOperandRepresentation(i));
                }
                out.printf("%08x\t%d\t%s\t%s\t%s\t%s%n", ins.getAddress().getOffset(), ins.getLength(),
                        hex(ins.getBytes()), ins.getMnemonicString(), ops,
                        f == null ? "-" : String.format("%08x", f.getEntryPoint().getOffset()));
                nIns++;
            }
            for (Function f : fm.getFunctions(true)) {
                if (f.isThunk() || f.isExternal()) continue;
                AddressSet holes = new AddressSet(f.getBody());
                for (AddressRange r : f.getBody()) {
                    Address a = r.getMinAddress();
                    while (a != null && a.compareTo(r.getMaxAddress()) <= 0) {
                        Instruction ins = listing.getInstructionContaining(a);
                        if (ins != null) {
                            holes.delete(ins.getMinAddress(), ins.getMaxAddress());
                            a = ins.getMaxAddress().next();
                        } else {
                            a = a.next();
                        }
                    }
                }
                for (AddressRange r : holes) {
                    byte[] b = getBytes(r.getMinAddress(), (int) r.getLength());
                    out.printf("%08x\t%d\t%s\t?UNDEF\t-\t%08x%n", r.getMinAddress().getOffset(), r.getLength(), hex(b),
                            f.getEntryPoint().getOffset());
                    nHole++;
                }
            }
        }
        println("ListingExport: " + nIns + " instructions, " + nHole + " holes in function bodies -> " + args[0]);
    }
}
