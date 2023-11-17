/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "softwareTimer.h"
#include "button.h"
#include "normalMode.h"
#include "deviceDriverSingleLed.h"
#include "deviceDriver7Segment.h"
#include "manualMode.h"
#include "tuningMode.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define INITMODE 0
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4

#define INITMODE 0
#define AUTOMODE 1
#define MANUALMODE 2
#define TUNINGMODE 3

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
int modeStatus = INITMODE;
int flagAdvancedMode = 0;
/* USER CODE END PV */

/* Priv
ate function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_TIM2_Init();
	/* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim2);

	/* USER CODE END 2 */

	/* Infinite loop */
	normalModeFunction();
	setTimer2(100);
	displayAll7Seg();
	setTimer4(20);
	setTimer1(1);
	while (1)
	{
		if (flag1== 1)
		{
			switch (getInputButton())
			{
				case BUTTON1SinglePress:
					switch (modeStatus)
					{
						case INITMODE:
							modeStatus= AUTOMODE;
							offAllSingLEDs();
							setInitNormalModeFunction();
							normalModeFunction();
							setTimer2(100);
							update7SEGBufferMode(1);
							displayAll7Seg();
							setTimer4(10);
							break;
						case AUTOMODE:
							modeStatus= AUTOMODE;
							offAllSingLEDs();
							setInitNormalModeFunction();
							normalModeFunction();
							setTimer2(100);
							update7SEGBufferMode(1);
							displayAll7Seg();
							setTimer4(10);
							break;
						case MANUALMODE:
							modeStatus= AUTOMODE;
							offAllSingLEDs();
							setInitNormalModeFunction();
							normalModeFunction();
							setTimer2(100);
							update7SEGBufferMode(1);
							displayAll7Seg();
							setTimer4(10);
							break;
						case TUNINGMODE:
							modeStatus= AUTOMODE;
							offAllSingLEDs();
							setInitNormalModeFunction();
							normalModeFunction();
							setTimer2(100);
							update7SEGBufferMode(1);
							displayAll7Seg();
							setTimer4(10);
							break;
						default:
							break;
					}
					break;
				case BUTTON1DoublePress:
					switch (modeStatus)
					{
						case INITMODE:
							modeStatus= MANUALMODE;
							setInitManualModeFunction();
							manualModeFunction();
							break;
						case AUTOMODE:
							modeStatus= MANUALMODE;
							setInitManualModeFunction();
							manualModeFunction();
							break;
						case MANUALMODE:
							modeStatus= MANUALMODE;
							setInitManualModeFunction();
							manualModeFunction();
						case TUNINGMODE:
							modeStatus= MANUALMODE;
							setInitManualModeFunction();
							manualModeFunction();
							break;
						default:
							break;
					}
					break;
				case BUTTON1TriplePress:
					switch (modeStatus)
					{
						case INITMODE:
							modeStatus= TUNINGMODE;
							setInitTuningModeFunction();
							TuningModeFunction();
							break;
						case AUTOMODE:
							modeStatus= TUNINGMODE;
							setInitTuningModeFunction();
							TuningModeFunction();
							break;
						case MANUALMODE:
							modeStatus= TUNINGMODE;
							setInitTuningModeFunction();
							TuningModeFunction();
							break;
						case TUNINGMODE:
							modeStatus= TUNINGMODE;
							setInitTuningModeFunction();
							TuningModeFunction();
							break;
						default:
							break;
					}
					break;
				case BUTTON1LongPress:
					switch (modeStatus)
					{
						case AUTOMODE:
							offAllSingLEDs();
							setInitNormalModeFunction();
							normalModeFunction();
							setTimer2(100);
							update7SEGBufferMode(1);
							displayAll7Seg();
							setTimer4(10);
							break;
						case MANUALMODE:
							manualModeFunction();
							break;
						case TUNINGMODE:
							TuningModeFunction();
							break;
						default:
							break;
					}
					break;
				case BUTTON2SinglePress:
					switch (modeStatus)
					{
						case MANUALMODE:
							manualModeFunction();
							break;
						case TUNINGMODE:
							modifyTuningModeFuction();
							break;
						default:
							break;
					}
					break;
				case BUTTON2DoublePress:
					switch (modeStatus)
					{
						case TUNINGMODE:
							saveTuningModeFunction();
							break;					
						default:
							break;
					}
					break;
				case BUTTON2LongPress:
					switch (modeStatus)
					{
						case TUNINGMODE:
							modifyTuningModeFuction();
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}
		if (flag1 == 1) // flag for button
		{
			setTimer1(1);
			getInput();
			if (flagButton[0] == PRESS_STATE)
			{
				flagButton[0] = NORMAL_STATE;
				switch (modeStatus)
				{
				case INITMODE:
					modeStatus = MODE1;
					flagAdvancedMode = 0;
					tempDurationLedGreen = durationLedGreen;
					tempDurationLedRed = durationLedRed;
					tempDurationLedYellow = durationLedYellow;
					offAllSingLEDs();
					update7SEGBufferMode(MODE1);
					normalModeFunction();
					setTimer2(100);
					displayAll7Seg();
					setTimer4(20);
					break;
				case MODE1:
					modeStatus = MODE2;
					flagAdvancedMode = 1;
					offAllSingLEDs();
					blinkingRED();
					setTimer3(50);
					update7SEGBufferTraffic1(durationLedRed);
					update7SEGBufferTraffic2(durationLedRed);
					update7SEGBufferMode(MODE2);
					break;
				case MODE2:
					modeStatus = MODE3;
					flagAdvancedMode = 1;
					offAllSingLEDs();
					blinkingYELLOW();
					setTimer3(50);
					update7SEGBufferTraffic1(durationLedYellow);
					update7SEGBufferTraffic2(durationLedYellow);
					update7SEGBufferMode(MODE3);
					break;
				case MODE3:
					modeStatus = MODE4;
					flagAdvancedMode = 1;
					offAllSingLEDs();
					blinkingGREEN();
					setTimer3(50);
					update7SEGBufferTraffic1(durationLedGreen);
					update7SEGBufferTraffic2(durationLedGreen);
					update7SEGBufferMode(MODE4);
					break;
				case MODE4:
					modeStatus = MODE1;
					flagAdvancedMode = 0;
					tempDurationLedGreen = durationLedGreen;
					tempDurationLedRed = durationLedRed;
					tempDurationLedYellow = durationLedYellow;
					offAllSingLEDs();
					update7SEGBufferMode(MODE1);
					normalModeFunction();
					setTimer2(100);
					break;
				default:
					break;
				}
			}
			
			if (flagButton[2] == PRESS_STATE)
			{
				flagButton[2] = NORMAL_STATE;
				if (tempDurationLedRed != tempDurationLedYellow + tempDurationLedGreen)
				{
					switch (modeStatus)
					{
					case MODE4:
						update7SEGBufferTraffic1(88);
						update7SEGBufferTraffic2(88);
						update7SEGBufferMode(8);
						onAllSingLEDs();
						modeStatus = INITMODE;
						break;
					default:
						break;
					}
				}
				else
				{
					durationLedGreen = tempDurationLedGreen;
					durationLedRed = tempDurationLedRed;
					durationLedYellow = tempDurationLedYellow;
					statusTraffic1 = INIT1;
					statusTraffic2 = INIT2;
					if (modeStatus == 1 || modeStatus == 0)
					{
						normalModeFunction();
						setTimer2(1000);
					}
				}
			}
		}
		if (flag2 == 1) // flag normal led
		{
			setTimer2(100);
			if (flagAdvancedMode == 0)
			{
				normalModeFunction();
			}
		}
		if (flag3 == 1) // flag for model modify
		{
			setTimer3(50);
			if (flagAdvancedMode == 1)
			{
				switch (modeStatus)
				{
				case MODE2:
					blinkingRED();
					break;
				case MODE3:
					blinkingYELLOW();
					break;
				case MODE4:
					blinkingGREEN();
					break;
				default:
					break;
				}
			}
		}
		if (flag4 == 1)
		{
			displayAll7Seg();
			setTimer4(20);
		}

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 * @brief TIM2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM2_Init(void)
{

	/* USER CODE BEGIN TIM2_Init 0 */

	/* USER CODE END TIM2_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM2_Init 1 */

	/* USER CODE END TIM2_Init 1 */
	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 7999;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 9;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	{
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN TIM2_Init 2 */

	/* USER CODE END TIM2_Init 2 */
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, segA_Pin | segB_Pin | segC_Pin | segD_Pin | segE_Pin | segF_Pin | segG_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, RED1_Pin | GREEN1_Pin | YELLOW1_Pin | RED2_Pin | GREEN2_Pin | YELLOW2_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, en4_Pin | en0_Pin | en1_Pin | en2_Pin | en3_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : segA_Pin segB_Pin segC_Pin segD_Pin
							 segE_Pin segF_Pin segG_Pin */
	GPIO_InitStruct.Pin = segA_Pin | segB_Pin | segC_Pin | segD_Pin | segE_Pin | segF_Pin | segG_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : RED1_Pin GREEN1_Pin YELLOW1_Pin en4_Pin
							 RED2_Pin GREEN2_Pin YELLOW2_Pin en0_Pin
							 en1_Pin en2_Pin en3_Pin */
	GPIO_InitStruct.Pin = RED1_Pin | GREEN1_Pin | YELLOW1_Pin | en4_Pin | RED2_Pin | GREEN2_Pin | YELLOW2_Pin | en0_Pin | en1_Pin | en2_Pin | en3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : button1_Pin button2_Pin button3_Pin */
	GPIO_InitStruct.Pin = button1_Pin | button2_Pin | button3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	runTimer();
}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	   ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
