> This is an STM32F103x6 Baremetal Software to test My EXTI-DRIVER.
> The APIs included in the EXTI-DRIVER are :
	#	MCAL_EXTI_Init
	#	MCAL_EXTI_Update
	#	MCAL_EXTI_Reset
> The Software uses the APIs mentioned above together with the HD44780U_LCD-DRIVER-APIs to display a message on the LCD whenever the CPU receives a specified external interrupt from GPIOB-PIN(9).
> The 3 Control Pins of the LCD are connected to GPIOA (PA9,PA10,PA11), while The 8 Data Pins of the LCD are connected to GPIOA (PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7).
> All {*.h & *.c} files were created and designed by myself.
> The Software was developed using STM32Cube-IDE and was auto built using ARM-GNU Cross-Toolchain v13.2.Release1.
> The Software was debugged, tested and verified using Keil uVision.
> A Simulation was done on Proteus for validation, and was recorded.



															From the author,
															  Mina Basally