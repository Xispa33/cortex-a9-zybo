################################################################################
# Automatically-generated file. Do not edit!
################################################################################

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
#-include src/subdir.mk
#-include subdir.mk
-include objects.mk
WORKSPACE_DIR = $(PWD)/../../
include ../../paths.mk

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
img.elf.size \

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
${APP_DIR}/src/main.c \
${APP_DIR}/src/xscugic_example.c \
${APP_DIR}/src/platform.c 

OBJS += \
${BUILD_STAGE_1}/main.o \
${BUILD_STAGE_1}/xscugic_example.o \
${BUILD_STAGE_1}/platform.o 

C_DEPS += \
${BUILD_STAGE_1}/main.d \
${BUILD_STAGE_1}/xscugic_example.d \
${BUILD_STAGE_1}/platform.d 

# All Target
all: pre-build main-build

# Main-build Target
main-build: img.elf secondary-outputs

# Each subdirectory must supply rules for building sources it contributes
${BUILD_STAGE_1}/%.o: ${APP_DIR}/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../bsp/ps7_cortexa9_0/include -I../inc -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Tool invocations
img.elf: $(OBJS) ${APP_DIR}/src/lscript.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM v7 gcc linker'
	arm-none-eabi-gcc -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -Wl,-build-id=none -specs=Xilinx.spec -Wl,-T -Wl,${APP_DIR}/src/lscript.ld -L${BUILD_STAGE_1}/bsp/ -o "${BUILD_STAGE_2}/img.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

img.elf.size: img.elf
	@echo 'Invoking: ARM v7 Print Size'
	arm-none-eabi-size ${BUILD_STAGE_2}/img.elf  |tee "${BUILD_STAGE_2}/img.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(S_UPPER_DEPS)$(C_DEPS)$(ELFSIZE) img.elf
	-@echo ' '

pre-build:
	-a9-linaro-pre-build-step
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build
