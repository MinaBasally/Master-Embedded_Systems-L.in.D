/*
 *  main.c
 *
 *  Created on: Jan 20, 2024
 *      Author: Mina
 *
 */

#include "UltrasonicSensor.h"
#include "Logic.h"
#include "DCMotor.h"
#include "stdio.h"

void setup() {
	/*initialize all the drivers*/
	/*initialize IRQs(Interrupt ReQuests)...*/
	/*initialize HAL US-Sensor_Driver & DC-Motor_Driver*/

	unsigned int i;
	for (i = 0; i < 30000; i++)
		; /*arbitrary delay*/

	/*initialize all modules*/
	US_state_ptr();
	DCMotor_state_ptr();

	for (i = 0; i < 30000; i++)
		; /*arbitrary delay*/
}

int main() {
	setup();
	unsigned int i;

	while (1) {
		US_state_ptr();
		Logic_state_ptr();
		DCMotor_state_ptr();

		for (i = 0; i < 30000; i++)
			; /*arbitrary delay*/
	}

	return 0;
}
