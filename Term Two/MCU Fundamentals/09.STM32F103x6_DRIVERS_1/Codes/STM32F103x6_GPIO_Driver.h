/*
 *  STM32F103x6_GPIO_Driver.h
 *
 *   Created on: Apr 11, 2024
 *       Author: Mina
 *
 */

#ifndef STM32F103X6_GPIO_DRIVER_H_
#define STM32F103X6_GPIO_DRIVER_H_






/*
 * ==========================================================================================
 * 										    Include
 * ==========================================================================================
 */
#include "STM32F103x6.h"



/*
 * ==========================================================================================
 * 								    Configuration Structure
 * ==========================================================================================
 */
typedef struct {
	uint16_t GPIO_PinNumber 	 ;     // Specifies the GPIO pins to be configured.
							      	   // This parameter must be set based on @ref GPIO_PINS_define

	uint8_t  GPIO_PinMode      	 ;     // Specifies the operating mode for the selected pins
							      	   // This parameter can be a value of @ref GPIO_MODE_define

	uint8_t GPIO_Pin_OutputSpeed ;     // Specifies the speed for the selected pins
								   	   // This parameter can be a value of @ref GPIO_SPEED_define
} GPIO_PinConfig_t;



/*
 * ==========================================================================================
 * 							    Macros Configuration References
 * ==========================================================================================
 */
//	@ref GPIO_PINS_define
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected  10    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected  100   */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected  1000  */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected  10000 */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_ALL               ((uint16_t)0xFFFF)  /* All Pins selected */

#define GPIO_PIN_MASK              0x0000FFFFUL		   /* PIN Mask for assertion test */



//	@ref GPIO_MODE_define
// 0: INPUT...Analog
// 1: INPUT...Floating (reset state)
// 2: INPUT...Pull-Up
// 3: INPUT...Pull-Down
// 4: OUTPUT...Push-Pull
// 5: OUTPUT...Open-Drain
// 6: Alternate Function...OUTPUT...Push-Pull
// 7: Alternate Function...OUTPUT...Open-Drain
// 8: Alternate Function...INPUT
#define  GPIO_MODE_INPUT_ANALOG					 0x0000u   // Analog input mode
#define  GPIO_MODE_INPUT_FLO                     0x0001u   // Floating input
#define  GPIO_MODE_INPUT_PU                      0x0002u   // Input with pull-up
#define  GPIO_MODE_INPUT_PD                      0x0003u   // Input with pull-down
#define  GPIO_MODE_OUTPUT_PP                     0x0004u   // General purpose output push-pull
#define  GPIO_MODE_OUTPUT_OD                     0x0005u   // General purpose output Open-drain
#define  GPIO_MODE_OUTPUT_AF_PP                  0x0006u   // Alternate function output Push-pull
#define  GPIO_MODE_OUTPUT_AF_OD                  0x0007u   // Alternate function output Open-drain
#define  GPIO_MODE_INPUT_AF                      0x0008u   // Alternate function input



//	@ref GPIO_SPEED_define
// 1: Output mode, max speed 10 MHz.
// 2: Output mode, max speed 2 MHz.
// 3: Output mode, max speed 50 MHz
#define GPIO_OUTPUT_SPEED_10MHz				0x0001u  //Output mode, max speed 10 MHz.
#define GPIO_OUTPUT_SPEED_2MHz				0x0002u  //Output mode, max speed 2 MHz.
#define GPIO_OUTPUT_SPEED_50MHz				0x0003u  //Output mode, max speed 50 MHz.



//	@ref GPIO_PIN_STATE
#define GPIO_PIN_SET    			1
#define GPIO_PIN_CLEAR      		0



//	@ref GPIO_LOCK_STATE
#define GPIO_LOCK_Enabled    		1
#define GPIO_LOCK_ERROR     	    0



/*
 * ==========================================================================================
 * 							  APIs Supported by "MCAL_GPIO DRIVER"
 * ==========================================================================================
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_Reset(GPIO_TypeDef *GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);







#endif /* STM32F103X6_GPIO_DRIVER_H_ */
