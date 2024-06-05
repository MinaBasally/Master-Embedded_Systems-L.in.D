/*
 *  IO_Memory_Map.h
 *
 *  Created: 4/8/2024
 *   Author: Mina
 *
 */ 


#ifndef IO_MEMORY_MAP_H_
#define IO_MEMORY_MAP_H_



// I/O Registers addresses
#define PORTA			(*((volatile unsigned char*)(0x3B)))		//Reset value: 0b0000 0000
#define DDRA			(*((volatile unsigned char*)(0x3A)))		//Reset value: 0b0000 0000
#define PINA			(*((volatile unsigned char*)(0x39)))		//Reset value: N/A

#define PORTB			(*((volatile unsigned char*)(0x38)))		//Reset value: 0b0000 0000
#define DDRB			(*((volatile unsigned char*)(0x37)))		//Reset value: 0b0000 0000
#define PINB			(*((volatile unsigned char*)(0x36)))		//Reset value: N/A

#define PORTC			(*((volatile unsigned char*)(0x35)))		//Reset value: 0b0000 0000
#define DDRC			(*((volatile unsigned char*)(0x34)))		//Reset value: 0b0000 0000
#define PINC			(*((volatile unsigned char*)(0x33)))		//Reset value: N/A

#define PORTD			(*((volatile unsigned char*)(0x32)))		//Reset value: 0b0000 0000
#define DDRD			(*((volatile unsigned char*)(0x31)))		//Reset value: 0b0000 0000
#define PIND			(*((volatile unsigned char*)(0x30)))		//Reset value: N/A



#endif /* IO_MEMORY_MAP_H_ */