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
	controlSingleLed(TRAFFIC1, YELLOWADVANCEDMODE);
	controlSingleLed(TRAFFIC2, YELLOWADVANCEDMODE);
}

void blinkingRED()
{
	controlSingleLed(TRAFFIC1, REDADVANCEDMODE);
	controlSingleLed(TRAFFIC2, REDADVANCEDMODE);
}
void blinkingGREEN()
{
	controlSingleLed(TRAFFIC1, GREENADVANCEDMODE);
	controlSingleLed(TRAFFIC2, GREENADVANCEDMODE);
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
