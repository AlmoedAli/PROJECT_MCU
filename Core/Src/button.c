#include "button.h"
#include "main.h"
#include "deviceDriverSingleLed.h"
#include "manualMode.h"
#include "normalMode.h"
#include "tuningMode.h"
#include "ledWalk.h"

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

int modeStatus = INITMODES;

void resetAllButton()
{
    for (int i= 0; i < 3; i++)
    {
    	eventButtonPressed[i]= 0;
    	eventButtonDrop[i]= 0;
    	timerNormalState[i]= 0;
    }
}

void implementButton(int indexButton)
{
	switch (indexButton)
	{
		case 0:
			switch (eventButtonPressed[indexButton])
			{
			case 0:
				if (eventButtonDrop[indexButton]== 0)
				{
					// BUTTON1LONGPress
					switch (modeStatus)
					{
						case MANUALMODE:
							runManualModeFunction();
							break;
						case TUNINGMODE:
							runTuningMode();
							break;
						default:
							break;
					}
				}
				break;
			case 1:
				if (eventButtonDrop[indexButton]== 0)
				{
					// BUtton1LongPress
					switch (modeStatus)
					{
						case MANUALMODE:
							runManualModeFunction();
							break;
						case TUNINGMODE:
							runTuningMode();
							break;
						default:
							break;
					}
				}
				else
				{
					if (eventButtonDrop[indexButton]== 1)
					{
						// BUTTON1SinglePress
						modeStatus= NORMALMODE;
						beginNormalMode();
					}
				}
				break;
			case 2:
				if (eventButtonDrop[indexButton]== 1 || eventButtonDrop[indexButton]== 2)
				{
					// BUTTON1DoublePress
					modeStatus= MANUALMODE;
					beginManualMode();
				}
				break;
			case 3:
				if (eventButtonDrop[indexButton]== 2 || eventButtonDrop[indexButton]== 3)
				{
					// BUTTON1TriplePress
					modeStatus= TUNINGMODE;
					beginTuningMode();
				}
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (eventButtonPressed[indexButton])
			{
			case 0:
				if (eventButtonDrop[indexButton]== 0)
				{
					// BUTTON2LongPress
					if (modeStatus== TUNINGMODE)
						modifyTuningMode();
				}
				break;
			case 1:
				if (eventButtonDrop[indexButton]== 0)
				{
					// BUTTON2LongPress
					if (modeStatus== TUNINGMODE)
						modifyTuningMode();
				}
				else
				{
					if (eventButtonDrop[indexButton]== 1)
					{
						//BUTTON2SinglePress
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
					}
				}
				break;
			case 2:
				if (eventButtonDrop[indexButton]== 1 || eventButtonDrop[indexButton]== 2)
				{
					// BUTTON2DoublePress
					if (modeStatus== TUNINGMODE)
						saveTuningMode();
				}
				break;
			default:
				break;
			}
			break;
		case 2:
			switch (eventButtonPressed[indexButton])
			{
			case 1:
				if (eventButtonDrop[indexButton]== 1)
				{
					// BUTTON3SinglePress
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
				}
				break;
			case 2:
				if (eventButtonDrop[indexButton]== 1 || eventButtonDrop[indexButton]== 2)
				{
					//  BUTTON3DoublePress
					modeStatus= INITMODES;
					offAllSingLEDs();
					offSingleRedGreenWalk();
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
	}
	resetAllButton();
}

void getInputButton()
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
						timerNormalState[i]= 15;
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
							implementButton(i);
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
							if (i== 0)
								timerLongPress[i]= 300;
							if (i== 1)
								timerLongPress[i]= 20;
							implementButton(i);
						}
					}
				}
			}
		}
	}
}

