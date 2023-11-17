///*
// * button.c
// *
// *  Created on: Oct 26, 2023
// *      Author: TVB09
// */
//
//
// #include "button.h"
// #include <main.h>
//
//
// GPIO_TypeDef* buttonPort[3]= {button1_GPIO_Port, button2_GPIO_Port, button3_GPIO_Port};
// uint16_t buttonPin[3]= {button1_Pin, button2_Pin, button3_Pin};
//
// int state0Button[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
// int state1Button[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
// int state2Button[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
// int state3Button[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
//
// int flagButton[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
//
// int flagPriorityButton[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
//
// int durationPressLongButton[3]= {100, 100, 100};
// int durationPressShortButton[3]= {20, 20, 20};
//
//
// void getInput()
//{
//	for (int i= 0; i < 3; i++)
//	{
//		state1Button[i]= state2Button[i];
//		state2Button[i]= state3Button[i];
//		state3Button[i]= HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
//		if ((state1Button[i]== state2Button[i]) && (state2Button[i]== state3Button[i]))
//		{
//			if (state0Button[i] != state1Button[i])
//			{
//				switch (state0Button[i])
//				{
//					case PRESS_STATE:
//						state0Button[i]= NORMAL_STATE;
//						flagPriorityButton[i]= NORMAL_STATE;
//						flagButton[i]= NORMAL_STATE;
//						if (durationPressShortButton[i] > 0)
//						{
//							flagButton[i]= PRESS_STATE;
//						}
//						break;
//					case NORMAL_STATE:
//						state0Button[i]= PRESS_STATE;
//						for (int j = 0; j < 3; j++)
//						{
//							if (j== i)
//								flagPriorityButton[j]= PRESS_STATE;
//							else
//								flagPriorityButton[j]= NORMAL_STATE;
//						}
//						durationPressLongButton[i]= 100;
//						durationPressShortButton[i]= 20;
//						break;
//					default:
//						break;
//				}
//			}
//			else
//			{
//				switch (state0Button[i])
//				{
//					case PRESS_STATE:
//						if (flagPriorityButton[i]== PRESS_STATE)
//						{
//							if (durationPressLongButton[i] > 0)
//							{
//								durationPressLongButton[i]--;
//								if (durationPressLongButton[i] <= 0)
//								{
//									durationPressLongButton[i]= 5;
//									flagButton[i]= PRESS_STATE;
//								}
//							}
//							if (durationPressShortButton[i] > 0)
//							{
//								durationPressShortButton[i]--;
//
//							}
//						}
//						break;
//					case NORMAL_STATE:
//						break;
//					default:
//						break;
//				}
//			}
//		}
//	}
//}

// #include "button.h"
// #include "main.h"

// GPIO_TypeDef *buttonPort[3] = {button1_GPIO_Port, button2_GPIO_Port, button3_GPIO_Port};
// uint16_t buttonPin[3] = {button1_Pin, button2_Pin, button3_Pin};

// int state0Button[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
// int state1Button[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
// int state2Button[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
// int state3Button[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

// int flagButton[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

// int durationPressLongButton[3] = {100, 100, 100};
// int durationPressShortButton[3] = {20, 20, 20};

// void getInput()
// {
// 	for (int i = 0; i < 3; i++)
// 	{
// 		state1Button[i] = state2Button[i];
// 		state2Button[i] = state3Button[i];
// 		state3Button[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
// 		if ((state1Button[i] == state2Button[i]) && (state2Button[i] == state3Button[i]))
// 		{
// 			if (state0Button[i] != state1Button[i]) // state0 != state1
// 			{
// 				switch (state0Button[i])
// 				{
// 				case PRESS_STATE: // button did press
// 					state0Button[i] = NORMAL_STATE;
// 					if (durationPressShortButton[i] > 0)
// 					{
// 						flagButton[i] = PRESS_STATE;
// 					}
// 					break;
// 				case NORMAL_STATE: // button is pressed;
// 					state0Button[i] = PRESS_STATE;
// 					durationPressLongButton[i] = 100;
// 					durationPressShortButton[i] = 20;
// 					break;
// 				default:
// 					break;
// 				}
// 			}
// 			else
// 			{
// 				switch (state0Button[i])
// 				{
// 				case NORMAL_STATE: // press didnot press
// 					break;
// 				case PRESS_STATE:
// 					if (durationPressLongButton[i] > 0)
// 					{
// 						durationPressLongButton[i]--;
// 						if (durationPressLongButton[i] <= 0)
// 						{
// 							flagButton[i] = PRESS_STATE;
// 							if (i == 1)
// 							{
// 								durationPressLongButton[i] = 10;
// 							}
// 						}
// 					}
// 					if (durationPressShortButton[i] > 0)
// 					{
// 						durationPressShortButton[i]--;
// 					}
// 					break;
// 				default:
// 					break;
// 				}
// 			}
// 		}
// 	}
// }


