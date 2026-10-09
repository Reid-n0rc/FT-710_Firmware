// Prepare a raw Renesas RX651 (R5F56514, 512 KB flash / 256 KB RAM) code-flash image for analysis.
// Run as a -preScript after importing the flat ROM with BinaryLoader at 0xFFF80000 using
// language rx62t:LE:32:default (community RX SLEIGH module, see docs/tooling.md).
//
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN \
//     -import build/FT-710_MAIN_V0112.bin -processor rx62t:LE:32:default \
//     -loader BinaryLoader -loader-baseAddr 0xFFF80000 \
//     -scriptPath tools/ghidra -preScript SetupRX651.java [copy=SRC:END:DST ...] [intb=0xADDR] \
//     -analysisTimeoutPerFile 3600
//
// What it does:
//   * adds RAM 0x00000000..0x0003FFFF, data flash 0x00100000 (32 KB), and volatile peripheral I/O
//     blocks 0x00080000..0x000FFFFF and 0x007FC000..0x007FFFFF (flash/FCU registers);
//   * optional copy=SRC:END:DST args model the C runtime .data copy-down: ROM bytes [SRC,END)
//     are written into RAM at DST (the RAM block is split so that range is initialized);
//   * creates functions + labels for the fixed vector table (0xFFFFFFD0..0xFFFFFFFC) and the
//     relocatable vector table at INTB (default 0xFFF8E6DC, 256 entries), named by RX651 vector
//     number (vecNNN_xxx), skipping the shared "unused" handler except once;
//   * defines the vector tables as pointer arrays and names a few RX651 peripheral bases.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.data.ArrayDataType;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.listing.Function;

import java.util.HashMap;
import java.util.Map;

public class SetupRX651 extends GhidraScript {

    private Address a(long off) {
        return currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(off);
    }

    private void uninit(String name, long start, long size, boolean vol) throws Exception {
        Memory m = currentProgram.getMemory();
        if (m.getBlock(a(start)) != null) {
            return;
        }
        MemoryBlock b = m.createUninitializedBlock(name, a(start), size, false);
        b.setRead(true);
        b.setWrite(true);
        b.setExecute(false);
        b.setVolatile(vol);
    }

    // RX651 vector names (hardware manual, interrupt vector table). Only the entries this
    // firmware populates need names; unknown ones get vecNNN.
    private static final Map<Integer, String> VEC = new HashMap<>();
    static {
        VEC.put(16, "BSC_BUSERR"); VEC.put(26, "ICU_SWINT2"); VEC.put(27, "ICU_SWINT");
        VEC.put(28, "CMT0_CMI0"); VEC.put(29, "CMT1_CMI1"); VEC.put(30, "CMTW0_CMWI0"); VEC.put(31, "CMTW1_CMWI1");
        VEC.put(38, "RSPI0_SPRI0"); VEC.put(39, "RSPI0_SPTI0");
        VEC.put(58, "SCI0_RXI0"); VEC.put(59, "SCI0_TXI0"); VEC.put(60, "SCI1_RXI1"); VEC.put(61, "SCI1_TXI1");
        VEC.put(62, "SCI2_RXI2"); VEC.put(63, "SCI2_TXI2");
        for (int i = 0; i < 16; i++) VEC.put(64 + i, "ICU_IRQ" + i);
        VEC.put(80, "SCI3_RXI3"); VEC.put(81, "SCI3_TXI3"); VEC.put(82, "SCI4_RXI4"); VEC.put(83, "SCI4_TXI4");
        VEC.put(84, "SCI5_RXI5"); VEC.put(85, "SCI5_TXI5"); VEC.put(86, "SCI6_RXI6"); VEC.put(87, "SCI6_TXI6");
        VEC.put(98, "SCI7_RXI7"); VEC.put(99, "SCI7_TXI7");
        VEC.put(106, "GROUPBE0"); VEC.put(107, "GROUPBL2"); VEC.put(110, "GROUPBL0"); VEC.put(111, "GROUPBL1");
        VEC.put(112, "GROUPAL0"); VEC.put(113, "GROUPAL1");
    }

    private static final String[] FIXED = {
        "SuperVisorInst", "AccessExc", "Undefined_0xD8", "UndefinedInst", "Undefined_0xE0", "FloatingPoint",
        "Undefined_0xE8", "Undefined_0xEC", "Undefined_0xF0", "Undefined_0xF4", "NMI", "PowerON_Reset"
    };

