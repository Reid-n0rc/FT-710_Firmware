// Second code-discovery pass for an ARM/Thumb image after auto-analysis (T06 DISPLAY; reusable).
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin \
//     -noanalysis -scriptPath tools/ghidra -postScript DisplayFindCode.java [codeBlock]
// (the default codeBlock is ".text"; -noanalysis is fine because the script runs the analysis
//  manager itself after seeding.)
// Pass 1: function pointers. Every aligned word in initialized, non-executable blocks whose value
//         points into the code block at a still-undefined location (bit 0 = Thumb) is disassembled
//         and made a function if the target starts with a typical prologue.
// Pass 2: prologue scan. Undefined gaps in the code block are scanned for ARM "push {..,lr}"
//         (E92D4xxx / STMFD sp!) and Thumb "push {..,lr}" (B5xx) / "push.w" (E92D 4xxx) starts.
// Pass 3: functions at the start of each run of orphan instructions (code in no function).
// Pointers inside GUI bitmaps can look like code pointers, so pass 1 demands a prologue too.
// @category FT710
import ghidra.app.cmd.disassemble.ArmDisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class DisplayFindCode extends GhidraScript {
    MemoryBlock code;

    boolean undefinedAt(Address a) {
        return getInstructionContaining(a) == null && getDataContaining(a) == null;
    }

    boolean armPrologue(Address a) throws Exception {
        int w = getInt(a);
        // STMFD sp!, {...lr}  or  SUB sp,sp,#imm / MOV r12,sp / PUSH via STR lr,[sp,#-4]!
        return (w & 0xFFFF4000) == 0xE92D4000 || w == 0xE52DE004 || (w & 0xFFFFF000) == 0xE24DD000;
    }

    boolean thumbPrologue(Address a) throws Exception {
        int h = getShort(a) & 0xffff;
        int h2 = getShort(a.add(2)) & 0xffff;
        return (h & 0xFF00) == 0xB500 || (h == 0xE92D && (h2 & 0x4000) != 0) || (h & 0xFF80) == 0xB080;
    }

    int make(Address a, boolean thumb) throws Exception {
        if (!undefinedAt(a)) return 0;
        new ArmDisassembleCommand(a, null, thumb).applyTo(currentProgram, monitor);
        if (getInstructionAt(a) == null) return 0;
        if (getFunctionAt(a) == null && createFunction(a, null) == null) return 0;
        return 1;
    }

    @Override
    protected void run() throws Exception {
        String name = getScriptArgs().length > 0 ? getScriptArgs()[0] : ".text";
        Memory mem = currentProgram.getMemory();
        code = mem.getBlock(name);
        long cs = code.getStart().getOffset(), ce = code.getEnd().getOffset();
        int p1 = 0, p2 = 0;
        for (MemoryBlock b : mem.getBlocks()) {
            if (b.isExecute() || !b.isInitialized()) continue;
            for (long o = (b.getStart().getOffset() + 3) & ~3L; o + 4 <= b.getEnd().getOffset() + 1; o += 4) {
                long v = getInt(toAddr(o)) & 0xffffffffL;
                if (v < cs || v > ce) continue;
                boolean thumb = (v & 1) != 0;
                Address t = toAddr(v & ~1L);
                if (!thumb && (v & 3) != 0) continue;
                if (!undefinedAt(t)) continue;
                if (thumb ? thumbPrologue(t) : armPrologue(t)) p1 += make(t, thumb);
            }
        }
        println("pass 1 (pointer tables): " + p1 + " functions");
        for (long o = cs; o < ce; o += 2) {
            Address a = toAddr(o);
            if (!undefinedAt(a)) continue;
            if ((o & 3) == 0 && armPrologue(a)) p2 += make(a, false);
            else if (thumbPrologue(a)) {
                // Thumb candidate must directly follow existing code or 0000/BF00 padding,
                // which keeps random B5xx halfwords in literal pools from becoming functions
                Address prev = a.subtract(2);
                int ph = getShort(prev) & 0xffff;
                if (getInstructionContaining(prev) != null || ph == 0 || ph == 0xBF00) p2 += make(a, true);
            }
        }
        println("pass 2 (prologue scan): " + p2 + " functions");
        analyzeChanges(currentProgram);
        // Pass 3: orphan instructions (disassembled but in no function, e.g. reached only through
        // a computed branch). Make a function at the start of every orphan run.
        int p3 = 0;
        Address prevEnd = null;
        for (ghidra.program.model.listing.Instruction i : currentProgram.getListing().getInstructions(code.getStart(), true)) {
            if (i.getAddress().compareTo(code.getEnd()) > 0) break;
            boolean orphan = getFunctionContaining(i.getAddress()) == null;
            if (orphan && (prevEnd == null || !prevEnd.equals(i.getAddress()))) {
                if (createFunction(i.getAddress(), null) != null) p3++;
            }
            ghidra.program.model.listing.Instruction cur = getInstructionAt(i.getAddress());
            prevEnd = (cur != null && getFunctionContaining(cur.getAddress()) == null && cur.getFallThrough() != null)
                    ? cur.getFallThrough() : null;
        }
        println("pass 3 (orphan code): " + p3 + " functions");
        analyzeChanges(currentProgram);
        println("functions now: " + currentProgram.getFunctionManager().getFunctionCount());
    }
}
