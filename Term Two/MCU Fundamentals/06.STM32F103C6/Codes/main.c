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

// GPIOA Registers
#define GPIOA_BASE		0x40010800
#define GPIOA_CRL		*((vuint32_t*)(GPIOA_BASE + 0x00))		//Reset value: 0x4444 4444 (reset state -> floating input)
#define GPIOA_CRH		*((vuint32_t*)(GPIOA_BASE + 0x04))		//Reset value: 0x4444 4444 (reset state -> floating input)
#define GPIOA_IDR		*((vuint32_t*)(GPIOA_BASE + 0x08))
#define GPIOA_ODR		*((vuint32_t*)(GPIOA_BASE + 0x0C))

// GPIOB Registers
#define GPIOB_BASE		0x40010C00
#define GPIOB_CRL		*((vuint32_t*)(GPIOB_BASE + 0x00))		//Reset value: 0x4444 4444 (reset state -> floating input)
#define GPIOB_CRH		*((vuint32_t*)(GPIOB_BASE + 0x04))		//Reset value: 0x4444 4444 (reset state -> floating input)
#define GPIOB_IDR		*((vuint32_t*)(GPIOB_BASE + 0x08))
#define GPIOB_ODR		*((vuint32_t*)(GPIOB_BASE + 0x0C))



void clock_init() {
	// GPIOA clock enable
	RCC_APB2ENR |= (0b1 << 2);
	// GPIOB clock enable
	RCC_APB2ENR |= (0b1 << 3);
}



void GPIO_init() {
	GPIOA_CRH = 0 ;
	GPIOA_CRL = 0 ;
	GPIOA_ODR = 0 ;
	GPIOB_CRH = 0 ;
	GPIOB_CRL = 0 ;
	GPIOB_ODR = 0 ;

	/////////////////////////
	/////////////////////////

	// Configuring GPIOA p1 to be a Floating Input (0b0100)
	GPIOA_CRL &= ~(0b1 << 4);
	GPIOA_CRL &= ~(0b1 << 5);
	GPIOA_CRL |= (0b1 << 6);
	GPIOA_CRL &= ~(0b1 << 7);
	// Configuring GPIOA p13 to be a Floating Input (0b0100)
	GPIOA_CRH &= ~(0b1 << 20);
	GPIOA_CRH &= ~(0b1 << 21);
	GPIOA_CRH |= (0b1 << 22);
	GPIOA_CRH &= ~(0b1 << 23);

	/////////////////////////
	/////////////////////////

	// Configuring GPIOB p1 to be a Push-Pull Output (0b0001)
	GPIOB_CRL |= (0b1 << 4);
	GPIOB_CRL &= ~(0b1 << 5);
	GPIOB_CRL &= ~(0b1 << 6);
	GPIOB_CRL &= ~(0b1 << 7);
	// Configuring GPIOB p13 to be a Push-Pull Output (0b0001)
	GPIOB_CRH |= (0b1 << 20);
	GPIOB_CRH &= ~(0b1 << 21);
	GPIOB_CRH &= ~(0b1 << 22);
	GPIOB_CRH &= ~(0b1 << 23);

	/////////////////////////
	/////////////////////////

	//Putting ZERO Potential Difference across both LEDs connected to PB1 & PB13
	GPIOB_ODR |= (0b1 << 1);
	GPIOB_ODR |= (0b1 << 13);
}



int main(void) {
	volatile unsigned int i;
	clock_init();
	GPIO_init();

	while(1) {
		// Toggling GPIOB p1 ONCE every time the button gets closed(switched ON) [Single pressing]
		// Button is connected to a pull-up resistor (PUR)
		if (((GPIOA_IDR & (0b1 << 1)) >> 1) == 0) {
			GPIOB_ODR ^= (0b1 << 1);
			while (((GPIOA_IDR & (0b1 << 1)) >> 1) == 0) ;
		}
		// Toggling GPIOB p13 Non-Stop every time the button gets closed(switched ON) [Multi-pressing]
		// Button is connected to a pull-down resistor (PDR)
		if (((GPIOA_IDR & (0b1 << 13)) >> 13) == 1) {
			GPIOB_ODR ^= (0b1 << 13);
			for (i = 0; i < 1000; i++) ;  //arbitrary delay
		}
	}

	return 0;
}
