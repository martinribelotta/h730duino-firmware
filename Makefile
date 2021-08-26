##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [3.14.1] date: [Tue Aug 17 11:37:53 ART 2021] 
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

######################################
# target
######################################
TARGET = tst-h730
VERBOSE = y

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og

MODULES = app microrl mpaland-printf segger-rtt tinyusb

#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
Core/Src/main.c \
Core/Src/stm32h7xx_it.c \
Core/Src/stm32h7xx_hal_msp.c \
Core/Src/system_stm32h7xx.c \
Core/Src/usb_descriptors.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_ospi.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rtc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rtc_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_eth.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_eth_ex.c

# ASM sources
ASM_SOURCES =  \
startup_stm32h730xx.s

#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
OD = $(PREFIX)objdump
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
OOCD = /opt/xpack-openocd-0.11.0-1/bin/openocd
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m7

# fpu
FPU = -mfpu=fpv5-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32H730xx \
-DDATA_IN_D2_SRAM

# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-ICore/Inc \
-IDrivers/STM32H7xx_HAL_Driver/Inc \
-IDrivers/STM32H7xx_HAL_Driver/Inc/Legacy \
-IDrivers/CMSIS/Device/ST/STM32H7xx/Include \
-IDrivers/CMSIS/Include

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -Wextra -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -Wextra -fdata-sections -ffunction-sections -ffreestanding

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"

ifneq ($(strip $(VERBOSE)),n)
Q:=@
else
Q:=
endif


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32H730ZBTx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys -ffreestanding
LIBDIR = 
LDFLAGS := $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections
LDFLAGS += -Wl,--print-memory-usage

# include segger/rtt.mk tinyusb-0.10.1/tinyusb.mk mpaland-printf/printf.mk

M := $(addsuffix /module.mk, $(MODULES))

include $(M)

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin $(BUILD_DIR)/$(TARGET).lst


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/o/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/o/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/o/%.o: %.c | $(BUILD_DIR)
	@echo CC $(<F)
	$(Q)$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/o/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/o/%.o: %.s | $(BUILD_DIR)
	@echo AS $(<F)
	$(Q)$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	@echo LD $(@F)
	$(Q)$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(Q)$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@echo GEN $(@F)
	$(Q)$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@echo GEN $(@F)
	$(Q)$(BIN) $< $@	
		
$(BUILD_DIR)/%.lst: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@echo GEN $(@F)
	$(Q)$(OD) -dsx $< > $@	
	
$(BUILD_DIR):
	@mkdir -p $@/o		

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)

flash: $(BUILD_DIR)/$(TARGET).elf
	$(OOCD) -f interface/stlink-v2.cfg -f target/stm32h7x.cfg -c "reset_config none; init; reset halt; program $(BUILD_DIR)/$(TARGET).elf verify reset exit"

flash-dfu: $(BUILD_DIR)/$(TARGET).bin
	dfu-util -a 0 -s 0x08000000:leave -D $<

dfu-run: ;
	python3 pydfu.py -x

#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
