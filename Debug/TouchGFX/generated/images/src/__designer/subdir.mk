################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__designer/Blue_Backgrounds_main_bg_portrait_240x320px.cpp \
../TouchGFX/generated/images/src/__designer/Blue_Clocks_Backgrounds_clock_modern_background.cpp \
../TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_hour_hand.cpp \
../TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_minute_hand.cpp \
../TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_second_hand.cpp \
../TouchGFX/generated/images/src/__designer/Blue_Icons_Back_arrow_32.cpp \
../TouchGFX/generated/images/src/__designer/Blue_Icons_Home_32.cpp 

OBJS += \
./TouchGFX/generated/images/src/__designer/Blue_Backgrounds_main_bg_portrait_240x320px.o \
./TouchGFX/generated/images/src/__designer/Blue_Clocks_Backgrounds_clock_modern_background.o \
./TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_hour_hand.o \
./TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_minute_hand.o \
./TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_second_hand.o \
./TouchGFX/generated/images/src/__designer/Blue_Icons_Back_arrow_32.o \
./TouchGFX/generated/images/src/__designer/Blue_Icons_Home_32.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__designer/Blue_Backgrounds_main_bg_portrait_240x320px.d \
./TouchGFX/generated/images/src/__designer/Blue_Clocks_Backgrounds_clock_modern_background.d \
./TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_hour_hand.d \
./TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_minute_hand.d \
./TouchGFX/generated/images/src/__designer/Blue_Clocks_Hands_clock_modern_second_hand.d \
./TouchGFX/generated/images/src/__designer/Blue_Icons_Back_arrow_32.d \
./TouchGFX/generated/images/src/__designer/Blue_Icons_Home_32.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__designer/%.o: ../TouchGFX/generated/images/src/__designer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c++1y -DSTM32 -DFreeRTOS -DSTM32F4 -DSTM32F429ZI -DSTM32F429I_DISC1 -DDEBUG -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Core/Inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/test/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/CFG/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/App/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/MEM/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/BSP" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/CMSIS/Include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/ST/touchgfx/framework/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/ST/touchgfx" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/App" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated/fonts/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated/gui_generated/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated/images/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated/texts/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/gui/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/target" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/target/generated" -O1 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


