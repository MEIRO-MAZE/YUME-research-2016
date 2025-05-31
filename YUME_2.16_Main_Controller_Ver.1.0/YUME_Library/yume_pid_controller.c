/*==============================================================================================
								  	 PROJECT YUME Ver.1.0
								  	 YUME PID CONTROLLER
==============================================================================================*/

#include "yume_pid_controller.h"
// PID FOLLOW VARIABLES


int count=1;
/*
 * Note: PID Calc setiap 50 ms, program langsung stuck di inisialisasi
 */
//void YUME_PID_Interrupt_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
//
//	TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
//
//	TIM_TimeBaseStructure.TIM_Prescaler = 33593;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period = 5000; //0.004*5000=50Hz jadi sampling adc setiap 20ms
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
//
//	TIM_Cmd(TIM2, ENABLE); //default di off dulu
//
//	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
//
//    NVIC_InitTypeDef NVIC_InitStructure;
//    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//
//}
//
//void TIM4_IRQHandler(void)
//{
//    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
//    	{
//    		count++;
//
//    		if (count==1) GPIO_SetBits(GPIOC, GPIO_Pin_0);
//    		//if (count==2) {GPIO_ResetBits(GPIOC, GPIO_Pin_0);count=1;}
//    		//PID_Calc_Interrupt_Init();
//    		//YUME_RGB_Tracer_Encoder();
//    		//PID_Calc();
//    		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
//    	}
//}

//ADC INTERRUPT INIT
//void YUME_PID_Interrupt_Init(void)
//{
////	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
//
//	TIM_TimeBaseStructure.TIM_Prescaler = 335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period = 5000; //0.004*5000=50ms jadi sampling adc setiap 20ms
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
//
//	TIM_Cmd(TIM5, ENABLE); //default di off dulu
//
//	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
//
//    NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}
//
//void TIM5_IRQHandler(void)
//{
//    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
//    	{
//    		PID_Calc();
//    		//PID_follow_right();
//    		TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
//    	}
//}


/*
 * WALL FOLLOWING FUNCTIONS
 */


/*
 * func : void YUME_PID_Init(void)
 * brief: initialize PID variables
 * param: N/A
 * Programmer's Note: This function only required to be called once in the early initialization
 * 					  Call this function in the YUME_Initialization function
 */
