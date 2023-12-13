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
#include "pwm.h"
#include "uart.h"

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
			update7SEGBufferTraffic1(durationLedRed);
			update7SEGBufferTraffic2(durationLedGreen);
			break;
		case REDGREENMANUAL:
			statusManualMode= REDYELLOWMANUAL;
			if (statusManualMode== statusLedWalkButton3Press)
				numberFreq= (numberFreq > 0)? numberFreq-1 :numberFreq;
			ledWalkOperationManualMode();
			offAllSingLEDs();
			onSingleRedTraffic1();
			onSingleYellowTraffic2();
			update7SEGBufferTraffic1(durationLedRed);
			update7SEGBufferTraffic2(durationLedYellow);
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
			update7SEGBufferTraffic1(durationLedGreen);
			update7SEGBufferTraffic2(durationLedRed);
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
			update7SEGBufferTraffic1(durationLedYellow);
			update7SEGBufferTraffic2(durationLedRed);
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
			update7SEGBufferTraffic1(durationLedRed);
			update7SEGBufferTraffic2(durationLedGreen);
			break;
		default:
			break;
	}
	printTerminalInfoModeTraffic1();
	printTerminalInfoTraffic2();
}

void beginManualMode()
{
	numberFreq= 0;
	buzzerOff();
	offSingleRedGreenWalk();
	update7SEGBufferMode(2);
	initStatusManualMode();
	runManualModeFunction();
}

void beginWalkManualMode()
{
	numberFreq= 2;
	statusLedWalkButton3Press= statusManualMode;
}
