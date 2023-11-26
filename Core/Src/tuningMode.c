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
#include "normalMode.h"

int tempDurationLedRed = 7;
int tempDurationLedGreen = 5;
int tempDurationLedYellow = 2;

int durationLedRed = 7;
int durationLedGreen = 5;
int durationLedYellow = 2;

#define INITMODE 0
#define RED  1
#define YELLOW 2
#define GREEN 3

int statusTuningMode= INITMODE;

void runTuningMode()
{
    switch (statusTuningMode)
    {
        case INITMODE:
            statusTuningMode= RED;
            offAllSingLEDs();
             blinkingRED();
             setTimer3(50);
            update7SEGBufferTraffic1(durationLedRed);
            update7SEGBufferTraffic2(durationLedRed);
            update7SEGBufferMode(3);
            // displayAll7Seg();
            // setTimer4(10);
            break;
        case RED:
            statusTuningMode= YELLOW;
            offAllSingLEDs();
             blinkingYELLOW();
             setTimer3(50);
            update7SEGBufferTraffic1(durationLedYellow);
            update7SEGBufferTraffic2(durationLedYellow);
            update7SEGBufferMode(3);
//            displayAll7Seg();
            setTimer4(10);
            break;
        case YELLOW:
            statusTuningMode= GREEN;
            offAllSingLEDs();
            blinkingGREEN();
            setTimer3(50);
            update7SEGBufferTraffic1(durationLedGreen);
            update7SEGBufferTraffic2(durationLedGreen);
            update7SEGBufferMode(3);
            // displayAll7Seg();
            // setTimer4(10);
            break;
        case GREEN:
            statusTuningMode= RED;
            offAllSingLEDs();
             blinkingRED();
             setTimer3(50);
            update7SEGBufferTraffic1(durationLedRed);
            update7SEGBufferTraffic2(durationLedRed);
            update7SEGBufferMode(3);
            // displayAll7Seg();
            // setTimer4(10);
            break;
        default:
            break;
    }
}

void initStatusTuningMode()
{
    statusTuningMode= INITMODE;
}

void beginTuningMode()
{
    initStatusTuningMode();
    runTuningMode();
}

void modifyTuningMode()
{
    switch (statusTuningMode)
    {
        case RED:
            tempDurationLedRed++;
            if (tempDurationLedRed > 99)
            {
                tempDurationLedRed = 0;
            }
            update7SEGBufferTraffic1(tempDurationLedRed);
            update7SEGBufferTraffic2(tempDurationLedRed);
            break;
        case YELLOW:
            tempDurationLedYellow++;
            if (tempDurationLedYellow > 99)
            {
                tempDurationLedYellow = 0;
            }
            update7SEGBufferTraffic1(tempDurationLedYellow);
            update7SEGBufferTraffic2(tempDurationLedYellow);
            break;
        case GREEN:
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
}

void saveTuningMode()
{
    if (tempDurationLedRed != tempDurationLedYellow + tempDurationLedGreen)
    {
        switch (statusTuningMode)
        {
            case GREEN:
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
    }
    else
    {
        durationLedGreen = tempDurationLedGreen;
        durationLedRed = tempDurationLedRed;
        durationLedYellow = tempDurationLedYellow;
        initStatusNormalMode();
    }
}

void animationTuningMode()
{
    switch (statusTuningMode)
    {
    case INITMODE:
        break;
    case RED:
        blinkingRED();
        break;
    case YELLOW:
        blinkingYELLOW();
        break;
    case GREEN:
        blinkingGREEN();
        break;
    default:
        break;
    }
}
