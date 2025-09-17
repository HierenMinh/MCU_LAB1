/*
 * ex6.c
 *
 *  Created on: Aug 29, 2025
 *      Author: qwein
 */
#include "ex6.h"

#define LED_ON 0
#define LED_OFF 1

#define CLK_PIN_NUM 12

GPIO_TypeDef* clkPorts[12] = {
    CLK_12_GPIO_Port, CLK_1_GPIO_Port, CLK_2_GPIO_Port, CLK_3_GPIO_Port,
    CLK_4_GPIO_Port, CLK_5_GPIO_Port, CLK_6_GPIO_Port, CLK_7_GPIO_Port,
    CLK_8_GPIO_Port, CLK_9_GPIO_Port, CLK_10_GPIO_Port, CLK_11_GPIO_Port
};

uint16_t clkPins[12] = {
    CLK_12_Pin, CLK_1_Pin, CLK_2_Pin, CLK_3_Pin,
    CLK_4_Pin, CLK_5_Pin, CLK_6_Pin, CLK_7_Pin,
    CLK_8_Pin, CLK_9_Pin, CLK_10_Pin, CLK_11_Pin
};

void exercise6_init() {
	for(int i = 0; i < CLK_PIN_NUM; i++) {
		HAL_GPIO_WritePin(clkPorts[i], clkPins[i], LED_OFF);
	}
}

void exercise6_run() {
	int idx = 5;
	while(1) {
		if(idx == 0) {
			HAL_GPIO_WritePin(clkPorts[11], clkPins[11], LED_OFF);
		} else {
			HAL_GPIO_WritePin(clkPorts[idx - 1], clkPins[idx - 1], LED_OFF);
		}
		HAL_GPIO_WritePin(clkPorts[idx], clkPins[idx], LED_ON);
		idx++;
		if(idx >= 12) {
			idx = 0;
		}
		HAL_Delay(1000);
	}
}


