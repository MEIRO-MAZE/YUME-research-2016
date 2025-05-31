/*****************************************************
Project   : YUME* Main Controller
Version   : 2.0
Year      : 2015
Date      :
Author    : Ryan
University: University of Brawijaya
Department: Electrical Engineering Department, Engineering Faculty
Division  : Legged Fire-Fighting Division (KRPAI)
Comments  : *Dreams/aspirations, in Japanese language

What's New: Optimization from Ver.1.x , YUME System using single STM32 and Rangefinder Controller
			New Pin Mapping for every actuator, sensor, and other peripheral

Board Type: STM32F4 Discovery Board
Chip  Type: STM32F407VG
*****************************************************/


#include "main.h"


int toggle=1;
void YUME_Initialization(void);
int main(void)
{
	int BUTTON_ACT;
	int SOUND_ACT;
	YUME_Initialization();

	mov_static();
	delay_ms(100);

	Sendto_PC(USART1,"System Running... \r ");

	while( (YUME_BUTTON_UNCLICKED) && (SOUND_INACTIVE) )
	{
		if(YUME_BUTTON_CLICKED){BUTTON_ACT=1;break;}
		if(SOUND_ACTIVATED){SOUND_ACT=1;break;}
		RotSwitch_Sampling();
		Display_MODE();
		if(YUME_BUTTON_CLICKED){BUTTON_ACT=1;break;}
		if(SOUND_ACTIVATED){SOUND_ACT=1;break;}
	}

	if(YUME_BUTTON_CLICKED){BUTTON_ACT=1;}
	if(SOUND_ACTIVATED){SOUND_ACT=1;}


	if(BUTTON_ACT==1)
	{
		YUME_Buzz(1);
		Sendto_PC(USART1,"YUME BUTTON ACTIVATED! \r");
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"BUTTON ACTIVATED");lcd_putstr(lcd);
		delay_ms(100);

		YUME_Dimension_Check();
	}
	else if(SOUND_ACT==1)
	{
		YUME_Buzz(2);
		Sendto_PC(USART1,"YUME SOUND ACTIVATED! \r");
		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"SOUND ACTIVATED");lcd_putstr(lcd);
		delay_ms(100);
	}

	switch(rot_switch_mode)
	{
		//YUME FAILED INITIALIZATION
		case YUME_MODE_DEFAULT:
			{

			}break;

		//YUME LOCATION-ROOM MODE
		case YUME_MODE_1:
			{
				YUME_Initial_Setup(rot_switch_mode);
				while(1)
				{
					ROOM_COUNTER = 1;
					YUME_Home_Detection();
					Escape_Home();

//					Home_HallwaySC_Detector();

					if(ROOM[1]==HALLWAY_SC)
					{
						YUME_LOCATION[0]= LOCATION_CORRIDOR;
						YUME_Buzz(1);
						YUME_PID_Init();
						FollowTracer_Right();

						mov_deflect_left(MED,FAR);
						mov_deflect_left(MED,FAR);
						mov_deflect_left(MED,FAR);

						YUME_Buzz(1);
						YUME_Room();
					}
					else
					{
						YUME_LOCATION[0]= LOCATION_ROOM;
//						delay_ms(500);
						RoomTypeDetector();

						if(ROOM_TYPE==GRAY_ROOM)
						{
							mov_fwd_5cm(5,FAST);
							RoomTypeDetector();
						}

//						YUME_PID_Init();
//						follow_right_counter(1);
//
//						RoomTypeDetector();

//						YUME_Buzz(5);
						YUME_Buzz(1);
						YUME_PID_Init();
						FollowTracer_Right();
					}


					YUME_LOCATION[1]=YUME_LOCATION[0];
					YUME_LOCATION[0]=LOCATION_CORRIDOR;

					YUME_Strategy();

					while(1)
					{
						YUME_Buzz(1);
						mov_static();
					}
//					YUME_TRIAL_A();
//					Obstacle_Avoider();
//					Evade_Wall();
//					mov_static();
//					while(BUTTON_IDLE)
//					{
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
//						lcd_gotoxy(0,1);sprintf(lcd,"CMPS-11");lcd_putstr(lcd);
//						lcd_gotoxy(0,2);sprintf(lcd,"CALIBRATION");lcd_putstr(lcd);
//						delay_ms(100);
//					}
//
//					lcd_gotoxy(0,3);sprintf(lcd,"INITIALIZING...");lcd_putstr(lcd);
//					CMPS11_I2C_Calibration();

//					CMPS11_Calibration();

//					while(1)
//					{
//						mov_static();
//						YUME_Buzz(3);
//
//					}
				}

			}break;

		//YUME RANGEFINDER MONITOR
		case YUME_MODE_2:
			{
				YUME_Initial_Setup(rot_switch_mode);
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"YUME  REDFIGHTER");lcd_putstr(lcd);delay_ms(50);
//				Sendto_PC(USART1,"\r YUME RED FIGHTER! \r");

				YUME_PID_Init();
				while(1)
				{
//					Check_Cat_Avoider();
//					YUME_Buzz(2);
//					YUME_PID_Init();
//					follow_right_counter(5);

//					YUME_PID_Init();
					FollowTracer_Right();
//
					YUME_Room();
//					YUME_FireFight_Ver3();

					while(1)
					{
						YUME_Buzz(3);
						mov_static();
					}
//					YUME_FireFight();
//					YUME_Navi(ROOM_1A,ROOM_4A);
//					FollowCarpet_Left(COLOUR_BLACK,INVERSE);
//					follow_left_counter(5);

//					Nav_1A_To_2();
//					follow_right_counter(5);
//					Nav_HallwaySC_To_1A();
//					Nav_HallwaySC_To_2();
//					FlameApproach();

//					Nav_2_To_4B();
//					Nav_4B_To_3();
//					RoomTypeDetector();

//					RoomDetector(1);
//					FollowCarpet_Right(COLOUR_GRAY,INVERSE);


//					YUME_PID_Init();
//					FollowTracer_Right();
//					mov_fwd_5cm(20,FAST_LEVEL_3);
//					Evade_Wall();
//
//					FireFighting();

//					WallFollow_Tester();
//					FollowTracer_Right();
//					FollowCarpet_Right(COLOUR_BLACK,INVERSE);

//					GetCMPS11_Angle16Bit();
//					GetCMPS11_Angle8Bit();



//					YUME_TRIAL_C();
////					YUME_RedFighter();
//					mov_fwd_5cm(80,FAST);
//
////					YUME_Extinguisher();
//					YUME_Extinguisher();
//
//
//
//					YUME_Celebrate();
//
//					YUME_Action_A();
//					YUME_Action_A();
//
//					mov_deflect_right(MED,FAR);
//					mov_deflect_right(MED,FAR);
//					mov_deflect_right(MED,FAR);
//
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//
//					mov_fwd_5cm(80,FAST);
//
//					while(1)
//					{
//						mov_static();
//						YUME_Buzz(4);
//						delay_ms(100);
//					}
				}
			}break;

		//YUME RUNTIME CALIBRATION
		case YUME_MODE_3:
			{
				YUME_Initial_Setup(rot_switch_mode);
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"RANGEFINDER STAT");lcd_putstr(lcd);delay_ms(50);
//				Sendto_PC(USART1,"\r YUME DISPLAY PING STATUS! \r");

				YUME_LOCATION[1]= YUME_LOCATION[0];
				YUME_LOCATION[0]= LOCATION_CORRIDOR;

				YUME_Buzz(2);
