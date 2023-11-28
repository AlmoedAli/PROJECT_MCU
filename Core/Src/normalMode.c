/*
 * normalMode.c
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */

#include <deviceDriver7Segment.h>
#include "normalMode.h"
#include <main.h>
#include "deviceDriverSingleLed.h"
#include "tuningMode.h"
#include "softwareTimer.h"
#include "ledWalk.h"

int statusTraffic1 = INIT;
int statusTraffic2 = INIT;

int counterLedRed1;
int counterLedRed2;
int counterLedGreen1;
int counterLedGreen2;
int counterLedYellow1;
int counterLedYellow2;

void initStatusNormalMode()
{
	statusTraffic1 = INIT;
	statusTraffic2 = INIT;
}
void runNormalMode()
{
	switch (statusTraffic1)
	{
	case INIT:
		counterLedRed1 = durationLedRed;
		statusTraffic1 = REDNORMAL;
		onSingleRedTraffic1();
		update7SEGBufferTraffic1(counterLedRed1);
		break;
	case REDNORMAL:
		if (counterLedRed1 > 0)
		{
			counterLedRed1--;
			if (counterLedRed1 <= 0)
			{
				counterLedGreen1 = durationLedGreen;
				statusTraffic1 = GREENNORMAL;
				if (statusTraffic1== statusTraffic1Button3Pressed)
					numberFreq= (numberFreq > 0)? numberFreq- 1: numberFreq;
				onSingleGreenTraffic1();
				update7SEGBufferTraffic1(counterLedGreen1);
			}
			else
			{
				onSingleRedTraffic1();
				update7SEGBufferTraffic1(counterLedRed1);
			}
		}
		break;
	case GREENNORMAL:
		if (counterLedGreen1 > 0)
		{
			counterLedGreen1--;
			if (counterLedGreen1 <= 0)
			{
				counterLedYellow1 = durationLedYellow;
				statusTraffic1 = YELLOWNORMAL;
				if (statusTraffic1== statusTraffic1Button3Pressed)
					numberFreq= (numberFreq > 0)? numberFreq- 1: numberFreq;
				onSingleYellowTraffic1();
				update7SEGBufferTraffic1(counterLedYellow1);
			}
			else
			{
				onSingleGreenTraffic1();
				update7SEGBufferTraffic1(counterLedGreen1);
			}
		}
		break;
	case YELLOWNORMAL:
		if (counterLedYellow1 > 0)
		{
			counterLedYellow1--;
			if (counterLedYellow1 <= 0)
			{
				counterLedRed1 = durationLedRed;
				statusTraffic1 = REDNORMAL;
				if (statusTraffic1== statusTraffic1Button3Pressed)
					numberFreq= (numberFreq > 0)? numberFreq- 1: numberFreq;
				onSingleRedTraffic1();
				update7SEGBufferTraffic1(counterLedRed1);
			}
			else
			{
				onSingleYellowTraffic1();
				update7SEGBufferTraffic1(counterLedYellow1);
			}
		}
		break;
	default:
		break;
	}
	switch (statusTraffic2)
	{
	case INIT:
		statusTraffic2 = GREENNORMAL;
		counterLedGreen2 = durationLedGreen;
		onSingleGreenTraffic2();
		update7SEGBufferTraffic2(counterLedGreen2);
		break;
	case GREENNORMAL:
		if (counterLedGreen2 > 0)
		{
			counterLedGreen2--;
			if (counterLedGreen2 <= 0)
			{
				onSingleYellowTraffic2();
				counterLedYellow2 = durationLedYellow;
				statusTraffic2 = YELLOWNORMAL;
				update7SEGBufferTraffic2(counterLedYellow2);
			}
			else
			{
				onSingleGreenTraffic2();
				update7SEGBufferTraffic2(counterLedGreen2);
			}
		}
		break;
	case YELLOWNORMAL:
		if (counterLedYellow2 > 0)
		{
			counterLedYellow2--;
			if (counterLedYellow2 <= 0)
			{
				counterLedRed2 = durationLedRed;
				statusTraffic2 = REDNORMAL;
				onSingleRedTraffic2();
				update7SEGBufferTraffic2(counterLedRed2);
			}
			else
			{
				onSingleYellowTraffic2();
				update7SEGBufferTraffic2(counterLedYellow2);
			}
		}
		break;
	case REDNORMAL:
		if (counterLedRed2 > 0)
		{
			counterLedRed2--;
			if (counterLedRed2 <= 0)
			{
				counterLedGreen2 = durationLedGreen;
				statusTraffic2 = GREENNORMAL;
				onSingleGreenTraffic2();
				update7SEGBufferTraffic2(counterLedGreen2);
			}
			else
			{
				onSingleRedTraffic2();
				update7SEGBufferTraffic2(counterLedRed2);
			}
		}
		break;
	default:
		break;
	}
}

void beginNormalMode()
{
	offSingleRedGreenWalk();
	offAllSingLEDs();
	initStatusNormalMode();
	runNormalMode();
	setTimer2(100);
	update7SEGBufferMode(1);
	displayAll7Seg();
	setTimer4(10);
}
