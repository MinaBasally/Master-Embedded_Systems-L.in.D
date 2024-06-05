/*
 *  main.c
 *
 *  Created on: 3/18/2024
 *  Author : Mina Basally
 *
 */ 

#define F_CPU 8000000ul

#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>



// INT0 any logical change(Pin.D2)
ISR(INT0_vect) {
	//DDRD = 0xff;
	PORTD |= (0b1 << 5);
	_delay_ms(1000);
}



// INT1 rising edge(Pin.D3)
ISR(INT1_vect) {
	//DDRD = 0xff;
	PORTD |= (0b1 << 6);
	_delay_ms(1000);
}



//INT2 falling edge(Pin.B2)
ISR(INT2_vect) {
	//DDRD = 0xff;
	PORTD |= (0b1 << 7) ;
	_delay_ms(1000);
}



int main(void) {
	/* INT0 any logical change(PD2)
	   INT1 rising edge(PD3) */
	   // (1101) //
	MCUCR  |= ((0b1 << 0) | (0b1 << 2) | (0b1 << 3));
	MCUCR  &= ~(0b1 << 1);
	MCUCSR &= ~(0b1 << 6);	//INT2 falling edge(PB2)
	GICR   |= ((0b1 << 5) | (0b1 << 6) | (0b1 << 7));
	sei(); // SREG [Set Global Interrupt Enable bit(7)]
	DDRD  |= ((0b1 << 5) | (0b1 << 6) | (0b1 << 7));
	PORTD |= ((0b1 << 5) | (0b1 << 6) | (0b1 << 7));
	_delay_ms(1000);
	
    while(1) {
		// Turn OFF all LEDs if any is turned ON
		if(PORTD & (0b111 << 5)) {
			PORTD &= ~((0b1 << 5) | (0b1 << 6) | (0b1 << 7));
			_delay_ms(1000);
		}
    }
	
}