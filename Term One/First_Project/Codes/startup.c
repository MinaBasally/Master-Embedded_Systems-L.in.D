/*
*          startup.c
*	Created on: Jan 30, 2024
*	Author: Mina Moheb Basally	
*/

#include "stdint.h"
#include "stdbool.h"
#include "platform_types.h"

extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern uint32_t _stack_top;

#define STACK_TOP  _stack_top

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


uint32_t vectors[]__attribute__((section(".vectors"))) = {
	(uint32_t) &STACK_TOP,
	(uint32_t) &Reset_handler,
	(uint32_t) &NMI_handler,
	(uint32_t) &H_fault_handler,
	(uint32_t) &MM_fault_handler,
	(uint32_t) &Bus_fault_handler,
	(uint32_t) &Usage_fault_handler,
};


void Reset_handler()
{
	//Copying data from ROM to RAM
	uint32_t data_size = (unsigned char *)&_E_data - (unsigned char *)&_S_data;
	unsigned char *ptr_src = (unsigned char *)&_E_text;
	unsigned char *ptr_dst = (unsigned char *)&_S_data;
	
	uint32_t i = 0;
	for (i; i < data_size; i++) {
		*ptr_dst++ = *ptr_src++;
	}
	
	
	// initializing .bss with Zeros
	uint32_t bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
	ptr_dst = (unsigned char *)&_S_bss;
	
		for (i = 0; i < bss_size; i++) {
		*ptr_dst++ = (unsigned char)0;
	}
	
	
	//jumping to main after the RAM is sorted
	main();
}
