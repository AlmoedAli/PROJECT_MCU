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
			switch (eventButtonPressed[indexButton])
			{
			case 0:
				switch (eventButtonDrop[indexButton])
				{
				case 0:
					resetAllButton();
					return BUTTON1LongPress;
					break;
				case 1:
					resetAllButton();
					return NOBUTTON;
					break;
				default:
					break;
				}
				break;
			case 1:
				switch (eventButtonDrop[indexButton])
				{
				case 0:
					resetAllButton();
					return BUTTON1LongPress;
					break;
				case 1:
					resetAllButton();
					return BUTTON1SinglePress;
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (eventButtonDrop[indexButton])
				{
				case 1:
					resetAllButton();
					return BUTTON1DoublePress;
					break;
				case 2:
					resetAllButton();
					return BUTTON1DoublePress;
					break;
				default:
					break;
				}
				break;
			case 3:
				switch (eventButtonDrop[indexButton])
				{
				case 2:
					resetAllButton();
					return BUTTON1TriplePress;
					break;
				case 3:
					resetAllButton();
					return BUTTON1TriplePress;
					break;
				default:
					break;
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
				switch (eventButtonDrop[indexButton])
				{
				case 0:
					resetAllButton();
					return BUTTON2LongPress;
					break;
				case 1:
					resetAllButton();
					return NOBUTTON;
					break;
				default:
					break;
				}
				break;
			case 1:
				switch (eventButtonDrop[indexButton])
				{
				case 0:
					resetAllButton();
					return BUTTON2LongPress;
					break;
				case 1:
					resetAllButton();
					return BUTTON2SinglePress;
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (eventButtonDrop[indexButton])
				{
				case 1:
					resetAllButton();
					return BUTTON2DoublePress;
					break;
				case 2:
					resetAllButton();
					return BUTTON2DoublePress;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
		case 2:
			switch (eventButtonPressed[indexButton])
			{
			case 0:
				switch (eventButtonDrop[indexButton])
				{
				case 0:
					resetAllButton();
					return BUTTON3LongPress;
					break;
				case 1:
					resetAllButton();
					return NOBUTTON;
					break;
				default:
					break;
				}
				break;
			case 1:
				switch (eventButtonDrop[indexButton])
				{
				case 0:
					resetAllButton();
					return BUTTON3LongPress;
					break;
				case 1:
					resetAllButton();
					return BUTTON3SinglePress;
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (eventButtonDrop[indexButton])
				{
				case 1:
					resetAllButton();
					return BUTTON3DoublePress;
					break;
				case 2:
					resetAllButton();
					return BUTTON3DoublePress;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
		default:
			resetAllButton();
			return NOBUTTON;
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
							if (i== 0)
								timerLongPress[i]= 300;
							if (i== 1)
								timerLongPress[i]= 20;
							return checkEventButton(i);		
						}
					}
				}
			}
		}
	}
	return NOBUTTON;
}

