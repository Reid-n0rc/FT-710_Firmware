// FT-710 DISPLAY (Renesas RZ/A1H, Cortex-A9) memory map + seeding. Run as a -preScript at import
// so auto-analysis sees the final memory map (T06, see docs/memory-maps.md "DISPLAY").
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY \
//     -import build/FT-710_DISPLAY_V0108.bin -overwrite \
//     -processor ARM:LE:32:v7 -loader BinaryLoader -loader-baseAddr 0x20100000 \
//     -scriptPath tools/ghidra -preScript DisplaySetup.java -analysisTimeoutPerFile 3600
// What it does:
//  1. Splits the imported image into .text (code), .rodata (constants + GUI bitmaps/fonts, not
//     executable) and the armcc scatter-load area (Region$$Table + compressed RW init data).
//  2. Parses Region$$Table, runs the armcc LZ decompressor (__decompress, 0x20100BFC) and creates
//     the RW data blocks as initialized memory, and the ZI (.bss) blocks as uninitialized memory.
//  3. Adds the rest of on-chip RAM, the RAM mirror, the SPI-flash window and RZ/A1H peripheral
//     ranges as uninitialized (peripherals volatile) blocks.
//  4. Labels the vector table / startup routines and disassembles from the exception vectors.
// @category FT710
import ghidra.app.cmd.disassemble.ArmDisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.ArrayDataType;
import ghidra.program.model.data.ByteDataType;
import ghidra.program.model.data.DWordDataType;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;

public class DisplaySetup extends GhidraScript {
    static final long TEXT_END = 0x20165178L;      // first byte of .rodata (code + armcc fplib end at 0x20165177)
    static final long REGION_TABLE = 0x204286A8L;  // armcc Region$$Table (5 x 16 bytes)
    static final int REGIONS = 5;
    static final long DECOMPRESS = 0x20100BFCL;    // __decompress (Thumb)
    static final long ZEROINIT = 0x20100C60L;      // __scatterload_zeroinit (Thumb)

    Address a(long v) { return toAddr(v); }

    void uninit(String name, long start, long end, boolean vol, boolean w, boolean x) throws Exception {
        Memory mem = currentProgram.getMemory();
        if (end <= start) return;
        MemoryBlock b = mem.createUninitializedBlock(name, a(start), end - start, false);
        b.setRead(true); b.setWrite(w); b.setExecute(x); b.setVolatile(vol);
        println(String.format("block %-14s %08X-%08X %s", name, start, end - 1, vol ? "volatile" : ""));
    }

    byte[] lz(long src, int size) throws Exception {
        Memory mem = currentProgram.getMemory();
        ByteArrayOutputStream o = new ByteArrayOutputStream();
        byte[] out = new byte[size + 512];
        int n = 0;
        long p = src;
        int c = mem.getByte(a(p++)) & 0xff;
        while (true) {
            int lit = c & 3;
            if (lit == 0) lit = mem.getByte(a(p++)) & 0xff;
            int mlen = c >> 4;
            if (mlen == 0) mlen = mem.getByte(a(p++)) & 0xff;
            for (int i = 0; i < lit - 1; i++) out[n++] = mem.getByte(a(p++));
            if (mlen != 0) {
                int off = mem.getByte(a(p++)) & 0xff;
                if ((c & 0xc) == 0xc) off += (mem.getByte(a(p++)) & 0xff) << 8;
                else off += (c & 0xc) << 6;
                int s = n - off;
                for (int i = 0; i < mlen + 2; i++) out[n++] = out[s++];
            }
            if (n >= size) break;
            c = mem.getByte(a(p++)) & 0xff;
        }
        o.write(out, 0, size);
        println(String.format("decompressed %08X -> %d bytes (src end %08X)", src, size, p));
        return o.toByteArray();
    }

    void seed(long addr, String name, boolean thumb) throws Exception {
        Address ad = a(addr);
        createLabel(ad, name, true, SourceType.ANALYSIS);
        ArmDisassembleCommand cmd = new ArmDisassembleCommand(ad, null, thumb);
        cmd.applyTo(currentProgram, monitor);
        if (getFunctionAt(ad) == null) createFunction(ad, name);
    }

    @Override
    protected void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        MemoryBlock img = mem.getBlock(a(0x20100000L));
        long imgEnd = img.getEnd().getOffset() + 1;

        // 1. split the file image
        mem.split(img, a(TEXT_END));
        mem.split(mem.getBlock(a(TEXT_END)), a(REGION_TABLE));
        MemoryBlock text = mem.getBlock(a(0x20100000L));
        text.setName(".text"); text.setRead(true); text.setWrite(false); text.setExecute(true);
        MemoryBlock ro = mem.getBlock(a(TEXT_END));
        ro.setName(".rodata"); ro.setRead(true); ro.setWrite(false); ro.setExecute(false);
        MemoryBlock sc = mem.getBlock(a(REGION_TABLE));
        sc.setName("scatter_init"); sc.setRead(true); sc.setWrite(false); sc.setExecute(false);
        println(String.format("image %08X-%08X split at %08X and %08X", 0x20100000L, imgEnd - 1, TEXT_END, REGION_TABLE));

