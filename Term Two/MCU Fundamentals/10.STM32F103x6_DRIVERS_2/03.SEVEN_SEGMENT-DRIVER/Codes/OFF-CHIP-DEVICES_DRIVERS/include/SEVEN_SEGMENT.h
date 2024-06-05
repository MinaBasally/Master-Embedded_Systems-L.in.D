/*
 *  SEVEN_SEGMENT.h
 *
 *   Created on: Apr 19, 2024
 *       Author: Mina
 *
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_



#include "STM32F103x6.h"
#include "STM32F103x6_GPIO_Driver.h"



#define _7SEG_ZERO 				0x01
#define _7SEG_ONE 				0x4F
#define _7SEG_TWO 				0x12
#define _7SEG_THREE 			0x06
#define _7SEG_FOUR 				0x4C
#define _7SEG_FIVE 				0x24
#define _7SEG_SIX 				0x20
#define _7SEG_SEVEN 			0x0D
#define _7SEG_EIGHT 			0x00
#define _7SEG_NINE 				0x04



//#define _7SEG_ZERO 			0x01
//#define _7SEG_ONE 			0x79
//#define _7SEG_TWO 			0x24
//#define _7SEG_THREE 			0x30
//#define _7SEG_FOUR 			0x4C
//#define _7SEG_FIVE 			0x12
//#define _7SEG_SIX 			0x02
//#define _7SEG_SEVEN 			0x19
//#define _7SEG_EIGHT 			0x00
//#define _7SEG_NINE 			0x10



void SEVEN_SEGMENT_Pin_a_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_b_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_c_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_d_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_e_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_f_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_g_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);



#endif /* SEVEN_SEGMENT_H_ */
