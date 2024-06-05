/*
 *  2-digit_7_segment_counter.c
 *
 *  Created: 4/5/2024
 *  Author : Mina Basally
 *
 */ 

#define F_CPU		8000000UL

#include "util/delay.h"
#include "utils.h"
#include "ATmega32_MemoryMap_4.h"



void GPIO_init() {
	DDRC = 0b11111100;		// Configuring PC2, PC3, PC4, PC5, PC6 & PC7 as output pins
	PORTC = 0b10001000;
	_delay_ms(1000);
	PORTC = 0b10000100;
	_delay_ms(1000);
	PORTC = 0b00000000;
	_delay_ms(250);
}



int main(void) {
	GPIO_init();
	unsigned int i, j;

    while (1) {

		for(i = 0; i < 10; i++) /*Outer Loop to count The Tens digit*/ {
			
			for(j = 0; j < 10; j++) /*Inner Loop to count The Units digit*/ {
				// [1]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [2]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [3]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [4]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [5]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [6]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [7]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [8]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [9]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
				
				// [10]
				PORTC = 0b1000 | (i << 4);
				_delay_ms(50);
				PORTC = 0b0100 | (j << 4);
				_delay_ms(50);
			}
			
		}
		
    }
	
}