/*
 * SCH.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Acer
 */

#include <deviceDriver7Segment.h>
#include "normalMode.h"
#include <main.h>
#include "deviceDriverSingleLed.h"
#include "softwareTimer.h"
#include "ledWalk.h"
#include "uart.h"
#include "SCH.h"
#include "variable.h"
#include "button.h"

typedef struct
{
  // Pointer to the task
  void (*pTask)(void);
  // Delay (ticks) until the function will (next) be run
  uint32_t Delay;
  // Interval (ticks) between subsequent runs
  uint32_t Period;
  // Incremented (by scheduler) when task is due to execute
  uint8_t RunMe;
  // This is a hint to solve the question below
  uint32_t TaskID;
} sTask;

uint8_t nTask = 0;
sTask SCH_tasks_G[SCH_MAX_TASKS];

// Ham giam dan thoi gian delay va set RunMe len de execute
void SCH_Update()
{
  if (SCH_tasks_G[0].pTask)
  {
    if (SCH_tasks_G[0].Delay == 0)
    {
      SCH_tasks_G[0].RunMe += 1;
    }
    else
    {
      SCH_tasks_G[0].Delay--;
    }
  }
}

// Ham them task vao mang
void SCH_Add_Task(void(*pFunction), const uint32_t Delay, const uint32_t Period, uint8_t taskID)
{
  int index = 0;
  int total_delay = Delay / 10;

  for (int i = 0; i < SCH_MAX_TASKS; i++)
  {
    if (SCH_tasks_G[i].pTask)
    {
      if (SCH_tasks_G[i].Delay <= total_delay)
      {
        total_delay = total_delay - SCH_tasks_G[i].Delay;
      }
      else
      {
        index = i;
        break;
      }
    }
    else
    {
      index = i;
      break;
    }
  }
  for (int i = SCH_MAX_TASKS; i > index; i--)
  {
    if (SCH_tasks_G[i - 1].pTask)
    {
      SCH_tasks_G[i].pTask = SCH_tasks_G[i - 1].pTask;
      SCH_tasks_G[i].Delay = SCH_tasks_G[i - 1].Delay;
      SCH_tasks_G[i].Period = SCH_tasks_G[i - 1].Period;
      SCH_tasks_G[i].RunMe = SCH_tasks_G[i - 1].RunMe;
      SCH_tasks_G[i].TaskID = SCH_tasks_G[i - 1].TaskID;
    }
  }
  SCH_tasks_G[index].pTask = pFunction;
  SCH_tasks_G[index].Delay = total_delay;
  SCH_tasks_G[index].Period = Period;
  SCH_tasks_G[index].RunMe = 0;
  SCH_tasks_G[index].TaskID = taskID;
  if (SCH_tasks_G[index + 1].pTask)
  {
    SCH_tasks_G[index + 1].Delay = SCH_tasks_G[index + 1].Delay - total_delay;
  }
}

void SCH_Delete(uint8_t index)
{
  SCH_tasks_G[index].Delay = 0;
  SCH_tasks_G[index].Period = 0;
  SCH_tasks_G[index].RunMe = 0;
  SCH_tasks_G[index].pTask = 0x0000;
  SCH_tasks_G[index].TaskID = 0;
}

void SCH_Delete_ID(uint8_t ID)
{
	uint8_t index = 0;
	uint8_t final = 0;

	for(int i = 0; i < SCH_MAX_TASKS; i++)
	{
	  if( SCH_tasks_G[i].TaskID == ID){
		  SCH_Delete(i);
		  index = i;
		  break;
	  }
	}
	for (int i = index; i < SCH_MAX_TASKS; i++)
	{
		SCH_tasks_G[i].pTask = SCH_tasks_G[i + 1].pTask;
		SCH_tasks_G[i].Delay = SCH_tasks_G[i + 1].Delay;
		SCH_tasks_G[i].Period = SCH_tasks_G[i + 1].Period;
		SCH_tasks_G[i].RunMe = SCH_tasks_G[i + 1].RunMe;
		SCH_tasks_G[i].TaskID = SCH_tasks_G[i + 1].TaskID;
		if (SCH_tasks_G[i].pTask == 0x0000 && i != index)
		{
		  final = i;
		  break;
		}
	}
	SCH_Delete(final);
}

