> This is an STM32F103x6 Baremetal Software to test My HD44780U_LCD DRIVER.
> The APIs included in the HD44780U_LCD DRIVER are :
	#	LCD_Init
	#	LCD_Clear_Screen
	#	LCD_Write_Command
	#	LCD_Write_Char
	#	LCD_Write_String
	#	LCD_GoTo_XY
	#	LCD_Display_Number
	#	LCD_Display_Real_Number
	#	LCD_Custom_Character
> The 3 Control Pins of the LCD are connected to GPIOA (PA9,PA10,PA11), while The 8 Data Pins of the LCD are connected to GPIOA (PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7).
> The Software uses the APIs mentioned above to display different characters on the LCD.
> All {*.h & *.c} files were created and designed by myself.
> The Software was developed using STM32Cube-IDE and was auto built using ARM-GNU Cross-Toolchain v13.2.Release1.
> The Software was debugged, tested and verified using Proteus.
> A Simulation was done on Proteus for validation, and was recorded.



															From the author,
															  Mina Basally