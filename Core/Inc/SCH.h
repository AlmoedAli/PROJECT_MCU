/*
 * SCH.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Acer
 */

#ifndef INC_SCH_H_
#define INC_SCH_H_

#include "main.h"

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40

// Ham giam dan thoi gian delay va set RunMe len de execute
void SCH_Update();

// Ham them task vao mang
void SCH_Add_Task(void(*pFunction), const uint32_t Delay,
		const uint32_t Period, uint8_t taskID);

void SCH_Delete(uint8_t index);

void SCH_Delete_ID(uint8_t ID);

// Xoa task dau tien
void SCH_Delete_Task(uint8_t index);

// Ham check xem task0 da can execute chua
void SCH_Dispatch_Tasks(void);

// Ham xoa tat ca cac task trong array, khien array nhu vua duoc khoi tao
void SCH_Init(void);

void task1();
void task2();
void task3();

#endif /* INC_SCH_H_ */
