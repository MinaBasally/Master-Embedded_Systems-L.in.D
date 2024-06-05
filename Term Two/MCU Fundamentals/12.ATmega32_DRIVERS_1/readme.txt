> This is an ATmega32 Baremetal Software to test My ATmega32 IO-DRIVER.
> The APIs included in this version of the IO DRIVER are :
	#	MCAL_GPIO_ResetReg
	#	MCAL_GPIO_ReadPin
	#	MCAL_GPIO_ReadPort
	#	MCAL_GPIO_WritePin
	#	MCAL_GPIO_WritePort
	#	MCAL_GPIO_TogglePin
> The Software uses the APIs mentioned above together with the HD44780U_LCD-DRIVER-APIs to display a message on the LCD.
> The 3 Control Pins of the LCD are connected to GPIOB (PB1,PB2,PB3), while The 4 Data Pins of the LCD are connected to GPIOA (PA4,PA5,PA6,PA7).
> All {*.h & *.c} files were created and designed by myself.
> The Software was developed using Atmel Studio and was auto built using AVR 8-bit GNU Cross-Toolchain (3.6.2.1778).
> The Software was debugged, tested and verified using Proteus.
> A Simulation was done on Proteus for validation, and was recorded.



															From the author,
															  Mina Basally