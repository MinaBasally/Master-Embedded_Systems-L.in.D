/*
 *  LIFO.h
 *
 *  Created on: Jan 10, 2024
 *      Author: Mina
 *
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdint.h"



/*Configure LIFO Data Type (By the USER)*/
#define data_type uint32_t



/*Data Types definitions*/
typedef struct {
	unsigned int length;
	unsigned int count;
	data_type *base;
	data_type *head;
} LIFO_t;

typedef enum {
	LIFO_Buff_No_Error, LIFO_Buff_NULL, LIFO_Buff_Empty, LIFO_Buff_Full
} LIFO_Buff_Status;



/*APIs Prototypes*/
LIFO_Buff_Status LIFO_Buff_init(LIFO_t *LIFO_Buff, data_type *buffer, unsigned int length);
LIFO_Buff_Status LIFO_Buff_push(LIFO_t *LIFO_Buff, data_type *x);
LIFO_Buff_Status LIFO_Buff_pop(LIFO_t *LIFO_Buff, data_type *y);
void LIFO_Buff_print(LIFO_t *LIFO_Buff);



#endif /* LIFO_H_ */
