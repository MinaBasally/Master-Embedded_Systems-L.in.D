/*
 *  UltrasonicSensor.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Mina
 *
 */

#include "UltrasonicSensor.h"
#include "state.h"
#include "stdio.h"
#include "stdlib.h"

#define defPRINTF(...)				{fflush(stdin); fflush(stdout);\
									 printf(__VA_ARGS__);\
									 fflush(stdin); fflush(stdout);}

unsigned int distance = 0;

/*this function will generate a random number in the range of l to u*/
unsigned int GenerateRandom(unsigned int l, unsigned int u) {
	unsigned int rand_num = ((unsigned int) rand() % (u - l + 1)) + l;
	return rand_num;
}

/*Defining A Global Pointer To State Function*/
state_ptr(US_state_ptr) = state(US_init);

/*States Functions Definitions*/
state_def(US_init) {
	US_state_id = US_init;

	/*initialize US-Sensor_Driver*/

	defPRINTF("Ultrasonic Sensor initialization...Done\n");
	US_state_ptr = state(US_busy);
}

state_def(US_busy) {
	US_state_id = US_busy;

	/*read from US sensor*/
	distance = GenerateRandom(45, 55);
	defPRINTF("US-Sensor State : busy...distance = %u\n", distance);

	/*send the measured distance to Logic*/
	US_get_dist(&distance);

	US_state_ptr = state(US_busy);
}
