/*
 *  STM32F103x6_EXTI_Driver.h
 *
 *   Created on: Apr 22, 2024
 *       Author: Mina
 *
 */

#ifndef STM32F103X6_EXTI_DRIVER_H_
#define STM32F103X6_EXTI_DRIVER_H_







/*
 * ==========================================================================================
 * 										    Include
 * ==========================================================================================
 */
#include "STM32F103x6.h"
#include "STM32F103x6_GPIO_Driver.h"



/*
 * ==========================================================================================
 * 								    Configuration Structure
 * ==========================================================================================
 */
typedef struct {
	GPIO_TypeDef * 	EXTI_Port;
	uint16_t 		PinNumber;
	uint8_t			EXTI_LineNumber;
	uint8_t			IRQ_Number;
} EXTI_GPIO_Mapping_t;



typedef struct {
	EXTI_GPIO_Mapping_t 	EXTI_Lx_Pyx;					/*Specify the External interrupt GPIO mapping.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 *This parameter must be a value of @ref EXTI_Define*/

	uint8_t 				EXTI_TriggerCase;				/*Specify the trigger mode (Rising , Falling or Both).
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 *This parameter must be a value of @ref EXTI_Trigger_Define*/

	uint8_t 				IRQ_EN;							/*Enable or Disable the EXTI IRQ (That will enable/disable the IRQ Mask in both EXTI and NVIC Interrupt controller.
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 *This parameter must be a value of @ref EXTI_IRQ_Define*/

	void (* P_IRQ_CallBack)(void);							/*Carries the address of the C function that will be called on interrupt (in case the IRQ is enabled)*/

} EXTI_PinConfig_t;



/*
 * ==========================================================================================
 * 							            Generic Macros
 * ==========================================================================================
 */
//	EXTI Lines
#define EXTI_L0				0
#define EXTI_L1				1
#define EXTI_L2				2
#define EXTI_L3				3
#define EXTI_L4				4
#define EXTI_L5				5
#define EXTI_L6				6
#define EXTI_L7				7
#define EXTI_L8				8
#define EXTI_L9				9
#define EXTI_L10			10
#define EXTI_L11			11
#define EXTI_L12			12
#define EXTI_L13			13
#define EXTI_L14			14
#define EXTI_L15			15



//	EXTI IRQs Map (Based On the CPU's IVT)
#define EXTI_L0_IRQ				6
#define EXTI_L1_IRQ				7
#define EXTI_L2_IRQ				8
#define EXTI_L3_IRQ				9
#define EXTI_L4_IRQ				10
#define EXTI_L5_IRQ				23
#define EXTI_L6_IRQ				23
#define EXTI_L7_IRQ				23
#define EXTI_L8_IRQ				23
#define EXTI_L9_IRQ				23
#define EXTI_L10_IRQ			40
#define EXTI_L11_IRQ			40
#define EXTI_L12_IRQ			40
#define EXTI_L13_IRQ			40
#define EXTI_L14_IRQ			40
#define EXTI_L15_IRQ			40



/*
 * ==========================================================================================
 * 							    Macros Configuration References
 * ==========================================================================================
 */
