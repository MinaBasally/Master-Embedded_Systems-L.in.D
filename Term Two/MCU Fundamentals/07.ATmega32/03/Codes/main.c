/*
 *  Buzzer_and_Button.c
 *
 *  Created: 4/4/2024
 *  Author : Mina Basally
 *
 */ 

#define F_CPU		8000000UL

#include "util/delay.h"
#include "utils.h"
#include "ATmega32_MemoryMap_3.h"



void GPIO_init() {
	DDRD = 0b00010000;		// Configuring PD4 as an output pin
	PORTD |= (0b1 << 4);
	_delay_ms(275);
	PORTD &= ~(0b1 << 4);
	_delay_ms(275);
}



int main(void) {
	GPIO_init();

    while (1) {
		
		if (readbit(PIND, 0)) {
			setbit(PORTD, 4);
			_delay_ms(225);
			clearbit(PORTD, 4);
			while (readbit(PIND, 0)) ;
		}
				
    }

}