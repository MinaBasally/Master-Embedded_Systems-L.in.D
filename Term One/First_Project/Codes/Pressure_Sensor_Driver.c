/*
 *  Pressure_Sensor_Driver.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Mina
 *
 */

#include "Pressure_Sensor_Driver.h"
#include "state.h"
#include "GPIO_Map.h"
#include "stdio.h"
/*#include "stdlib.h"*/



extern int *pressure_ptr;
enum {
	Pressure_Sensor_Driver_init,
	Pressure_Sensor_Driver_reading,
	Pressure_Sensor_Driver_waiting
} Pressure_Sensor_Driver_state_id;



/*Interface Function Definition*/
int Read_From_Pressure_Sensor() {
	return (GPIOA_IDR & 0xFF);
}



/*Defining A Global Pointer To State Function*/
state_ptr(Pressure_Sensor_Driver_state_ptr) = state(Pressure_Sensor_Driver_init);



/*States Functions Definitions*/
state_def(Pressure_Sensor_Driver_init) {
	Pressure_Sensor_Driver_state_id = Pressure_Sensor_Driver_init;
	/*defPRINTF("Pressure Sensor initialization...Done\n");*/
}



state_def(Pressure_Sensor_Driver_reading) {
	Pressure_Sensor_Driver_state_id = Pressure_Sensor_Driver_reading;
	*pressure_ptr = Read_From_Pressure_Sensor();
}



state_def(Pressure_Sensor_Driver_waiting) {
	Pressure_Sensor_Driver_state_id = Pressure_Sensor_Driver_waiting;
}
