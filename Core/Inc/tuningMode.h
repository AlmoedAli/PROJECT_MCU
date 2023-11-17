/*
 * tuningMode.h
 *
 *  Created on: Nov 17, 2023
 *      Author: TVB09
 */

#ifndef INC_TUNINGMODE_H_
#define INC_TUNINGMODE_H_

extern int durationLedRed;
extern int durationLedGreen;
extern int durationLedYellow;

extern int tempDurationLedRed;
extern int tempDurationLedGreen;
extern int tempDurationLedYellow;

void changeStatusTuningMode();
void setInitTuningModeFunction();
void modifyTuningModeFuction();
void saveTuningModeFunction();

#endif /* INC_TUNINGMODE_H_ */
