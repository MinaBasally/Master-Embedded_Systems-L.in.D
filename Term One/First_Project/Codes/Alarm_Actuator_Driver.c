/*
 *  Alarm_Actuator_Driver.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Mina
 *
 */

#include "Alarm_Actuator_Driver.h"
#include "state.h"
#include "GPIO_Map.h"
#include "stdio.h"
/*#include "stdlib.h"*/



enum {
	Alarm_Actuator_Driver_init,
	Alarm_Actuator_Driver_Alarm_OFF,
	Alarm_Actuator_Driver_Alarm_ON
} Alarm_Actuator_Driver_state_id;



/*Defining A Global Pointer To State Function*/
state_ptr(Alarm_Actuator_Driver_state_ptr) = state(Alarm_Actuator_Driver_init);



/*Interface Function Definition*/
void Raise_Alarm() {
	SET_BIT(GPIOA_ODR, 13);
}

void Stop_Alarm() {
	RESET_BIT(GPIOA_ODR, 13);
}



/*States Functions Definitions*/
state_def(Alarm_Actuator_Driver_init) {
	Alarm_Actuator_Driver_state_id = Alarm_Actuator_Driver_init;
	/*defPRINTF("Alarm_Actuator_Driver initialization...Done\n");*/
	/*Alarm_Actuator_Driver_state_ptr = state(Alarm_Actuator_Driver_Alarm_OFF);
	 Alarm_Actuator_Driver_state_ptr();*/
}



state_def(Alarm_Actuator_Driver_Alarm_OFF) {
	Alarm_Actuator_Driver_state_id = Alarm_Actuator_Driver_Alarm_OFF;
	Stop_Alarm();
}



state_def(Alarm_Actuator_Driver_Alarm_ON) {
	Alarm_Actuator_Driver_state_id = Alarm_Actuator_Driver_Alarm_ON;
	Raise_Alarm();
}
