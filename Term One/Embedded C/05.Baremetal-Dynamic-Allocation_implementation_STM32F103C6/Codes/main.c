/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mina M. Basally
 * @brief          : Main program body
 ******************************************************************************
 */

#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"
#include "platform_types.h"

 #if !defined(__SOFT_FP__) && defined(__ARM_FP)
 #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
 #endif



// Registers addresses
#define RCC_BASE		0x40021000
#define GPIOA_BASE		0x40010800
#define RCC_APB2ENR		*((vuint32_t*)(RCC_BASE + 0x00000018))		//Reset value: 0x0000 0000
#define GPIOA_CRH		*((vuint32_t*)(GPIOA_BASE + 0x00000004))
#define GPIOA_ODR		*((vuint32_t*)(GPIOA_BASE + 0x0000000C))


extern void NMI_handler(void)
{
	
}

extern void Bus_fault_handler(void)
{
	
}



// GPIOA clock enable
#define RCC_APB2ENR_IOPAEN		(0b1 << 2)

// Bit fields
typedef union {
	vuint32_t all_fields;
	struct {
		vuint32_t reserved :13;
		vuint32_t p13 :1;
	} pins;
} R_ODR_t;

volatile R_ODR_t *const R_ODR = (volatile R_ODR_t*) (GPIOA_BASE + 0x0000000C);
unsigned char g_variables[3] = {1, 2, 3};
unsigned char const g_const_variables[3] = {1, 2, 3};



void* _sbrk(int increment) {
	extern uint32_t _E_bss;   //symbol defined in linker script
	extern uint32_t _E_heap;  //symbol defined in linker script
	static unsigned char *next_heap_ptr = (unsigned char *)NULL;
	next_heap_ptr = (unsigned char *)_E_bss;
	unsigned char *prev_heap_ptr = (unsigned char *)NULL;

	
	//stack protection
	if ((next_heap_ptr + increment) > ((unsigned char *)&_E_heap))
		return (void *)NULL;
	
	
	prev_heap_ptr = next_heap_ptr;
	
	//reserving the required increment in heap memory 
	next_heap_ptr += increment;
	
	return (void *)prev_heap_ptr;
}



int main(void) {
	unsigned long i;
	RCC_APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

	while (1) {
		R_ODR->pins.p13 = 1;
		for (i = 0; i < 300000; i++) ;  //arbitrary delay

		R_ODR->pins.p13 = 0;
		for (i = 0; i < 300000; i++) ;  //arbitrary delay
	}

	volatile long *ptr = (long *)malloc(4);  //Dynamic memory allocation
	//free(ptr);
	return 0;
}