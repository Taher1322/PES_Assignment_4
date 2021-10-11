################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Assignment4_Buffahiti.c \
../source/TSI.c \
../source/Timer.c \
../source/button_int.c \
../source/led.c \
../source/mtb.c \
../source/pwm.c \
../source/semihost_hardfault.c \
../source/state_machine.c 

OBJS += \
./source/Assignment4_Buffahiti.o \
./source/TSI.o \
./source/Timer.o \
./source/button_int.o \
./source/led.o \
./source/mtb.o \
./source/pwm.o \
./source/semihost_hardfault.o \
./source/state_machine.o 

C_DEPS += \
./source/Assignment4_Buffahiti.d \
./source/TSI.d \
./source/Timer.d \
./source/button_int.d \
./source/led.d \
./source/mtb.d \
./source/pwm.d \
./source/semihost_hardfault.d \
./source/state_machine.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=1 -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\board" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\source" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\drivers" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\CMSIS" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\utilities" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


