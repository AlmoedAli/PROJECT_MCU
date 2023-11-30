/*
 * update7SEG.h
 *
 *  Created on: Nov 2, 2023
 *      Author: TVB09
 */

#ifndef INC_DEVICEDRIVER7SEGMENT_H_
#define INC_DEVICEDRIVER7SEGMENT_H_

#define UPDATETRAFFIC1 0
#define UPDATETRAFFIC2 1
#define UPDATEMODE 2

extern int durationLedRed;
extern int durationLedGreen;
extern int durationLedYellow;

extern int tempDurationLedRed;
extern int tempDurationLedGreen;
extern int tempDurationLedYellow;

extern int led_buffer[3];

void update7SEGBufferTraffic1(int time);
void update7SEGBufferTraffic2(int time);
void update7SEGBufferMode(int time);

#endif /* INC_DEVICEDRIVER7SEGMENT_H_ */
