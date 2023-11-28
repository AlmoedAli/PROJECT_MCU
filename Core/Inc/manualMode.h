/*
 * manualMode.h
 *
 *  Created on: Nov 17, 2023
 *      Author: TVB09
 */

#ifndef INC_MANUALMODE_H_
#define INC_MANUALMODE_H_

#define INITMODE 13
#define REDGREEN 14
#define REDYELLOW 15
#define GREENRED 16
#define YELLOWRED 17

extern int statusManualMode;

void runManualModeFunction();
void beginManualMode();
void beginWalkManualMode();

#endif /* INC_MANUALMODE_H_ */
