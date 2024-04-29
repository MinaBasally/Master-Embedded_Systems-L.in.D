/*
 *  Alarm_Actuator_Driver.h
 *
 *  Created on: Jan 19, 2024
 *      Author: Mina
 *
 */

#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_

#include "state.h"
#include "stdio.h"
/*#include "stdlib.h"*/



/*State Function Prototype*/
state_def(Alarm_Actuator_Driver_init);
state_def(Alarm_Actuator_Driver_Alarm_OFF);
state_def(Alarm_Actuator_Driver_Alarm_ON);



/*State Function Address
 *state(Alarm_Actuator_Driver_init);
 *state(Alarm_Actuator_Driver_Alarm_OFF);
 *state(Alarm_Actuator_Driver_Alarm_ON);*/



void Raise_Alarm();
void Stop_Alarm();



/*Declaring A Global Pointer To State Function*/
extern state_ptr(Alarm_Actuator_Driver_state_ptr);



#endif /* ALARM_ACTUATOR_DRIVER_H_ */