    private void entry(long target, String name) throws Exception {
        Address t = a(target);
        if (currentProgram.getMemory().getBlock(t) == null) {
            return;
        }
        Function f = getFunctionAt(t);
        if (f == null) {
            disassemble(t);
            f = createFunction(t, name);
        }
        if (f != null && f.getName().startsWith("FUN_")) {
            f.setName(name, SourceType.USER_DEFINED);
        } else if (f == null) {
            createLabel(t, name, true);
        }
        addEntryPoint(t);
    }

    @Override
    protected void run() throws Exception {
        long intb = 0xFFF8E6DCL;
        Memory m = currentProgram.getMemory();
        // .data copy-down ranges first, so the RAM block is created around them
        java.util.List<long[]> copies = new java.util.ArrayList<>();
        for (String arg : getScriptArgs()) {
            if (arg.startsWith("copy=")) {
                String[] p = arg.substring(5).split(":");
                copies.add(new long[] { Long.decode(p[0]), Long.decode(p[1]), Long.decode(p[2]) });
            } else if (arg.startsWith("intb=")) {
                intb = Long.decode(arg.substring(5));
            }
        }
        long ramEnd = 0x40000;
        long cur = 0;
        copies.sort((x, y) -> Long.compare(x[2], y[2]));
        int n = 0;
        for (long[] c : copies) {
            long len = c[1] - c[0];
            if (len <= 0) continue;
            if (c[2] > cur) uninit("RAM_" + n++, cur, c[2] - cur, false);
            byte[] buf = new byte[(int) len];
            m.getBytes(a(c[0]), buf);
            MemoryBlock b = m.createInitializedBlock(String.format("RAM_data_%08X", c[2]), a(c[2]),
                    new java.io.ByteArrayInputStream(buf), len, monitor, false);
            b.setRead(true); b.setWrite(true); b.setExecute(false);
            b.setComment(String.format("copy-down of ROM 0x%08X..0x%08X (startup .data init)", c[0], c[1]));
            cur = c[2] + len;
            println(String.format("copy-down ROM %08X..%08X -> RAM %08X", c[0], c[1], c[2]));
        }
        if (cur < ramEnd) uninit("RAM_" + n, cur, ramEnd - cur, false);
        uninit("IO_periph", 0x00080000L, 0x80000L, true);
        uninit("DataFlash", 0x00100000L, 0x8000L, false);
        uninit("IO_flash", 0x007FC000L, 0x4000L, true);

        // ROM block is code+rodata: read/execute, not writable
        MemoryBlock rom = m.getBlock(a(0xFFF80000L));
        if (rom != null) {
            rom.setName("ROM");
            rom.setWrite(false);
            rom.setExecute(true);
        }

        // fixed vector table
        Address fv = a(0xFFFFFFD0L);
        clearListing(fv, a(0xFFFFFFFFL));
        createData(fv, new ArrayDataType(PointerDataType.dataType, 12, 4));
        createLabel(fv, "FixedVectors", true);
        for (int i = 0; i < 12; i++) {
            long t = m.getInt(a(0xFFFFFFD0L + 4 * i)) & 0xFFFFFFFFL;
            entry(t, FIXED[i]);
        }
        // relocatable vector table
        Address rv = a(intb);
        clearListing(rv, a(intb + 0x3FF));
        createData(rv, new ArrayDataType(PointerDataType.dataType, 256, 4));
        createLabel(rv, "RelocatableVectors", true);
        Map<Long, Integer> count = new HashMap<>();
        for (int i = 0; i < 256; i++) {
            long t = m.getInt(a(intb + 4 * i)) & 0xFFFFFFFFL;
            count.merge(t, 1, Integer::sum);
        }
        for (int i = 0; i < 256; i++) {
            long t = m.getInt(a(intb + 4 * i)) & 0xFFFFFFFFL;
            if (count.get(t) > 8) {
                entry(t, "Dummy_Interrupt");
                continue;
            }
            String nm = VEC.containsKey(i) ? VEC.get(i) : "";
            entry(t, String.format("vec%03d_%s", i, nm.isEmpty() ? "isr" : nm));
        }
        println("SetupRX651: memory map + vectors done (INTB=" + Long.toHexString(intb) + ")");
    }
}
