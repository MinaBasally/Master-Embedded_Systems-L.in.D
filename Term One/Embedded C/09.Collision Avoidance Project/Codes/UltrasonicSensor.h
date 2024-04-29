/*
 *  UltrasonicSensor.h
 *
 *  Created on: Jan 19, 2024
 *      Author: Mina
 *
 */

#ifndef ULTRASONICSENSOR_H_
#define ULTRASONICSENSOR_H_

#include "state.h"
#include "stdio.h"
#include "stdlib.h"

/*State Function Prototype*/
state_def(US_init);
state_def(US_busy);

/*State Function Address
 *state(US_init);
 *state(US_busy);*/

/*Declaring A Global Pointer To State Function*/
extern state_ptr(US_state_ptr);

enum {
	US_init, US_busy
} US_state_id;

#endif /* ULTRASONICSENSOR_H_ */
