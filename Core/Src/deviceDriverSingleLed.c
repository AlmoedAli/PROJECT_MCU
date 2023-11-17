/*
 * deviceDriverSingleLed.c
 *
 *  Created on: Nov 4, 2023
 *      Author: TVB09
 */

#include <main.h>
#include "deviceDriverSingleLed.h"
#include "physical7SingleLed.h"

void blinkingYELLOW()
{
	controlSingleLed(TRAFFIC1, YELLOWTUNINGMODE);
	controlSingleLed(TRAFFIC2, YELLOWTUNINGMODE);
}

void blinkingRED()
{
	controlSingleLed(TRAFFIC1, REDTUNINGMODE);
	controlSingleLed(TRAFFIC2, REDTUNINGMODE);
}
void blinkingGREEN()
{
	controlSingleLed(TRAFFIC1, GREENTUNINGMODE);
	controlSingleLed(TRAFFIC2, GREENTUNINGMODE);
}
void offAllSingLEDs()
{
	controlSingleLed(TRAFFIC1, OFF);
	controlSingleLed(TRAFFIC2, OFF);
}
void onAllSingLEDs()
{
	controlSingleLed(TRAFFIC1, ON);
	controlSingleLed(TRAFFIC2, ON);
}
void onSingleRedTraffic1()
{
	controlSingleLed(TRAFFIC1, REDNORMALMODE);
}
void onSingleYellowTraffic1()
{
	controlSingleLed(TRAFFIC1, YELLOWNORMALMODE);
}

void onSingleGreenTraffic1()
{
	controlSingleLed(TRAFFIC1, GREENNORMALMODE);
}

void onSingleRedTraffic2()
{
	controlSingleLed(TRAFFIC2, REDNORMALMODE);
}
void onSingleYellowTraffic2()
{
	controlSingleLed(TRAFFIC2, YELLOWNORMALMODE);
}

void onSingleGreenTraffic2()
{
	controlSingleLed(TRAFFIC2, GREENNORMALMODE);
}
