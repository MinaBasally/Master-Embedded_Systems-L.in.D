/*
 *  Main_System_Algorithm.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Mina
 *
 */

#include "Pressure_Sensor_Driver.h"
#include "Main_System_Algorithm.h"
#include "Alarm_Actuator_Driver.h"
#include "state.h"
#include "GPIO_Map.h"
#include "stdio.h"
/*#include "stdlib.h"*/



void GPIO_INITIALIZATION() {
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}

void Delay(int nCount) {
	for (; nCount != 0; nCount--)
		;
}

void setup() {
	/*initialize all the drivers*/
	GPIO_INITIALIZATION();
	Pressure_Sensor_Driver_state_ptr();
	Alarm_Actuator_Driver_state_ptr();
	/*initialize IRQs(Interrupt ReQuests)...*/
	/*initialize HAL Pressure_Sensor_Driver & Alarm_Actuator_Driver*/
	Delay(30000); /*arbitrary delay*/
}



int pressure = 1;
int *pressure_ptr = &pressure;
/**pressure_ptr = 1;*/
unsigned int Threshold = 20;
enum {
	Main_System_Algorithm_processing,
	Main_System_Algorithm_High_Pressure_Detected,
	Main_System_Algorithm_Alarm_Monitoring
} Main_System_Algorithm_state_id;



/*Defining A Global Pointer To State Function*/
state_ptr(Main_System_Algorithm_state_ptr) = state(Main_System_Algorithm_processing);



int main() {
	setup();

	while (1) {
		Main_System_Algorithm_state_ptr();
	}

	return 0;
}



/*States Functions Definitions*/
state_def(Main_System_Algorithm_processing) {
	Main_System_Algorithm_state_id = Main_System_Algorithm_processing;

	Pressure_Sensor_Driver_state_ptr = state(Pressure_Sensor_Driver_reading);
	Pressure_Sensor_Driver_state_ptr();
	Pressure_Sensor_Driver_state_ptr = state(Pressure_Sensor_Driver_waiting);
	Pressure_Sensor_Driver_state_ptr();

	/*
	 if (pressure > Threshold) {
	 Main_System_Algorithm_state_ptr = state(Main_System_Algorithm_High_Pressure_Detected);

	 } else {
	 Main_System_Algorithm_state_ptr = state(Main_System_Algorithm_processing);
	 }
	 */

	(pressure > Threshold) ?
			(Main_System_Algorithm_state_ptr = state(
					Main_System_Algorithm_High_Pressure_Detected)) :
			(Main_System_Algorithm_state_ptr = state(
					Main_System_Algorithm_processing));
}



state_def(Main_System_Algorithm_High_Pressure_Detected) {
	Main_System_Algorithm_state_id =
			Main_System_Algorithm_High_Pressure_Detected;

	/*Raise_Alarm*/
	Alarm_Actuator_Driver_state_ptr = state(Alarm_Actuator_Driver_Alarm_ON);
	Alarm_Actuator_Driver_state_ptr();

	/*Monitor_Alarm*/
	Main_System_Algorithm_state_ptr = state(
			Main_System_Algorithm_Alarm_Monitoring);
}



state_def(Main_System_Algorithm_Alarm_Monitoring) {
	Main_System_Algorithm_state_id = Main_System_Algorithm_Alarm_Monitoring;

	/*Alarm_Timer*/
	Delay(30000);

	/*Stop_Alarm*/
	Alarm_Actuator_Driver_state_ptr = state(Alarm_Actuator_Driver_Alarm_OFF);
	Alarm_Actuator_Driver_state_ptr();
	Main_System_Algorithm_state_ptr = state(Main_System_Algorithm_processing);
}
