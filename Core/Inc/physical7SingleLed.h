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
#define REDADVANCEDMODE 3
#define GREENADVANCEDMODE 4
#define YELLOWADVANCEDMODE 5
#define OFF 6
#define ON 7
#define TRAFFIC1 8
#define TRAFFIC2 9

void controlSingleLed(int orderTraffic, int statusLed);

#endif /* INC_PHYSICAL7SINGLELED_H_ */
