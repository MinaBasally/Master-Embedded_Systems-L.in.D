/*
 *  Keypad.c
 *
 *  Created: 4/9/2024
 *   Author: Mina
 *
 */ 

#include "Keypad.h"
#include "util/delay.h"



int Keypad_Rows[] = {R0, R1, R2, R3};			//rows of the keypad
int Keypad_Cols[] = {C0, C1, C2, C3};			//columns of the keypad



void Keypad_Init() {
	DataDir_KEYPAD_PORT &= ~((0b1 << R0) | (0b1 << R1) | (0b1 << R2) | (0b1 << R3));			// Set Row Pins as inputs
	DataDir_KEYPAD_PORT |=  ((0b1 << C0) | (0b1 << C1) | (0b1 << C2) | (0b1 << C3));			// Set Column Pins as outputs
	KEYPAD_PORT = 0xFF;
}



char Keypad_Get_Key() {
	unsigned int i, j;
	
	for (i = 0; i < 4; i++) {
		KEYPAD_PORT |=  ((0b1 << C0) | (0b1 << C1) | (0b1 << C2) | (0b1 << C3));
		KEYPAD_PORT &= ~(0b1 << Keypad_Cols[i]);
		
		for(j = 0; j < 4; j++) {
			if (!(KEYPAD_PIN & (0b1 << Keypad_Rows[j]))) {
				while(!(KEYPAD_PIN & (0b1 << Keypad_Rows[j]))) ;
				
				switch(i) {
					case (0):
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '!';
						break;
					case (1):
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					case (2):
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					case (3):
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
				}
				
			}
		}
		
	}
	
	return 'A';			// 'A' is returned if no key was pressed
}