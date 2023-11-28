/*
 * physical7Segment.c
 *
 *  Created on: Nov 7, 2023
 *      Author: TVB09
 */

#include "physical7Segment.h"
#include <main.h>

#define INIT 0
#define SEG7_1ON 1
#define SEG7_2ON 2
#define SEG7_3ON 3
#define SEG7_4ON 4
#define SEG7_5ON 5

int status7SEG = INIT;
int led_buffer[5] = {1, 2, 3, 4, 1};

void show7SEG(GPIO_PinState A, GPIO_PinState B, GPIO_PinState C, GPIO_PinState D, GPIO_PinState E,
			  GPIO_PinState F, GPIO_PinState G)
{
	HAL_GPIO_WritePin(segA_GPIO_Port, segA_Pin, A);
	HAL_GPIO_WritePin(segB_GPIO_Port, segB_Pin, B);
	HAL_GPIO_WritePin(segC_GPIO_Port, segC_Pin, C);
	HAL_GPIO_WritePin(segD_GPIO_Port, segD_Pin, D);
	HAL_GPIO_WritePin(segE_GPIO_Port, segE_Pin, E);
	HAL_GPIO_WritePin(segF_GPIO_Port, segF_Pin, F);
	HAL_GPIO_WritePin(segG_GPIO_Port, segG_Pin, G);
}

void display(int num)
{
	switch (num)
	{
	case 0:
		show7SEG(0, 0, 0, 0, 0, 0, 1);
		break;
	case 1:
		show7SEG(1, 0, 0, 1, 1, 1, 1);
		break;
	case 2:
		show7SEG(0, 0, 1, 0, 0, 1, 0);
		break;

	case 3:
		show7SEG(0, 0, 0, 0, 1, 1, 0);
		break;
	case 4:
		show7SEG(1, 0, 0, 1, 1, 0, 0);
		break;
	case 5:
		show7SEG(0, 1, 0, 0, 1, 0, 0);
		break;
	case 6:
		show7SEG(0, 1, 0, 0, 0, 0, 0);
		break;
	case 7:
		show7SEG(0, 0, 0, 1, 1, 1, 1);
		break;
	case 8:
		show7SEG(0, 0, 0, 0, 0, 0, 0);
		break;
	case 9:
		show7SEG(0, 0, 0, 0, 1, 0, 0);
		break;
	default:
		show7SEG(0, 0, 0, 0, 1, 0, 0);
		break;
	}
}

void Scan7SEG()
{
	switch (status7SEG)
	{
	case INIT:
		HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, 0);
		HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, 1);
		HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, 1);
		HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, 1);
		HAL_GPIO_WritePin(en4_GPIO_Port, en4_Pin, 1);
		display(led_buffer[0]);
		status7SEG = SEG7_1ON;
		break;
	case SEG7_1ON:
		HAL_GPIO_TogglePin(en0_GPIO_Port, en0_Pin);
		HAL_GPIO_TogglePin(en1_GPIO_Port, en1_Pin);
		display(led_buffer[1]);
		status7SEG = SEG7_2ON;
		break;
	case SEG7_2ON:
		HAL_GPIO_TogglePin(en1_GPIO_Port, en1_Pin);
		HAL_GPIO_TogglePin(en2_GPIO_Port, en2_Pin);
		display(led_buffer[2]);
		status7SEG = SEG7_3ON;
		break;
	case SEG7_3ON:
		HAL_GPIO_TogglePin(en2_GPIO_Port, en2_Pin);
		HAL_GPIO_TogglePin(en3_GPIO_Port, en3_Pin);
		status7SEG = SEG7_4ON;
		display(led_buffer[3]);
		break;
	case SEG7_4ON:
		HAL_GPIO_TogglePin(en3_GPIO_Port, en3_Pin);
		HAL_GPIO_TogglePin(en4_GPIO_Port, en4_Pin);
		status7SEG = SEG7_5ON;
		display(led_buffer[4]);
		break;
	case SEG7_5ON:
		HAL_GPIO_TogglePin(en4_GPIO_Port, en4_Pin);
		HAL_GPIO_TogglePin(en0_GPIO_Port, en0_Pin);
		status7SEG = SEG7_1ON;
		display(led_buffer[0]);
		break;
	default:
		break;
	}
}
