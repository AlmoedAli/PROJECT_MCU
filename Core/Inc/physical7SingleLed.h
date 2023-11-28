/*
 * physical7SingleLed.h
 *
 *  Created on: Nov 7, 2023
 *      Author: TVB09
 */

#ifndef INC_PHYSICAL7SINGLELED_H_
#define INC_PHYSICAL7SINGLELED_H_

#define REDNORMALMODE 0
#define GREENNORMALMODE 1
#define YELLOWNORMALMODE 2
#define REDTUNINGMODE 3
#define GREENTUNINGMODE 4
#define YELLOWTUNINGMODE 5
#define OFF 6
#define ON 7
#define TRAFFIC1 8
#define TRAFFIC2 9
#define OFFLEDWALK 10
#define ONGREENOFFREDWALK 11
#define ONREDOFFGREENWALK 12

void controlSingleLed(int orderTraffic, int statusLed);

#endif /* INC_PHYSICAL7SINGLELED_H_ */
