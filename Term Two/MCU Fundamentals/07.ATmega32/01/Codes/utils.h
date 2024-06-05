/*
 *  utils.h
 *
 *  Created: 4/2/2024
 *   Author: Mina
 *
 */ 


#ifndef UTILS_H_
#define UTILS_H_



#define clearbit(reg, bit)			(reg &= ~(0b1 << bit))
#define setbit(reg, bit)			(reg |=  (0b1 << bit))
#define togglebit(reg, bit)			(reg ^=  (0b1 << bit))
#define readbit(reg, bit)			((reg & (0b1 << bit)) >> bit)



#endif /* UTILS_H_ */