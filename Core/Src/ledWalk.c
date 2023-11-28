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

int numberFreq;
int statusTraffic1Button3Pressed;

void ledWalkOperation()
{
    switch (statusTraffic1)
    {
    case REDNORMAL:

    	switch (numberFreq)
    	{
			case 0:
				controlSingleLed(TRAFFIC1, OFFLEDWALK);
				break;
			default:
				controlSingleLed(TRAFFIC1, ONGREENOFFREDWALK);
				break;
		}
        break;
    case GREENNORMAL:
    	switch (numberFreq)
		{
			case 0:
				controlSingleLed(TRAFFIC1, OFFLEDWALK);
				break;
			default:
				controlSingleLed(TRAFFIC1, ONREDOFFGREENWALK);
				break;
		}
        break;
    case YELLOWNORMAL:
    	switch (numberFreq)
		{
			case 0:
				controlSingleLed(TRAFFIC1, OFFLEDWALK);
				break;
			default:
				controlSingleLed(TRAFFIC1, ONREDOFFGREENWALK);
				break;
		}
        break;
    default:
        break;
    }
}
