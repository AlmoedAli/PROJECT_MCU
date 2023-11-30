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

#define BUTTON1SinglePress 2
#define BUTTON1DoublePress 3
#define BUTTON1TriplePress 4
#define BUTTON1LongPress 5

#define BUTTON2SinglePress 6
#define BUTTON2DoublePress 7
#define BUTTON2LongPress 8

#define BUTTON3SinglePress 9
#define BUTTON3DoublePress 10
#define BUTTON3LongPress 11

#define NOBUTTON 12

int getInputButton();
void resetAllButton();

#endif /* INC_BUTTON_H_ */
