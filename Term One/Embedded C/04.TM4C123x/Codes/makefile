#
#          MAKEFILE
#	Created on: Jan 03, 2024
#	Author: Mina Moheb Basally	
#

CC = arm-none-eabi-
#compiler flags
CFLAGS  = -c  -mcpu=cortex-m4  -mthumb  -nostartfiles  -gdwarf-2  -g
#assembler flags
ASFLAGS =     -mcpu=cortex-m4  -mthumb  -gdwarf-2  -g
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
Project_Name = LED_toggle_TM4C123x_cortex-m4


#all is the default target
all:	$(Project_Name).hex
	@echo "=========================================build Completed========================================="

%.o:	%.s
	$(CC)as.exe  $(ASFLAGS)   $<  -o  $@  2> log

%.o:	%.c
	$(CC)gcc.exe  $(CFLAGS)  $(INCS)   $<  -o  $@

$(Project_Name).elf:	$(OBJ_s)  $(OBJ_c)  $(L_S)
	$(CC)ld.exe         $(LDFLAGS)  $(L_S)  $(OBJ_s)  $(OBJ_c)  $(LIBS)   -o  $@   -Map=map_file.map
	cp					$(Project_Name).elf   $(Project_Name).axf

symbols.txt:	$(Project_Name).elf
	$(CC)nm.exe    $<  >>  $@

elf_sections_headers.txt:	$(Project_Name).elf
	$(CC)objdump.exe		$(ODFLAGS)   $<  >>  $@

$(Project_Name).bin:	$(Project_Name).elf  symbols.txt  elf_sections_headers.txt
	$(CC)objcopy.exe    $(OCFLAGS)  binary   $(Project_Name).elf   $@

$(Project_Name).hex:	$(Project_Name).elf  $(Project_Name).bin
	$(CC)objcopy.exe    $(OCFLAGS)  binary   $(Project_Name).elf   $@

clean:
	rm  *.elf  *.axf  *.bin  *.hex  *.map  *.txt

clean_all:
	rm  *.hex  *.bin  *.axf  *.elf  *.map  *.txt  *.o
	@echo "===========================================All is clean==========================================="	