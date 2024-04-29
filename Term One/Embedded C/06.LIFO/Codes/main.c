/*
 *  main.c
 *
 *  *A Program To Test My LIFO Implementation*
 *
 *  Created on: Jan 10, 2024
 *      Author: Mina
 *
 */

#include "stdio.h"
#include "LIFO.h"
#define length 5



int main() {
	LIFO_t LIFO_Buff_UART;
	data_type i, temp, UART_Buffer[length];

	if (LIFO_Buff_init(&LIFO_Buff_UART, UART_Buffer, length) == LIFO_Buff_No_Error) {

		for (i = 0; i < 8; i++) {
			if (LIFO_Buff_push(&LIFO_Buff_UART, &i) == LIFO_Buff_No_Error)
				;
			else
				break;

			LIFO_Buff_print(&LIFO_Buff_UART);
		}

		for (i = 0; i < 8; i++) {
			if (LIFO_Buff_pop(&LIFO_Buff_UART, &temp) == LIFO_Buff_No_Error)
				;
			else
				break;

			LIFO_Buff_print(&LIFO_Buff_UART);
			if (!(LIFO_Buff_UART.count))
				break;
		}

	}

	getchar();
	return 0;
}
