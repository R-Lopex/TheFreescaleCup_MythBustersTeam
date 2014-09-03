################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/app/app_GPIO.c" \

C_SRCS += \
../Sources/app/app_GPIO.c \

OBJS += \
./Sources/app/app_GPIO.o \

C_DEPS += \
./Sources/app/app_GPIO.d \

OBJS_QUOTED += \
"./Sources/app/app_GPIO.o" \

C_DEPS_QUOTED += \
"./Sources/app/app_GPIO.d" \

OBJS_OS_FORMAT += \
./Sources/app/app_GPIO.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/app/app_GPIO.o: ../Sources/app/app_GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/app_GPIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/app_GPIO.o"
	@echo 'Finished building: $<'
	@echo ' '


