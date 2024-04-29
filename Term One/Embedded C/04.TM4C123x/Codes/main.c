/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Mina M. Basally
 * @brief          : Main program body
 ******************************************************************************
 */

#include "stdio.h"

 #if !defined(__SOFT_FP__) && defined(__ARM_FP)
 #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
 #endif



// Registers addresses
#define SYSCTL_BASE					0x400FE000
#define GPIOF_BASE					0x40025000
#define SYSCTL_RCGC2_R				  *((volatile unsigned long*)(SYSCTL_BASE + 0x00000108))
#define GPIOF_DATA_R_OFFSET			0x000003FC
#define GPIOF_DIR_R_OFFSET			0x00000400
#define GPIOF_DEN_R_OFFSET			0x0000051C



// Bit fields
typedef union {
	volatile unsigned long all_fields;
	struct {
		volatile unsigned long reserved :3;
		volatile unsigned long p3 :1;
	} pins;
} P_GPIOF_t;



int main(void) {
	unsigned long i;
	SYSCTL_RCGC2_R = 0x00000020;
	for (i = 0; i < 3000; i++) ; //arbitrary delay to make sure GPIO PORT(F) is up and running
	
	volatile P_GPIOF_t *const GPIOF_DATA_R = (volatile P_GPIOF_t*) (GPIOF_BASE + GPIOF_DATA_R_OFFSET);
	volatile P_GPIOF_t *const GPIOF_DIR_R  = (volatile P_GPIOF_t*) (GPIOF_BASE + GPIOF_DIR_R_OFFSET);
	volatile P_GPIOF_t *const GPIOF_DEN_R  = (volatile P_GPIOF_t*) (GPIOF_BASE + GPIOF_DEN_R_OFFSET);
	
	GPIOF_DIR_R->pins.p3  = 1;
	GPIOF_DEN_R->pins.p3  = 1;
	
	while (1) {
		GPIOF_DATA_R->pins.p3 = 1;
		for (i = 0; i < 300000; i++) ; //arbitrary delay

		GPIOF_DATA_R->pins.p3 = 0;
		for (i = 0; i < 300000; i++) ; //arbitrary delay
	}

	return 0;
}