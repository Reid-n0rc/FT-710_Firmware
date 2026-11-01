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
CFLAGS := -std=gnu99 -g -Os -fno-common -ffunction-sections -fdata-sections -ffreestanding -fno-builtin $(CPUFLAGS) \
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
                     rpmsg_lite/porting/platform/imxrt600_m33/rpmsg_platform.c common/llist.c)

# Recreated sources (this directory).
OWN_SRC := $(wildcard board/*.c app/*.c libc/*.c libc/redlib/*.c)

# Hand-written assembly of the C library (libc/redlib/*.S).
OWN_ASM := $(wildcard libc/redlib/*.S)

SRC := $(VENDOR_SRC) $(OWN_SRC)
OBJ := $(patsubst %.c,$(OUT)/obj/%.o,$(SRC)) $(patsubst %.S,$(OUT)/obj/%.o,$(OWN_ASM))

# The HiFi4 images (Yaesu's DSP code, never committed), decoded by tools/bootstrap.sh into build/.
BUILD ?= ../../build
DSP_IMAGE0 ?= $(BUILD)/FT-710_IFDSP_V0101_hifi4_0_tcm.bin
DSP_IMAGE1 ?= $(BUILD)/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin
DSP_IMAGE2 ?= $(BUILD)/FT-710_IFDSP_V0101_hifi4_2_sram_data.bin

# Link order = the order of the objects in the image (src/ifdsp_m33/status.tsv addresses, T24 round 2): the
# application, rpmsg-lite, the FreeRTOS kernel, the SDK drivers by file name (the IDE project keeps them flat in one
# drivers/ folder), the board files, the C library members in the order their functions appear. The linker script
# sorts input sections by alignment (16, 4, then 2), so each group of the image is in this order.
o = $(OUT)/obj/$(1).o
SDK_ORDER := fsl_clock fsl_common fsl_common_arm fsl_ctimer fsl_dma fsl_dmic fsl_dsp fsl_flexcomm fsl_flexspi fsl_gpio \
             fsl_hashcrypt fsl_i3c fsl_iap fsl_inputmux fsl_mu fsl_ostimer fsl_otfad fsl_pint fsl_power fsl_reset \
             fsl_sctimer fsl_sema42 fsl_usart fsl_usdhc fsl_utick
LIBC_ORDER := crt redlib/memcpy redlib/memset redlib/heap redlib/csys_alloc ctype redlib/stdio_init redlib/streams \
              redlib/vsnprintf_core redlib/printf redlib/setvbuf string redlib/cdigit_value redlib/strtoul_core \
              redlib/strtoul redlib/sbrk redlib/errno redlib/cwrite_buffer redlib/fflush redlib/fseek redlib/ftell \
              redlib/check_heap redlib/file_clear_flag20 redlib/fputc redlib/cfdopen redlib/file_flush_write_buffer \
              redlib/cfclose redlib/remove redlib/cfflush1 redlib/uldivmod redlib/memcpy_body redlib/sys
LINK_OBJ := \
  $(foreach f,codec regfile uart ipc main pwm console semihost_hardfault console_frame,$(call o,app/$(f))) \
  $(foreach f,rpmsg_lite/porting/platform/imxrt600_m33/rpmsg_platform rpmsg_lite/porting/environment/rpmsg_env_freertos \
              rpmsg_lite/rpmsg_queue common/llist rpmsg_lite/rpmsg_lite virtio/virtqueue,$(call o,$(RL)/$(f))) \
  $(foreach f,portable/MemMang/heap_4 portable/GCC/ARM_CM33_NTZ/non_secure/port portable/GCC/ARM_CM33_NTZ/non_secure/portasm \
              event_groups list queue tasks timers,$(call o,$(FR)/$(f))) \
  $(foreach b,$(SDK_ORDER),$(filter %/$(b).o,$(OBJ))) \
  $(filter %/startup_mimxrt685s.o %/system_MIMXRT685S_cm33.o,$(OBJ)) \
  $(foreach f,board clock_config dsp_ipc dsp_support peripherals pin_mux,$(call o,board/$(f))) \
  $(foreach f,$(LIBC_ORDER),$(call o,libc/$(f))) \
  $(OUT)/obj/board/dsp_image.o

all: $(OBJ) $(OUT)/ifdsp_m33.elf

$(OUT)/obj/board/dsp_image.o: board/dsp_image.S $(DSP_IMAGE0) $(DSP_IMAGE1) $(DSP_IMAGE2)
	@mkdir -p $(dir $@)
	$(CC) $(CPUFLAGS) -c -DDSP_IMAGE0='"$(DSP_IMAGE0)"' -DDSP_IMAGE1='"$(DSP_IMAGE1)"' -DDSP_IMAGE2='"$(DSP_IMAGE2)"' $< -o $@

$(OUT)/ifdsp_m33.elf: $(LINK_OBJ) ifdsp_m33.ld
	$(CC) $(CPUFLAGS) -nostdlib -Wl,--gc-sections -Wl,-Map,$(OUT)/ifdsp_m33.map -T ifdsp_m33.ld $(LINK_OBJ) -lgcc -o $@
	$(CROSS)objcopy -O binary $@ $(OUT)/ifdsp_m33_0x08001000.bin
	$(CROSS)size $@

$(OUT)/obj/libc/redlib/%.o: libc/redlib/%.S
	@mkdir -p $(dir $@)
	$(CC) $(CPUFLAGS) -c $< -o $@

$(OUT)/obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

vendor:
	./vendor.sh

check: all
	python3 -I ../../tools/equiv_m33.py status --emu --objs $(OUT)/obj

clean:
	rm -rf $(OUT)

.PHONY: all vendor check clean
