/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "STM32F103x6.h"
#include "STM32F103x6_GPIO_Driver.h"
#include "SEVEN_SEGMENT.h"
#include "LCD.h"
#include "Keypad.h"



void _wait_ms(uint32_t time)
{
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++) ;
}



void clock_init()
{
	//	GPIOA clock enable
	RCC_GPIOA_CLK_EN();

	//	GPIOB clock enable
	RCC_GPIOB_CLK_EN();
}



void SEVEN_SEGMENT_init()
{
	GPIO_PinConfig_t pin;
	//	Initializing pin "a" of the 7-SEGMENT
	pin.GPIO_PinNumber = GPIO_PIN_15;
	pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	pin.GPIO_Pin_OutputSpeed = GPIO_OUTPUT_SPEED_10MHz;
	SEVEN_SEGMENT_Pin_a_Init(GPIOB, &pin);

	//	Initializing pin "b" of the 7-SEGMENT
	pin.GPIO_PinNumber = GPIO_PIN_14;
	SEVEN_SEGMENT_Pin_b_Init(GPIOB, &pin);

	//	Initializing pin "c" of the 7-SEGMENT
	pin.GPIO_PinNumber = GPIO_PIN_13;
	SEVEN_SEGMENT_Pin_c_Init(GPIOB, &pin);

	//	Initializing pin "d" of the 7-SEGMENT
	pin.GPIO_PinNumber = GPIO_PIN_12;
	SEVEN_SEGMENT_Pin_d_Init(GPIOB, &pin);

	//	Initializing pin "e" of the 7-SEGMENT
	pin.GPIO_PinNumber = GPIO_PIN_11;
	SEVEN_SEGMENT_Pin_e_Init(GPIOB, &pin);

	//	Initializing pin "f" of the 7-SEGMENT
	pin.GPIO_PinNumber = GPIO_PIN_10;
	SEVEN_SEGMENT_Pin_f_Init(GPIOB, &pin);

	//	Initializing pin "g" of the 7-SEGMENT
	pin.GPIO_PinNumber = GPIO_PIN_9;
	SEVEN_SEGMENT_Pin_g_Init(GPIOB, &pin);
}



int main(void)
{
	unsigned int i, count = 0;
	unsigned char key_pressed;
	clock_init();
	LCD_Init();
	LCD_Write_String("LCD is ready...");
	_wait_ms(750);
	LCD_Clear_Screen();
	_wait_ms(750);
	LCD_Clear_Screen();
	SEVEN_SEGMENT_init();
	LCD_Write_String("7-SEGMENT is-   ready..");
	MCAL_GPIO_WritePort(GPIOB, (uint16_t)((0xFF) << 9));
	_wait_ms(750);
	LCD_Clear_Screen();
	unsigned char LCD_DISPLAY[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char SEVEN_SEGMENT_DISPLAY[11] = {_7SEG_ZERO, _7SEG_ONE, _7SEG_TWO, _7SEG_THREE, _7SEG_FOUR, _7SEG_FIVE, _7SEG_SIX, _7SEG_SEVEN, _7SEG_EIGHT, _7SEG_NINE, _7SEG_ZERO};

	for (i = 0; i < 11; i++)
	{
		LCD_Write_Char(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, SEVEN_SEGMENT_DISPLAY[i] << 9); /* Write data on to the 7SEG port */
		_wait_ms(250);
	}

	LCD_Clear_Screen();
	Keypad_Init();
	LCD_Write_String("Keypad is ready...");
	_wait_ms(750);
	LCD_Clear_Screen();

	while(1)
	{
		key_pressed = Keypad_Get_Key();

		switch(key_pressed)
		{
			case 'A':
				break;
			case '!':
				count = 0;
				LCD_Clear_Screen();
				break;
			default:
				LCD_Write_Char(key_pressed);
				count++;
				if (count == 16) {
					LCD_GoTo_XY(2,0);
				} else if (count == 32) {
					LCD_Clear_Screen();
					LCD_GoTo_XY(1,0);
					count = 0;
				}
				break;
		}

	}

	return 0;
}