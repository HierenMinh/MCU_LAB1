/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CLK_1_Pin GPIO_PIN_1
#define CLK_1_GPIO_Port GPIOA
#define CLK_2_Pin GPIO_PIN_2
#define CLK_2_GPIO_Port GPIOA
#define CLK_3_Pin GPIO_PIN_3
#define CLK_3_GPIO_Port GPIOA
#define CLK_4_Pin GPIO_PIN_4
#define CLK_4_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define LED_YELLOW_Pin GPIO_PIN_6
#define LED_YELLOW_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_7
#define LED_GREEN_GPIO_Port GPIOA
#define SEG0_Pin GPIO_PIN_0
#define SEG0_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_1
#define SEG1_GPIO_Port GPIOB
#define SEG2_Pin GPIO_PIN_2
#define SEG2_GPIO_Port GPIOB
#define CLK_5_Pin GPIO_PIN_10
#define CLK_5_GPIO_Port GPIOB
#define CLK_6_Pin GPIO_PIN_11
#define CLK_6_GPIO_Port GPIOB
#define CLK_7_Pin GPIO_PIN_12
#define CLK_7_GPIO_Port GPIOB
#define RED_W2_Pin GPIO_PIN_13
#define RED_W2_GPIO_Port GPIOB
#define YELLOW_W2_Pin GPIO_PIN_14
#define YELLOW_W2_GPIO_Port GPIOB
#define GREEN_W2_Pin GPIO_PIN_15
#define GREEN_W2_GPIO_Port GPIOB
#define RED_W1_Pin GPIO_PIN_9
#define RED_W1_GPIO_Port GPIOA
#define YELLOW_W1_Pin GPIO_PIN_10
#define YELLOW_W1_GPIO_Port GPIOA
#define GREEN_W1_Pin GPIO_PIN_11
#define GREEN_W1_GPIO_Port GPIOA
#define CLK_8_Pin GPIO_PIN_12
#define CLK_8_GPIO_Port GPIOA
#define CLK_9_Pin GPIO_PIN_13
#define CLK_9_GPIO_Port GPIOA
#define CLK_10_Pin GPIO_PIN_14
#define CLK_10_GPIO_Port GPIOA
#define CLK_11_Pin GPIO_PIN_15
#define CLK_11_GPIO_Port GPIOA
#define SEG3_Pin GPIO_PIN_3
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_4
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_5
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_6
#define SEG6_GPIO_Port GPIOB
#define CLK_12_Pin GPIO_PIN_7
#define CLK_12_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