        // 2. Region$$Table: {load addr, exec addr, size, handler}
        long ramGapStart = imgEnd;  // stacks live between the image end and the first RW region
        String[] rwNames = {".data", ".data_nc", ".data2"};
        String[] ziNames = {".bss", ".bss2"};
        int rw = 0, zi = 0;
        createData(a(REGION_TABLE), new ArrayDataType(DWordDataType.dataType, REGIONS * 4, 4));
        createLabel(a(REGION_TABLE), "Region$$Table", true, SourceType.ANALYSIS);
        for (int i = 0; i < REGIONS; i++) {
            long e = REGION_TABLE + i * 16L;
            long src = getInt(a(e)) & 0xffffffffL;
            long dst = getInt(a(e + 4)) & 0xffffffffL;
            int size = getInt(a(e + 8));
            long fn = getInt(a(e + 12)) & 0xffffffffL;
            if (fn == DECOMPRESS) {
                byte[] data = lz(src, size);
                String nm = rw < rwNames.length ? rwNames[rw] : ".data" + rw;
                rw++;
                MemoryBlock b = mem.createInitializedBlock(nm, a(dst), new ByteArrayInputStream(data), size, monitor, false);
                b.setRead(true); b.setWrite(true); b.setExecute(false);
                b.setComment(String.format("armcc RW region, LZ-compressed at %08X", src));
                println(String.format("block %-14s %08X-%08X init from %08X", nm, dst, dst + size - 1, src));
                createLabel(a(src), "Load$$" + nm.substring(1) + "$$Base", true, SourceType.ANALYSIS);
            } else if (fn == ZEROINIT) {
                String nm = zi < ziNames.length ? ziNames[zi] : ".bss" + zi;
                zi++;
                uninit(nm, dst, dst + size, false, true, false);
            } else {
                printerr(String.format("unknown scatter handler %08X in entry %d", fn, i));
            }
        }
        // compressed blob: keep it as bytes so nothing disassembles it
        long blob = REGION_TABLE + REGIONS * 16L;
        createData(a(blob), new ArrayDataType(ByteDataType.dataType, (int) (imgEnd - blob), 1));

        // 3. rest of the address map (RZ/A1H)
        uninit("ram_lo", 0x20000000L, 0x20100000L, false, true, false);           // below the image
        uninit("ram_stack", ramGapStart, 0x20450000L, false, true, false);        // SVC/IRQ/... stacks (SP 0x2044C000)
        uninit("ram_mid", 0x204FC5F4L, 0x20800000L, false, true, false);          // after .bss (frame buffers via 0x605xxxxx?)
        uninit("ram_hi", 0x2091D570L, 0x20A00000L, false, true, false);           // after .bss2 (heap up to 0x20980000?)
        uninit("ram_nc_lo", 0x60000000L, 0x60500000L, false, true, false);        // uncached RAM mirror
        uninit("ram_nc_hi", 0x605048A0L, 0x60A00000L, false, true, false);
        uninit("spi_flash", 0x18000000L, 0x19000000L, false, false, false);       // W25Q128 via SPIBSC0 (16 MB)
        uninit("io_3FE", 0x3FE00000L, 0x40000000L, true, true, false);           // SPIBSC, PL310, ...
        uninit("io_E800", 0xE8000000L, 0xE8300000L, true, true, false);          // SCIF, RSPI, SDHI, USB, DMAC, GIC, ...
        uninit("io_FCFE", 0xFCFE0000L, 0xFD000000L, true, true, false);          // CPG, GPIO, INTC, WDT, RIIC, OSTM, MTU2, VDC5, ...

        // 4. vectors + startup
        String[] vec = {"vec_reset", "vec_undef", "vec_svc", "vec_pabort", "vec_dabort", "vec_reserved", "vec_irq", "vec_fiq"};
        for (int i = 0; i < 8; i++) {
            Address v = a(0x20100000L + i * 4);
            createLabel(v, vec[i], true, SourceType.ANALYSIS);
            new ArmDisassembleCommand(v, null, false).applyTo(currentProgram, monitor);
        }
        createData(a(0x20100028L), DWordDataType.dataType);
        createLabel(a(0x20100028L), "initial_sp", true, SourceType.ANALYSIS);
        seed(0x2010002CL, "Reset_Handler", false);
        seed(0x20100080L, "reset_in_ram", false);
        seed(0x20100194L, "SVC_Handler", false);
        seed(0x201001D8L, "IRQ_Handler", false);
        seed(0x2010021CL, "FIQ_Handler", false);
        seed(0x20100220L, "Undef_Handler", false);
        seed(0x20100224L, "PAbort_Handler", false);
        seed(0x20100228L, "DAbort_Handler", false);
        seed(0x20100BC0L, "__main", false);
        seed(0x20100BC8L, "__scatterload", true);
        seed(DECOMPRESS, "__decompress", true);
        seed(ZEROINIT, "__scatterload_zeroinit", true);
        seed(0x20100CDCL, "__rt_entry", true);
        seed(0x2011497CL, "sfl_decode", false);
        seed(0x20114A64L, "sfl_crc", false);
        println("DisplaySetup done");
    }
}
