/*
 * manualMode.c
 *
 *  Created on: Nov 17, 2023
 *      Author: TVB09
 */


#include "manualMode.h"
#include "deviceDriverSingleLed.h"
#include "deviceDriver7Segment.h"
#include "ledWalk.h"

int statusManualMode= INITMANUAL;

void initStatusManualMode()
{
	statusManualMode= INITMANUAL;
}
void runManualModeFunction()
{
	switch (statusManualMode) 
	{
		case INITMANUAL:
			statusManualMode= REDGREENMANUAL;
			update7SEGBufferMode(2);
			offAllSingLEDs();
			onSingleRedTraffic1();
			onSingleGreenTraffic2();
			break;
		case REDGREENMANUAL:
			statusManualMode= REDYELLOWMANUAL;
			if (statusManualMode== statusLedWalkButton3Press)
				numberFreq= (numberFreq > 0)? numberFreq-1 :numberFreq;
			ledWalkOperationManualMode();
			offAllSingLEDs();
			onSingleRedTraffic1();
			onSingleYellowTraffic2();
			break;
		case REDYELLOWMANUAL:
			statusManualMode= GREENREDMANUAL;
			if (statusManualMode== statusLedWalkButton3Press)
				numberFreq= (numberFreq > 0)? numberFreq-1 :numberFreq;
			ledWalkOperationManualMode();
			update7SEGBufferMode(2);
			offAllSingLEDs();
			onSingleGreenTraffic1();
			onSingleRedTraffic2();
			break;
		case GREENREDMANUAL:
			statusManualMode= YELLOWREDMANUAL;
			if (statusManualMode== statusLedWalkButton3Press)
				numberFreq= (numberFreq > 0)? numberFreq-1 :numberFreq;
			ledWalkOperationManualMode();
			update7SEGBufferMode(2);
			offAllSingLEDs();
			onSingleYellowTraffic1();
			onSingleRedTraffic2();
			break;
		case YELLOWREDMANUAL:
			statusManualMode= REDGREENMANUAL;
			if (statusManualMode== statusLedWalkButton3Press)
				numberFreq= (numberFreq > 0)? numberFreq-1 :numberFreq;
			ledWalkOperationManualMode();
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
	numberFreq= 0;
	offSingleRedGreenWalk();
	initStatusManualMode();
	runManualModeFunction();
}

void beginWalkManualMode()
{
	numberFreq= 3;
	statusLedWalkButton3Press= statusManualMode;
}
