/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mina M. Basally
 * @brief          : Main program body
 ******************************************************************************
 */

#include "stdint.h"
#include "stdbool.h"
#include "platform_types.h"

 #if !defined(__SOFT_FP__) && defined(__ARM_FP)
 #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
 #endif



// RCC Registers
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		*((vuint32_t*)(RCC_BASE + 0x18))		//Reset value: 0x0000 0000
// GPIOA clock-enable bit
#define RCC_APB2ENR_IOPAEN		(0b1 << 2)

// GPIOA Registers
#define GPIOA_BASE		0x40010800
#define GPIOA_CRL		*((vuint32_t*)(GPIOA_BASE + 0x00))		//Reset value: 0x4444 4444 (p0 reset state -> floating input)
#define GPIOA_CRH		*((vuint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_ODR		*((vuint32_t*)(GPIOA_BASE + 0x0C))

// AFIO Registers
#define AFIO_BASE		0x40010000
#define AFIO_EXTICR1	*((vuint32_t*)(AFIO_BASE + 0x08))		//Reset value: 0x0000

// EXTI Registers
#define EXTI_BASE		0x40010400
#define EXTI_IMR		*((vuint32_t*)(EXTI_BASE + 0x00))		//Reset value: 0x0000 0000
#define EXTI_RTSR		*((vuint32_t*)(EXTI_BASE + 0x08))		//Reset value: 0x0000 0000
#define EXTI_PR			*((vuint32_t*)(EXTI_BASE + 0x14))		//Reset value: 0x0000 0000

// NVIC Registers
#define NVIC_ISER0		*((vuint32_t*)(0xE000E100))				//Reset value: 0x0000 0000



// Bit fields
typedef union {
	vuint32_t all_fields;
	struct {
		//vuint32_t p0 :1;
		vuint32_t reserved :13;
		vuint32_t p13 :1;
	} pins;
} R_ODR_t;

volatile R_ODR_t *const R_ODR = (volatile R_ODR_t*) (GPIOA_BASE + 0x0C);



void clock_init() {
	// GPIOA clock enable
	RCC_APB2ENR |= RCC_APB2ENR_IOPAEN;
}



void GPIOA_init() {
	// Configuring p13 to be an output
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
}



void EXTI0_init() {
	// Unmasking Interrupt request from Line 0
	EXTI_IMR  |= (0b1 << 0);

	// Enabling Rising Trigger (for Event and Interrupt) for input line 0.
	EXTI_RTSR |= (0b1 << 0);
}



void NVIC_init() {
	// Enabling Interrupt request from EXTI0
	NVIC_ISER0  |= (0b1 << 6);
}



/* EXTI Line0 interrupt handler */
void EXTI0_IRQHandler() {
	// Toggle pin 13
	R_ODR->pins.p13 ^= (0b1);

	// Write 1 to clear The Pending Status
	EXTI_PR   |= (0b1 << 0);
}



int main(void) {
	clock_init();
	GPIOA_init();
	EXTI0_init();
	NVIC_init();

	while(1) ;

	return 0;
}
