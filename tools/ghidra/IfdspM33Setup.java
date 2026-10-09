// Pre-analysis setup for the IFDSP (NXP i.MX RT685, Cortex-M33) image FT-710_IFDSP_V0101.bin.
// Adds the RT685 memory map, the MCUXpresso copy-down .data/.ramfunc block, .bss, and seeds the
// vector table entries as Thumb functions. See docs/memory-maps.md (IFDSP) for the derivation.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -import build/FT-710_IFDSP_V0101.bin \
//     -processor ARM:LE:32:v8-m -loader BinaryLoader -loader-baseAddr 0x08000000 \
//     -scriptPath tools/ghidra -preScript IfdspM33Setup.java -postScript IfdspFindFuncs.java \
//     -analysisTimeoutPerFile 3600
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.database.mem.FileBytes;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;

import java.math.BigInteger;
import java.util.List;

public class IfdspM33Setup extends GhidraScript {
    static final long FLASH = 0x08000000L;
    // MCUXpresso global section table at 0x08001130 (src, dst, len): only the first entry is non-empty.
    static final long DATA_LMA = 0x0805D428L, DATA_VMA = 0x00080000L, DATA_LEN = 0x7EC4L;
    static final long BSS_VMA = 0x00087EC4L, BSS_LEN = 0x1A034L;
    static final long SRAM_LEN = 0x480000L; // 4.5 MB

    static final String[] SYS = {"__initial_sp", "ResetISR", "NMI_Handler", "HardFault_Handler",
        "MemManage_Handler", "BusFault_Handler", "UsageFault_Handler", "SecureFault_Handler",
        "imageLength", "imageType", "offsetToCrcOrCert", "SVC_Handler", "DebugMon_Handler",
        "imageLoadAddress", "PendSV_Handler", "SysTick_Handler"};
    // MIMXRT685S_cm33.h IRQ numbers 0..59.
    static final String[] IRQ = {"WDT0", "DMA0", "GPIO_INTA", "GPIO_INTB", "PIN_INT0", "PIN_INT1",
        "PIN_INT2", "PIN_INT3", "UTICK0", "MRT0", "CTIMER0", "CTIMER1", "SCT0", "CTIMER3",
        "FLEXCOMM0", "FLEXCOMM1", "FLEXCOMM2", "FLEXCOMM3", "FLEXCOMM4", "FLEXCOMM5",
        "FLEXCOMM14", "FLEXCOMM15", "ADC0", "Reserved39", "ACMP", "DMIC0", "Reserved42",
        "HYPERVISOR", "SECURE_VIOLATION", "HWVAD0", "Reserved46", "RNG", "RTC",
        "DSP_TIE_EXPSTATE1", "MU_A", "PIN_INT4", "PIN_INT5", "PIN_INT6", "PIN_INT7", "CTIMER2",
        "CTIMER4", "OS_EVENT", "FLEXSPI", "FLEXCOMM6", "FLEXCOMM7", "USDHC0", "USDHC1",
        "SGPIO_INTA", "SGPIO_INTB", "I3C0", "USB0", "USB0_NEEDCLK", "WDT1", "USB_PHYDCD", "DMA1",
        "PUF", "POWERQUAD", "CASPER", "PMC_PMIC", "HASHCRYPT"};

    Address a(long v) { return toAddr(v); }

    MemoryBlock uninit(String name, long start, long len, boolean x, boolean vol) throws Exception {
        Memory mem = currentProgram.getMemory();
        MemoryBlock b = mem.createUninitializedBlock(name, a(start), len, false);
        b.setRead(true); b.setWrite(true); b.setExecute(x); b.setVolatile(vol);
        return b;
    }

    @Override
    protected void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        MemoryBlock flash = mem.getBlock(a(FLASH));
        flash.setName("flexspi_xip");
        flash.setRead(true); flash.setWrite(false); flash.setExecute(true);
        // Split off the HiFi4 images and the .data load image so analyzers don't disassemble them as Thumb.
        mem.split(flash, a(0x08001844L));
        MemoryBlock dsp = mem.getBlock(a(0x08001844L));
        dsp.setName("flexspi_dsp_images");
        dsp.setExecute(false);
        dsp.setComment("3 HiFi4 (Xtensa) images copied by the M33 DSP loader; see decomp/ifdsp/hifi4");
        mem.split(dsp, a(0x0805D41CL));
        MemoryBlock lma = mem.getBlock(a(0x0805D41CL));
        lma.setName("flexspi_data_lma");
        lma.setExecute(false);
        lma.setComment("DSP image sizes + load image of sram_data_ramfunc (0x0805D428 -> 0x00080000)");