void YUME_PID_Init(void)
{
	//YUME PID WALL FOLLOWING RIGHT RULE
	PID_F_R.P[0]=0;
	PID_F_R.P[1]=0;
	PID_F_R.P[2]=0;
	PID_F_R.I[0]=0;
	PID_F_R.I[1]=0;
	PID_F_R.I[2]=0;
	PID_F_R.D[0]=0;
	PID_F_R.D[1]=0;
	PID_F_R.D[2]=0;

	//DEFAULT
//	PID_F_R.Kp=4;
//	PID_F_R.Ki=4;
//	PID_F_R.Kd=2;

	PID_F_R.Kp=2;
	PID_F_R.Ki=2;
	PID_F_R.Kd=0;

	PID_F_R.Ts=1;

	//NEW METHOD
//	PID_F_R.Kp=6;
//	PID_F_R.Ki=1;
//	PID_F_R.Kd=1;
//	PID_F_R.Ts=1;
	PID_F_R.set_point_upper=24;
	PID_F_R.set_point_lower=22;
	PID_F_R.set_point=22;

	PID_F_R.error[0]=0;
	PID_F_R.error[1]=0;
	PID_F_R.error[2]=0;
	PID_F_R.pid_value[0]=0;
	PID_F_R.pid_value[1]=0;
	PID_F_R.pid_value[2]=0;
	PID_F_L.P[1]=0;
	PID_F_L.P[2]=0;
	PID_F_L.I[0]=0;
	PID_F_L.I[1]=0;
	PID_F_L.I[2]=0;
	PID_F_L.D[0]=0;
	PID_F_L.D[1]=0;
	PID_F_L.D[2]=0;

	PID_F_L.Kp=4;
	PID_F_L.Ki=2;
	PID_F_L.Kd=0;
	PID_F_L.Ts=1;

	PID_F_L.error[0]=0;
	PID_F_L.error[1]=0;
	PID_F_L.error[2]=0;

	PID_F_L.pid_value[0]=0;
	PID_F_L.pid_value[1]=0;
	PID_F_L.pid_value[2]=0;

	PID_F_L.set_point=12;
	PID_F_L.set_point_upper=14;
	PID_F_L.set_point_lower=12;

	//YUME PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_R.P[0]=0;
	PID_DFL_R.P[1]=0;
	PID_DFL_R.P[2]=0;
	PID_DFL_R.I[0]=0;
	PID_DFL_R.I[1]=0;
	PID_DFL_R.I[2]=0;
	PID_DFL_R.D[0]=0;
	PID_DFL_R.D[1]=0;
	PID_DFL_R.D[2]=0;
	PID_DFL_R.Kp=4;
	PID_DFL_R.Ki=4;
	PID_DFL_R.Kd=3;
	PID_DFL_R.Ts=1;
	PID_DFL_R.error[0]=0;
	PID_DFL_R.error[1]=0;
	PID_DFL_R.error[2]=0;
	PID_DFL_R.pid_value[0]=0;
	PID_DFL_R.pid_value[1]=0;
	PID_DFL_R.pid_value[2]=0;
	PID_DFL_R.set_point=16;

	//YUME PID WALL CENTERING DEFLECT RIGHT RULE
	PID_DFL_L.P[0]=0;
	PID_DFL_L.P[1]=0;
	PID_DFL_L.P[2]=0;
	PID_DFL_L.I[0]=0;
	PID_DFL_L.I[1]=0;
	PID_DFL_L.I[2]=0;
	PID_DFL_L.D[0]=0;
	PID_DFL_L.D[1]=0;
	PID_DFL_L.D[2]=0;
	PID_DFL_L.Kp=1;
	PID_DFL_L.Ki=0;
	PID_DFL_L.Kd=0;
	PID_DFL_L.Ts=1;
	PID_DFL_L.error[0]=0;
	PID_DFL_L.error[1]=0;
	PID_DFL_L.error[2]=0;
	PID_DFL_L.pid_value[0]=0;
	PID_DFL_L.pid_value[1]=0;
	PID_DFL_L.pid_value[2]=0;
	PID_DFL_L.set_point=16;
}

/*
 * func      : void PID_Calc(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_RightRule(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */
	PID_F_R.pid_value[2]=PID_F_R.pid_value[1];
	PID_F_R.pid_value[1]=PID_F_R.pid_value[0];

	PID_F_R.error[2]=PID_F_R.error[1];
	PID_F_R.error[1]=PID_F_R.error[0];

	if (Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point) {PID_F_R.error[0]=0;}
	else if (Ping[PING_ASKEW_RIGHT] > PID_F_R.set_point)
		{
			PID_F_R.error[0] = Ping[PING_ASKEW_RIGHT] - PID_F_R.set_point;
		}

	else if (Ping[PING_ASKEW_RIGHT] < PID_F_R.set_point)
		{
			PID_F_R.error[0] = PID_F_R.set_point - Ping[PING_ASKEW_RIGHT];
		}

	/*
	 * PID FORMULA
	 */
	PID_F_R.P[2]= PID_F_R.error[0]-PID_F_R.error[2];
	PID_F_R.P[1]= PID_F_R.Kp;
	PID_F_R.P[0]= PID_F_R.P[1]*PID_F_R.P[2]; //Proportional Controller

	PID_F_R.I[2]= PID_F_R.Ki*PID_F_R.Ts/2;
	PID_F_R.I[1]= PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.I[0]= PID_F_R.I[2]*PID_F_R.I[1]; //Integral Controller


	PID_F_R.D[2]= 2*PID_F_R.Kd/PID_F_R.Ts;
	PID_F_R.D[1]= PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2];
	PID_F_R.D[0]= PID_F_R.D[2]*PID_F_R.D[1]; //Derivative Controller

