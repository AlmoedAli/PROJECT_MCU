/*
 * manualMode.c
 *
 *  Created on: Nov 17, 2023
 *      Author: TVB09
 */


#include "manualMode.h"
#include "deviceDriverSingleLed.h"
#include "deviceDriver7Segment.h"

int statusManualMode= INITMODE;

void initStatusManualMode()
{
	statusManualMode= INITMODE;
}
void runManualModeFunction()
{
	switch (statusManualMode) 
	{
		case INITMODE:
			statusManualMode= REDGREEN;
			update7SEGBufferMode(2);
			offAllSingLEDs();
			onSingleRedTraffic1();
			onSingleGreenTraffic2();
			break;
		case REDGREEN:
			statusManualMode= REDYELLOW;
			update7SEGBufferMode(2);
			offAllSingLEDs();
			onSingleRedTraffic1();
			onSingleYellowTraffic2();
			break;
		case REDYELLOW:
			statusManualMode= GREENRED;
			update7SEGBufferMode(2);
			offAllSingLEDs();
			onSingleGreenTraffic1();
			onSingleRedTraffic2();
			break;
		case GREENRED:
			statusManualMode= YELLOWRED;
			update7SEGBufferMode(2);
			offAllSingLEDs();
			onSingleYellowTraffic1();
			onSingleRedTraffic2();
			break;
		case YELLOWRED:
			statusManualMode= REDGREEN;
			update7SEGBufferMode(2);
			offAllSingLEDs();
			onSingleRedTraffic1();
			onSingleGreenTraffic2();
			break;
		default:
			break;
	}
}

void beginManualMode()
{
	offSingleRedGreenWalk();
	initStatusManualMode();
	runManualModeFunction();
}
