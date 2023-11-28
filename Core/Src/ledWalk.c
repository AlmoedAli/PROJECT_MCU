/*
 * ledWalk.c
 *
 *  Created on: Nov 27, 2023
 *      Author: TVB09
 */


#include "ledWalk.h"
#include "normalMode.h"
#include "main.h"
#include "physical7SingleLed.h"
#include "manualMode.h"

int numberFreq;
int statusLedWalkButton3Press;

void ledWalkOperationNormalMode()
{
    switch (statusTraffic1)
    {
    case REDNORMAL:
		if (numberFreq <= 0)
			controlSingleLedWalk(OFFLEDWALK);
		else
			controlSingleLedWalk(ONGREENOFFREDWALK);
        break;
    case GREENNORMAL:
		if (numberFreq <= 0)
			controlSingleLedWalk(OFFLEDWALK);
		else
			controlSingleLedWalk(ONREDOFFGREENWALK);
        break;
    case YELLOWNORMAL:
		if (numberFreq <= 0)
			controlSingleLedWalk(OFFLEDWALK);
		else	
			controlSingleLedWalk(ONREDOFFGREENWALK);
        break;
    default:
        break;
    }
}

void ledWalkOperationManualMode()
{
	switch (statusManualMode)
	{
	case REDGREEN:
		switch (numberFreq)
		{
		case 0:
			controlSingleLedWalk(OFFLEDWALK);
			break;
		default:
			controlSingleLedWalk(ONGREENOFFREDWALK);
			break;
		}
		break;
	case YELLOWRED:
		switch (numberFreq)
		{
			case 0:
				controlSingleLedWalk(OFFLEDWALK);
				break;
			default:
				controlSingleLedWalk(ONREDOFFGREENWALK);
				break;
		}
		break;
	case GREENRED:
		switch (numberFreq)
		{
			case 0:
				controlSingleLedWalk(OFFLEDWALK);
				break;
			default:
				controlSingleLedWalk(ONREDOFFGREENWALK);
				break;
		}
		break;
	case REDYELLOW:
		switch (numberFreq)
		{
			case 0:
				controlSingleLedWalk(OFFLEDWALK);
				break;
			default:
				controlSingleLedWalk(ONGREENOFFREDWALK);
				break;
		}
		break;
	default:
		break;
	}
}
