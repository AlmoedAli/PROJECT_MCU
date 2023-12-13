/*
 * uart.h
 *
 *  Created on: Nov 30, 2023
 *      Author: TVB09
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include  "main.h"

extern UART_HandleTypeDef huart2;

void printTerminalInfoTraffic2();
void printTerminalInfoModeTraffic1();
void MX_USART2_UART_Init(void);

#endif /* INC_UART_H_ */
