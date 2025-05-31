/*==============================================================================================
								  	  PROJECT YUME Ver.2.0
								  	 YUME SOUND ACTIVATION LIBRARY
==============================================================================================*/

#include <yume_sound_activation.h>

void YUME_Sound_Activation_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = SOUND_ACT_PIN;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP; //Default input == 1
	GPIO_Init(SOUND_ACT_PORT, &GPIO_InitStructure);
}

void YUME_Sound_Activation(void)
{

	YUME_Sound_Activate = SOUND_SCAN;

	while ( (SOUND_SCAN!=0)&&(YUME_START!=1) )
	{
		YUME_Sound_Activate = SOUND_SCAN;
		YUME_START=YUME_BUTTON_INPUT;

		RotSwitch_Sampling();
		Display_MODE();

////		//VER 1
////		if(YUME_BUTTON_CLICKED)
////		{
////			if(YUME_BUTTON_UNCLICKED)
////			{
////				YUME_START=1;
////			}
////		}
//
////		VER 2
//		if(YUME_BUTTON_CLICKED)
//		{
//				YUME_START=1;
//		}


	}

	lcd_gotoxy(0,3);sprintf(lcd," YUME Activated!");lcd_putstr(lcd);
}
