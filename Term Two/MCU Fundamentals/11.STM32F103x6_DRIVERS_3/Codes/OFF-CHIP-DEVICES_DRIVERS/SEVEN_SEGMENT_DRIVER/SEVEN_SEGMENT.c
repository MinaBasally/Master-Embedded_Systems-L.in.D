/*
 *  SEVEN_SEGMENT.c
 *
 *   Created on: Apr 19, 2024
 *       Author: Mina
 *
 */



#include "SEVEN_SEGMENT.h"



/**========================================================================================================
 * @Fn				-void SEVEN_SEGMENT_Pin_Init.
 * @brief 			-Initializes the GPIOx PINy according to the specified parameters in the PinConfig_t.
 * @param  [in] 	-GPIOx: to select a specific GPIO Instant, where x can be (A..E) depending on the GPIO Instant used.
 * @param  [in] 	-PinConfig pointer to a GPIO_PinConfig_t structure that contains the configuration information
 * 					for the specified GPIO PIN.
 * @retval [out] 	-none.
 * Note				-Stm32F103x6 MCU has GPIO Module Instants A,B,C,D,E.
 * 				 	But LQFP48 Package has ALL OF A&B instants pins, and only PART OF C&D instants pins are
 * 				 	exported as external PINS from the MCU.
 */
void SEVEN_SEGMENT_Pin_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	MCAL_GPIO_Init(GPIOx, PinConfig);
}



void SEVEN_SEGMENT_Pin_a_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	SEVEN_SEGMENT_Pin_Init(GPIOx, PinConfig);
}



void SEVEN_SEGMENT_Pin_b_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	SEVEN_SEGMENT_Pin_Init(GPIOx, PinConfig);
}



void SEVEN_SEGMENT_Pin_c_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	SEVEN_SEGMENT_Pin_Init(GPIOx, PinConfig);
}



void SEVEN_SEGMENT_Pin_d_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	SEVEN_SEGMENT_Pin_Init(GPIOx, PinConfig);
}



void SEVEN_SEGMENT_Pin_e_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	SEVEN_SEGMENT_Pin_Init(GPIOx, PinConfig);
}



void SEVEN_SEGMENT_Pin_f_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	SEVEN_SEGMENT_Pin_Init(GPIOx, PinConfig);
}



void SEVEN_SEGMENT_Pin_g_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	SEVEN_SEGMENT_Pin_Init(GPIOx, PinConfig);
}
