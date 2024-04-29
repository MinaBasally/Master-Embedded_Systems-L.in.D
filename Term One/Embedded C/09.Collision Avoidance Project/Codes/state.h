/*
 *  state.h
 *
 *  Created on: Jan 19, 2024
 *      Author: Mina
 *
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

/*State Function*/
#define state_def(_state_)  void St_##_state_()

/*Address Of State Function*/
#define state(_state_)		St_##_state_

/*Global Pointer To State Function*/
#define state_ptr(_state_)  void (*_state_)()

/*Interface Functions Prototypes*/
void US_get_dist(unsigned int *d);
void Logic_get_speed(unsigned int *s);

#endif /* STATE_H_ */