//	@ref EXTI_Define
//EXTI_L0_Px0
#define EXTI_L0_PA0					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_0, EXTI_L0, EXTI_L0_IRQ}
#define EXTI_L0_PB0					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_0, EXTI_L0, EXTI_L0_IRQ}
#define EXTI_L0_PC0					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_0, EXTI_L0, EXTI_L0_IRQ}
#define EXTI_L0_PD0					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_0, EXTI_L0, EXTI_L0_IRQ}
//EXTI_L1_Px1
#define EXTI_L1_PA1					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_1, EXTI_L1, EXTI_L1_IRQ}
#define EXTI_L1_PB1					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_1, EXTI_L1, EXTI_L1_IRQ}
#define EXTI_L1_PC1					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_1, EXTI_L1, EXTI_L1_IRQ}
#define EXTI_L1_PD1					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_1, EXTI_L1, EXTI_L1_IRQ}
//EXTI_L2_Px2
#define EXTI_L2_PA2					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_2, EXTI_L2, EXTI_L2_IRQ}
#define EXTI_L2_PB2					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_2, EXTI_L2, EXTI_L2_IRQ}
#define EXTI_L2_PC2					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_2, EXTI_L2, EXTI_L2_IRQ}
#define EXTI_L2_PD2					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_2, EXTI_L2, EXTI_L2_IRQ}
//EXTI_L3_Px3
#define EXTI_L3_PA3					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_3, EXTI_L3, EXTI_L3_IRQ}
#define EXTI_L3_PB3					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_3, EXTI_L3, EXTI_L3_IRQ}
#define EXTI_L3_PC3					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_3, EXTI_L3, EXTI_L3_IRQ}
#define EXTI_L3_PD3					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_3, EXTI_L3, EXTI_L3_IRQ}
//EXTI_L4_Px4
#define EXTI_L4_PA4					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_4, EXTI_L4, EXTI_L4_IRQ}
#define EXTI_L4_PB4					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_4, EXTI_L4, EXTI_L4_IRQ}
#define EXTI_L4_PC4					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_4, EXTI_L4, EXTI_L4_IRQ}
#define EXTI_L4_PD4					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_4, EXTI_L4, EXTI_L4_IRQ}
//EXTI_L5_Px5
#define EXTI_L5_PA5					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_5, EXTI_L5, EXTI_L5_IRQ}
#define EXTI_L5_PB5					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_5, EXTI_L5, EXTI_L5_IRQ}
#define EXTI_L5_PC5					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_5, EXTI_L5, EXTI_L5_IRQ}
#define EXTI_L5_PD5					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_5, EXTI_L5, EXTI_L5_IRQ}
//EXTI_L6_Px6
#define EXTI_L6_PA6					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_6, EXTI_L6, EXTI_L6_IRQ}
#define EXTI_L6_PB6					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_6, EXTI_L6, EXTI_L6_IRQ}
#define EXTI_L6_PC6					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_6, EXTI_L6, EXTI_L6_IRQ}
#define EXTI_L6_PD6					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_6, EXTI_L6, EXTI_L6_IRQ}
//EXTI_L7_Px7
#define EXTI_L7_PA7					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_7, EXTI_L7, EXTI_L7_IRQ}
#define EXTI_L7_PB7					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_7, EXTI_L7, EXTI_L7_IRQ}
#define EXTI_L7_PC7					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_7, EXTI_L7, EXTI_L7_IRQ}
#define EXTI_L7_PD7					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_7, EXTI_L7, EXTI_L7_IRQ}
//EXTI_L8_Px8
#define EXTI_L8_PA8					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_8, EXTI_L8, EXTI_L8_IRQ}
#define EXTI_L8_PB8					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_8, EXTI_L8, EXTI_L8_IRQ}
#define EXTI_L8_PC8					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_8, EXTI_L8, EXTI_L8_IRQ}
#define EXTI_L8_PD8					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_8, EXTI_L8, EXTI_L8_IRQ}
//EXTI_L9_Px9
#define EXTI_L9_PA9					(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_9, EXTI_L9, EXTI_L9_IRQ}
#define EXTI_L9_PB9					(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_9, EXTI_L9, EXTI_L9_IRQ}
#define EXTI_L9_PC9					(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_9, EXTI_L9, EXTI_L9_IRQ}
#define EXTI_L9_PD9					(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_9, EXTI_L9, EXTI_L9_IRQ}
//EXTI_L10_Px10
#define EXTI_L10_PA10				(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_10, EXTI_L10, EXTI_L10_IRQ}
#define EXTI_L10_PB10				(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_10, EXTI_L10, EXTI_L10_IRQ}
#define EXTI_L10_PC10				(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_10, EXTI_L10, EXTI_L10_IRQ}
#define EXTI_L10_PD10				(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_10, EXTI_L10, EXTI_L10_IRQ}
//EXTI_L11_Px11
#define EXTI_L11_PA11				(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_11, EXTI_L11, EXTI_L11_IRQ}
#define EXTI_L11_PB11				(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_11, EXTI_L11, EXTI_L11_IRQ}
#define EXTI_L11_PC11				(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_11, EXTI_L11, EXTI_L11_IRQ}
#define EXTI_L11_PD11				(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_11, EXTI_L11, EXTI_L11_IRQ}
//EXTI_L12_Px12
#define EXTI_L12_PA12				(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_12, EXTI_L12, EXTI_L12_IRQ}
#define EXTI_L12_PB12				(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_12, EXTI_L12, EXTI_L12_IRQ}
#define EXTI_L12_PC12				(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_12, EXTI_L12, EXTI_L12_IRQ}
#define EXTI_L12_PD12				(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_12, EXTI_L12, EXTI_L12_IRQ}
//EXTI_L13_Px13
#define EXTI_L13_PA13				(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_13, EXTI_L13, EXTI_L13_IRQ}
#define EXTI_L13_PB13				(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_13, EXTI_L13, EXTI_L13_IRQ}
#define EXTI_L13_PC13				(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_13, EXTI_L13, EXTI_L13_IRQ}
#define EXTI_L13_PD13				(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_13, EXTI_L13, EXTI_L13_IRQ}
//EXTI_L14_Px14
#define EXTI_L14_PA14				(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_14, EXTI_L14, EXTI_L14_IRQ}
#define EXTI_L14_PB14				(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_14, EXTI_L14, EXTI_L14_IRQ}
#define EXTI_L14_PC14				(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_14, EXTI_L14, EXTI_L14_IRQ}
#define EXTI_L14_PD14				(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_14, EXTI_L14, EXTI_L14_IRQ}
//EXTI_L15_Px15
#define EXTI_L15_PA15				(EXTI_GPIO_Mapping_t){GPIOA, GPIO_PIN_15, EXTI_L15, EXTI_L15_IRQ}
#define EXTI_L15_PB15				(EXTI_GPIO_Mapping_t){GPIOB, GPIO_PIN_15, EXTI_L15, EXTI_L15_IRQ}
#define EXTI_L15_PC15				(EXTI_GPIO_Mapping_t){GPIOC, GPIO_PIN_15, EXTI_L15, EXTI_L15_IRQ}
#define EXTI_L15_PD15				(EXTI_GPIO_Mapping_t){GPIOD, GPIO_PIN_15, EXTI_L15, EXTI_L15_IRQ}



//	@ref EXTI_Trigger_Define
#define EXTI_Trigger_Rising						0
#define EXTI_Trigger_Falling					1
#define EXTI_Trigger_RisingAndFalling			2



//	@ref EXTI_IRQ_Define
#define EXTI_IRQ_ENABLE		  1
#define EXTI_IRQ_Disable      0



/*
 * ==========================================================================================
 * 							  APIs Supported by "MCAL_EXTI DRIVER"
 * ==========================================================================================
 */
void MCAL_EXTI_Init(EXTI_PinConfig_t *EXTI_config);
void MCAL_EXTI_Update(EXTI_PinConfig_t *EXTI_config);
void MCAL_EXTI_Reset();







#endif /* STM32F103X6_EXTI_DRIVER_H_ */
