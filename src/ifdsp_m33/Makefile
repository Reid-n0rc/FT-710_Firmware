# FT-710 IFDSP Cortex-M33: recreated source build (T24).
#
#   make vendor     fetch the pinned vendor sources (vendor.sh, vendor.tsv)
#   make            compile every object into out/obj and link out/ifdsp_m33.elf (+ .bin of the SRAM and flash parts)
#   make check      byte check + differential emulation against the original image -> status.tsv
#                   (needs build/FT-710_IFDSP_V0101.bin, see docs/getting-started.md; FT710_BUILD=<dir> to point elsewhere)
#
# Toolchain: the image was built with GCC 10.2.1 (Arm 10-2020-q4-major); any other version still builds, but fewer
# functions come out byte-identical. Evidence: docs/tasks/T24-source-recreation.md, "Toolchain".
CROSS ?= arm-none-eabi-
CC := $(CROSS)gcc
OUT := out
V := vendor
SDK := $(V)/mcux-sdk
FR := $(V)/FreeRTOS-Kernel
RL := $(V)/rpmsg-lite/lib

CPUFLAGS := -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb
# MCUXpresso IDE "Release" settings as far as the bytes show them: -Os, -fno-builtin, -ffunction-sections.
CFLAGS := -std=gnu99 -Os -fno-common -ffunction-sections -fdata-sections -ffreestanding -fno-builtin $(CPUFLAGS) \
          -DCPU_MIMXRT685SFVKB_cm33 -DCPU_MIMXRT685SFVKB -D__REDLIB__ -D__USE_CMSIS -DNDEBUG -DSDK_OS_FREE_RTOS \
          -Wall -Wno-unused-function
INC := -Iconfig -Iboard -Iapp -Ilibc \
       -I$(SDK)/CMSIS/Include -I$(SDK)/devices/MIMXRT685S -I$(SDK)/devices/MIMXRT685S/drivers -I$(SDK)/drivers/common \
       $(addprefix -I$(SDK)/drivers/,flexcomm sctimer mu sema42 lpc_gpio inputmux pint lpc_dma otfad hashcrypt i3c ctimer \
                                      dmic flexspi usdhc utick ostimer lpc_iopctl) \
       -I$(FR)/include -I$(FR)/portable/GCC/ARM_CM33_NTZ/non_secure \
       -I$(RL)/include -I$(RL)/include/platform/imxrt600_m33

# Vendor sources, unmodified (vendor.tsv).
VENDOR_SRC := \
  $(SDK)/devices/MIMXRT685S/mcuxpresso/startup_mimxrt685s.c \
  $(SDK)/devices/MIMXRT685S/system_MIMXRT685S_cm33.c \
  $(addprefix $(SDK)/devices/MIMXRT685S/drivers/,fsl_clock.c fsl_power.c fsl_reset.c fsl_dsp.c fsl_iap.c) \
  $(SDK)/drivers/common/fsl_common.c $(SDK)/drivers/common/fsl_common_arm.c \
  $(SDK)/drivers/flexcomm/fsl_flexcomm.c $(SDK)/drivers/flexcomm/fsl_usart.c \
  $(SDK)/drivers/sctimer/fsl_sctimer.c $(SDK)/drivers/mu/fsl_mu.c $(SDK)/drivers/sema42/fsl_sema42.c \
  $(SDK)/drivers/lpc_gpio/fsl_gpio.c $(SDK)/drivers/inputmux/fsl_inputmux.c $(SDK)/drivers/pint/fsl_pint.c \
  $(SDK)/drivers/lpc_dma/fsl_dma.c $(SDK)/drivers/otfad/fsl_otfad.c $(SDK)/drivers/hashcrypt/fsl_hashcrypt.c \
  $(SDK)/drivers/i3c/fsl_i3c.c $(SDK)/drivers/ctimer/fsl_ctimer.c $(SDK)/drivers/dmic/fsl_dmic.c \
  $(SDK)/drivers/flexspi/fsl_flexspi.c $(SDK)/drivers/usdhc/fsl_usdhc.c $(SDK)/drivers/utick/fsl_utick.c \
  $(SDK)/drivers/ostimer/fsl_ostimer.c \
  $(addprefix $(FR)/,tasks.c queue.c list.c timers.c event_groups.c portable/MemMang/heap_4.c \
                     portable/GCC/ARM_CM33_NTZ/non_secure/port.c portable/GCC/ARM_CM33_NTZ/non_secure/portasm.c) \
  $(addprefix $(RL)/,rpmsg_lite/rpmsg_lite.c rpmsg_lite/rpmsg_queue.c virtio/virtqueue.c \
                     rpmsg_lite/porting/environment/rpmsg_env_freertos.c \
                     rpmsg_lite/porting/platform/imxrt600_m33/rpmsg_platform.c)

# Recreated sources (this directory).
OWN_SRC := $(wildcard board/*.c app/*.c libc/*.c)

SRC := $(VENDOR_SRC) $(OWN_SRC)
OBJ := $(patsubst %.c,$(OUT)/obj/%.o,$(SRC))

all: $(OBJ)

$(OUT)/obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

vendor:
	./vendor.sh

check: all
	python3 -I ../../tools/equiv_m33.py status --objs $(OUT)/obj

clean:
	rm -rf $(OUT)

.PHONY: all vendor check clean