#include "button.h"
#include "main.h"


GPIO_TypeDef* buttonPort[3]= {button1_GPIO_Port, button2_GPIO_Port, button3_GPIO_Port};
uint16_t buttonPin[3]= {button1_Pin, button2_Pin, button3_Pin};

int state0Button[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int state1Button[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int state2Button[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int state3Button[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int timerLongPress[3]= {200, 200, 200};
int timerNormalState[3]= {0, 0, 0};
int eventButtonPressed[3]= {0, 0, 0};
int eventButtonDrop[3]= {0, 0, 0};

void resetAllButton()
{
	for (int i=0 ; i < 3; i++)
	{
		eventButtonDrop[i]= 0;
		eventButtonPressed[i]= 0;
		timerNormalState[i]= 0;
	}
}

int checkEventButton(int indexButton)
{
	switch (indexButton)
	{
		case 0:
			switch (eventButtonDrop[i])
			{
				case 0:
					resetAllButton();
					return BUTTON1LongPress;
					break;
				case 1:
					resetAllButton();
					return BUTTON1SinglePress;
					break;
				case 2:
					resetAllButton();
					return BUTTON1DoublePress;
					break;
				case 3:
					resetAllButton();
					return BUTTON1TriplePress;
					break;
				default:
					resetAllButton();
					break;
			}
		case 1:
			switch (eventButtonDrop[i])
			{
				case 0:
					resetAllButton();
					return BUTTON2LongPress;
					break;
				case 1:
					resetAllButton();
					return BUTTON2SinglePress;
					break;
				case 2:
					resetAllButton();
					return BUTTON2DoublePress;
					break;
				default:
					resetAllButton();
					break;
			}
			break;
		case 2:
			resetAllButton();
			break;
		default:
			resetAllButton();
			break;
	}
}
int getInputButton()
{
	for (int i= 0; i < 3; i++)
	{
		state1Button[i]= state2Button[i];
		state2Button[i]= state3Button[i];
		state3Button[i]= HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
		if ((state1Button[i]== state2Button[i]) && (state2Button[i]== state3Button[i]))
		{
			if (state0Button[i] != state1Button[i])  // state0 != state1
			{
				switch (state0Button[i])
				{
					case PRESS_STATE:   // button did press
						state0Button[i]= NORMAL_STATE;
						eventButtonDrop[i]+= 1;
						timerNormalState[i]= 20;
						break;
					case NORMAL_STATE:  // button is pressed;
						state0Button[i]= PRESS_STATE;
						eventButtonPressed[i]+= 1;
						timerLongPress[i]= 300;
						break;
					default:
						break;

				}
			}
			else
			{
				if (state0Button[i]== NORMAL_STATE)
				{
					if (timerNormalState[i] > 0)
					{
						timerNormalState[i]--;
						if (timerNormalState[i] <= 0)
						{
							return checkEventButton(i);
						}
					}
				}
				else   // state0Button[i]== PRESS_SATE;
				{
					if (timerLongPress[i] > 0)
					{
						timerLongPress[i]--;
						if (timerLongPress[i] <= 0)
						{
							if (i== 1)
								timerLongPress[i]= 20;
							return checkEventButton(i);		
						}
					}
				}
			}
		}
	}
}

