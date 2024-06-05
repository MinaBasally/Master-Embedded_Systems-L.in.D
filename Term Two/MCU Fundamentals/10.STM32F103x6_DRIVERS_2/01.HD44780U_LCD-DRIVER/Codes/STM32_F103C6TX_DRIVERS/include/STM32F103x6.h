/*
 *  STM32F103x6.h
 *
 *   Created on: Apr 11, 2024
 *       Author: Mina
 *
 */

#ifndef STM32F103X6_H_
#define STM32F103X6_H_







//---------------------------------------------------------------------------------------------------
//	Include
//---------------------------------------------------------------------------------------------------
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"



//===================================================================================================================



//---------------------------------------------------------------------------------------------------
//	Base Addresses for Memories
//---------------------------------------------------------------------------------------------------
#define FLASH_MEMORY_BASE 							0x08000000UL
#define SYSTEM_MEMORY_BASE 							0x1FFFF000UL
#define SRAM_MEMORY_BASE 							0x20000000UL
#define PERIPHERALS_BASE 							0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE  		0xE0000000UL



//---------------------------------------------------------------------------------------------------
//	Base Addresses for AHB Peripherals
//---------------------------------------------------------------------------------------------------

//	RCC *******
#define RCC_BASE 							0x40021000UL
//#define RCC_BASE              				(Peripherals_BASE + 0x00021000UL)



//---------------------------------------------------------------------------------------------------
//	Base Addresses for APB2 Peripherals
//---------------------------------------------------------------------------------------------------

//	GPIO *******
//	ALL [A]&[B] Port Pins are externally-routed in LQFP48-Package
#define GPIOA_BASE 							0x40010800UL
#define GPIOB_BASE 							0x40010C00UL
//	NOT ALL [C]&[D] Port Pins are externally-routed in LQFP48-Package
#define GPIOC_BASE 							0x40011000UL
#define GPIOD_BASE 							0x40011400UL
//	Port [E] Pins ARE NOT externally-routed in LQFP48-Package
#define GPIOE_BASE 							0x40011800UL


//	EXTI *******
#define EXTI_BASE 							0x40010400UL


//	AFIO *******
#define AFIO_BASE 							0x40010000UL



//---------------------------------------------------------------------------------------------------
//	Base Addresses for APB1 Peripherals
//---------------------------------------------------------------------------------------------------



//===================================================================================================================



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Peripherals Registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Peripheral Registers: GPIO *******
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t	CRL;
	volatile uint32_t	CRH;
	volatile uint32_t	IDR;
	volatile uint32_t	ODR;
	volatile uint32_t	BSRR;
	volatile uint32_t	BRR;
	volatile uint32_t	LCKR;
} GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Peripheral Registers: RCC *******
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
} RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Peripheral Registers: EXTI *******
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Peripheral Registers: AFIO *******
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	//volatile uint32_t EXTICR2;
	//volatile uint32_t EXTICR3;
	//volatile uint32_t EXTICR4;
	uint32_t RESERVED0;
	volatile uint32_t MAPR2;
} AFIO_TypeDef;



//===================================================================================================================



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//	GPIO *******
#define GPIOA			((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB			((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC			((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD			((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE			((GPIO_TypeDef *)GPIOE_BASE)


//	RCC *******
#define RCC				((RCC_TypeDef *)RCC_BASE)


//	EXTI *******
#define EXTI			((EXTI_TypeDef *)EXTI_BASE)


//	AFIO *******
#define AFIO			((AFIO_TypeDef *)AFIO_BASE)



//===================================================================================================================



/*
 * ======================================================================================================
 * 							                  CORTEX_M3_NVIC
 * ======================================================================================================
 */
//--------------------------------------------------------------------------------------------------
//	NVIC Base Address
//--------------------------------------------------------------------------------------------------
#define NVIC_BASE		0xE000E100UL



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Peripheral Registers: NVIC *******
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_ISER0  *((volatile uint32_t *)(NVIC_BASE + 0x0))
#define NVIC_ISER1  *((volatile uint32_t *)(NVIC_BASE + 0x4))
#define NVIC_ISER2  *((volatile uint32_t *)(NVIC_BASE + 0x8))

#define NVIC_ICER0  *((volatile uint32_t *)(NVIC_BASE + 0x80))
#define NVIC_ICER1  *((volatile uint32_t *)(NVIC_BASE + 0x84))
#define NVIC_ICER2  *((volatile uint32_t *)(NVIC_BASE + 0x88))



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	NVIC IRQ Enable/Disable:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Enable
#define NVIC_IRQ6_EXTI0_Enable 			(NVIC_ISER0 |= 1 << 6)
#define NVIC_IRQ7_EXTI1_Enable 			(NVIC_ISER0 |= 1 << 7)
#define NVIC_IRQ8_EXTI2_Enable 			(NVIC_ISER0 |= 1 << 8)
#define NVIC_IRQ9_EXTI3_Enable 			(NVIC_ISER0 |= 1 << 9)
#define NVIC_IRQ10_EXTI4_Enable 		(NVIC_ISER0 |= 1 << 10)
#define NVIC_IRQ23_EXTI9_5_Enable 		(NVIC_ISER0 |= 1 << 23)
#define NVIC_IRQ40_EXTI15_10_Enable 	(NVIC_ISER1 |= 1 << 8)

//Disable
#define NVIC_IRQ6_EXTI0_Disable 		(NVIC_ICER0 |= 1 << 6)
#define NVIC_IRQ7_EXTI1_Disable 		(NVIC_ICER0 |= 1 << 7)
#define NVIC_IRQ8_EXTI2_Disable 		(NVIC_ICER0 |= 1 << 8)
#define NVIC_IRQ9_EXTI3_Disable 		(NVIC_ICER0 |= 1 << 9)
#define NVIC_IRQ10_EXTI4_Disable 		(NVIC_ICER0 |= 1 << 10)
#define NVIC_IRQ23_EXTI9_5_Disable 		(NVIC_ICER0 |= 1 << 23)
#define NVIC_IRQ40_EXTI15_10_Disable 	(NVIC_ICER1 |= 1 << 8)



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Clock Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	GPIO *******
#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |= (0b1<<2))
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |= (0b1<<3))
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |= (0b1<<4))
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |= (0b1<<5))
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |= (0b1<<6))


//	AFIO *******
#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR |= (0b1<<0))







#endif /* STM32F103X6_H_ */
