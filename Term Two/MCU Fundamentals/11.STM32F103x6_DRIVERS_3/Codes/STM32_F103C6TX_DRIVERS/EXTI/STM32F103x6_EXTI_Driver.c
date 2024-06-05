/*
 *  STM32F103x6_EXTI_Driver.c
 *
 *   Created on: Apr 22, 2024
 *       Author: Mina
 *
 */

#include "STM32F103x6.h"
#include "STM32F103x6_EXTI_Driver.h"
#include "STM32F103x6_GPIO_Driver.h"



/*
 * ==========================================================================================
 * 							           Global Variables
 * ==========================================================================================
 */
void (* GP_IRQ_Callback[16])(void);		//array of pointers to functions



/*
 * ==========================================================================================
 * 							            Generic Macros
 * ==========================================================================================
 */
#define AFIO_EXTICR_ResetValue			0x00000000
#define EXTI_REGISTERS_ResetValue		0x00000000
#define EXTI_PR_ResetValue				0xFFFFFFFF

#define EXTI_Pxx_Map(x)		((x == GPIOA)? 0 : \
							 (x == GPIOB)? 1 : \
							 (x == GPIOC)? 2 : \
							 (x == GPIOD)? 3 : 0)



/*
 * ==========================================================================================
 * 							           Generic Functions
 * ==========================================================================================
 */
void Enable_NVIC(uint8_t IRQx)
{
    switch(IRQx)
    {
        case EXTI_L0_IRQ:
            NVIC_IRQ6_EXTI0_Enable;
            break;
        case EXTI_L1_IRQ:
            NVIC_IRQ7_EXTI1_Enable;
            break;
        case EXTI_L2_IRQ:
            NVIC_IRQ8_EXTI2_Enable;
            break;
        case EXTI_L3_IRQ:
            NVIC_IRQ9_EXTI3_Enable;
            break;
        case EXTI_L4_IRQ:
            NVIC_IRQ10_EXTI4_Enable;
            break;
        case EXTI_L5_IRQ:
        //case EXTI_L6_IRQ:
        //case EXTI_L7_IRQ:
        //case EXTI_L8_IRQ:
        //case EXTI_L9_IRQ:
            NVIC_IRQ23_EXTI9_5_Enable;
            break;
        case EXTI_L10_IRQ:
        //case EXTI_L11_IRQ:
        //case EXTI_L12_IRQ:
        //case EXTI_L13_IRQ:
        //case EXTI_L14_IRQ:
        //case EXTI_L15_IRQ:
            NVIC_IRQ40_EXTI15_10_Enable;
            break;
    }
}



void Disable_NVIC(uint8_t IRQx)
{
    switch(IRQx)
    {
    case EXTI_L0_IRQ:
        NVIC_IRQ6_EXTI0_Disable;
        break;
    case EXTI_L1_IRQ:
        NVIC_IRQ7_EXTI1_Disable;
        break;
    case EXTI_L2_IRQ:
        NVIC_IRQ8_EXTI2_Disable;
        break;
    case EXTI_L3_IRQ:
        NVIC_IRQ9_EXTI3_Disable;
        break;
    case EXTI_L4_IRQ:
        NVIC_IRQ10_EXTI4_Disable;
        break;
    case EXTI_L5_IRQ:
    //case EXTI_L6_IRQ:
    //case EXTI_L7_IRQ:
    //case EXTI_L8_IRQ:
    //case EXTI_L9_IRQ:
        NVIC_IRQ23_EXTI9_5_Disable;
        break;
    case EXTI_L10_IRQ:
    //case EXTI_L11_IRQ:
    //case EXTI_L12_IRQ:
    //case EXTI_L13_IRQ:
    //case EXTI_L14_IRQ:
    //case EXTI_L15_IRQ:
        NVIC_IRQ40_EXTI15_10_Disable;
        break;
    }
}



