/*
 *  DCMotor.h
 *
 *  Created on: Jan 19, 2024
 *      Author: Mina
 *
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "state.h"
#include "stdio.h"
#include "stdlib.h"

/*State Function Prototype*/
state_def(DCMotor_init);
state_def(DCMotor_idle);
state_def(DCMotor_running);

/*State Functions Addresses
 *state(DCMotor_init);
 *state(DCMotor_idle);
 *state(DCMotor_running);*/

/*Declaring A Global Pointer To State Function*/
extern state_ptr(DCMotor_state_ptr);

enum {
	DCMotor_init, DCMotor_idle, DCMotor_running
} DCMotor_state_id;

#endif /* DCMOTOR_H_ */
