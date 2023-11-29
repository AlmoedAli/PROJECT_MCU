/*
 * physical7SingleLed.h
 *
 *  Created on: Nov 7, 2023
 *      Author: TVB09
 */

#ifndef INC_PHYSICAL7SINGLELED_H_
#define INC_PHYSICAL7SINGLELED_H_

#define REDNORMAL 0
#define GREENNORMAL 1
#define YELLOWNORMAL 2
#define REDTUNING 3
#define GREENTUNING 4
#define YELLOWTUNING 5
#define OFF 6
#define ON 7
#define TRAFFIC1 8
#define TRAFFIC2 9
#define OFFLEDWALK 10
#define ONGREENOFFREDWALK 11
#define ONREDOFFGREENWALK 12

void controlSingleLedTraffic(int orderTraffic, int statusLed);
void controlSingleLedWalk(int statusLed);

#endif /* INC_PHYSICAL7SINGLELED_H_ */