void Update_EXTI(EXTI_PinConfig_t *EXTI_config)
{
	//	1 - Set the EXTI given pin as AF FLOATING INPUT
	GPIO_PinConfig_t pinCfg;
	pinCfg.GPIO_PinNumber 	= EXTI_config->EXTI_Lx_Pyx.PinNumber;
	pinCfg.GPIO_PinMode  	= GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_config->EXTI_Lx_Pyx.EXTI_Port, &pinCfg);

	//	2 - Route the given pin to the corresponding EXTI line
	uint8_t AFIO_EXTICR_RegIndex, AFIO_EXTICR_BitField;
	AFIO_EXTICR_RegIndex =  EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber / 4;
	AFIO_EXTICR_BitField = (EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber % 4) * 4;

	AFIO->EXTICR[AFIO_EXTICR_RegIndex] &= ~(0xF << AFIO_EXTICR_BitField);	//Clear the bits at first
	AFIO->EXTICR[AFIO_EXTICR_RegIndex] |=  (EXTI_Pxx_Map(EXTI_config->EXTI_Lx_Pyx.EXTI_Port) << AFIO_EXTICR_BitField);

	//	3.1 - Configure the EXTI registers from the given config
	if (EXTI_config->EXTI_TriggerCase == EXTI_Trigger_Rising) {
		EXTI->RTSR |=  (1 << EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber);
		EXTI->FTSR &= ~(1 << EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber);
	} else if (EXTI_config->EXTI_TriggerCase == EXTI_Trigger_Falling) {
		EXTI->FTSR |=  (1 << EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber);
		EXTI->RTSR &= ~(1 << EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber);
	} else if (EXTI_config->EXTI_TriggerCase == EXTI_Trigger_RisingAndFalling) {
		EXTI->RTSR |=  (1 << EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber);
		EXTI->FTSR |=  (1 << EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber);
	}

	//	3.2 - Enabling/Disabling IRQ for both peripherals; EXTI & NVIC
	if (EXTI_config->IRQ_EN == EXTI_IRQ_ENABLE) {
		EXTI->IMR |=  (1 << EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber);	//Write 1 to remove mask from the IRQ
		Enable_NVIC(EXTI_config->EXTI_Lx_Pyx.IRQ_Number);
	} else if (EXTI_config->IRQ_EN == EXTI_IRQ_Disable) {
		EXTI->IMR &= ~(1 << EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber);	//Write 0 to mask the IRQ
		Disable_NVIC(EXTI_config->EXTI_Lx_Pyx.IRQ_Number);
	}

	//	4 - Update the IRQs-Handlers-Callbacks
	GP_IRQ_Callback[EXTI_config->EXTI_Lx_Pyx.EXTI_LineNumber] = EXTI_config->P_IRQ_CallBack;
}



///**************************************************************************************************************************
/*
 * ==========================================================================================================
 * 							              APIs Functions Definitions
 * ==========================================================================================================
 */
/**========================================================================================================
 * @Fn				-MCAL_EXTI_Init.
 * @brief 			-Initializes the EXTI Line x, AFIO & NVIC IRQs, and defines the IRQs-Handlers-Callbacks.
 * @param  [in] 	-EXTI_config; to set it refer to @ref EXTI_Define, @ref EXTI_Trigger_Define & @ref EXTI_IRQ_Define.
 * @retval [out] 	-none.
 * Note				-Stm32F103x6 MCU has GPIO Module Instants A,B,C,D,E.
 * 				 	But LQFP48 Package has ALL OF A&B instants pins, and only PART OF C&D instants pins are
 * 				 	exported as external PINS from the MCU.
 */
void MCAL_EXTI_Init(EXTI_PinConfig_t *EXTI_config)
{
	Update_EXTI(EXTI_config);
}



/**========================================================================================================
 * @Fn				-MCAL_EXTI_Update.
 * @brief 			-Updates the previous configuration of EXTI Line x.
 * @param  [in] 	-EXTI_config; to set it refer to @ref EXTI_Define, @ref EXTI_Trigger_Define & @ref EXTI_IRQ_Define.
 * @retval [out] 	-none.
 * Note				-Stm32F103x6 MCU has GPIO Module Instants A,B,C,D,E.
 * 				 	But LQFP48 Package has ALL OF A&B instants pins, and only PART OF C&D instants pins are
 * 				 	exported as external PINS from the MCU.
 */
void MCAL_EXTI_Update(EXTI_PinConfig_t *EXTI_config)
{
	Update_EXTI(EXTI_config);
}



/**========================================================================================================
 * @Fn				-MCAL_EXTI_Reset.
 * @brief 			-Resets ALL EXTI registers & AFIO EXTICR registers, and Disables ALL NVIC-EXTI-IRQs.
 * @param  [in] 	-none.
 * @retval [out] 	-none.
 * Note				-none.
 */
