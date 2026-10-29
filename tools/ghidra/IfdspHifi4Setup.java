// Pre-analysis setup for the IFDSP HiFi4 (Xtensa) program. Input is the carved file from
// tools/ifdsp_dsp_images.py (the three DSP images back to back, exactly as in flash 0x08001844..0x0805D41C).
// Maps each image at the address the Cortex-M33 loader (FUN_00084ad8) copies it to, adds the rest of the
// RT685 map as the DSP sees it, and seeds the reset/exception vectors.
// Headless usage (from the repo root):
//   python3 -I tools/ifdsp_dsp_images.py build/FT-710_IFDSP_V0101.bin build
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -import build/FT-710_IFDSP_V0101_hifi4.bin \
//     -processor Xtensa:LE:32:rt600hifi4 -loader BinaryLoader -loader-baseAddr 0x0 \
//     -scriptPath tools/ghidra -preScript IfdspHifi4Setup.java -postScript IfdspHifi4FindFuncs.java \
//     -analysisTimeoutPerFile 3600
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.database.mem.FileBytes;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;

public class IfdspHifi4Setup extends GhidraScript {
    // Offsets inside the carved file (image sizes 0x20644, 0x383B4, 0x31E0 from flash 0x0805D41C).
    static final long IMG0 = 0x0, IMG0_LEN = 0x20644;   // -> 0x24000000 (DTCM 0x24000000 + ITCM 0x24020000)
    static final long IMG1 = 0x20644, IMG1_LEN = 0x383B4; // -> 0x00200000 (SRAM: text, rodata, data)
    static final long IMG2 = 0x389F8, IMG2_LEN = 0x31E0;  // -> 0x20040000 (all zeros: shared/non-cached)
    static final long SRAM_LEN = 0x480000L;

    Memory mem;
    FileBytes fb;

    void init(String name, long addr, long off, long len, boolean x, String c) throws Exception {
        MemoryBlock b = mem.createInitializedBlock(name, toAddr(addr), fb, off, len, false);
        b.setRead(true); b.setWrite(true); b.setExecute(x); b.setComment(c);
    }

    void uninit(String name, long addr, long len, boolean x, boolean vol) throws Exception {
        MemoryBlock b = mem.createUninitializedBlock(name, toAddr(addr), len, false);
        b.setRead(true); b.setWrite(true); b.setExecute(x); b.setVolatile(vol);
    }

    void func(long addr, String name) throws Exception {
        disassemble(toAddr(addr));
        if (getFunctionAt(toAddr(addr)) == null) createFunction(toAddr(addr), name);
        else getFunctionAt(toAddr(addr)).setName(name, SourceType.USER_DEFINED);
        addEntryPoint(toAddr(addr));
    }

    @Override
    protected void run() throws Exception {
        mem = currentProgram.getMemory();
        fb = mem.getAllFileBytes().get(0);
        for (MemoryBlock b : mem.getBlocks()) mem.removeBlock(b, monitor);

        init("dsp_dtcm", 0x24000000L, IMG0, 0x10000, false, "DSP image 0, first half (DTCM)");
        init("dsp_itcm", 0x24020000L, IMG0 + 0x20000, IMG0_LEN - 0x20000, true,
                "DSP image 0, ResetVector @0x24020000, VECBASE @0x24020400");
        uninit("dsp_itcm_free", 0x24020000L + IMG0_LEN - 0x20000, 0x10000 - (IMG0_LEN - 0x20000), true, false);
        // Image 1 = .rodata/.literal (0x200000..0x207CEF), .text (0x207CF0..0x2367FF), then .data (float filter
        // coefficient tables etc.). Both read-only so the decompiler resolves L32R literals; the rodata is not
        // executable, so analysis does not treat its tables as code space (T21j, from T22d).
        init("sram_dsp_rodata", 0x00200000L, IMG1, 0x7CF0, false, "DSP image 1: rodata, l32r literal pool");
        mem.getBlock(toAddr(0x00200000L)).setWrite(false);
        init("sram_dsp_text", 0x00207CF0L, IMG1 + 0x7CF0, 0x36800 - 0x7CF0, true, "DSP image 1: text");
        mem.getBlock(toAddr(0x00207CF0L)).setWrite(false);
        init("sram_dsp_data", 0x00236800L, IMG1 + 0x36800, IMG1_LEN - 0x36800, false, "DSP image 1: .data");
        uninit("sram_dsp_bss", 0x00200000L + IMG1_LEN, 0x300000L - (0x00200000L + IMG1_LEN), false, false);
        uninit("sram_m33", 0x0, 0x200000L, false, false);
        uninit("sram_hi", 0x300000L, SRAM_LEN - 0x300000L, false, false);
        uninit("sram_alias_lo", 0x20000000L, 0x40000L, false, false);
        init("sram_shared", 0x20040000L, IMG2, IMG2_LEN, false, "DSP image 2 (zero-filled)");
        uninit("sram_alias_hi", 0x20040000L + IMG2_LEN, SRAM_LEN - 0x40000L - IMG2_LEN, false, false);
        uninit("periph", 0x40000000L, 0x00160000L, false, true);

        func(0x24020000L, "_ResetVector");
        String[] win = {"_WindowOverflow4", "_WindowUnderflow4", "_WindowOverflow8",
            "_WindowUnderflow8", "_WindowOverflow12", "_WindowUnderflow12"};
        for (int i = 0; i < win.length; i++) func(0x24020400L + 0x40L * i, win[i]);
        // Other vectors (interrupt levels, debug, NMI, kernel/user/double exception): each starts
        // after a zero gap in 0x24020560..0x24020644.
        int n = 0;
        long end = 0x24020000L + IMG0_LEN - 0x20000;
        for (long p = 0x24020560L; p < end; p += 4) {
            boolean gap = mem.getInt(toAddr(p - 4)) == 0;
            if (gap && (mem.getByte(toAddr(p)) != 0 || mem.getByte(toAddr(p + 1)) != 0)) {
                func(p, String.format("_Vector_%x", p & 0xFFF));
                n++;
            }
        }
        createLabel(toAddr(0x24000000L), "dsp_dtcm_base", true, SourceType.USER_DEFINED);
        println("IfdspHifi4Setup: memory map added, " + (7 + n) + " vectors seeded");
    }
}
