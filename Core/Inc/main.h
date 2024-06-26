/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
#define segA_Pin GPIO_PIN_0
#define segA_GPIO_Port GPIOA
#define segB_Pin GPIO_PIN_1
#define segB_GPIO_Port GPIOA
#define segC_Pin GPIO_PIN_2
#define segC_GPIO_Port GPIOA
#define segD_Pin GPIO_PIN_3
#define segD_GPIO_Port GPIOA
#define segE_Pin GPIO_PIN_4
#define segE_GPIO_Port GPIOA
#define segF_Pin GPIO_PIN_5
#define segF_GPIO_Port GPIOA
#define segG_Pin GPIO_PIN_6
#define segG_GPIO_Port GPIOA
#define RED1_Pin GPIO_PIN_0
#define RED1_GPIO_Port GPIOB
#define GREEN1_Pin GPIO_PIN_1
#define GREEN1_GPIO_Port GPIOB
#define YELLOW1_Pin GPIO_PIN_2
#define YELLOW1_GPIO_Port GPIOB
#define en4_Pin GPIO_PIN_10
#define en4_GPIO_Port GPIOB
#define button1_Pin GPIO_PIN_10
#define button1_GPIO_Port GPIOA
#define button2_Pin GPIO_PIN_11
#define button2_GPIO_Port GPIOA
#define button3_Pin GPIO_PIN_12
#define button3_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_3
#define RED2_GPIO_Port GPIOB
#define GREEN2_Pin GPIO_PIN_4
#define GREEN2_GPIO_Port GPIOB
#define YELLOW2_Pin GPIO_PIN_5
#define YELLOW2_GPIO_Port GPIOB
#define en0_Pin GPIO_PIN_6
#define en0_GPIO_Port GPIOB
#define en1_Pin GPIO_PIN_7
#define en1_GPIO_Port GPIOB
#define en2_Pin GPIO_PIN_8
#define en2_GPIO_Port GPIOB
#define en3_Pin GPIO_PIN_9
#define en3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
