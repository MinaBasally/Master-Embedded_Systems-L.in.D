/*
 *  FIFO.h
 *
 *  Created on: Jan 10, 2024
 *      Author: Mina
 *
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"



/*Configure FIFO Data Type (By the USER)*/
#define data_type uint32_t



/*Data Types definitions*/
typedef struct {
	unsigned int length;
	unsigned int count;
	data_type *base;
	data_type *head;
	data_type *tail;
} FIFO_t;

typedef enum {
	FIFO_Buff_No_Error, FIFO_Buff_NULL, FIFO_Buff_Empty, FIFO_Buff_Full
} FIFO_Buff_Status;



/*APIs Prototypes*/
FIFO_Buff_Status FIFO_Buff_init(FIFO_t *FIFO_Buff, data_type *buffer, unsigned int length);
FIFO_Buff_Status FIFO_Buff_push(FIFO_t *FIFO_Buff, data_type *x);
FIFO_Buff_Status FIFO_Buff_pop(FIFO_t *FIFO_Buff, data_type *y);
void FIFO_Buff_print(FIFO_t *FIFO_Buff);



#endif /* FIFO_H_ */
