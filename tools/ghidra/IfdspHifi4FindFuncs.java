// Post-analysis pass for the IFDSP HiFi4 (Xtensa) program: creates functions at every 4-byte-aligned
// `entry a1, N` instruction (windowed-ABI prologue; call4/8/12 targets are 4-aligned) in undefined bytes
// of the DSP SRAM image, then re-runs analysis. Repeats until nothing new is found. Finally removes functions whose entry lies
// in uninitialized memory (artifacts of mis-decoded HiFi4 FLIX bundles).
// Headless usage: see IfdspHifi4Setup.java (run as -postScript IfdspHifi4FindFuncs.java).
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;

public class IfdspHifi4FindFuncs extends GhidraScript {
    static final long START = 0x00200000L, END = 0x002383B4L; // DSP image 1 (sram_dsp)

    @Override
    protected void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        Listing listing = currentProgram.getListing();
        int total = 0;
        for (int pass = 0; pass < 8; pass++) {
            int found = 0;
            for (long p = START; p < END - 3; p += 4) {
                Address ad = toAddr(p);
                if (listing.getInstructionContaining(ad) != null) continue;
                if (listing.getDefinedDataContaining(ad) != null) continue;
                int b0 = mem.getByte(ad) & 0xFF, b1 = mem.getByte(ad.add(1)) & 0xFF;
                // ENTRY as, imm12: op0=6, n=3, m=0 -> byte0 0x36; as=a1 -> low nibble of byte1 = 1.
                if (b0 != 0x36 || (b1 & 0x0F) != 0x01) continue;
                if (!disassemble(ad)) continue;
                if (getFunctionAt(ad) == null && createFunction(ad, null) != null) found++;
            }
            total += found;
            println("IfdspHifi4FindFuncs pass " + pass + ": " + found + " new functions");
            if (found == 0) break;
            analyzeChanges(currentProgram);
        }
        // Mis-sized FLIX bundles make Ghidra follow bogus call targets into unloaded or data memory; drop those.
        int removed = 0;
        java.util.List<ghidra.program.model.listing.Function> junk = new java.util.ArrayList<>();
        for (ghidra.program.model.listing.Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            ghidra.program.model.mem.MemoryBlock b = mem.getBlock(f.getEntryPoint());
            if (b == null || !b.isInitialized() || !b.isExecute()) junk.add(f);
        }
        for (ghidra.program.model.listing.Function f : junk) {
            removeFunction(f);
            removed++;
        }
        println("IfdspHifi4FindFuncs: removed " + removed + " functions in unloaded memory");
        println("IfdspHifi4FindFuncs: " + total + " functions added, "
                + currentProgram.getFunctionManager().getFunctionCount() + " total");
    }
}
