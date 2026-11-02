# FT-710 IFDSP HiFi4: recreated source build (T24).
#
#   make vendor     fetch the pinned vendor sources (vendor.sh, vendor.tsv)
#   make            compile every object into out/obj
#   make check      differential emulation against the original image -> status.tsv
#                   (needs build/FT-710_IFDSP_V0101_hifi4.bin and the Ghidra copy of tools/equiv_hifi4_emu.py)
#
# Toolchain: the Zephyr SDK 0.17.0 GCC 12.2.0 for the NXP RT600 HiFi4 core (xtensa-nxp_rt600_adsp_zephyr-elf). It emits
# base Xtensa with the core's integer options only (no FPU, no HiFi4, no FLIX bundles; its assembler knows all of them),
# so nothing can come out byte-identical to the image, which was built with Cadence XCC. Evidence:
# docs/tasks/T24-source-recreation.md, "IFDSP HiFi4".
CROSS ?= /root/opt/zephyr-sdk-0.17.0/xtensa-nxp_rt600_adsp_zephyr-elf/bin/xtensa-nxp_rt600_adsp_zephyr-elf-
CC := $(CROSS)gcc
OUT := out
V := vendor
NL := $(V)/newlib-cygwin/newlib

# -O2 as the image's code shows (registers only, zero-overhead loops); one section per function and variable, so the
# harness links each function alone and places each variable at its address in the image; -mlongcalls lets the
# scratch link reach every original callee (the linker relaxes the calls that are in CALL8 range).
CFLAGS := -std=gnu99 -g -O2 -ffunction-sections -fdata-sections -fno-common -mlongcalls -Wall -Wno-unused-function
# the C library members: newlib's own build flags for these files (no builtins, no loop-to-library-call rewrite, which
# would turn memmove's byte loop into a call to memmove)
LIBCFLAGS := $(CFLAGS) -fno-builtin -fno-tree-loop-distribute-patterns -D_COMPILING_NEWLIB -DMISSING_SYSCALL_NAMES
INC := -Iinclude -I$(NL)/libc/string -I$(NL)/libm/common
# libm: newlib-3.1.0's math.h (struct exception, _LIB_VERSION) ahead of the toolchain's newlib 4 header
LIBM_INC := -I$(NL)/libc/include

# newlib machine/xtensa (Tensilica assembly), unmodified
NL_ASM := $(addprefix $(NL)/libc/machine/xtensa/,memcpy.S memset.S strlen.S strcmp.S strncpy.S)
# newlib C members, unmodified
NL_C := $(addprefix $(NL)/libc/string/,strncmp.c memchr.c memmove.c) $(NL)/libc/stdlib/rand.c $(NL)/libc/errno/errno.c \
        $(NL)/libm/common/s_matherr.c $(NL)/libm/math/sf_fabs.c \
        $(addprefix $(NL)/libm/common/,sf_copysign.c sf_nan.c sf_finite.c sf_fpclassify.c sf_scalbn.c)

# rpmsg-lite v3.1.1, unmodified: the bare-metal environment, the core, the name service, the virtqueue
RL := $(V)/rpmsg-lite/lib
RL_C := $(addprefix $(RL)/,rpmsg_lite/porting/environment/rpmsg_env_bm.c rpmsg_lite/rpmsg_lite.c rpmsg_lite/rpmsg_ns.c \
          virtio/virtqueue.c common/llist.c)
# -D__XCC__: rpmsg_compiler.h picks its HiFi4 branch by the XCC macro (MEM_BARRIER = nop, as env_mb 0x21AB50 is);
# GCC would get the Arm "dsb"
RL_INC := -D__XCC__ -I$(RL)/include -I$(RL)/include/platform/imxrt600_hifi4

# Recreated sources (this directory).
OWN_C := $(wildcard app/*.c libc/*.c)

OBJ := $(patsubst %.S,$(OUT)/obj/%.o,$(NL_ASM)) $(patsubst %.c,$(OUT)/obj/%.o,$(NL_C) $(RL_C) $(OWN_C))

all: $(OBJ)

vendor:
	./vendor.sh

$(OUT)/obj/$(NL)/%.o: $(NL)/%.S
	@mkdir -p $(dir $@)
	$(CC) -g -c -I$(NL)/libc/machine/xtensa $< -o $@

$(OUT)/obj/$(NL)/libm/%.o: $(NL)/libm/%.c
	@mkdir -p $(dir $@)
	$(CC) $(LIBCFLAGS) $(LIBM_INC) $(INC) -c $< -o $@

$(OUT)/obj/$(NL)/%.o: $(NL)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(LIBCFLAGS) $(INC) -c $< -o $@

$(OUT)/obj/$(RL)/%.o: $(RL)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) $(RL_INC) -c $< -o $@

$(OUT)/obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) $(RL_INC) -c $< -o $@

check: all
	cd ../.. && python3 -I tools/equiv_hifi4_emu.py status

clean:
	rm -rf $(OUT)

.PHONY: all vendor check clean
