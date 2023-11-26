/*
 * ledWalk.c
 *
 *  Created on: Nov 26, 2023
 *      Author: Acer
 */

#include "ledWalk.h"
#include "main.h"
#include "physical7SingleLed.h"
#include "physicalBuzzer.h"

int walkStatus;
int flagWalk;

void runLedWalkMode(){
	switch(walkStatus){
	case REDON:
		buzzerOff();
		WALKOFF();
		break;
	case GREENON:
		WALKON();
		break;
	case YELLOWON:
		buzzerOn();
		WALKOFF();
		break;
	default:
		break;
	}
}