//				YUME_PID_Init();
				while(1)
				{
										Sendto_PC(USART1,"\r YUME RUNTIME CALIBRATION! \r");
										while(1)
										{
											YUME_Calibration();
											CMD_ACTUATE();
										}


//					Nav_1A_To_3();
//					Nav_4B_To_3();
//					Nav_1C_To_4A();
//
//					while(1)
//					{
//						mov_static();
//						YUME_Buzz(4);
//						delay_ms(100);
//					}

//					YUME_CandleScan();
//					 CandleScan2();



//					YUME_PID_Init();
//					FollowTracer_Right();
//
//
//
//					//YUME IN CORRIDOR
//					YUME_Buzz(2);
//					mov_fwd_5cm(15,FAST);
//
//					//YUME IN CORRIDOR
//					mov_rot_left(MED,CLOSE);
//
//					//YUME STABILIZE
//					YUME_Buzz(2);
//					Stabilize_After_Exit();
//
//					//YUME MAP UPDATE
//					YUME_Buzz(2);
//					ROOM_COUNTER++;
//					RoomDetector(ROOM_COUNTER);
//
//					Stabilize_After_Exit();
//
//					Nav_1C_To_4A();

//					Nav_1A_To_HallwaySC();
//
//					while(1)
//					{
//						YUME_Buzz(3);
//						mov_static();
//					}


//					follow_left_counter(1);
//					PushTo_Burst();
//					RotRight_Angle();
//					RoomDetector_Check();
//					TCSlave_Check();
//					FollowHome_Right();
//					Evade_Wall();
//					follow_right_counter(5);
//					FollowTracer_Right();
//
//					Nav_3_To_4A();
//					while(1)
//					{
//						mov_static();
//						YUME_Buzz(4);
//						delay_ms(100);
//					}


//					RoomDetector(ROOM_COUNTER);
//
//
//					if(ROOM[ROOM_COUNTER]== ROOM_4A)
//					{
//						mov_rot_left(MED,CLOSE);
//						mov_rot_left(MED,CLOSE);
//						RoomDetector(ROOM_COUNTER);
//					}
//
//					if(ROOM[ROOM_COUNTER]== ROOM_1A)
//					{
//						mov_rot_left(MED,CLOSE);
//						mov_rot_left(MED,CLOSE);
//						RoomDetector(ROOM_COUNTER);
//					}

//					Nav_1A_To_HallwaySC();


//					Fwd_FlameSide(15, FAST_LEVEL_3);

//					while(1)
//					{
//						FIRE_LED_BLINK_ON;
//						FIRE_LED_ON;
//						YUME_Buzz(2);
//						mov_static();
//					}







//					mov_static();
//					delay_ms(100);
//					YUME_START=YUME_BUTTON_INPUT;
//					if(YUME_START==1)
//					{
//						if(toggle==1) {toggle=2;YUME_Buzz(3);}
//						else if(toggle==2) {toggle=1;YUME_Buzz(2);}
//					}
//
//					if(toggle==1)
//					{
//
//						Display_Ping_Status ();
//						Send_Ping_Status ();
//					}
//
//					else if (toggle==2)
//					{
//
//						Get_IR();
//						Display_IR_Stat();
//					}
//					delay_ms(100);

				}


			}break;

		//YUME TRIAL MODE
		case YUME_MODE_4:
			{

				YUME_Initial_Setup(rot_switch_mode);
				while(1)
				{
					Hybrid_TCS3200Tracer_MainMenu();
				}
			}break;

		//YUME TESTING MODE
		case YUME_MODE_5:
			{
				YUME_Initial_Setup(rot_switch_mode);
//				YUME_Initial_Setup(rot_switch_mode);
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
//				lcd_gotoxy(4,1);sprintf(lcd,"TCS 3200");lcd_putstr(lcd);delay_ms(50);
//				lcd_gotoxy(2,2);sprintf(lcd,"PUSH-TO-SEND");lcd_putstr(lcd);delay_ms(50);
//				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
//				lcd_gotoxy(4,1);sprintf(lcd,"DEMO 2015");lcd_putstr(lcd);delay_ms(50);
//				Sendto_PC(USART1,"YUME PUSH-TO-SEND TCS3200 STAT \r");
//
//				YUME_LOCATION[LAST_LOC]=LOCATION_CORRIDOR;
//				YUME_LOCATION[PRESENT_LOC]=LOCATION_ROOM;
//				INITIAL_ZONE=ZONE_BLUE;
//

//				delay_ms(100);
				while(1)
				{
//
//					INITIAL_ZONE=ZONE_BLUE;



//					Gyro_Calibration();
					while(1)
					{

						Sensor_Menu();
//						Get_TPA81();
//						follow_left_counter(10);
//						Object_Follow();
//						Avoider();



//						PushtoSend_TCS3200_Status();
//						YUME_TRIAL_A();


//						PushTo_Burst();
//						FRONT_Sum_Colour();
//						MID_Sum_Colour();

//						PushtoSend_TCS3200_Status();


						//mov_static();
						//mov_fwd_5cm(5,FAST);//
//						lcd_display_clear();

//						Read_Accelerometer();
//						Read_Gyroscope();
//						ComplementaryFilter();
//						Sendto_PC(USART1,"X ANGLE: %d | Y ANGLE: %d | Z ANGLE: %d \t\t\t", (int)Accel_Angle_X,(int)Accel_Angle_Y,(int)Accel_Angle_Z);
////						Sendto_PC(USART1,"ROLL: %d | PITCH: %d  \r", (int)ROLL,(int)PITCH);
//						Sendto_PC(USART1,"COMP ROLL: %d | COMP PITCH: %d  \t\t", (int)COMPLEMENTARY_ROLL,(int)COMPLEMENTARY_PITCH);
////						Sendto_PC(USART1,"LPF_ACCEL_X: %d | LPF_ACCEL_Y: %d | LPF_ACCEL_Z: %d ", (int) LPF_ACCEL_X, (int) LPF_ACCEL_Y, (int) LPF_ACCEL_Z);
//						Sendto_PC(USART1,"LPF_ACCEL_Z: %d \r", (int) LPF_ACCEL_Z);

//						Read_Gyroscope();
//						Sendto_PC(USART1,"ROLL: %d | PITCH: %d \r",(int)ROLL,(int)PITCH);
//						Sendto_PC(USART1,"X ANGLE: %d | Y ANGLE: %d | Z ANGLE: %d \r",(int) RATE_GYRO_X, (int) RATE_GYRO_Y, (int) RATE_GYRO_Z);
//						Sendto_PC(USART1,"X ANGLE: %d | Y ANGLE: %d | Z ANGLE: %d \r",GYRO_ANGLE_X,GYRO_ANGLE_Y,GYRO_ANGLE_Z);

						//Read_Gyro();
//						lcd_gotoxy(0,0);sprintf(lcd,"YUME GYRO");lcd_putstr(lcd);
//						lcd_gotoxy(1,0);
//						sprintf(lcd,"X: %d Y: %d Z: %d",YUME_MPU6050.Gyroscope_X,YUME_MPU6050.Gyroscope_Y,YUME_MPU6050.Gyroscope_Z);
						//Sendto_PC(USART1,"YUME GYRO X: %d Y: %d Z: %d \r",YUME_MPU6050.Gyroscope_X,YUME_MPU6050.Gyroscope_Y,YUME_MPU6050.Gyroscope_Z);
//						lcd_putstr(lcd);

//						lcd_gotoxy(2,0);sprintf(lcd,"YUME ACCEL");lcd_putstr(lcd);
//						lcd_gotoxy(3,0);
//						sprintf(lcd,"X: %d Y: %d Z: %d",YUME_MPU6050.Accelerometer_X,YUME_MPU6050.Accelerometer_Y,YUME_MPU6050.Accelerometer_Z);
						//Sendto_PC(USART1,"YUME ACCELEROMETER X: %d Y: %d Z: %d \r",YUME_MPU6050.Accelerometer_X,YUME_MPU6050.Accelerometer_Y,YUME_MPU6050.Accelerometer_Z);
//						lcd_putstr(lcd);

						//delay_ms(300);//

//						YUME_BLDC_Fight();
//						YUME_Search_Fire();
//						Get_UV();
//						Sendto_PC(USART1,"\rUV_state: %d \r",UV_state);
//						Get_TPA81();
//						Sendto_PC(USART1,"FIRE: %d \r",FIRE);
//						lcd_display_clear();
//						lcd_gotoxy(0,0);sprintf(lcd,"FIRE: %d", FIRE);lcd_putstr(lcd);delay_ms(50);
//						lcd_gotoxy(0,0);sprintf(lcd,"UV STATE: %d", UV_state);lcd_putstr(lcd);delay_ms(50);
//						delay_ms(100);

//						TCS3200_AutoCalibration();
//						YUME_FireFight();
//						YUME_Celebrate();
//						mov_celebrate();

//						PushtoSend_TCS3200_Status();
//						YUME_FireFight();
//						mov_deflect_right(MED,FAR);

//						Get_UV();
//
//						while(UV_Lock==0)
//						{
//							Get_UV();
//							YUME_Buzz(1);
//						}
//
//						while(UV_Lock==1)
//						{
//							YUME_Buzz(4);
//							YUME_LED_BLINK_ON;
//
//							mov_fwd_5cm(15,FAST_LEVEL_3);
//
//							YUME_Search_Fire();
//							mov_rotright_fire(MED,FAR);
//							mov_rotright_fire(MED,FAR);
//							mov_rotright_fire(MED,FAR);
//	//						YUME_FireTracker();
//							Get_UV();
//							if(UV_state==1)
//							{
//								UV_Lock=0;
//								led_off_counter=1;
//							}
//						}
//						led_off_counter=1;
//						Sendto_PC(USART1,"\rUV_state: %d \r",UV_state);
//						Sendto_PC(USART1,"UV_Lock: %d \r",UV_Lock);
//						Sendto_PC(USART1,"led_off_counter: %d \r",led_off_counter);
//

					}
				}

			}break;

		//YUME SEARCH FIRE TEST
		case YUME_MODE_6:
			{
//				YUME_Initial_Setup(rot_switch_mode);
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
//				lcd_gotoxy(0,1);sprintf(lcd,"YUME SEARCH FIRE");lcd_putstr(lcd);delay_ms(50);
//				Sendto_PC(USART1,"YUME SEARCH FIRE \r");

//				YUME_PID_Init();
//				YUME_Buzz(2);
//				YUME_PID_Init();

//				RoomTypeDetector();
//
//				YUME_Buzz(2);
//				YUME_PID_Init();
				FlameSense_PID_Init();
				while(1)
				{

					YUME_FlameFollowDemo();
//					FlameApproach();
//					FollowTracer_Right();
////
//						//YUME IN CORRIDOR
//						YUME_Buzz(1);
//						mov_fwd_5cm(15,FAST_LEVEL_3);
//
//						//YUME IN CORRIDOR
//						mov_rot_left(MED,CLOSE);
//
//						//YUME STABILIZE
//						YUME_Buzz(1);
//						Stabilize_After_Exit();
//
//						//YUME MAP UPDATE
//						YUME_Buzz(1);
//						ROOM_COUNTER++;
//						RoomDetector(ROOM_COUNTER);


//					Nav_4A_To_2();
//					YUME_LOCATION[0]==LOCATION_CORRIDOR;
//					Nav_1A_To_2();
//
//					while(1)
//					{
//						YUME_Buzz(1);
//						mov_static();
//					}

//					FollowTracer_Left();

//					mov_celebrate();
//					Nav_1A_To_4A();
//
////					Evade_Wall();
////					FollowTracer_Right();
////					YUME_FlameDemo();
//////					FIRE=0;
//////
//////					YUME_FlameCheck();
//////					if(FIRE==1)
//////					{
//						Nav_3_To_4A();
//						Nav_2_To_4B();
//						while(1)
//						{
//							YUME_Buzz(1);
//							mov_static();
//						}
//					}
//
//					else if(FIRE==0)
//					{
//						mov_rot_right(MED,FAR);
//						mov_rot_right(MED,FAR);
//
//						YUME_FlameCheck();
//						if(FIRE==1)
//						{
//							while(1)
//							{
//								YUME_Buzz(1);
//								mov_static();
//							}
//						}
//					}


//					Get_UV();
//
//					while(UV_Lock==0)
//					{
//						YUME_LED_OFF;
//						Get_UV();
//					}
//					while(UV_Lock==1)
//					{
//						YUME_LED_ON;
////						YUME_LED_BLINK_ON;
//						YUME_Search_Fire();
////						YUME_FireTracker();
//						Get_UV();
//						if(UV_state==1)
//						{
//							UV_Lock=0;
//							led_off_counter=1;
//						}
//					}
//					led_off_counter=1;
//					Sendto_PC(USART1,"\rUV_state: %d \r",UV_state);
//					Sendto_PC(USART1,"UV_Lock: %d \r",UV_Lock);
//					Sendto_PC(USART1,"led_off_counter: %d \r",led_off_counter);

//
//					PID_Runtime_Tuning();
//					RoomDetector_Check();
//					PushTo_Burst();
//					FlameApproach();

//					mov_static();
//					delay_ms(100);
//
//					if(BUTTON_A_CLICKED) {toggle=2;YUME_Buzz(3);}
//					if(BUTTON_B_CLICKED) {toggle=1;YUME_Buzz(2);}
//
//					if(toggle==1)
//					{
//
//						Display_Ping_Status ();
//						Send_Ping_Status ();
//					}
//
//					else if (toggle==2)
//					{
//
//						Get_IR();
//						Display_IR_Stat();
//					}
//					delay_ms(100);


				}
			}break;
	}
	while(1);

	return 0;
}

