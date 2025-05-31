/*==============================================================================================
								 	 PROJECT YUME Ver.2.0
								  	 YUME UTILITIES LIBRARY
==============================================================================================*/

#include "yume_utilities.h"

void YUME_Initial_Setup(int YUME_MODE)
{
//	int LIMITER;


//	if(YUME_MODE>3)
//	{
//		YUME_Buzz(3);
//		LIMITER= YUME_MODE - 3;
//		delay_ms(500);
//		YUME_Buzz(LIMITER);
//	}
//	else
//	{
//		delay_ms(500);
//		YUME_Buzz(YUME_MODE);
//	}

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
	delay_ms(100);
//
//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"YUME Mode %d", YUME_MODE);lcd_putstr(lcd);delay_ms(200);
}
