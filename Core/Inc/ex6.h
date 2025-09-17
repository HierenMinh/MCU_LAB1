/*
 * ex6.h
 *
 *  Created on: Aug 29, 2025
 *      Author: qwein
 */

#ifndef INC_EX6_H_
#define INC_EX6_H_

#include "main.h"
#include "ex6.h"

extern GPIO_TypeDef* clkPorts[12];
extern uint16_t clkPins[12];

void exercise6_init();

void exercise6_run();



#endif /* INC_EX6_H_ */
