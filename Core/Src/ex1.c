/*
 * ex1.c
 *
 *  Created on: Aug 29, 2025
 *      Author: qwein
 */
#include "ex1.h"

#define LED_ON 0
#define LED_OFF 1
#define TIME 2

void exercise1_init() {
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, LED_OFF);
}

void exercise1_run() {
	int counter = 2;

	while(1) {
		counter--;
		if(counter < 0) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			counter = TIME;
		}
		HAL_Delay(1000);
	}
}

