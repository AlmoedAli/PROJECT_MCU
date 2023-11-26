/*
 * update7SEG.h
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */

#ifndef INC_DEVICEDRIVER7SEGMENT_H_
#define INC_DEVICEDRIVER7SEGMENT_H_

//extern int led_buffer[5];

void displayAll7Seg();
void update7SEGBufferTraffic1(int time);
void update7SEGBufferTraffic2(int time);
void update7SEGBufferMode(int time);

#endif /* INC_DEVICEDRIVER7SEGMENT_H_ */
