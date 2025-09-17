/*
 * led_7seg.c
 *
 *  Created on: Aug 28, 2025
 *      Author: qwein
 */
#include "ex4.h"

#define SEG_ON 0
#define SEG_OFF 1

void display7SEG(int num) {
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

	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (m & (0x01 << 0)) ? SEG_ON : SEG_OFF); // a
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (m & (0x01 << 1)) ? SEG_ON : SEG_OFF); // b
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (m & (0x01 << 2)) ? SEG_ON : SEG_OFF); // c
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (m & (0x01 << 3)) ? SEG_ON : SEG_OFF); // d
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (m & (0x01 << 4)) ? SEG_ON : SEG_OFF); // e
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (m & (0x01 << 5)) ? SEG_ON : SEG_OFF); // f
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (m & (0x01 << 6)) ? SEG_ON : SEG_OFF); // g
}


void exercise4_init() {
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SEG_OFF);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SEG_OFF);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SEG_OFF);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SEG_OFF);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SEG_OFF);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SEG_OFF);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SEG_OFF);
}

void exercise4_run() {
	 int counter = 0;
	 while (1){
		 if(counter >= 10) counter = 0;
		 display7SEG(counter++);
		 HAL_Delay(1000);
	 }
}
