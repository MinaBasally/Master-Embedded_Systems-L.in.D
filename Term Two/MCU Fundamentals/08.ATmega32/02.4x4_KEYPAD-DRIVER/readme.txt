> This is an ATmega32 Baremetal Software to test My 4x4_KEYPAD-DRIVER.
> The APIs included in the 4x4_KEYPAD-DRIVER are :
	#	Keypad_Init
	#	Keypad_Get_Key
> The 8 pins of the keypad are connected to I/O (PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7).
> The Software uses the APIs mentioned above together with the HD44780U_LCD-DRIVER-APIs to display the pressed key on the LCD whenever a key is pressed.
> The 3 Control Pins of the LCD are connected to I/O (PB1,PB2,PB3), while The 8 Data Pins of the LCD are connected to I/O (PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7).
> All {*.h & *.c} files were created and designed by myself.
> The Software was developed using Atmel Studio and was auto built using AVR 8-bit GNU Cross-Toolchain (3.6.2.1778).
> The Software was debugged, tested and verified using Proteus.
> A Simulation was done on Proteus, and was recorded.



															From the author,
															  Mina Basally