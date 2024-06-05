> This is an STM32F103C6 Baremetal Software to toggle an LED using GPIOA.
> The same Software was redeveloped 3 times to configure The STM32F103C6 Board to run with 3 different Clock and Frequency settings as follows :
	Configuration 1 --> The Default Clock and Frequency settings.
	Configuration 2 --> Clock Source: internal HSI_RC,  APB1 Bus frequency = 4 MHz,   APB2 Bus frequency = 2 MHz,   AHB frequency = 8 MHz,   SysClk = 8 MHz.
	Configuration 3 --> Clock Source: internal HSI_RC,  APB1 Bus frequency = 16 MHz,  APB2 Bus frequency = 8 MHz,   AHB frequency = 32 MHz,  SysClk = 32 MHz.
> All {*.h, *.c, *.s, *.ld & make} files were created and designed by myself.
> The Software was cross-compiled using ARM-GNU Cross-Toolchain v13.2.Release1.
> The Software was tested and verified using Keil uVision.
> A Simulation was done on Keil uVision, and was recorded.



															From the author,
															  Mina Basally