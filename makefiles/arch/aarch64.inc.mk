ifeq (,$(CPU_MODEL))
  $(error CPU_MODEL must have been defined by the board/cpu Makefile.features)
endif

# Target triple for the build. Use arm-none-eabi if you are unsure.
TARGET_ARCH_AARCH64 ?= aarch64-none-elf
TARGET_ARCH ?= $(TARGET_ARCH_AARCH64)

# define build specific options
CFLAGS_CPU   = -v -mcpu=$(CPU) -mlittle-endian $(CFLAGS_FPU)

CFLAGS_LINK  = -ffunction-sections -fdata-sections -fno-builtin -fshort-enums
CFLAGS_DBG  ?= -ggdb -g3
CFLAGS_OPT  ?= -Os

CFLAGS += $(CFLAGS_CPU) $(CFLAGS_LINK) $(CFLAGS_DBG) $(CFLAGS_OPT)

ASFLAGS += $(CFLAGS_CPU) $(CFLAGS_DBG)
LINKFLAGS += -L$(RIOTCPU)/$(CPU)/ldscripts -L$(RIOTCPU)/cortexm_common/ldscripts
LINKER_SCRIPT ?= $(CPU_MODEL).ld
LINKFLAGS += -T$(LINKER_SCRIPT) -Wl,--fatal-warnings

LINKFLAGS += $(CFLAGS_CPU) $(CFLAGS_DBG) $(CFLAGS_OPT) -static -lgcc -nostartfiles
LINKFLAGS += -Wl,--gc-sections

# extract version inside the first parentheses
ARM_GCC_VERSION = $(shell $(TARGET_ARCH)-gcc --version | sed -n '1 s/[^(]*(\([^\)]*\)).*/\1/p')

CFLAGS += -DCPU_MODEL_$(call uppercase_and_underscore,$(CPU_MODEL))
CFLAGS += -DCPU_CORE_$(call uppercase_and_underscore,$(CPU_CORE))

MCPU ?= $(CPU_CORE)

# CPU depends on the cortex-m common module, so include it:
include $(RIOTCPU)/armv8a/Makefile.include

# Avoid overriding the default rule:
all:

# Rule to generate assembly listings from ELF files:
%.lst: %.elf
	$(OBJDUMP) $(OBJDUMPFLAGS) $< > $@
