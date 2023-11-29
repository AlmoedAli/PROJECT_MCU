/*
 * update7SEG.c
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */

#include "deviceDriver7Segment.h"
#include "physical7Segment.h"

int tempDurationLedRed = 7;
int tempDurationLedGreen = 5;
int tempDurationLedYellow = 2;

int durationLedRed = 5;
int durationLedGreen = 3;
int durationLedYellow = 2;

int led_buffer[3]= {0, 0, 0};
void update7SEGBuffer(int time, int signalUpdate)
{
	switch (signalUpdate)
	{
	case UPDATETRAFFIC1:
		led_buffer[0] = time;
		break;
	case UPDATETRAFFIC2:
		led_buffer[1] = time;
		break;
	case UPDATEMODE:
		led_buffer[2] = time;
		break;
	default:
		break;
	}
}

void update7SEGBufferTraffic1(int time)
{
	update7SEGBuffer(time, UPDATETRAFFIC1);
}

void update7SEGBufferTraffic2(int time)
{
	update7SEGBuffer(time, UPDATETRAFFIC2);
}

void update7SEGBufferMode(int time)
{
	update7SEGBuffer(time, UPDATEMODE);
}

//void displayAll7Seg()
//{
//	Scan7SEG();
//}
