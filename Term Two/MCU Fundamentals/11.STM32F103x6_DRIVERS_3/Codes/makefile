################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32_F103C6TX_DRIVERS/GPIO/subdir.mk
-include STM32_F103C6TX_DRIVERS/EXTI/subdir.mk
-include OFF-CHIP-DEVICES_DRIVERS/SEVEN_SEGMENT_DRIVER/subdir.mk
-include OFF-CHIP-DEVICES_DRIVERS/HD44780U-LCD_DRIVER/subdir.mk
-include OFF-CHIP-DEVICES_DRIVERS/4x4-KEYPAD_DRIVER/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := DRIVERS4
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
DRIVERS4.elf \

MAP_FILES += \
DRIVERS4.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
DRIVERS4.list \

OBJCOPY_HEX += \
DRIVERS4.hex \

OBJCOPY_BIN += \
DRIVERS4.bin \


# All Target
all: main-build

# Main-build Target
main-build: DRIVERS4.elf secondary-outputs

# Tool invocations
DRIVERS4.elf DRIVERS4.map: $(OBJS) $(USER_OBJS) C:\Users\Mina\STM32CubeIDE\workspace_1.14.0\Embedded_C_course\DRIVERS4\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc  -gdwarf-2 -o "DRIVERS4.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Mina\STM32CubeIDE\workspace_1.14.0\Embedded_C_course\DRIVERS4\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="DRIVERS4.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

DRIVERS4.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "DRIVERS4.list"
	@echo 'Finished building: $@'
	@echo ' '

DRIVERS4.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "DRIVERS4.hex"
	@echo 'Finished building: $@'
	@echo ' '

DRIVERS4.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "DRIVERS4.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) DRIVERS4.bin DRIVERS4.elf DRIVERS4.hex DRIVERS4.list DRIVERS4.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
