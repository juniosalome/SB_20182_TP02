################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/montador/lista.c \
../src/montador/main.c \
../src/montador/montador.c 

OBJS += \
./src/montador/lista.o \
./src/montador/main.o \
./src/montador/montador.o 

C_DEPS += \
./src/montador/lista.d \
./src/montador/main.d \
./src/montador/montador.d 


# Each subdirectory must supply rules for building sources it contributes
src/montador/%.o: ../src/montador/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