void MCAL_EXTI_Reset()
{
	//	1 - Write the reset values on AFIO_EXTICR to reset the EXTI_Lx_Pyx_Pxx mappings
	AFIO->EXTICR[0] = AFIO_EXTICR_ResetValue;
	AFIO->EXTICR[1] = AFIO_EXTICR_ResetValue;
	AFIO->EXTICR[2] = AFIO_EXTICR_ResetValue;
	AFIO->EXTICR[3] = AFIO_EXTICR_ResetValue;

	//	2 - Write the reset values on EXTI Registers to reset EXTI lines configurations
	EXTI->EMR		= EXTI_REGISTERS_ResetValue;
	EXTI->FTSR		= EXTI_REGISTERS_ResetValue;
	EXTI->IMR		= EXTI_REGISTERS_ResetValue;
	EXTI->RTSR		= EXTI_REGISTERS_ResetValue;
	EXTI->SWIER		= EXTI_REGISTERS_ResetValue;
	EXTI->PR		= EXTI_PR_ResetValue;			//W_C (write to clear)

	//	3 - Disable the EXTI IRQs of the NVIC
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI9_5_Disable;
	NVIC_IRQ40_EXTI15_10_Disable;
}



///**************************************************************************************************************************
/*
 * ==========================================================================================================
 * 							            EXTI_IRQHandlers Redefinitions
 * ==========================================================================================================
 */
void EXTI0_IRQHandler(void)  			/* EXTI Line0 interrupt */
{
	//Clear this IRQ from the Pending_Register immediately after the CPU Acknowledges the IRQ
	EXTI->PR |= (1<<0);
	//Call the Callback Function defined in the application layer
	GP_IRQ_Callback[0]();
}



void EXTI1_IRQHandler(void)         	/* EXTI Line1 interrupt */
{
	//Clear this IRQ from the Pending_Register immediately after the CPU Acknowledges the IRQ
	EXTI->PR |= (1<<1);
	//Call the Callback Function defined in the application layer
	GP_IRQ_Callback[1]();
}



void EXTI2_IRQHandler(void)         	/* EXTI Line2 interrupt */
{
	//Clear this IRQ from the Pending_Register immediately after the CPU Acknowledges the IRQ
	EXTI->PR |= (1<<2);
	//Call the Callback Function defined in the application layer
	GP_IRQ_Callback[2]();
}



void EXTI3_IRQHandler(void)          	/* EXTI Line3 interrupt */
{
	//Clear this IRQ from the Pending_Register immediately after the CPU Acknowledges the IRQ
	EXTI->PR |= (1<<3);
	//Call the Callback Function defined in the application layer
	GP_IRQ_Callback[3]();
}



void EXTI4_IRQHandler(void)          	/* EXTI Line4 interrupt */
{
	//Clear this IRQ from the Pending_Register immediately after the CPU Acknowledges the IRQ
	EXTI->PR |= (1<<4);
	//Call the Callback Function defined in the application layer
	GP_IRQ_Callback[4]();
}



void EXTI9_5_IRQHandler(void)        	/* EXTI Line[9:5] interrupts */
{
	if(EXTI->PR & (1<<5))  {EXTI->PR |= (1<<5); GP_IRQ_Callback[5]();}
	if(EXTI->PR & (1<<6))  {EXTI->PR |= (1<<6); GP_IRQ_Callback[6]();}
	if(EXTI->PR & (1<<7))  {EXTI->PR |= (1<<7); GP_IRQ_Callback[7]();}
	if(EXTI->PR & (1<<8))  {EXTI->PR |= (1<<8); GP_IRQ_Callback[8]();}
	if(EXTI->PR & (1<<9))  {EXTI->PR |= (1<<9); GP_IRQ_Callback[9]();}
}



void EXTI15_10_IRQHandler(void)      	/* EXTI Line[15:10] interrupts */
{
	if(EXTI->PR & (1<<10))  {EXTI->PR |= (1<<10); GP_IRQ_Callback[10]();}
	if(EXTI->PR & (1<<11))  {EXTI->PR |= (1<<11); GP_IRQ_Callback[11]();}
	if(EXTI->PR & (1<<12))  {EXTI->PR |= (1<<12); GP_IRQ_Callback[12]();}
	if(EXTI->PR & (1<<13))  {EXTI->PR |= (1<<13); GP_IRQ_Callback[13]();}
	if(EXTI->PR & (1<<14))  {EXTI->PR |= (1<<14); GP_IRQ_Callback[14]();}
	if(EXTI->PR & (1<<15))  {EXTI->PR |= (1<<15); GP_IRQ_Callback[15]();}
}
