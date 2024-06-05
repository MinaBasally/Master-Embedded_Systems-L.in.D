/*
 *  DRIVERS.c
 *
 *  Created: 5/1/2024
 *  Author : Mina Basally
 *
 */

#include "ATmega32_IO_DRIVER.h"
#include "LCD.h"


int main(void)
{
	LCD_Init();
	LCD_Write_String("Learn-in-Depth");

    while (1) 
    {
    }
}