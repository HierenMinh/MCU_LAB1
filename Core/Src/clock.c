/*
 * clock.c
 *
 *  Created on: Aug 30, 2025
 *      Author: qwein
 */
#include "clock.h"

#define LED_ON 0
#define LED_OFF 1

int sec;
int min;
int hr;

void clearAllClock() {
	exercise6_init();
}

void setNumberOnClock(int num) {
	if(num >= 0 && num < 12)
		HAL_GPIO_WritePin(clkPorts[num], clkPins[num], LED_ON);
}

void clearNumberOnClock(int num) {
	if(num >= 0 && num < 12)
		HAL_GPIO_WritePin(clkPorts[num], clkPins[num], LED_OFF);
}

void clock_init() {
	hr = 11;
	min = 55;
	sec = 0;
	clearAllClock();
	setNumberOnClock(hr);
	setNumberOnClock(min / 5);
	setNumberOnClock(sec / 5);
}

void clock_run() {
	while(1) {
		if(sec != min && sec / 5 != hr) {
			clearNumberOnClock(sec / 5);
		}
		sec++;
		if(sec >= 60) {
			sec = 0;
			if(min / 5 != hr && min / 5 != sec / 5) {
				clearNumberOnClock(min / 5);
			}
			min++;
		}
		setNumberOnClock(sec / 5);
		if(min >= 60) {
			min = 0;
			if(hr != 0) {
				clearNumberOnClock(hr);
			}
			hr++;
		}
		setNumberOnClock(min / 5);
		if(hr >= 12) {
			hr = 0;
		}
		setNumberOnClock(hr);
		HAL_Delay(100);
	}
}
