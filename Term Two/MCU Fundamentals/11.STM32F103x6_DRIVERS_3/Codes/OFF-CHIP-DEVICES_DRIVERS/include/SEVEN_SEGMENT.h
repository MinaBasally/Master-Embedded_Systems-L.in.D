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



#define ZERO 			0x01
#define ONE 			0x4F
#define TWO 			0x12
#define THREE 			0x06
#define FOUR 			0x4C
#define FIVE 			0x24
#define SIX 			0x20
#define SEVEN 			0x0D
#define EIGHT 			0x00
#define NINE 			0x04



//#define ZERO 			0x01
//#define ONE 			0x79
//#define TWO 			0x24
//#define THREE 		0x30
//#define FOUR 			0x4C
//#define FIVE 			0x12
//#define SIX 			0x02
//#define SEVEN 		0x19
//#define EIGHT 		0x00
//#define NINE 			0x10



void SEVEN_SEGMENT_Pin_a_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_b_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_c_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_d_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_e_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_f_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void SEVEN_SEGMENT_Pin_g_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);



#endif /* SEVEN_SEGMENT_H_ */
