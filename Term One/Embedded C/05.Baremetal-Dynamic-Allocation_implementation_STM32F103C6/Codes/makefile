#
#           MAKEFILE
#	Created on: Jan 07, 2024
#	Author: Mina Moheb Basally	
#

CC = arm-none-eabi-
#compiler flags
CFLAGS  = -mcpu=cortex-m3  -mthumb  -nostartfiles  -gdwarf-2  -g
#assembler flags
ASFLAGS = -mcpu=cortex-m3  -mthumb  -gdwarf-2  -g
#linker flags
LDFLAGS = -T
#objcopy flags
OCFLAGS = -O
#objdump flags
ODFLAGS = -h
#Directories to be included
INCS = -I .
LIBS =
#list of all existing (.c) files
SRC_c = $(wildcard *.c)
#same as OBJ_c = $(patsubst %.c, %.o, $SRC_c)
OBJ_c = $(SRC_c:.c=.o)
#list of all existing (.s) files
SRC_s = $(wildcard *.s)
#same as OBJ_s = $(patsubst %.s, %.o, $SRC_s)
OBJ_s = $(SRC_s:.s=.o)
#list of all existing (.ld) files
L_S   = $(wildcard *.ld)
Project_Name = Baremetal_Dynamic_Allocation_implementation_STM32F103C6_cortex-m3


#all is the default target
all:	$(Project_Name).hex
	@echo "=========================================build Completed========================================="

%.o:	%.s
	$(CC)as.exe  $(ASFLAGS)   $<  -o  $@  2> log

$(Project_Name).elf:	$(SRC_c)
	$(CC)gcc.exe  $(CFLAGS)  $(LDFLAGS)  $(L_S)  $(SRC_c)  -Wl,-Map=map_file.map  $(INCS)   -o  $@

symbols.txt:	$(Project_Name).elf
	$(CC)nm.exe   $<  >>  $@

elf_sections_headers.txt:	$(Project_Name).elf
	$(CC)objdump.exe		$(ODFLAGS)   $<  >>  $@

$(Project_Name).bin:	$(Project_Name).elf  symbols.txt  elf_sections_headers.txt
	$(CC)objcopy.exe    $(OCFLAGS)  binary   $(Project_Name).elf   $@

$(Project_Name).hex:	$(Project_Name).bin  $(Project_Name).elf
	$(CC)objcopy.exe    $(OCFLAGS)  binary   $(Project_Name).elf   $@

clean:
	rm  *.elf  *.bin  *.hex  *.map  *.txt

clean_all:
	rm  *.hex  *.bin  *.elf  *.map  *.txt  *.o
	@echo "===========================================All is clean==========================================="