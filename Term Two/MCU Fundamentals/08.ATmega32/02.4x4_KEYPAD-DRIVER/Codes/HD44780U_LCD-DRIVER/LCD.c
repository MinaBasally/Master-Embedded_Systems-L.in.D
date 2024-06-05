/*
 *  LCD.c
 *
 *  Created: 4/7/2024
 *   Author: Mina Basally
 *
 */ 

#include "LCD.h"
#include "util/delay.h"
#include "stdlib.h"
#include "stdio.h"



void LCD_Init() {
	_delay_ms(25);
	DataDir_LCD_CTRL_PORT |=  ((0b1 << EN_SWITCH)  |  (0b1 << RS_SWITCH)  |  (0b1 << RW_SWITCH));
	LCD_CTRL_PORT         &= ~((0b1 << EN_SWITCH)  |  (0b1 << RS_SWITCH)  |  (0b1 << RW_SWITCH));
	
	DataDir_LCD_PORT = 0xFF;
	_delay_ms(15);
	
	LCD_Clear_Screen();
	
	#ifdef EIGHT_BIT_MODE
	LCD_Write_Command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	//LCD_Write_Command(0x02);				/* send for 4 bit initialization of LCD */
	//LCD_Write_Command(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_Write_Command(0x0c);              /* Display ON cursor OFF */
	//LCD_Write_Command(0x06);              /* Increment cursor (shift cursor to right) */
	//LCD_Write_Command(0x01);
	LCD_Write_Command(0x02);
	LCD_Write_Command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_Write_Command(LCD_ENTRY_MODE);
	LCD_Write_Command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Write_Command(LCD_DISP_ON_CURSOR_BLINK);
}



void LCD_Clear_Screen() {
	LCD_Write_Command(LCD_CLEAR_SCREEN);
}



void LCD_Write_Command(unsigned char command) {
	LCD_Check_Is_LCD_Busy();
	//DataDir_LCD_PORT = 0xFF;
	
	#ifdef EIGHT_BIT_MODE
	LCD_PORT =   command;
	LCD_CTRL_PORT &= ~((0b1 << RS_SWITCH)  |  (0b1 << RW_SWITCH));
	LCD_Kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT =   ((LCD_PORT & 0x0F)  |  (command & 0xF0));
	LCD_CTRL_PORT &= ~((0b1 << RS_SWITCH)  |  (0b1 << RW_SWITCH));
	_delay_ms(1);
	LCD_Kick();
	LCD_PORT =   ((LCD_PORT & 0x0F)  |  (command << DATA_shift));
	LCD_CTRL_PORT &= ~((0b1 << RS_SWITCH)  |  (0b1 << RW_SWITCH));
	_delay_ms(1);
	LCD_Kick();
	#endif
}



void LCD_Write_Char(unsigned char character) {
	//LCD_Check_Is_LCD_Busy();
	//DataDir_LCD_PORT = 0xFF;
	
	#ifdef EIGHT_BIT_MODE
	LCD_Check_Is_LCD_Busy();
	LCD_PORT =   character;
	LCD_CTRL_PORT |=  (0b1 << RS_SWITCH);		//turn RS ON for Data mode.
	LCD_CTRL_PORT &= ~(0b1 << RW_SWITCH);	//turn RW OFF so you can write.
	LCD_Kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT =   ((LCD_PORT & 0x0F)  |  (character & 0xF0));
	LCD_CTRL_PORT |=  (0b1 << RS_SWITCH);		//turn RS ON for Data mode.
	LCD_CTRL_PORT &= ~(0b1 << RW_SWITCH);		//turn RW OFF so you can write.
	_delay_ms(1);
	LCD_Kick();
	LCD_PORT =   ((LCD_PORT & 0x0F)  |  (character << DATA_shift));
	LCD_CTRL_PORT |=  (0b1 << RS_SWITCH);		//turn RS ON for Data mode.
	LCD_CTRL_PORT &= ~(0b1 << RW_SWITCH);		//turn RW OFF so you can write.
	_delay_ms(1);
	LCD_Kick();
	#endif
}



void LCD_Write_String(char *string){
	int count = 0;
	
	while (*string > 0) {
		LCD_Write_Char(*string++);
		count++;
		if (count == 16) {
			LCD_GoTo_XY(2,0);
			} else if (count == 32) {
			LCD_Clear_Screen();
			LCD_GoTo_XY(1,0);
			count = 0;
		}
	}
	
}



void LCD_Check_Is_LCD_Busy() {
	DataDir_LCD_PORT &= ~(0xFF << DATA_shift);
	LCD_CTRL_PORT |=  (1 << RW_SWITCH);
	LCD_CTRL_PORT &= ~(1 << RS_SWITCH);
	
	if (((LCD_PIN & (0b1 << 7)) >> 7) == 1) {
		LCD_Kick();
	}
	
	DataDir_LCD_PORT |= (0xFF << DATA_shift);
	LCD_CTRL_PORT &= ~(0b1 << RW_SWITCH);
}



void LCD_Kick() {
	LCD_CTRL_PORT |=  (0b1 << EN_SWITCH);
	//asm volatile ("nop");
	_delay_ms(50);
	LCD_CTRL_PORT &= ~(0b1 << EN_SWITCH);
}



void LCD_GoTo_XY (unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_Write_Command(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	} else if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_Write_Command(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}



void LCD_Display_Number (int number) {
	char arr[7];
	sprintf(arr, "%d", number);
	LCD_Write_String(arr);
}



void LCD_Display_Real_Number (double number) {
	char arr[16];
	
	char *tmpSign = (number < 0) ? "-" : "";
	double tmpVal = (number < 0) ? -number : number;
	
	int tmpInt1   = tmpVal;
	float tmpFrac = tmpVal - tmpInt1;
	int tmpInt2   = tmpFrac * 100000;
	
	sprintf (arr, "%s%d.%05d", tmpSign, tmpInt1, tmpInt2);
	LCD_Write_String(arr);
}



void LCD_Custom_Character() {
	LCD_Write_Command(64);		// Command(64) is to store the 1st Custom Character in the CGRAM
	LCD_Write_Char(0);
	LCD_Write_Char(14);
	LCD_Write_Char(17);
	LCD_Write_Char(2);
	LCD_Write_Char(4);
	LCD_Write_Char(4);
	LCD_Write_Char(0);
	LCD_Write_Char(4);
	LCD_GoTo_XY(1, 6);
	//LCD_Write_Command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Write_Char(0);			// Display the 1st Custom Character stored in the CGRAM
	
	LCD_Write_Command(72);		// Command(64+8) is to store the 2nd Custom Character in the CGRAM
	LCD_Write_Char(0);
	LCD_Write_Char(10);
	LCD_Write_Char(21);
	LCD_Write_Char(17);
	LCD_Write_Char(18);
	LCD_Write_Char(4);
	LCD_Write_Char(0);
	LCD_Write_Char(0);
	LCD_GoTo_XY(1, 9);
	LCD_Write_Char(1);			// Display the 2nd Custom Character stored in the CGRAM
}