################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
../Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
../Middlewares/Third_Party/FreeRTOS/Source/list.c \
../Middlewares/Third_Party/FreeRTOS/Source/queue.c \
../Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c \
../Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
../Middlewares/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/croutine.o \
./Middlewares/Third_Party/FreeRTOS/Source/event_groups.o \
./Middlewares/Third_Party/FreeRTOS/Source/list.o \
./Middlewares/Third_Party/FreeRTOS/Source/queue.o \
./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o \
./Middlewares/Third_Party/FreeRTOS/Source/tasks.o \
./Middlewares/Third_Party/FreeRTOS/Source/timers.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/croutine.d \
./Middlewares/Third_Party/FreeRTOS/Source/event_groups.d \
./Middlewares/Third_Party/FreeRTOS/Source/list.d \
./Middlewares/Third_Party/FreeRTOS/Source/queue.d \
./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d \
./Middlewares/Third_Party/FreeRTOS/Source/tasks.d \
./Middlewares/Third_Party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c11 -DSTM32 -DFreeRTOS -DSTM32F4 -DSTM32F429ZI -DSTM32F429I_DISC1 -DDEBUG -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Core/Inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/test/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/CFG/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/MEM/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/BSP" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/CMSIS/Include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/App" -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


