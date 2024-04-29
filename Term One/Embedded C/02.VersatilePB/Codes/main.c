/*
*          main.c
*	Created on: Dec 23, 2023
*	Author: Mina Moheb Basally	
*/

#include "uart.h"

unsigned char string_buffer[100]        = "learn-in-depth: <Mina>";
unsigned char const string_bufferr[100] = "to create a rodata section in the output binary file";

void main(void) {

//Board = ARM Versatile/PB (core = ARM926EJ-S)
Uart_Send_string(string_buffer);

}