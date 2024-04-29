/*
 *  Pressure_Sensor_Driver.h
 *
 *  Created on: Jan 29, 2024
 *      Author: Mina
 *
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

#include "state.h"
#include "stdio.h"
/*#include "stdlib.h"*/



/*State Function Prototype*/
state_def(Pressure_Sensor_Driver_init);
state_def(Pressure_Sensor_Driver_reading);
state_def(Pressure_Sensor_Driver_waiting);



/*State Function Address
 *state(Pressure_Sensor_Driver_init);
 *state(Pressure_Sensor_Driver_reading);
 *state(Pressure_Sensor_Driver_waiting);*/



int Read_From_Pressure_Sensor();



/*Declaring A Global Pointer To State Function*/
extern state_ptr(Pressure_Sensor_Driver_state_ptr);



#endif /* PRESSURE_SENSOR_DRIVER_H_ */
