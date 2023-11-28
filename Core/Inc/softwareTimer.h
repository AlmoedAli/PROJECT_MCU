/*
 * softwareTimer.h
 *
 *  Created on: Oct 26, 2023
 *      Author: TVB09
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int counter1;
extern int flag1;

extern int counter2;
extern int flag2;

extern int counter3;
extern int flag3;

extern int counter4;
extern int flag4;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void runTimer();

#endif /* INC_SOFTWARETIMER_H_ */
