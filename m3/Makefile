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
# Simple makefile for the cortex-M0+ build system
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#
#------------------------------------------------------------------------------
include sources.mk

# Target NAME
TARGET = c1m3
# Compiler Flags Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LINKER_FILE = msp432p401r.lds
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
# Architecture Specific Flags
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs
CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)
# GNU Utilities
SIZE = arm-none-eabi-size
OBJECTDUMP = arm-none-eabi-objdump

# Files from SOURCE
OBJECTS := $(SRCS:.c=.o)
PREPROCESSED := $(SRCS:.c=.i)
ASSEMBLY := $(SRCS:.c=.asm)
DEPENDENCIES := $(SRCS:.c=.d)

# It helps to delete files when cleaning
GENERATED_FILES = *.asm *.i *.o *.d *.map

# Targets
%.i: %.c
	$(CC) $(INC) -E $< $(CFLAGS) -o $@

%.asm: %.c
	$(CC) $(INC) -S $< $(CFLAGS) -o $@

$(TARGET).asm: $(TARGET).out
	$(OBJECTDUMP) -d $(TARGET).out >> $@

%.o: %.c
	$(CC) $(INC) -c $< $(CFLAGS) -o $@

%.d: %.c
	$(CC) $(INC) -M $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJECTS)
	$(CC) $(INC) $(OBJECTS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out $(TARGET).asm

$(TARGET).out: $(OBJECTS) $(DEPENDENCIES)
	$(CC) $(INC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)
	$(SIZE) -Atd ./$(TARGET).out
	$(SIZE) ./$(TARGET).out
	
.PHONY: clean
clean: 
	rm -f $(OBJECTS) $(PREPROCESSED) $(ASSEMBLY) $(DEPENDENCIES) $(GENERATED_FILES) $(TARGET).out