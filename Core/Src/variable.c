/*
 * variable.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Acer
 */

#include <deviceDriver7Segment.h>
#include "normalMode.h"
#include <main.h>
#include "deviceDriverSingleLed.h"
#include "softwareTimer.h"
#include "ledWalk.h"
#include "uart.h"
#include "SCH.h"
#include "variable.h"

int modeStatus = INITMODES;
