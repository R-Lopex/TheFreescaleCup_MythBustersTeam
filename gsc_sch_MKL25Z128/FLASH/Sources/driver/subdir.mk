################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/driver/driver_ADC.c" \
"../Sources/driver/driver_arm_cm0.c" \

C_SRCS += \
../Sources/driver/driver_ADC.c \
../Sources/driver/driver_arm_cm0.c \

OBJS += \
./Sources/driver/driver_ADC.o \
./Sources/driver/driver_arm_cm0.o \

C_DEPS += \
./Sources/driver/driver_ADC.d \
./Sources/driver/driver_arm_cm0.d \

OBJS_QUOTED += \
"./Sources/driver/driver_ADC.o" \
"./Sources/driver/driver_arm_cm0.o" \

C_DEPS_QUOTED += \
"./Sources/driver/driver_ADC.d" \
"./Sources/driver/driver_arm_cm0.d" \

OBJS_OS_FORMAT += \
./Sources/driver/driver_ADC.o \
./Sources/driver/driver_arm_cm0.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/driver/driver_ADC.o: ../Sources/driver/driver_ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/driver/driver_ADC.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/driver/driver_ADC.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/driver/driver_arm_cm0.o: ../Sources/driver/driver_arm_cm0.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/driver/driver_arm_cm0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/driver/driver_arm_cm0.o"
	@echo 'Finished building: $<'
	@echo ' '


