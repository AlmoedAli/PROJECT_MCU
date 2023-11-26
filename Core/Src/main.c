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
#include "ledWalk.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define INITMODE 0
#define NORMALMODE 1
#define MANUALMODE 2
#define TUNINGMODE 3

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
int modeStatus = INITMODE;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
typedef struct {
	//Pointer to the task
	void (*pTask)(void);
	//Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	//Interval (ticks) between subsequent runs
	uint32_t Period;
	//Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	//This is a hint to solve the question below
	uint32_t TaskID;
}sTask;

#define SCH_MAX_TASKS 40
uint8_t nTask = 0;
sTask SCH_tasks_G[SCH_MAX_TASKS];

uint8_t data[] = "Hello UART";

uint8_t temp = 0;
uint8_t buffer[] = {0, 1, 2, 3, 4, '\n'};
uint8_t index_buffer = 0;

void printTerminal(uint8_t val){
	uint8_t str[]="!7SEG:";
	char* buffer2;
	itoa(val, buffer2, 10);
	uint8_t endline[] = "#\r";

	HAL_UART_Transmit(&huart2, str, sizeof(str), 1000);
	HAL_UART_Transmit(&huart2, buffer2, sizeof(buffer2), 1000);
	HAL_UART_Transmit(&huart2, endline, sizeof(endline), 1000);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART2){
		buffer[index_buffer++] = temp;
		if(index_buffer == 30) index_buffer = 0;
		HAL_UART_Transmit(&huart2, &temp, 1, 1000);
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

void SCH_Update(){
	if(SCH_tasks_G[0].pTask){
		if(SCH_tasks_G[0].Delay == 0){
			SCH_tasks_G[0].RunMe+=1;
		}
		else{
			SCH_tasks_G[0].Delay--;
		}
	}
}

void SCH_Add_Task(void (*pFunction), const uint32_t Delay, const uint32_t Period){
	int index = 0;
	int total_delay = Delay/10;

	for(int i=0; i<SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].pTask){
			if(SCH_tasks_G[i].Delay <= total_delay){
				total_delay = total_delay - SCH_tasks_G[i].Delay;
			}
			else{
				index = i;
				break;
			}
		}
		else{
			index = i;
			break;
		}
	}
	for(int i = SCH_MAX_TASKS; i>index; i--){
		if(SCH_tasks_G[i-1].pTask){
			SCH_tasks_G[i].pTask = SCH_tasks_G[i-1].pTask;
			SCH_tasks_G[i].Delay = SCH_tasks_G[i-1].Delay;
			SCH_tasks_G[i].Period = SCH_tasks_G[i-1].Period;
			SCH_tasks_G[i].RunMe = SCH_tasks_G[i-1].RunMe;
		}
	}
	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = total_delay;
	SCH_tasks_G[index].Period = Period;
	SCH_tasks_G[index].RunMe = 0;
	if(SCH_tasks_G[index+1].pTask){
		SCH_tasks_G[index+1].Delay = SCH_tasks_G[index+1].Delay - total_delay;
	}
}

void SCH_Delete(uint8_t index){
	SCH_tasks_G[index].Delay = 0;
	SCH_tasks_G[index].Period = 0;
	SCH_tasks_G[index].RunMe = 0;
	SCH_tasks_G[index].pTask = 0x0000;
}

void SCH_Delete_Task(uint8_t index){
	int final = 0;
	SCH_Delete(index);
	for(int i=index; i<SCH_MAX_TASKS; i++){
			SCH_tasks_G[i].pTask = SCH_tasks_G[i+1].pTask;
			SCH_tasks_G[i].Delay = SCH_tasks_G[i+1].Delay;
			SCH_tasks_G[i].Period = SCH_tasks_G[i+1].Period;
			SCH_tasks_G[i].RunMe = SCH_tasks_G[i+1].RunMe;
			if(SCH_tasks_G[i].pTask == 0x0000){
				final = i;
				break;
			}
	}
	SCH_Delete(final);
}

void SCH_Dispatch_Tasks(void){
	if(SCH_tasks_G[0].pTask){
		if(SCH_tasks_G[0].RunMe>0){
			(*SCH_tasks_G[0].pTask)();
			SCH_tasks_G[0].RunMe--;

			if(SCH_tasks_G[0].Period){
				SCH_Add_Task(SCH_tasks_G[0].pTask, SCH_tasks_G[0].Period, SCH_tasks_G[0].Period);
			}
			SCH_Delete_Task(0);
		}
	}
}

void SCH_Init(void){
	uint8_t i;
	for(i=0; i<SCH_MAX_TASKS; i++){
		SCH_tasks_G[i].Delay = 0;
		SCH_tasks_G[i].Period = 0;
		SCH_tasks_G[i].RunMe = 0;
		SCH_tasks_G[i].pTask = 0x0000;
	}
}
void toggleLED(){
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}
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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
//	HAL_TIM_Base_Start_IT(&htim2);
	HAL_UART_Receive_IT(&huart2, &temp, 1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	SCH_Add_Task(toggleLED, 1000, 1000);
//	SCH_Add_Task(getInputButton, 10, 10)
	setTimer1(100);
  while (1)
  {
//	  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
//	  printTerminal(100);
//	  HAL_Delay(500);
//	  for(int i=0; i<100; i++){
//	  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, i);
//	  HAL_Delay(10);
//	  }
	  if(flag1 == 1){
		  setTimer1(100);
		  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		  runNormalMode();
	  }
	  if(flagWalk == 1){
		  runLedWalkMode();
	  }
	  if(flagWalkOff == 1){
		  flagWalk = 0;
		  WALKOFF();
	  }
	  runTimer();
	  getKeyInput();
	  HAL_Delay(10);
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
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
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
  TIM_OC_InitTypeDef sConfigOC = {0};

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
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, segE_Pin|LED_Pin|segG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RED1_Pin|GREEN1_Pin|YELLOW1_Pin|RED2_Pin
                          |GREEN2_Pin|YELLOW2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, en4_Pin|LED_WALK_Pin|en1_Pin|en2_Pin
                          |en3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : segE_Pin LED_Pin segG_Pin */
  GPIO_InitStruct.Pin = segE_Pin|LED_Pin|segG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : RED1_Pin GREEN1_Pin YELLOW1_Pin en4_Pin
                           RED2_Pin GREEN2_Pin YELLOW2_Pin LED_WALK_Pin
                           en1_Pin en2_Pin en3_Pin */
  GPIO_InitStruct.Pin = RED1_Pin|GREEN1_Pin|YELLOW1_Pin|en4_Pin
                          |RED2_Pin|GREEN2_Pin|YELLOW2_Pin|LED_WALK_Pin
                          |en1_Pin|en2_Pin|en3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : button1_Pin button2_Pin button3_Pin */
  GPIO_InitStruct.Pin = button1_Pin|button2_Pin|button3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	runTimer();
//	SCH_Update();
//	getInputButton();
	getKeyInput();
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

#ifdef  USE_FULL_ASSERT
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
