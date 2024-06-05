/*
 *  LEDs_and_Button.c
 *
 *  Created: 4/2/2024 9:01:13 PM
 *  Author : Mina Basally
 *
 */ 

#define F_CPU		8000000UL

#include "util/delay.h"
#include "utils.h"
#include "ATmega32_MemoryMap_2.h"



void GPIO_init() {
	DDRD = 0b11100000;		// Configuring PD5, PD6 & PD7 as output pins
	PORTD |= (0b111 << 5);
	_delay_ms(500);
	PORTD &= ~(0b111 << 5);
	_delay_ms(500);
}



int main(void) {
	GPIO_init();
	volatile unsigned int x = 0;
	
    while (1) {
		
		while (x == 0) {
			if (readbit(PIND, 0)) {
				setbit(PORTD, 5);
				while (readbit(PIND, 0)) ;
				x = 1;
			}
		}
		
		while (x == 1) {
			if (readbit(PIND, 0)) {
				setbit(PORTD, 6);
				while (readbit(PIND, 0)) ;
				x = 2;
			}
		}
		
		while (x == 2) {
			if (readbit(PIND, 0)) {
				setbit(PORTD, 7);
				while (readbit(PIND, 0)) ;
				x = 3;
			}
		}
		
		while (x == 3) {
			if (readbit(PIND, 0)) {
				PORTD &= ~(0b111 << 5);
				while (readbit(PIND, 0)) ;
				x = 0;
			}
		}
		
    }
	
}