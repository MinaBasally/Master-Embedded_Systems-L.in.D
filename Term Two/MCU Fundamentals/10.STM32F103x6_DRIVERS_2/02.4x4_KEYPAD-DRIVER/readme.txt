> This is an STM32F103x6 Baremetal Software to test My 4x4_KEYPAD-DRIVER.
> The APIs included in the 4x4_KEYPAD-DRIVER are :
	#	Keypad_Init
	#	Keypad_Get_Key
> The 8 pins of the keypad are connected to GPIOB (PB0,PB1,PB3,PB4,PB5,PB6,PB7,PB8).
> The Software uses the APIs mentioned above together with the HD44780U_LCD-DRIVER-APIs to display the pressed key on the LCD whenever a key is pressed.
> The 3 Control Pins of the LCD are connected to GPIOA (PA9,PA10,PA11), while The 8 Data Pins of the LCD are connected to GPIOA (PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7).
> All {*.h & *.c} files were created and designed by myself.
> The Software was developed using STM32Cube-IDE and was auto built using ARM-GNU Cross-Toolchain v13.2.Release1.
> The Software was debugged, tested and verified using Proteus.
> A Simulation was done on Proteus for validation, and was recorded.



															From the author,
															  Mina Basally