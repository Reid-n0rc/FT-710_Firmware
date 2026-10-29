// Execute single instructions of the current program with Ghidra's p-code emulator from given start states and print
// the end states, for checking the SLEIGH semantics against a reference model (tools/rx_semcheck.py, T22a, #104).
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh <projdir> <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript RxEmuStep.java <cases.tsv> <out.tsv>
// cases.tsv: id  addr(hex)  regs  mem  uop
//   regs  "R1=0x12;R2=0x0;PSW=0x5" (any register by name; unlisted registers keep the previous case's value)
//   mem   "addr:hexbytes;addr:hexbytes" (written before the step; "-" for none)
//   uop   value written to the output of every CALLOTHER (user pcodeop, e.g. scmpu) the instruction executes ("-" = 0)
// out.tsv: id  ok|error  regs-after  writes  calls
//   regs-after  R0..R15,PC,PSW,USP,ISP,FPSW,ACC as "name=0x..;" ; writes = every byte range the step wrote, "addr:hex;"
//   calls       "name(arg0,arg1,...)" for each CALLOTHER, args as values (varnode inputs after the op index)
// @category FT710
import ghidra.app.emulator.EmulatorHelper;
import ghidra.app.script.GhidraScript;
import ghidra.pcode.emulate.BreakCallBack;
import ghidra.pcode.pcoderaw.PcodeOpRaw;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.pcode.Varnode;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class RxEmuStep extends GhidraScript {
    static final String[] OUT_REGS = {"SP", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10", "R11", "R12",
            "R13", "R14", "R15", "PC", "PSW", "USP", "ISP", "FPSW", "ACC"};

    private static byte[] unhex(String s) {
        byte[] b = new byte[s.length() / 2];
        for (int i = 0; i < b.length; i++) b[i] = (byte) Integer.parseInt(s.substring(2 * i, 2 * i + 2), 16);
        return b;
    }

    private static String hex(byte[] b) {
        StringBuilder sb = new StringBuilder();
        for (byte x : b) sb.append(String.format("%02x", x & 0xff));
        return sb.toString();
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        AddressSpace ram = currentProgram.getAddressFactory().getDefaultAddressSpace();
        EmulatorHelper emu = new EmulatorHelper(currentProgram);
        final List<String> calls = new ArrayList<>();
        final long[] uop = {0};
        emu.registerDefaultCallOtherCallback(new BreakCallBack() {
            @Override
            public boolean pcodeCallback(PcodeOpRaw op) {
                var st = emulate.getMemoryState();
                StringBuilder sb = new StringBuilder();
                String name = emulate.getLanguage().getUserDefinedOpName((int) op.getInput(0).getOffset());
                sb.append(name).append("(");
                for (int i = 1; i < op.getNumInputs(); i++) {
                    Varnode v = op.getInput(i);
                    if (i > 1) sb.append(",");
                    sb.append("0x").append(st.getBigInteger(v, false).toString(16));
                }
                sb.append(")");
                calls.add(sb.toString());
                Varnode out = op.getOutput();
                if (out != null) st.setValue(out, BigInteger.valueOf(uop[0]).and(
                        BigInteger.ONE.shiftLeft(8 * out.getSize()).subtract(BigInteger.ONE)));
                return true;
            }
        });
        long n = 0, nerr = 0;
        try (BufferedReader in = new BufferedReader(new FileReader(args[0]));
             PrintWriter out = new PrintWriter(args[1], "UTF-8")) {
            String line;
            while ((line = in.readLine()) != null) {
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] p = line.split("\t", -1);
                Address pc = ram.getAddress(Long.parseLong(p[1], 16));
                for (String kv : p[2].split(";")) {
                    if (kv.isEmpty() || kv.equals("-")) continue;
                    String[] t = kv.split("=");
                    emu.writeRegister(t[0], new BigInteger(t[1].replace("0x", ""), 16));
                }
                if (!p[3].equals("-")) {
                    for (String m : p[3].split(";")) {
                        if (m.isEmpty()) continue;
                        String[] t = m.split(":");
                        emu.writeMemory(ram.getAddress(Long.parseLong(t[0], 16)), unhex(t[1]));
                    }
                }
                uop[0] = p[4].equals("-") ? 0 : Long.parseUnsignedLong(p[4].replace("0x", ""), 16);
                calls.clear();
                emu.writeRegister(emu.getPCRegister(), pc.getOffset());
                emu.enableMemoryWriteTracking(false);
                emu.enableMemoryWriteTracking(true);
                boolean ok = emu.step(monitor);
                StringBuilder regs = new StringBuilder();
                for (String r : OUT_REGS) regs.append(r).append("=0x").append(emu.readRegister(r).toString(16)).append(";");
                StringBuilder wr = new StringBuilder();
                if (emu.getTrackedMemoryWriteSet() != null) {
                    for (AddressRange ar : emu.getTrackedMemoryWriteSet()) {
                        if (ar.getAddressSpace() != ram) continue;
                        wr.append(String.format("%08x", ar.getMinAddress().getOffset())).append(":")
                                .append(hex(emu.readMemory(ar.getMinAddress(), (int) ar.getLength()))).append(";");
                    }
                }
                if (!ok) nerr++;
                out.println(p[0] + "\t" + (ok ? "ok" : "error:" + emu.getLastError()) + "\t" + regs + "\t" +
                        (wr.length() == 0 ? "-" : wr) + "\t" + (calls.isEmpty() ? "-" : String.join(";", calls)));
                n++;
            }
        } finally {
            emu.dispose();
        }
        println("RxEmuStep: " + n + " cases, " + nerr + " emulation errors -> " + args[1]);
    }
}
