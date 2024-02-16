################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/mpu9250/Src/driver_mpu9250.c \
../Drivers/mpu9250/Src/driver_mpu9250_interface.c 

OBJS += \
./Drivers/mpu9250/Src/driver_mpu9250.o \
./Drivers/mpu9250/Src/driver_mpu9250_interface.o 

C_DEPS += \
./Drivers/mpu9250/Src/driver_mpu9250.d \
./Drivers/mpu9250/Src/driver_mpu9250_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/mpu9250/Src/%.o Drivers/mpu9250/Src/%.su: ../Drivers/mpu9250/Src/%.c Drivers/mpu9250/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"D:/FPV/STM32F4_FPV/Drivers/mpu9250/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-mpu9250-2f-Src

clean-Drivers-2f-mpu9250-2f-Src:
	-$(RM) ./Drivers/mpu9250/Src/driver_mpu9250.d ./Drivers/mpu9250/Src/driver_mpu9250.o ./Drivers/mpu9250/Src/driver_mpu9250.su ./Drivers/mpu9250/Src/driver_mpu9250_interface.d ./Drivers/mpu9250/Src/driver_mpu9250_interface.o ./Drivers/mpu9250/Src/driver_mpu9250_interface.su

.PHONY: clean-Drivers-2f-mpu9250-2f-Src