//	PID_F_R.I= ( (PID_F_R.Ki*PID_F_R.Ts/2)*(PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2]) );
//	PID_F_R.D= ( (2*PID_F_R.Kd/PID_F_R.Ts)*(PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2]));

	PID_F_R.pid_value[0]= PID_F_R.pid_value[2] + PID_F_R.P[0] + PID_F_R.I[0] + PID_F_R.D[0];
}

/*
 * PID FOLLOW LEFT RULE
 */

/*
 * func      : void PID_Calc_LeftRule(void)
 * brief     : PID Controller Calculations
 * param     : N/A
 * Written By: Ryan
 * Ver       : 1
 * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
 * 					  This function should be called everytime PID function executed
 */
void PID_Calc_LeftRule(void)
{
	/*
	 * Update Nilai Variable PID & Set-Point Error
	 */

	PID_F_L.pid_value[2]=PID_F_L.pid_value[1];
	PID_F_L.pid_value[1]=PID_F_L.pid_value[0];

	PID_F_L.error[2]=PID_F_L.error[1];
	PID_F_L.error[1]=PID_F_L.error[0];

	if (Ping[PING_ASKEW_LEFT]==PID_F_L.set_point) {PID_F_L.error[0]=0;}

	else if (Ping[PING_ASKEW_LEFT] > PID_F_L.set_point)
		{
			PID_F_L.error[0] = Ping[PING_ASKEW_LEFT] - PID_F_L.set_point;
		}

	else if (Ping[PING_ASKEW_LEFT] < PID_F_L.set_point)
		{
			PID_F_L.error[0] = PID_F_L.set_point - Ping[PING_ASKEW_LEFT];
		}

	/*
	 * PID FORMULA
	 */
	PID_F_L.P[2]= PID_F_L.error[0]-PID_F_L.error[2];
	PID_F_L.P[1]= PID_F_L.Kp;
	PID_F_L.P[0]= PID_F_L.P[1]*PID_F_L.P[2]; //Proportional Controller

	PID_F_L.I[2]= PID_F_L.Ki*PID_F_L.Ts/2;
	PID_F_L.I[1]= PID_F_L.error[0]+(2*PID_F_L.error[1])+PID_F_L.error[2];
	PID_F_L.I[0]= PID_F_L.I[2]*PID_F_L.I[1]; //Integral Controller

	PID_F_L.D[2]= 2*PID_F_L.Kd/PID_F_L.Ts;
	PID_F_L.D[1]= PID_F_L.error[0]-(2*PID_F_L.error[1])+PID_F_L.error[2];
	PID_F_L.D[0]= PID_F_L.D[2]*PID_F_L.D[1]; //Derivative Controller

//	PID_F_L.I= ( (PID_F_L.Ki*PID_F_L.Ts/2)*(PID_F_L.error[0]+(2*PID_F_L.error[1])+PID_F_L.error[2]) );
//	PID_F_L.D= ( (2*PID_F_L.Kd/PID_F_L.Ts)*(PID_F_L.error[0]-(2*PID_F_L.error[1])+PID_F_L.error[2]));

	PID_F_L.pid_value[0]= PID_F_L.pid_value[2] + PID_F_L.P[0] + PID_F_L.I[0] + PID_F_L.D[0];
}


