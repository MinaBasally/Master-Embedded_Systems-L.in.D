/*
 *  DCMotor.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Mina
 *
 */

#include "DCMotor.h"
#include "state.h"
#include "stdio.h"
#include "stdlib.h"

#define defPRINTF(...)				{fflush(stdin); fflush(stdout);\
									 printf(__VA_ARGS__);\
									 fflush(stdin); fflush(stdout);}

extern unsigned int distance;
extern unsigned int speed;

/*Defining A Global Pointer To State Function*/
state_ptr(DCMotor_state_ptr) = state(DCMotor_init);

/*Interface Function Definition*/
void Logic_get_speed(unsigned int *s) {
	speed = *s;
	defPRINTF("Logic : speed = %u ----> DC-Motor\n", speed);
	(speed == 0) ?
			(DCMotor_state_ptr = state(DCMotor_idle)) : (DCMotor_state_ptr =
					state(DCMotor_running));
}

/*States Functions Definitions*/
state_def(DCMotor_init) {
	DCMotor_state_id = DCMotor_init;

	/*initialize DC-Motor_Driver*/

	defPRINTF("DC-Motor initialization...Done\n");
	DCMotor_state_ptr = state(DCMotor_idle);
	DCMotor_state_ptr();
}

state_def(DCMotor_idle) {
	DCMotor_state_id = DCMotor_idle;

	/*State Action: call PWM to set DC-Motor speed = 0*/

	/*print current DC-Motor state*/
	defPRINTF("DC-Motor State : idle...distance = %u , speed = %u\n", distance,
			speed);
}

state_def(DCMotor_running) {
	DCMotor_state_id = DCMotor_running;

	/*State Action: call PWM to set DC-Motor speed = 30*/

	/*print current DC-Motor state*/
	defPRINTF("DC-Motor State : running...distance = %u , speed = %u\n",
			distance, speed);
}