void YUME_Initialization(void)
{
	//CLOCK CONFIG
	SystemInit();

	//SYSTICK DELAY INIT
	SysTick_Init();

	//YUME HEXAPOD SERVO INIT
	YUME_Servo_Initialization();

	//LCD INIT
	delay_ms(50);
	YUME_LCD_Init();
	lcd_cursor_off_blink_off();
	lcd_display_clear();

//	PanServo_Init();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"SYSTEM");lcd_putstr(lcd);
	lcd_gotoxy(1,2);sprintf(lcd,"INITIALIZATION");lcd_putstr(lcd);
	lcd_gotoxy(1,3);sprintf(lcd,"BRAWIJAYA 2016");lcd_putstr(lcd);
	delay_ms(500);

//	SHARP_IR_Init();

	//INERTIAL MEASUREMENT UNIT (IMU) SENSOR
//	MPU_6050_Init();
//	YUME_GY_85_Init ();
	YUME_CMPS11_Init();

	//YUME USART COMMUNICATION PROTOCOLS
	USART1_Init(9600);
	USART2_Init(9600);
	USART3_Init(9600);
	UART4_Init(9600);
	UART5_Init(9600);
	USART6_Init(9600);
	//USART4_Init(9600);

	//YUME USER INTERFACE
	Button_Init();
	Buzzer_Init();
//	LED_Init();
	FIRE_LED_Init();
	YUME_LED_Interrupt_Init();
	RotSwitch_Init();
	RotSwitch_Sampling();



	//YUME UV-TRON INIT
//	YUME_UV_TRON_Init();

	//YUME THERMOPILE INIT
//	YUME_Thermopile_Init();

	//INFRARED PROXIMITY SENSOR
	IR_Proximity_Init();
	//IR_Interrupt_Init();

//	YUME COLOUR SENSOR
//	TCS3200_Init();
//	YUME_TCS3200_Interrupt_Init();
//	YUME_Tracer_Init();
//	Tracer_Decoder_Interrupt_Init();

	//YUME BRUSHLESS DC FAN INITIALIZATION
	YUME_BLDC_Init();
//	YUME_Extinguisher_Init();

	//YUME PID CONTROLLER INITIALIZATION
	YUME_PID_Init();
	//YUME_PID_Interrupt_Init();


//	I2C3_Init ();

	//YUME CONTACT BUMPER
	Bumper_Init();


	//YUME SENSOR STAT INTERRUPT
//	YUME_Stat_Interrupt_Init();
//	YUME_LED_Interrupt_Init();

//	PanServo_Init();

	FlameSensor_Init();

	//YUME FLAME TRACKING PID
	FlameSense_PID_Init();

	//YUME SOUND ACTIVATION INIT
	YUME_Sound_Activation_Init();

	YUME_Buzz(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT YUME");lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"SYSTEM");lcd_putstr(lcd);
	lcd_gotoxy(1,2);sprintf(lcd,"INITIALIZATION");lcd_putstr(lcd);
	lcd_gotoxy(3,3);sprintf(lcd,"COMPLETED");lcd_putstr(lcd);
	delay_ms(50);


	Sendto_PC(USART1,"PROJECT YUME 2016 \r");
	Sendto_PC(USART1,"ELECTRICAL ENGINEERING - UNIVERSITY OF BRAWIJAYA \r");
	Sendto_PC(USART1,"SYSTEM INITIALIZATION");
	Sendto_PC(USART1,".");
	Sendto_PC(USART1,".");
	Sendto_PC(USART1,". \r");
	Sendto_PC(USART1,"INITIALIZATION COMPLETED \r");

}

