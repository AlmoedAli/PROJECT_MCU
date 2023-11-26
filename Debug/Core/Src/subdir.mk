################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
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
../Core/Src/physicalBuzzer.c \
../Core/Src/physicalSingleLed.c \
../Core/Src/softwareTimer.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tuningMode.c 

OBJS += \
./Core/Src/button.o \
./Core/Src/deviceDriver7Segment.o \
./Core/Src/deviceDriverSingleLed.o \
./Core/Src/ledWalk.o \
./Core/Src/main.o \
./Core/Src/manualMode.o \
./Core/Src/normalMode.o \
./Core/Src/physicalBuzzer.o \
./Core/Src/physicalSingleLed.o \
./Core/Src/softwareTimer.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tuningMode.o 

C_DEPS += \
./Core/Src/button.d \
./Core/Src/deviceDriver7Segment.d \
./Core/Src/deviceDriverSingleLed.d \
./Core/Src/ledWalk.d \
./Core/Src/main.d \
./Core/Src/manualMode.d \
./Core/Src/normalMode.d \
./Core/Src/physicalBuzzer.d \
./Core/Src/physicalSingleLed.d \
./Core/Src/softwareTimer.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tuningMode.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/button.cyclo ./Core/Src/button.d ./Core/Src/button.o ./Core/Src/button.su ./Core/Src/deviceDriver7Segment.cyclo ./Core/Src/deviceDriver7Segment.d ./Core/Src/deviceDriver7Segment.o ./Core/Src/deviceDriver7Segment.su ./Core/Src/deviceDriverSingleLed.cyclo ./Core/Src/deviceDriverSingleLed.d ./Core/Src/deviceDriverSingleLed.o ./Core/Src/deviceDriverSingleLed.su ./Core/Src/ledWalk.cyclo ./Core/Src/ledWalk.d ./Core/Src/ledWalk.o ./Core/Src/ledWalk.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/manualMode.cyclo ./Core/Src/manualMode.d ./Core/Src/manualMode.o ./Core/Src/manualMode.su ./Core/Src/normalMode.cyclo ./Core/Src/normalMode.d ./Core/Src/normalMode.o ./Core/Src/normalMode.su ./Core/Src/physicalBuzzer.cyclo ./Core/Src/physicalBuzzer.d ./Core/Src/physicalBuzzer.o ./Core/Src/physicalBuzzer.su ./Core/Src/physicalSingleLed.cyclo ./Core/Src/physicalSingleLed.d ./Core/Src/physicalSingleLed.o ./Core/Src/physicalSingleLed.su ./Core/Src/softwareTimer.cyclo ./Core/Src/softwareTimer.d ./Core/Src/softwareTimer.o ./Core/Src/softwareTimer.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tuningMode.cyclo ./Core/Src/tuningMode.d ./Core/Src/tuningMode.o ./Core/Src/tuningMode.su

.PHONY: clean-Core-2f-Src

