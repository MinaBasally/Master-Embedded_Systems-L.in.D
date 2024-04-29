/*
 *  Logic.h
 *
 *  Created on: Jan 19, 2024
 *      Author: Mina
 *
 */

#ifndef LOGIC_H_
#define LOGIC_H_

#include "state.h"
#include "stdio.h"
#include "stdlib.h"

/*State Function Prototype*/
state_def(Logic_waiting);
state_def(Logic_driving);

/*State Function Address
 *state(Logic_waiting);
 *state(Logic_driving);*/

/*Declaring A Global Pointer To State Function*/
extern state_ptr(Logic_state_ptr);

enum {
	Logic_waiting, Logic_driving
} Logic_state_id;

#endif /* LOGIC_H_ */
