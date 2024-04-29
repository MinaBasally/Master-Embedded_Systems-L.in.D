/*
*          startup.c
*	Created on: Jan 03, 2024
*	Author: Mina Moheb Basally	
*/

#include "stdio.h"

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

extern int main(void);

void Reset_handler();

void Default_handler()
{
	Reset_handler();
}

void NMI_handler()        __attribute__((weak, alias ("Default_handler")));
void H_fault_handler()    __attribute__((weak, alias ("Default_handler")));
void MM_fault_handler()   __attribute__((weak, alias ("Default_handler")));
void Bus_fault_handler()  __attribute__((weak, alias ("Default_handler")));
void Usage_fault_handler()__attribute__((weak, alias ("Default_handler")));

//Reserve stack size
//Global static uninitialized array of size = 256*4=1024B=1KB (.bss section)
static unsigned long stack[256];

//Global array(vector) of constant pointers to functions(interrupt handlers) that take nothing and return nothing
//This array(vector) matches the IVT in the specs of this System On Chip [SOC]
void (* const G_arr_ptr_fn[])()__attribute__((section(".vectors"))) = {
	(void(*)()) ((unsigned long)stack + sizeof(stack)),  //stack top
	&Reset_handler,
	&NMI_handler,
	&H_fault_handler,
	&MM_fault_handler,
	&Bus_fault_handler,
	&Usage_fault_handler,
};


void Reset_handler()
{
	//Copying .data from ROM to RAM
	unsigned int data_size     = (unsigned char *)&_E_data - (unsigned char *)&_S_data;
	unsigned char *ptr_src = (unsigned char *)&_E_text;
	unsigned char *ptr_dst = (unsigned char *)&_S_data;
	unsigned int i = 0;
	for (i; i < data_size; i++) {
		*ptr_dst++ = *ptr_src++;
	}
	
	
	//initializing .bss with Zeros
	unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
	ptr_dst = (unsigned char *)&_S_bss;
	
		for (i = 0; i < bss_size; i++) {
		*ptr_dst++ = (unsigned char)0;
	}
	
	
	//jumping to main after the RAM is sorted
	main();
}
