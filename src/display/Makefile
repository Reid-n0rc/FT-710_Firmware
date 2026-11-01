# FT-710 DISPLAY (RZ/A1H Cortex-A9): recreated source build and check (T24).
#
#   make            compile every recreated file into out/obj (A32, soft-float, one section per function)
#   make check      differential emulation of every recreated function against the original image -> status.tsv
#                   (needs build/FT-710_DISPLAY_V0108.bin, see docs/getting-started.md; FT710_BUILD=<dir> elsewhere)
#   make link       hybrid link (display.ld, tools/display_link.py): the original image with every function that
#                   passed the check linked in place, into the gap or into RAM2 -> out/FT-710_DISPLAY_hybrid.bin
#                   (never commit it)
#   make bootcheck  the emulated boot of the original and of the hybrid image (tools/display_boot_emu.py)
#   make linkcheck  the hybrid image against the original at every patched entry (differential emulation)
#   make rtos-test  the NORTi stand-in (rtos/) in Unicorn (tools/test_norti_standin.py)
#
# The image was built with armcc (ARM Compiler 5), which is not available, so the C cannot be byte-identical and is
# checked by differential emulation instead. The image uses the armcc soft-float library (__aeabi_dadd & co. in
# .text), so the build is soft-float too. -fno-tree-loop-distribute-patterns keeps GCC from turning the copy and fill
# loops of lib/memory.c into calls of themselves. -fno-ipa-ra: every call follows the AAPCS (the check runs the
# callees as the image's own code, which does not keep the registers GCC would assume).
#
# Compiler, pinned (T24 round 6): xPack GNU Arm Embedded GCC 10.2.1-1.1 ("10.2.1 20201103", Arm 10-2020-q4-major).
# Reasons: the code GCC emits is what the check verifies, and where a trial reads past a table the verdict even
# depends on how the compiler lays out .rodata (round 5: GCC 13.2.1 and 10.2.1 gave different verdicts for
# vdc5_reg_display_output before its preset was fixed), so status.tsv must come from one known compiler; xPack
# publishes this exact version for Linux, macOS and Windows, while arm-none-eabi-gcc on the path is whatever the
# system ships (13.2.1 in the T24 container); and it is the compiler of src/ifdsp_m33 (the M33 image's own) and of
# DISPLAY rounds 3 to 5. Install: docs/tooling.md "Source recreation". XPACK= points at the unpacked release;
# a different compiler stops the build unless ANY_GCC=1 is given (then the results are not the recorded ones).
XPACK ?= /home/user/t24/tc/10.2.1-1.1
CROSS ?= $(XPACK)/bin/arm-none-eabi-
GCC_PINNED := 10.2.1
CC := $(CROSS)gcc
OUT := out
GCC_FOUND := $(shell $(CC) -dumpversion 2>/dev/null)
ifneq ($(GCC_FOUND),$(GCC_PINNED))
ifneq ($(ANY_GCC),1)
$(error $(CC) is GCC "$(GCC_FOUND)", the DISPLAY tree is pinned to xPack GCC $(GCC_PINNED): set XPACK=<its directory> or CROSS=<its prefix> (ANY_GCC=1 builds anyway))
endif
endif

CFLAGS := -std=gnu99 -g -O2 -marm -mcpu=cortex-a9 -mfloat-abi=soft -ffreestanding -fno-builtin -fno-common \
          -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-tree-loop-distribute-patterns -fno-ipa-ra -Wall -Wextra -Wno-unused-parameter -Iinclude

SRCS := $(wildcard app/*.c lib/*.c drivers/*.c fs/*.c)
ASRCS := $(wildcard lib/*.S startup/*.S)
OBJ := $(patsubst %.c,$(OUT)/obj/%.o,$(SRCS)) $(patsubst %.S,$(OUT)/obj/%.o,$(ASRCS))

all: $(OBJ)

$(OUT)/obj/%.o: %.c $(wildcard include/*.h)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# hand-written run-time routines, transcribed from the image (byte-identical at their original addresses)
$(OUT)/obj/%.o: %.S
	@mkdir -p $(dir $@)
	$(CC) -mcpu=cortex-a9 -mfloat-abi=soft -c $< -o $@

check: all
	python3 -I ../../tools/equiv_display_emu.py status

# the start-up with RAM2's copy loop (vectors.S, RAM2_LOAD), linked only into the hybrid image, outside out/obj so
# that the check does not see it
$(OUT)/obj_ram2/startup/vectors.o: startup/vectors.S
	@mkdir -p $(dir $@)
	$(CC) -mcpu=cortex-a9 -mfloat-abi=soft -DRAM2_LOAD -c $< -o $@

link: all $(OUT)/obj_ram2/startup/vectors.o
	python3 -I ../../tools/equiv_display_emu.py abicheck
	python3 -I ../../tools/display_link.py --cross $(CROSS)

linkcheck: link
	python3 -I ../../tools/equiv_display_emu.py linkcheck

bootcheck: link
	python3 -I ../../tools/display_boot_emu.py --compare out/FT-710_DISPLAY_hybrid.bin

rtos-test:
	python3 -I ../../tools/test_norti_standin.py --cross $(CROSS)

clean:
	rm -rf $(OUT)

.PHONY: all check link linkcheck bootcheck rtos-test clean
