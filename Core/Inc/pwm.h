/*
 * pwm.h
 *
 *  Created on: Dec 1, 2023
 *      Author: TVB09
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "main.h"

extern TIM_HandleTypeDef htim3;
extern int flagBuzzer;
extern int pre;
extern int com;
void MX_TIM3_Init(void);
void buzzerSetup();
void buzzerRun();
void buzzerBegin();
void buzzerOff();

#endif /* INC_PWM_H_ */
