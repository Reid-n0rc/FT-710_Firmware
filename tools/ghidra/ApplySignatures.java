// Apply function signatures from a TSV (T21d, #97 B3). Run after ApplyNames.java.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript ApplySignatures.java tools/ghidra/signatures_main.tsv
// TSV: address<TAB>name<TAB>return<TAB>params<TAB>source<TAB>note; params is "type name, type name" or "void".
// Types: void bool char int8 uint8 int16 uint16 int32 uint32 int64 uint64 float double, with '*' for a pointer and
// "type[n]" for an array (a structure passed by value). A parameter "type name@stack:N" lives at entry SP+N (N >= 4);
// any such parameter, or a 64-bit return, switches the function to custom storage.
// Signatures are set with SourceType.USER_DEFINED, so the decompiler uses them as locked prototypes (its parameter
// ID no longer guesses arguments or returns for these functions or at their call sites). Storage is dynamic
// (CC-RX: R1..R4, return R1); a 64-bit return gets custom storage R2:R1 (low word in R1).
// The name column is only checked (a warning if the function has another name); ApplyNames.java sets names.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class ApplySignatures extends GhidraScript {
    DataType type(String t) throws Exception {
        t = t.trim();
        if (t.endsWith("*")) return new PointerDataType(type(t.substring(0, t.length() - 1)));
        java.util.regex.Matcher am = java.util.regex.Pattern.compile("(.*)\\[(\\d+)\\]").matcher(t);
        if (am.matches()) {
            DataType e = type(am.group(1));
            int n = Integer.parseInt(am.group(2));
            return new ArrayDataType(e, n, e.getLength());
        }
        switch (t) {
            case "void": return VoidDataType.dataType;
            case "bool": return BooleanDataType.dataType;
            case "char": return CharDataType.dataType;
            case "int8": return SignedByteDataType.dataType;
            case "uint8": return ByteDataType.dataType;
            case "int16": return ShortDataType.dataType;
            case "uint16": return UnsignedShortDataType.dataType;
            case "int32": return IntegerDataType.dataType;
            case "uint32": return UnsignedIntegerDataType.dataType;
            case "int64": return LongLongDataType.dataType;
            case "uint64": return UnsignedLongLongDataType.dataType;
            case "float": return FloatDataType.dataType;
            case "double": return DoubleDataType.dataType;
        }
        throw new IllegalArgumentException("unknown type '" + t + "'");
    }

    @Override
    protected void run() throws Exception {
        int ok = 0, bad = 0;
        Register r1 = currentProgram.getRegister("R1"), r2 = currentProgram.getRegister("R2");
        // the cspec default (__fastcall: R1..R4, return R1); without a named convention the decompiler warns
        String cc = currentProgram.getCompilerSpec().getDefaultCallingConvention().getName();
        for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            if (line.isBlank() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            Address a = toAddr(Long.parseLong(p[0].replaceFirst("^0x", ""), 16));
            Function f = getFunctionAt(a);
            if (f == null) { printerr("ApplySignatures: no function at " + a + " (" + p[1] + ")"); bad++; continue; }
            if (!f.getName().equals(p[1])) println("ApplySignatures: warning: " + a + " is " + f.getName() + ", TSV says " + p[1]);
            try {
                DataType rt = type(p[2]);
                List<Variable> params = new ArrayList<>();
                List<Integer> stackOff = new ArrayList<>(); // -1 = next register
                String ps = p.length > 3 ? p[3].trim() : "void";
                if (!ps.equals("void") && !ps.isEmpty()) {
                    int i = 0;
                    for (String q : ps.split(",")) {
                        q = q.trim();
                        int off = -1, at = q.indexOf("@stack:");
                        if (at >= 0) { off = Integer.decode(q.substring(at + 7).trim()); q = q.substring(0, at).trim(); }
                        int sp = Math.max(q.lastIndexOf(' '), Math.max(q.lastIndexOf('*'), q.lastIndexOf(']')));
                        String tn = q.substring(0, sp + 1).trim(), nm = q.substring(sp + 1).trim();
                        if (tn.isEmpty() || nm.isEmpty()) { tn = q; nm = "p" + (i + 1); }
                        params.add(new ParameterImpl(nm, type(tn), currentProgram, SourceType.USER_DEFINED));
                        stackOff.add(off);
                        i++;
                    }
                }
                if (rt.getLength() == 8 || stackOff.stream().anyMatch(o -> o >= 0)) {
                    // custom storage: register params in R1..R4 in order (sized), "@stack:N" params at entry SP+N
                    // (N >= 4, above the return address; CC-RX packs small stack arguments), return R2:R1 if 64-bit
                    List<Variable> cp = new ArrayList<>();
                    int k = 1;
                    for (int j = 0; j < params.size(); j++) {
                        Variable v = params.get(j);
                        VariableStorage vs;
                        if (stackOff.get(j) >= 0) {
                            vs = new VariableStorage(currentProgram, stackOff.get(j), v.getLength());
                        } else {
                            Register reg = currentProgram.getRegister("R" + k++);
                            vs = new VariableStorage(currentProgram, reg.getAddress(), v.getLength());
                        }
                        cp.add(new ParameterImpl(v.getName(), v.getDataType(), vs, currentProgram, SourceType.USER_DEFINED));
                    }
                    ReturnParameterImpl ret = rt.getLength() == 8
                            ? new ReturnParameterImpl(rt, new VariableStorage(currentProgram, r2, r1), currentProgram)
                            : rt.getLength() <= 0 ? new ReturnParameterImpl(rt, VariableStorage.VOID_STORAGE, currentProgram)
                            : new ReturnParameterImpl(rt, new VariableStorage(currentProgram, r1.getAddress(), rt.getLength()),
                                    currentProgram);
                    f.updateFunction(cc, ret, cp, FunctionUpdateType.CUSTOM_STORAGE, true, SourceType.USER_DEFINED);
                } else {
                    ReturnParameterImpl ret = new ReturnParameterImpl(rt, currentProgram);
                    f.updateFunction(cc, ret, params, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true,
                            SourceType.USER_DEFINED);
                }
                f.setSignatureSource(SourceType.USER_DEFINED);
                ok++;
            } catch (Exception e) {
                printerr("ApplySignatures: " + a + " " + p[1] + ": " + e.getMessage());
                bad++;
            }
        }
        println("ApplySignatures: " + ok + " applied, " + bad + " failed");
    }
}