///*
// * func      : void PID_Calc(void)
// * brief     : PID Controller Calculations
// * param     : N/A
// * Written By: Ryan
// * Ver       : 1
// * Programmer's Note: PID Formula rewritten with guidance from KRPAI Senior, Desta.
// * 					  This function should be called everytime PID function executed
// */
//void Centerize_PID_Calc(void)
//{
//	/*
//	 * Update Nilai Variable PID & Set-Point Error
//	 */
//
//	PID_DFL_R.pid_value[2]=PID_DFL_R.pid_value[1];
//	PID_DFL_R.pid_value[1]=PID_DFL_R.pid_value[0];
//
//	PID_DFL_R.error[2]=PID_DFL_R.error[1];
//	PID_DFL_R.error[1]=PID_DFL_R.error[0];
//
//	if (Ping[PING_RIGHT]==PID_DFL_R.set_point) {PID_DFL_R.error[0]=0;}
//	else if (Ping[PING_RIGHT] > PID_DFL_R.set_point)
//		{
//			PID_DFL_R.error[0] = Ping[PING_RIGHT] - PID_DFL_R.set_point;
//		}
//
//	else if (Ping[PING_RIGHT] < PID_DFL_R.set_point)
//		{
//			PID_DFL_R.error[0] = PID_DFL_R.set_point - Ping[PING_RIGHT];
//		}
//
//	/*
//	 * PID FORMULA
//	 */
//	PID_DFL_R.P[2]= PID_DFL_R.error[0]-PID_DFL_R.error[2];
//	PID_DFL_R.P[1]= PID_DFL_R.Kp;
//	PID_DFL_R.P[0]= PID_DFL_R.P[1]*PID_DFL_R.P[2]; //Proportional Controller
//
//	PID_DFL_R.I[2]= PID_DFL_R.Ki*PID_DFL_R.Ts/2;
//	PID_DFL_R.I[1]= PID_DFL_R.error[0]+(2*PID_DFL_R.error[1])+PID_DFL_R.error[2];
//	PID_DFL_R.I[0]= PID_DFL_R.I[2]*PID_DFL_R.I[1]; //Integral Controller
//
//	PID_DFL_R.D[2]= 2*PID_DFL_R.Kd/PID_DFL_R.Ts;
//	PID_DFL_R.D[1]= PID_DFL_R.error[0]-(2*PID_DFL_R.error[1])+PID_DFL_R.error[2];
//	PID_DFL_R.D[0]= PID_DFL_R.D[2]*PID_DFL_R.D[1]; //Derivative Controller
//
//	//PID_F_R.I= ( (PID_F_R.Ki*PID_F_R.Ts/2)*(PID_F_R.error[0]+(2*PID_F_R.error[1])+PID_F_R.error[2]) );
//	//PID_F_R.D= ( (2*PID_F_R.Kd/PID_F_R.Ts)*(PID_F_R.error[0]-(2*PID_F_R.error[1])+PID_F_R.error[2]));
//
//	PID_DFL_R.pid_value[0]= PID_DFL_R.pid_value[2] + PID_DFL_R.P[0] + PID_DFL_R.I[0] + PID_DFL_R.D[0];
//}

//void Centerize_Right(void)
//{
//	if (Ping[PING_FRONT]<=25)
//	{
//		while (Ping[PING_ASKEW_RIGHT]<=15)
//		{
//			mov_rot_left(MED, FAR);
//		}
//
//		if (Ping[PING_ASKEW_RIGHT]>50)
//		{
//			mov_rot_right(MED, FAR);
//		}
//	}
//	else PID_Centerize_Right();
//}
//
//void PID_Centerize_Right(void)
//{
//	Centerize_PID_Calc();
//
//	//KONDISI ROBOT SESUAI
//	if ( Ping[PING_RIGHT]==PID_DFL_R.set_point )
//		{
//			mov_fwd_5cm(5, MED);
//		}
//
//	//KONDISI ROBOT JAUH DARI DINDING
//	else if ( Ping[PING_RIGHT]>PID_DFL_R.set_point )
//		{
//			//if (PID_DFL_R.pid_value[0]>=3) PID_DFL_R.pid_value[0]=3; //windup
//
//			if ((PID_DFL_R.pid_value[0]<1)&&(PID_DFL_R.pid_value[0]>=0))
//				{
//					mov_fwd_5cm(5, MED);
//				}
//			Centerize_deflect_right(MED, FAR, &PID_DFL_R.pid_value[0]);
//		}
//
//	//KONDISI ROBOT DEKAT DENGAN DINDING
//	else if ( Ping[PING_RIGHT]<PID_DFL_R.set_point )
//		{
//			//if (PID_DFL_R.pid_value[0]>=3) PID_DFL_R.pid_value[0]=3; //windup
//			if ((PID_DFL_R.pid_value[0]<1)&&(PID_DFL_R.pid_value[0]>=0))
//				{
//					mov_fwd_5cm(5, MED);
//				}
//			 Centerize_deflect_left(MED, FAR, &PID_DFL_R.pid_value[0]);
//		}
//}
//
//
//void Centerize_deflect_right(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	int counter;
//	//int limit= *COMMAND_LOOP;
//
//	for(counter=1;counter<=*COMMAND_LOOP;counter++)
//	{
//		mov_deflect_right(MED, FAR);
//	}
//
//}
//
//void Centerize_deflect_left(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	int counter;
//	//int limit= *COMMAND_LOOP;
//	mov_askew_left_transition();
//	for(counter=1;counter<=*COMMAND_LOOP;counter++)
//	{
//		mov_deflect_left(MED, FAR);
//	}
//
//}




