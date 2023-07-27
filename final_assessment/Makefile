#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
#------------------------------------------------------------------------------
# Simple makefile to support multiple build platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#				<FILE>.o - Builds <FILE>.o object file
#	   			<FILE>.i - Generate the preprocessed output
#      			<FILE>.asm - Generate assembly output
#      			compile-all : Compiles all source files
#	   			build: Build and link all source files
#	   			clean: Removes all generated files.
# 
# Platform Overrides:
# 					HOST: Uses gcc compiler (default)
#					MSP432: Uses arm-none-eabi-gcc compiler (cross-compiled)
#
# @author: Lucas Cunha @Lucasgb7
# @date: July 26 2023
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
VERBOSE = ENABLE
COURSE = COURSE1

# Platform Checking
ifeq ($(PLATFORM), MSP432)
#	Compiler Flags Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LINKER_FILE = msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
#	Architecture Specific Flags 
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	FPU = fpv4-sp-d16
	FLOAT_ABI = hard
	ARMFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfpu=$(FPU) -mfloat-abi=$(FLOAT_ABI) -mthumb
#	GNU Utilities
	SIZE = arm-none-eabi-size
	OBJECTDUMP = arm-none-eabi-objdump

else
# 	Compiler Flags Defines
	CC = gcc 
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
#	GNU Utilities
	SIZE = size
	OBJECTDUMP = objdump

endif

ifeq ($(VERBOSE), ENABLE)
	CPPFLAGS += -DVERBOSE
endif

ifeq ($(COURSE), COURSE1)
	CPPFLAGS += -DCOURSE1
endif

# Compiler TARGET and Compiler (Generic) Flags
TARGET = final_assessment
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(CPPFLAGS) $(ARMFLAGS) 

# Files from SOURCE
OBJECTS := $(SOURCES:.c=.o)
PREPROCESSED := $(SOURCES:.c=.i)
ASSEMBLY := $(SORUCES:.c=.asm)
DEPENDENCIES := $(SOURCES:.c=.d)

# It helps to delete files when cleaning
GENERATED_FILES =*.asm *.i *.o *.d *.map

# Targets
%.i: %.c
	$(CC) $(INCLUDES) -E $< $(CFLAGS) -o $@

%.asm: %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJECTDUMP) -d $(TARGET).out >> $@

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJECTS)
	$(CC) $(INCLUDES) $(OBJECTS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out $(TARGET).asm

$(TARGET).out: $(OBJECTS) $(DEPENDENCIES)
	$(CC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)
	$(SIZE) -Atd ./$(TARGET).out
	$(SIZE) ./$(TARGET).out
	
.PHONY: clean
clean: 
	rm -f $(OBJECTS) $(PREPROCESSED) $(ASSEMBLY) $(DEPENDENCIES) $(GENERATED_FILES) $(TARGET).out