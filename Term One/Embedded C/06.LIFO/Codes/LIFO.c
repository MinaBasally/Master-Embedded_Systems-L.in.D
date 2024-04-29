/*
 *  LIFO.c
 *
 *  *LIFO LINEAR DATA STRUCTURE*
 *
 *  Created on: Jan 10, 2024
 *      Author: Mina
 *
 */

#include "LIFO.h"
#include "stdio.h"



/*LIFO Buffer initialization*/
LIFO_Buff_Status LIFO_Buff_init(LIFO_t *LIFO_Buff, data_type *buffer,
		unsigned int length) {
	if (buffer == NULL) {
		printf("LIFO Buffer initialization......FAILED\n\n");
		return LIFO_Buff_NULL;
	}

	LIFO_Buff->length = length;
	LIFO_Buff->count = 0;
	LIFO_Buff->base = buffer;
	LIFO_Buff->head = buffer;

	printf("LIFO Buffer initialization......DONE\n\n");
	return LIFO_Buff_No_Error;
}



/*Push Data to LIFO Buffer*/
LIFO_Buff_Status LIFO_Buff_push(LIFO_t *LIFO_Buff, data_type *x) {
	if (!LIFO_Buff->base || !LIFO_Buff->head) {
		printf("LIFO Buffer does not exist\n\n");
		printf("Addition to LIFO Buffer......FAILED\n\n");
		return LIFO_Buff_NULL;
	}

	if (LIFO_Buff->count == LIFO_Buff->length) {
		printf("LIFO Buffer is full\n\n");
		printf("Addition to LIFO Buffer......FAILED\n\n");
		return LIFO_Buff_Full;
	}

	*(LIFO_Buff->head) = *x;
	LIFO_Buff->count++;
	LIFO_Buff->head++;

	printf("Addition to LIFO Buffer......DONE\n\n");
	return LIFO_Buff_No_Error;
}



/*Get Data from LIFO Buffer*/
LIFO_Buff_Status LIFO_Buff_pop(LIFO_t *LIFO_Buff, data_type *y) {
	if (!LIFO_Buff->base || !LIFO_Buff->head) {
		printf("LIFO Buffer does not exist\n\n");
		return LIFO_Buff_NULL;
	}

	if (LIFO_Buff->count == 0) {
		printf("LIFO Buffer is empty\n\n");
		return LIFO_Buff_Empty;
	}

	LIFO_Buff->head--;
	*y = *(LIFO_Buff->head);
	LIFO_Buff->count--;
	printf("Retrieving data from LIFO Buffer :  %X\n\n", *(LIFO_Buff->head));

	return LIFO_Buff_No_Error;
}



/*Print ALL Data inside LIFO Buffer*/
void LIFO_Buff_print(LIFO_t *LIFO_Buff) {
	data_type *temp;
	unsigned int i = 0;

	if (!LIFO_Buff->base || !LIFO_Buff->head)
		printf("Buffer does not exist\n\n");
	else if (LIFO_Buff->count == 0)
		printf(
				"***********LIFO Buffer is empty***********\n******************************************\n\n");
	else {
		temp = LIFO_Buff->head;
		printf("***********LIFO Buffer Display***********\n");

		for (; (i < LIFO_Buff->count); i++) {
			printf("\t\t %X\n", *(--temp));
		}

		printf("*****************************************\n\n");
	}
}
