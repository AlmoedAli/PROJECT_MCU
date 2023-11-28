/*
 * normalMode.h
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */

#ifndef INC_NORMALMODE_H_
#define INC_NORMALMODE_H_

#define INIT 0
#define	REDNORMAL 1
#define GREENNORMAL 2
#define YELLOWNORMAL 3

extern int statusTraffic1;
extern int statusTraffic2;
extern int numberFreq;

void beginNormalMode();
void runNormalMode();

#endif /* INC_NORMALMODE_H_ */
