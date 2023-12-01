/*
 * tuningMode.c
 *
 *  Created on: Nov 17, 2023
 *      Author: TVB09
 */


#include "tuningMode.h"
#include "deviceDriver7Segment.h"
#include "deviceDriverSingleLed.h"
#include "softwareTimer.h"
#include "ledWalk.h"
#include "uart.h"
#include "pwm.h"

#define INITMODE 0
#define REDTUNING  1
#define YELLOWTUNING 2
#define GREENTUNING 3

int statusTuningMode= INITMODE;

void runTuningMode()
{
    switch (statusTuningMode)
    {
        case INITMODE:
            statusTuningMode= REDTUNING;
            offAllSingLEDs();
            // blinkingRED();
            // setTimer3(50);
            update7SEGBufferTraffic1(durationLedRed);
            update7SEGBufferTraffic2(durationLedRed);
            break;
        case REDTUNING:
            statusTuningMode= YELLOWTUNING;
            offAllSingLEDs();
            // blinkingYELLOW();
            // setTimer3(50);
            update7SEGBufferTraffic1(durationLedYellow);
            update7SEGBufferTraffic2(durationLedYellow);
            break;
        case YELLOWTUNING:
            statusTuningMode= GREENTUNING;
            offAllSingLEDs();
            // blinkingGREEN();
            // setTimer3(50);
            update7SEGBufferTraffic1(durationLedGreen);
            update7SEGBufferTraffic2(durationLedGreen);
            break;
        case GREENTUNING:
            statusTuningMode= REDTUNING;
            offAllSingLEDs();
            // blinkingRED();
            // setTimer3(50);
            update7SEGBufferTraffic1(durationLedRed);
            update7SEGBufferTraffic2(durationLedRed);
            break;
        default:
            break;
    }
    printTerminalInfoModeTraffic1();
    printTerminalInfoTraffic2();
}

void initStatusTuningMode()
{
    statusTuningMode= INITMODE;
}

void setValueAllOfTraffic()
{
	tempDurationLedGreen = durationLedGreen;
	tempDurationLedRed = durationLedRed;
	tempDurationLedYellow = durationLedYellow;
}

void beginTuningMode()
{
	numberFreq= 0;
	buzzerOff();
	setValueAllOfTraffic();
    offSingleRedGreenWalk();
    initStatusTuningMode();
    update7SEGBufferMode(3);
    runTuningMode();
}

void modifyTuningMode()
{
    switch (statusTuningMode)
    {
        case REDTUNING:
            tempDurationLedRed++;
            if (tempDurationLedRed > 99)
            {
                tempDurationLedRed = 0;
            }
            update7SEGBufferTraffic1(tempDurationLedRed);
            update7SEGBufferTraffic2(tempDurationLedRed);
            break;
        case YELLOWTUNING:
            tempDurationLedYellow++;
            if (tempDurationLedYellow > 99)
            {
                tempDurationLedYellow = 0;
            }
            update7SEGBufferTraffic1(tempDurationLedYellow);
            update7SEGBufferTraffic2(tempDurationLedYellow);
            break;
        case GREENTUNING:
            tempDurationLedGreen++;
            if (tempDurationLedGreen > 99)
            {
                tempDurationLedGreen = 0;
            }
            update7SEGBufferTraffic1(tempDurationLedGreen);
            update7SEGBufferTraffic2(tempDurationLedGreen);
            break;
        default:
            break;
    }
    printTerminalInfoModeTraffic1();
	printTerminalInfoTraffic2();
}

void saveTuningMode()
{
    if (tempDurationLedRed != tempDurationLedYellow + tempDurationLedGreen)
    {
        switch (statusTuningMode)
        {
            case GREENTUNING:
                update7SEGBufferTraffic1(88);
                update7SEGBufferTraffic2(88);
                update7SEGBufferMode(8);
                onAllSingLEDs();
                tempDurationLedGreen = durationLedGreen;
                tempDurationLedRed = durationLedRed;
                tempDurationLedYellow = durationLedYellow;
                break;
            default:
                tempDurationLedGreen = durationLedGreen;
                tempDurationLedRed = durationLedRed;
                tempDurationLedYellow = durationLedYellow;
                break;
        }
        uint8_t str[]="!SAVE_VALUE_FAIL#\n\n";
		HAL_UART_Transmit(&huart1, str, sizeof(str), 1000);
    }
    else
    {
        durationLedGreen = tempDurationLedGreen;
        durationLedRed = tempDurationLedRed;
        durationLedYellow = tempDurationLedYellow;
        uint8_t str[]="!SAVE_VALUE_PASS#\n\n";
        HAL_UART_Transmit(&huart1, str, sizeof(str), 1000);
    }
}

void animationTuningMode()
{
    switch (statusTuningMode)
    {
    case INITMODE:
        break;
    case REDTUNING:
        blinkingRED();
        break;
    case YELLOWTUNING:
        blinkingYELLOW();
        break;
    case GREENTUNING:
        blinkingGREEN();
        break;
    default:
        break;
    }
}
