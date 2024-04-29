/*
 *  FIFO.c
 *
 *  *CIRCULAR FIFO LINEAR DATA STRUCTURE*
 *
 *  Created on: Jan 10, 2024
 *      Author: Mina
 *
 */

#include "stdio.h"
#include "FIFO.h"



/*FIFO Buffer initialization*/
FIFO_Buff_Status FIFO_Buff_init(FIFO_t *FIFO_Buff, data_type *buffer,
		unsigned int length) {
	if (buffer == NULL) {
		printf("FIFO Buffer initialization......FAILED\n\n");
		return FIFO_Buff_NULL;
	}

	FIFO_Buff->length = length;
	FIFO_Buff->count = 0;
	FIFO_Buff->base = buffer;
	FIFO_Buff->head = buffer;
	FIFO_Buff->tail = buffer;

	printf("FIFO Buffer initialization......DONE\n\n");
	return FIFO_Buff_No_Error;
}



/*Push Data to FIFO Buffer*/
FIFO_Buff_Status FIFO_Buff_push(FIFO_t *FIFO_Buff, data_type *x) {
	if (!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail) {
		printf("FIFO Buffer does not exist\n\n");
		printf("Addition to FIFO Buffer......FAILED\n\n");
		return FIFO_Buff_NULL;
	}

	if (FIFO_Buff->count == FIFO_Buff->length) {
		printf("FIFO Buffer is full\n\n");
		printf("Addition to FIFO Buffer......FAILED\n\n");
		return FIFO_Buff_Full;
	}

	*(FIFO_Buff->head) = *x;
	FIFO_Buff->count++;

	if (FIFO_Buff->head
			== ((FIFO_Buff->base) + (FIFO_Buff->length) * sizeof(data_type)))
		FIFO_Buff->head = FIFO_Buff->base;
	else
		FIFO_Buff->head++;

	printf("Addition to FIFO Buffer......DONE\n\n");
	return FIFO_Buff_No_Error;
}



/*Get Data from FIFO Buffer*/
FIFO_Buff_Status FIFO_Buff_pop(FIFO_t *FIFO_Buff, data_type *y) {
	if (!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail) {
		printf("FIFO Buffer does not exist\n\n");
		return FIFO_Buff_NULL;
	}

	if (FIFO_Buff->count == 0) {
		printf("FIFO Buffer is empty\n\n");
		return FIFO_Buff_Empty;
	}

	*y = *(FIFO_Buff->tail);
	FIFO_Buff->count--;
	printf("Retrieving data from FIFO Buffer :  %X\n\n", *(FIFO_Buff->tail));

	if (FIFO_Buff->tail
			== ((FIFO_Buff->base) + (FIFO_Buff->length) * sizeof(data_type)))
		FIFO_Buff->tail = FIFO_Buff->base;
	else
		FIFO_Buff->tail++;

	return FIFO_Buff_No_Error;
}



/*Print ALL Data inside FIFO Buffer*/
void FIFO_Buff_print(FIFO_t *FIFO_Buff) {
	data_type *temp;
	unsigned int i;

	if (!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail)
		printf("Buffer does not exist\n\n");
	else if (FIFO_Buff->count == 0)
		printf(
				"***********FIFO Buffer is empty***********\n******************************************\n\n");
	else {
		temp = FIFO_Buff->tail;
		printf("***********FIFO Buffer Display***********\n");

		for (i = 0; (i < FIFO_Buff->count); i++) {
			if (temp
					== ((FIFO_Buff->base)
							+ (FIFO_Buff->length) * sizeof(data_type)))
				temp = FIFO_Buff->base;

			printf("\t\t %X\n", *(temp++));
		}

		printf("*****************************************\n\n");
	}
}
