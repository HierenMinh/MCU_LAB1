/*
 * ex2.c
 *
 *  Created on: Aug 29, 2025
 *      Author: qwein
 */
#include "ex2.h"

#define LED_ON 0
#define LED_OFF 1

#define TIME_RED 5
#define TIME_GREEN 3
#define TIME_YELLOW 2

typedef enum {
	RED = 0,
	YELLOW,
	GREEN
} state;


void exercise2_init() {
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, LED_OFF);
}

void exercise2_run() {
	int counter = TIME_RED;
	int status_red = 1;
	int status_yellow = 0;
	int status_green = 0;
	state traffic_state = RED;
	while(1) {
		counter--;
		if(counter < 0 && traffic_state == RED) {
			counter = TIME_YELLOW;
			status_yellow = LED_OFF;
			status_red = LED_OFF;
			status_green = LED_ON;
			traffic_state = GREEN;

		}
		if(counter < 0 && traffic_state == YELLOW) {
			counter = TIME_GREEN;
			status_yellow = LED_OFF;
			status_red = LED_ON;
			status_green = LED_OFF;
			traffic_state = RED;
		}
		if(counter < 0 && traffic_state == GREEN) {
			counter = TIME_RED;
			status_yellow = LED_ON;
			status_red = LED_OFF;
			status_green = LED_OFF;
			traffic_state = YELLOW;
		}
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, status_red);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, status_yellow);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, status_green);
		HAL_Delay(1000);
	}


}
