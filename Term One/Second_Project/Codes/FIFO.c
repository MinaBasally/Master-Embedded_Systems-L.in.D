/*
 *  FIFO.c
 *
 *  *CIRCULAR FIFO DATA STRUCTURE*
 *
 *  Created on: Feb 1, 2024
 *      Author: Mina
 *
 */

#include "FIFO.h"
#include "stdio.h"

#define defPRINTF(...)				{fflush(stdin); fflush(stdout);\
									 printf(__VA_ARGS__);\
									 fflush(stdin); fflush(stdout);}



/*Structures Definitions*/
Student_t Students[entries];



/*FIFO Buffer initialization*/
FIFO_Buff_Status FIFO_Buff_init(FIFO_t *FIFO_Buff, data_type *buffer,
		unsigned int length) {
	FIFO_Buff->length = (unsigned int) 0;
	FIFO_Buff->count = 0;
	FIFO_Buff->base = NULL;
	FIFO_Buff->head = NULL;
	FIFO_Buff->tail = NULL;

	if (buffer == NULL) {
		defPRINTF("[ERROR!]...FIFO Buffer initialization...FAILED!\n\n\n\n");
		return FIFO_Buff_NULL;
	}

	FIFO_Buff->length = length;
	FIFO_Buff->count = 0;
	FIFO_Buff->base = buffer;
	FIFO_Buff->head = buffer;
	FIFO_Buff->tail = buffer;

	defPRINTF("[INFO!]...FIFO Buffer initialization...DONE!\n\n\n\n");
	return FIFO_Buff_No_Error;
}



/*Push Data to FIFO Buffer*/
FIFO_Buff_Status FIFO_Buff_push(FIFO_t *FIFO_Buff, data_type *x) {
	if (!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail) {
		defPRINTF("[ERROR!]...Student Addition...FAILED!\n\n");
		return FIFO_Buff_NULL;
	}

	if (FIFO_Buff->count == FIFO_Buff->length) {
		defPRINTF("[ERROR!]...Student Addition...FAILED!\n\n");
		return FIFO_Buff_Full;
	}

	unsigned int i;
	for (i = 0; i < FIFO_Buff->length; i++) {
		if (!(FIFO_Buff->count)
				|| (((FIFO_Buff->head->RollNum == (unsigned int) 64799)
						|| (FIFO_Buff->head->RollNum == (unsigned int) 0))
						&& (FIFO_Buff->head->GPA == 0.00000)
						&& (FIFO_Buff->head->CourseID[0] == (unsigned int) 0))) {
			*(FIFO_Buff->head) = *x;
			FIFO_Buff->count++;
			defPRINTF("Roll Number: %u...\n", FIFO_Buff->head->RollNum);
			defPRINTF("[INFO!]...Student Added Successfully!\n");
			break;
		}
		if (FIFO_Buff->head
				== ((FIFO_Buff->base) + (FIFO_Buff->length) * sizeof(data_type)))
			FIFO_Buff->head = FIFO_Buff->base;
		else
			FIFO_Buff->head++;
	}

	if (FIFO_Buff->head
			== ((FIFO_Buff->base) + (FIFO_Buff->length) * sizeof(data_type)))
		FIFO_Buff->head = FIFO_Buff->base;
	else
		FIFO_Buff->head++;

	return FIFO_Buff_No_Error;
}



/*Get Data from FIFO Buffer*/
FIFO_Buff_Status FIFO_Buff_pop(FIFO_t *FIFO_Buff, data_type *y) {
	if (!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail)
		return FIFO_Buff_NULL;

	if (FIFO_Buff->count == 0)
		return FIFO_Buff_Empty;

	*y = *(FIFO_Buff->tail);
	FIFO_Buff->count--;

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
	unsigned int i, j;

	if (!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail) {
		defPRINTF("Buffer does not exist\n\n");
	} else if (FIFO_Buff->count == 0) {
		defPRINTF("\n############# Database is empty #############\n\n");
	} else {
		temp = FIFO_Buff->tail;
		defPRINTF("\n############# Database Display #############\n\n");

		for (i = 0; (i < FIFO_Buff->length); i++) {
			if (temp
					== ((FIFO_Buff->base)
							+ (FIFO_Buff->length) * sizeof(data_type)))
				temp = FIFO_Buff->base;

			if (!(((temp->RollNum == (unsigned int) 64799)
					|| (temp->RollNum == (unsigned int) 0))
					&& (temp->GPA == 0.00000)
					&& (temp->CourseID[0] == (unsigned int) 0))) {
				defPRINTF("\n===================================\n");
				defPRINTF("\tRoll Number : %u\n", temp->RollNum);
				defPRINTF("\tFirst Name  : %s\n", temp->FName);
				defPRINTF("\tLast Name   : %s\n", temp->LName);
				defPRINTF("\tGPA : %.3f\n", temp->GPA);

				defPRINTF("\tRegistered Courses[Max. = %d] :-\n", MaxCourses);
				for (j = 0; j < MaxCourses; j++) {
					defPRINTF("\tCourse %u ID : %u\n", j + 1, temp->CourseID[j]);
					if (j == MaxCourses - 1) {
						break;
					} else if (!(temp->CourseID[j + 1])) {
						break;
					}
				}

				defPRINTF("\n");
			}
			temp++;
		}

		defPRINTF("###########################################\n\n");
	}
}
