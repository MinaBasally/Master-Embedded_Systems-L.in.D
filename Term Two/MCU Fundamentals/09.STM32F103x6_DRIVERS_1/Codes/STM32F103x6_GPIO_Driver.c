/*
 *  STM32F103x6_GPIO_Driver.c
 *
 *   Created on: Apr 11, 2024
 *       Author: Mina
 *
 */

#include "STM32F103x6.h"
#include "STM32F103x6_GPIO_Driver.h"



uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber) {
	//	from pin 0 to 7 CRL
	case GPIO_PIN_0:
		return 0 ;
		break ;
	case GPIO_PIN_1:
		return 4 ;
		break ;
	case GPIO_PIN_2:
		return 8 ;
		break ;
	case GPIO_PIN_3:
		return 12 ;
		break ;
	case GPIO_PIN_4:
		return 16 ;
		break ;
	case GPIO_PIN_5:
		return 20 ;
		break ;
	case GPIO_PIN_6:
		return 24 ;
		break ;
	case GPIO_PIN_7:
		return 28 ;
		break ;

	//	from pin 8 to 15 CRH
	case GPIO_PIN_8:
		return 0 ;
		break ;
	case GPIO_PIN_9:
		return 4 ;
		break ;
	case GPIO_PIN_10:
		return 8 ;
		break ;
	case GPIO_PIN_11:
		return 12 ;
		break ;
	case GPIO_PIN_12:
		return 16 ;
		break ;
	case GPIO_PIN_13:
		return 20 ;
		break ;
	case GPIO_PIN_14:
		return 24 ;
		break ;
	case GPIO_PIN_15:
		return 28 ;
		break ;
	}

	return 0 ;
}



/**========================================================================================================
 * @Fn				-MCAL_GPIO_Init.
 * @brief 			-Initializes the GPIOx PINy according to the specified parameters in the PinConfig_t.
 * @param  [in] 	-GPIOx: to select a specific GPIO Instant, where x can be (A..E) depending on the GPIO Instant used.
 * @param  [in] 	-PinConfig pointer to a GPIO_PinConfig_t structure that contains the configuration information
 * 					for the specified GPIO PIN.
 * @retval [out] 	-none.
 * Note				-Stm32F103x6 MCU has GPIO Module Instants A,B,C,D,E.
 * 				 	But LQFP48 Package has ALL OF A&B instants pins, and only PART OF C&D instants pins that are
 * 				 	exported as external PINS from the MCU.
 */
void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	//	Port configuration Register low  (GPIOx_CRL) Configures PINS from 0 >>> 7
	//	Port configuration Register High (GPIOx_CRH) Configures PINS from 8 >>> 15
	volatile uint32_t *ConfigReg = NULL;
	uint8_t PinModeVal = 0;
	ConfigReg = (PinConfig->GPIO_PinNumber > GPIO_PIN_7)?  &GPIOx->CRH : &GPIOx->CRL;
	uint32_t CRLH_Position = (uint32_t)Get_CRLH_Position(PinConfig->GPIO_PinNumber);

	//	clear CNF[1:0] bits & MODE[1:0] bits
	*(ConfigReg) &= (~(0xF << CRLH_Position));

	//	if Pin is output
	if (PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_AF_OD
			|| PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_AF_PP
			|| PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_OD
			|| PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_PP)
	{
		//	Configure CNF[1:0] bits & MODE[1:0] bits
		PinModeVal = ((((PinConfig->GPIO_PinMode - 4) << 2) | (PinConfig->GPIO_Pin_OutputSpeed))  & 0x0F);
	}
	//	else pin is input
	//	MODE =  00: Input Mode (reset state)
	else
	{
		//	in case of input analog or input floating
		if((PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_ANALOG) || (PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_FLO))
		{
			PinModeVal = (((PinConfig->GPIO_PinMode << 2) | (0x0))  & 0x0F);
		}
		//	in case of Alternate Function
		else if (PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_AF)
		{
			PinModeVal = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x0)  & 0x0F);  // AF Floating Input
		}
		//	in case of Pull-Up or Pull-Down
		else
		{
			PinModeVal = ((((GPIO_MODE_INPUT_PU) << 2) | 0x0)  & 0x0F);
			//	in case of Pull-Up
			if(PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_PU)
			{
				//	PxODR = 1 Input Pull-Up :Table 20. Port bit configuration table
				GPIOx->ODR |= (uint32_t)PinConfig->GPIO_PinNumber;
			}
			//	in case of Pull-Down
			else
			{
				//	PxODR = 0 Input Pull-Down :Table 20. Port bit configuration table
				GPIOx->ODR &= ~((uint32_t)PinConfig->GPIO_PinNumber);
			}
		}
	}
	//	write on the CRL or CRH
	(*ConfigReg) |= (((uint32_t)PinModeVal) << CRLH_Position);
}



