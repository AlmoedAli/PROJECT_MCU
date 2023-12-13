/*
 * normalMode.h
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */

#ifndef INC_NORMALMODE_H_
#define INC_NORMALMODE_H_

#define INITNORMAL 0
#define	REDNORMAL 1
#define GREENNORMAL 2
#define YELLOWNORMAL 3

extern int statusTraffic1;
extern int statusTraffic2;
extern int counterLedRed1;

void beginNormalMode();
void runNormalMode();
void beginWalkNormalMode();

#endif /* INC_NORMALMODE_H_ */