// Xoa task dau tien
void SCH_Delete_Task(uint8_t index)
{
  int final = 0;
  SCH_Delete(index);
  for (int i = index; i < SCH_MAX_TASKS; i++)
  {
    SCH_tasks_G[i].pTask = SCH_tasks_G[i + 1].pTask;
    SCH_tasks_G[i].Delay = SCH_tasks_G[i + 1].Delay;
    SCH_tasks_G[i].Period = SCH_tasks_G[i + 1].Period;
    SCH_tasks_G[i].RunMe = SCH_tasks_G[i + 1].RunMe;
    SCH_tasks_G[i].TaskID = SCH_tasks_G[i + 1].TaskID;
    if (SCH_tasks_G[i].pTask == 0x0000)
    {
      final = i;
      break;
    }
  }
  SCH_Delete(final);
}

// Ham check xem task0 da can execute chua
void SCH_Dispatch_Tasks(void)
{
  if (SCH_tasks_G[0].pTask)
  {
    if (SCH_tasks_G[0].RunMe > 0)
    {
      (*SCH_tasks_G[0].pTask)();
      SCH_tasks_G[0].RunMe--;

      if (SCH_tasks_G[0].Period)
      {
        SCH_Add_Task(SCH_tasks_G[0].pTask, SCH_tasks_G[0].Period,
        		SCH_tasks_G[0].Period, SCH_tasks_G[0].TaskID);
      }
      SCH_Delete_Task(0);
    }
  }
}
// Ham xoa tat ca cac task trong array, khien array nhu vua duoc khoi tao
void SCH_Init(void)
{
  uint8_t i;
  for (i = 0; i < SCH_MAX_TASKS; i++)
  {
    SCH_tasks_G[i].Delay = 0;
    SCH_tasks_G[i].Period = 0;
    SCH_tasks_G[i].RunMe = 0;
    SCH_tasks_G[i].pTask = 0x0000;
    SCH_tasks_G[i].TaskID = 0;
  }
}

void task1()
{
  if (modeStatus == NORMALMODE)
  {
    runNormalMode();
    ledWalkOperationNormalMode();
  }
}
void task2()
{
  if (modeStatus == TUNINGMODE)
  {
    animationTuningMode();
  }
}
void task3()
{
	switch (getInputButton())
	{
		case BUTTON1SinglePress:
			modeStatus= NORMALMODE;
			beginNormalMode();
			offSingleRedGreenWalk();
			break;
		case BUTTON1DoublePress:
			modeStatus= MANUALMODE;
			beginManualMode();
			break;
		case BUTTON1TriplePress:
			modeStatus= TUNINGMODE;
			beginTuningMode();
			break;
		case BUTTON1LongPress:
			switch (modeStatus)
			{
				case MANUALMODE:
					runManualModeFunction();
					break;
				case TUNINGMODE:
					runTuningMode();
					break;
				case INITMODES:
					offAllSingLEDs();
					break;
				default:
					break;
			}
			break;
		case BUTTON2SinglePress:
			switch (modeStatus)
			{
				case NORMALMODE:
					beginNormalMode();
					break;
				case MANUALMODE:
					runManualModeFunction();
					break;
				case TUNINGMODE:
					modifyTuningMode();
					break;
				default:
					break;
			}
			break;
		case BUTTON2DoublePress:
			switch (modeStatus)
			{
				case TUNINGMODE:
					saveTuningMode();
					break;
				case INITMODES:
					offAllSingLEDs();
					break;
				default:
					break;
			}
			break;
		case BUTTON2LongPress:
			switch (modeStatus)
			{
				case TUNINGMODE:
					modifyTuningMode();
					break;
				case INITMODES:
					offAllSingLEDs();
					break;
				default:
					break;
			}
			break;
		case BUTTON3SinglePress:
			switch (modeStatus)
			{
				case NORMALMODE:
					beginWalkNormalMode();
					ledWalkOperationNormalMode();
					break;
				case MANUALMODE:
					beginWalkManualMode();
					ledWalkOperationManualMode();
					break;
				default:
					break;

			}
			break;
		case BUTTON3DoublePress:
  modeStatus= INITMODES;
			offAllSingLEDs();
			offSingleRedGreenWalk();
			break;
		default:
			break;
	}
}
