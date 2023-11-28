/*
 * normalMode.h
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */

#ifndef INC_NORMALMODE_H_
#define INC_NORMALMODE_H_

#define INIT 18
#define	REDNORMAL 19
#define GREENNORMAL 20
#define YELLOWNORMAL 21

extern int statusTraffic1;
extern int statusTraffic2;

void beginNormalMode();
void runNormalMode();
void beginWalkNormalMode();

#endif /* INC_NORMALMODE_H_ */
