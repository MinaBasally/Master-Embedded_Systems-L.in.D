/*
 *  ATmega32_IO_Driver.c
 *
 *  Created: 5/2/2024
 *   Author: Mina
 *
 */ 

#include "ATmega32_IO_DRIVER.h"






/*
 * ==========================================================================================================
 * 							              APIs Functions Definitions
 * ==========================================================================================================
 */
/**========================================================================================================
 * @Fn				-MCAL_GPIO_ResetReg.
 * @brief 			-Reset a Specific REGISTER.
 * @param  [in] 	-GPIOx_REG: to select a specific GPIOx Register, where x can be (A..D) depending on the GPIO Instant used.
 * @retval [out] 	-none.
 * Note				-none.
 */
void MCAL_GPIO_ResetReg(uint8_t *GPIOx_REG)
{
	/* Reset Registers Manually */
	*GPIOx_REG  = 0x00;
}



/**========================================================================================================
 * @Fn				-MCAL_GPIO_ReadPin.
 * @brief 			-Read a Specific PIN.
 * @param  [in] 	-GPIOx_REG: to select a specific GPIOx Register, where x can be (A..D) depending on the GPIO Instant used.
 * @param  [in] 	-PinNumber: specifies the port bit to be read, refer to @ref GPIO_PINS_define.
 * @retval [out] 	-the input-pin value (1 or 0).
 * Note				-none.
 */
uint8_t MCAL_GPIO_ReadPin(uint8_t *GPIOx_REG, uint8_t PinNumber)
{
	uint8_t BitVal;

	if ((*GPIOx_REG) & PinNumber)
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
 * @param  [in] 		-GPIOx_REG: to select a specific GPIOx Register, where x can be (A..D) depending on the GPIO Instant used.
 * @retval [out] 		-the input-port value.
 * Note					-none.
 */
uint8_t MCAL_GPIO_ReadPort(uint8_t *GPIOx_REG)
{
	uint8_t PortVal;
	PortVal = (*GPIOx_REG);
	return PortVal;
}



/**========================================================================================================
 * @Fn					-MCAL_GPIO_WritePin.
 * @brief 				-write on an output pin.
 * @param  [in] 		-GPIOx_REG: to select a specific GPIOx Register, where x can be (A..D) depending on the GPIO Instant used.
 * @param  [in] 		-PinNumber: specifies the port bit to be written on, refer to @ref GPIO_PINS_define.
 * @param  [in] 		-Value: the value to be written on the output pin (1 or 0).
 * @retval [out]		-none.
 * Note					-none.
 */
void MCAL_GPIO_WritePin(uint8_t *GPIOx_REG, uint8_t PinNumber, uint8_t Value)
{
	if (Value)
	{
		*GPIOx_REG |= PinNumber;
	}
	else
	{
		*GPIOx_REG &= ~(PinNumber);
	}

}



/**========================================================================================================
 * @Fn					-MCAL_GPIO_WritePort.
 * @brief 				-write on an output port.
 * @param  [in] 		-GPIOx_REG: to select a specific GPIOx Register, where x can be (A..D) depending on the GPIO Instant used.
 * @param  [in] 		-Value: the value to be written on the output port.
 * @retval [out]		-none.
 * Note					-none.
 */
void MCAL_GPIO_WritePort(uint8_t *GPIOx_REG, uint8_t Value)
{
	*GPIOx_REG = (Value);
}



/**========================================================================================================
 * @Fn					-MCAL_GPIO_TogglePin.
 * @brief 				-Toggle the specified output pin.
 * @param  [in] 		-GPIOx_REG: to select a specific GPIOx Register, where x can be (A..D) depending on the GPIO Instant used.
 * @param  [in] 		-PinNumber: specifies the port bit to be toggled, refer to @ref GPIO_PINS_define.
 * @retval [out] 		-none.
 * Note					-none.
 */
void MCAL_GPIO_TogglePin(uint8_t *GPIOx_REG, uint8_t PinNumber)
{
	*GPIOx_REG ^= (PinNumber);
}