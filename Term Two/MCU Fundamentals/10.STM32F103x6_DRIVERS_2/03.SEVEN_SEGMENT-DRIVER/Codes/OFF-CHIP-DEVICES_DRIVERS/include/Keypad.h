/*
 *  Keypad.h
 *
 *  Created: 4/9/2024
 *   Author: Mina
 *
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_



#include "STM32F103x6.h"
#include "STM32F103x6_GPIO_Driver.h"

#define KEYPAD_PORT				GPIOB
#define DataDir_KEYPAD_PORT		GPIOB

#define R0			GPIO_PIN_0			// PB0
#define R1			GPIO_PIN_1			// PB1
#define R2			GPIO_PIN_3			// PB3
#define R3			GPIO_PIN_4			// PB4
#define C0			GPIO_PIN_5			// PB5
#define C1			GPIO_PIN_6			// PB6
#define C2			GPIO_PIN_7			// PB7
#define C3			GPIO_PIN_8			// PB8



void Keypad_Init();
char Keypad_Get_Key();
extern void _wait_ms(uint32_t time);



#endif /* KEYPAD_H_ */
