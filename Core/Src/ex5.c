/*
 * ex5.c
 *
 *  Created on: Aug 29, 2025
 *      Author: qwein
 */
#include "ex5.h"

typedef enum {
    RED = 0,
    YELLOW,
    GREEN,
} traffic_light_state_t;

#define SEG_ON 0
#define SEG_OFF 1

#define LED_ON 0
#define LED_OFF 1

#define RED_TIME 5
#define YELLOW_TIME 2
#define GREEN_TIME 3

void exercise5_init() {
	exercise3_init();
	exercise4_init();
}

void exercise5_run() {
	traffic_light_state_t tl_state_w1 = RED;
	int w1_counter = RED_TIME;
	int num_w1 = RED_TIME + 1;

	traffic_light_state_t tl_state_w2 = GREEN;
	int w2_counter = GREEN_TIME;
	int num_w2 = GREEN_TIME + 1;

	while (1)
	{

		  switch (tl_state_w2) {
		  case RED:
				HAL_GPIO_WritePin(RED_W2_GPIO_Port, RED_W2_Pin, LED_ON);
				HAL_GPIO_WritePin(YELLOW_W2_GPIO_Port, YELLOW_W2_Pin, LED_OFF);
				HAL_GPIO_WritePin(GREEN_W2_GPIO_Port, GREEN_W2_Pin, LED_OFF);
				num_w2--;
				w2_counter--;
				display7SEG(num_w2);
				if(w2_counter <= 0) {
					tl_state_w2 = GREEN;
					w2_counter = GREEN_TIME;
					num_w2 = GREEN_TIME + 1;
				}
				break;
		  case GREEN:
				HAL_GPIO_WritePin(RED_W2_GPIO_Port, RED_W2_Pin, LED_OFF);
				HAL_GPIO_WritePin(YELLOW_W2_GPIO_Port, YELLOW_W2_Pin, LED_OFF);
				HAL_GPIO_WritePin(GREEN_W2_GPIO_Port, GREEN_W2_Pin, LED_ON);
				num_w2--;
				w2_counter--;
				display7SEG(num_w2);
				if(w2_counter <= 0) {
					tl_state_w2 = YELLOW;
					w2_counter = YELLOW_TIME;
					num_w2 = YELLOW_TIME + 1;
				}
				break;
		  case YELLOW:
				HAL_GPIO_WritePin(RED_W2_GPIO_Port, RED_W2_Pin, LED_OFF);
				HAL_GPIO_WritePin(YELLOW_W2_GPIO_Port, YELLOW_W2_Pin, LED_ON);
				HAL_GPIO_WritePin(GREEN_W2_GPIO_Port, GREEN_W2_Pin, LED_OFF);

				num_w2--;
				w2_counter--;
				display7SEG(num_w2);
				if(w2_counter <= 0) {
					tl_state_w2 = RED;
					w2_counter = RED_TIME;
					num_w2 = RED_TIME + 1;
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

				num_w1--;
				w1_counter--;
				display7SEG_2(num_w1);
				if(w1_counter <= 0) {
					tl_state_w1 = GREEN;
					w1_counter = GREEN_TIME;
					num_w1 = GREEN_TIME + 1;
				}
				break;
		  case GREEN:
			  	HAL_GPIO_WritePin(RED_W1_GPIO_Port, RED_W1_Pin, LED_OFF);
				HAL_GPIO_WritePin(YELLOW_W1_GPIO_Port, YELLOW_W1_Pin, LED_OFF);
				HAL_GPIO_WritePin(GREEN_W1_GPIO_Port, GREEN_W1_Pin, LED_ON);

				num_w1--;
				w1_counter--;
				display7SEG_2(num_w1);
				if(w1_counter <= 0) {
					tl_state_w1 = YELLOW;
					w1_counter = YELLOW_TIME;
					num_w1 = YELLOW_TIME + 1;
				}
				break;
		  case YELLOW:
			  	HAL_GPIO_WritePin(RED_W1_GPIO_Port, RED_W1_Pin, LED_OFF);
				HAL_GPIO_WritePin(YELLOW_W1_GPIO_Port, YELLOW_W1_Pin, LED_ON);
				HAL_GPIO_WritePin(GREEN_W1_GPIO_Port, GREEN_W1_Pin, LED_OFF);
				num_w1--;
				w1_counter--;
				display7SEG_2(num_w1);
				if(w1_counter <= 0) {
					tl_state_w1 = RED;
					w1_counter = RED_TIME;
					num_w1 = RED_TIME + 1;
				}
				break;
		  default:
			    break;
		  }
		  HAL_Delay(1000);
	}
}

void display7SEG_2(int num) {
	const uint8_t lut[10] = {
			0x3F, // 0: a b c d e f
			0x06, // 1:   b c
			0x5B, // 2: a b   d e   g
			0x4F, // 3: a b c d     g
			0x66, // 4:   b c     f g
			0x6D, // 5: a   c d   f g
			0x7D, // 6: a   c d e f g
			0x07, // 7: a b c
			0x7F, // 8: a b c d e f g
			0x6F  // 9: a b c d   f g
		};
	uint8_t m = (num >= 0 && num <= 9) ? lut[num] : 0x79; // invalid -> display 'E'
	HAL_GPIO_WritePin(CLK_12_GPIO_Port, CLK_12_Pin, (m & (0x01 << 0)) ? SEG_ON : SEG_OFF); // a
	HAL_GPIO_WritePin(CLK_1_GPIO_Port,  CLK_1_Pin,  (m & (0x01 << 1)) ? SEG_ON : SEG_OFF); // b
	HAL_GPIO_WritePin(CLK_2_GPIO_Port,  CLK_2_Pin,  (m & (0x01 << 2)) ? SEG_ON : SEG_OFF); // c
	HAL_GPIO_WritePin(CLK_3_GPIO_Port,  CLK_3_Pin,  (m & (0x01 << 3)) ? SEG_ON : SEG_OFF); // d
	HAL_GPIO_WritePin(CLK_4_GPIO_Port,  CLK_4_Pin,  (m & (0x01 << 4)) ? SEG_ON : SEG_OFF); // e
	HAL_GPIO_WritePin(CLK_5_GPIO_Port,  CLK_5_Pin,  (m & (0x01 << 5)) ? SEG_ON : SEG_OFF); // f
	HAL_GPIO_WritePin(CLK_6_GPIO_Port,  CLK_6_Pin,  (m & (0x01 << 6)) ? SEG_ON : SEG_OFF); // g

}