        List<FileBytes> fbs = mem.getAllFileBytes();
        FileBytes fb = fbs.get(0);
        long fileOff = DATA_LMA - FLASH;
        MemoryBlock data = mem.createInitializedBlock("sram_data_ramfunc", a(DATA_VMA), fb, fileOff,
                DATA_LEN, false);
        data.setRead(true); data.setWrite(true); data.setExecute(true);
        data.setComment("copy-down of flash 0x0805D428..0x080652EC by ResetISR (.ramfunc code + .data)");
        // The image runs entirely from SRAM: code, literal pools and rodata fill 0x80000..0x87EBC, and only
        // the last 8 bytes (0xAAAAAAAA, SystemCoreClock = 12000000) look like writable .data. Mark the code
        // part read-only so the decompiler resolves literal-pool constants instead of showing DAT_ loads.
        mem.split(data, a(0x00087EBCL));
        data.setName("sram_text_rodata");
        data.setWrite(false);
        MemoryBlock dvars = mem.getBlock(a(0x00087EBCL));
        dvars.setName("sram_data");
        dvars.setExecute(false);
        dvars.setComment(".data (copied from flash 0x080652E4)");
        MemoryBlock bss = uninit("sram_bss", BSS_VMA, BSS_LEN, false, false);
        bss.setComment(".bss, zeroed by ResetISR");
        // Rest of the 4.5 MB SRAM, code-bus alias (0x00000000) and data-bus alias (0x20000000).
        uninit("sram_lo", 0x0, DATA_VMA, true, false);
        uninit("sram_hi", BSS_VMA + BSS_LEN, SRAM_LEN - (BSS_VMA + BSS_LEN), true, false);
        uninit("sram_data_alias", 0x20000000L, SRAM_LEN, false, false);
        // HiFi4 TCMs as seen from the M33 (DSP image targets).
        uninit("dsp_dtcm", 0x24000000L, 0x10000, false, false);
        uninit("dsp_itcm", 0x24020000L, 0x10000, false, false);
        // Peripherals: APB/AHB non-secure alias (the image uses 0x4xxxxxxx), secure alias, PPB.
        uninit("periph", 0x40000000L, 0x00160000L, false, true);
        uninit("periph_s", 0x50000000L, 0x00160000L, false, true);
        uninit("ppb", 0xE0000000L, 0x00100000L, false, true);

        // Copy tables.
        createLabel(a(0x08001130L), "__data_section_table", true, SourceType.USER_DEFINED);
        createLabel(a(0x08001178L), "__bss_section_table", true, SourceType.USER_DEFINED);
        for (long p = 0x08001130L; p < 0x080011A8L; p += 4) createDWord(a(p));
        // DSP images (pointers/sizes in the M33 DSP loader's literal pool; sizes at 0x0805D41C).
        createLabel(a(0x08001844L), "dsp_image0_tcm", true, SourceType.USER_DEFINED);
        createLabel(a(0x08021E88L), "dsp_image1_sram_text", true, SourceType.USER_DEFINED);
        createLabel(a(0x0805A23CL), "dsp_image2_sram_data", true, SourceType.USER_DEFINED);
        createLabel(a(0x0805D41CL), "dsp_image0_size", true, SourceType.USER_DEFINED);
        createLabel(a(0x0805D420L), "dsp_image1_size", true, SourceType.USER_DEFINED);
        createLabel(a(0x0805D424L), "dsp_image2_size", true, SourceType.USER_DEFINED);
        for (long p = 0x0805D41CL; p < 0x0805D428L; p += 4) createDWord(a(p));

        // Vector table at 0x08001000: 16 system + 60 IRQ entries.
        Register tmode = currentProgram.getRegister("TMode");
        int seeded = 0;
        for (int i = 0; i < 16 + IRQ.length; i++) {
            Address slot = a(0x08001000L + 4L * i);
            createDWord(slot);
            long v = mem.getInt(slot) & 0xFFFFFFFFL;
            String name = i < 16 ? SYS[i] : IRQ[i - 16] + "_IRQHandler";
            if (i == 0 || i == 8 || i == 9 || i == 10 || i == 13 || (v & 1) == 0 || v == 0) {
                createLabel(slot, "vec_" + name, true, SourceType.USER_DEFINED);
                continue;
            }
            Address t = a(v & ~1L);
            if (!mem.contains(t)) continue;
            createLabel(slot, "vec_" + name, true, SourceType.USER_DEFINED);
            if (tmode != null) {
                currentProgram.getProgramContext().setValue(tmode, t, t, BigInteger.ONE);
            }
            disassemble(t);
            Function f = getFunctionAt(t);
            if (f == null) f = createFunction(t, name);
            else if (f.getName().startsWith("FUN_")) f.setName(name, SourceType.USER_DEFINED);
            else createLabel(t, name, false, SourceType.USER_DEFINED);
            seeded++;
        }
        addEntryPoint(a(0x080011A8L));
        println("IfdspM33Setup: memory map added, " + seeded + " vector entries seeded");
    }
}
