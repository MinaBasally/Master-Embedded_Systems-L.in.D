/*
 *  LEDs_Lighting_Pattern.c
 *
 *  Created: 4/1/2024
 *  Author : Mina Basally
 *
 */ 

#define F_CPU		8000000UL

#include "util/delay.h"
#include "utils.h"
#include "ATmega32_MemoryMap_1.h"



int main(void) {
	DDRD = 0b11100000;		// Configuring PD5, PD6 & PD7 as output pins
	unsigned int i;
    
    while (1) {
		
		for (i = 0; i < 3; i++) {
			setbit(PORTD, (i + 5));
			_delay_ms(500);
		}
		
		for (i = 0; i < 3; i++) {
			clearbit(PORTD, (7 - i));
			_delay_ms(500);
		}
		
    }
	
}