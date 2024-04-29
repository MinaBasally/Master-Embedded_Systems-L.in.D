/*
 *  main.c
 *
 *  *A Program To Test My FIFO Implementation*
 *
 *  Created on: Jan 10, 2024
 *      Author: Mina
 *
 */

#include "stdio.h"
#include "FIFO.h"
#define length 5



int main() {
	FIFO_t FIFO_Buff_UART;
	data_type i, temp, UART_Buffer[length];

	if (FIFO_Buff_init(&FIFO_Buff_UART, UART_Buffer, length) == FIFO_Buff_No_Error) {

		for (i = 0; i < 8; i++) {
			if (FIFO_Buff_push(&FIFO_Buff_UART, &i) == FIFO_Buff_No_Error)
				;
			else
				break;

			FIFO_Buff_print(&FIFO_Buff_UART);
		}

		for (i = 0; i < 8; i++) {
			if (FIFO_Buff_pop(&FIFO_Buff_UART, &temp) == FIFO_Buff_No_Error)
				;
			else
				break;

			FIFO_Buff_print(&FIFO_Buff_UART);
			if (!(FIFO_Buff_UART.count))
				break;
		}

	}

	getchar();
	return 0;
}
