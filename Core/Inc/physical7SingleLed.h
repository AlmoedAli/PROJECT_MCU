/*
 * physical7SingleLed.h
 *
 *  Created on: Nov 7, 2023
 *      Author: TVB09
 */

#ifndef INC_PHYSICAL7SINGLELED_H_
#define INC_PHYSICAL7SINGLELED_H_

#define REDNORMALMODE 22
#define GREENNORMALMODE 23
#define YELLOWNORMALMODE 24
#define REDTUNINGMODE 25
#define GREENTUNINGMODE 26
#define YELLOWTUNINGMODE 27
#define OFF 28
#define ON 29
#define TRAFFIC1 30
#define TRAFFIC2 31
#define OFFLEDWALK 32
#define ONGREENOFFREDWALK 33
#define ONREDOFFGREENWALK 34

void controlSingleLedTraffic(int orderTraffic, int statusLed);
void controlSingleLedWalk(int statusLed);

#endif /* INC_PHYSICAL7SINGLELED_H_ */
