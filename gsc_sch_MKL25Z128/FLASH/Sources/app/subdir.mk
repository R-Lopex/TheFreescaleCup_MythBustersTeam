################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/app/app_GPIO.c" \
"../Sources/app/app_Servos.c" \
"../Sources/app/app_TFC.c" \

C_SRCS += \
../Sources/app/app_GPIO.c \
../Sources/app/app_Servos.c \
../Sources/app/app_TFC.c \

OBJS += \
./Sources/app/app_GPIO.o \
./Sources/app/app_Servos.o \
./Sources/app/app_TFC.o \

C_DEPS += \
./Sources/app/app_GPIO.d \
./Sources/app/app_Servos.d \
./Sources/app/app_TFC.d \

OBJS_QUOTED += \
"./Sources/app/app_GPIO.o" \
"./Sources/app/app_Servos.o" \
"./Sources/app/app_TFC.o" \

C_DEPS_QUOTED += \
"./Sources/app/app_GPIO.d" \
"./Sources/app/app_Servos.d" \
"./Sources/app/app_TFC.d" \

OBJS_OS_FORMAT += \
./Sources/app/app_GPIO.o \
./Sources/app/app_Servos.o \
./Sources/app/app_TFC.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/app/app_GPIO.o: ../Sources/app/app_GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/app_GPIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/app_GPIO.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/app_Servos.o: ../Sources/app/app_Servos.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/app_Servos.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/app_Servos.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/app_TFC.o: ../Sources/app/app_TFC.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/app/app_TFC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/app/app_TFC.o"
	@echo 'Finished building: $<'
	@echo ' '


