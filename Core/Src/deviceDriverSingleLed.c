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
	controlSingleLedTraffic(TRAFFIC1, YELLOWTUNINGMODE);
	controlSingleLedTraffic(TRAFFIC2, YELLOWTUNINGMODE);
}

void blinkingRED()
{
	controlSingleLedTraffic(TRAFFIC1, REDTUNINGMODE);
	controlSingleLedTraffic(TRAFFIC2, REDTUNINGMODE);
}
void blinkingGREEN()
{
	controlSingleLedTraffic(TRAFFIC1, GREENTUNINGMODE);
	controlSingleLedTraffic(TRAFFIC2, GREENTUNINGMODE);
}
void offAllSingLEDs()
{
	controlSingleLedTraffic(TRAFFIC1, OFF);
	controlSingleLedTraffic(TRAFFIC2, OFF);
}
void onAllSingLEDs()
{
	controlSingleLedTraffic(TRAFFIC1, ON);
	controlSingleLedTraffic(TRAFFIC2, ON);
}
void onSingleRedTraffic1()
{
	controlSingleLedTraffic(TRAFFIC1, REDNORMALMODE);
}
void onSingleYellowTraffic1()
{
	controlSingleLedTraffic(TRAFFIC1, YELLOWNORMALMODE);
}

void onSingleGreenTraffic1()
{
	controlSingleLedTraffic(TRAFFIC1, GREENNORMALMODE);
}

void onSingleRedTraffic2()
{
	controlSingleLedTraffic(TRAFFIC2, REDNORMALMODE);
}
void onSingleYellowTraffic2()
{
	controlSingleLedTraffic(TRAFFIC2, YELLOWNORMALMODE);
}

void onSingleGreenTraffic2()
{
	controlSingleLedTraffic(TRAFFIC2, GREENNORMALMODE);
}

void offSingleRedGreenWalk()
{
	controlSingleLedWalk(OFFLEDWALK);
}
void onGreenOffRedWalk()
{
	controlSingleLedWalk(ONGREENOFFREDWALK);
}
void onRedOffGreenWalk()
{
	controlSingleLedWalk(ONREDOFFGREENWALK);
}

