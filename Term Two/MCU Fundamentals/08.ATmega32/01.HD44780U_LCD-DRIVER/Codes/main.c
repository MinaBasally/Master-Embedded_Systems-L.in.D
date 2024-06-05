/*
 *  LCD_HD44780U.c
 *
 *  Created: 4/7/2024
 *  Author : Mina Basally
 *
 */ 

#include "LCD/LCD.h"
#include "util/delay.h"



int main(void) {
    LCD_Init();
	
    while (1) {
		LCD_Write_String("Hello! I'm Mina Basally..");
		_delay_ms(500);
		LCD_Clear_Screen();
		LCD_Write_String("This is a brief Test to verify  my LCD-Driver...");
		_delay_ms(500);
		LCD_Clear_Screen();
		LCD_Write_String("Displaying a-   Real Number  :   ");
		LCD_Display_Real_Number(-90.07318);
		_delay_ms(500);
		LCD_Clear_Screen();
		LCD_Write_String("Displaying an-  Integer : ");
		LCD_Display_Number(99);
		_delay_ms(500);
		LCD_Clear_Screen();
		LCD_Write_String("Displaying      Custom Characte-rs :  ");
		LCD_Custom_Character();
		_delay_ms(1000);
		LCD_Clear_Screen();
    }
	
}