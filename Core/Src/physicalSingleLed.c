/*
 * physicalSingleLed.c
 *
 *  Created on: Nov 7, 2023
 *      Author: TVB09
 */

#include <main.h>
#include "physical7SingleLed.h"

void controlSingleLed(int orderTraffic, int statusLed)
{
	switch (orderTraffic)
	{
	case TRAFFIC1:
		switch (statusLed)
		{
		case REDNORMALMODE:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			break;
		case GREENNORMALMODE:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			break;
		case YELLOWNORMALMODE:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			break;
		case REDADVANCEDMODE:
			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
			break;
		case YELLOWADVANCEDMODE:
			HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
			break;
		case GREENADVANCEDMODE:
			HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			break;
		case OFF:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			break;
		case ON:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			break;
		default:
			break;
		}
		break;
	case TRAFFIC2:
		switch (statusLed)
		{
		case REDNORMALMODE:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
			break;
		case GREENNORMALMODE:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			break;
		case YELLOWNORMALMODE:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
			break;
		case REDADVANCEDMODE:
			HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
			break;
		case YELLOWADVANCEDMODE:
			HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
			break;
		case GREENADVANCEDMODE:
			HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
			break;
		case OFF:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
			break;
		case ON:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
