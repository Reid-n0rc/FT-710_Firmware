# FT-710 DISPLAY (RZ/A1H Cortex-A9): recreated source build and check (T24).
#
#   make            compile every recreated file into out/obj (A32, soft-float, one section per function)
#   make check      differential emulation of every recreated function against the original image -> status.tsv
#                   (needs build/FT-710_DISPLAY_V0108.bin, see docs/getting-started.md; FT710_BUILD=<dir> elsewhere)
#
# The image was built with armcc (ARM Compiler 5), which is not available: nothing here can be byte-identical, and any
# arm-none-eabi GCC will do (T24 used xPack 10.2.1-1.1, the M33's compiler). The image uses the armcc soft-float
# library (__aeabi_dadd & co. in .text), so the build is soft-float too. -fno-tree-loop-distribute-patterns keeps
# GCC from turning the copy and fill loops of lib/memory.c into calls of themselves.
CROSS ?= arm-none-eabi-
CC := $(CROSS)gcc
OUT := out

CFLAGS := -std=gnu99 -g -O2 -marm -mcpu=cortex-a9 -mfloat-abi=soft -ffreestanding -fno-builtin -fno-common \
          -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-tree-loop-distribute-patterns -Wall -Wextra -Wno-unused-parameter -Iinclude

SRCS := $(wildcard app/*.c lib/*.c drivers/*.c)
OBJ := $(patsubst %.c,$(OUT)/obj/%.o,$(SRCS))

all: $(OBJ)

$(OUT)/obj/%.o: %.c $(wildcard include/*.h)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

check: all
	python3 -I ../../tools/equiv_display_emu.py status

clean:
	rm -rf $(OUT)

.PHONY: all check clean
