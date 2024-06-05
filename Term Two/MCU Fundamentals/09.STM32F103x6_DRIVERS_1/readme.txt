> This is an STM32F103x6 Baremetal Software to test My STM32F103x6 GPIO-DRIVER.
> The APIs included in this version of the GPIO DRIVER are :
	#	MCAL_GPIO_Init
	#	MCAL_GPIO_Reset
	#	MCAL_GPIO_ReadPin
	#	MCAL_GPIO_ReadPort
	#	MCAL_GPIO_WritePin
	#	MCAL_GPIO_WritePort
	#	MCAL_GPIO_TogglePin
	#	MCAL_GPIO_LockPin
> The Software toggles GPIOB->pin1 & GPIOB->pin13 using two push-buttons conntected to GPIOA->pin1 & GPIOA->pin13.
> Both input pins are configured as Floating Inputs, while both output pins are configured as Push-Pull Outputs.
> All {*.h & *.c} files were created and designed by myself.
> The Software was developed using STM32Cube-IDE and was auto built using ARM-GNU Cross-Toolchain v13.2.Release1.
> The Software was debugged, tested and verified using Keil uVision.
> A Simulation was done on Keil uVision, and was recorded.



															From the author,
															  Mina Basally