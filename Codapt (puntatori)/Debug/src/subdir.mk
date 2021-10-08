################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Codapt\ (puntatori).cpp 

OBJS += \
./src/Codapt\ (puntatori).o 

CPP_DEPS += \
./src/Codapt\ (puntatori).d 


# Each subdirectory must supply rules for building sources it contributes
src/Codapt\ (puntatori).o: ../src/Codapt\ (puntatori).cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Codapt (puntatori).d" -MT"src/Codapt\ (puntatori).d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


