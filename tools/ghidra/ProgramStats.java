// Print coverage statistics for a program: functions, instruction bytes, defined data,
// and the largest undefined (non-0xFF) gaps inside the executable ROM block.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript ProgramStats.java [out.txt]
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Data;
import ghidra.program.model.mem.MemoryBlock;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ProgramStats extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        PrintWriter out = args.length > 0 ? new PrintWriter(args[0], "UTF-8") : new PrintWriter(System.out);
        int funcs = currentProgram.getFunctionManager().getFunctionCount();
        long insBytes = 0, insCount = 0;
        for (Instruction i : currentProgram.getListing().getInstructions(true)) {
            insBytes += i.getLength();
            insCount++;
        }
        long dataBytes = 0;
        for (Data d : currentProgram.getListing().getDefinedData(true)) {
            dataBytes += d.getLength();
        }
        out.println("functions " + funcs + ", instructions " + insCount + " (" + insBytes + " bytes), defined data "
                + dataBytes + " bytes");
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            out.println(String.format("block %-16s %s..%s init=%s rwx=%s%s%s vol=%s", b.getName(), b.getStart(),
                    b.getEnd(), b.isInitialized(), b.isRead() ? "r" : "-", b.isWrite() ? "w" : "-",
                    b.isExecute() ? "x" : "-", b.isVolatile()));
        }
        MemoryBlock rom = currentProgram.getMemory().getBlock("ROM");
        if (rom != null) {
            AddressSet und = new AddressSet(rom.getStart(), rom.getEnd());
            for (Instruction i : currentProgram.getListing().getInstructions(rom.getStart(), true)) {
                und.delete(i.getMinAddress(), i.getMaxAddress());
            }
            for (Data d : currentProgram.getListing().getDefinedData(rom.getStart(), true)) {
                und.delete(d.getMinAddress(), d.getMaxAddress());
            }
            List<AddressRange> gaps = new ArrayList<>();
            long nonff = 0;
            for (AddressRange r : und) {
                byte[] buf = new byte[(int) r.getLength()];
                currentProgram.getMemory().getBytes(r.getMinAddress(), buf);
                int c = 0;
                for (byte x : buf) if (x != (byte) 0xFF) c++;
                nonff += c;
                if (c > 64) gaps.add(r);
            }
            out.println("ROM undefined non-0xFF bytes: " + nonff);
            gaps.sort((x, y) -> Long.compare(y.getLength(), x.getLength()));
            for (int k = 0; k < Math.min(40, gaps.size()); k++) {
                out.println("gap " + gaps.get(k).getMinAddress() + " len " + gaps.get(k).getLength());
            }
        }
        out.flush();
        if (args.length > 0) out.close();
    }
}
