/*
 * manualMode.h
 *
 *  Created on: Nov 17, 2023
 *      Author: TVB09
 */

#ifndef INC_MANUALMODE_H_
#define INC_MANUALMODE_H_

#define INITMANUAL 0
#define REDGREENMANUAL 1
#define REDYELLOWMANUAL 2
#define GREENREDMANUAL 3
#define YELLOWREDMANUAL 4

extern int statusManualMode;

void runManualModeFunction();
void beginManualMode();
void beginWalkManualMode();

#endif /* INC_MANUALMODE_H_ */
