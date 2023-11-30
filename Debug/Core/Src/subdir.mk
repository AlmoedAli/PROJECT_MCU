################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/button.c \
../Core/Src/deviceDriver7Segment.c \
../Core/Src/deviceDriverSingleLed.c \
../Core/Src/ledWalk.c \
../Core/Src/main.c \
../Core/Src/manualMode.c \
../Core/Src/normalMode.c \
../Core/Src/physical7Segment.c \
../Core/Src/physicalSingleLed.c \
../Core/Src/softwareTimer.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tuningMode.c \
../Core/Src/uart.c 

OBJS += \
./Core/Src/button.o \
./Core/Src/deviceDriver7Segment.o \
./Core/Src/deviceDriverSingleLed.o \
./Core/Src/ledWalk.o \
./Core/Src/main.o \
./Core/Src/manualMode.o \
./Core/Src/normalMode.o \
./Core/Src/physical7Segment.o \
./Core/Src/physicalSingleLed.o \
./Core/Src/softwareTimer.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tuningMode.o \
./Core/Src/uart.o 

C_DEPS += \
./Core/Src/button.d \
./Core/Src/deviceDriver7Segment.d \
./Core/Src/deviceDriverSingleLed.d \
./Core/Src/ledWalk.d \
./Core/Src/main.d \
./Core/Src/manualMode.d \
./Core/Src/normalMode.d \
./Core/Src/physical7Segment.d \
./Core/Src/physicalSingleLed.d \
./Core/Src/softwareTimer.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tuningMode.d \
./Core/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

