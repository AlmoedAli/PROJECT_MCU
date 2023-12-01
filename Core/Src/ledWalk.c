/*
 * ledWalk.c
 *
 *  Created on: Nov 27, 2023
 *      Author: TVB09
 */


#include "ledWalk.h"
#include "deviceDriverSingleLed.h"
#include "manualMode.h"
#include "normalMode.h"
#include "pwm.h"

int numberFreq;
int statusLedWalkButton3Press;

void ledWalkOperationNormalMode()
{
    switch (statusTraffic1)
    {
    case REDNORMAL:
		if (numberFreq <= 0)
		{
			buzzerOff();
			offSingleRedGreenWalk();
		}
		else
		{
			onGreenOffRedWalk();
			if (counterLedRed1 <= 3)
			{
				buzzerBegin();
			}
		}
        break;
    case GREENNORMAL:
		if (numberFreq <= 0)
		{
			offSingleRedGreenWalk();
			buzzerOff();
		}
		else
		{
			onRedOffGreenWalk();
			buzzerOff();
		}
        break;
    case YELLOWNORMAL:
		if (numberFreq <= 0)
			offSingleRedGreenWalk();
		else	
			onRedOffGreenWalk();
        break;
    default:
        break;
    }
}

void ledWalkOperationManualMode()
{
	switch (statusManualMode)
	{
	case REDGREENMANUAL:
		if (numberFreq <= 0)
			offSingleRedGreenWalk();
		else
			onGreenOffRedWalk();
		break;
	case YELLOWREDMANUAL:
		if (numberFreq <= 0)
			offSingleRedGreenWalk();
		else
			onGreenOffRedWalk();
		break;
	case GREENREDMANUAL:
		if (numberFreq <= 0)
			offSingleRedGreenWalk();
		else
			onRedOffGreenWalk();
		break;
	case REDYELLOWMANUAL:
		if (numberFreq <= 0)
			offSingleRedGreenWalk();
		else
			onGreenOffRedWalk();

		break;
	default:
		break;
	}
}
