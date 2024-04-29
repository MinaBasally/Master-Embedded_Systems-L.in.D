/*
 *  Main_System_Algorithm.h
 *
 *  Created on: Jan 29, 2024
 *      Author: Mina
 *
 */

#ifndef MAIN_SYSTEM_ALGORITHM_H_
#define MAIN_SYSTEM_ALGORITHM_H_

#include "state.h"
#include "stdio.h"
/*#include "stdlib.h"*/



/*State Function Prototype*/
state_def(Main_System_Algorithm_processing);
state_def(Main_System_Algorithm_High_Pressure_Detected);
state_def(Main_System_Algorithm_Alarm_Monitoring);



/*State Function Address
 *state(Main_System_Algorithm_processing);
 *state(Main_System_Algorithm_High_Pressure_Detected);
 *state(Main_System_Algorithm_Alarm_Monitoring);*/



void GPIO_INITIALIZATION();
void Delay(int nCount);



/*Declaring A Global Pointer To State Function*/
extern state_ptr(Main_System_Algorithm_state_ptr);



#endif /* MAIN_SYSTEM_ALGORITHM_H_ */
