/*
 * physicalSingleLed.c
 *
 *  Created on: Nov 7, 2023
 *      Author: TVB09
 */

#include <main.h>
#include "physical7SingleLed.h"

void controlSingleLedTraffic(int orderTraffic, int statusLed)
{
	switch (orderTraffic)
	{
	case TRAFFIC1:
		switch (statusLed)
		{
		case REDNORMAL:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			break;
		case GREENNORMAL:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			break;
		case YELLOWNORMAL:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			break;
		case REDTUNING:
			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
			break;
		case YELLOWTUNING:
			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
			HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			break;
		case GREENTUNING:
			HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			break;
		case OFF:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			break;
		case ON:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
			break;
		default:
			break;
		}
		break;
	case TRAFFIC2:
		switch (statusLed)
		{
		case REDNORMAL:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
			break;
		case GREENNORMAL:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			break;
		case YELLOWNORMAL:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
			break;
		case REDTUNING:
			HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
			break;
		case YELLOWTUNING:
			HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
			HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
			break;
		case GREENTUNING:
			HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
			break;
		case OFF:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
			break;
		case ON:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
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

void controlSingleLedWalk(int statusLed)
{
	switch (statusLed)
	{
		case ONGREENOFFREDWALK:
			HAL_GPIO_WritePin(REDWALK_GPIO_Port, REDWALK_Pin, RESET);
			HAL_GPIO_WritePin(GREENWALK_GPIO_Port, GREENWALK_Pin, SET);
			break;
		case OFFLEDWALK:
			HAL_GPIO_WritePin(REDWALK_GPIO_Port, REDWALK_Pin, RESET);
			HAL_GPIO_WritePin(GREENWALK_GPIO_Port, GREENWALK_Pin, RESET);
			break;
		case ONREDOFFGREENWALK:
			HAL_GPIO_WritePin(REDWALK_GPIO_Port, REDWALK_Pin, SET);
			HAL_GPIO_WritePin(GREENWALK_GPIO_Port, GREENWALK_Pin, RESET);
			break;
		default:
			break;
	}
}
