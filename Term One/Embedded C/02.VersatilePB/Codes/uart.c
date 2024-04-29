/*
*          uart.c
*	Created on: Dec 23, 2023
*	Author: Mina Moheb Basally	
*/

#include "uart.h"

//UART registers
#define UART0DR *((volatile unsigned int* const)((unsigned int *)0x101F1000))

//UART API
void Uart_Send_string(unsigned char *ptr_t_ch) {

while(*ptr_t_ch != '\0')
{
UART0DR = (unsigned int)(*ptr_t_ch);
ptr_t_ch++;
}

}