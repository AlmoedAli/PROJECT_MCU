///*
// * schON.c
// *
// *  Created on: Dec 1, 2023
// *      Author: Acer
// */
//
//
//#include <deviceDriver7Segment.h>
//#include "normalMode.h"
//#include <main.h>
//#include "deviceDriverSingleLed.h"
//#include "softwareTimer.h"
//#include "ledWalk.h"
//#include "uart.h"
//#include "sch.h"
//#include "button.h"
//
//typedef struct
//{
//  // Pointer to the task
//  void (*pTask)(void);
//  // Delay (ticks) until the function will (next) be run
//  uint32_t Delay;
//  // Interval (ticks) between subsequent runs
//  uint32_t Period;
//  // Incremented (by scheduler) when task is due to execute
//  uint8_t RunMe;
//  // This is a hint to solve the question below
//  uint32_t TaskID;
//} sTask;
//
//uint8_t nTask = 0;
//sTask SCH_Tasks_G[SCH_MAX_TASKS];
//
//void SCH_Update(){
//	uint8_t index;
//	for( index=0; index<SCH_MAX_TASKS; index++){
//		if(SCH_Tasks_G[index].pTask){
//			if(SCH_Tasks_G[index].Delay == 0){
//				SCH_Tasks_G[index].RunMe+=1;
//				if(SCH_Tasks_G[index].Period){
//					SCH_Tasks_G[index].Delay = SCH_Tasks_G[index].Period;
//				}
//			}
//			else{
//				SCH_Tasks_G[index].Delay--;
//			}
//		}
//	}
//}
//
//uint8_t SCH_addTask(void (*pFunction), const uint8_t Delay, const uint8_t Period){
//	uint8_t index = -1;
//	for(int i=0; i<SCH_MAX_TASKS; i++){
//		if(SCH_Tasks_G[i].pTask){
//			continue;
//		}
//		else{
//			index = i;
//			break;
//		}
//	}
//	if(index == -1){
//		//Error
//
//		return SCH_MAX_TASKS;
//	}
//	SCH_Tasks_G[index].pTask = pFunction;
//	SCH_Tasks_G[index].Delay = Delay;
//	SCH_Tasks_G[index].Period = Period;
//	SCH_Tasks_G[index].RunMe = 0;
//	return index;
//}
//
//void SCH_Delete_Task(uint8_t index){
//	SCH_Tasks_G[index].Delay = 0;
//	SCH_Tasks_G[index].Period = 0;
//	SCH_Tasks_G[index].RunMe = 0;
//	SCH_Tasks_G[index].pTask = 0x0000;
//}
//
//void SCH_Dispatch_Tasks(void){
//	uint8_t index;
//	for(index = 0; index<SCH_MAX_TASKS; index++){
//		if(SCH_Tasks_G[index].RunMe>0){
//			(*SCH_Tasks_G[index].pTask)();
//			SCH_Tasks_G[index].RunMe--;
//
//			if(SCH_Tasks_G[index].Period==0)
//			{
//				SCH_Delete_Task(index);
//			}
//		}
//	}
////	SCH_Report_Status();
////	SCH_Go_To_Sleep();
//}
//
//void SCH_Init(void)
//{
//  uint8_t i;
//  for (i = 0; i < SCH_MAX_TASKS; i++)
//  {
//    SCH_Tasks_G[i].Delay = 0;
//    SCH_Tasks_G[i].Period = 0;
//    SCH_Tasks_G[i].RunMe = 0;
//    SCH_Tasks_G[i].pTask = 0x0000;
//    SCH_Tasks_G[i].TaskID = 0;
//  }
//}
//
////function for run normal mode every 1s
//void task1()
//{
//  if (modeStatus == NORMALMODE)
//  {
//    runNormalMode();
//    ledWalkOperationNormalMode();
//  }
//}
//
////function for run tuning mode every 0.5s
//void task2()
//{
//  if (modeStatus == TUNINGMODE)
//  {
//    animationTuningMode();
//  }
//}
//
////function for get button every 10ms
//void task3()
//{
//	getInputButton();
//}
