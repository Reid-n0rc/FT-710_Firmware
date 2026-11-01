# Recreated MAIN (RX651) source, T24. Builds one object per source file into out/obj/ (ignored; never committed).
#
#   make -C src/main CROSS=<prefix>        e.g. CROSS=$HOME/opt/rx-gcc-13.3.0/bin/rx-elf-
#   make -C src/main check CROSS=<prefix>  = python3 -I tools/equiv_main_emu.py status (needs Ghidra, see README.md)
#
# GCC for RX (mainline 13.3.0, docs/tooling.md "GCC for RX") knows RXv1 only (-mcpu=rx600); the RX651 is RXv2, a
# superset, so the code runs unchanged. The image was built with Renesas CC-RX (docs/tasks/T24-source-recreation.md,
# "MAIN"), which is not available here, so the check is differential emulation, not a byte match.
#   -ffunction-sections   one section per function: the checker links each function on its own
#   -fno-ipa-ra           calls to functions of the same file may go to the image's own code in the check, which
#                         keeps only the ABI's registers (as in src/display/Makefile)
#   -fno-tree-loop-distribute-patterns   no memset/memcpy calls for plain loops
#   -fno-optimize-sibling-calls          a call stays BSR + RTS as CC-RX -O0 writes it: a tail call (BRA) would
#                         run the callee 4 bytes higher on the stack, and callees that hand the address of a stack
#                         local to a driver (R_SCIn_Serial_Send keeps it) make the stack depth observable
#                         (T24 MAIN round 2: tuner_task)
#   -ffreestanding -fno-builtin          the image's C library is the one that counts
CROSS ?= rx-elf-
CC := $(CROSS)gcc
ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
OUT := out
CFLAGS := -mcpu=rx600 -mlittle-endian-data -Os -g -ffunction-sections -fdata-sections -fno-ipa-ra \
          -fno-tree-loop-distribute-patterns -fno-optimize-sibling-calls -ffreestanding -fno-builtin -fno-common -std=gnu11 \
          -Wall -Wextra -Wno-unused-parameter -Iinclude -I$(OUT)/include -I$(ROOT)/tools/ghidra

SRCS := $(wildcard lib/*.c bsp/*.c drivers/*.c app/*.c)
OBJS := $(patsubst %.c,$(OUT)/obj/%.o,$(SRCS))

all: $(OBJS)

$(OUT)/include/iodefine.h: $(ROOT)/tools/main_iodefine.py $(ROOT)/tools/ghidra/sfr_rx651.tsv
	python3 -I $(ROOT)/tools/main_iodefine.py $@

# the typed state blocks (struct ui_state g_ui, struct opstate g_opstate, ...) from tools/ghidra/structs_main.h
$(OUT)/include/ft710_state.h: $(ROOT)/tools/main_structs.py $(ROOT)/tools/ghidra/structs_main.h $(ROOT)/tools/ghidra/enums_main.h
	python3 -I $(ROOT)/tools/main_structs.py $@

$(OUT)/obj/%.o: %.c $(OUT)/include/iodefine.h $(OUT)/include/ft710_state.h $(wildcard include/*.h drivers/*.h app/*.h)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

check: all
	python3 -I $(ROOT)/tools/equiv_main_emu.py status

clean:
	rm -rf $(OUT)

.PHONY: all check clean
