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
	controlSingleLedTraffic(TRAFFIC1, YELLOWTUNING);
	controlSingleLedTraffic(TRAFFIC2, YELLOWTUNING);
}

void blinkingRED()
{
	controlSingleLedTraffic(TRAFFIC1, REDTUNING);
	controlSingleLedTraffic(TRAFFIC2, REDTUNING);
}

void blinkingGREEN()
{
	controlSingleLedTraffic(TRAFFIC1, GREENTUNING);
	controlSingleLedTraffic(TRAFFIC2, GREENTUNING);
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
	controlSingleLedTraffic(TRAFFIC1, REDNORMAL);
}

void onSingleYellowTraffic1()
{
	controlSingleLedTraffic(TRAFFIC1, YELLOWNORMAL);
}

void onSingleGreenTraffic1()
{
	controlSingleLedTraffic(TRAFFIC1, GREENNORMAL);
}

void onSingleRedTraffic2()
{
	controlSingleLedTraffic(TRAFFIC2, REDNORMAL);
}

void onSingleYellowTraffic2()
{
	controlSingleLedTraffic(TRAFFIC2, YELLOWNORMAL);
}

void onSingleGreenTraffic2()
{
	controlSingleLedTraffic(TRAFFIC2, GREENNORMAL);
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

