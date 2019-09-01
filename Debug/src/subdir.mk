################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/contour.cpp \
../src/imgSeg.cpp \
../src/morphology.cpp \
../src/tess.cpp 

OBJS += \
./src/contour.o \
./src/imgSeg.o \
./src/morphology.o \
./src/tess.o 

CPP_DEPS += \
./src/contour.d \
./src/imgSeg.d \
./src/morphology.d \
./src/tess.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/opencv -I/usr/local/include/ -I/usr/include/leptonica/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


