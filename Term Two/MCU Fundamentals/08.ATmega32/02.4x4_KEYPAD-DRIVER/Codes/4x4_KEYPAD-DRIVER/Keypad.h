/*
 *  Keypad.h
 *
 *  Created: 4/9/2024
 *   Author: Mina
 *
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU		8000000UL

#include "../Memory_Map/IO_Memory_Map.h"

#define KEYPAD_PORT				PORTD
#define DataDir_KEYPAD_PORT		DDRD
#define KEYPAD_PIN				PIND

#define R0			0			// PD0
#define R1			1			// PD1
#define R2			2			// PD2
#define R3			3			// PD3
#define C0			4			// PD4
#define C1			5			// PD5
#define C2			6			// PD6
#define C3			7			// PD7



void Keypad_Init();
char Keypad_Get_Key();



#endif /* KEYPAD_H_ */