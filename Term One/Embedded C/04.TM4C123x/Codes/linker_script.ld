/*
*       linker_script.ld
*	Created on: Jan 03, 2024
*	Author: Mina Moheb Basally	
*/


/* Entry Point */
ENTRY(Reset_handler)


MEMORY
{
	flash (RX): ORIGIN = 0x00000000, LENGTH = 128K
	sram (RWX): ORIGIN = 0x20000000, LENGTH = 20K
}


SECTIONS 
{

	.text :
	{
		*(.vectors*)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_E_text = .;
	}>flash

	.data :
	{
		_S_data = . ;
		*(.data)
		. = ALIGN(4);
		_E_data = . ;
	}>sram AT >flash

	.bss :
	{
        . = ALIGN(4);
		_S_bss = . ;
		*(.bss*)
		startup.o(.bss*)
		. = ALIGN(4);
		_E_bss = . ;
/*		. = . + 0x1000;    */ /* stack memory = 4096B/1024 = 4KB */
/*		. = ALIGN(4);      */
/*		_stack_top = . ;   */
	}>sram

}