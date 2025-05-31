///*==============================================================================================
//								  	  PROJECT YUME Ver.1.0
//								  TCS3200 COLOUR SENSOR LIBRARY
//==============================================================================================*/
//
//#include "yume_tcs3200.h"
////#include "stm32f4xx.h"
////#include "stm32f4xx_gpio.h"
////#include "stm32f4xx_tim.h"
////#include "stm32f4xx_rcc.h"
////#include <stdio.h>
//
//
//
//uint32_t TCS3200_CCR1_Val = 80000;
//float white,red,blue,green;
//float F_white,F_red,F_blue,F_green;
//float M_white, M_red, M_blue, M_green;
//char tcs_stat[16];
//char TCS3200_MID, TCS3200_FRONT;
//
//void YUME_TCS3200_Interrupt_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);
//
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//
//	TIM_TimeBaseStructure.TIM_Prescaler = 8399; //f per count= 84.000.000/(8399+1)=10.000Hz = 0,1ms (0,0001 s)
//	//335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period = 30000; //0,1 ms x 30.000 = 3s
//	// 0,1 ms x 500 = 50 ms -> 0,5 s -> 2 Hz
//			//200; //0,1 X 200 = 20 ms -> 0,2 s -> 5 Hz
//	//10000; //0,1ms x 10000 = 1 s
//	//0.004*125000=500ms jadi sampling adc setiap 500ms //MAX 65535
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
//	TIM_Cmd(TIM12, ENABLE); //default di off dulu
//	TIM_ITConfig(TIM12, TIM_IT_Update, ENABLE);
//
//    NVIC_InitTypeDef NVIC_InitStructure;
//    NVIC_InitStructure.NVIC_IRQChannel = TIM8_BRK_TIM12_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}
//
//void TIM12_IRQHandler(void)
//{
//    if (TIM_GetITStatus(TIM12, TIM_IT_Update) != RESET)
//    {
//
//    	FRONT_Sum_Colour();
//
//    	TIM_ClearITPendingBit(TIM12, TIM_IT_Update);
//    }
//}
//
//
//void TCS3200_Pin_Config(void)
//{
//
//	//FRONT TCS3200 COLOUR SENSOR
//	//OUTPUT
////	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_TCS3200_FRONT_OUT, ENABLE);
////	GPIO_InitStructure.GPIO_Pin = F_S0_PIN| F_S1_PIN | F_S2_PIN | F_S3_PIN | F_OE_PIN;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;            // Pin ini memiliki Mode Ouput
////	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			 // Pin bersifat Push Pull (Pull-up, down or no Pull)
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 		 // kecepatan clock(2, 25, 50 or 100 MHz)
////	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; 		 // pin tidak diberikan pull up
////	GPIO_Init(TCS3200_FRONT_OUT_PORT, &GPIO_InitStructure); // inisialisasi periperal GPIO sesuai parameter typdef diatas
////
////	//INPUT
////	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_TCS3200_FRONT_IN, ENABLE);
////	GPIO_InitStructure.GPIO_Pin = F_OUT_PIN;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
////	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
////	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
////	GPIO_Init(TCS3200_FRONT_IN_PORT, &GPIO_InitStructure);
//
//	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOB, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_1;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;            // Pin ini memiliki Mode Ouput
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			 // Pin bersifat Push Pull (Pull-up, down or no Pull)
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 		 // kecepatan clock(2, 25, 50 or 100 MHz)
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; 		 // pin tidak diberikan pull up
//	GPIO_Init(GPIOB, &GPIO_InitStructure); // inisialisasi periperal GPIO sesuai parameter typdef diatas
//
//	//INPUT
//	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOC, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = F_OUT_PIN;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
//	GPIO_Init(GPIOC, &GPIO_InitStructure);
//
//
//	//MIDDLE TCS3200 COLOUR SENSOR
////	//OUTPUT
////	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_TCS3200_MIDDLE_OUT, ENABLE);
////	GPIO_InitStructure.GPIO_Pin = M_S0_PIN| M_S1_PIN | M_S2_PIN | M_S3_PIN | M_OE_PIN;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;            // Pin ini memiliki Mode Ouput
////	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			 // Pin bersifat Push Pull (Pull-up, down or no Pull)
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 		 // kecepatan clock(2, 25, 50 or 100 MHz)
////	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; 		 // pin tidak diberikan pull up
////	GPIO_Init(TCS3200_MIDDLE_OUT_PORT, &GPIO_InitStructure); 					 // inisialisasi periperal GPIO sesuai parameter typdef diatas
////
////	//INPUT
////	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_TCS3200_MIDDLE_IN, ENABLE);
////	GPIO_InitStructure.GPIO_Pin = M_OUT_PIN;
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
////	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
////	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
////	GPIO_Init(TCS3200_MIDDLE_IN_PORT, &GPIO_InitStructure);
//
//	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOE, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7| GPIO_Pin_6 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_4;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;            // Pin ini memiliki Mode Output
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 			 // Pin bersifat Push Pull (Pull-up, down or no Pull)
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 		 // kecepatan clock(2, 25, 50 or 100 MHz)
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; 		 // pin tidak diberikan pull up
//	GPIO_Init(GPIOE, &GPIO_InitStructure); 					 // inisialisasi periperal GPIO sesuai parameter typdef diatas
//
//	//INPUT
//	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOE, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //kecepatan clock(2, 25, 50 or 100 MHz)
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
//	GPIO_Init(GPIOE, &GPIO_InitStructure);
//
//
//	return;
//}
//
//void TIM2_Init(void)
//{
//		uint32_t TCS3200_CCR1_Val = 80000;
//		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
//		TIM_TimeBaseStructure.TIM_Prescaler = 83; //f per count= 84000000/(83+1)=1000000Hz
//		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//		TIM_TimeBaseStructure.TIM_Period = TCS3200_CCR1_Val;
//		TIM_TimeBaseStructure.TIM_ClockDivision = 0;
//		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//		TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
//}
//
//void TCS3200_FRONT_Mode(unsigned char mode)
//{
//
//    if(mode == 0){
//    //power OFF mode-  LED off and both channels "low"
//    GPIO_ResetBits(TCS3200_F_OE);  //digitalWrite(LED, LOW);
//    GPIO_ResetBits(TCS3200_F_S0);  //digitalWrite(S0, LOW); //S0
//    GPIO_ResetBits(TCS3200_F_S1);  //digitalWrite(S1, LOW); //S1
//    //  Serial.println("mOFFm");
//
//    }else if(mode == 1){
//    //this will put in 1:1, highest sensitivity
//    GPIO_SetBits(TCS3200_F_S0);   //digitalWrite(S0, HIGH); //S0
//    GPIO_SetBits(TCS3200_F_S1);  //digitalWrite(S1, HIGH); //S1
//    // Serial.println("m1:1m");
//
//    }else if(mode == 2){
//    //this will put in 1:5
//    GPIO_SetBits(TCS3200_F_S0);  //digitalWrite(S0, HIGH); //S0
//    GPIO_ResetBits(TCS3200_F_S1); //digitalWrite(S1, LOW); //S1
//    //Serial.println("m1:5m");
//
//    }else if(mode == 3){
//    //this will put in 1:50
//    GPIO_ResetBits(TCS3200_F_S0); //digitalWrite(S0, LOW); //S0
//    GPIO_SetBits(TCS3200_F_S1);  //digitalWrite(S1, HIGH); //S1
//    //Serial.println("m1:50m");
//    }
//
//    return;
//
//}
//
//
//float FRONT_Colour_Read(unsigned char color,  unsigned char LEDstate)
//{
//	// create a var where the pulse reading from sensor will go
//	float readPulse;
//	//turn on sensor and use highest frequency/sensitivity setting
//	TCS3200_FRONT_Mode(2);
//	//set the S2 and S3 pins to select the color to be sensed
//	if(color == 0)
//	{	//white
//		GPIO_ResetBits(TCS3200_F_S3); //digitalWrite(S3, LOW); //S3
//		GPIO_SetBits(TCS3200_F_S2);   //digitalWrite(S2, HIGH); //S2
//		// Serial.print(" w");
//	}
//
//	else if(color == 1)
//	{	//red
//		GPIO_ResetBits(TCS3200_F_S3);  //digitalWrite(S3, LOW); //S3
//		GPIO_ResetBits(TCS3200_F_S2);  //digitalWrite(S2, LOW); //S2
//		// Serial.print(" r");
//	}
//
//	else if(color == 2)
//	{	//blue
//		GPIO_SetBits(TCS3200_F_S3);    //digitalWrite(S3, HIGH); //S3
//		GPIO_ResetBits(TCS3200_F_S2);  //digitalWrite(S2, LOW); //S2
//		// Serial.print(" b");
//	}
//
//	else if(color == 3)
//	{	//green
//		GPIO_SetBits(TCS3200_F_S3);    //digitalWrite(S3, HIGH); //S3
//		GPIO_SetBits(TCS3200_F_S2);    //digitalWrite(S2, HIGH); //S2
//		// Serial.print(" g");
//	}
//
////  turn LEDs on or off, as directed by the LEDstate var = bikin error
////	if(LEDstate == 0){
////		GPIO_ResetBits(GPIOA, GPIO_Pin_7);  //digitalWrite(LED, LOW);
////		}
////	if(LEDstate == 1){
////		GPIO_SetBits(GPIOA, GPIO_Pin_7);  //digitalWrite(LED, HIGH);
////	}
//
////setting for a delay to let the sensor sit for a moment before taking a reading.
//// wait a bit for LEDs to actually turn on, as directed by sensorDelay var
//	//delay_ms(100);
//
//// now take a measurement from the sensor, timing a low pulse on the sensor's "out" pin
//// batas timeout 80000us = 80ms
//	//readPulse = pulseIn(taosOutPin, LOW, 80000); //start count saat sinyal high, berhenti ketika low
//	while(GPIO_ReadInputDataBit(TCS3200_F_OUT)==0){} RESET_TIM2; TIM2_ON;
//	while(GPIO_ReadInputDataBit(TCS3200_F_OUT)==1){} TIM2_OFF;
//
//	readPulse = TIM2->CNT;
////if the pulseIn times out, it returns 0 and that throws off numbers. just cap it at 80k if it happens
//	if(readPulse < .1)
//	{
//		readPulse = 80000;
//	}
//
////turn off color sensor and LEDs to save power
////TCS3200Mode(0);
//
//// return the pulse value back to whatever called for it...
//return readPulse;
//
//}
//
//
//
//void FRONT_Detect_Colour(void)
//{
//	F_white = FRONT_Colour_Read(0,1);
//	F_red = FRONT_Colour_Read(1,1);
//	F_blue = FRONT_Colour_Read(2,1);
//	F_green = FRONT_Colour_Read(3,1);
//}
//
//
//void FRONT_Sum_Colour(void)
//{
//	unsigned int counter=0;
//
//
//
//	while(counter<5)
//	{
//		FRONT_Detect_Colour();
//		counter++;
//		F_sum_red+=F_red;
//		F_sum_blue+=F_blue;
//		F_sum_white+=F_white;
//		F_sum_green+=F_green;
//
//		if(counter==5)
//		{
//			F_sum_red=F_sum_red/8;
//			F_sum_blue=F_sum_blue/8;
//			F_sum_white=F_sum_white/8;
//			F_sum_green= F_sum_green/8;
//			F_THRESHOLD = F_sum_red-F_sum_blue;
//			F_TOTAL_SUM= F_sum_red + F_sum_blue + F_sum_green;
//
////			Sendto_PC(USART1,"==================================== \r");
////			Sendto_PC(USART1,"F_sum_red: %d \r",(int)F_sum_red);
////			Sendto_PC(USART1,"F_sum_blue: %d \r",(int)F_sum_blue);
////			Sendto_PC(USART1,"F_sum_white: %d \r",(int)F_sum_white);
////			Sendto_PC(USART1,"F_sum_green: %d \r\r",(int)F_sum_green);
////			Sendto_PC(USART1,"F_TOTAL_SUM: %d \r\r",(int)F_TOTAL_SUM);
//
//			if(F_sum_green<=120) //WHITE DETECTED
//			{
//				F_DETECTED_COLOUR = COLOUR_WHITE;
//				TRACER_STAT=TRACER_DETECTED;
//				COLOUR_STAT=COLOUR_NOT_DETECTED;
//			}
//			else if(F_sum_green>120) //Grey Carpet or Black Floor
//			{
//				//BLACK FLOOR
//				if(F_TOTAL_SUM>520)
//				{
//					F_DETECTED_COLOUR= COLOUR_BLACK;
//					TRACER_STAT=TRACER_NOT_DETECTED;
//					COLOUR_STAT=COLOUR_DETECTED;
//				}
//
//				//Grey Carpet
//				else if(F_TOTAL_SUM<=520)
//				{
//					F_DETECTED_COLOUR= COLOUR_GRAY;
//					TRACER_STAT=TRACER_NOT_DETECTED;
//					COLOUR_STAT=COLOUR_DETECTED;
//				}
//			}
//
//
//
//
////			if((F_sum_red < 1000)&&(F_sum_blue < 1000)&&(F_sum_white < 1000)&&(F_sum_green < 1000) )
////			{
////				if(F_sum_white<30) //WHITE DETECTED
////				{
////					if(F_sum_red<=92 && F_sum_blue<=92) //agar di karpet merah tidak detect putih
////					{
////						F_DETECTED_COLOUR = COLOUR_WHITE;TRACER_STAT=TRACER_DETECTED; COLOUR_STAT=COLOUR_NOT_DETECTED;
////						ZONE=ZONE;
////
//////						Sendto_PC(USART1,"DETECT WHITE \r");
//////						lcd_display_clear();
//////						lcd_gotoxy(0,0); sprintf(lcd,"F: WHITE"); lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////					}
////				}
////
////				else if(F_sum_white>=30)
////				{
////					if( (F_sum_red>=130) && (F_sum_blue>=130) )//BLACK DETECTED
////					{
////						F_DETECTED_COLOUR= COLOUR_BLACK; TRACER_STAT=TRACER_NOT_DETECTED;COLOUR_STAT=COLOUR_DETECTED;
////						ZONE=ZONE;
//////						Sendto_PC(USART1,"DETECT BLACK \r");
//////						lcd_display_clear();
//////						lcd_gotoxy(0,0); sprintf(lcd,"F: BLACK"); lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////					}
////
////					else if( (F_sum_red<F_sum_blue) )//RED DETECTED
////					{
////						F_DETECTED_COLOUR= COLOUR_RED; TRACER_STAT=TRACER_NOT_DETECTED;COLOUR_STAT=COLOUR_DETECTED;
////						ZONE = ZONE_RED;
//////						Sendto_PC(USART1,"DETECT RED \r");
//////						lcd_display_clear();
//////						lcd_gotoxy(0,0); sprintf(lcd,"F: RED"); lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////					}
////
////					else if( (F_sum_blue<F_sum_red) )//BLUE DETECTED
////					{
////						F_DETECTED_COLOUR= COLOUR_BLUE; TRACER_STAT=TRACER_NOT_DETECTED;COLOUR_STAT=COLOUR_DETECTED;
////						ZONE = ZONE_BLUE;
//////						Sendto_PC(USART1,"DETECT BLUE  \r");
//////						lcd_display_clear();
//////						lcd_gotoxy(0,0); sprintf(lcd,"F: BLUE"); lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////
////					}
////				}
////
////				else
////				{
//////					lcd_display_clear();
//////					lcd_gotoxy(0,0); sprintf(lcd,"F: FAILURE"); lcd_putstr(lcd);delay_ms(50);
//////					lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////					lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////					counter=0;F_sum_red=0;F_sum_blue=0;F_sum_white=0;
////				}
////			}
//		}
//
//
//	}
////	counter=0;F_sum_red=0;F_sum_blue=0;F_sum_white=0;F_sum_green=0;
//}
//
//
//
//
//
//
//void TIM13_Init(void)
//{
//		uint32_t TCS3200_CCR1_Val = 80000;
//		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13,ENABLE);
//		TIM_TimeBaseStructure.TIM_Prescaler = 83; //f per count= 84000000/(83+1)=1000000Hz
//		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//		TIM_TimeBaseStructure.TIM_Period = TCS3200_CCR1_Val;
//		TIM_TimeBaseStructure.TIM_ClockDivision = 0;
//		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//		TIM_TimeBaseInit(TIM13, &TIM_TimeBaseStructure);
//}
//
//void TCS3200_MID_Mode(unsigned char mode)
//{
//    if(mode == 0){
//    //power OFF mode-  LED off and both channels "low"
//    GPIO_ResetBits(TCS3200_M_OE);  //digitalWrite(LED, LOW);
//    GPIO_ResetBits(TCS3200_M_S0);  //digitalWrite(S0, LOW); //S0
//    GPIO_ResetBits(TCS3200_M_S1);  //digitalWrite(S1, LOW); //S1
//    //  Serial.println("mOFFm");
//    }
//
//    else if(mode == 1){
//    //this will put in 1:1, highest sensitivity
//    GPIO_SetBits(TCS3200_M_S0);   //digitalWrite(S0, HIGH); //S0
//    GPIO_SetBits(TCS3200_M_S1);  //digitalWrite(S1, HIGH); //S1
//    // Serial.println("m1:1m");
//    }
//
//    else if(mode == 2){
//    //this will put in 1:5
//    GPIO_SetBits(TCS3200_M_S0);  //digitalWrite(S0, HIGH); //S0
//    GPIO_ResetBits(TCS3200_M_S1); //digitalWrite(S1, LOW); //S1
//    //Serial.println("m1:5m");
//    }
//
//    else if(mode == 3){
//    //this will put in 1:50
//    GPIO_ResetBits(TCS3200_M_S0); //digitalWrite(S0, LOW); //S0
//    GPIO_SetBits(TCS3200_M_S1);  //digitalWrite(S1, HIGH); //S1
//    //Serial.println("m1:50m");
//    }
//
//    return ;
//
//}
//
//float MID_Colour_Read(unsigned char color,  unsigned char LEDstate)
//{
//	float readPulse;
//
//	//turn on sensor and use highest frequency/sensitivity setting
//	TCS3200_MID_Mode(2);
//
//	//set the S2 and S3 pins to select the color to be sensed
//	if(color == 0) //white
//	{
//		GPIO_ResetBits(TCS3200_M_S3); //digitalWrite(S3, LOW); //S3
//		GPIO_SetBits(TCS3200_M_S2);   //digitalWrite(S2, HIGH); //S2
//	}
//
//	else if(color == 1) //red
//	{
//		GPIO_ResetBits(TCS3200_M_S3);  //digitalWrite(S3, LOW); //S3
//		GPIO_ResetBits(TCS3200_M_S2);  //digitalWrite(S2, LOW); //S2
//	}
//
//	else if(color == 2) //blue
//	{
//		GPIO_SetBits(TCS3200_M_S3);    //digitalWrite(S3, HIGH); //S3
//		GPIO_ResetBits(TCS3200_M_S2);  //digitalWrite(S2, LOW); //S2
//	}
//
//	else if(color == 3) //green
//	{
//		GPIO_SetBits(TCS3200_M_S3);    //digitalWrite(S3, HIGH); //S3
//		GPIO_SetBits(TCS3200_M_S2);    //digitalWrite(S2, HIGH); //S2
//	}
//
//	while(GPIO_ReadInputDataBit(TCS3200_M_OUT)==0){} RESET_TIM13; TIM13_ON;
//	while(GPIO_ReadInputDataBit(TCS3200_M_OUT)==1){} TIM13_OFF;
//
//	readPulse = TIM13->CNT;
//
//	//if the pulseIn times out, it returns 0 and that throws off numbers. just cap it at 80k if it happens
//
//	if(readPulse < .1)
//	{
//		readPulse = 80000;
//	}
//
//	//turn off color sensor and LEDs to save power
//	//TCS3200Mode(0);
//
//	// return the pulse value back to whatever called for it...
//	return readPulse;
//}
//
//void MID_Detect_Colour(void)
//{
//	M_white = MID_Colour_Read(0,1);
//	M_red   = MID_Colour_Read(1,1);
//	M_blue  = MID_Colour_Read(2,1);
//	M_green = MID_Colour_Read(3,1);
//}
//
//void MID_Sum_Colour(void)
//{
//	unsigned int counter=0;
//
//	while(counter<5)
//	{
//		MID_Detect_Colour();
//		//delay_ms(1000); //kecepatan pengambilan data, gak perlu supaya cepet
//		counter++;
//		M_sum_red+=M_red;
//		M_sum_blue+=M_blue;
//		M_sum_white+=M_white;
//		M_sum_green+=M_green;
//
//		if(counter==5)
//		{
//			M_sum_red=M_sum_red/8;
//			M_sum_blue=M_sum_blue/8;
//			M_sum_white=M_sum_white/8;
//			M_sum_green=M_sum_green/8;
//			M_THRESHOLD = M_sum_red-M_sum_blue;
//			M_TOTAL_SUM= M_sum_red + M_sum_blue + M_sum_green;
//
////			Sendto_PC(USART1,"==================================== \r");
////			Sendto_PC(USART1,"M_sum_red: %d \r",(int)M_sum_red);
////			Sendto_PC(USART1,"M_sum_blue: %d \r",(int)M_sum_blue);
////			Sendto_PC(USART1,"M_sum_white: %d \r",(int)M_sum_white);
////			Sendto_PC(USART1,"M_sum_green: %d \r\r",(int)M_sum_green);
////			Sendto_PC(USART1,"M_TOTAL_SUM: %d \r\r",(int)M_TOTAL_SUM);
//
//
//			if(M_sum_green<=80) //WHITE DETECTED
//			{
//				M_DETECTED_COLOUR = COLOUR_WHITE;
//				TRACER_STAT=TRACER_DETECTED;
//				COLOUR_STAT=COLOUR_NOT_DETECTED;
//			}
//			else if(M_sum_green>80) //Grey Carpet or Black Floor
//			{
//				//BLACK FLOOR
//				if(M_TOTAL_SUM>400)
//				{
//					M_DETECTED_COLOUR= COLOUR_BLACK;
//					TRACER_STAT=TRACER_NOT_DETECTED;
//					COLOUR_STAT=COLOUR_DETECTED;
//				}
//
//				//Grey Carpet
//				else if(M_TOTAL_SUM<=400)
//				{
//					M_DETECTED_COLOUR= COLOUR_GRAY;
//					TRACER_STAT=TRACER_NOT_DETECTED;
//					COLOUR_STAT=COLOUR_DETECTED;
//				}
//			}
//
////			if((M_sum_red < 1000)&&(M_sum_blue < 1000)&&(M_sum_white < 1000))
////			{
////				if(M_sum_white<24) //WHITE DETECTED
////				{
////					if(M_sum_red<=75 && M_sum_blue<=75) //agar di karpet merah tidak detect putih
////					{
////						M_DETECTED_COLOUR = COLOUR_WHITE;TRACER_STAT=TRACER_DETECTED;COLOUR_STAT=COLOUR_NOT_DETECTED;
//////						Sendto_PC(USART1,"DETECT WHITE \r");
//////						lcd_display_clear();
//////						lcd_gotoxy(0,0); sprintf(lcd,"F: WHITE"); lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////					}
////				}
////
////
////				else if(M_sum_white>=24)
////				{
////					if( (M_sum_red>=110) && (M_sum_blue>=110) )//BLACK DETECTED
////					{
////						M_DETECTED_COLOUR= COLOUR_BLACK; TRACER_STAT=TRACER_NOT_DETECTED;COLOUR_STAT=COLOUR_DETECTED;
//////						Sendto_PC(USART1,"DETECT BLACK \r");
//////						lcd_display_clear();
//////						lcd_gotoxy(0,0); sprintf(lcd,"F: BLACK"); lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////					}
////
////					else if( (M_sum_red<M_sum_blue) )//RED DETECTED
////					{
////						M_DETECTED_COLOUR= COLOUR_RED;
////						TRACER_STAT=TRACER_NOT_DETECTED;
////						COLOUR_STAT=COLOUR_DETECTED;
////						ZONE = ZONE_RED;
//////						Sendto_PC(USART1,"DETECT RED \r");
//////						lcd_display_clear();
//////						lcd_gotoxy(0,0); sprintf(lcd,"F: RED"); lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////					}
////
////					else if( (M_sum_blue<M_sum_red) )//BLUE DETECTED
////					{
////						M_DETECTED_COLOUR= COLOUR_BLUE; TRACER_STAT=TRACER_NOT_DETECTED;COLOUR_STAT=COLOUR_DETECTED;
////						ZONE = ZONE_BLUE;
//////						Sendto_PC(USART1,"DETECT BLUE  \r");
//////						lcd_display_clear();
//////						lcd_gotoxy(0,0); sprintf(lcd,"F: BLUE"); lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////						lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////
////					}
////				}
////
////				else
////				{
//////					lcd_display_clear();
//////					lcd_gotoxy(0,0); sprintf(lcd,"F: FAILURE"); lcd_putstr(lcd);delay_ms(50);
//////					lcd_gotoxy(0,1);sprintf(lcd,"R:%d B:%d",(int)F_sum_red,(int)F_sum_blue);lcd_putstr(lcd);delay_ms(50);
//////					lcd_gotoxy(0,2);sprintf(lcd,"W:%d T:%d",(int)F_sum_white, TRACER_STAT);lcd_putstr(lcd);delay_ms(50);
////					counter=0;M_sum_red=0;M_sum_blue=0;M_sum_white=0;
////				}
////			}
//		}
//	}
////	counter=0;M_sum_red=0;M_sum_blue=0;M_sum_white=0;M_sum_green=0;
//}
//
//
////void MID_Sum_Colour(void)
////{
////	unsigned char r=0;
////	static float sum_red=0,sum_blue=0,sum_white=0;
////	int M_sred,M_sblue,M_swhite;
////
////	extern char TCS3200_MID;
////	{
////
////		while(r<5)
////		{
////			MID_Detect_Colour();
////			//delay_ms(1000); //kecepatan pengambilan data, gak perlu supaya cepet
////			r++;
////			sum_red+=red;
////			sum_blue+=blue;
////			sum_white+=white;
////			//sprintf(tcs_stat," White= %.2f\t Red= %.2f\t Blue= %.2f\t Green= %.2f\t \r",white,red,blue,green);
////			//usart_puts(kata);
////
////			if(r==5)
////			{
////				sum_red=sum_red/8;
////				sum_blue=sum_blue/8;
////				sum_white=sum_white/8;
////
////				if((sum_red < 1000)&&(sum_blue < 1000))
////					{
////					M_sred=sum_red;
////					M_sblue=sum_blue;
////					M_swhite=sum_white;
////					if ((M_sred<=35)&&(M_sblue<=45)&&(M_swhite<=23)) {TCS3200_MID='A';}
////					if ((M_sred>=65)&&(M_sred<=100)&&(M_sblue>=60)&&(M_sblue<=90)&&(M_swhite>=19)&&(M_swhite<=32)) {TCS3200_MID='B';}
////					if((M_sred>=26)&&(M_sred<=65)&&(M_sblue>=49)&&(M_sblue<=82)&&(M_swhite>=12)&&(M_swhite<=26)) {TCS3200_MID='C';}
////					if((M_sred>=63)&&(M_sred<=94)&&(M_sblue>=29)&&(M_sblue<=59)&&(M_swhite>=12)&&(M_swhite<=27)) {TCS3200_MID='D';}
////
////					lcd_display_clear();
////					lcd_gotoxy(0,0);sprintf(lcd,"M_sred: %d",M_sred);lcd_putstr(lcd);
////					lcd_gotoxy(0,1);sprintf(lcd,"M_sred: %d",M_sred);lcd_putstr(lcd);
////					lcd_gotoxy(0,2);sprintf(lcd,"M_sblue: %d",M_sblue);lcd_putstr(lcd);
////					lcd_gotoxy(0,3);sprintf(lcd,"M_swhite: %d",M_swhite);lcd_putstr(lcd);
////					}
////				else
////				{
////					sprintf(tcs_stat,"Kemungkinan Data Salah\nSum_Red= %.2f\t Sum_Blue= %.2f\r",sum_red,sum_blue);
////					r=0;sum_red=0;sum_blue=0;
////				}
////			}
////		}
////	}
////}
//
//
//void yume_display_colour(void)
//{
//	FRONT_Sum_Colour();
//	MID_Sum_Colour();
//	//lcd_gotoxy(0,3);
//	//lcd_putstr(tcs_stat);
//
//}
//
//void TCS3200_Init(void)
//{
//	TCS3200_Pin_Config();
//
//	//FRONT TCS3200
//	TIM2_Init();
//
//	//MIDDLE TCS3200
//	TIM13_Init();
//}
//
//void Send_TCS3200_Status(void)
//{
//	FRONT_Sum_Colour();
//
//	Sendto_PC(USART1,"\r=======================================\r");
//	Sendto_PC(USART1,"FRONT TCS3200 TRACER \r");
//	switch(F_DETECTED_COLOUR)
//	{
//		case 1: {Sendto_PC(USART1,"DETECT BLACK \r");YUME_Buzz(1);break;}
//		case 2: {Sendto_PC(USART1,"DETECT WHITE \r");YUME_Buzz(2);break;}
//		case 3: {Sendto_PC(USART1,"DETECT RED \r");YUME_Buzz(3);break;}
//		case 4: {Sendto_PC(USART1,"DETECT BLUE \r");YUME_Buzz(2);YUME_Buzz(2);break;}
//		case 5: {Sendto_PC(USART1,"DETECT GRAY \r");YUME_Buzz(4);break;}
//	}
//	Sendto_PC(USART1,"RED:%d BLUE:%d \r",(int)F_sum_red,(int)F_sum_blue);
//	Sendto_PC(USART1,"WHITE: %d GREEN: %d TRACER: %d \r",(int)F_sum_white, (int)F_sum_green, TRACER_STAT);
//	Sendto_PC(USART1,"FRONT TCS3200 MODE: %d \r",COLOUR_STAT);
//	Sendto_PC(USART1,"FRONT TCS3200 ZONE: %d \r\r",ZONE);
//	Sendto_PC(USART1,"F_TOTAL_SUM: %d \r\r",(int)F_TOTAL_SUM);
//
////	delay_ms(500);
//	MID_Sum_Colour();
//
//	Sendto_PC(USART1,"MIDDLE TCS3200 TRACER \r");
//	switch(M_DETECTED_COLOUR)
//	{
//		case 1: {Sendto_PC(USART1,"DETECT BLACK \r");YUME_Buzz(1);break;}
//		case 2: {Sendto_PC(USART1,"DETECT WHITE \r");YUME_Buzz(2);break;}
//		case 3: {Sendto_PC(USART1,"DETECT RED \r");YUME_Buzz(3);break;}
//		case 4: {Sendto_PC(USART1,"DETECT BLUE \r");YUME_Buzz(2);YUME_Buzz(2);break;}
//		case 5: {Sendto_PC(USART1,"DETECT GRAY \r");YUME_Buzz(4);break;}
//	}
//	Sendto_PC(USART1,"RED:%d BLUE:%d \r",(int)M_sum_red,(int)M_sum_blue);
//	Sendto_PC(USART1,"WHITE: %d GREEN: %d TRACER: %d \r",(int)M_sum_white, (int)M_sum_green, TRACER_STAT);
//	Sendto_PC(USART1,"MIDDLE TCS3200 MODE: %d \r",COLOUR_STAT);
//	Sendto_PC(USART1,"MIDDLE TCS3200 ZONE: %d \r\r",ZONE);
//	Sendto_PC(USART1,"M_TOTAL_SUM: %d \r\r",(int)M_TOTAL_SUM);
//	Sendto_PC(USART1,"\r=======================================\r");
//
//}
//
//void PushtoSend_TCS3200_Status(void)
//{
//	mov_static();
//	delay_ms(100);
//	YUME_START=YUME_BUTTON_INPUT;
//	if(YUME_START==1)
//	{
//		Send_TCS3200_Status();
////		FRONT_Sum_Colour();
////		MID_Sum_Colour();
//	}
//}
//
//void TCS3200_AutoCalibration(void)
//{
//	//FRONT TCS3200
//	int F_BlackFloor_White,F_WhiteCircle_White,F_White_Threshold=0;
//	int F_BlackFloor_Red,F_BlackFloor_Blue;
//	int F_BlueCarpet_Red,F_BlueCarpet_Blue;
//	int F_RedCarpet_Red,F_RedCarpet_Blue;
//	int F_white_diff;
//	int F_WhiteCircle_RB_Threshold;
//	int F_BlackFloor_RB_Threshold;
//
//	//MIDDLE TCS3200
//	int M_BlackFloor_White,M_WhiteCircle_White,M_White_Threshold=0;
//	int M_BlackFloor_Red,M_BlackFloor_Blue;
//	int M_BlueCarpet_Red,M_BlueCarpet_Blue;
//	int M_RedCarpet_Red,M_RedCarpet_Blue;
//	int M_white_diff;
//	int M_WhiteCircle_RB_Threshold;
//	int M_BlackFloor_RB_Threshold;
//
//
//	YUME_START=0;
//	mov_static();
//	delay_ms(100);
//	Sendto_PC(USART1,"CALIBRATE ON BLACK FLOOR\r");
//	while(YUME_START==0)
//	{
//		YUME_START=YUME_BUTTON_INPUT;
//	}
//
//	FRONT_Sum_Colour();
//	F_BlackFloor_White=F_sum_white;
//	F_BlackFloor_Red= F_sum_red;
//	F_BlackFloor_Blue=F_sum_blue;
//
//	MID_Sum_Colour();
//	M_BlackFloor_White=M_sum_white;
//	M_BlackFloor_Red= M_sum_red;
//	M_BlackFloor_Blue=M_sum_blue;
//
//	Sendto_PC(USART1,"BLACK FLOOR DATA ACQUIRED!\r");
//	Sendto_PC(USART1,"F_BlackFloor_White: %d \r",F_BlackFloor_White);
//	Sendto_PC(USART1,"M_BlackFloor_White: %d \r",M_BlackFloor_White);
//	delay_ms(200);
//
//	Sendto_PC(USART1,"CALIBRATE ON WHITE CANDLE CIRCLE\r");
//	YUME_START=0;
//	while(YUME_START==0)
//	{
//		YUME_START=YUME_BUTTON_INPUT;
//	}
//	FRONT_Sum_Colour();
//	F_WhiteCircle_White=F_sum_white;
//	MID_Sum_Colour();
//	M_WhiteCircle_White=M_sum_white;
//
//	Sendto_PC(USART1,"CANDLE CIRCLE DATA ACQUIRED!r");
//	Sendto_PC(USART1,"F_WhiteCircle_White: %d \r",F_WhiteCircle_White);
//	Sendto_PC(USART1,"M_WhiteCircle_White: %d \r",M_WhiteCircle_White);
//	delay_ms(200);
//
//	F_white_diff= F_BlackFloor_White - F_WhiteCircle_White;
//	if(F_white_diff>15)
//	{
//		Sendto_PC(USART1,"F_white_diff > 20 \r");
//		F_White_Threshold= F_WhiteCircle_White+10;
//	}
//	else if ( (F_white_diff<15)&&(F_white_diff>5) )
//	{
//		Sendto_PC(USART1,"F_white_diff <=20 \r");
//		F_White_Threshold=F_WhiteCircle_White+5;
//		while ( F_White_Threshold < (F_BlackFloor_White-10))
//		{
//			F_White_Threshold++;
//		}
//	}
//	else Sendto_PC(USART1,"FRONT TCS3200 CALIBRATION ERROR \r");
//
//	M_white_diff= M_BlackFloor_White - M_WhiteCircle_White;
//	if(M_white_diff>15)
//	{
//		Sendto_PC(USART1,"M_white_diff > 20 \r");
//		M_White_Threshold= M_WhiteCircle_White+10;
//	}
//	else if ( (M_white_diff<15)&&(M_white_diff>5) )
//	{
//		Sendto_PC(USART1,"M_white_diff <=20 \r");
//		M_White_Threshold=M_WhiteCircle_White+5;
//		while ( M_White_Threshold < (M_BlackFloor_White-10))
//		{
//			M_White_Threshold++;
//		}
//	}
//
//	else Sendto_PC(USART1,"MIDDLE TCS3200 CALIBRATION ERROR \r");
//
//	Sendto_PC(USART1,"F_White_Threshold Acquired! Value: %d \r",F_White_Threshold);
//	Sendto_PC(USART1,"M_White_Threshold Acquired! Value: %d \r",M_White_Threshold);
//
//
//
//	Sendto_PC(USART1,"CALIBRATE ON RED CARPET\r");
//	YUME_START=0;
//	while(YUME_START==0)
//	{
//		YUME_START=YUME_BUTTON_INPUT;
//	}
//	FRONT_Sum_Colour();
//	F_RedCarpet_Red= F_sum_red;
//	F_RedCarpet_Blue= F_sum_blue;
//	MID_Sum_Colour();
//	M_RedCarpet_Red= M_sum_red;
//	M_RedCarpet_Blue= M_sum_blue;
//
//	Sendto_PC(USART1,"RED CARPET DATA ACQUIRED!\r");
//	Sendto_PC(USART1,"F_RedCarpet_Red: %d \r",F_RedCarpet_Red);
//	Sendto_PC(USART1,"F_RedCarpet_Blue: %d \r",F_RedCarpet_Blue);
//	Sendto_PC(USART1,"M_RedCarpet_Red: %d \r",M_RedCarpet_Red);
//	Sendto_PC(USART1,"M_RedCarpet_Blue: %d \r",M_RedCarpet_Blue);
//	delay_ms(200);
//
//	Sendto_PC(USART1,"CALIBRATE ON BLUE CARPET\r");
//	YUME_START=0;
//	while(YUME_START==0)
//	{
//		YUME_START=YUME_BUTTON_INPUT;
//	}
//	FRONT_Sum_Colour();
//	F_BlueCarpet_Red= F_sum_red;
//	F_BlueCarpet_Blue= F_sum_blue;
//	MID_Sum_Colour();
//	M_BlueCarpet_Red= M_sum_red;
//	M_BlueCarpet_Blue= M_sum_blue;
//
//	Sendto_PC(USART1,"BLUE CARPET DATA ACQUIRED!\r");
//	Sendto_PC(USART1,"F_BlueCarpet_Red: %d \r",F_BlueCarpet_Red);
//	Sendto_PC(USART1,"F_BlueCarpet_Blue: %d \r",F_BlueCarpet_Blue);
//	Sendto_PC(USART1,"M_BlueCarpet_Red: %d \r",M_BlueCarpet_Red);
//	Sendto_PC(USART1,"M_BlueCarpet_Blue: %d \r",M_BlueCarpet_Blue);
//	delay_ms(200);
//
//
//	//AUTO CALIBRATION WHITE CIRCLE RED/BLUE THRESHOLD
//	if(F_RedCarpet_Red < F_RedCarpet_Blue)
//	{
//		F_WhiteCircle_RB_Threshold= F_RedCarpet_Red - 20;
//	}
//	else F_WhiteCircle_RB_Threshold= F_RedCarpet_Blue - 20;
//
//	if(M_RedCarpet_Red < M_RedCarpet_Blue)
//	{
//		M_WhiteCircle_RB_Threshold= M_RedCarpet_Red - 20;
//	}
//	else M_WhiteCircle_RB_Threshold= M_RedCarpet_Blue - 20;
//
//
//
//	//AUTO CALIBRATION BLACK FLOOR RED/BLUE THRESHOLD
//
//	if(F_BlueCarpet_Blue < F_BlueCarpet_Red)
//	{
//		F_BlackFloor_RB_Threshold= F_BlueCarpet_Blue;
//		while( F_BlackFloor_RB_Threshold < (F_BlueCarpet_Blue-10))
//		{
//			F_BlackFloor_RB_Threshold++;
//		}
//	}
//
//	if(M_BlueCarpet_Blue < M_BlueCarpet_Red)
//	{
//		M_BlackFloor_RB_Threshold= M_BlueCarpet_Blue;
//		while( M_BlackFloor_RB_Threshold < (M_BlueCarpet_Blue-10))
//		{
//			M_BlackFloor_RB_Threshold++;
//		}
//	}
//
//
//	Sendto_PC(USART1,"RED/BLUE THRESHOLD ACQUIRED!\r");
//	Sendto_PC(USART1,"F_WhiteCircle_RB_Threshold: %d \r",F_WhiteCircle_RB_Threshold);
//	Sendto_PC(USART1,"F_BlackFloor_RB_Threshold: %d \r",F_BlackFloor_RB_Threshold);
//
//
//	Sendto_PC(USART1,"\r====================FRONT TCS3200====================\r");
//	Sendto_PC(USART1,"F_White_Threshold: %d \r",F_White_Threshold);
//	Sendto_PC(USART1,"F_WhiteCircle_RB_Threshold: %d \r",F_WhiteCircle_RB_Threshold);
//	Sendto_PC(USART1,"F_BlackFloor_RB_Threshold: %d \r",F_BlackFloor_RB_Threshold);
//	Sendto_PC(USART1,"=======================================================\r");
//
//	Sendto_PC(USART1,"\r====================MIDDLE TCS3200====================\r");
//	Sendto_PC(USART1,"M_White_Threshold: %d \r",M_White_Threshold);
//	Sendto_PC(USART1,"M_WhiteCircle_RB_Threshold: %d \r",M_WhiteCircle_RB_Threshold);
//	Sendto_PC(USART1,"M_BlackFloor_RB_Threshold: %d \r",M_BlackFloor_RB_Threshold);
//	Sendto_PC(USART1,"=======================================================\r");
//
//
//
//	while(1)
//	{
//		mov_static();
//		delay_ms(100);
//	}
//}
//
//void TCS3200_AutoCal(void)
//{
//	//FRONT TCS3200
//	int WHITE=0,RED=1,BLUE=2;
//	int FRONT=0,MIDDLE=1;
//	int BlackFloor[2][3];
//	int WhiteCandleCircle[2][3];
//	int BlueCarpet[2][3];
//	int RedCarpet[2][3];
//
//	int RB_Carpet[2],RB_Reff[2],RB_Diff[2];
//	int White_Diff[2], White_Threshold[2];
//	int CandleCircle_RB_Threshold[2];
//	int BlackFloor_RB_Threshold[2];
//
////===========================================================================================//
//	YUME_START=0;
//	mov_static();
//	delay_ms(100);
//	Sendto_PC(USART1,"CALIBRATE ON BLACK FLOOR!\r");
//
//	YUME_Buzz(4);
//
//	while(YUME_START==0)
//	{
//		YUME_START=YUME_BUTTON_INPUT;
//	}
//	YUME_Buzz(1);
//	FRONT_Sum_Colour();
//	BlackFloor[FRONT][WHITE]= F_sum_white;
//	BlackFloor[FRONT][RED]= F_sum_red;
//	BlackFloor[FRONT][BLUE]= F_sum_blue;
//
//	MID_Sum_Colour();
//	BlackFloor[MIDDLE][WHITE]= M_sum_white;
//	BlackFloor[MIDDLE][RED]= M_sum_red;
//	BlackFloor[MIDDLE][BLUE]= M_sum_blue;
//
//
//	Sendto_PC(USART1,"\r BLACK FLOOR DATA ACQUIRED! \r");
//	Sendto_PC(USART1,"FRONT TCS3200\r");
//	Sendto_PC(USART1,"BlackFloor[FRONT][WHITE]: %d \r",BlackFloor[FRONT][WHITE]);
//	Sendto_PC(USART1,"BlackFloor[FRONT][RED]: %d \r",BlackFloor[FRONT][RED]);
//	Sendto_PC(USART1,"BlackFloor[FRONT][BLUE]: %d \r",BlackFloor[FRONT][BLUE]);
//	Sendto_PC(USART1,"MIDDLE TCS3200\r");
//	Sendto_PC(USART1,"BlackFloor[MIDDLE][WHITE]: %d \r",BlackFloor[MIDDLE][WHITE]);
//	Sendto_PC(USART1,"BlackFloor[MIDDLE][RED]: %d \r",BlackFloor[MIDDLE][RED]);
//	Sendto_PC(USART1,"BlackFloor[MIDDLE][BLUE]: %d \r",BlackFloor[MIDDLE][BLUE]);
//
//
//
////===========================================================================================//
//
//	YUME_START=0;
//	mov_static();
//	delay_ms(100);
//	Sendto_PC(USART1,"CALIBRATE ON WHITE CIRCLE!\r");
//
//	YUME_Buzz(4);
//	while(YUME_START==0)
//	{
//		YUME_START=YUME_BUTTON_INPUT;
//	}
//	YUME_Buzz(2);
//
//	FRONT_Sum_Colour();
//	WhiteCandleCircle[FRONT][WHITE]= F_sum_white;
//	WhiteCandleCircle[FRONT][RED]= F_sum_red;
//	WhiteCandleCircle[FRONT][BLUE]= F_sum_blue;
//
//	MID_Sum_Colour();
//	WhiteCandleCircle[MIDDLE][WHITE]= M_sum_white;
//	WhiteCandleCircle[MIDDLE][RED]= M_sum_red;
//	WhiteCandleCircle[MIDDLE][BLUE]= M_sum_blue;
//
//
//	Sendto_PC(USART1,"\r WHITE CANDLE CIRCLE DATA ACQUIRED! \r");
//	Sendto_PC(USART1,"FRONT TCS3200\r");
//	Sendto_PC(USART1,"WhiteCandleCircle[FRONT][WHITE]: %d \r",WhiteCandleCircle[FRONT][WHITE]);
//	Sendto_PC(USART1,"WhiteCandleCircle[FRONT][RED]: %d \r",WhiteCandleCircle[FRONT][RED]);
//	Sendto_PC(USART1,"WhiteCandleCircle[FRONT][BLUE]: %d \r",WhiteCandleCircle[FRONT][BLUE]);
//	Sendto_PC(USART1,"MIDDLE TCS3200\r");
//	Sendto_PC(USART1,"WhiteCandleCircle[MIDDLE][WHITE]: %d \r",WhiteCandleCircle[MIDDLE][WHITE]);
//	Sendto_PC(USART1,"WhiteCandleCircle[MIDDLE][RED]: %d \r",WhiteCandleCircle[MIDDLE][RED]);
//	Sendto_PC(USART1,"WhiteCandleCircle[MIDDLE][BLUE]: %d \r",WhiteCandleCircle[MIDDLE][BLUE]);
//
////===========================================================================================//
//
//	YUME_START=0;
//	mov_static();
//	delay_ms(100);
//	Sendto_PC(USART1,"CALIBRATE ON BLUE CARPET!\r");
//
//	YUME_Buzz(4);
//	while(YUME_START==0)
//	{
//		YUME_START=YUME_BUTTON_INPUT;
//	}
//	YUME_Buzz(3);
//	FRONT_Sum_Colour();
//	BlueCarpet[FRONT][WHITE]= F_sum_white;
//	BlueCarpet[FRONT][RED]= F_sum_red;
//	BlueCarpet[FRONT][BLUE]= F_sum_blue;
//
//	MID_Sum_Colour();
//	BlueCarpet[MIDDLE][WHITE]= M_sum_white;
//	BlueCarpet[MIDDLE][RED]= M_sum_red;
//	BlueCarpet[MIDDLE][BLUE]= M_sum_blue;
//
//	Sendto_PC(USART1,"\r BLUE CARPET DATA ACQUIRED! \r");
//	Sendto_PC(USART1,"FRONT TCS3200\r");
//	Sendto_PC(USART1,"BlueCarpet[FRONT][WHITE]: %d \r",BlueCarpet[FRONT][WHITE]);
//	Sendto_PC(USART1,"BlueCarpet[FRONT][RED]: %d \r",BlueCarpet[FRONT][RED]);
//	Sendto_PC(USART1,"BlueCarpet[FRONT][BLUE]: %d \r",BlueCarpet[FRONT][BLUE]);
//	Sendto_PC(USART1,"MIDDLE TCS3200\r");
//	Sendto_PC(USART1,"BlueCarpet[MIDDLE][WHITE]: %d \r",BlueCarpet[MIDDLE][WHITE]);
//	Sendto_PC(USART1,"BlueCarpet[MIDDLE][RED]: %d \r",BlueCarpet[MIDDLE][RED]);
//	Sendto_PC(USART1,"BlueCarpet[MIDDLE][BLUE]: %d \r",BlueCarpet[MIDDLE][BLUE]);
//
//
////===========================================================================================//
//
//	YUME_START=0;
//	mov_static();
//	delay_ms(100);
//	Sendto_PC(USART1,"CALIBRATE ON RED CARPET!\r");
//
//	YUME_Buzz(4);
//	while(YUME_START==0)
//	{
//		YUME_START=YUME_BUTTON_INPUT;
//	}
//
//	YUME_Buzz(2);
//	YUME_Buzz(2);
//
//	FRONT_Sum_Colour();
//	RedCarpet[FRONT][WHITE]= F_sum_white;
//	RedCarpet[FRONT][RED]= F_sum_red;
//	RedCarpet[FRONT][BLUE]= F_sum_blue;
//
//	MID_Sum_Colour();
//	RedCarpet[MIDDLE][WHITE]= M_sum_white;
//	RedCarpet[MIDDLE][RED]= M_sum_red;
//	RedCarpet[MIDDLE][BLUE]= M_sum_blue;
//
//
//	Sendto_PC(USART1,"\r RED CARPET DATA ACQUIRED! \r");
//	Sendto_PC(USART1,"FRONT TCS3200\r");
//	Sendto_PC(USART1,"RedCarpet[FRONT][WHITE]: %d \r",RedCarpet[FRONT][WHITE]);
//	Sendto_PC(USART1,"RedCarpet[FRONT][RED]: %d \r",RedCarpet[FRONT][RED]);
//	Sendto_PC(USART1,"RedCarpet[FRONT][BLUE]: %d \r",RedCarpet[FRONT][BLUE]);
//	Sendto_PC(USART1,"MIDDLE TCS3200\r");
//	Sendto_PC(USART1,"RedCarpet[MIDDLE][WHITE]: %d \r",RedCarpet[MIDDLE][WHITE]);
//	Sendto_PC(USART1,"RedCarpet[MIDDLE][RED]: %d \r",RedCarpet[MIDDLE][RED]);
//	Sendto_PC(USART1,"RedCarpet[MIDDLE][BLUE]: %d \r",RedCarpet[MIDDLE][BLUE]);
//
//
///*
// * FRONT TCS3200 AUTO CALIBRATION
// */
////==========================================================================================//
//	White_Diff[FRONT]= BlackFloor[FRONT][WHITE] - WhiteCandleCircle[FRONT][WHITE];
//
//	if (White_Diff[FRONT]>20)
//	{
//		White_Threshold[FRONT]= WhiteCandleCircle[FRONT][WHITE];
//		while (White_Threshold[FRONT] <= (BlackFloor[FRONT][WHITE]-15) )
//		{
//			White_Threshold[FRONT]++;
//		}
//	}
//	else if (White_Diff[FRONT]>0)
//	{
//		White_Threshold[FRONT]= WhiteCandleCircle[FRONT][WHITE];
//		while (White_Threshold[FRONT] <= (BlackFloor[FRONT][WHITE]-5) )
//		{
//			White_Threshold[FRONT]++;
//		}
//	}
//	else White_Threshold[FRONT]= 9999;
//
////==========================================================================================//
//
//	if(WhiteCandleCircle[FRONT][RED]>WhiteCandleCircle[FRONT][BLUE])
//	{
//		CandleCircle_RB_Threshold[FRONT]= (WhiteCandleCircle[FRONT][RED]+20);
//	}
//	else
//	{
//		CandleCircle_RB_Threshold[FRONT]= (WhiteCandleCircle[FRONT][BLUE]+20);
//	}
//
////==========================================================================================//
//
//	RB_Carpet[FRONT]= fmax(BlueCarpet[FRONT][BLUE],RedCarpet[FRONT][RED]);
//	RB_Reff[FRONT]  = fmin(BlackFloor[FRONT][BLUE],BlackFloor[FRONT][RED]);
//	RB_Diff[FRONT]  = RB_Reff[FRONT] - RB_Carpet[FRONT];
//	if(RB_Diff[FRONT]>15)
//	{
//		BlackFloor_RB_Threshold[FRONT]= RB_Carpet[FRONT]+10;
//	}
//	else
//	{
//		BlackFloor_RB_Threshold[FRONT]= RB_Carpet[FRONT]+5;
//	}
//
//
///*
// * MIDDLE TCS3200 AUTO CALIBRATION
// */
////==========================================================================================//
//	White_Diff[MIDDLE]= BlackFloor[MIDDLE][WHITE] - WhiteCandleCircle[MIDDLE][WHITE];
//
//	if (White_Diff[MIDDLE]>20)
//	{
//		White_Threshold[MIDDLE]= WhiteCandleCircle[MIDDLE][WHITE];
//		while (White_Threshold[MIDDLE] <= (BlackFloor[MIDDLE][WHITE]-15) )
//		{
//			White_Threshold[MIDDLE]++;
//		}
//	}
//	else if (White_Diff[MIDDLE]>0)
//	{
//		White_Threshold[MIDDLE]= WhiteCandleCircle[MIDDLE][WHITE];
//		while (White_Threshold[MIDDLE] <= (BlackFloor[MIDDLE][WHITE]-5) )
//		{
//			White_Threshold[MIDDLE]++;
//		}
//	}
//	else White_Threshold[MIDDLE]= 9999;
//
////==========================================================================================//
//
//	if(WhiteCandleCircle[MIDDLE][RED]>WhiteCandleCircle[MIDDLE][BLUE])
//	{
//		CandleCircle_RB_Threshold[MIDDLE]= (WhiteCandleCircle[MIDDLE][RED]+20);
//	}
//	else
//	{
//		CandleCircle_RB_Threshold[MIDDLE]= (WhiteCandleCircle[MIDDLE][BLUE]+20);
//	}
//
////==========================================================================================//
//
//	RB_Carpet[MIDDLE]= fmax(BlueCarpet[MIDDLE][BLUE],RedCarpet[MIDDLE][RED]);
//	RB_Reff[MIDDLE]  = fmin(BlackFloor[MIDDLE][BLUE],BlackFloor[MIDDLE][RED]);
//	RB_Diff[MIDDLE]  = RB_Reff[MIDDLE] - RB_Carpet[MIDDLE];
//	if(RB_Diff[MIDDLE]>15)
//	{
//		BlackFloor_RB_Threshold[MIDDLE]= RB_Carpet[MIDDLE]+10;
//	}
//	else
//	{
//		BlackFloor_RB_Threshold[MIDDLE]= RB_Carpet[MIDDLE]+5;
//	}
//
//
//
//	Sendto_PC(USART1,"\r====================FRONT TCS3200====================\r");
//	Sendto_PC(USART1,"White_Threshold[FRONT]: %d \r",White_Threshold[FRONT]);
//	Sendto_PC(USART1,"CandleCircle_RB_Threshold[FRONT]: %d \r",CandleCircle_RB_Threshold[FRONT]);
//	Sendto_PC(USART1,"BlackFloor_RB_Threshold[FRONT]: %d \r",BlackFloor_RB_Threshold[FRONT]);
//	Sendto_PC(USART1,"=======================================================\r");
//
//	Sendto_PC(USART1,"\r====================MIDDLE TCS3200===================\r");
//	Sendto_PC(USART1,"White_Threshold[MIDDLE]: %d \r",White_Threshold[MIDDLE]);
//	Sendto_PC(USART1,"CandleCircle_RB_Threshold[MIDDLE]: %d \r",CandleCircle_RB_Threshold[MIDDLE]);
//	Sendto_PC(USART1,"BlackFloor_RB_Threshold[MIDDLE]: %d \r",BlackFloor_RB_Threshold[MIDDLE]);
//	Sendto_PC(USART1,"=======================================================\r");
//
//
//	while(1)
//	{
//		YUME_Buzz(2);
//		mov_static();
//		delay_ms(500);
//	}
//
//
//}
