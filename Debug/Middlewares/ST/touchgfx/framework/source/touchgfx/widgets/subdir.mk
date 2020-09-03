################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AbstractButton.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AnimatedImage.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AnimationTextureMapper.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Box.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/BoxWithBorder.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Button.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ButtonWithIcon.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ButtonWithLabel.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Image.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Keyboard.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/PixelDataWidget.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/RadioButton.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/RepeatButton.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ScalableImage.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/SnapshotWidget.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextArea.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextAreaWithWildcard.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextureMapper.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TiledImage.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ToggleButton.cpp \
../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TouchArea.cpp 

OBJS += \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AbstractButton.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AnimatedImage.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AnimationTextureMapper.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Box.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/BoxWithBorder.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Button.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ButtonWithIcon.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ButtonWithLabel.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Image.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Keyboard.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/PixelDataWidget.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/RadioButton.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/RepeatButton.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ScalableImage.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/SnapshotWidget.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextArea.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextAreaWithWildcard.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextureMapper.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TiledImage.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ToggleButton.o \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TouchArea.o 

CPP_DEPS += \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AbstractButton.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AnimatedImage.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/AnimationTextureMapper.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Box.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/BoxWithBorder.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Button.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ButtonWithIcon.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ButtonWithLabel.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Image.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/Keyboard.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/PixelDataWidget.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/RadioButton.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/RepeatButton.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ScalableImage.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/SnapshotWidget.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextArea.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextAreaWithWildcard.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TextureMapper.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TiledImage.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/ToggleButton.d \
./Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/TouchArea.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/%.o: ../Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c++1y -DSTM32 -DFreeRTOS -DSTM32F4 -DSTM32F429ZI -DSTM32F429I_DISC1 -DDEBUG -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Core/Inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/test/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/CFG/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/App/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/MEM/inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/BSP" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/CMSIS/Include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Drivers/STM32F4xx_HAL_Driver/Inc" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/ST/touchgfx/framework/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/ST/touchgfx" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/App" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated/fonts/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated/gui_generated/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated/images/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated/texts/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/generated" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/gui/include" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/target" -I"E:/Embedded/Projects/STM/STM32F429I_Clock/TouchGFX/target/generated" -O1 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