void MCAL_GPIO_Reset (GPIO_TypeDef *GPIOx)
{
	/* Reset Registers Manually */
	//	GPIOx->BRR  = 0x00000000;
	//	GPIOx->BSRR = 0x00000000;
	//	GPIOx->CRH  = 0x44444444;
	//	GPIOx->CRL  = 0x44444444;
	////	GPIOx->IDR;  (READ Only)
	//	GPIOx->LCKR = 0x00000000;
	//	GPIOx->ODR  = 0x00000000;


	/* Reset Registers Automatically using the Reset Controller(RCC) */
	//	(RCC->APB2RSTR) : APB2 peripheral reset register
	//	Set and cleared by software.
	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |=  (1<<2);  // Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}

	if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=  (1<<3);  // Bit 3 IOPARST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}

	if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |=  (1<<4);  // Bit 4 IOPARST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}

	if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |=  (1<<5);  // Bit 5 IOPARST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}

	if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |=  (1<<6);  // Bit 6 IOPARST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);
	}
}



/**========================================================================================================
 * @Fn				-MCAL_GPIO_ReadPin.
 * @brief 			-Read a Specific PIN.
 * @param  [in] 	-GPIOx: to select a specific GPIO Instant, where x can be (A..E) depending on the GPIO Instant used.
 * @param  [in] 	-PinNumber: specifies the port bit to be read, refer to @ref GPIO_PINS_define.
 * @retval [out] 	-the input-pin value (1 or 0).
 * Note				-none.
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	uint8_t BitVal;

	if (((uint16_t)GPIOx->IDR) & PinNumber)
	{
		BitVal = GPIO_PIN_SET;
	}
	else
	{
		BitVal = GPIO_PIN_CLEAR;
	}
	return BitVal;
}



/**========================================================================================================
 * @Fn					-MCAL_GPIO_ReadPort.
 * @brief 				-read the input-port value.
 * @param  [in] 		-GPIOx: to select a specific GPIO Instant, where x can be (A..E) depending on the GPIO Instant used.
 * @retval [out] 		-the input-port value.
 * Note					-none.
 */
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx)
{
	uint16_t PortVal;
	PortVal = ((uint16_t)GPIOx->IDR);
	return PortVal;
}



/**========================================================================================================
 * @Fn					-MCAL_GPIO_WritePin.
 * @brief 				-write on an output pin.
 * @param  [in] 		-GPIOx: to select a specific GPIO Instant, where x can be (A..E) depending on the GPIO Instant used.
 * @param  [in] 		-PinNumber: specifies the port bit to be written on, refer to @ref GPIO_PINS_define.
 * @param  [in] 		-Value: the value to be written on the output pin (1 or 0).
 * @retval [out]		-none.
 * Note					-none.
 */
void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx, uint16_t PinNumber , uint8_t Value)
{
	if (Value)
		//GPIOx->ODR |= PinNumber ;

		//	or
		//	Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//	These bits are write-only and can be accessed in Word mode only.
		//	0: No action on the corresponding ODRx bit
		//	1: Set the corresponding ODRx bit
		GPIOx->BSRR = PinNumber;
	else
	{
		//	Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		//	These bits are write-only and can be accessed in Word mode only.
		//	0: No action on the corresponding ODRx bit
		//	1: Reset the corresponding ODRx bit
		GPIOx->BRR = PinNumber;
	}

}



/**========================================================================================================
 * @Fn					-MCAL_GPIO_WritePort.
 * @brief 				-write on an output port.
 * @param  [in] 		-GPIOx: to select a specific GPIO Instant, where x can be (A..E) depending on the GPIO Instant used.
 * @param  [in] 		-Value: the value to be written on the output port.
 * @retval [out]		-none.
 * Note					-none.
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx, uint16_t Value)
{
	GPIOx->ODR = ((uint32_t)Value);
}



/**========================================================================================================
 * @Fn					-MCAL_GPIO_TogglePin.
 * @brief 				-Toggle the specified output pin.
 * @param  [in] 		-GPIOx: to select a specific GPIO Instant, where x can be (A..E) depending on the GPIO Instant used.
 * @param  [in] 		-PinNumber: specifies the port bit to be toggled, refer to @ref GPIO_PINS_define.
 * @retval [out] 		-none.
 * Note					-none.
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx, uint16_t PinNumber )
{
	GPIOx->ODR ^= ((uint32_t)PinNumber);
}



/**========================================================================================================
 * @Fn					-MCAL_GPIO_LockPin.
 * @brief 				-The Locking mechanism allows the IO pin configuration to be frozen.
 * @param  [in] 		-GPIOx: to select a specific GPIO Instant, where x can be (A..E) depending on the GPIO Instant used.
 * @param  [in] 		-PinNumber: specifies the port bit to be locked, refer to @ref GPIO_PINS_define.
 * @retval [out]		-ENABLED(1) if pin configuration was locked successfully Or ERROR(0) if locking failed, refer to @ref GPIO_LOCK_STATE.
 * Note					-none.
 */
uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked

	//	Set LCKK[16]
	volatile uint32_t temp = (1<<16);

	//	set the key
	temp |= ((uint32_t)PinNumber);

	//	Write 1
	GPIOx->LCKR = temp;
	//	Write 0
	GPIOx->LCKR = PinNumber;
	//	Write 1
	GPIOx->LCKR = temp;
	//	Read 0
	temp = GPIOx->LCKR;
	//	Read 1 (this read is optional but confirms that the lock is active)
	if ((GPIOx->LCKR) & (1<<16))
	{
		return (uint8_t)GPIO_LOCK_Enabled;
	}
	else
	{
		return (uint8_t)GPIO_LOCK_ERROR;
	}
}
