/*
*      linker_script.ld
*	Created on: Dec 25, 2023
*	Author: Mina Moheb Basally	
*/

ENTRY(reset)


MEMORY
{
	Mem (rwx): ORIGIN = 0x00000000, LENGTH = 64M
}


SECTIONS 
{

. = 0x10000;
.startup . :
{
startup.o(.text)
}>Mem

.text :
{
*(.text) *(.rodata)
}>Mem

.data :
{
*(.data)
}>Mem

.bss :
{
*(.bss) *(.comment)
}>Mem

. = . + 0x1000;  /* stack memory = 4096B/1024 = 4KB */
stack_top = . ;

}