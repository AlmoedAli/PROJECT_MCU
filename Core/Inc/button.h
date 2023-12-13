/*
 * button.h
 *
 *  Created on: Oct 26, 2023
 *      Author: TVB09
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE 1
#define PRESS_STATE 0

#define INITMODES 2
#define NORMALMODE 3
#define MANUALMODE 4
#define TUNINGMODE 5

extern int modeStatus;

void getInputButton();

#endif /* INC_BUTTON_H_ */
