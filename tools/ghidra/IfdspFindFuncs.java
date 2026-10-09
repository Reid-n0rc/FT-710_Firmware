// Post-analysis pass for the IFDSP Cortex-M33 program: finds Thumb functions that auto-analysis missed
// (code only reached through function-pointer tables) by disassembling `push {..., lr}` prologues in
// undefined bytes of the known code ranges, then re-runs analysis. Also defines the ASCII strings in the SRAM rodata tail. Repeats until nothing new is found.
// Headless usage: see IfdspM33Setup.java (run as -postScript IfdspFindFuncs.java).
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;

import java.math.BigInteger;

public class IfdspFindFuncs extends GhidraScript {
    // [start, end) of M33 code: flash startup code, and the .ramfunc copy in SRAM (strings begin at 0x87B4C).
    static final long[][] RANGES = {{0x080011A8L, 0x08001830L}, {0x00080000L, 0x00087B4CL}};

    @Override
    protected void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        Listing listing = currentProgram.getListing();
        Register tmode = currentProgram.getRegister("TMode");
        // Define the NUL-terminated ASCII strings in the SRAM rodata tail (0x87B4C..0x87EBC).
        int strs = 0;
        for (long p = 0x00087B4CL; p < 0x00087EBCL; ) {
            Address ad = toAddr(p);
            int len = 0;
            while (p + len < 0x00087EBCL) {
                int c = mem.getByte(ad.add(len)) & 0xFF;
                if (c == 0 || !(c == 9 || c == 10 || c == 13 || (c >= 0x20 && c < 0x7F))) break;
                len++;
            }
            boolean nul = p + len < 0x00087EBCL && mem.getByte(ad.add(len)) == 0;
            if (len >= 3 && nul && listing.getInstructionContaining(ad) == null) {
                // Auto-analysis leaves these as small undefined/pointer data items; replace them.
                clearListing(ad, ad.add(len));
                try { createAsciiString(ad); strs++; } catch (Exception e) { /* overlaps */ }
            }
            p += Math.max(1, len + (nul ? 1 : 0));
        }
        println("IfdspFindFuncs: " + strs + " strings defined");
        int total = 0;
        for (int pass = 0; pass < 8; pass++) {
            int found = 0;
            for (long[] r : RANGES) {
                for (long p = r[0]; p < r[1] - 4; p += 2) {
                    Address ad = toAddr(p);
                    if (listing.getCodeUnitContaining(ad) != null
                            && listing.getInstructionContaining(ad) != null) continue;
                    if (listing.getDefinedDataContaining(ad) != null) continue;
                    int h0 = mem.getShort(ad) & 0xFFFF;
                    int h1 = mem.getShort(ad.add(2)) & 0xFFFF;
                    boolean push16 = (h0 & 0xFF00) == 0xB500;               // push {..., lr}
                    boolean push32 = h0 == 0xE92D && (h1 & 0x4000) != 0;     // stmdb sp!, {..., lr}
                    if (!push16 && !push32) continue;
                    if (tmode != null) {
                        currentProgram.getProgramContext().setValue(tmode, ad, ad, BigInteger.ONE);
                    }
                    if (!disassemble(ad)) continue;
                    if (getFunctionAt(ad) == null && createFunction(ad, null) != null) found++;
                }
            }
            total += found;
            println("IfdspFindFuncs pass " + pass + ": " + found + " new functions");
            if (found == 0) break;
            analyzeChanges(currentProgram);
        }
        println("IfdspFindFuncs: " + total + " functions added, "
                + currentProgram.getFunctionManager().getFunctionCount() + " total");
    }
}
