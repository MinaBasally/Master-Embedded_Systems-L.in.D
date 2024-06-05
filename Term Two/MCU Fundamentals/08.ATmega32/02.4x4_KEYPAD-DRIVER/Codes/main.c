/*
 *  Keypad(4x4_keys)_LCD(HD44780U).c
 *
 *  Created: 4/9/2024
 *  Author : Mina Basally
 *
 */ 

#include "Keypad_4x4_keys/Keypad.h"
#include "LCD/LCD.h"
#include "util/delay.h"



int main(void) {
	LCD_Init();
	Keypad_Init();
	_delay_ms(50);
	unsigned int count = 0;
	unsigned char key_pressed;
	
	while(1) {
		key_pressed = Keypad_Get_Key();
		
		switch(key_pressed) {
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
	
}

