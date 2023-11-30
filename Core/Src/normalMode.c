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
#include "softwareTimer.h"
#include "ledWalk.h"
#include "uart.h"
#include "SCH.h"

int statusTraffic1 = INITNORMAL;
int statusTraffic2 = INITNORMAL;

int counterLedRed1;
int counterLedRed2;
int counterLedGreen1;
int counterLedGreen2;
int counterLedYellow1;
int counterLedYellow2;

void initStatusNormalMode()
{
	statusTraffic1 = INITNORMAL;
	statusTraffic2 = INITNORMAL;
}
void runNormalMode()
{
	switch (statusTraffic1)
	{
	case INITNORMAL:
		counterLedRed1 = durationLedRed;
		statusTraffic1 = REDNORMAL;
		onSingleRedTraffic1();
		update7SEGBufferTraffic1(counterLedRed1);
		printTerminalInfoModeTraffic1();
		break;
	case REDNORMAL:
		if (counterLedRed1 > 0)
		{
			counterLedRed1--;
			if (counterLedRed1 <= 0)
			{
				counterLedGreen1 = durationLedGreen;
				statusTraffic1 = GREENNORMAL;
				if (statusLedWalkButton3Press== statusTraffic1)
					numberFreq= (numberFreq > 0)? numberFreq- 1: numberFreq;
				ledWalkOperationNormalMode();
				onSingleGreenTraffic1();
				update7SEGBufferTraffic1(counterLedGreen1);
				printTerminalInfoModeTraffic1();
			}
			else
			{
				onSingleRedTraffic1();
				update7SEGBufferTraffic1(counterLedRed1);
				printTerminalInfoModeTraffic1();
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
				if (statusLedWalkButton3Press== statusTraffic1)
					numberFreq= (numberFreq > 0)? numberFreq- 1: numberFreq;
				ledWalkOperationNormalMode();
				onSingleYellowTraffic1();
				update7SEGBufferTraffic1(counterLedYellow1);
				printTerminalInfoModeTraffic1();
			}
			else
			{
				onSingleGreenTraffic1();
				update7SEGBufferTraffic1(counterLedGreen1);
				printTerminalInfoModeTraffic1();
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
				if (statusLedWalkButton3Press== statusTraffic1)
					numberFreq= (numberFreq > 0)? numberFreq- 1: numberFreq;
				ledWalkOperationNormalMode();
				onSingleRedTraffic1();
				update7SEGBufferTraffic1(counterLedRed1);
				printTerminalInfoModeTraffic1();
			}
			else
			{
				onSingleYellowTraffic1();
				update7SEGBufferTraffic1(counterLedYellow1);
				printTerminalInfoModeTraffic1();
			}
		}
		break;
	default:
		break;
	}
	switch (statusTraffic2)
	{
	case INITNORMAL:
		statusTraffic2 = GREENNORMAL;
		counterLedGreen2 = durationLedGreen;
		onSingleGreenTraffic2();
		update7SEGBufferTraffic2(counterLedGreen2);
		printTerminalInfoTraffic2();
		break;
	case GREENNORMAL:
		if (counterLedGreen2 > 0)
		{
			counterLedGreen2--;
			if (counterLedGreen2 <= 0)
			{
				counterLedYellow2 = durationLedYellow;
				statusTraffic2 = YELLOWNORMAL;
				onSingleYellowTraffic2();
				update7SEGBufferTraffic2(counterLedYellow2);
				printTerminalInfoTraffic2();
			}
			else
			{
				onSingleGreenTraffic2();
				update7SEGBufferTraffic2(counterLedGreen2);
				printTerminalInfoTraffic2();
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
				printTerminalInfoTraffic2();
			}
			else
			{
				onSingleYellowTraffic2();
				update7SEGBufferTraffic2(counterLedYellow2);
				printTerminalInfoTraffic2();
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
				printTerminalInfoTraffic2();
			}
			else
			{
				onSingleRedTraffic2();
				update7SEGBufferTraffic2(counterLedRed2);
				printTerminalInfoTraffic2();
			}
		}
		break;
	default:
		break;
	}
}

void beginNormalMode()
{
	numberFreq= 0;
	offSingleRedGreenWalk();
	offAllSingLEDs();
	update7SEGBufferMode(1);
	initStatusNormalMode();
	runNormalMode();
//	setTimer2(100);
//	SCH_Delete_ID(2);
//	SCH_Add_Task(task2, 500, 500, 2);
}

void beginWalkNormalMode()
{
	numberFreq= 3;
	statusLedWalkButton3Press= statusTraffic1;
}
