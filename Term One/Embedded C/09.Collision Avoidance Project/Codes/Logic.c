/*
 *  Logic.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Mina
 *
 */

#include "Logic.h"
#include "state.h"
#include "stdio.h"
#include "stdlib.h"

#define defPRINTF(...)				{fflush(stdin); fflush(stdout);\
									 printf(__VA_ARGS__);\
									 fflush(stdin); fflush(stdout);}

extern unsigned int distance;
unsigned int Threshold = 50;
unsigned int speed = 0;

/*Defining A Global Pointer To State Function*/
state_ptr(Logic_state_ptr);

/*Interface Function Definition*/
void US_get_dist(unsigned int *d) {
	distance = *d;
	defPRINTF("US-Sensor : distance = %u ----> Logic\n", distance);
	(distance > Threshold) ?
			(Logic_state_ptr = state(Logic_driving)) :
			(Logic_state_ptr = state(Logic_waiting));
}

/*States Functions Definitions*/
state_def(Logic_waiting) {
	Logic_state_id = Logic_waiting;

	/*set speed = 0 and send it to DC Motor*/
	speed = 0;
	Logic_get_speed(&speed);
	defPRINTF("Logic State : waiting...distance = %u , speed = %u\n", distance,
			speed);
}

state_def(Logic_driving) {
	Logic_state_id = Logic_driving;

	/*set speed = 30 and send it to DC Motor*/
	speed = 30;
	Logic_get_speed(&speed);
	defPRINTF("Logic State : driving...distance = %u , speed = %u\n", distance,
			speed);
}
