/*==============================================================================================
								 	 PROJECT YUME Ver.1.0
							  YUME CONTACT BUMPER SENSOR LIBRARY
==============================================================================================*/

#include "yume_bumper.h"
void Bumper_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_BUMPER_LEFT, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2; //FRONT RIGHT
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(BUMPER_PORT_LEFT, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_BUMPER_RIGHT, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7; //FRONT RIGHT
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_Init(BUMPER_PORT_RIGHT, &GPIO_InitStructure);

}

void GetBumper(void)
{
	BUMPER[0]= GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2);
	BUMPER[1]= GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7);
}

void Display_Bumper_Stat(void)
{
	GetBumper();
	if( (BUMPER[LEFT]||BUMPER[RIGHT])==ACTIVE)
	{
		YUME_Buzz(1);
	}
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
	lcd_gotoxy(1,1);sprintf(lcd,"BUMPER MONITOR");lcd_putstr(lcd);
	lcd_gotoxy(4,2);sprintf(lcd,"BMP_L: %d",BUMPER[LEFT]);lcd_putstr(lcd);
	lcd_gotoxy(4,3);sprintf(lcd,"BMP_R: %d",BUMPER[RIGHT]);lcd_putstr(lcd);
	delay_ms(100);
}


void Sensor_Menu(void)
{
	int MENU_VAR=0;

//	while(BUTTON_IDLE)
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"YUME 2016");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"SENSOR MONITOR");lcd_putstr(lcd);
//		delay_ms(100);
//	}

	if(YUME_BUTTON_CLICKED)
	{
//		while(BUTTON_IDLE)
//		{
//			YUME_Buzz(1);
//			lcd_display_clear();
//			lcd_gotoxy(0,0);sprintf(lcd,"YUME 2016");lcd_putstr(lcd);
//			lcd_gotoxy(0,1);sprintf(lcd,"SENSOR MONITOR");lcd_putstr(lcd);
//			delay_ms(100);
//		}

		while(1)
		{
			if(BUTTON_A_CLICKED)
			{
				YUME_Buzz(2);
				while(BUTTON_A_CLICKED){};
				MENU_VAR++;
			}
			if(BUTTON_B_CLICKED)
			{
				YUME_Buzz(1);
				while(BUTTON_B_CLICKED){};
				MENU_VAR--;
			}

			if(MENU_VAR>5) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=5;

			switch(MENU_VAR)
			{
				case 0:
						{
							Display_Ping_Status ();
							Send_Ping_Status ();
						}break;

				case 1:
						{
							Get_IR();
							Display_IR_Stat();
						}break;
				case 2:
						{
							Display_Bumper_Stat();
						}break;
				case 3:
						{
							Display_FlameSense();
						}break;

				case 4:
						{
							RoomDetector();
						}break;
				case 5:
						{
							PushTo_Burst();
//							YUME_BLDC_Fight();
						}break;
//				case 6:
//						{
//							Display_Flame();
//						}break;

			}

		}

	}

}
