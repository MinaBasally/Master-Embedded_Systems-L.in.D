/*
 *  ATmega32_IO_Driver.h
 *
 *  Created: 4/8/2024
 *   Author: Mina
 *
 */



#ifndef ATMEGA32_IO_DRIVER_H_
#define ATMEGA32_IO_DRIVER_H_







/*
 * ==========================================================================================
 * 										    Include
 * ==========================================================================================
 */
#include "ATmega32.h"



/*
 * ==========================================================================================
 * 								    Configuration Structure
 * ==========================================================================================
 */
typedef struct {
	uint8_t GPIO_PinNumber 		 ;     // Specifies the GPIO pins to be configured.
							      	   // This parameter must be set based on @ref GPIO_PINS_define

	uint8_t  GPIO_PinMode      	 ;     // Specifies the operating mode for the selected pins
							      	   // This parameter can be a value of @ref GPIO_MODE_define
} GPIO_PinConfig_t;



/*
 * ==========================================================================================
 * 							    Macros Configuration References
 * ==========================================================================================
 */
//	@ref GPIO_PINS_define
#define GPIO_PIN_0                 ((uint8_t)0x01)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint8_t)0x02)  /* Pin 1 selected  10    */
#define GPIO_PIN_2                 ((uint8_t)0x04)  /* Pin 2 selected  100   */
#define GPIO_PIN_3                 ((uint8_t)0x08)  /* Pin 3 selected  1000  */
#define GPIO_PIN_4                 ((uint8_t)0x10)  /* Pin 4 selected  10000 */
#define GPIO_PIN_5                 ((uint8_t)0x20)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint8_t)0x40)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint8_t)0x80)  /* Pin 7 selected    */
#define GPIO_PIN_ALL               ((uint8_t)0xFF)  /* All Pins selected */

#define GPIO_PIN_MASK              0x00FFU		   /* PIN Mask for assertion test */



//	@ref GPIO_MODE_define
#define  GPIO_MODE_INPUT                     0   // Input
#define  GPIO_MODE_OUTPUT                    1   // Output



//	@ref GPIO_PIN_STATE
#define GPIO_PIN_SET    			1
#define GPIO_PIN_CLEAR      		0



/*
 * ==========================================================================================
 * 							  APIs Supported by "MCAL_GPIO DRIVER"
 * ==========================================================================================
 */
void MCAL_GPIO_ResetReg(uint8_t *GPIOx_REG);

uint8_t MCAL_GPIO_ReadPin(uint8_t *GPIOx_REG, uint8_t PinNumber);
uint8_t MCAL_GPIO_ReadPort(uint8_t *GPIOx_REG);

void MCAL_GPIO_WritePin(uint8_t *GPIOx_REG, uint8_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(uint8_t *GPIOx_REG, uint8_t Value);

void MCAL_GPIO_TogglePin(uint8_t *GPIOx_REG, uint8_t PinNumber);



/*
// I/O Registers addresses
#define PORTA			(*((volatile unsigned char*)(0x3B)))		//Reset value: 0b0000 0000
#define DDRA			(*((volatile unsigned char*)(0x3A)))		//Reset value: 0b0000 0000
#define PINA			(*((volatile unsigned char*)(0x39)))		//Reset value: N/A

#define PORTB			(*((volatile unsigned char*)(0x38)))		//Reset value: 0b0000 0000
#define DDRB			(*((volatile unsigned char*)(0x37)))		//Reset value: 0b0000 0000
#define PINB			(*((volatile unsigned char*)(0x36)))		//Reset value: N/A

#define PORTC			(*((volatile unsigned char*)(0x35)))		//Reset value: 0b0000 0000
#define DDRC			(*((volatile unsigned char*)(0x34)))		//Reset value: 0b0000 0000
#define PINC			(*((volatile unsigned char*)(0x33)))		//Reset value: N/A

#define PORTD			(*((volatile unsigned char*)(0x32)))		//Reset value: 0b0000 0000
#define DDRD			(*((volatile unsigned char*)(0x31)))		//Reset value: 0b0000 0000
#define PIND			(*((volatile unsigned char*)(0x30)))		//Reset value: N/A
*/







#endif /* ATMEGA32_IO_DRIVER_H_ */