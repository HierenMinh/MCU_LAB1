/*
 * ex3.c
 *
 *  Created on: Aug 29, 2025
 *      Author: qwein
 */

#ifndef SRC_EX3_C_
#define SRC_EX3_C_

#include "ex3.h"

typedef enum {
    RED = 0,
    YELLOW,
    GREEN,
} traffic_light_state_t;

#define LED_ON 0
#define LED_OFF 1

#define RED_TIME 5
#define YELLOW_TIME 2
#define GREEN_TIME 3

void exercise3_init() {
	HAL_GPIO_WritePin(RED_W1_GPIO_Port, RED_W1_Pin, LED_OFF);
	HAL_GPIO_WritePin(YELLOW_W1_GPIO_Port, YELLOW_W1_Pin, LED_OFF);
	HAL_GPIO_WritePin(GREEN_W1_GPIO_Port, GREEN_W1_Pin, LED_OFF);
	HAL_GPIO_WritePin(RED_W2_GPIO_Port, RED_W2_Pin, LED_OFF);
	HAL_GPIO_WritePin(YELLOW_W2_GPIO_Port, YELLOW_W2_Pin, LED_OFF);
	HAL_GPIO_WritePin(GREEN_W2_GPIO_Port, GREEN_W2_Pin, LED_OFF);

}

void exercise3_run() {
	traffic_light_state_t tl_state_w1 = RED;
	int w1_counter = RED_TIME;
	traffic_light_state_t tl_state_w2 = GREEN;
	int w2_counter = GREEN_TIME;
	while (1)
	{
		  switch (tl_state_w2) {
		  case RED:
				HAL_GPIO_WritePin(RED_W2_GPIO_Port, RED_W2_Pin, LED_ON);
				HAL_GPIO_WritePin(YELLOW_W2_GPIO_Port, YELLOW_W2_Pin, LED_OFF);
				HAL_GPIO_WritePin(GREEN_W2_GPIO_Port, GREEN_W2_Pin, LED_OFF);
				w2_counter--;
				if(w2_counter <= 0) {
					tl_state_w2 = GREEN;
					w2_counter = GREEN_TIME;
				}
				break;
		  case GREEN:
				HAL_GPIO_WritePin(RED_W2_GPIO_Port, RED_W2_Pin, LED_OFF);
				HAL_GPIO_WritePin(YELLOW_W2_GPIO_Port, YELLOW_W2_Pin, LED_OFF);
				HAL_GPIO_WritePin(GREEN_W2_GPIO_Port, GREEN_W2_Pin, LED_ON);
				w2_counter--;
				if(w2_counter <= 0) {
					tl_state_w2 = YELLOW;
					w2_counter = YELLOW_TIME;
				}
				break;
		  case YELLOW:
				HAL_GPIO_WritePin(RED_W2_GPIO_Port, RED_W2_Pin, LED_OFF);
				HAL_GPIO_WritePin(YELLOW_W2_GPIO_Port, YELLOW_W2_Pin, LED_ON);
				HAL_GPIO_WritePin(GREEN_W2_GPIO_Port, GREEN_W2_Pin, LED_OFF);
				w2_counter--;
				if(w2_counter <= 0) {
					tl_state_w2 = RED;
					w2_counter = RED_TIME;
				}
				break;
		  default:
				break;
		  	  }

		  switch (tl_state_w1) {
		  case RED:
				HAL_GPIO_WritePin(RED_W1_GPIO_Port, RED_W1_Pin, LED_ON);
				HAL_GPIO_WritePin(YELLOW_W1_GPIO_Port, YELLOW_W1_Pin, LED_OFF);
				HAL_GPIO_WritePin(GREEN_W1_GPIO_Port, GREEN_W1_Pin, LED_OFF);
				w1_counter--;
				if(w1_counter <= 0) {
					tl_state_w1 = GREEN;
					w1_counter = GREEN_TIME;
				}
				break;
		  case GREEN:
			  	HAL_GPIO_WritePin(RED_W1_GPIO_Port, RED_W1_Pin, LED_OFF);
				HAL_GPIO_WritePin(YELLOW_W1_GPIO_Port, YELLOW_W1_Pin, LED_OFF);
				HAL_GPIO_WritePin(GREEN_W1_GPIO_Port, GREEN_W1_Pin, LED_ON);
				w1_counter--;
				if(w1_counter <= 0) {
					tl_state_w1 = YELLOW;
					w1_counter = YELLOW_TIME;
				}
				break;
		  case YELLOW:
			  	HAL_GPIO_WritePin(RED_W1_GPIO_Port, RED_W1_Pin, LED_OFF);
				HAL_GPIO_WritePin(YELLOW_W1_GPIO_Port, YELLOW_W1_Pin, LED_ON);
				HAL_GPIO_WritePin(GREEN_W1_GPIO_Port, GREEN_W1_Pin, LED_OFF);
				w1_counter--;
				if(w1_counter <= 0) {
					tl_state_w1 = RED;
					w1_counter = RED_TIME;
				}
				break;
		  default:
			    break;
		  }
		  HAL_Delay(1000);
	}
}





#endif /* SRC_EX3_C_ */
