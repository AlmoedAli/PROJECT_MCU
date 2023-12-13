/*
 * uart.c
 *
 *  Created on: Nov 30, 2023
 *      Author: TVB09
 */


#include "uart.h"
#include "deviceDriver7Segment.h"
#include <stdlib.h>
UART_HandleTypeDef huart2;

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
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


void printTerminalInfoTraffic2()
{
	uint8_t str01[]="!7SEG:";
	uint8_t endline[] = "#\n\n";

	char valueTraffic2[20];
	itoa(led_buffer[1], valueTraffic2, 10);

	HAL_UART_Transmit(&huart2, str01, sizeof(str01), 1000);
	HAL_UART_Transmit(&huart2, (void*)valueTraffic2, 2, 1000);
	HAL_UART_Transmit(&huart2, (void*)endline, sizeof(endline), 1000);
}
void printTerminalInfoModeTraffic1()
{
	uint8_t str01[]="!7SEG:";
	uint8_t str2[]= "!MODE:";
	uint8_t endline[] = "#\n";

	char valueTraffic1[20];
	itoa(led_buffer[0], valueTraffic1, 10);

	char valueMode[20];
	itoa(led_buffer[2], valueMode, 10);

	HAL_UART_Transmit(&huart2, str2, sizeof(str2), 1000);
	HAL_UART_Transmit(&huart2, (void*)valueMode, 2, 1000);
	HAL_UART_Transmit(&huart2, (void*)endline, sizeof(endline), 1000);

	HAL_UART_Transmit(&huart2, str01, sizeof(str01), 1000);
	HAL_UART_Transmit(&huart2, (void*)valueTraffic1, 2, 1000);
	HAL_UART_Transmit(&huart2, (void*)endline, sizeof(endline), 1000);
}
