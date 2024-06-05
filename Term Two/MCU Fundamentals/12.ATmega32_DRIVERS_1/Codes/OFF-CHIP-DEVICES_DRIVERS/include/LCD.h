/*
 *  LCD.h
 *
 *  Created: 4/7/2024
 *   Author: Mina
 *
 */


#ifndef LCD_H_
#define LCD_H_



#define F_CPU		8000000UL

#include "ATmega32_IO_Driver.h"

#define DataDir_LCD_PORT			GPIOA->DDRx			//DDRA
#define LCD_PORT					GPIOA->PORTx		//PORTA
#define LCD_PIN						GPIOA->PINx			//PINA
#define DataDir_LCD_CTRL_PORT		GPIOB->DDRx			//DDRB
#define LCD_CTRL_PORT				GPIOB->PORTx		//PORTB
#define LCD_CTRL_PIN				GPIOB->PINx			//PINB
#define RS_SWITCH					GPIO_PIN_1
#define RW_SWITCH					GPIO_PIN_2
#define EN_SWITCH					GPIO_PIN_3
//#define DATA_shift					0		// in 8 bit mode 0 and in 4 bit mode 4
#define DATA_shift					4		// in 8 bit mode 0 and in 4 bit mode 4
//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)



void LCD_Init();
void LCD_Clear_Screen();
void LCD_Write_Command (unsigned char command);
void LCD_Write_Char (unsigned char character);
void LCD_Write_String (char *string);
void LCD_Check_Is_LCD_Busy(void);
void LCD_Kick(void);
void LCD_GoTo_XY (unsigned char line, unsigned char position);
void LCD_Display_Number (int number);
void LCD_Display_Real_Number (double number);
void LCD_Custom_Character(void);



#endif /* LCD_H_ */