################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Hardware.c \
../Core/Src/HardwareIRQs.c \
../Core/Src/main.c 

OBJS += \
./Core/Src/Hardware.o \
./Core/Src/HardwareIRQs.o \
./Core/Src/main.o 

C_DEPS += \
./Core/Src/Hardware.d \
./Core/Src/HardwareIRQs.d \
./Core/Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Hardware.d ./Core/Src/Hardware.o ./Core/Src/Hardware.su ./Core/Src/HardwareIRQs.d ./Core/Src/HardwareIRQs.o ./Core/Src/HardwareIRQs.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su

.PHONY: clean-Core-2f-Src

