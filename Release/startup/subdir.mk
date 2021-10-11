################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mkl25z4.c 

OBJS += \
./startup/startup_mkl25z4.o 

C_DEPS += \
./startup/startup_mkl25z4.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -DSDK_DEBUGCONSOLE=1 -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\board" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\source" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\drivers" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\CMSIS" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\utilities" -I"C:\Users\ujjai\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Assignment4_Buffahiti\startup" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