/*
 *  YUME PID CONTROLLER RUNTIME TUNING
 */
void PID_Runtime_Tuning(void)
{
	int MENU_VAR;

	while(BUTTON_IDLE)
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"YUME 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"PID CONTROLLER");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"RUNTIME");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"TUNING");lcd_putstr(lcd);
		delay_ms(100);
	}

	if(YUME_BUTTON_CLICKED)
	{


		while(1)
		{
//			while(BUTTON_IDLE)
//			{
//				YUME_Buzz(1);
//				lcd_display_clear();
//				lcd_gotoxy(0,0);sprintf(lcd,"YUME 2016");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"PID TUNING");lcd_putstr(lcd);
//				lcd_gotoxy(0,2);sprintf(lcd,"INITIALIZING");lcd_putstr(lcd);
//				delay_ms(100);
//			}

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

			if(MENU_VAR>3) MENU_VAR=0;
			else if (MENU_VAR<0) MENU_VAR=3;

			switch(MENU_VAR)
			{
				case 0:
						{
							lcd_display_clear();
							lcd_gotoxy(0,0);sprintf(lcd,"FOLLOW RIGHT");lcd_putstr(lcd);
							delay_ms(100);
							while(MENU_VAR==0)
							{
								follow_right_counter(1);

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

								if(MENU_VAR>3) MENU_VAR=0;
								else if (MENU_VAR<0) MENU_VAR=3;
								//WALL FOLLOW START
							}


						}break;

				case 1:
						{
							mov_static();
							Kp_Tuning();

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

							if(MENU_VAR>3) MENU_VAR=0;
							else if (MENU_VAR<0) MENU_VAR=3;
							//Kp Tuning

						}break;
				case 2:
						{
							mov_static();
							Ki_Tuning();

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

							if(MENU_VAR>3) MENU_VAR=0;
							else if (MENU_VAR<0) MENU_VAR=3;
							//Ki Tuning
						}break;
				case 3:
						{
							mov_static();
							Kd_Tuning();

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

							if(MENU_VAR>3) MENU_VAR=0;
							else if (MENU_VAR<0) MENU_VAR=3;
							//Kd Tuning
						}break;

			}
		}

	}

}

void Kp_Tuning(void)
{

	while(YUME_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			YUME_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_R.Kp++;
		}
		if(BUTTON_B_CLICKED)
		{
			YUME_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_R.Kp--;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Kp: %d",(int)PID_F_R.Kp);lcd_putstr(lcd);
		delay_ms(100);
	}

}

void Ki_Tuning(void)
{

	while(YUME_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			YUME_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_R.Ki++;
		}
		if(BUTTON_B_CLICKED)
		{
			YUME_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_R.Ki--;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Ki: %d",(int)PID_F_R.Ki);lcd_putstr(lcd);
		delay_ms(100);
	}

}

void Kd_Tuning(void)
{

	while(YUME_BUTTON_UNCLICKED)
	{
		if(BUTTON_A_CLICKED)
		{
			YUME_Buzz(2);
			while(BUTTON_A_CLICKED){};
			PID_F_R.Kd++;
		}
		if(BUTTON_B_CLICKED)
		{
			YUME_Buzz(1);
			while(BUTTON_B_CLICKED){};
			PID_F_R.Kd--;
		}

		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"PID_F_R.Kd: %d",(int)PID_F_R.Kd);lcd_putstr(lcd);
		delay_ms(100);
	}

}
