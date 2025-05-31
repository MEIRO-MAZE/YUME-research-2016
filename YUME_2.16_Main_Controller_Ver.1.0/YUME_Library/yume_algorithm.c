///*========================================================================================
//								  	  PROJECT YUME Ver.2.0
//								  YUME ALGORITHM LIBRARY
//==============================================================================================*/
//
//#include "yume_algorithm.h"
//
///* func      : void YUME_Dimension_Check(void)
// * brief     : Detecting dimension checking condition and configuring locomotion to fit the dimension check box
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Sunday, October 15th 2015)
// * Revised BY: N/A
// * programmer's Note: Trigger the YUME Dimension check by putting your hands <= 10 cm away from RIGHT and LEFT PING)))
// *
// */
//void YUME_Dimension_Check(void)
//{
//	YUME_Buzz(3);
//
//	while( (Ping[PING_LEFT]<=10)&&(Ping[PING_RIGHT]<=10) )
//	{
//		mov_fwd_3cm(5,FAST_LEVEL_2);
//		YUME_Buzz(1);
//	}
//
//
//	YUME_Buzz(3);
//}
//
///* func      : void YUME_Home_Detection(void)
// * brief     : Detecting Home
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Sunday, October 15th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void YUME_Home_Detection(void)
//{
//	unsigned int HOME;
//
////	FRONT_Sum_Colour();
////	F_TRACER= TRACER_STAT;
////	MID_Sum_Colour();
////	M_TRACER= TRACER_STAT;
////	HOME= F_TRACER | M_TRACER;
//	//while (F_DETECTED_COLOUR!=COLOUR_WHITE && M_DETECTED_COLOUR!=COLOUR_WHITE){}
////
////	HOME = (F_DETECTED_COLOUR==COLOUR_WHITE) || (M_DETECTED_COLOUR==COLOUR_WHITE)||
////		   (F_DETECTED_COLOUR==COLOUR_RED) || (M_DETECTED_COLOUR==COLOUR_RED);
//	//HOME DETECTOR
////	if( (F_DETECTED_COLOUR==COLOUR_WHITE || M_DETECTED_COLOUR==COLOUR_WHITE) ||
////		   (F_DETECTED_COLOUR==COLOUR_WHITE && M_DETECTED_COLOUR==COLOUR_RED) ||
////		   (F_DETECTED_COLOUR==COLOUR_RED && M_DETECTED_COLOUR==COLOUR_WHITE)
////	      )
////
//	HOME=1;
//	if (HOME==1)
//	{
//
//		if (Ping[PING_FRONT]>30)
//		{
//			YUME_Buzz(4);
////			while(
////					( (Ping[PING_FRONT]>=30) && (Ping[PING_RIGHT]>=20) && (Ping[PING_ASKEW_RIGHT]>=15) ) ||
////					( (Ping[PING_FRONT]<=30) && (Ping[PING_RIGHT]>=20) && (Ping[PING_ASKEW_RIGHT]>=15) )
////				 )
//			if( Ping[PING_RIGHT]>20 )
//			{
//				mov_rot_right(MED,FAR); //adjust to correct position
//				mov_rot_right(MED,FAR); //adjust to correct position
//				while(
//						(Ping[PING_RIGHT]>=15) && (Ping[PING_ASKEW_RIGHT]>=15)
//					 )
//				{
//					mov_rot_right(MED,FAR);
//					if(Ping[PING_FRONT]<=13 )
//					{
//						mov_bwd(5,FAST);
//					}
//
//				}
//			}
//
//		}
//
//		else if(Ping[PING_FRONT]<=30)
//		{
//			YUME_Buzz(5);
//
//			while(
////				   Ping[PING_RIGHT]>=25
//				   ( (Ping[PING_FRONT]<=30) && (Ping[PING_RIGHT]>=15) ) ||
//				   ( (Ping[PING_FRONT]<=30 && Ping[PING_RIGHT]<=15)   )
//				 )
//			{
//				if(Ping[PING_FRONT]<=13 )
//				{
//					mov_bwd(5,FAST);
//				}
//				mov_rot_left(MED,FAR);
//			}
//			while(Ping[PING_ASKEW_RIGHT]<=13)
//			{
//				mov_rot_left(MED,FAR);
//			}
//		}
//
//	}
//}
//
//
//void Escape_Home(void)
//{
//	MID_Sum_Colour();
//	while(TRACER_STAT==1)
//	{
//		MID_Sum_Colour();
//		mov_fwd_5cm(20,FAST_LEVEL_3);
//	}
//
//	MID_Sum_Colour();
//	if(ZONE==ZONE_RED)INITIAL_ZONE=ZONE_RED;
//	else if(ZONE==ZONE_BLUE)INITIAL_ZONE=ZONE_BLUE;
//
//	if(INITIAL_ZONE==ZONE_RED)
//	{
//		Sendto_PC(USART1,"YUME INITIAL ZONE: RED ZONE \r");
//	}
//
//	else if(INITIAL_ZONE==ZONE_BLUE)
//	{
//		Sendto_PC(USART1,"YUME INITIAL ZONE: BLUE ZONE \r");
//	}
//
//}
//
//void Evade_Wall(void)
//{
//	Get_IR();
//
//
//	if( (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) || (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED) )
//	{
//		while( (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED))
//		{
////			Get_IR_Right();
//			Get_IR();
//			mov_deflect_left(MED,FAR);
//		}
//
//		while( (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)  )
//		{
////			Get_IR_Left();
//			Get_IR();
//			mov_deflect_right(MED,FAR);
//		}
//	}
//
//	if(
//		 ( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ) &&
//		 ( (INFRARED[IR_FRONT_MIDDLE]==IR_NOT_DETECTED) || (Ping[PING_FRONT]>= 30) )
//	  )
//	 {
//		Sendto_PC(USART1,"YUME FUNCTION CALL Cat_Avoider in Evade_Wall \r");
//		Cat_Avoider();
//	 }
//	else if(
//			 ((INFRARED[IR_BUMPER_RIGHT]==IR_DETECTED) && (INFRARED[IR_BUMPER_LEFT]==IR_NOT_DETECTED))
//			)
//	{
//		Sendto_PC(USART1,"YUME ROT RIGHT in Evade Wall: IR_FRONT_RIGHT DETECTS OBSTACLE \r");
//		//mov_bwd(5,MED);
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//
//		Get_IR();
//		while( INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED )
//		{
//			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
//	}
//	else if(
//			 ((INFRARED[IR_BUMPER_RIGHT]==IR_DETECTED) && (INFRARED[IR_BUMPER_LEFT]==IR_NOT_DETECTED))
//			)
//	{
//		Sendto_PC(USART1,"YUME ROT LEFT in Evade Wall: IR_FRONT_LEFT DETECTS OBSTACLE \r");
//		//mov_bwd(5,MED);
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//
//		Get_IR();
//		while( INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED )
//		{
//			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//	}
////	else if (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
////	{
////		if(INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED)
////		{
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////		}
////		else if(INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED)
////		{
////			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
////		}
////	}
//
//}
//
//void Evade_Wall_Room(void)
//{
//	Get_IR();
//
//	if( (INFRARED[MID_RIGHT]==IR_DETECTED) || (INFRARED[MID_LEFT]==IR_DETECTED) )
//	{
//		while(INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED)
//		{
//			Get_IR();
////			Get_IR_Right();
////			mov_deflect_left(MED,FAR);
//			mov_deflect_left(MED,FAR);
//		}
//
//		while(INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)
//		{
//			Get_IR();
////			Get_IR_Left();
////			mov_deflect_right(MED,FAR);
//			mov_deflect_right(MED,FAR);
//		}
//	}
//
//}
//
//void Evade_Wall_Room_Blue(void)
//{
//	Get_IR();
//
//	if( (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) || (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED) )
//	{
//		while(INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED)
//		{
//			Get_IR_Right();
//			mov_deflect_left(MED,FAR);
////			mov_deflect_left(MED,FAR);
//		}
//
//		while(INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)
//		{
//			Get_IR_Left();
////			mov_deflect_right(MED,FAR);
//			mov_deflect_right(MED,FAR);
//		}
//	}
//
//	if( (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//		(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//		(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//	  )
//	{
//		Sendto_PC(USART1,"YUME ROT LEFT in Evade Wall: INFRARED DETECTS OBSTACLE \r");
//		//mov_bwd(5,MED);
//		while(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)
//
//
//
//
//		{
//			mov_rotleft_fire(MED,FAR);
//			mov_rotleft_fire(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//	}
//}
//
//void Evade_Wall_Room_Red(void)
//{
//	Get_IR();
//
//	if( (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED) || (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED) )
//	{
//		while(INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED)
//		{
//			Get_IR_Right();
//			mov_deflect_left(MED,FAR);
////			mov_deflect_left(MED,FAR);
//		}
//
//		while(INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)
//		{
//			Get_IR_Left();
////			mov_deflect_right(MED,FAR);
//			mov_deflect_right(MED,FAR);
//		}
//	}
//
//	if( (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//		(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//		(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//	  )
//	{
//		Sendto_PC(USART1,"YUME ROT RIGHT in Evade Wall: INFRARED DETECTS OBSTACLE \r");
//		while(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//		{
//			mov_rotright_fire(MED,FAR);
//			mov_rotright_fire(MED,FAR);
//			Get_IR();
//		}
//	}
//}
//
//
//void YUME_TCS3200_Check(unsigned int tcs3200_mode, unsigned int cross_mode)
//{
//	switch(tcs3200_mode)
//	{
//		case FRONT_TCS3200_MODE:
//		{
//			FRONT_Sum_Colour();
//			F_TRACER= TRACER_STAT;
//			switch(cross_mode)
//			{
//				case CROSS_OFF:
//				{
//					while (ZONE!=INITIAL_ZONE)
//					{
//						FRONT_Sum_Colour();
//						mov_rot_right(MED,FAR);
//						if (Ping[PING_FRONT]>=15)
//						{
//							mov_fwd_5cm(5,MED);
//						}
//					}
//				}break;
//
//				case CROSS_ON:
//				{
//
//				}break;
//			}
//
//		}break;
//
//		case MID_TCS3200_MODE:
//		{
//			MID_Sum_Colour();
//			M_TRACER= TRACER_STAT;
//			switch(cross_mode)
//			{
//				case CROSS_OFF:
//				{
//					while (ZONE!=INITIAL_ZONE)
//					{
//						MID_Sum_Colour();
//						mov_rot_right(MED,FAR);
//						if (Ping[PING_FRONT]>=15)
//						{
//							mov_fwd_5cm(5,MED);
//						}
//					}
//
//				}break;
//
//				case CROSS_ON:
//				{
//
//				}break;
//			}
//
//		}break;
//		default: break;
//	}
//	Sendto_PC(USART1,"TRACER STAT: %d | ZONE : %d | INITIAL_ZONE %d \r",TRACER_STAT, ZONE, INITIAL_ZONE);
//	TRACER_STAT= F_TRACER | M_TRACER;
//}
//
///* func      : void YUME_Tracer_Check(void)
// * brief     : Checking both TCS3200 tracer and applying room-corridor transition
// * param     : N/A
// * retval    : N/A
// * Ver       : 5
// * written By: Ryan (??? Missing record)
// * Revised By: Ryan (Tuesday, November 24th 2015)
// * programmer's Note:
// *
// */
//void YUME_Tracer_Check(void)
//{
//	F_TRACER=0;
//	M_TRACER=0;
//
//    FRONT_Sum_Colour();
//    F_TRACER= TRACER_STAT;
//	MID_Sum_Colour();
//    M_TRACER= TRACER_STAT;
//
//   // Sendto_PC(USART1,"\rTRACER CHECK STATUS - F_TRACER: %d | M_TRACER %d! \r",F_TRACER,M_TRACER);
//
//    //TRACER_STAT= F_TRACER | M_TRACER;
//    CANDLE_CIRCLE_FLAG = F_TRACER && M_TRACER;
//    HOME_CIRCLE_FLAG = F_TRACER && M_TRACER;
//
//
//
//    Get_IR();
//    if( (HOME_CIRCLE_FLAG==HOME_CIRCLE_DETECTED) &&
//    	(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//      )
//    {
//    	Sendto_PC(USART1,"HOME CIRCLE DETECTED! \r");
//
//    	if(RETURN_TRIP_FLAG= RETURN_ENABLED)
//    	{
//    		RETURN_TRIP_FLAG= RETURN_SUCCESS;
//    	}
//    	else if (RETURN_TRIP_FLAG= RETURN_DISABLED)
//    	{
//        	if(Ping[PING_RIGHT]>Ping[PING_LEFT])
//        	{
//        		while(Ping[PING_RIGHT]>Ping[PING_LEFT])
//        		{
//        			mov_rot_right(MED,FAR);
//        			mov_rot_right(MED,FAR);
//        		}
//        	}
//        	else if (Ping[PING_LEFT] > Ping[PING_RIGHT])
//        	{
//        		while (Ping[PING_LEFT] > Ping[PING_RIGHT])
//        		{
//        			mov_rot_left(MED,FAR);
//        			mov_rot_left(MED,FAR);
//        		}
//        	}
//
//        	if(INITIAL_ZONE==ZONE_RED)
//        	{
//        		FollowEvade_HomeCircle_Left(7);
//
//        	}
//        	else if (INITIAL_ZONE==ZONE_BLUE)
//        	{
//        		FollowEvade_HomeCircle_Right(7);
//        	}
//    	}
//
//    }
//
//    else if( (CANDLE_CIRCLE_FLAG==CANDLE_CIRCLE_DETECTED) &&
//    	      (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) &&
//    	      (YUME_FOUND_FIRE_OVERRIDE==1)
//           )
//    	{
//    		//bypass
//    	}
//
//    else if( (CANDLE_CIRCLE_FLAG==CANDLE_CIRCLE_DETECTED) &&
//    	      (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) &&
//    	      (YUME_FOUND_FIRE_OVERRIDE==0)
//           )
//    {
//    	Sendto_PC(USART1,"CANDLE CIRCLE DETECTED! on YUME_Tracer_Check \r");
//
//    	//YUME AVOIDING CANDLE CIRCLE
//    	if (UV_Lock==0)
//    	{
//    		Sendto_PC(USART1,"YUME AVOIDING CANDLE CIRCLE \r");
//
//    		if(Ping[PING_RIGHT]>=Ping[PING_LEFT])
//    		{
//    			while(Ping[PING_FRONT]<=35)
//    			{
//    				mov_rot_right(FAST,FAR);
//    				mov_rot_right(FAST,FAR);
//    				mov_rot_right(FAST,FAR);
//    				mov_rot_right(FAST,FAR);
//    			}
//    		}
//
//    		else if(Ping[PING_LEFT]>Ping[PING_RIGHT])
//    		{
//    			while(Ping[PING_FRONT]<=35)
//    			{
//    				mov_rot_left(FAST,FAR);
//    				mov_rot_left(FAST,FAR);
//    				mov_rot_left(FAST,FAR);
//
//    			}
//    		}
//
////    		while(Ping[PING_FRONT]<=25)
////    		{
////    			if(INITIAL_ZONE==ZONE_BLUE)
////    			{
////        			mov_rot_left(MED,FAR);
////        			mov_rot_left(MED,FAR);
////    			}
////    			else if(INITIAL_ZONE==ZONE_RED)
////    			{
////        			mov_rot_right(MED,FAR);
////        			mov_rot_right(MED,FAR);
////
////    			}
////
////    		}
//    		mov_fwd_5cm(5,FAST);
//    	}
//
//    	//YUME EXTINGUISHING FIRE
//    	else if (UV_Lock==1)
//    	{
//    		YUME_Found_Fire();
//    		//YUME_Found_Fire();
////    		while(UV_Lock==1)
////    		{
////    			YUME_Search_Fire();
////    			mov_rot_right(MED,FAR);
////    			mov_rot_right(MED,FAR);
////    		}
//
//
//    	}
//    	//RESET TRACER STAT
//    	F_TRACER=0;
//    	M_TRACER=0;
//
//    }
//
//
//    else if( (M_TRACER==1) && (YUME_FOUND_FIRE_OVERRIDE==0) )
//	{
//		Sendto_PC(USART1,"\r WHITE LINES DETECTED! \r");
//
////		if	(
////				(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR) &&
////				(FOLLOW_CARPET_FLAG==FOLLOW_CARPET_ENABLED) &&
////				(RETURN_FLAG==RETURN_DISABLED)
////			)
////		{
////			Sendto_PC(USART1,"YUME ESCAPE VARIABLE DOOR TRAP \r");
////			YUME_Buzz(3);
////			YUME_Buzz(3);
////
////			if(INITIAL_ZONE==ZONE_BLUE)
////			{
////
////				Get_IR();
////				while ( (Ping[PING_FRONT]>=30) || ( (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) ) )
////				{
////					mov_rot_right(MED,FAR);
////					mov_rot_right(MED,FAR);
////					mov_rot_right(MED,FAR);
////					Get_IR();
////				}
////
////				Get_IR();
////				while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
////				{
////					mov_rot_right(MED,FAR);
////					mov_rot_right(MED,FAR);
////					mov_rot_right(MED,FAR);
////					Get_IR();
////				}
////
////
////				YUME_Buzz(1);
////				YUME_PID_Init();
////				follow_right_counter(10);
////
////				YUME_Buzz(1);
////				YUME_PID_Init();
////				FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
////			}
////
////			else if (INITIAL_ZONE==ZONE_RED)
////			{
////				Get_IR();
////				while ( (Ping[PING_FRONT]>=30) || ((INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)) )
////				{
////					mov_rot_left(MED,FAR);
////					mov_rot_left(MED,FAR);
////					mov_rot_left(MED,FAR);
////					Get_IR();
////				}
////				Get_IR();
////				while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
////				{
////					mov_rot_left(MED,FAR);
////					mov_rot_left(MED,FAR);
////					mov_rot_left(MED,FAR);
////					Get_IR();
////				}
////
////				YUME_Buzz(1);
////				YUME_PID_Init();
////				follow_left_counter(10);
////
////				YUME_Buzz(1);
////				YUME_PID_Init();
////				FollowCarpet_Left(&COLOUR_RED,&INVERSE);
////			}
////
//////			FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
////		}
//
//		if (RETURN_TRIP_FLAG==RETURN_ENABLED)
//		{
//			mov_fwd_5cm(15,FAST_LEVEL_3);
//		}
//
//		else if ( (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) &&
//		     (UV_Lock==1) &&
//		     (YUME_FOUND_FIRE_OVERRIDE==0)
//		   )
//		{
//			Get_IR();
//			if (Ping[PING_FRONT]<=25 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) )
//			{
//				Sendto_PC(USART1,"YUME FOUND CANDLE CIRCLE! on YUME_Tracer_Check \r");
//	    		while(UV_Lock==1)
//	    		{
//	    			YUME_Search_Fire();
//	    			mov_rot_right(MED,FAR);
//	    			mov_rot_right(MED,FAR);
//	    		}
//			}
//			else
//			{
//				ReturnTo_Room();
//		    	//RESET TRACER STAT
//		    	F_TRACER=0;
//		    	M_TRACER=0;
//			}
//		}
//
//
//		else if ( (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR) &&
//				  ( (Ping[PING_FRONT]<=30) && ( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ) )
//		        )
//		{
//	    	if(Ping[PING_RIGHT]>Ping[PING_LEFT])
//	    	{
//	    		while(Ping[PING_RIGHT]>Ping[PING_LEFT])
//	    		{
//	    			mov_rot_right(MED,FAR);
//	    			mov_rot_right(MED,FAR);
//	    		}
//	    	}
//	    	else if (Ping[PING_LEFT] > Ping[PING_RIGHT])
//	    	{
//	    		while (Ping[PING_LEFT] > Ping[PING_RIGHT])
//	    		{
//	    			mov_rot_left(MED,FAR);
//	    			mov_rot_left(MED,FAR);
//	    		}
//	    	}
//
//			Get_IR();
//			Sendto_PC(USART1,"YUME AVOIDING HOME CIRCLE \r");
//		    if(INITIAL_ZONE==ZONE_RED)
//		    {
//		    	FollowEvade_HomeCircle_Left(7);
//		    }
//		    else if (INITIAL_ZONE==ZONE_BLUE)
//		    {
//		    	FollowEvade_HomeCircle_Right(7);
//		    }
//
//
//		}
//
//		else if (
//					(YUME_CROSSING_AUTHORITY==CROSS_ENABLED) &&
//					(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//				)
//		{
//			YUME_Buzz(1);
//			YUME_CROSSING_STATUS=CROSSING_SUCCESS;
//
//			mov_fwd_5cm(10,FAST);
//			YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//			if(YUME_CROSSING_AUTHORITY==CROSS_DISABLED)
//			{
//				YUME_Buzz(2);
//				delay_ms(500);
//				YUME_Buzz(2);
//			}
//
//
//			if(YUME_CROSSING_STATUS==CROSSING_SUCCESS)
//			{
//				YUME_Buzz(4);
//			}
//			Sendto_PC(USART1,"CROSSING SUCCESS! \r");
//			Sendto_PC(USART1,"YUME_CROSSING_AUTHORITY: %d \r",YUME_CROSSING_AUTHORITY);
//			Sendto_PC(USART1,"YUME_CROSSING_STATUS: %d \r",YUME_CROSSING_STATUS);
//		}
//
//		else
//		{
//			Sendto_PC(USART1,"\rYUME Location BEFORE \r");
//			Send_Location();
//			YUME_LOCATION[LAST_LOC]= YUME_LOCATION[PRESENT_LOC];
//			YUME_LOCATION[PRESENT_LOC]= LOCATION_ROOM;
//
//			Sendto_PC(USART1,"\rYUME Location Estimator \r");
//			Send_Location();
//
//			if( (YUME_LOCATION[LAST_LOC]== LOCATION_CORRIDOR) && (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) )
//			{
//				YUME_LOCATION[PRESENT_LOC]=LOCATION_ROOM;
//				Sendto_PC(USART1,"YUME FOUND A ROOM! \r");
//				mov_fwd_5cm(10,FAST_LEVEL_3);
//			}
//			else if( (YUME_LOCATION[LAST_LOC]== LOCATION_ROOM) && (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) )
//			{
//				YUME_LOCATION[PRESENT_LOC]=LOCATION_CORRIDOR;
//				Sendto_PC(USART1,"YUME FOUND A CORRIDOR! \r");
//				//Evade_Wall();
//				Evade_Wall_Room();
//				mov_fwd_5cm(30,FAST_LEVEL_3);
////				Evade_Wall_Room();
//			}
//
//
//			Send_Location ();
//	    	//RESET TRACER STAT
//	    	F_TRACER=0;
//	    	M_TRACER=0;
//		}
//
//    	//RESET TRACER STAT
//    	F_TRACER=0;
//    	M_TRACER=0;
//	}
//
//}
//
///* func      : void Zone_Check (unsigned int INITIAL_ZONE)
// * brief     : Checking current zone and correcting its deviations
// * param     : unsigned int INITIAL_ZONE (ZONE_RED=2, ZONE_BLUE=3)
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void Zone_Check(unsigned int *INITIAL_ZONE)
//{
//	FRONT_Sum_Colour();
//	while (ZONE!= *INITIAL_ZONE)
//	{
//		FRONT_Sum_Colour();
//		mov_rot_right(MED,FAR);
//		if (Ping[PING_FRONT]>=25)
//		{
//			mov_fwd_5cm(5,MED);
//		}
//	}
//}
//
//
//void YUME_Success(void)
//{
//	while(1)
//	{
//		YUME_Buzz(4);
//		mov_static();
//		delay_ms(200);
//	}
//}
//
//void YUME_RedFighter(void)
//{
//	YUME_Initial_Setup(rot_switch_mode);
//	Sendto_PC(USART1,"\r YUME READY TO FIGHT!!! \r");
//	Sendto_PC(USART1,"YUME RED FIGHTER! \r");
//	INITIAL_ZONE=ZONE_RED;
//
//
//	while(1)
//	{
//
////====================================YUME DEFAULT ROUTINES=====================================//
//		//PING_FRONT FAILCHECK
//		while(Ping[PING_FRONT]==0)
//		{
//			YUME_Buzz(1);
//			delay_ms(100);
//		}
//
//		Sendto_PC(USART1,"\r YUME BLUE FIGHTER WHILE INFINITE LOOP \r");
//
//		Home_Detection_Red();
//
//		YUME_Buzz(4);
//		Escape_Home();
//		Evade_Wall();
////==============================================================================================//
//
//
///*/=============================================================================================//
///*//* 						    YUME NON ARBITRARY START ROUTINES								*/
///*/=============================================================================================*/
//		//YUME NON ARBITRARY START (HOME == SC)
//		if (M_DETECTED_COLOUR==COLOUR_RED)
//		{
//			RedFighter_Non_Arbitrary();
//		}
//
///*/=============================================================================================//
///*//* 						       YUME ARBITRARY START ROUTINES								*/
///*/=============================================================================================*/
//		//YUME ARBITRARY ZONE (HOME == ROOM)
//		else if (M_DETECTED_COLOUR==COLOUR_BLACK)
//		{
//			RedFighter_Arbitrary();
//		}
//
///*/=============================================================================================//
///*//*///////////////////////////////////////////////////////////////////////////////////////////*/
///*/=============================================================================================*/
//
//	}
//}
//
//
//void RedFighter_Non_Arbitrary(void)
//{
//	//DEFAULT CROSSING AUTHORITY
//	YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//	YUME_LOCATION[PRESENT_LOC]=LOCATION_CORRIDOR;
//	YUME_Buzz(2);
//	YUME_Buzz(2);
//	Sendto_PC(USART1,"\r YUME NON ARBITRARY START\r");
//
//	Cat_Avoider();
//
//	Sendto_PC(USART1,"YUME IN RED ZONE \r");
//	Sendto_PC(USART1,"YUME FOLLOW TRACER RIGHT RULE! \r");
//
//	YUME_PID_Init();
//	CAT_SHIFT_FOLLOW=NO_SHIFT;
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		YUME_PID_Init();
//		follow_right_new();
//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//	}
//	CAT_SHIFT_FOLLOW=NO_SHIFT;
//
//	//YUME FOUND A CAT!
//	//HALLWAY SC -> ROOM 4
//	if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//	{
//		YUME_Buzz(3);
//		CAT_SHIFT_FOLLOW=NO_SHIFT;
//		while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//		{
//			CAT_SHIFT_FOLLOW=NO_SHIFT;
//			Sendto_PC(USART1,"\rYUME FOUND A CAT! SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
//			Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//			YUME_PID_Init();
//			follow_right_new();
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		}
//		CAT_SHIFT_FOLLOW=NO_SHIFT;
//	}
//
//	YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
//
//
//	while(1)
//	{
//
////====================================YUME ROOM ROUTINES========================================//
//
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//			YUME_Buzz(4);
//			ROOM_COUNTER++;
//			while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//			{
//				Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//				YUME_ROOM();
//				if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//			}
//
//			if(EXTINGUISHED_FIRE>=1)
//			{
//				if( (YUME_CROSSING_STATUS!=CROSSING_SUCCESS) &&
//				    (FIRST_CAT_ENCOUNTER==CAT_NOT_DETECTED)
//				  )
//				{
//					YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
//				}
//			}
//		}
//
////==============================================================================================//
//
//
////=================================YUME CORRIDOR ROUTINES=======================================//
//
////				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
////				{
//			Sendto_PC(USART1,"\r YUME SWITCH LOCATION TO: CORRIDOR \r");
////			Evade_Wall();
//			ROOM_FLAG[PREVIOUS_ROOM]=ROOM_FLAG[PRESENT_ROOM];
//
//				//COUNTERMEASURE AFTER ESCAPE WARZONE -- DESTINATION ROOM 1
//				if(WARZONE_FLAG==1)
//				{
//					YUME_Buzz(2);
//					YUME_Buzz(2);
//					WARZONE_FLAG=0;
//					Sendto_PC(USART1,"PRESENT WARZONE_FLAG: %d \r",WARZONE_FLAG);
//
//					ROOM_FLAG[PRESENT_ROOM]=WARZONE;
//					Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//					Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
////					//WARZONE -> ROOM 4
////					if(Ping[PING_FRONT]<=50)
////					{
////						Get_IR();
////						while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
////						{
////							mov_rot_left(MED,FAR);
////							mov_rot_left(MED,FAR);
////							mov_rot_left(MED,FAR);
////							Get_IR();
////						}
////
////						YUME_Buzz(4);
////						Sendto_PC(USART1,"\rYUME ESCAPE VARIABLE DOOR INFINITE LOOP! \r");
////
////						YUME_Buzz(1);
////						Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL RED FLOOR DETECTED \r");
////						YUME_PID_Init();
////						FollowCarpet_Left(&COLOUR_RED,&INVERSE);
////						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
////
////						YUME_Buzz(1);
////						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK FLOOR DETECTED \r");
////						YUME_PID_Init();
////						FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
////						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
////
////						YUME_Buzz(1);
////						//NORMAL FOLLOW UNTIL TRACER
////						CAT_SHIFT_FOLLOW=NO_SHIFT;
////						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
////						{
////							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
////							YUME_PID_Init();
////							followtracer_left();
////							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////						}
////
////						//YUME FOUND A CAT!
////						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
////						{
////							YUME_Buzz(3);
////							YUME_PID_Init();
////							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
////							{
////								CAT_SHIFT_FOLLOW=NO_SHIFT;
////								Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
////								Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
////								YUME_PID_Init();
////								follow_right_new();
////								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////							}
////							CAT_SHIFT_FOLLOW=NO_SHIFT;
////						}
////					}
//
//					if(Ping[PING_FRONT]<=50)
//					{
//						YUME_Buzz(3);
//						VARIABLE_DOOR=VAR_DOOR_DETECTED;
//					}
//					//WARZONE -> ROOM 1 GATE B
//					else
//					{
////						YUME_Buzz(1);
//						VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//
//					}
//
//					YUME_Buzz(1);
//
//					//WARZONE -> ROOM 1 GATE B
////					else
////					{
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=0;
//							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							follow_right_new();
////							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
////					}
//
//				}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//				//COUNTERMEASURE FOR ROOM 1 GATE B
//				else if( (Ping[PING_LEFT]<=30) && (Ping[PING_ASKEW_LEFT]<=30) )
//				{
//					YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//					ROOM_FLAG[PRESENT_ROOM]=ROOM_ONE;
//					Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//					Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//					YUME_Buzz(3);
//					Sendto_PC(USART1,"YUME IN FRONT OF ROOM 1 GATE B\r");
////					mov_fwd_5cm(5,FAST_LEVEL_3);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
////					mov_rot_right(MED,FAR);
//
//					for(global_counter=0;global_counter<=6;global_counter++)
//					{
//						Get_IR();
//						if( (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//							(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//							(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//						  )
//						{
//							mov_rot_right(MED,FAR);
//							mov_rot_right(MED,FAR);
//							Get_IR();
//						}
//						mov_fwd_5cm(5,FAST_LEVEL_3);
//					}
//
//
//					//YUME ROOM 1 GATE B -> ROOM 3
//					if(
//						(ROOM_COUNTER<=2) ||
//						(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//					  )
//					{
//						YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//						SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_DISABLED;
//						YUME_Buzz(2);
//						YUME_Buzz(2);
//						Sendto_PC(USART1,"ROOM 1 -> ROOM 3 \r");
//
//						YUME_Buzz(1);
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL RED CARPET DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_RED,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(1);
//						Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLACK FLOOR DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(3);
//						//NORMAL FOLLOW UNTIL TRACER
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							follow_right_new();
////							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//					}
//
//
//					//YUME ROOM 1 GATE B -> ROOM 4
//					else if (
//							  (ROOM_COUNTER>2) || (VARIABLE_DOOR==VAR_DOOR_DETECTED)
//						    )
//					{
//
//						YUME_CROSSING_STATUS=CROSS_DISABLED;
//						VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//
//
//						YUME_Buzz(1);
//						Send_TCS3200_Status();
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL RED CARPET DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_RED,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(1);
//						Send_TCS3200_Status();
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK FLOOR DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(1);
//						//NORMAL FOLLOW UNTIL TRACER
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
////							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							followtracer_left();
//							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//						//YUME FOUND A CAT!
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//						{
//							YUME_Buzz(3);
//							YUME_PID_Init();
//							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//							{
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
//								Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//								YUME_PID_Init();
//								follow_right_new();
//								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							}
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//						}
//
//					}
//
//				}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//				//APPLIED FOR ALL ROOMS OTHER THAN ROOM 1
//				else
//				{
//					Sendto_PC(USART1,"\rYUME OTHER ROOM \r");
//					YUME_Buzz(2);
//
//					ROOM_FLAG[PRESENT_ROOM]=OTHER_ROOM;
//					Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//					Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//
//					//ROOM 3 -> CROSSING ZONE -> WARZONE
//					if(
//							( (Ping[PING_ASKEW_RIGHT]>40) || (Ping[PING_RIGHT]>40) ) &&
//							(YUME_CROSSING_AUTHORITY==CROSS_ENABLED)
//					  )
//					{
//						YUME_Buzz(3);
//						Sendto_PC(USART1,"YUME ROOM 3 -> CROSSING ZONE -> WARZONE \r");
//
//
//						while( (Ping[PING_FRONT]<=30) )
//						{
//							mov_rot_right(MED,FAR);
//						}
//
//
//						//FOLLOW UNTIL DETECT BORDERLINE
//						YUME_PID_Init();
//						FollowCrossing_Left();
//
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS)
//						{
//							YUME_Buzz(2);
//							Sendto_PC(USART1,"YUME CROSSING TO BLUEZONE! \r");
//							YUME_CrossingTo_BlueZone();
//						}
//
//						else if(YUME_CROSSING_STATUS==CROSSING_FAILED)
//						{
//							YUME_Buzz(1);
////							mov_fwd_5cm(20,FAST);
//							ReturnTo_RedZone();
//						}
//
//						YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							follow_right_new();
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//
//					}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					//SPECIAL CONDITION
//					else if (
//								(FIRST_CAT_ENCOUNTER==CAT_DETECTED) ||
//								(
//										(ROOM_FLAG[PREVIOUS_ROOM]==OTHER_ROOM) &&
//										(ROOM_FLAG[PRESENT_ROOM]==OTHER_ROOM) &&
//										(CAT_FOUND[CAT_PRESENT]>=1) &&
////										(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//										(SPECIAL_CONDITION_COUNTER>=1)
//								)
//							)
//					{
//						Sendto_PC(USART1,"\rYUME SPECIAL CONDITION TRIGGERED!\r");
//						CAT_FOUND[CAT_PREVIOUS]=0;
//						CAT_FOUND[CAT_PRESENT]=0;
//						SPECIAL_CONDITION_COUNTER=0;
//						FIRST_CAT_ENCOUNTER=CAT_NOT_DETECTED;
//						SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_ENABLED;
//
//						YUME_Buzz(3);
//						YUME_Buzz(3);
//						mov_rot_right(MED,FAR);
//						mov_rot_right(MED,FAR);
//						mov_rot_right(MED,FAR);
//						mov_rot_right(MED,FAR);
//
//						Get_IR();
//						while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//						{
//							mov_rot_right(MED,FAR);
//							mov_rot_right(MED,FAR);
//							Get_IR();
//						}
//
//						mov_fwd_5cm(20,FAST_LEVEL_3);
//
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_RED,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							YUME_PID_Init();
//							followtracer_left();
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//					}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//					else
//					{
//						if(CAT_FOUND[CAT_PRESENT]>=1)
//						{
////							CAT_FOUND[CAT_PREVIOUS]=0;
////							CAT_FOUND[CAT_PRESENT]=0;
//							SPECIAL_CONDITION_COUNTER++;
//						}
//
//						YUME_Buzz(2);
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//
//						Get_IR();
//						while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//						{
//							mov_rot_left(MED,FAR);
//							Get_IR();
//						}
//
//						Evade_Wall();
//						mov_fwd_5cm(15,FAST);
//						Send_Location();
//						Send_TCS3200_Status();
//
//						//ROOM 1 DOOR A -> ROOM 3
//						if (
//								(ROOM_COUNTER==2) ||
//								(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//							)
//						{
//							Sendto_PC(USART1,"\rSPECIAL CONDITION ROOM 1 DOOR B -> ROOM 3\r");
//							SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_DISABLED;
//
//							YUME_Buzz(3);
//							YUME_Buzz(3);
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL RED CARPET DETECTED \r");
//							YUME_PID_Init();
//							FollowCarpet_Left(&COLOUR_RED,&INVERSE);
//							FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//							YUME_Buzz(3);
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLACK CARPET DETECTED \r");
//							YUME_PID_Init();
//							FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//							FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//							YUME_Buzz(3);
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL RED CARPET DETECTED \r");
//							YUME_PID_Init();
//							FollowCarpet_Left(&COLOUR_RED,&INVERSE);
//							FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//							YUME_Buzz(3);
//							mov_rot_right(MED,FAR);
//							mov_rot_right(MED,FAR);
//
//							for(global_counter=0;global_counter<=12;global_counter++)
//							{
//								Get_IR();
//								if( (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//									(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//									(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//								  )
//								{
//									mov_rot_right(MED,FAR);
//									mov_rot_right(MED,FAR);
//									Get_IR();
//								}
//								mov_fwd_5cm(5,FAST_LEVEL_3);
//							}
//
//
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//							{
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//								YUME_PID_Init();
//								follow_right_new();
//								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							}
//
//						}
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//						//DEFAULT ALGORITHM
//						//ROOM 3 -> WARZONE
//						//ROOM 4 -> ROOM 3
//						//ROOM 1 GATE B -> ROOM 4
//						else
//						{
//							YUME_Buzz(3);
//
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL RED CARPET DETECTED \r");
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							YUME_PID_Init();
//							FollowCarpet_Left(&COLOUR_RED,&INVERSE);
//
//							YUME_Buzz(1);
//							Send_TCS3200_Status();
//
////							//ESCAPE FROM VARIABLE DOOR TRAP
////							if(FOLLOW_CARPET_FLAG==FOLLOW_CARPET_ENABLED)
////							{
////								YUME_Buzz(4);
////
////								Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK CARPET DETECTED \r");
////								CAT_SHIFT_FOLLOW=NO_SHIFT;
////								YUME_PID_Init();
////								FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
////								YUME_Buzz(4);
////							}
////							FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//							{
////								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//								YUME_PID_Init();
//								follow_right_new();
//								if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							}
//
//							//YUME FOUND A CAT!
//							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//							{
//								YUME_Buzz(3);
//								YUME_PID_Init();
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//								{
//									CAT_SHIFT_FOLLOW=NO_SHIFT;
//									Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER LEFT\r");
//									Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//									YUME_PID_Init();
//									followtracer_left();
//									if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//								}
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//							}
//						}
//					}
//				}
////==============================================================================================//
//	}
//}
//
//
//void RedFighter_Arbitrary(void)
//{
//
//
//	YUME_Buzz(3);
//	Sendto_PC(USART1,"\r YUME ARBITRARY START! \r");
//
//	YUME_LOCATION[PRESENT_LOC]=LOCATION_ROOM;
//
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		YUME_PID_Init();
//		FollowExit_Right();
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//	ROOM_COUNTER++;
//
//	//DEFAULT CROSSING AUTHORITY
//	YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
//
//
//
//	while(1)
//	{
//
//		//=================================YUME CORRIDOR ROUTINES=======================================//
//		Sendto_PC(USART1,"\r YUME SWITCH LOCATION TO: CORRIDOR \r");
////		Evade_Wall();
//		ROOM_FLAG[PREVIOUS_ROOM]=ROOM_FLAG[PRESENT_ROOM];
//
//		//COUNTERMEASURE AFTER ESCAPE WARZONE -- DESTINATION ROOM 1
//		if(WARZONE_FLAG==1)
//		{
//			YUME_Buzz(2);
//			YUME_Buzz(2);
//			WARZONE_FLAG=0;
//			Sendto_PC(USART1,"PRESENT WARZONE_FLAG: %d \r",WARZONE_FLAG);
//
//			ROOM_FLAG[PRESENT_ROOM]=WARZONE;
//			Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//			Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//			if(Ping[PING_FRONT]<=50)
//			{
//				YUME_Buzz(3);
//				VARIABLE_DOOR=VAR_DOOR_DETECTED;
//			}
//			//WARZONE -> ROOM 1 GATE B
//			else
//			{
////						YUME_Buzz(1);
//				VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//			}
//
//				//WARZONE -> ROOM 1 GATE B
//				CAT_SHIFT_FOLLOW=NO_SHIFT;
//				while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//				{
//					CAT_SHIFT_FOLLOW=0;
//					Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//					YUME_PID_Init();
//					follow_right_new();
////					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//		}
///////////////////////////////////////////////////////////////////////////////////////////////
//
//		//COUNTERMEASURE FOR ROOM 1 GATE B
//		else if( (Ping[PING_LEFT]<=30) && (Ping[PING_ASKEW_LEFT]<=30) )
//		{
//			ROOM_FLAG[PRESENT_ROOM]=ROOM_ONE;
//			Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//			Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//			YUME_Buzz(3);
//			Sendto_PC(USART1,"YUME IN FRONT OF ROOM 1 GATE B\r");
////			mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
//
//			for(global_counter=0;global_counter<=6;global_counter++)
//			{
//				Get_IR();
//				if(
//					(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//					(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//					(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//					)
//
//				{
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					Get_IR();
//				}
//
//				mov_fwd_5cm(5,FAST_LEVEL_3);
//			}
//
//			//YUME ROOM 1 GATE B -> ROOM 3
//			if(
//					(ROOM_COUNTER<=2) ||
//					(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//			   )
//
//			{
//				YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//				SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_DISABLED;
//				YUME_Buzz(2);
//				YUME_Buzz(2);
//				Sendto_PC(USART1,"ROOM 1 -> ROOM 3 \r");
//
//				YUME_Buzz(1);
//				Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL RED CARPET DETECTED \r");
//				YUME_PID_Init();
//				FollowCarpet_Right(&COLOUR_RED,&INVERSE);
//				FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//				YUME_Buzz(1);
//				Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLACK FLOOR DETECTED \r");
//				YUME_PID_Init();
//				FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//				FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//				YUME_Buzz(3);
//				//NORMAL FOLLOW UNTIL TRACER
//				CAT_SHIFT_FOLLOW=NO_SHIFT;
//				while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//				{
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//					YUME_PID_Init();
//					follow_right_new();
////					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//			}
//
//
//			//YUME ROOM 1 GATE B -> ROOM 4
//			else if (
//						(ROOM_COUNTER>2) || (VARIABLE_DOOR==VAR_DOOR_DETECTED)
//					)
//			{
//				YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//				VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//
//
//				YUME_Buzz(3);
//				Send_TCS3200_Status();
//				Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL RED CARPET DETECTED \r");
//				YUME_PID_Init();
//				FollowCarpet_Right(&COLOUR_RED,&INVERSE);
//				FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//				YUME_Buzz(3);
//				Send_TCS3200_Status();
//				Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK FLOOR DETECTED \r");
//				YUME_PID_Init();
//				FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//				FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//				YUME_Buzz(3);
//				//NORMAL FOLLOW UNTIL TRACER
//				CAT_SHIFT_FOLLOW=NO_SHIFT;
//				while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//				{
////					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//					YUME_PID_Init();
//					followtracer_left();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//				//YUME FOUND A CAT!
//				if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//				{
//					YUME_Buzz(3);
//					YUME_PID_Init();
//					while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//					{
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
//						Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//						YUME_PID_Init();
//						follow_right_new();
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//
//				}
//
//			}
//
//		}
//
///////////////////////////////////////////////////////////////////////////////////////////////
//
//
//		//APPLIED FOR ALL ROOMS OTHER THAN ROOM 1
//		else
//		{
//			Sendto_PC(USART1,"\rYUME OTHER ROOM \r");
//			YUME_Buzz(2);
//
//			ROOM_FLAG[PRESENT_ROOM]=OTHER_ROOM;
//			Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//			Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//			//VARIABLE DOOR FLAG
//			VARIABLE_DOOR= VAR_DOOR_SCAN;
//
//			//ROOM 3 -> CROSSING ZONE -> WARZONE
//			if(
//					( (Ping[PING_ASKEW_RIGHT]>40) || (Ping[PING_RIGHT]>40) ) &&
//					(YUME_CROSSING_AUTHORITY==CROSS_ENABLED)
//			  )
//
//			{
//				YUME_Buzz(3);
//				Sendto_PC(USART1,"YUME ROOM 3 -> CROSSING ZONE -> WARZONE \r");
//
//				while( (Ping[PING_FRONT]<=25) )
//				{
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//				}
//
//
//				//FOLLOW UNTIL DETECT BORDERLINE
//				YUME_PID_Init();
//				FollowCrossing_Left();
//				Evade_Wall();
//
//				if(YUME_CROSSING_STATUS==CROSSING_SUCCESS)
//				{
//					YUME_Buzz(2);
//					Sendto_PC(USART1,"YUME CROSSING TO BLUEZONE! \r");
//					YUME_CrossingTo_BlueZone();
//				}
//
//				else if(YUME_CROSSING_STATUS==CROSSING_FAILED)
//				{
//					YUME_Buzz(1);
////					mov_fwd_5cm(20,FAST);
//					ReturnTo_RedZone();
//				}
//
//				YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//				YUME_Buzz(1);
//				CAT_SHIFT_FOLLOW=NO_SHIFT;
//				while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//				{
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//					YUME_PID_Init();
//					follow_right_new();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//				//ANTICIPATION FOR ARBITRARY START IN ROOM 4
//				//CAT ON SC
//				//ROOM 4 -> SC -> DETECT CAT (SHIFT FOLLOW) -> ROOM 1 GATE A
//
//				//YUME FOUND A CAT!
//				if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//				{
//					YUME_Buzz(1);
//					YUME_PID_Init();
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//					{
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER LEFT\r");
//						Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//						YUME_PID_Init();
//						followtracer_left();
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//				}
//
//
//			 }
//		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//			//SPECIAL CONDITION
//			else if (
//						(FIRST_CAT_ENCOUNTER==CAT_DETECTED) ||
//						(
//							(ROOM_FLAG[PREVIOUS_ROOM]==OTHER_ROOM) &&
//							(ROOM_FLAG[PRESENT_ROOM]==OTHER_ROOM) &&
//							(CAT_FOUND[CAT_PRESENT]>=1) &&
////							(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//							(SPECIAL_CONDITION_COUNTER>=1)
//						)
//					)
//
//			{
//				Sendto_PC(USART1,"\rYUME SPECIAL CONDITION TRIGGERED!\r");
//				CAT_FOUND[CAT_PREVIOUS]=0;
//				CAT_FOUND[CAT_PRESENT]=0;
//				SPECIAL_CONDITION_COUNTER=0;
//				FIRST_CAT_ENCOUNTER=CAT_NOT_DETECTED;
//				SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_ENABLED;
//
//				YUME_Buzz(3);
//				YUME_Buzz(3);
//
//				mov_rot_right(MED,FAR);
//				mov_rot_right(MED,FAR);
//				mov_rot_right(MED,FAR);
//				mov_rot_right(MED,FAR);
//
//				Get_IR();
//				while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//				{
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					Get_IR();
//				}
//
//				mov_fwd_5cm(20,FAST_LEVEL_3);
//
//				YUME_PID_Init();
//				FollowCarpet_Right(&COLOUR_RED,&INVERSE);
//				FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//				YUME_PID_Init();
//				FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//				FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//				while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//				{
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					YUME_PID_Init();
//					followtracer_left();
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//			}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////
//
//			else
//			{
//				if(CAT_FOUND[CAT_PRESENT]>=1)
//				{
////					CAT_FOUND[CAT_PREVIOUS]=0;
////					CAT_FOUND[CAT_PRESENT]=0;
//					SPECIAL_CONDITION_COUNTER++;
//				}
//
//				YUME_Buzz(2);
//				mov_rot_left(MED,FAR);
//				mov_rot_left(MED,FAR);
//				mov_rot_left(MED,FAR);
//				mov_rot_left(MED,FAR);
//
//				Get_IR();
//				while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//				{
//					mov_rot_left(MED,FAR);
//					Get_IR();
//				}
//
//				Evade_Wall();
//				mov_fwd_5cm(15,FAST);
//				Send_Location();
//				Send_TCS3200_Status();
//
//				//ROOM 1 DOOR A -> ROOM 3
//				if (
//						(ROOM_COUNTER==3) ||
//						(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//					)
//
//				{
//					Sendto_PC(USART1,"\rSPECIAL CONDITION ROOM 1 DOOR B -> ROOM 3\r");
//					SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_DISABLED;
//
//					YUME_Buzz(3);
//					YUME_Buzz(3);
//					Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL RED CARPET DETECTED \r");
//					YUME_PID_Init();
//					FollowCarpet_Left(&COLOUR_RED,&INVERSE);
//					FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//					YUME_Buzz(1);
//					Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLACK CARPET DETECTED \r");
//					YUME_PID_Init();
//					FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//					FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//					YUME_Buzz(1);
//					Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL RED CARPET DETECTED \r");
//					YUME_PID_Init();
//					FollowCarpet_Left(&COLOUR_RED,&INVERSE);
//					FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//
//					//CROSSING THE CROSSROAD
//					YUME_Buzz(3);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//
//					for(global_counter=0;global_counter<=12;global_counter++)
//					{
//						Get_IR();
//						if(
//							(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//							(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//							(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//						   )
//						{
//							mov_rot_right(MED,FAR);
//							mov_rot_right(MED,FAR);
//							Get_IR();
//						}
//
//						mov_fwd_5cm(5,FAST_LEVEL_3);
//					}
//
//
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//					{
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//						YUME_PID_Init();
//						follow_right_new();
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//				}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////
//
//				//DEFAULT ALGORITHM
//				//ROOM 3 -> WARZONE
//				//ROOM 4 -> ROOM 3
//				//ROOM 1 GATE B -> ROOM 4
//
//				else
//				{
//					YUME_Buzz(3);
//
//					Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL RED CARPET DETECTED \r");
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					YUME_PID_Init();
//					FollowCarpet_Left(&COLOUR_RED,&INVERSE);
//
//					YUME_Buzz(1);
//					Send_TCS3200_Status();
//
////					//ESCAPE FROM VARIABLE DOOR TRAP
////					if(FOLLOW_CARPET_FLAG==FOLLOW_CARPET_ENABLED)
////					{
////						YUME_Buzz(4);
////
////						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK CARPET DETECTED \r");
////						CAT_SHIFT_FOLLOW=NO_SHIFT;
////						YUME_PID_Init();
////						FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
////						YUME_Buzz(4);
////					}
////					FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//					{
////						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//						YUME_PID_Init();
//						follow_right_new();
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//					//YUME FOUND A CAT!
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//					{
//						YUME_Buzz(3);
//						YUME_PID_Init();
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER LEFT\r");
//							Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//							YUME_PID_Init();
//							followtracer_left();
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//					}
//				}
//			}
//		}
////==============================================================================================//
//
//
////=====================================YUME ROOM ROUTINES=======================================//
//
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//			YUME_Buzz(4);
//			ROOM_COUNTER++;
//
//			while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//			{
//				Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//				YUME_ROOM();
//				if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//			}
//
//			if(EXTINGUISHED_FIRE>=1)
//			{
//				if( (YUME_CROSSING_STATUS!=CROSSING_SUCCESS) &&
//				    (FIRST_CAT_ENCOUNTER==CAT_NOT_DETECTED)
//				  )
//				{
//					YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
//				}
//			}
//		}
//
////==============================================================================================//
//	}
//}
//
//
//void YUME_BlueFighter(void)
//{
//	YUME_Initial_Setup(rot_switch_mode);
//	Sendto_PC(USART1,"\r YUME READY TO FIGHT!!! \r");
//	Sendto_PC(USART1,"YUME BLUE FIGHTER! \r");
//	INITIAL_ZONE=ZONE_BLUE;
//
//
//	while(1)
//	{
//
////====================================YUME DEFAULT ROUTINES=====================================//
//		//PING_FRONT FAILCHECK
//		while(Ping[PING_FRONT]==0)
//		{
//			YUME_Buzz(1);
//			delay_ms(1000);
//		}
//
//		Sendto_PC(USART1,"\r YUME BLUE FIGHTER WHILE INFINITE LOOP \r");
//
//		Home_Detection_Blue();
//
//		YUME_Buzz(1);
//		Escape_Home();
//		Evade_Wall();
//
////==============================================================================================//
//
//
///*/=============================================================================================//
///*//* 						    YUME NON ARBITRARY START ROUTINES								*/
///*/=============================================================================================*/
//		//YUME NON ARBITRARY START (HOME == SC)
//		if (M_DETECTED_COLOUR==COLOUR_BLUE)
//		{
//			BlueFighter_Non_Arbitrary();
//		}
//
///*/=============================================================================================//
///*//* 						       YUME ARBITRARY START ROUTINES								*/
///*/=============================================================================================*/
//		//YUME ARBITRARY ZONE (HOME == ROOM)
//		else if (M_DETECTED_COLOUR==COLOUR_BLACK)
//		{
//			BlueFighter_Arbitrary();
//		}
//
///*/=============================================================================================//
///*//*///////////////////////////////////////////////////////////////////////////////////////////*/
///*/=============================================================================================*/
//
//	}
//}
//
//
//void BlueFighter_Non_Arbitrary(void)
//{
//	//DEFAULT CROSSING AUTHORITY
//	YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//
//	YUME_LOCATION[PRESENT_LOC]=LOCATION_CORRIDOR;
//	YUME_Buzz(2);
//	YUME_Buzz(2);
//
//	Sendto_PC(USART1,"\r YUME NON ARBITRARY START\r");
//
//	Cat_Avoider();
//
//	Sendto_PC(USART1,"YUME IN BLUE ZONE \r");
//	Sendto_PC(USART1,"YUME FOLLOW LEFT RULE! \r");
//
//	CAT_SHIFT_FOLLOW=NO_SHIFT;
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		YUME_PID_Init();
//		followtracer_left();
//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//	}
//
//	//YUME FOUND A CAT!
//	if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//	{
//		YUME_Buzz(3);
//		CAT_SHIFT_FOLLOW=NO_SHIFT;
//		while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//		{
//			CAT_SHIFT_FOLLOW=NO_SHIFT;
//			Sendto_PC(USART1,"\rYUME FOUND A CAT! SHIFT ALGORITHM TO FOLLOWTRACER LEFT\r");
//			Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//			YUME_PID_Init();
//			followtracer_left();
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		}
//		CAT_SHIFT_FOLLOW=NO_SHIFT;
//	}
//
//	YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
//
//
//	while(1)
//	{
//
////====================================YUME ROOM ROUTINES========================================//
//
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//			YUME_Buzz(4);
//
//			ROOM_COUNTER++;
//			while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//			{
//				Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//				YUME_ROOM();
//				if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//			}
//			if(EXTINGUISHED_FIRE>=1)
//			{
//				if( (YUME_CROSSING_STATUS!=CROSSING_SUCCESS) &&
//				    (FIRST_CAT_ENCOUNTER==CAT_NOT_DETECTED)
//				  )
//				{
//					YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
//				}
//			}
////			if(YUME_CROSSING_STATUS!=CROSSING_SUCCESS)
////			{
////				YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
////			}
//
//		}
//
//
////==============================================================================================//
//
//
////=================================YUME CORRIDOR ROUTINES=======================================//
//
////				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
////				{
//			Sendto_PC(USART1,"\r YUME SWITCH LOCATION TO: CORRIDOR \r");
////			Evade_Wall();
//			ROOM_FLAG[PREVIOUS_ROOM]=ROOM_FLAG[PRESENT_ROOM];
//
//				//COUNTERMEASURE AFTER ESCAPE WARZONE -- DESTINATION ROOM 1
//				if(WARZONE_FLAG==1)
//				{
//					YUME_Buzz(2);
//					YUME_Buzz(2);
//					WARZONE_FLAG=0;
//					Sendto_PC(USART1,"PRESENT WARZONE_FLAG: %d \r",WARZONE_FLAG);
//
//					ROOM_FLAG[PRESENT_ROOM]=WARZONE;
//					Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//					Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//
////					//WARZONE -> ROOM 4
////					if(Ping[PING_FRONT]<=50)
////					{
////						Get_IR();
////						while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
////						{
////							mov_rot_right(MED,FAR);
////							mov_rot_right(MED,FAR);
////							mov_rot_right(MED,FAR);
////							Get_IR();
////						}
////
////						YUME_Buzz(4);
////						Sendto_PC(USART1,"\rYUME ESCAPE VARIABLE DOOR INFINITE LOOP! \r");
////
////						YUME_Buzz(1);
////						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLUE FLOOR DETECTED \r");
////						YUME_PID_Init();
////						FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
////
////						YUME_Buzz(1);
////						Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLACK FLOOR DETECTED \r");
////						YUME_PID_Init();
////						FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
////
////						YUME_Buzz(1);
////						//NORMAL FOLLOW UNTIL TRACER
////						CAT_SHIFT_FOLLOW=NO_SHIFT;
////						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
////						{
////							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
////							YUME_PID_Init();
////							follow_right_new();
////							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////						}
////
////						//YUME FOUND A CAT!
////						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
////						{
////							YUME_Buzz(3);
////							YUME_PID_Init();
////							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
////							{
////								CAT_SHIFT_FOLLOW=NO_SHIFT;
////								Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
////								Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
////								YUME_PID_Init();
////								followtracer_left();
////								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////							}
////							CAT_SHIFT_FOLLOW=NO_SHIFT;
////						}
////					}
//
//					if(Ping[PING_FRONT]<=50)
//					{
//						YUME_Buzz(3);
//						VARIABLE_DOOR=VAR_DOOR_DETECTED;
//					}
//					//WARZONE -> ROOM 1 GATE B
//					else
//					{
////						YUME_Buzz(1);
//						VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//
//					}
//
//					YUME_Buzz(1);
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//					{
//						CAT_SHIFT_FOLLOW=0;
//						Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//						YUME_PID_Init();
//						followtracer_left();
////							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//				}
//
//				//COUNTERMEASURE FOR ROOM 1 GATE B
//				else if( (Ping[PING_RIGHT]<=30) && (Ping[PING_ASKEW_RIGHT]<=30) )
//				{
//					//DEFAULT
//
//
//					ROOM_FLAG[PRESENT_ROOM]=ROOM_ONE;
//					Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//					Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//					YUME_Buzz(7);
//					Sendto_PC(USART1,"YUME IN FRONT OF ROOM 1 \r");
////							mov_fwd_5cm(5,FAST_LEVEL_3);
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
////							mov_rot_left(MED,FAR);
//
//					for(global_counter=0;global_counter<=6;global_counter++)
//					{
//						Get_IR();
//						if( (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//							(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//							(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//						  )
//						{
//							mov_rot_left(MED,FAR);
//							mov_rot_left(MED,FAR);
//							Get_IR();
//						}
//						mov_fwd_5cm(5,FAST_LEVEL_2);
//					}
//
//
//					//YUME ROOM 1 GATE B -> ROOM 3
//					if(
//						(ROOM_COUNTER<=2) ||
//						(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//					  )
//					{
//						YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//						SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_DISABLED;
//						YUME_Buzz(2);
//						YUME_Buzz(2);
//						Sendto_PC(USART1,"ROOM 1 -> ROOM 3 \r");
//
//						YUME_Buzz(1);
//						Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLUE CARPET DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Left(&COLOUR_BLUE,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(1);
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK FLOOR DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(3);
//						//NORMAL FOLLOW UNTIL TRACER
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							followtracer_left();
////									if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//					}
//
//
//					//YUME ROOM 1 GATE B -> ROOM 4
//					else if (
//							  (ROOM_COUNTER>2) || (VARIABLE_DOOR==VAR_DOOR_DETECTED)
//						    )
//					{
//
//						YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//						VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//
//						YUME_Buzz(1);
//						Send_TCS3200_Status();
//						Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLUE CARPET DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Left(&COLOUR_BLUE,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(1);
//						Send_TCS3200_Status();
//						Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLACK FLOOR DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(1);
//						//NORMAL FOLLOW UNTIL TRACER
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
////									CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							follow_right_new();
//							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//						//YUME FOUND A CAT!
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//						{
//							YUME_Buzz(3);
//							YUME_PID_Init();
//							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//							{
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
//								Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//								YUME_PID_Init();
//								followtracer_left();
//								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							}
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//						}
//
//					}
//
//				}
//
//				//APPLIED FOR ALL ROOMS OTHER THAN ROOM 1
//				else
//				{
//					Sendto_PC(USART1,"\rYUME OTHER ROOM \r");
//					YUME_Buzz(2);
//
//					ROOM_FLAG[PRESENT_ROOM]=OTHER_ROOM;
//					Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//					Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//
//					//ROOM 3 -> CROSSING ZONE -> WARZONE
//					if(
//							( (Ping[PING_ASKEW_LEFT]>40) || (Ping[PING_LEFT]>40) ) &&
//							(YUME_CROSSING_AUTHORITY==CROSS_ENABLED)
//					  )
//					{
//						YUME_Buzz(3);
//						Sendto_PC(USART1,"YUME ROOM 3 -> CROSSING ZONE -> WARZONE \r");
//
//						while( (Ping[PING_FRONT]<=25) )
//						{
//							mov_rot_left(MED,FAR);
//						}
//
//						//FOLLOW UNTIL DETECT TRACER LINE
//						YUME_PID_Init();
//						FollowCrossing_Right();
//						Evade_Wall();
//
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS)
//						{
//							YUME_Buzz(2);
//							Sendto_PC(USART1,"YUME CROSSING TO REDZONE! \r");
//							YUME_CrossingTo_RedZone();
//						}
//
//
//						else if(YUME_CROSSING_STATUS==CROSSING_FAILED)
//						{
//							YUME_Buzz(1);
//							ReturnTo_BlueZone();
//						}
//						YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							followtracer_left();
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//
//					}
//
//					//SPECIAL CONDITION
//					else if (
//								(FIRST_CAT_ENCOUNTER==CAT_DETECTED) ||
//								(
//										(ROOM_FLAG[PREVIOUS_ROOM]==OTHER_ROOM) &&
//										(ROOM_FLAG[PRESENT_ROOM]==OTHER_ROOM) &&
//										(CAT_FOUND[CAT_PRESENT]>=1) &&
////										(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//										(SPECIAL_CONDITION_COUNTER>=1)
//								)
//
//							)
//					{
//						Sendto_PC(USART1,"\rYUME SPECIAL CONDITION TRIGGERED!\r");
//						CAT_FOUND[CAT_PREVIOUS]=0;
//						CAT_FOUND[CAT_PRESENT]=0;
//						SPECIAL_CONDITION_COUNTER=0;
//						FIRST_CAT_ENCOUNTER=CAT_NOT_DETECTED;
//						SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_ENABLED;
//
//						YUME_Buzz(3);
//						YUME_Buzz(3);
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//
//						Get_IR();
//						while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//						{
//							mov_rot_left(MED,FAR);
//							mov_rot_left(MED,FAR);
//							Get_IR();
//						}
//
//						mov_fwd_5cm(20,FAST_LEVEL_3);
//
//						YUME_Buzz(1);
//						YUME_PID_Init();
//						FollowCarpet_Left(&COLOUR_BLUE,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
////						FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
//
//						YUME_Buzz(1);
//						YUME_PID_Init();
//						FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						YUME_Buzz(1);
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							YUME_PID_Init();
//							follow_right_new();
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//
//					}
//
//					else
//					{
//						if(CAT_FOUND[CAT_PRESENT]>=1)
//						{
//							CAT_FOUND[CAT_PREVIOUS]=0;
//							CAT_FOUND[CAT_PRESENT]=0;
//							SPECIAL_CONDITION_COUNTER++;
//						}
//
//						YUME_Buzz(2);
//						mov_rot_right(MED,FAR);
//						mov_rot_right(MED,FAR);
//						mov_rot_right(MED,FAR);
//						mov_rot_right(MED,FAR);
//
//						Get_IR();
//						while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//						{
//							mov_rot_right(MED,FAR);
//							Get_IR();
//						}
//
//						Evade_Wall();
//						mov_fwd_5cm(15,FAST);
//						Send_Location();
//						Send_TCS3200_Status();
//
//						//ROOM 1 DOOR A -> ROOM 3
//						if (
//								(ROOM_COUNTER==2) ||
//								(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//							)
//						{
//							Sendto_PC(USART1,"\rSPECIAL CONDITION ROOM 1 DOOR A -> ROOM 3\r");
//							SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_DISABLED;
//
//							YUME_Buzz(3);
//							YUME_Buzz(3);
//							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLUE CARPET DETECTED \r");
//							YUME_PID_Init();
//							FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
//							FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//							YUME_Buzz(3);
//							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK CARPET DETECTED \r");
//							YUME_PID_Init();
//							FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//							FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//							YUME_Buzz(3);
//							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLUE CARPET DETECTED \r");
//							YUME_PID_Init();
//							FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
//							FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//
//							//CROSSING THE CROSSROAD
//							YUME_Buzz(3);
//
//							mov_rot_left(MED,FAR);
//							mov_rot_left(MED,FAR);
//
//							for(global_counter=0;global_counter<=12;global_counter++)
//							{
//								Get_IR();
//								if( (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//									(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//									(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//								  )
//								{
//									mov_rot_left(MED,FAR);
//									mov_rot_left(MED,FAR);
//									Get_IR();
//								}
//								mov_fwd_5cm(5,FAST_LEVEL_3);
//							}
//
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//							{
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//								YUME_PID_Init();
//								followtracer_left();
//								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							}
//
//						}
//
//						//ROOM 3 -> WARZONE
//						//ROOM 4 -> ROOM 3
//						//ROOM 1 GATE A -> ROOM 4
//						else
//						{
//							YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//							YUME_Buzz(3);
//
//							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLUE CARPET DETECTED \r");
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							YUME_PID_Init();
//							FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
//
//							YUME_Buzz(3);
//							Send_TCS3200_Status();
//
//
////							//ESCAPE FROM VARIABLE DOOR TRAP
////							if(FOLLOW_CARPET_FLAG==FOLLOW_CARPET_ENABLED)
////							{
////								YUME_Buzz(4);
////
////								Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK CARPET DETECTED \r");
////								CAT_SHIFT_FOLLOW=NO_SHIFT;
////								YUME_PID_Init();
////								FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
////								FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
////								YUME_Buzz(4);
////							}
//
//
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//							{
////								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//								YUME_PID_Init();
//								followtracer_left();
//								if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							}
//
//							//YUME FOUND A CAT!
//							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//							{
//								YUME_Buzz(3);
//								YUME_PID_Init();
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//								{
//									CAT_SHIFT_FOLLOW=NO_SHIFT;
//									Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
//									Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//									YUME_PID_Init();
//									follow_right_new();
//									if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//								}
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//							}
//						}
//					}
//
//
//				}
////				}
//
////==============================================================================================//
//	}
//}
//
//
//void BlueFighter_Arbitrary(void)
//{
//	YUME_Buzz(2);
//	Sendto_PC(USART1,"\r YUME ARBITRARY START! \r");
//
//	YUME_LOCATION[PRESENT_LOC]=LOCATION_ROOM;
//
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		YUME_PID_Init();
//		FollowExit_Left();
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//	ROOM_COUNTER++;
//
//	//DEFAULT CROSSING AUTHORITY
//	YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
//
//
//	while(1)
//	{
//
//		//if(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//		//{
//		Sendto_PC(USART1,"\r YUME SWITCH LOCATION TO: CORRIDOR \r");
////		Evade_Wall();
//		ROOM_FLAG[PREVIOUS_ROOM]=ROOM_FLAG[PRESENT_ROOM];
//
//		//COUNTERMEASURE AFTER ESCAPE WARZONE -- DESTINATION ROOM 1
//		if(WARZONE_FLAG==1)
//		{
//			YUME_Buzz(2);
//			YUME_Buzz(2);
//			WARZONE_FLAG=0;
//			Sendto_PC(USART1,"PRESENT WARZONE_FLAG: %d \r",WARZONE_FLAG);
//
//			ROOM_FLAG[PRESENT_ROOM]=WARZONE;
//			Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//			Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//
//			if(Ping[PING_FRONT]<=50)
//			{
//				YUME_Buzz(3);
//				VARIABLE_DOOR=VAR_DOOR_DETECTED;
//			}
//			//WARZONE -> ROOM 1 GATE B
//			else
//			{
////						YUME_Buzz(1);
//				VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//			}
//
//			CAT_SHIFT_FOLLOW=NO_SHIFT;
//			while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//			{
//				CAT_SHIFT_FOLLOW=NO_SHIFT;
//				Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//				YUME_PID_Init();
//				followtracer_left();
//		//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//			}
//
//		}
//
//		//COUNTERMEASURE FOR ROOM 1
//		else if( (Ping[PING_RIGHT]<=30) && (Ping[PING_ASKEW_RIGHT]<=30) )
//		{
//			ROOM_FLAG[PRESENT_ROOM]=ROOM_ONE;
//			Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//			Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//			YUME_Buzz(3);
//
//			Sendto_PC(USART1,"YUME IN FRONT OF ROOM 1 \r");
//		//	mov_fwd_5cm(5,FAST_LEVEL_3);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//		//	mov_rot_left(MED,FAR);
//
//			for(global_counter=0;global_counter<=6;global_counter++)
//			{
//				Get_IR();
//				if( (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//					(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//					(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//				  )
//				{
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//					Get_IR();
//				}
//				mov_fwd_5cm(5,FAST);
//			}
//
//
//		//	Evade_Wall();
//
//			//YUME ROOM 1 -> ROOM 3
//			if(
//					(ROOM_COUNTER<=2) ||
//					(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//			   )
//			{
//				YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//
//				SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_DISABLED;
//				YUME_Buzz(2);
//				YUME_Buzz(2);
//				Sendto_PC(USART1,"ROOM 1 -> ROOM 3 \r");
//
//				YUME_Buzz(1);
//				Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLUE CARPET DETECTED \r");
//				YUME_PID_Init();
//				FollowCarpet_Left(&COLOUR_BLUE,&INVERSE);
//
//				YUME_Buzz(1);
//				Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK FLOOR DETECTED \r");
//				YUME_PID_Init();
//				FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//
//				YUME_Buzz(3);
//				//NORMAL FOLLOW UNTIL TRACER
//				CAT_SHIFT_FOLLOW=NO_SHIFT;
//				while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//				{
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//					YUME_PID_Init();
//					followtracer_left();
//		//			if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//			}
//
//			//YUME ROOM 1 -> ROOM 4
//			else if (
//						(ROOM_COUNTER>2) || (VARIABLE_DOOR==VAR_DOOR_DETECTED)
//					)
//			{
//				YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//				VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//
//				YUME_Buzz(1);
//				Send_TCS3200_Status();
//				Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLUE CARPET DETECTED \r");
//				YUME_PID_Init();
//				FollowCarpet_Left(&COLOUR_BLUE,&INVERSE);
//
//				YUME_Buzz(1);
//				Send_TCS3200_Status();
//				Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL BLACK FLOOR DETECTED \r");
//				YUME_PID_Init();
//				FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//
//				YUME_Buzz(1);
//				//NORMAL FOLLOW UNTIL TRACER
//				CAT_SHIFT_FOLLOW=NO_SHIFT;
//				while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//				{
////					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//					YUME_PID_Init();
//					follow_right_new();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//										//YUME FOUND A CAT!
//				if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//				{
//					YUME_Buzz(3);
//					YUME_PID_Init();
//					while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//					{
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
//						Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//						YUME_PID_Init();
//						followtracer_left();
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//				}
//
//			}
//
//		}
//
//			//APPLIED FOR ALL ROOMS OTHER THAN ROOM 1
//			else
//			{
//				Sendto_PC(USART1,"\rYUME OTHER ROOM \r");
//				YUME_Buzz(2);
//
//				ROOM_FLAG[PRESENT_ROOM]=OTHER_ROOM;
//				Sendto_PC(USART1,"ROOM_FLAG[PREVIOUS_ROOM]: %d \r",ROOM_FLAG[PREVIOUS_ROOM]);
//				Sendto_PC(USART1,"ROOM_FLAG[PRESENT_ROOM]: %d \r",ROOM_FLAG[PRESENT_ROOM]);
//
//				VARIABLE_DOOR= VAR_DOOR_SCAN;
//
//				//ROOM 3 -> WARZONE
//				if(
//						( (Ping[PING_LEFT]>=40) || (Ping[PING_ASKEW_LEFT]>=40) ) &&
//						(YUME_CROSSING_AUTHORITY==CROSS_ENABLED)// ||
//						//(ROOM_COUNTER<=1)
//				  )
//				{
//					YUME_Buzz(5);
////							mov_rot_left(MED,FAR);
////							mov_rot_left(MED,FAR);
////							mov_rot_left(MED,FAR);
////							mov_rot_left(MED,FAR);
////
////							Get_IR();
//					while( (Ping[PING_FRONT]<=25) )
//					{
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//					}
//
//					YUME_Buzz(1);
//					//FOLLOW UNTIL DETECT TRACER LINE
//					YUME_PID_Init();
//					FollowCrossing_Right();
//					Evade_Wall();
//
//					if(YUME_CROSSING_STATUS==CROSSING_SUCCESS)
//					{
//						YUME_Buzz(2);
//						Sendto_PC(USART1,"YUME CROSSING TO REDZONE! \r");
//						YUME_CrossingTo_RedZone();
//					}
//
//
//					YUME_Buzz(1);
//					if(YUME_CROSSING_STATUS==CROSSING_FAILED)
//					{
//						Sendto_PC(USART1,"YUME CROSSING FAILED! \r");
//						ReturnTo_BlueZone();
//						YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//					}
//
//
//
//					YUME_Buzz(2);
//					CAT_SHIFT_FOLLOW=NO_SHIFT;
//					while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//					{
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//						YUME_PID_Init();
//						followtracer_left();
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//					//ANTICIPATION FOR ARBITRARY START IN ROOM 4
//					//CAT ON SC
//					//ROOM 4 -> SC -> DETECT CAT (SHIFT FOLLOW) -> ROOM 1 GATE A
//
//					//YUME FOUND A CAT!
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//					{
//						YUME_Buzz(1);
//						YUME_PID_Init();
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
//							Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//							YUME_PID_Init();
//							follow_right_new();
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//					}
//
//
//				}
//
//				//SPECIAL CONDITION
//				else if (
//							(FIRST_CAT_ENCOUNTER==CAT_DETECTED) ||
//							(
//								(ROOM_FLAG[PREVIOUS_ROOM]==OTHER_ROOM) &&
//								(ROOM_FLAG[PRESENT_ROOM]==OTHER_ROOM) &&
//								(CAT_FOUND[CAT_PRESENT]>=1) &&
////								(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//								(SPECIAL_CONDITION_COUNTER>=1)
//							)
//						)
//				{
//					Sendto_PC(USART1,"\rYUME SPECIAL CONDITION TRIGGERED!\r");
//					CAT_FOUND[CAT_PREVIOUS]=0;
//					CAT_FOUND[CAT_PRESENT]=0;
//					SPECIAL_CONDITION_COUNTER=0;
//					FIRST_CAT_ENCOUNTER=CAT_NOT_DETECTED;
//					SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_ENABLED;
//
//					YUME_Buzz(3);
//					YUME_Buzz(3);
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//
//					Get_IR();
//					while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//					{
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//						Get_IR();
//					}
//
//					mov_fwd_5cm(20,FAST_LEVEL_3);
//
//					YUME_PID_Init();
//					FollowCarpet_Left(&COLOUR_BLUE,&INVERSE);
//
//					YUME_PID_Init();
//					FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//
//					while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//					{
//						YUME_PID_Init();
//						follow_right_new();
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//
//				}
//
//
//				else
//				{
//					if(CAT_FOUND[CAT_PRESENT]>=1)
//					{
////						CAT_FOUND[CAT_PREVIOUS]=0;
////						CAT_FOUND[CAT_PRESENT]=0;
//						SPECIAL_CONDITION_COUNTER++;
//					}
//
//					YUME_Buzz(2);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
////					mov_rot_right(MED,FAR);
//
//					Get_IR();
//					while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//					{
//						mov_rot_right(MED,FAR);
//						Get_IR();
//					}
//
//					Evade_Wall();
//					mov_fwd_5cm(10,FAST);
//					Send_Location();
//					Send_TCS3200_Status();
//
//					//ROOM 1 DOOR A -> ROOM 3
//					if (
//							(ROOM_COUNTER==3) ||
//							(SPECIAL_CONDITION_FLAG==SPECIAL_CONDITION_ENABLED)
//						)
//					{
//						Sendto_PC(USART1,"\rSPECIAL CONDITION ROOM 1 DOOR A -> ROOM 3\r");
//						SPECIAL_CONDITION_FLAG=SPECIAL_CONDITION_DISABLED;
//
//						YUME_Buzz(4);
//
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLUE CARPET DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
//
//						YUME_Buzz(1);
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK CARPET DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//
//						YUME_Buzz(1);
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLUE CARPET DETECTED \r");
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
//
//						//CROSSING THE CROSSROAD
//						YUME_Buzz(3);
//
//						mov_rot_left(MED,FAR);
//						mov_rot_left(MED,FAR);
//
//						for(global_counter=0;global_counter<=12;global_counter++)
//						{
//							Get_IR();
//							if( (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ||
//								(INFRARED[IR_FRONT_LEFT]==IR_DETECTED)  ||
//								(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//							  )
//							{
//								mov_rot_left(MED,FAR);
//								mov_rot_left(MED,FAR);
//								Get_IR();
//							}
//							mov_fwd_5cm(5,FAST_LEVEL_3);
//						}
//
//
//					    CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							followtracer_left();
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//					}
//
//					//ROOM 3 -> WARZONE
//					//ROOM 4 -> ROOM 3
//					//ROOM 1 GATE B -> ROOM 4
//					else
//					{
//						YUME_CROSSING_AUTHORITY=CROSS_DISABLED;
//						YUME_Buzz(1);
//
//						Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLUE CARPET DETECTED \r");
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						YUME_PID_Init();
//						FollowCarpet_Right(&COLOUR_BLUE,&INVERSE);
//
//						YUME_Buzz(1);
//						Send_TCS3200_Status();
//
////						//ESCAPE FROM VARIABLE DOOR TRAP
////						if(FOLLOW_CARPET_FLAG==FOLLOW_CARPET_ENABLED)
////						{
////							YUME_Buzz(4);
////
////							Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK CARPET DETECTED \r");
////							CAT_SHIFT_FOLLOW=NO_SHIFT;
////							YUME_PID_Init();
////							FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
////							YUME_Buzz(4);
////						}
////						FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//						CAT_SHIFT_FOLLOW=NO_SHIFT;
//						while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//						{
////									CAT_SHIFT_FOLLOW=NO_SHIFT;
//							Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//							YUME_PID_Init();
//							followtracer_left();
//							if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						}
//
//						//YUME FOUND A CAT!
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW)
//						{
//							YUME_Buzz(1);
//							YUME_PID_Init();
//							CAT_SHIFT_FOLLOW=NO_SHIFT;
//							while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//							{
//								CAT_SHIFT_FOLLOW=NO_SHIFT;
//								Sendto_PC(USART1,"\rYUME SHIFT ALGORITHM TO FOLLOWTRACER RIGHT\r");
//								Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//								YUME_PID_Init();
//								follow_right_new();
//								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							}
//						}
//					}
//				}
//			}
//
////==============================================================================================//
//
//
////=====================================YUME ROOM ROUTINES=======================================//
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//			YUME_Buzz(4);
//
//			ROOM_COUNTER++;
//			while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//			{
//				Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//				YUME_ROOM();
//				if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//			}
//			if(EXTINGUISHED_FIRE>=1)
//			{
//				if( (YUME_CROSSING_STATUS!=CROSSING_SUCCESS) &&
//				    (FIRST_CAT_ENCOUNTER==CAT_NOT_DETECTED)
//				  )
//				{
//					YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
//				}
//			}
////			if(YUME_CROSSING_STATUS!=CROSSING_SUCCESS)
////			{
////				YUME_CROSSING_AUTHORITY=CROSS_ENABLED;
////			}
//
//		}
////==============================================================================================//
//
//
//	}
//
//
//}
//
//
//
//
//
//
//
//
//
//
///*
// * YUME FOLLOW TRACER
// */
//
///* func      : void follow_tracer_right(void)
// * brief     : Wall following algorithm using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void follow_tracer_right(void)
//{
//	while(YUME_LOCATION[PRESENT_LOC]!=LOCATION_ROOM)
//	{
////		YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////		if(TRACER_STAT==1){YUME_Success();}
//
//		if (Ping[PING_FRONT]<=25)
//		{
//			if (Ping[PING_RIGHT]<=15)
//			{
//				Cat_Avoider();
//				Sendto_PC(USART1,"YUME ROTATE LEFT \r");
//				mov_rot_left(MED, FAR);
////				YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////				if(TRACER_STAT==1){YUME_Success();}
//
//			}
//
//			if (Ping[PING_RIGHT]>15)
//			{
//				Cat_Avoider();
//				Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
//				mov_rot_right(MED, FAR);
//
////				YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////				if(TRACER_STAT==1){YUME_Success();}
//			}
//		}
//		else PID_follow_tracer_right();
//
//		Cat_Avoider();
////		YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////		if(TRACER_STAT==1){YUME_Success();}
//	}
//
//}
//
///* func      : void PID_follow_tracer_right(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_follow_tracer_right(void)
//{
//	PID_Calc();
//
//	while(YUME_LOCATION[PRESENT_LOC]!=LOCATION_ROOM)
//	{
//		Cat_Avoider();
////		YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////		if(TRACER_STAT==1){YUME_Success();}
//
//		//KONDISI ROBOT SESUAI
//		if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//		//if ( (Ping[PING_RIGHT]<=set_point_upper) && (Ping[PING_RIGHT]>=set_point_lower) )
//			{
//				Sendto_PC(USART1,"YUME FORWARD \r");
//				mov_fwd_5cm(5, FAST);
//
//				Cat_Avoider();
////				YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////				if(TRACER_STAT==1){YUME_Success();}
//			}
//
//		//KONDISI ROBOT JAUH DARI DINDING
//		else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//			{
//				if (PID_F_R.pid_value[0]>3) PID_F_R.pid_value[0]=3; //WINDUP
//
//				if ((PID_F_R.pid_value[0]<1)&&(PID_F_R.pid_value[0]>=0))
//					{
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_5cm(5, FAST);
//
//						Cat_Avoider();
////						YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////						if(TRACER_STAT==1){YUME_Success();}
//					}
//
//				folltracer_curve_right(MED, FAR, &PID_F_R.pid_value[0]);
//
//				Cat_Avoider();
////				YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////				if(TRACER_STAT==1){YUME_Success();}
//			}
//
//		//KONDISI ROBOT DEKAT DENGAN DINDING
//		else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//			{
//				if (PID_F_R.pid_value[0]>3) PID_F_R.pid_value[0]=3; //WINDUP
//
//				if ((PID_F_R.pid_value[0]<1)&&(PID_F_R.pid_value[0]>=0))
//					{
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_5cm(5, FAST);
//
//						Cat_Avoider();
////						YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////						if(TRACER_STAT==1){YUME_Success();}
//					}
//
//				folltracer_curve_left(MED, FAR, &PID_F_R.pid_value[0]);
//
//				Cat_Avoider();
////				YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////				if(TRACER_STAT==1){YUME_Success();}
//			}
//
//		Cat_Avoider();
////		YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////		if(TRACER_STAT==1){YUME_Success();}
//	}
//}
//
//
///* func      : void folltracer_curve_right(int SPEED, int STEP, float *COMMAND_LOOP)
// * brief     : convert control signal to actuating signal in follow right until tracer
// * param     : int SPEED, int STEP, float *COMMAND_LOOP (pid_value[0])
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding PID wall following function
// *
// */
//void folltracer_curve_right(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	int counter;
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//
//	Cat_Avoider();
////	YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////	if(TRACER_STAT==1){YUME_Success();}
//
//	for(counter=1;counter<=*COMMAND_LOOP;counter++)
//	{
//		while (Ping[PING_FRONT]<=10)
//		{
//			if (Ping[PING_RIGHT]<=15)
//			{
//				mov_rot_left(MED, FAR);
//				mov_rot_left(MED, FAR);
//				OVERRIDE=1;
//			}
//
//			if (Ping[PING_RIGHT]>15)
//			{
//				mov_rot_right(MED, FAR);
//				mov_rot_right(MED, FAR);
//				OVERRIDE=1;
//			}
//
//			Cat_Avoider();
////			YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////			if(TRACER_STAT==1){YUME_Success();}
//
//		}
//		if(OVERRIDE==1){break;}
//
//		if (OVERRIDE==0)
//		{
//			Cat_Avoider();
////			YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////			if(TRACER_STAT==1){YUME_Success();}
//			mov_curve_right_trace(MED,FAR);
//		}
//
//		Cat_Avoider();
////		YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////		if(TRACER_STAT==1){YUME_Success();}
//
//	}
//}
//
///* func      : void folltracer_curve_left(int SPEED, int STEP, float *COMMAND_LOOP)
// * brief     : convert control signal to actuating signal in follow right until tracer
// * param     : int SPEED, int STEP, float *COMMAND_LOOP (pid_value[0])
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding PID wall following function
// *
// */
//void folltracer_curve_left(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	int counter;
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//
//	Cat_Avoider();
////	YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////	if(TRACER_STAT==1){YUME_Success();}
//
//	for(counter=1;counter<=*COMMAND_LOOP;counter++)
//	{
//		while (Ping[PING_FRONT]<=10)
//		{
//			if (Ping[PING_RIGHT]<=15)
//			{
//				mov_rot_left(MED, FAR);
//				mov_rot_left(MED, FAR);
//				OVERRIDE=1;
//			}
//
//			if (Ping[PING_RIGHT]>15)
//			{
//				mov_rot_right(MED, FAR);
//				mov_rot_right(MED, FAR);
//				OVERRIDE=1;
//			}
//			Cat_Avoider();
////			YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////			if(TRACER_STAT==1){YUME_Success();}
//		}
//		if(OVERRIDE==1){break;}
//
//		if(OVERRIDE==0)
//		{
//			Cat_Avoider();
////			YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////			if(TRACER_STAT==1){YUME_Success();}
//
//			mov_curve_left_trace(MED,FAR);
//
//
//		}
//
//		Cat_Avoider();
////		YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////		if(TRACER_STAT==1){YUME_Success();}
//
//	}
//}
//
//
///* func      : void YUME_Found_Fire(void)
// * brief     : YUME FOUND FIRESPOT AND EXTINGUISHING ALGORITHM
// * param     : N/A
// * retval    : N/A
// * Ver       : 2
// * 				 1. Initial Code
// * 			     2. Add anticipation for different value of UV_state and UV_Lock
// * written By: Ryan (???? Missing)
// * Revised BY: Ryan (Monday, November 16th, 2015
// * programmer's Note:
// *
// */
//void YUME_Found_Fire(void)
//{
//	YUME_FOUND_FIRE_OVERRIDE=1;
//	YUME_Buzz(3);
//	Sendto_PC(USART1,"YUME has found the fire source! \r");
//	YUME_Tracer_Check();
//
//	//Evade_Wall();
//	Evade_Wall_Room();
//	Get_IR();
////	while( (Ping[PING_FRONT]>=20) &&
////		   (F_TRACER==TRACER_NOT_DETECTED)
////		 )
//	Get_IR();
//	Evade_Wall_Room_Blue();
////	Evade_Wall_Room_Blue();
////	while(  ( ( Ping[PING_FRONT]>=20) &&
//////			  (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) &&
//////			  (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED)  &&
////			  (INFRARED[IR_FRONT_MIDDLE]==IR_NOT_DETECTED)
////			  //(INFRARED[IR_FRONT_MIDDLE]==IR_NOT_DETECTED)
////			)
////			&&
////		    (TRACER_STAT==TRACER_NOT_DETECTED)
////		 )
////	{
////
////		Mov_Fwd_Trace(5,FAST_LEVEL_3);
//////		Evade_Wall_Room_Blue();
////		Get_IR();
////	}
//	while(  Ping[PING_FRONT]>=25)
//			{
//				mov_fwd_5cm(5,FAST_LEVEL_3);
//			}
////	mov_fwd_5cm(15,FAST_LEVEL_3);
//
//
//
//	//IF CANDLE CIRCLE DETECTED
//	if(F_TRACER==TRACER_DETECTED)
//	{
//		Sendto_PC(USART1,"YUME EXTINGUISHER via Found_Fire and CANDLE_CIRCLE detected \r");
//		while (UV_Lock==1)
//		{
//			YUME_Extinguisher();
//
//			Get_IR();
//
//			if(Ping[PING_FRONT]<=30)
//			{
//				if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]) ||
//					(INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)
//				  )
//				{
//					mov_rotright_fire(FAST_LEVEL_3,FAR);
//					mov_rotright_fire(FAST_LEVEL_3,FAR);
//					mov_rotright_fire(FAST_LEVEL_3,FAR);
//				}
//				else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]) ||
//						  (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED)
//						)
//				{
//					mov_rotleft_fire(FAST_LEVEL_3,FAR);
//					mov_rotleft_fire(FAST_LEVEL_3,FAR);
//					mov_rotleft_fire(FAST_LEVEL_3,FAR);
//				}
//			}
//			else
//			{
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//			}
//
//
//			if(EXTINGUISHER_FLAG==1)
//			{
//				Get_UV();
//				if(UV_state==NO_FIRE)
//				{
//					UV_Lock=0;
//					EXTINGUISHER_FLAG=0;
//				}
//			}
//		}
//
//	}
//	Sendto_PC(USART1,"1. EXTINGUISHER_FLAG: %d | UV_Lock: %d \r",EXTINGUISHER_FLAG,UV_Lock);
//
//
//	Get_UV();
//
//	if(EXTINGUISHER_FLAG==1)
//	{
//		Get_UV();
//		if(UV_state==NO_FIRE)
//		{
//			UV_Lock=0;
//			EXTINGUISHER_FLAG=0;
//		}
//	}
//
//	if(UV_Lock==1)
//	{
//		//IF CANDLE CIRCLE IS NOT PRESENT
////		mov_bwd(5,MED);
////		mov_static();
//		YUME_Extinguisher();
//	}
//
//	Sendto_PC(USART1,"2. EXTINGUISHER_FLAG: %d | UV_Lock: %d \r",EXTINGUISHER_FLAG,UV_Lock);
//
//	while (UV_Lock==1)
//	{
//		Sendto_PC(USART1,"YUME SEARCH FIRE via Found_Fire and CANDLE_CIRCLE detected \r");
//		YUME_Search_Fire();
//		Get_IR();
//
////		Get_UV(); if ( (UV_state==NO_FIRE)&& (UV_Lock==0) ) break;
//
//		if (Ping[PING_FRONT]>=20)
//		{
//			while (Ping[PING_FRONT]>=20)
//			{
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//			}
//		}
//		else if(
//			(
//				(Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]) ||
//				(INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)
//			)
//			&&
//			(
//					(Ping[PING_FRONT]<20) || (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//			)
//		   )
//		{
//			mov_rotright_fire(FAST_LEVEL_3,FAR);
//			mov_rotright_fire(FAST_LEVEL_3,FAR);
//			mov_rotright_fire(FAST_LEVEL_3,FAR);
//		}
//		else if (  (
//				      (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]) ||
//				      (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED)
//				   )
//				    &&
//				   (
//					  (Ping[PING_FRONT]<20) || (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//				   )
//				)
//		{
//			mov_rotleft_fire(FAST_LEVEL_3,FAR);
//			mov_rotleft_fire(FAST_LEVEL_3,FAR);
//			mov_rotleft_fire(FAST_LEVEL_3,FAR);
//		}
//
//		Get_UV();
//		if(EXTINGUISHER_FLAG==1)
//		{
//			Get_UV();
//			if(UV_state==NO_FIRE)
//			{
//				UV_Lock=0;
//				EXTINGUISHER_FLAG=0;
//			}
//		}
//
//		while(UV_Lock==1)
//		{
//			YUME_Buzz(1);
////			if(Ping[PING_FRONT]<=30)
////			{
////				if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]) ||
////					(INFRARED[IR_MID_LEFT]==IR_MID_DETECTED)
////				  )
////				{
////					mov_rotright_fire(FAST_LEVEL_3,FAR);
////					mov_rotright_fire(FAST_LEVEL_3,FAR);
////					mov_rotright_fire(FAST_LEVEL_3,FAR);
////				}
////				else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]) ||
////						  (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED)
////						)
////				{
////					mov_rotleft_fire(FAST_LEVEL_3,FAR);
////					mov_rotleft_fire(FAST_LEVEL_3,FAR);
////					mov_rotleft_fire(FAST_LEVEL_3,FAR);
////				}
////			}
//
//			mov_rotleft_fire(FAST_LEVEL_3,FAR);
//			mov_rotleft_fire(FAST_LEVEL_3,FAR);
//
//			YUME_FireTracker();
//
//			YUME_Buzz(1);
//			//YUME FOLLOWFIRE 2nd TIME
//			Sendto_PC(USART1,"YUME FOLLOW FIRE 2ND TIME! \r");
//			if(INITIAL_ZONE==ZONE_RED)
//			{
//				if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
//				{
//					followfire_right_new();
//				}
//				else
//				{
//					followfire_left_new();
//				}
//
//			}
//			else if(INITIAL_ZONE==ZONE_BLUE)
//			{
//				if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
//				{
//					followfire_left_new();
//				}
//				else
//				{
//					followfire_right_new();
//				}
//
//			}
//
//			while(UV_Lock==1)
//			{
//				YUME_FireTracker();
//				mov_rot_right(MED,FAR);
//				mov_rot_right(MED,FAR);
//				mov_rot_right(MED,FAR);
//
//				Get_UV();
//				if(EXTINGUISHER_FLAG==1)
//				{
//					Get_UV();
//					if(UV_state==NO_FIRE)
//					{
//						UV_Lock=0;
//						EXTINGUISHER_FLAG=0;
//					}
//				}
//			}
//
//			while(  ( ( Ping[PING_FRONT]>=20) ||
//					  (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) ||
//					  (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED)  //||
//					  //(INFRARED[IR_FRONT_MIDDLE]==IR_NOT_DETECTED)
//					)
//					&&
//				    (TRACER_STAT==TRACER_NOT_DETECTED)
//				 )
//			{
//
////				YUME_FireTracker();
//				Mov_Fwd_Trace(5,FAST_LEVEL_3);
////				Evade_Wall_Room_Blue();
//				Get_IR();
//
//				Get_UV();
//				if(EXTINGUISHER_FLAG==1)
//				{
//					Get_UV();
//					if(UV_state==NO_FIRE)
//					{
//						UV_Lock=0;
//						EXTINGUISHER_FLAG=0;
//					}
//				}
//
//				if(UV_Lock==1)
//				{
//					//IF CANDLE CIRCLE IS NOT PRESENT
//					mov_bwd(5,MED);
//					YUME_Extinguisher();
//				}
//			}
//
//		}
//
//
//		//YUME FOUND FIRE TERMINATE
//
//		if(EXTINGUISHER_FLAG==1)
//		{
//			Get_UV();
//			if(UV_state==NO_FIRE)
//			{
//				UV_Lock=0;
//				EXTINGUISHER_FLAG=0;
//			}
//		}
//
//
//	}
//
//	Get_UV();
//	UV_Lock=0; //UV_Lock FLAG RESET
//	EXTINGUISHED_FIRE++;
//	led_off_counter=1;
//
//	Sendto_PC(USART1,"\r||================================================================||\r");
//	Sendto_PC(USART1,"UV_state: %d \r",UV_state);
//	Sendto_PC(USART1,"UV_Lock: %d \r",UV_Lock);
//	Sendto_PC(USART1,"EXTINGUISHED FIRE : %d \r",EXTINGUISHED_FIRE);
//	Sendto_PC(USART1,"\r||================================================================||\r");
//
//
//	/*
//	 * ESCAPE FROM FIRE ROOM
//	 */
//
//	if (UV_Lock==0)
//	{
//		//Get_IR();
//
//		if(Ping[PING_FRONT]<=13)
//		{
//			mov_bwd(20,MED);
//		}
//
//
//		//yume trial A
////		mov_rot_left(MED,FAR);
////		mov_rot_left(MED,FAR);
////		Get_IR();
////		while(
////				(Ping[PING_FRONT]<=30) ||
////				(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
////			 )
////		//while( (IR_FRONT_RIGHT==IR_NOT_DETECTED)&& (IR_FRONT_LEFT==IR_NOT_DETECTED) )
////		{
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
//////				mov_rot_left(MED,FAR);
//////				mov_rot_left(MED,FAR);
////			Get_IR();
////		}
//
//		//YUME TRIAL B
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		Get_IR();
//		while(
//				(Ping[PING_FRONT]<=30) ||
//				(INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//			 )
//		//while( (IR_FRONT_RIGHT==IR_NOT_DETECTED)&& (IR_FRONT_LEFT==IR_NOT_DETECTED) )
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
////				mov_rot_left(MED,FAR);
////				mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//		mov_fwd_5cm(15,FAST_LEVEL_3);
//
////		//Evade_Wall();
////		if(INITIAL_ZONE==ZONE_RED)
////		{
////			//DEFAULT
////			if(ENEMY_ZONE_STAT==COMFORT_ZONE)
////			{
////				mov_rot_right(MED,FAR);
////				mov_rot_right(MED,FAR);
////
////				Get_IR();+
////				while(
////						(Ping[PING_FRONT]<=30) ||
////						(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
////						(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)
////
////					 )
////				//while( (IR_FRONT_RIGHT==IR_NOT_DETECTED)&& (IR_FRONT_LEFT==IR_NOT_DETECTED) )
////				{
////					mov_rot_right(MED,FAR);
////					mov_rot_right(MED,FAR);
////	//				mov_rot_right(MED,FAR);
////	//				mov_rot_right(MED,FAR);
////					Get_IR();
////				}
////			}
////			else if (ENEMY_ZONE_STAT==ENEMY_ZONE)
////			{
////				mov_rot_left(MED,FAR);
////				mov_rot_left(MED,FAR);
////				Get_IR();
////				while(
////						(Ping[PING_FRONT]<=30) ||
////						(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
////						(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)
////
////					 )
////				//while( (IR_FRONT_RIGHT==IR_NOT_DETECTED)&& (IR_FRONT_LEFT==IR_NOT_DETECTED) )
////				{
////					mov_rot_left(MED,FAR);
////					mov_rot_left(MED,FAR);
////	//				mov_rot_left(MED,FAR);
////	//				mov_rot_left(MED,FAR);
////					Get_IR();
////				}
////			}
////
////		}
////		else if(INITIAL_ZONE==ZONE_BLUE)
////		{
////			if(ENEMY_ZONE_STAT==COMFORT_ZONE)
////			{
////				mov_rot_left(MED,FAR);
////				mov_rot_left(MED,FAR);
////				Get_IR();
////				while(
////						(Ping[PING_FRONT]<=30) ||
////						(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
////						(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)
////
////					 )
////				//while( (IR_FRONT_RIGHT==IR_NOT_DETECTED)&& (IR_FRONT_LEFT==IR_NOT_DETECTED) )
////				{
////					mov_rot_left(MED,FAR);
////					mov_rot_left(MED,FAR);
////	//				mov_rot_left(MED,FAR);
////	//				mov_rot_left(MED,FAR);
////					Get_IR();
////				}
////			}
////			else if(ENEMY_ZONE_STAT==ENEMY_ZONE)
////			{
////				mov_rot_right(MED,FAR);
////				mov_rot_right(MED,FAR);
////
////				Get_IR();
////				while(
////						(Ping[PING_FRONT]<=30) ||
////						(INFRARED[IR_FRONT_LEFT]==IR_DETECTED) ||
////						(INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)
////
////					 )
////				//while( (IR_FRONT_RIGHT==IR_NOT_DETECTED)&& (IR_FRONT_LEFT==IR_NOT_DETECTED) )
////				{
////					mov_rot_right(MED,FAR);
////					mov_rot_right(MED,FAR);
////	//				mov_rot_right(MED,FAR);
////	//				mov_rot_right(MED,FAR);
////					Get_IR();
////				}
////			}
////
////		}
//
//
//
//
//		Sendto_PC(USART1,"\r END OF YUME FOUND FIRE FUNCTION \r");
//		Send_Location ();
//		FIRE_PUTOFF=1;
//		YUME_FOUND_FIRE_OVERRIDE=0;
//
//	}
//
//}
//
//void YUME_Search_Fire(void)
//{
//	Sendto_PC(USART1,"YUME Hexapod Search Fire Sequences \r");
//
//	static int right=90,left=90;
//
//	generate_movement_data(0,0,10);
//	delay_ms(50);
//
////	if (FIRE==0&&UV_state==0)
//	if (UV_state==0)
//	{
//		while(right>=20&&left<=160&&UV_state==0)
//		{
//			Get_TPA81();
//			if (FIRE==1)YUME_Extinguisher();
////			panas = YUME_TPA_Check(1);
//			inv_kine(front_left,left,7,leg);
//			inv_kine(front_right,right,7,leg);
//			inv_kine(middle_left,left,7,leg);
//			inv_kine(middle_right,right,7,leg);
//			inv_kine(rear_left,left,7,leg);
//			inv_kine(rear_right,right,7,leg);
//			delay_ms(10);
//			right-=3;
//			left+=3;
//
//		}
//		delay_ms(50);
//	}
//
////	if (FIRE==0&&UV_state==0)
//	if (UV_state==0)
//	{
//		while(right<=90&&left>=90&&UV_state==0)
//		{
//			Get_TPA81();
//			if (FIRE==1)YUME_Extinguisher();
////			panas = YUME_TPA_Check(1);
//		    inv_kine(front_left,left,7,leg);
//		    inv_kine(front_right,right,7,leg);
//		    inv_kine(middle_left,left,7,leg);
//		    inv_kine(middle_right,right,7,leg);
//		    inv_kine(rear_left,left,7,leg);
//		    inv_kine(rear_right,right,7,leg);
//		    delay_ms(10);
//		    right+=3;
//		    left-=3;
//		}
//		delay_ms(50);
//	}
//
////	if (FIRE==0&&UV_state==0)
//	if (UV_state==0)
//	{
//		while(right<=160&&left>=20&&UV_state==0)
//		{
//			Get_TPA81();
//			if (FIRE==1)YUME_Extinguisher();
//	//		panas = YUME_TPA_Check(1);
//
//			inv_kine(front_left,left,7,leg);
//			inv_kine(front_right,right,7,leg);
//			inv_kine(middle_left,left,7,leg);
//			inv_kine(middle_right,right,7,leg);
//			inv_kine(rear_left,left,7,leg);
//			inv_kine(rear_right,right,7,leg);
//			delay_ms(10);
//			right+=3;
//			left-=3;
//		}
//		delay_ms(50);
//	}
//
////	if (FIRE==0&&UV_state==0)
//	if (UV_state==0)
//	{
//		while(right>=90&&left<=90&&UV_state==0)
//		{
//			Get_TPA81();
//			if (FIRE==1)YUME_Extinguisher();
//	//		panas = YUME_TPA_Check(1);
//			inv_kine(front_left,left,7,leg);
//			inv_kine(front_right,right,7,leg);
//			inv_kine(middle_left,left,7,leg);
//			inv_kine(middle_right,right,7,leg);
//			inv_kine(rear_left,left,7,leg);
//			inv_kine(rear_right,right,7,leg);
//			delay_ms(10);
//			right-=3;
//			left+=3;
//		}
//		delay_ms(50);
//	}
//
//
//
//}
//
//void YUME_FireTracker(void)
//{
//	Sendto_PC(USART1,"YUME FIRE TRACKING... \r");
//
//	static int right=90,left=90;
//
//	generate_movement_data(0,0,10);
//	delay_ms(50);
//
//	if (UV_state==0)
//	{
//		while(right>=20&&left<=160&&UV_state==0)
//		{
//			Get_TPA81();
//			if (FIRE==1){Evade_Wall_Room();mov_rot_right(MED,FAR);YUME_Found_Fire();}
////			panas = YUME_TPA_Check(1);
//			inv_kine(front_left,left,7,leg);
//			inv_kine(front_right,right,7,leg);
//			inv_kine(middle_left,left,7,leg);
//			inv_kine(middle_right,right,7,leg);
//			inv_kine(rear_left,left,7,leg);
//			inv_kine(rear_right,right,7,leg);
//			delay_ms(20);
//			right-=5;
//			left+=5;
//
//		}
//		delay_ms(50);
//	}
//
//	if (UV_state==0)
//	{
//		while(right<=90&&left>=90&&UV_state==0)
//		{
//			Get_TPA81();
//			if (FIRE==1){Evade_Wall_Room();mov_rot_right(MED,FAR);YUME_Found_Fire();}
////			panas = YUME_TPA_Check(1);
//		    inv_kine(front_left,left,7,leg);
//		    inv_kine(front_right,right,7,leg);
//		    inv_kine(middle_left,left,7,leg);
//		    inv_kine(middle_right,right,7,leg);
//		    inv_kine(rear_left,left,7,leg);
//		    inv_kine(rear_right,right,7,leg);
//		    delay_ms(20);
//		    right+=5;
//		    left-=5;
//		}
//		delay_ms(50);
//	}
//
//	if (UV_state==0)
//	{
//		while(right<=160&&left>=20&&UV_state==0)
//		{
//			Get_TPA81();
//			if (FIRE==1){Evade_Wall_Room();mov_rot_left(MED,FAR);YUME_Found_Fire();}
//	//		panas = YUME_TPA_Check(1);
//
//			inv_kine(front_left,left,7,leg);
//			inv_kine(front_right,right,7,leg);
//			inv_kine(middle_left,left,7,leg);
//			inv_kine(middle_right,right,7,leg);
//			inv_kine(rear_left,left,7,leg);
//			inv_kine(rear_right,right,7,leg);
//			delay_ms(20);
//			right+=5;
//			left-=5;
//		}
//		delay_ms(50);
//	}
//
//	if (UV_state==0)
//	{
//		while(right>=90&&left<=90&&UV_state==0)
//		{
//			Get_TPA81();
//			if (FIRE==1){Evade_Wall_Room();mov_rot_left(MED,FAR);YUME_Found_Fire();}
//	//		panas = YUME_TPA_Check(1);
//			inv_kine(front_left,left,7,leg);
//			inv_kine(front_right,right,7,leg);
//			inv_kine(middle_left,left,7,leg);
//			inv_kine(middle_right,right,7,leg);
//			inv_kine(rear_left,left,7,leg);
//			inv_kine(rear_right,right,7,leg);
//			delay_ms(20);
//			right-=5;
//			left+=5;
//		}
//		delay_ms(50);
//	}
//
//}
//
//void YUME_FireScan(void)
//{
//	Sendto_PC(USART1,"YUME FIRE SCAN... \r");
//
//	static int right=90,left=90;
//
//	generate_movement_data(0,0,10);
//	delay_ms(50);
//
//	Get_UV();
//
//	while(right>=20&&left<=160)
//	{
//		Get_UV();
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(10);
//		right-=5;
//		left+=5;
//
//	}
//	delay_ms(50);
//
//
//	while(right<=90&&left>=90)
//	{
//		Get_UV();
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(10);
//		right+=5;
//		left-=5;
//	}
//	delay_ms(50);
//
//
//
//	while(right<=160&&left>=20)
//	{
//		Get_UV();
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(10);
//		right+=5;
//		left-=5;
//	}
//	delay_ms(50);
//
//
//	while(right>=90&&left<=90)
//	{
//		Get_UV();
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(10);
//		right-=5;
//		left+=5;
//	}
//	delay_ms(50);
//
//}
//
//
//
///* func      : void YUME_FireFight(void)
// * brief     : YUME FIRE FIGHTING ALGORITHM IN ENCLOSED ROOM
// * param     : N/A
// * retval    : N/A
// * Ver       : 2
// * 				 1. Initial Code
// * 			     2. Add anticipation for different value of UV_state and UV_Lock
// * written By: Ryan (???? Missing)
// * Revised BY: Ryan (Monday, November 16th, 2015
// * programmer's Note:
// *
// */
//void YUME_FireFight(void)
//{
//	FIRE_PUTOFF=0;
//	firetrack_counter=0;
//	Get_UV();
//	Get_IR();
//	Get_TPA81();
//	led_off_counter=0;
//	RETURN_COUNTER=0;
//
//	//while( (UV_state==0) && (FIRE==0) && (UV_Lock==1) )
//
//	while( (UV_Lock==1) )
//	{
//		YUME_Buzz(2);
//		YUME_LED_BLINK_ON;
//		Get_UV();
//		Get_TPA81();
//
//		if(FIRE==1)YUME_Found_Fire();
//
//		YUME_FireTracker();
//		YUME_PID_Init();
//		followfire_right_new();
////		followfire_left_new();
////		if(INITIAL_ZONE==ZONE_RED)
////		{
////			if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
////			{
////				followfire_right_new();
////			}
////			else
////			{
////				followfire_left_new();
////			}
////
////		}
////		else if(INITIAL_ZONE==ZONE_BLUE)
////		{
////			if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
////			{
////				followfire_left_new();
////			}
////			else
////			{
////				followfire_right_new();
////			}
////
////		}
//
//		if(FIRE_PUTOFF==1) break;
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//	YUME_Buzz(2);
//
//	Get_UV();
//	if(UV_state==NO_FIRE)
//	{
//		UV_Lock=0;
//		led_off_counter=1;
//	}
//
//	YUME_Buzz(3);
//	Sendto_PC(USART1,"\r\r ===YUME FOLLOW EXIT RIGHT RULE=== \r\r");
//
//	YUME_PID_Init();
////	FollowExit_Right();
//	FollowExit_Left();
//
////	if(WARZONE_FLAG==1)
////	{
////		YUME_Buzz(2);
////		if(INITIAL_ZONE==ZONE_BLUE)
////		{
////			ReturnTo_BlueWarzone();
////		}
////
////		else if(INITIAL_ZONE==ZONE_RED)
////		{
////			ReturnTo_RedWarzone();
////		}
////
////	}
////
////
////	//YUME ESCAPE PREPARATION
////	if(INITIAL_ZONE==ZONE_RED)
////	{
////		if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
////		{
////			YUME_Buzz(3);
////			Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER RIGHT RULE=== \r\r");
////			YUME_PID_Init();
////			follow_right_counter(10);
////
////
////			YUME_Buzz(1);
////		    FRONT_Sum_Colour();
////		    F_TRACER= TRACER_STAT;
////			MID_Sum_Colour();
////		    M_TRACER= TRACER_STAT;
////			while( (F_TRACER==TRACER_DETECTED)||(M_TRACER==TRACER_DETECTED) )
////			{
////			    FRONT_Sum_Colour();
////			    F_TRACER= TRACER_STAT;
////				MID_Sum_Colour();
////			    M_TRACER= TRACER_STAT;
////				Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER RIGHT RULE=== \r\r");
////				YUME_PID_Init();
////				follow_right_counter(5);
////			}
////
////
////
////			YUME_Buzz(1);
////			Sendto_PC(USART1,"\r\r ===YUME FOLLOW EXIT RIGHT RULE=== \r\r");
////			YUME_PID_Init();
////			FollowExit_Right();
////		}
////		else
////		{
////			YUME_Buzz(1);
////			Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER LEFT RULE=== \r\r");
////			YUME_PID_Init();
////			follow_left_counter(10);
////
////			YUME_Buzz(1);
////		    FRONT_Sum_Colour();
////		    F_TRACER= TRACER_STAT;
////			MID_Sum_Colour();
////		    M_TRACER= TRACER_STAT;
////			while( (F_TRACER==TRACER_DETECTED)||(M_TRACER==TRACER_DETECTED) )
////			{
////			    FRONT_Sum_Colour();
////			    F_TRACER= TRACER_STAT;
////				MID_Sum_Colour();
////			    M_TRACER= TRACER_STAT;
////				Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER LEFT RULE=== \r\r");
////				YUME_PID_Init();
////				follow_left_counter(5);
////			}
////
////			YUME_Buzz(1);
////			Sendto_PC(USART1,"\r\r ===YUME FOLLOW EXIT LEFT RULE=== \r\r");
////			YUME_PID_Init();
////			FollowExit_Left();
////		}
////
////	}
////
////
////	else if(INITIAL_ZONE==ZONE_BLUE)
////	{
////		if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
////		{
////			YUME_Buzz(3);
////			Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER LEFT RULE=== \r\r");
////			YUME_PID_Init();
////			follow_left_counter(10);
////
////			YUME_Buzz(1);
////		    FRONT_Sum_Colour();
////		    F_TRACER= TRACER_STAT;
////			MID_Sum_Colour();
////		    M_TRACER= TRACER_STAT;
////			while( (F_TRACER==TRACER_DETECTED)||(M_TRACER==TRACER_DETECTED) )
////			{
////			    FRONT_Sum_Colour();
////			    F_TRACER= TRACER_STAT;
////				MID_Sum_Colour();
////			    M_TRACER= TRACER_STAT;
////				Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER LEFT RULE=== \r\r");
////				YUME_PID_Init();
////				follow_left_counter(5);
////			}
////
////			YUME_Buzz(1);
////			Sendto_PC(USART1,"\r\r ===YUME FOLLOW EXIT LEFT RULE=== \r\r");
////			YUME_PID_Init();
////			FollowExit_Left();
////		}
////		else
////		{
////			YUME_Buzz(1);
////			Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER RIGHT RULE=== \r\r");
////			YUME_PID_Init();
////			follow_right_counter(10);
////
////
////			YUME_Buzz(1);
////		    FRONT_Sum_Colour();
////		    F_TRACER= TRACER_STAT;
////			MID_Sum_Colour();
////		    M_TRACER= TRACER_STAT;
////			while( (F_TRACER==TRACER_DETECTED)||(M_TRACER==TRACER_DETECTED) )
////			{
////			    FRONT_Sum_Colour();
////			    F_TRACER= TRACER_STAT;
////				MID_Sum_Colour();
////			    M_TRACER= TRACER_STAT;
////				Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER RIGHT RULE=== \r\r");
////				YUME_PID_Init();
////				follow_right_counter(5);
////			}
////
////
////
////			YUME_Buzz(1);
////			Sendto_PC(USART1,"\r\r ===YUME FOLLOW EXIT RIGHT RULE=== \r\r");
////			YUME_PID_Init();
////			FollowExit_Right();
////		}
////
////	}
//
//	//VARIABLE DOOR VARIABLES RESET
//	VARIABLE_DOOR=VAR_DOOR_NOT_DETECTED;
//
//	YUME_LED_BLINK_OFF;
//
//}
//
//void follow_fire_right(void)
//{
//	if (Ping[PING_FRONT]<=10)
//	{
//		while (Ping[PING_ASKEW_RIGHT]<=15)
//		{
//			mov_rot_left(MED, FAR);
//			Get_TPA81();
//			if(FIRE==1) YUME_Found_Fire();
//		}
//
//		if (Ping[PING_ASKEW_RIGHT]>15)
//		{
//			mov_rot_right(MED, FAR);
//			Get_TPA81();
//			if(FIRE==1) YUME_Found_Fire();
//		}
//	}
//	else PID_follow_fire_right();
//}
//
//void PID_follow_fire_right(void)
//{
//	PID_Calc();
//
//	//KONDISI ROBOT SESUAI
//	if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//		{
//			mov_fwd_5cm(5, MED);
//			Get_TPA81();
//			if(FIRE==1) YUME_Found_Fire();
//		}
//
//	//KONDISI ROBOT JAUH DARI DINDING
//	else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//		{
//			if (PID_F_R.pid_value[0]>=3) PID_F_R.pid_value[0]=3; //windup
//
//			if ((PID_F_R.pid_value[0]<1)&&(PID_F_R.pid_value[0]>=0))
//				{
//					mov_fwd_5cm(5, MED);
//					Get_TPA81();
//					if(FIRE==1) YUME_Found_Fire();
//				}
//			else SearchFire_curve_right(MED, FAR, &PID_F_R.pid_value[0]);
//		}
//
//	//KONDISI ROBOT DEKAT DENGAN DINDING
//	else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//		{
//			if (PID_F_R.pid_value[0]>=3) PID_F_R.pid_value[0]=3; //windup
//			if ((PID_F_R.pid_value[0]<1)&&(PID_F_R.pid_value[0]>=0))
//				{
//					mov_fwd_5cm(5, MED);
//					Get_TPA81();
//					if(FIRE==1) YUME_Found_Fire();
//				}
//			SearchFire_curve_left(MED, FAR, &PID_F_R.pid_value[0]);
//		}
//}
//
//void follow_fire_left(void)
//{
//	if (Ping[PING_FRONT]<=10)
//	{
//		while (Ping[PING_ASKEW_LEFT]<=15)
//		{
//			mov_rot_right(MED, FAR);
//			Get_TPA81();
//			if(FIRE==1) YUME_Found_Fire();
//		}
//
//		if (Ping[PING_ASKEW_LEFT]>15)
//		{
//			mov_rot_left(MED, FAR);
//			Get_TPA81();
//			if(FIRE==1) YUME_Found_Fire();
//		}
//	}
//	else PID_follow_fire_left();
//}
//
//void PID_follow_fire_left(void)
//{
//	PID_Calc_LeftRule();
//
//	//KONDISI ROBOT SESUAI
//	if ( Ping[PING_ASKEW_LEFT]==PID_F_L.set_point )
//		{
//			mov_fwd_5cm(5, MED);
//			Get_TPA81();
//			if(FIRE==1) YUME_Found_Fire();
//		}
//
//	//KONDISI ROBOT JAUH DARI DINDING
//	else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//		{
//			if (PID_F_L.pid_value[0]>=7) PID_F_L.pid_value[0]=7; //windup
//
//			if ((PID_F_L.pid_value[0]<1)&&(PID_F_L.pid_value[0]>=0))
//				{
//					mov_fwd_5cm(5, MED);
//					Get_TPA81();
//					if(FIRE==1) YUME_Found_Fire();
//				}
//			else SearchFire_curve_left(MED, FAR, &PID_F_R.pid_value[0]);
//
//		}
//
//	//KONDISI ROBOT DEKAT DENGAN DINDING
//	else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//		{
//			if (PID_F_L.pid_value[0]>=7) PID_F_L.pid_value[0]=7; //windup
//			if ((PID_F_L.pid_value[0]<1)&&(PID_F_L.pid_value[0]>=0))
//				{
//					mov_fwd_5cm(5, MED);
//					Get_TPA81();
//					if(FIRE==1) YUME_Found_Fire();
//				}
//			else SearchFire_curve_right(MED, FAR, &PID_F_R.pid_value[0]);
//		}
//}
//
//
//void SearchFire_curve_right(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	int counter;
//	//int limit= *COMMAND_LOOP;
//
//	for(counter=1;counter<=*COMMAND_LOOP;counter++)
//	{
//		Get_TPA81();
//		if(FIRE==1) YUME_Found_Fire();
//		mov_curve_right_fire(MED,FAR);
//	}
//
//}
//
//void SearchFire_curve_left(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	int counter;
//	//int limit= *COMMAND_LOOP;
//
//	for(counter=1;counter<=*COMMAND_LOOP;counter++)
//	{
//		Get_TPA81();
//		if(FIRE==1) YUME_Found_Fire();
//		mov_curve_left_fire(MED,FAR);
//	}
//
//}
//
//
//void mov_curve_right_fire(int SPEED, int STEP)
//{
//	Sendto_PC(USART1,"YUME Curve Right Movement \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//
//	//gait_mode(CURVE_RIGHT, SPEED);
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3],10,leg-3);
//	inv_kine(middle_left,90+beta[1],10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5],10,leg-3);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//2
//	inv_kine(front_left,90+beta[0]+15,7,leg);
//	inv_kine(front_right,90-beta[3]+10,10,leg-3);
//	inv_kine(middle_left,90-beta[1]-15,10,leg-3);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+15,7,leg);
//	inv_kine(rear_right,90-beta[5]+10,10,leg-3);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//3
//	inv_kine(front_left,90+beta[0]+15,7,leg);
//	inv_kine(front_right,90-beta[3]+10,7,leg);
//	inv_kine(middle_left,90-beta[1]-15,7,leg);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+15,7,leg);
//	inv_kine(rear_right,90-beta[5]+10,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//4
//	inv_kine(front_left,90+beta[0]+15,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4],10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]+15,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//5
//	inv_kine(front_left,90-beta[0]-15,10,leg-3);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+15,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]-15,10,leg-3);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//6
//	inv_kine(front_left,90-beta[0]-15,7,leg);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+15,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,7,leg);
//	inv_kine(rear_left,90-beta[2]-15,7,leg);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//}
//
//
//void mov_curve_left_fire(int SPEED, int STEP)
//{
//	Sendto_PC(USART1,"YUME Curve Left Movement \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//gait_mode(CURVE_LEFT, SPEED);
//
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3]+15,10,leg-3);
//	inv_kine(middle_left,90+beta[1]-10,10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5]+15,10,leg-3);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//2
//	inv_kine(front_left,90+beta[0]-10,7,leg);
//	inv_kine(front_right,90-beta[3]-15,10,leg-3);
//	inv_kine(middle_left,90-beta[1]+10,10,leg-3);
//	inv_kine(middle_right,90+beta[4]+15,7,leg);
//	inv_kine(rear_left,90+beta[2]-10,7,leg);
//	inv_kine(rear_right,90-beta[5]-15,10,leg-3);
//	delay_ms(SPEED);
//
//
//	Get_TPA81();
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//3
//	inv_kine(front_left,90+beta[0]-10,7,leg);
//	inv_kine(front_right,90-beta[3]-15,7,leg);
//	inv_kine(middle_left,90-beta[1]+10,7,leg);
//	inv_kine(middle_right,90+beta[4]+15,7,leg);
//	inv_kine(rear_left,90+beta[2]-10,7,leg);
//	inv_kine(rear_right,90-beta[5]-15,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//4
//	inv_kine(front_left,90+beta[0]-10,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4]+15,10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]-10,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//5
//	inv_kine(front_left,90-beta[0]+10,10,leg-3);
//	inv_kine(front_right,90+beta[3]+15,7,leg);
//	inv_kine(middle_left,90+beta[1]-10,7,leg);
//	inv_kine(middle_right,90-beta[4]-15,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]+10,10,leg-3);
//	inv_kine(rear_right,90+beta[5]+15,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//6
//	inv_kine(front_left,90-beta[0]+10,7,leg);
//	inv_kine(front_right,90+beta[3]+15,7,leg);
//	inv_kine(middle_left,90+beta[1]-10,7,leg);
//	inv_kine(middle_right,90-beta[4]-15,7,leg);
//	inv_kine(rear_left,90-beta[2]+10,7,leg);
//	inv_kine(rear_right,90+beta[5]+15,7,leg);
//	delay_ms(SPEED);
//}
//
//void YUME_Extinguisher(void)
//{
//	Sendto_PC(USART1,"YUME Hexapod Search Fire Sequences \r");
//
//	YUME_Buzz(4);
////	mov_bwd(5,MED);
//
////	YUME_HydroPump ();
////	EXTINGUISHER_FLAG=1;
//
//	static int right=90,left=90;
//
//	YUME_Buzz(4);
//	EXTINGUISHER_ON;
//	delay_ms(2000);
//
//	generate_movement_data(0,0,10);
//	delay_ms(50);
//
//	while(right>=20&&left<=160&&UV_state==0)
//	{
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(20);
//		right-=5;
//		left+=5;
//		if(UV_state==1) break;
//	}
//	delay_ms(100);
//
//	while(right<=90&&left>=90&&UV_state==0)
//	{
//	    inv_kine(front_left,left,7,leg);
//	    inv_kine(front_right,right,7,leg);
//	    inv_kine(middle_left,left,7,leg);
//	    inv_kine(middle_right,right,7,leg);
//	    inv_kine(rear_left,left,7,leg);
//	    inv_kine(rear_right,right,7,leg);
//	    delay_ms(20);
//	    right+=5;
//	    left-=5;
//	    if(UV_state==1) break;
//	}
//	delay_ms(100);
//
//	while(right<=160&&left>=20&&UV_state==0)
//	{
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(20);
//		right+=5;
//		left-=5;
//		if(UV_state==1) break;
//	}
//	delay_ms(100);
//
//	while(right>=90&&left<=90&&UV_state==0)
//	{
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(20);
//		right-=5;
//		left+=5;
//		if(UV_state==1) break;
//	}
//	delay_ms(100);
//
//
//
////		while(right>=20&&left<=160&&UV_state==0)
////		{
////			inv_kine(front_left,left,7,leg);
////			inv_kine(front_right,right,7,leg);
////			inv_kine(middle_left,left,7,leg);
////			inv_kine(middle_right,right,7,leg);
////			inv_kine(rear_left,left,7,leg);
////			inv_kine(rear_right,right,7,leg);
////			delay_ms(10);
////			right-=3;
////			left+=3;
////			if(UV_state==1) break;
////		}
////		delay_ms(100);
////
////		while(right<=90&&left>=90&&UV_state==0)
////		{
////		    inv_kine(front_left,left,7,leg);
////		    inv_kine(front_right,right,7,leg);
////		    inv_kine(middle_left,left,7,leg);
////		    inv_kine(middle_right,right,7,leg);
////		    inv_kine(rear_left,left,7,leg);
////		    inv_kine(rear_right,right,7,leg);
////		    delay_ms(10);
////		    right+=3;
////		    left-=3;
////		    if(UV_state==1) break;
////		}
////		delay_ms(100);
////
////		while(right<=160&&left>=20&&UV_state==0)
////		{
////			inv_kine(front_left,left,7,leg);
////			inv_kine(front_right,right,7,leg);
////			inv_kine(middle_left,left,7,leg);
////			inv_kine(middle_right,right,7,leg);
////			inv_kine(rear_left,left,7,leg);
////			inv_kine(rear_right,right,7,leg);
////			delay_ms(10);
////			right+=3;
////			left-=3;
////			if(UV_state==1) break;
////		}
////		delay_ms(100);
////
////		while(right>=90&&left<=90&&UV_state==0)
////		{
////			inv_kine(front_left,left,7,leg);
////			inv_kine(front_right,right,7,leg);
////			inv_kine(middle_left,left,7,leg);
////			inv_kine(middle_right,right,7,leg);
////			inv_kine(rear_left,left,7,leg);
////			inv_kine(rear_right,right,7,leg);
////			delay_ms(10);
////			right-=3;
////			left+=3;
////			if(UV_state==1) break;
////		}
////		delay_ms(200);
//
////	YUME_BLDC_OFF;
//	EXTINGUISHER_OFF;
//	EXTINGUISHER_FLAG=1;
//
//
//}
//
//
//void Cat_Avoider(void)
//{
//	Get_IR();
//	CAT_FOUND[CAT_PREVIOUS] = CAT_FOUND[CAT_PRESENT];
////	if(((INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)) && (Ping[PING_FRONT]>=25))
//	if(
//		 ( (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) ) &&
//		 ( (INFRARED[IR_FRONT_MIDDLE]==IR_NOT_DETECTED) || (Ping[PING_FRONT]>= 30) )
//	  )
//	{
//		CAT_FOUND[CAT_PRESENT]++;
//
//		/*
//		 * SET SPECIAL CONDITION VARIABLES
//		 */
//		if(ROOM_COUNTER<=1)
//		{
//			//SPECIAL_CONDITION_FLAG= SPECIAL_CONDITION_ENABLED;
//			FIRST_CAT_ENCOUNTER=CAT_DETECTED;
//			YUME_CROSSING_AUTHORITY= CROSS_DISABLED;
//		}
//	}
//
////	Sendto_PC(USART1,"\r CAT_FOUND[CAT_PREVIOUS]: %d \r CAT_FOUND[CAT_PRESENT]: %d \r" ,CAT_FOUND[CAT_PREVIOUS],CAT_FOUND[CAT_PRESENT]);
////	Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r\r",CAT_SHIFT_FOLLOW);
//
//	if (
//			((INFRARED[IR_FRONT_LEFT]==IR_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED)) &&
//			( (INFRARED[IR_FRONT_MIDDLE]==IR_NOT_DETECTED) && (Ping[PING_FRONT]>= 30) )
//		)
//	{
//		if(CAT_FOUND[CAT_PREVIOUS]!=CAT_FOUND[CAT_PRESENT]) CAT_SHIFT_FOLLOW=SHIFT_FOLLOW;
////		else if(CAT_FOUND[CAT_PREVIOUS]==CAT_FOUND[CAT_PRESENT]) CAT_SHIFT_FOLLOW=NO_SHIFT;
//		Sendto_PC(USART1,"\r YUME DETECTING CAT OBSTACLE! \r CAT_FOUND[CAT_PREVIOUS]: %d \r CAT_FOUND[CAT_PRESENT]: %d \r" ,CAT_FOUND[CAT_PREVIOUS],CAT_FOUND[CAT_PRESENT]);
//		Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r\r",CAT_SHIFT_FOLLOW);
//
//		YUME_Buzz(2);
//		YUME_Buzz(2);
//		//YUME_Buzz(3);
//
//		Get_IR();
//		mov_bwd(15,MED);
//
//		Evade_Wall_Room();
//
//		if (INITIAL_ZONE==ZONE_BLUE)
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//
//			Get_IR();
//			while ( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (Ping[PING_FRONT]< 30) )
//			{
//				mov_rot_right(MED,FAR);
//				mov_rot_right(MED,FAR);
//				mov_rot_right(MED,FAR);
//				Get_IR();
//			}
//			follow_left_counter(10);
//		}
//
//		else if (INITIAL_ZONE==ZONE_RED)
//		{
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//
//			Get_IR();
//			while ( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (Ping[PING_FRONT]< 30) )
//			{
//				mov_rot_left(MED,FAR);
//				mov_rot_left(MED,FAR);
//				mov_rot_left(MED,FAR);
//				Get_IR();
//			}
//			follow_right_counter(10);
//		}
//
//
//
//
////		if (Ping[PING_RIGHT]<=Ping[PING_LEFT])
////		{
////			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
////
////			Get_IR();
////			while ( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (Ping[PING_FRONT]< 30) )
////			{
////				mov_rot_right(MED,FAR);
////				mov_rot_right(MED,FAR);
////				mov_rot_right(MED,FAR);
////				Get_IR();
////			}
////			follow_left_counter(10);
////		}
//
////		else if (Ping[PING_LEFT]<Ping[PING_RIGHT])
////		{
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////
////			Get_IR();
////			while ( (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) || (Ping[PING_FRONT]< 30) )
////			{
////				mov_rot_left(MED,FAR);
////				mov_rot_left(MED,FAR);
////				mov_rot_left(MED,FAR);
////				Get_IR();
////			}
////			follow_right_counter(10);
////		}
//
//	}
//}
//
///*
// * func  : void mov_fwd_5cm (int distance, int SPEED)
// * brief : convert (int) distance into forward locomotion
// * param : (int) distance is prescaled by 5
// * Ver   : 4
// * 		   Configured for the new YUME's mechanical
// *		   Last Revised By: Ryan (Thursday, August 28, 2015
// * programmer's note  : theoretically, robot should move 5 cm in each iteration,
// * 					    but in the actual case, it just move for about 4.75 cm
// * 					    (case: mov_fwd_5cm(20,FAST) -> YUME moves forward only 18 cm
// *
// */
//void mov_fwd_trace (int distance, int SPEED)
//{
//	Sendto_PC(USART1,"YUME Forward Movement 5 cm \r");
//	int limit= distance/5;
//	int loop;
//	//if (STEP==FAR)       { limit= distance/5; generate_movement_data(0,5,10);}
//	//else if (STEP==HALF) { limit= distance/3; generate_movement_data(0,3,10);}
//	//else if (STEP=CLOSE) { limit= distance/2; generate_movement_data(0,2,10);}
//
//	generate_movement_data(0,5,10);
//	delay_ms(50);
//	for (loop=1;loop<=limit;loop++)
//		{
//			//gait_mode(FORWARD, &SPEED);
//			//1
//			inv_kine(front_left,90,7,leg);
//			inv_kine(front_right,90+beta[3],10,leg-3);
//			inv_kine(middle_left,90+beta[1],10,leg-3);
//			inv_kine(middle_right,90,7,leg);
//			inv_kine(rear_left,90,7,leg);
//			inv_kine(rear_right,90+beta[5],10,leg-3);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
////			if(TRACER_STAT==1){YUME_Success();}
//
//
//			//2
//			inv_kine(front_left,90+beta[0],7,leg);
//			inv_kine(front_right,90-beta[3],10,leg-3);
//			inv_kine(middle_left,90-beta[1],10,leg-3);
//			inv_kine(middle_right,90+beta[4],7,leg);
//			inv_kine(rear_left,90+beta[2],7,leg);
//			inv_kine(rear_right,90-beta[5],10,leg-3);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
////			if(TRACER_STAT==1){YUME_Success();}
//
//			//3
//			inv_kine(front_left,90+beta[0],7,leg);
//			inv_kine(front_right,90-beta[3],7,leg);
//			inv_kine(middle_left,90-beta[1],7,leg);
//			inv_kine(middle_right,90+beta[4],7,leg);
//			inv_kine(rear_left,90+beta[2],7,leg);
//			inv_kine(rear_right,90-beta[5],7,leg);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
////			if(TRACER_STAT==1){YUME_Success();}
//
//			//4
//			inv_kine(front_left,90+beta[0],10,leg-3);
//			inv_kine(front_right,90,7,leg);
//			inv_kine(middle_left,90,7,leg);
//			inv_kine(middle_right,90+beta[4],10,leg-3);
//			inv_kine(rear_left,90+beta[2],7,leg-2);
//			inv_kine(rear_right,90,7,leg);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
////			if(TRACER_STAT==1){YUME_Success();}
//
//			//5
//			inv_kine(front_left,90-beta[0],10,leg-3);
//			inv_kine(front_right,90+beta[3],7,leg);
//			inv_kine(middle_left,90+beta[1],7,leg);
//			inv_kine(middle_right,90-beta[4],10,leg-3);
//			inv_kine(rear_left,90-beta[2],7,leg-2);
//			inv_kine(rear_right,90+beta[5],7,leg);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
////			if(TRACER_STAT==1){YUME_Success();}
//
//			//6
//			inv_kine(front_left,90-beta[0],7,leg);
//			inv_kine(front_right,90+beta[3],7,leg);
//			inv_kine(middle_left,90+beta[1],7,leg);
//			inv_kine(middle_right,90-beta[4],7,leg);
//			inv_kine(rear_left,90-beta[2],7,leg);
//			inv_kine(rear_right,90+beta[5],7,leg);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
////			if(TRACER_STAT==1){YUME_Success();}
//		}
//}
//
///*
// * Func : void mov_curve_right(int SPEED, int STEP)
// * brief: Robot's forward curve right locomotion, useful for wall following and solving the crossroad
// * Written By: Ryan (MON, MARCH 9th, 2015)
// * Ver  : 2 (Last Revised By: Ryan (MON, August 19th, 2015)
// *   	     sudut belok dikurangi (yang lama sering bermasalah untuk follow)
// * programmer's note  :
// */
//void mov_curve_right_trace(int SPEED, int STEP)
//{
//	Sendto_PC(USART1,"YUME Curve Right Movement \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//
//	//gait_mode(CURVE_RIGHT, SPEED);
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3],10,leg-3);
//	inv_kine(middle_left,90+beta[1],10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5],10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//2
//	inv_kine(front_left,90+beta[0]+15,7,leg);
//	inv_kine(front_right,90-beta[3]+10,10,leg-3);
//	inv_kine(middle_left,90-beta[1]-15,10,leg-3);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+15,7,leg);
//	inv_kine(rear_right,90-beta[5]+10,10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//3
//	inv_kine(front_left,90+beta[0]+15,7,leg);
//	inv_kine(front_right,90-beta[3]+10,7,leg);
//	inv_kine(middle_left,90-beta[1]-15,7,leg);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+15,7,leg);
//	inv_kine(rear_right,90-beta[5]+10,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//4
//	inv_kine(front_left,90+beta[0]+15,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4],10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]+15,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//5
//	inv_kine(front_left,90-beta[0]-15,10,leg-3);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+15,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]-15,10,leg-3);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//6
//	inv_kine(front_left,90-beta[0]-15,7,leg);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+15,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,7,leg);
//	inv_kine(rear_left,90-beta[2]-15,7,leg);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//}
//
///*
// * Func : void mov_curve_left(int SPEED, int STEP)
// * brief: Robot's forward curve right locomotion, useful for wall following and solving the crossroad
// * Written By: Ryan (MON, MARCH 9th, 2015)
// * Ver  : 2 (Last Revised By: Ryan (MON, August 19th, 2015)
// *   	     sudut belok dikurangi (yang lama sering bermasalah untuk follow)
// * programmer's note  :
// */
//void mov_curve_left_trace(int SPEED, int STEP)
//{
//	Sendto_PC(USART1,"YUME Curve Left Movement \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//gait_mode(CURVE_LEFT, SPEED);
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3]+15,10,leg-3);
//	inv_kine(middle_left,90+beta[1]-10,10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5]+15,10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//2
//	inv_kine(front_left,90+beta[0]-10,7,leg);
//	inv_kine(front_right,90-beta[3]-15,10,leg-3);
//	inv_kine(middle_left,90-beta[1]+10,10,leg-3);
//	inv_kine(middle_right,90+beta[4]+15,7,leg);
//	inv_kine(rear_left,90+beta[2]-10,7,leg);
//	inv_kine(rear_right,90-beta[5]-15,10,leg-3);
//	delay_ms(SPEED);
//
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//3
//	inv_kine(front_left,90+beta[0]-10,7,leg);
//	inv_kine(front_right,90-beta[3]-15,7,leg);
//	inv_kine(middle_left,90-beta[1]+10,7,leg);
//	inv_kine(middle_right,90+beta[4]+15,7,leg);
//	inv_kine(rear_left,90+beta[2]-10,7,leg);
//	inv_kine(rear_right,90-beta[5]-15,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//4
//	inv_kine(front_left,90+beta[0]-10,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4]+15,10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]-10,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//5
//	inv_kine(front_left,90-beta[0]+10,10,leg-3);
//	inv_kine(front_right,90+beta[3]+15,7,leg);
//	inv_kine(middle_left,90+beta[1]-10,7,leg);
//	inv_kine(middle_right,90-beta[4]-15,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]+10,10,leg-3);
//	inv_kine(rear_right,90+beta[5]+15,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	if(TRACER_STAT==1){YUME_Success();}
//	//6
//	inv_kine(front_left,90-beta[0]+10,7,leg);
//	inv_kine(front_right,90+beta[3]+15,7,leg);
//	inv_kine(middle_left,90+beta[1]-10,7,leg);
//	inv_kine(middle_right,90-beta[4]-15,7,leg);
//	inv_kine(rear_left,90-beta[2]+10,7,leg);
//	inv_kine(rear_right,90+beta[5]+15,7,leg);
//	delay_ms(SPEED);
//}
//
//void YUME_ROOM(void)
//{
//	FIRE_PUTOFF=0;
//	WARZONE_FLAG=0;
//	UV_state=1;
//	UV_Lock=0;
//	firetrack_counter=0;
//
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		YUME_Buzz(2);
//		Get_UV();
//		Get_UV();
//
//		YUME_FireScan();
//
////		YUME_Tracer_Check();
////		if( (F_DETECTED_COLOUR==COLOUR_RED) || (M_DETECTED_COLOUR==COLOUR_RED) ||
////		    (F_DETECTED_COLOUR==COLOUR_BLUE) || (M_DETECTED_COLOUR==COLOUR_BLUE)
////		  )
////		{
////			WARZONE_FLAG=1;
////			Sendto_PC(USART1,"\r WARZONE FLAG: %d \r",WARZONE_FLAG);
////		}
//
////		if (WARZONE_FLAG==1)
////		{
////			YUME_Buzz(4);
////			if(INITIAL_ZONE==ZONE_RED)
////			{
////				if(YUME_CROSSING_STATUS==CROSSING_SUCCESS)
////				{
////					follow_right_counter(18);
////					Get_UV();
////					if( (UV_Lock==1) && (YUME_CROSSING_STATUS==CROSSING_SUCCESS) )
////					{
////						YUME_Buzz(1);
////						YUME_LED_BLINK_ON;
////						follow_right_counter(18);
////						Evade_Wall_Room_Blue();
////						mov_rotleft_fire(MED,FAR);
////						mov_rotleft_fire(MED,FAR);
////						mov_rotleft_fire(MED,FAR);
//////						mov_rot_left(MED,FAR);
//////						mov_rot_left(MED,FAR);
//////						mov_rot_left(MED,FAR);
//////						mov_rot_left(MED,FAR);
////						YUME_Buzz(1);
////						YUME_FireFight();
////					}
////				}
////
////				else
////				{
////					mov_fwd_5cm(15,FAST_LEVEL_3);
////					Sendto_PC(USART1,"YUME ESCAPE WARZONE! \r");
////					Escape_Warzone();
////					ROOM1_FLAG=1;
////					WARZONE_COUNTER++;
////				}
////
////			}
////
////
////			else if(INITIAL_ZONE==ZONE_BLUE)
////			{
////				if(YUME_CROSSING_STATUS==CROSSING_SUCCESS)
////				{
////					follow_left_counter(15);
////
////					Get_UV();
////					if( (UV_Lock==1) && (YUME_CROSSING_STATUS==CROSSING_SUCCESS) )
////					{
////						YUME_Buzz(1);
////						YUME_LED_BLINK_ON;
////						follow_left_counter(18);
////						Evade_Wall_Room_Red();
////						mov_rotright_fire(MED,FAR);
////						mov_rotright_fire(MED,FAR);
////						mov_rotright_fire(MED,FAR);
//////						mov_rot_right(MED,FAR);
//////						mov_rot_right(MED,FAR);
//////						mov_rot_right(MED,FAR);
//////						mov_rot_right(MED,FAR);
////						YUME_Buzz(1);
////						YUME_FireFight();
////					}
////				}
////
////				else
////				{
////					mov_fwd_5cm(15,FAST_LEVEL_3);
////					Sendto_PC(USART1,"YUME ESCAPE WARZONE! \r");
////					Escape_Warzone();
////					ROOM1_FLAG=1;
////					WARZONE_COUNTER++;
////				}
////			}
////
////
////
////		}
//
//		if( (UV_state==FIRE_DETECTED)||(UV_Lock==1) )
//		{
//			YUME_Buzz(2);
//			Sendto_PC(USART1,"YUME ON FIRE ROOM \r");
//			YUME_FireFight();
//		}
//
//		else if ( (UV_state==NO_FIRE) && (UV_Lock==0) )
//		{
//			YUME_Buzz(1);
//			mov_fwd_5cm(10,FAST_LEVEL_3);
//			Sendto_PC(USART1,"YUME ON NORMAL ROOM \r");
//
//			//Exit_No_Fire();
//
//			if(INITIAL_ZONE==ZONE_RED)
//			{
//				Exit_No_Fire_Red();
//			}
//			else if(INITIAL_ZONE==ZONE_BLUE)
//			{
//				Exit_No_Fire_Blue();
//			}
//
//
//
//		}
//	}
//}
//
//void Exit_No_Fire_Red(void)
//{
//	mov_fwd_5cm(10,FAST_LEVEL_3);
//	Evade_Wall();
//	Sendto_PC(USART1,"YUME EXIT NO FIRE RED ZONE \r");
//	Get_IR();
//
//	if(ROOM1_FLAG==0)
//	{
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
//			if(Ping[PING_FRONT]<=10) mov_bwd(5,MED);
//			Get_IR();
//		}
//
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			if(Ping[PING_FRONT]<=10) mov_bwd(5,MED);
//			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
//
//			Get_IR();
//		}
//		FollowExit_Right();
//		ROOM1_FLAG=0;
//	}
//
//	if(ROOM1_FLAG==1)
//	{
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			if(Ping[PING_FRONT]<=10) mov_bwd(5,MED);
//			Get_IR();
//		}
//
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			if(Ping[PING_FRONT]<=10) mov_bwd(5,MED);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//
//			Get_IR();
//		}
//		FollowExit_Left();
//		ROOM1_FLAG=0;
//
//	}
//
//
//}
//
//void Exit_No_Fire_Blue(void)
//{
//	mov_fwd_5cm(5,FAST_LEVEL_3);
//	Evade_Wall();
//	Sendto_PC(USART1,"YUME EXIT NO FIRE BLUE ZONE \r");
//	Get_IR();
//
//	if(ROOM1_FLAG==0)
//	{
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			if(Ping[PING_FRONT]<=10) mov_bwd(5,MED);
//			Get_IR();
//		}
//
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			if(Ping[PING_FRONT]<=10) mov_bwd(5,MED);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//
//			Get_IR();
//		}
//		FollowExit_Left();
//		ROOM1_FLAG=0;
//
//	}
//
//	else if(ROOM1_FLAG==1)
//	{
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			if(Ping[PING_FRONT]<=10) mov_bwd(5,MED);
//			Get_IR();
//		}
//
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			if(Ping[PING_FRONT]<=10) mov_bwd(5,MED);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//
//			Get_IR();
//		}
//		FollowExit_Right();
//		ROOM1_FLAG=0;
//	}
//
//
//}
//void YUME_CORRIDOR(void)
//{
//	if( (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR) )
//	{
//
//		YUME_Buzz(7);
//
//		if(WARZONE_FLAG==1)
//		{
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//
//			mov_fwd_5cm(25,FAST_LEVEL_3);
//			WARZONE_FLAG=0;
//		}
//
//		else
//		{
//			mov_fwd_5cm(10,FAST_LEVEL_3);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//		}
//
//
//
//
//		YUME_Tracer_Check();
//
//		Send_TCS3200_Status();
//		Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL DETECTING CARPET \r");
//		YUME_PID_Init();
//		FollowCarpet_Right(&COLOUR_BLACK,&NORMAL);
//
//		Send_TCS3200_Status();
//		Sendto_PC(USART1,"\rYUME FOLLOW LEFT WHILE RED CARPED DETECTED \r");
//		YUME_PID_Init();
//		FollowCarpet_Left(&COLOUR_RED,&NORMAL);
//
//		Send_TCS3200_Status();
//		Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//		YUME_PID_Init();
//		follow_right_new();
//
//		while(1)
//		{
//			mov_static();
//			delay_ms(100);
//			YUME_Buzz(7);
//		}
//
//	}
//}
///*
// * WALL FOLLOWING NEW ALGORITHM
// */
//
//
///* func      : void follow_tracer_right(void)
// * brief     : Wall following algorithm using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void follow_right_new(void)
//{
//	Cat_Avoider();
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//	while( (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR) && (CAT_SHIFT_FOLLOW==NO_SHIFT) )
//	{
//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		Cat_Avoider();
//		Evade_Wall();
//		YUME_Tracer_Check();
//
//		if (Ping[PING_FRONT]<=10)
//		{
//
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT \r");
//			mov_rot_left(MED, FAR);
//			mov_rot_left(MED, FAR);
//			mov_rot_left(MED, FAR);
//
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//
//
//		}
//		else
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			PID_follow_right_new();
//			if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		}
//	}
//
//}
//
///* func      : void PID_follow_tracer_right(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_follow_right_new(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//	OVERRIDE=0;
//
//	Cat_Avoider();
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//
//	while( (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR) && (CAT_SHIFT_FOLLOW==NO_SHIFT) )
//	{
//		OVERRIDE=0;
//
//
//		while(OVERRIDE==0)
//		{
//			Cat_Avoider();
//			Evade_Wall();
//
//			YUME_Tracer_Check();
//			PID_Calc();
//
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//					if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						curve_right_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//					if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						curve_left_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//			OVERRIDE=0;
//		}
//		OVERRIDE=0;
//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//	}
//	OVERRIDE=0;
//
//}
//
//
///* func      : void folltracer_curve_right(int SPEED, int STEP, float *COMMAND_LOOP)
// * brief     : convert control signal to actuating signal in follow right until tracer
// * param     : int SPEED, int STEP, float *COMMAND_LOOP (pid_value[0])
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding PID wall following function
// *
// */
//void curve_right_new(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	Sendto_PC(USART1,"YUME Curve Right Movement \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_MR=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);
//
//
//	Cat_Avoider();
//
//	//gait_mode(CURVE_RIGHT, SPEED);
//	YUME_Tracer_Check();
//
////	YUME_Tracer_Check();
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3]-DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90+beta[1],10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5]-DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//2
//	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//3
//	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90+beta[4]-DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//4
//	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4]-DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//5
//	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
//	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]+DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//6
//	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90+beta[3]-DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90+beta[5]-DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: CORRIDOR  \r");
//	}
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: ROOM  \r");
//	}
//}
//
///* func      : void folltracer_curve_left(int SPEED, int STEP, float *COMMAND_LOOP)
// * brief     : convert control signal to actuating signal in follow right until tracer
// * param     : int SPEED, int STEP, float *COMMAND_LOOP (pid_value[0])
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding PID wall following function
// *
// */
//void curve_left_new(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	Sendto_PC(USART1,"YUME Curve Left Movement \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);
//
//	Cat_Avoider();
////	YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////	if(TRACER_STAT==1){YUME_Success();}
//
//	//gait_mode(CURVE_LEFT, SPEED);
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//    YUME_Tracer_Check();
////    YUME_Tracer_Check();
//	//2
//	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//3
//	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
//	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//4
//	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//5
//	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//	//6
//	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
//	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
////	YUME_Tracer_Check();
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: CORRIDOR  \r");
//	}
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: ROOM  \r");
//	}
//}
//
//
//void CandleCircle_Check(void)
//{
//	if ( (M_TRACER==TRACER_DETECTED) && (M_TRACER==TRACER_DETECTED) &&
//	     ( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) )
//	   )
//	{
//		Sendto_PC(USART1,"CANDLE CIRCLE DETECTED on CandleCircle_Check! \r");
//
//		while(UV_Lock==1)
//		{
//			YUME_Search_Fire();
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//		}
//
//		//YUME_Found_Fire();
//	}
//}
//
//void followfire_right_new(void)
//{
//
//		Sendto_PC(USART1,"UV_state: %d \r",UV_state);
//		Sendto_PC(USART1,"UV_Lock: %d \r",UV_Lock);
//		Sendto_PC(USART1,"EXTINGUISHED FIRE : %d \r",EXTINGUISHED_FIRE);
//
////		Evade_Wall();
////		Evade_Wall_Room();
//		if(INITIAL_ZONE==ZONE_BLUE)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Red();
//			}
//			else Evade_Wall_Room_Blue();
//		}
//		else if(INITIAL_ZONE==ZONE_RED)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Blue();
//			}
//
//			else Evade_Wall_Room_Red();
//		}
//
////		CandleCircle_Check();
//		if (Ping[PING_FRONT]<=17)
//		{
//			if(INITIAL_ZONE==ZONE_BLUE)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Red();
//				}
//				else Evade_Wall_Room_Blue();
//			}
//			else if(INITIAL_ZONE==ZONE_RED)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Blue();
//				}
//
//				else Evade_Wall_Room_Red();
//			}
////			Evade_Wall();
////			CandleCircle_Check();
////			if (Ping[PING_RIGHT]>=Ping[PING_LEFT])
////			{
////				Evade_Wall_Room_Blue();
//////				Evade_Wall();
////				CandleCircle_Check();
////				Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_right\r");
////				mov_rotright_fire(FAST, FAR);
////				mov_rotright_fire(FAST, FAR);
////			}
////
////			if (Ping[PING_LEFT]>Ping[PING_RIGHT])
////			{
////				Evade_Wall_Room_Blue();
//////				Evade_Wall();
////				CandleCircle_Check();
////				Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_right\r");
////				mov_rotleft_fire(FAST, FAR);
////				mov_rotleft_fire(FAST, FAR);
////			}
//
//			if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//			{
////				CandleCircle_Check();
//				Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_right\r");
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//				mov_rotright_fire(FAST_LEVEL_3,FAR);
//			}
//			else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//			{
////				CandleCircle_Check();
//				Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_right\r");
//				mov_rotleft_fire(FAST_LEVEL_3,FAR);
//				mov_rotleft_fire(FAST_LEVEL_3,FAR);
//				mov_rotleft_fire(FAST_LEVEL_3,FAR);
//			}
//
//
//
//		}
//		else PID_followfire_right_new();
//
//
//
//}
//
//void PID_followfire_right_new(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//
//	if(INITIAL_ZONE==ZONE_BLUE)
//	{
//		if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//		{
//			Evade_Wall_Room_Red();
//		}
//		else Evade_Wall_Room_Blue();
//	}
//	else if(INITIAL_ZONE==ZONE_RED)
//	{
//		if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//		{
//			Evade_Wall_Room_Blue();
//		}
//
//		else Evade_Wall_Room_Red();
//	}
////
////	Evade_Wall();
////	Evade_Wall_Room();
////	CandleCircle_Check();
//	while(OVERRIDE==0)
//	{
//		if(FIRE_PUTOFF==1) break;
//		Sendto_PC(USART1,"firetrack_counter: %d \r",firetrack_counter);
//		if(firetrack_counter>=4)
//		{
//			if(INITIAL_ZONE==ZONE_BLUE)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Red();
//				}
//				else Evade_Wall_Room_Blue();
//			}
//			else if(INITIAL_ZONE==ZONE_RED)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Blue();
//				}
//
//				else Evade_Wall_Room_Red();
//			}
////			Evade_Wall();
////			Evade_Wall_Room();
//			YUME_FireTracker();
//
////			Evade_Wall_Room_Blue();
////
////			mov_rotright_fire(FAST,FAR);
////			mov_rotright_fire(FAST,FAR);
////			mov_rotright_fire(FAST,FAR);
//
//			if(INITIAL_ZONE==ZONE_BLUE)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Red();
//				}
//				else Evade_Wall_Room_Blue();
//			}
//			else if(INITIAL_ZONE==ZONE_RED)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Blue();
//				}
//
//				else Evade_Wall_Room_Red();
//			}
//
////			YUME_FireTracker();
//			firetrack_counter=0;
//		}
//		firetrack_counter++;
//
//
////		CandleCircle_Check();
//		if(INITIAL_ZONE==ZONE_BLUE)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Red();
//			}
//			else Evade_Wall_Room_Blue();
//		}
//		else if(INITIAL_ZONE==ZONE_RED)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Blue();
//			}
//
//			else Evade_Wall_Room_Red();
//		}
////		Evade_Wall();
////		Evade_Wall_Room();
//		PID_Calc();
//		//KONDISI ROBOT SESUAI
//		//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//		if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//			{
////				Evade_Wall_Room_Blue();
////				Evade_Wall();
//				if(FIRE_PUTOFF==1) break;
//
//				if (Ping[PING_FRONT]<=17)
//				{
////					CandleCircle_Check();
////					if (Ping[PING_RIGHT]>=Ping[PING_LEFT])
////					{
////						Evade_Wall_Room_Blue();
//////						Evade_Wall();
////						CandleCircle_Check();
////						Sendto_PC(USART1,"YUME ROTATE LEFT in PID_follow_fire_right\r");
////						mov_rotright_fire(FAST, FAR);
////						mov_rotright_fire(FAST, FAR);
////						OVERRIDE=1;
////					}
////
////					if (Ping[PING_LEFT]>Ping[PING_RIGHT])
////					{
////						Evade_Wall_Room_Blue();
//////						Evade_Wall();
////						CandleCircle_Check();
////						Sendto_PC(USART1,"YUME ROTATE RIGHT in PID_follow_fire_right\r");
////						mov_rotleft_fire(FAST, FAR);
////						mov_rotleft_fire(FAST, FAR);
////						OVERRIDE=1;
////					}
//
//					if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//					{
////						CandleCircle_Check();
//						Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_right\r");
//						mov_rotright_fire(FAST_LEVEL_3,FAR);
//						mov_rotright_fire(FAST_LEVEL_3,FAR);
//						mov_rotright_fire(FAST_LEVEL_3,FAR);
//						OVERRIDE=1;
//					}
//					else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//					{
////						CandleCircle_Check();
//						Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_right\r");
//						mov_rotleft_fire(FAST_LEVEL_3,FAR);
//						mov_rotleft_fire(FAST_LEVEL_3,FAR);
//						mov_rotleft_fire(FAST_LEVEL_3,FAR);
//						OVERRIDE=1;
//					}
//				}
//
//				if(OVERRIDE==1){break;}
//
//				if (OVERRIDE==0)
//				{
//					if(INITIAL_ZONE==ZONE_BLUE)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Red();
//						}
//						else Evade_Wall_Room_Blue();
//					}
//					else if(INITIAL_ZONE==ZONE_RED)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Blue();
//						}
//
//						else Evade_Wall_Room_Red();
//					}
////					Evade_Wall();
////					CandleCircle_Check();
//					Sendto_PC(USART1,"YUME FORWARD in PID_follow_fire_right\r");
//					Mov_Fwd_Trace(5, FAST_LEVEL_3);
//				}
//			}
//
//		//KONDISI ROBOT JAUH DARI DINDING
//		else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//			{
//				if(FIRE_PUTOFF==1) break;
//
//				if(INITIAL_ZONE==ZONE_BLUE)
//				{
//					if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//					{
//						Evade_Wall_Room_Red();
//					}
//					else Evade_Wall_Room_Blue();
//				}
//				else if(INITIAL_ZONE==ZONE_RED)
//				{
//					if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//					{
//						Evade_Wall_Room_Blue();
//					}
//
//					else Evade_Wall_Room_Red();
//				}
////				CandleCircle_Check();
////				Evade_Wall_Room_Blue();
////				Evade_Wall();
////				Evade_Wall_Room();
//				if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//
//				if ((PID_F_R.pid_value[0]<1)&&(PID_F_R.pid_value[0]>=0))
//				{
//					Sendto_PC(USART1,"PID VALUE FOLLOW FIRE CURVE RIGHT ERROR \r");
//					Mov_Fwd_Trace(5,FAST_LEVEL_3);
//				}
//
//				else
//				{
//					if(INITIAL_ZONE==ZONE_BLUE)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Red();
//						}
//						else Evade_Wall_Room_Blue();
//					}
//					else if(INITIAL_ZONE==ZONE_RED)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Blue();
//						}
//
//						else Evade_Wall_Room_Red();
//					}
////					Evade_Wall();
////					CandleCircle_Check();
//
//					if (Ping[PING_FRONT]<=17)
//					{
////						CandleCircle_Check();
////						if (Ping[PING_RIGHT]>=Ping[PING_LEFT])
////						{
////							Evade_Wall_Room_Blue();
//////							Evade_Wall();
////							CandleCircle_Check();
////							Sendto_PC(USART1,"YUME ROTATE LEFT in PID_follow_fire_right\r");
////							mov_rotright_fire(FAST, FAR);
////							mov_rotright_fire(FAST, FAR);
////							OVERRIDE=1;
////						}
////
////						if (Ping[PING_LEFT]>Ping[PING_RIGHT])
////						{
////							Evade_Wall_Room_Blue();
//////							Evade_Wall();
////							CandleCircle_Check();
////							Sendto_PC(USART1,"YUME ROTATE RIGHT in PID_follow_fire_right\r");
////							mov_rotleft_fire(FAST, FAR);
////							mov_rotleft_fire(FAST, FAR);
////							OVERRIDE=1;
////						}
//						if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//						{
////							CandleCircle_Check();
//							Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_right\r");
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							OVERRIDE=1;
//						}
//						else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//						{
////							CandleCircle_Check();
//							Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_right\r");
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							OVERRIDE=1;
//						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
////						CandleCircle_Check();
//						if(INITIAL_ZONE==ZONE_BLUE)
//						{
//							if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//							{
//								Evade_Wall_Room_Red();
//							}
//							else Evade_Wall_Room_Blue();
//						}
//						else if(INITIAL_ZONE==ZONE_RED)
//						{
//							if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//							{
//								Evade_Wall_Room_Blue();
//							}
//
//							else Evade_Wall_Room_Red();
//						}
////						Evade_Wall();
////						Evade_Wall_Room();
//						curve_right_fire_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//					}
//
//				}
//
//
//			}
//
//		//KONDISI ROBOT DEKAT DENGAN DINDING
//		else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//			{
//				if(FIRE_PUTOFF==1) break;
//
//				if(INITIAL_ZONE==ZONE_BLUE)
//				{
//					if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//					{
//						Evade_Wall_Room_Red();
//					}
//					else Evade_Wall_Room_Blue();
//				}
//				else if(INITIAL_ZONE==ZONE_RED)
//				{
//					if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//					{
//						Evade_Wall_Room_Blue();
//					}
//
//					else Evade_Wall_Room_Red();
//				}
////				CandleCircle_Check();
////				Evade_Wall_Room_Blue();
////				Evade_Wall();
//				if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//
//				if ((PID_F_R.pid_value[0]<1)&&(PID_F_R.pid_value[0]>=0))
//				{
//					Sendto_PC(USART1,"PID VALUE FOLLOW FIRE CURVE LEFT ERROR \r");
//					Mov_Fwd_Trace(5,FAST_LEVEL_3);
//				}
//
//				else
//				{
////					CandleCircle_Check();
////					Evade_Wall_Room_Blue();
//					if(INITIAL_ZONE==ZONE_BLUE)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Red();
//						}
//						else Evade_Wall_Room_Blue();
//					}
//					else if(INITIAL_ZONE==ZONE_RED)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Blue();
//						}
//
//						else Evade_Wall_Room_Red();
//					}
////					Evade_Wall();
//					if (Ping[PING_FRONT]<=17)
//					{
////						CandleCircle_Check();
////						if (Ping[PING_RIGHT]>=Ping[PING_LEFT])
////						{
////							Evade_Wall_Room_Blue();
//////							Evade_Wall();
////							CandleCircle_Check();
////							Sendto_PC(USART1,"YUME ROTATE LEFT in PID_follow_fire_right\r");
////							mov_rotright_fire(FAST, FAR);
////							mov_rotright_fire(FAST, FAR);
////							OVERRIDE=1;
////						}
////
////						if (Ping[PING_LEFT]>Ping[PING_RIGHT])
////						{
//////							Evade_Wall();
////							Evade_Wall_Room_Blue();
////							CandleCircle_Check();
////							Sendto_PC(USART1,"YUME ROTATE RIGHT in PID_follow_fire_right\r");
////							mov_rotleft_fire(FAST, FAR);
////							mov_rotleft_fire(FAST, FAR);
////							OVERRIDE=1;
////						}
//						if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//						{
////							CandleCircle_Check();
//							Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_right\r");
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							OVERRIDE=1;
//						}
//						else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//						{
////							CandleCircle_Check();
//							Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_right\r");
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							OVERRIDE=1;
//						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
////						CandleCircle_Check();
////						Evade_Wall();
////						Evade_Wall_Room();
//						if(INITIAL_ZONE==ZONE_BLUE)
//						{
//							if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//							{
//								Evade_Wall_Room_Red();
//							}
//							else Evade_Wall_Room_Blue();
//						}
//						else if(INITIAL_ZONE==ZONE_RED)
//						{
//							if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//							{
//								Evade_Wall_Room_Blue();
//							}
//
//							else Evade_Wall_Room_Red();
//						}
//						curve_left_fire_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//					}
//				}
//
//			}
//
////		Evade_Wall();
////		Evade_Wall_Room();
//		if(INITIAL_ZONE==ZONE_BLUE)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Red();
//			}
//			else Evade_Wall_Room_Blue();
//		}
//		else if(INITIAL_ZONE==ZONE_RED)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Blue();
//			}
//
//			else Evade_Wall_Room_Red();
//		}
//
////		CandleCircle_Check();
//		if(FIRE_PUTOFF==1) break;
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//}
//
//
//void followfire_left_new(void)
//{
//
//		Sendto_PC(USART1,"UV_state: %d \r",UV_state);
//		Sendto_PC(USART1,"UV_Lock: %d \r",UV_Lock);
//		Sendto_PC(USART1,"EXTINGUISHED FIRE : %d \r",EXTINGUISHED_FIRE);
//
//		if(INITIAL_ZONE==ZONE_BLUE)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Red();
//			}
//			else Evade_Wall_Room_Blue();
//		}
//		else if(INITIAL_ZONE==ZONE_RED)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Blue();
//			}
//
//			else Evade_Wall_Room_Red();
//		}
//
////		CandleCircle_Check();
//		if (Ping[PING_FRONT]<=15)
//		{
//			if(INITIAL_ZONE==ZONE_BLUE)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Red();
//				}
//				else Evade_Wall_Room_Blue();
//			}
//			else if(INITIAL_ZONE==ZONE_RED)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Blue();
//				}
//
//				else Evade_Wall_Room_Red();
//			}
//
////			if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
////			{
//////				CandleCircle_Check();
////				Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_left\r");
////				mov_rotright_fire(FAST_LEVEL_3,FAR);
////				mov_rotright_fire(FAST_LEVEL_3,FAR);
////				mov_rotright_fire(FAST_LEVEL_3,FAR);
////			}
////			else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
////			{
////				CandleCircle_Check();
////				Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_left\r");
////				mov_rotleft_fire(FAST_LEVEL_3,FAR);
////				mov_rotleft_fire(FAST_LEVEL_3,FAR);
////				mov_rotleft_fire(FAST_LEVEL_3,FAR);
////			}
//
//		}
//		else PID_followfire_left_new();
//
//}
//
//void PID_followfire_left_new(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//
//	if(INITIAL_ZONE==ZONE_BLUE)
//	{
//		if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//		{
//			Evade_Wall_Room_Red();
//		}
//		else Evade_Wall_Room_Blue();
//	}
//	else if(INITIAL_ZONE==ZONE_RED)
//	{
//		if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//		{
//			Evade_Wall_Room_Blue();
//		}
//
//		else Evade_Wall_Room_Red();
//	}
//
//	while(OVERRIDE==0)
//	{
//		if(FIRE_PUTOFF==1) break;
//		Sendto_PC(USART1,"firetrack_counter: %d \r",firetrack_counter);
//		if(firetrack_counter>=4)
//		{
//			if(INITIAL_ZONE==ZONE_BLUE)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Red();
//				}
//				else Evade_Wall_Room_Blue();
//			}
//			else if(INITIAL_ZONE==ZONE_RED)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Blue();
//				}
//
//				else Evade_Wall_Room_Red();
//			}
//
//			YUME_FireTracker();
//
////			mov_rotleft_fire(FAST,FAR);
////			mov_rotleft_fire(FAST,FAR);
////			mov_rotleft_fire(FAST,FAR);
//
//			if(INITIAL_ZONE==ZONE_BLUE)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Red();
//				}
//				else Evade_Wall_Room_Blue();
//			}
//			else if(INITIAL_ZONE==ZONE_RED)
//			{
//				if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//				{
//					Evade_Wall_Room_Blue();
//				}
//
//				else Evade_Wall_Room_Red();
//			}
//
//			YUME_FireTracker();
//			firetrack_counter=0;
//		}
//		firetrack_counter++;
//
//		if(INITIAL_ZONE==ZONE_BLUE)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Red();
//			}
//			else Evade_Wall_Room_Blue();
//		}
//		else if(INITIAL_ZONE==ZONE_RED)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Blue();
//			}
//
//			else Evade_Wall_Room_Red();
//		}
//
//		PID_Calc_LeftRule();
//
//		//KONDISI ROBOT SESUAI
//		//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//		if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//			{
////				Evade_Wall_Room_Blue();
////				Evade_Wall();
//				if(FIRE_PUTOFF==1) break;
//
//				if (Ping[PING_FRONT]<=11)
//				{
//
//					if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//					{
////						CandleCircle_Check();
//						Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_right\r");
//						mov_rotright_fire(FAST_LEVEL_3,FAR);
//						mov_rotright_fire(FAST_LEVEL_3,FAR);
//						mov_rotright_fire(FAST_LEVEL_3,FAR);
//						OVERRIDE=1;
//					}
//					else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//					{
////						CandleCircle_Check();
//						Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_right\r");
//						mov_rotleft_fire(FAST_LEVEL_3,FAR);
//						mov_rotleft_fire(FAST_LEVEL_3,FAR);
//						mov_rotleft_fire(FAST_LEVEL_3,FAR);
//						OVERRIDE=1;
//					}
//				}
//
//				if(OVERRIDE==1){break;}
//
//				if (OVERRIDE==0)
//				{
//					if(INITIAL_ZONE==ZONE_BLUE)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Red();
//						}
//						else Evade_Wall_Room_Blue();
//					}
//					else if(INITIAL_ZONE==ZONE_RED)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Blue();
//						}
//
//						else Evade_Wall_Room_Red();
//					}
//
//					Sendto_PC(USART1,"YUME FORWARD in PID_follow_fire_right\r");
//					Mov_Fwd_Trace(5, FAST_LEVEL_3);
//				}
//			}
//
//		//KONDISI ROBOT JAUH DARI DINDING
//		else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//			{
//				if(FIRE_PUTOFF==1) break;
//
//				if(INITIAL_ZONE==ZONE_BLUE)
//				{
//					if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//					{
//						Evade_Wall_Room_Red();
//					}
//					else Evade_Wall_Room_Blue();
//				}
//				else if(INITIAL_ZONE==ZONE_RED)
//				{
//					if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//					{
//						Evade_Wall_Room_Blue();
//					}
//
//					else Evade_Wall_Room_Red();
//				}
//
//				if (PID_F_L.pid_value[0]>8) PID_F_L.pid_value[0]=8; //WINDUP
//
//				if ((PID_F_L.pid_value[0]<1)&&(PID_F_L.pid_value[0]>=0))
//				{
//					Sendto_PC(USART1,"PID VALUE FOLLOW FIRE CURVE RIGHT ERROR \r");
//					Mov_Fwd_Trace(5,FAST_LEVEL_3);
//				}
//
//				else
//				{
//					if(INITIAL_ZONE==ZONE_BLUE)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Red();
//						}
//						else Evade_Wall_Room_Blue();
//					}
//					else if(INITIAL_ZONE==ZONE_RED)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Blue();
//						}
//
//						else Evade_Wall_Room_Red();
//					}
////					Evade_Wall();
////					CandleCircle_Check();
//
//					if (Ping[PING_FRONT]<=11)
//					{
//
//						if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//						{
////							CandleCircle_Check();
//							Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_right\r");
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							OVERRIDE=1;
//						}
//						else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//						{
////							CandleCircle_Check();
//							Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_right\r");
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							OVERRIDE=1;
//						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
////						CandleCircle_Check();
//						if(INITIAL_ZONE==ZONE_BLUE)
//						{
//							if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//							{
//								Evade_Wall_Room_Red();
//							}
//							else Evade_Wall_Room_Blue();
//						}
//						else if(INITIAL_ZONE==ZONE_RED)
//						{
//							if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//							{
//								Evade_Wall_Room_Blue();
//							}
//
//							else Evade_Wall_Room_Red();
//						}
//						curve_left_fire_new(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//					}
//				}
//			}
//
//		//KONDISI ROBOT DEKAT DENGAN DINDING
//		else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//			{
//				if(FIRE_PUTOFF==1) break;
//
//				if(INITIAL_ZONE==ZONE_BLUE)
//				{
//					if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//					{
//						Evade_Wall_Room_Red();
//					}
//					else Evade_Wall_Room_Blue();
//				}
//				else if(INITIAL_ZONE==ZONE_RED)
//				{
//					if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//					{
//						Evade_Wall_Room_Blue();
//					}
//
//					else Evade_Wall_Room_Red();
//				}
////				CandleCircle_Check();
////				Evade_Wall_Room_Blue();
////				Evade_Wall();
//				if (PID_F_L.pid_value[0]>8) PID_F_L.pid_value[0]=8; //WINDUP
//
//				if ((PID_F_L.pid_value[0]<1)&&(PID_F_L.pid_value[0]>=0))
//				{
//					Sendto_PC(USART1,"PID VALUE FOLLOW FIRE CURVE LEFT ERROR \r");
//					Mov_Fwd_Trace(5,FAST_LEVEL_3);
//				}
//
//				else
//				{
////					CandleCircle_Check();
////					Evade_Wall_Room_Blue();
//					if(INITIAL_ZONE==ZONE_BLUE)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Red();
//						}
//						else Evade_Wall_Room_Blue();
//					}
//					else if(INITIAL_ZONE==ZONE_RED)
//					{
//						if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//						{
//							Evade_Wall_Room_Blue();
//						}
//
//						else Evade_Wall_Room_Red();
//					}
////					Evade_Wall();
//					if (Ping[PING_FRONT]<=11)
//					{
//						if( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) >= (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//						{
////							CandleCircle_Check();
//							Sendto_PC(USART1,"YUME ROTATE RIGHT in follow_fire_right\r");
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							mov_rotright_fire(FAST_LEVEL_3,FAR);
//							OVERRIDE=1;
//						}
//						else if ( (Ping[PING_ASKEW_RIGHT]+Ping[PING_RIGHT]) < (Ping[PING_ASKEW_LEFT]+Ping[PING_LEFT]))
//						{
////							CandleCircle_Check();
//							Sendto_PC(USART1,"YUME ROTATE LEFT in follow_fire_right\r");
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							mov_rotleft_fire(FAST_LEVEL_3,FAR);
//							OVERRIDE=1;
//						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						if(INITIAL_ZONE==ZONE_BLUE)
//						{
//							if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//							{
//								Evade_Wall_Room_Red();
//							}
//							else Evade_Wall_Room_Blue();
//						}
//						else if(INITIAL_ZONE==ZONE_RED)
//						{
//							if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//							{
//								Evade_Wall_Room_Blue();
//							}
//
//							else Evade_Wall_Room_Red();
//						}
//						curve_right_fire_new(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//
//					}
//				}
//
//			}
//
//		if(INITIAL_ZONE==ZONE_BLUE)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Red();
//			}
//			else Evade_Wall_Room_Blue();
//		}
//		else if(INITIAL_ZONE==ZONE_RED)
//		{
//			if(ENEMY_ZONE_STAT==ENEMY_ZONE)
//			{
//				Evade_Wall_Room_Blue();
//			}
//
//			else Evade_Wall_Room_Red();
//		}
//
//		if(FIRE_PUTOFF==1) break;
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//}
//
//void curve_right_fire_new(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	Sendto_PC(USART1,"YUME Curve Right Movement \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
//	//unsigned int DELTA_MR;
//	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);
//
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//
//	//gait_mode(CURVE_RIGHT, SPEED);
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3],10,leg-3);
//	inv_kine(middle_left,90+beta[1],10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5],10,leg-3);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//2
//	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//3
//	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//4
//	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4],10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//5
//	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//6
//	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,7,leg);
//	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: CORRIDOR  \r");
//	}
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: ROOM  \r");
//	}
//}
//
//
//void curve_left_fire_new(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	Sendto_PC(USART1,"YUME Curve Left Movement \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);
//
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//gait_mode(CURVE_LEFT, SPEED);
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//2
//	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//3
//	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
//	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//4
//	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//5
//	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	Get_TPA81();
//	YUME_Tracer_Check();
//	if(FIRE==1) YUME_Found_Fire();
//	//6
//	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
//	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: CORRIDOR  \r");
//	}
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: ROOM  \r");
//	}
//
//}
//
//
//
//
///*
// *  YUME WALL FOLLOWING LEFT RULE NEW ALGORITHM
// */
//
///* func      : void followtracer_left(void)
// * brief     : Wall following left rule algorithm using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 28th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void followtracer_left(void)
//{
//	Cat_Avoider();
//	Evade_Wall();
//	YUME_Tracer_Check();
//	Sendto_PC(USART1,"followtracer_left \r");
//	Sendto_PC(USART1,"YUME_LOCATION[PRESENT_LOC]: %d \r",YUME_LOCATION[PRESENT_LOC]);
//	Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//	CAT_SHIFT_FOLLOW=0;
//
//	while( (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)  && (CAT_SHIFT_FOLLOW==NO_SHIFT) )
//	{
//		Cat_Avoider();
//		Evade_Wall();
//		YUME_Tracer_Check();
//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//
//		if (Ping[PING_FRONT]<=13)
//		{
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		}
//		else
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			PID_followtracer_left();
//			if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		}
//	}
//
//}
//
///* func      : void PID_followtracer_left(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_followtracer_left(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//	OVERRIDE=0;
//
//	Cat_Avoider();
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//	while( (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)  && (CAT_SHIFT_FOLLOW==NO_SHIFT) )
//	{
//		OVERRIDE=0;
//		while(OVERRIDE==0)
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			PID_Calc_LeftRule();
//
//			YUME_Tracer_Check();
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if (Ping[PING_FRONT]<=13)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5,FAST_LEVEL_3);
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//
//					YUME_Tracer_Check();
//					if (PID_F_L.pid_value[0]>8) PID_F_L.pid_value[0]=8; //WINDUP
//
//					if (Ping[PING_FRONT]<=13)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//
//						YUME_Tracer_Check();
//						curve_right_new(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//					YUME_Tracer_Check();
//					Cat_Avoider();
//					Evade_Wall();
//
////					if(OVERRIDE==1){break;}
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//				{
//					YUME_Tracer_Check();
//					if (PID_F_L.pid_value[0]>8) PID_F_L.pid_value[0]=8; //WINDUP
//
//					if (Ping[PING_FRONT]<=13)
//					{
//
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//						YUME_Tracer_Check();
//
//						curve_left_new(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//					YUME_Tracer_Check();
//					Cat_Avoider();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				}
//
//			YUME_Tracer_Check();
//			Cat_Avoider();
//			OVERRIDE=0;
//		}
//		OVERRIDE=0;
//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//
//	}
//	OVERRIDE=0;
//}
//
//
///* func      : void FollowExit_Right(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       :  1. Initial Code
// * 				2. Add anticipation for exit room in blue zone
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: Ryan (Monday, November 16th 2015)
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void FollowExit_Right(void)
//{
////	Evade_Wall();
//	Evade_Wall_Room();
//	YUME_Tracer_Check();
//	Sendto_PC(USART1,"\rYUME FOLLOW EXIT \r");
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
////		Evade_Wall();
//		//if(FIRE_PUTOFF==1) break;
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//
//		if (Ping[PING_FRONT]<=15)
//		{
//
//			Evade_Wall_Room();
//			YUME_Tracer_Check();
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT \r");
//			mov_rot_left(MED, FAR);
//			mov_rot_left(MED, FAR);
//			mov_rot_left(MED, FAR);
//			YUME_Tracer_Check();
//
//		}
//		else
//		{
//			Evade_Wall_Room();
//			YUME_Tracer_Check();
////			Evade_Wall();
//			//if(FIRE_PUTOFF==1) break;
//			if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//			PID_FollowExit_Right();
//		}
//
//		YUME_Tracer_Check();
////		Evade_Wall();
//		//if(FIRE_PUTOFF==1) break;
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//
//}
//
///* func      : void PID_FollowExit_Right(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_FollowExit_Right(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//
//	Send_Location ();
//
////	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
////	{
//		Evade_Wall_Room();
//		if (OVERRIDE==0)
//		{
////			Evade_Wall();
//			YUME_Tracer_Check();
//			PID_Calc();
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//				{
//					if (Ping[PING_FRONT]<=15)
//					{
//
////						Evade_Wall();
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						YUME_Tracer_Check();
//						OVERRIDE=1;
//					}
//
//					//if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
////						Evade_Wall();
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						Mov_Fwd_Trace(5, FAST_LEVEL_3);
//					}
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//				{
//					if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//
//					if (Ping[PING_FRONT]<=15)
//					{
//
////						Evade_Wall();
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						YUME_Tracer_Check();
//						OVERRIDE=1;
//					}
//
//					//if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
////						Evade_Wall();
//						YUME_Tracer_Check();
//						Evade_Wall_Room();
//						curve_right_room(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//					}
//
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//				{
//					if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//
//					if (Ping[PING_FRONT]<=15)
//					{
//
////						Evade_Wall();
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						YUME_Tracer_Check();
//						OVERRIDE=1;
//					}
//
//					//if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
////						Evade_Wall();
//						YUME_Tracer_Check();
//						Evade_Wall_Room();
//						curve_left_room(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//					}
//
//				}
//
//		}
////	}
//
//}
//
///* func      : void FollowExit_Left(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Sunday, November 8th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void FollowExit_Left(void)
//{
//	Evade_Wall_Room();
//	Sendto_PC(USART1,"\rYUME FOLLOW EXIT LEFT RULE\r");
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Evade_Wall_Room();
//		YUME_Tracer_Check();
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//
//		if (Ping[PING_FRONT]<=10)
//		{
//
//			Evade_Wall_Room();
//
//			YUME_Tracer_Check();
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//		}
//		else
//		{
//			Evade_Wall_Room();
//
//			YUME_Tracer_Check();
//			if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//			PID_FollowExit_Left();
//		}
//
//		YUME_Tracer_Check();
//		Evade_Wall_Room();
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//
//}
//
///* func      : void PID_FollowExit_Left(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Sunday, November 8th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_FollowExit_Left(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//
//	Send_Location ();
//	YUME_Tracer_Check();
//
//
//		Evade_Wall_Room();
//		if (OVERRIDE==0)
//		{
////			Evade_Wall();
//
//			PID_Calc_LeftRule();
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_L.set_point )
//			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//				{
//					if (Ping[PING_FRONT]<=10)
//					{
//
//						Evade_Wall_Room();
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//					}
//
//					//if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Evade_Wall_Room();
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//
//						Mov_Fwd_Trace(5, FAST_LEVEL_3);
//					}
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//				{
//					if (PID_F_L.pid_value[0]>6) PID_F_L.pid_value[0]=6; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//
//						Evade_Wall_Room();
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//					}
//
//					//if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Evade_Wall_Room();
//						YUME_Tracer_Check();
//						curve_left_room(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//					}
//
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//				{
//					if (PID_F_L.pid_value[0]>6) PID_F_L.pid_value[0]=6; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//
//						Evade_Wall_Room();
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//					}
//
//					//if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Evade_Wall_Room();
//						YUME_Tracer_Check();
//						curve_right_room(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//					}
//				}
//		}
////	}
//
//}
//
//
//void Mov_Fwd_Trace (int distance, int SPEED)
//{
//	Sendto_PC(USART1,"YUME Forward Tracing Movement\r");
//	int limit= distance/5;
//	int loop;
//	//if (STEP==FAR)       { limit= distance/5; generate_movement_data(0,5,10);}
//	//else if (STEP==HALF) { limit= distance/3; generate_movement_data(0,3,10);}
//	//else if (STEP=CLOSE) { limit= distance/2; generate_movement_data(0,2,10);}
//
//	generate_movement_data(0,5,10);
//	delay_ms(50);
//	for (loop=1;loop<=limit;loop++)
//		{
//			//gait_mode(FORWARD, &SPEED);
//			Get_IR();
//
//			YUME_Tracer_Check();
//			//1
//			inv_kine(front_left,90,7,leg);
//			inv_kine(front_right,90+beta[3],10,leg-3);
//			inv_kine(middle_left,90+beta[1],10,leg-3);
//			inv_kine(middle_right,90,7,leg);
//			inv_kine(rear_left,90,7,leg);
//			inv_kine(rear_right,90+beta[5],10,leg-3);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
//			//2
//			inv_kine(front_left,90+beta[0],7,leg);
//			inv_kine(front_right,90-beta[3],10,leg-3);
//			inv_kine(middle_left,90-beta[1],10,leg-3);
//			inv_kine(middle_right,90+beta[4],7,leg);
//			inv_kine(rear_left,90+beta[2],7,leg);
//			inv_kine(rear_right,90-beta[5],10,leg-3);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
//			//3
//			inv_kine(front_left,90+beta[0],7,leg);
//			inv_kine(front_right,90-beta[3],7,leg);
//			inv_kine(middle_left,90-beta[1],7,leg);
//			inv_kine(middle_right,90+beta[4],7,leg);
//			inv_kine(rear_left,90+beta[2],7,leg);
//			inv_kine(rear_right,90-beta[5],7,leg);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
//			//4
//			inv_kine(front_left,90+beta[0],10,leg-3);
//			inv_kine(front_right,90,7,leg);
//			inv_kine(middle_left,90,7,leg);
//			inv_kine(middle_right,90+beta[4],10,leg-3);
//			inv_kine(rear_left,90+beta[2],7,leg-2);
//			inv_kine(rear_right,90,7,leg);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
//			//5
//			inv_kine(front_left,90-beta[0],10,leg-3);
//			inv_kine(front_right,90+beta[3],7,leg);
//			inv_kine(middle_left,90+beta[1],7,leg);
//			inv_kine(middle_right,90-beta[4],10,leg-3);
//			inv_kine(rear_left,90-beta[2],7,leg-2);
//			inv_kine(rear_right,90+beta[5],7,leg);
//			delay_ms(SPEED);
//
//			YUME_Tracer_Check();
//			//6
//			inv_kine(front_left,90-beta[0],7,leg);
//			inv_kine(front_right,90+beta[3],7,leg);
//			inv_kine(middle_left,90+beta[1],7,leg);
//			inv_kine(middle_right,90-beta[4],7,leg);
//			inv_kine(rear_left,90-beta[2],7,leg);
//			inv_kine(rear_right,90+beta[5],7,leg);
//			delay_ms(SPEED);
//
//
//		}
//}
//
///*
// *  Func  : void mov_rot_right(int SPEED, int STEP)
// *  Brief : rotate hexapod body clockwise per parameter with desired speed and step length
// *  Param : SPEED -> default= MED_SLOW(200), MED(150), FAST(130), ULTRA_FAST(50);
// *  		STEP  -> default= FAR(5), CLOSE (2);
// *  ver	  : 1
// *  Last revised by: Ryan (MON, August 3rd 2015)
// *     	             Configured for the new YUME's mechanical
// * programmer's note  :
// */
//void mov_rotright_fire(int SPEED, int STEP)
//{
//	Sendto_PC(USART1,"YUME Rotate Right Movement \r");
//	switch(STEP)
//	{
//		case CLOSE:
//			{
//				generate_movement_data(0,STEP,10);
//				delay_ms(50);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//gait_mode(ROTATE_RIGHT,SPEED);
//				//1
//				inv_kine(front_left,90+beta[0],7,leg); //mundur
//				inv_kine(front_right,90+beta[3],10,leg-3); //mundur
//				inv_kine(middle_left,90-beta[1],10,leg-3); //maju
//				inv_kine(middle_right,90-beta[4],7,leg); //maju
//				inv_kine(rear_left,90+beta[2],7,leg); //mundur
//				inv_kine(rear_right,90+beta[5],10,leg-3); //mundur
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//2
//				inv_kine(front_left,90+beta[0],7,leg); //mundur
//				inv_kine(front_right,90+beta[3],7,leg); //mundur
//				inv_kine(middle_left,90-beta[1],7,leg); //maju
//				inv_kine(middle_right,90-beta[4],7,leg); //maju
//				inv_kine(rear_left,90+beta[2],7,leg); //mundur
//				inv_kine(rear_right,90+beta[5],7,leg); //mundur
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//3
//				inv_kine(front_left,90-beta[0],10,leg-3); //maju
//				inv_kine(front_right,90-beta[3],7,leg); //maju
//				inv_kine(middle_left,90+beta[1],7,leg); //mundur
//				inv_kine(middle_right,90+beta[4],10.5,leg-3); //mundur
//				inv_kine(rear_left,90-beta[2],10,leg-3); //maju
//				inv_kine(rear_right,90-beta[5],7,leg); //maju
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//4
//				inv_kine(front_left,90-beta[0],7,leg); //maju
//				inv_kine(front_right,90-beta[3],7,leg); //maju
//				inv_kine(middle_left,90+beta[1],7,leg); //mundur
//				inv_kine(middle_right,90+beta[4],7,leg); //mundur
//				inv_kine(rear_left,90-beta[2],7,leg); //maju
//				inv_kine(rear_right,90-beta[5],7,leg); //maju
//				delay_ms(SPEED);
//
//			}break;
//
//		case FAR:
//			{
//				generate_movement_data(0,STEP,10);
//				delay_ms(50);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//gait_mode(ROTATE_RIGHT,SPEED);
//				//1
//				inv_kine(front_left,90+beta[0],7,leg); //mundur
//				inv_kine(front_right,90+beta[3],10,leg-3); //mundur
//				inv_kine(middle_left,90-beta[1],10,leg-3); //maju
//				inv_kine(middle_right,90-beta[4],7,leg); //maju
//				inv_kine(rear_left,90+beta[2],7,leg); //mundur
//				inv_kine(rear_right,90+beta[5],10,leg-3); //mundur
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//2
//				inv_kine(front_left,90+beta[0],7,leg); //mundur
//				inv_kine(front_right,90+beta[3],7,leg); //mundur
//				inv_kine(middle_left,90-beta[1],7,leg); //maju
//				inv_kine(middle_right,90-beta[4],7,leg); //maju
//				inv_kine(rear_left,90+beta[2],7,leg); //mundur
//				inv_kine(rear_right,90+beta[5],7,leg); //mundur
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//3
//				inv_kine(front_left,90-beta[0],10,leg-3); //maju
//				inv_kine(front_right,90-beta[3],7,leg); //maju
//				inv_kine(middle_left,90+beta[1],7,leg); //mundur
//				inv_kine(middle_right,90+beta[4],10.5,leg-3); //mundur
//				inv_kine(rear_left,90-beta[2],10,leg-3); //maju
//				inv_kine(rear_right,90-beta[5],7,leg); //maju
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//4
//				inv_kine(front_left,90-beta[0],7,leg); //maju
//				inv_kine(front_right,90-beta[3],7,leg); //maju
//				inv_kine(middle_left,90+beta[1],7,leg); //mundur
//				inv_kine(middle_right,90+beta[4],7,leg); //mundur
//				inv_kine(rear_left,90-beta[2],7,leg); //maju
//				inv_kine(rear_right,90-beta[5],7,leg); //maju
//				delay_ms(SPEED);
//
//			}break;
//		default: break;
//	}
//}
//
//
//void mov_rotleft_fire(int SPEED, int STEP)
//{
//	Sendto_PC(USART1,"YUME Rotate Left SEARCH FIRE Movement \r");
//	switch(STEP)
//	{
//		case CLOSE:
//			{
//				generate_movement_data(0,STEP,10);
//				delay_ms(50);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//gait_mode(ROTATE_LEFT, SPEED);
//				//1
//				inv_kine(front_left,90-beta[0],7,leg); //maju /
//				inv_kine(front_right,90-beta[3],10,leg-3); //maju
//				inv_kine(middle_left,90+beta[1],10,leg-3); //mundur /
//				inv_kine(middle_right,90+beta[4],7,leg); //mundur /
//				inv_kine(rear_left,90-beta[2],7,leg); //maju /
//				inv_kine(rear_right,90-beta[5],10,leg-3); //maju /
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//2
//				inv_kine(front_left,90-beta[0],7,leg); //maju /
//				inv_kine(front_right,90-beta[3],7,leg); //maju /
//				inv_kine(middle_left,90+beta[1],7,leg); //mundur /
//				inv_kine(middle_right,90+beta[4],7,leg); //mundur /
//				inv_kine(rear_left,90-beta[2],7,leg); //maju /
//				inv_kine(rear_right,90-beta[5],7,leg); //maju /
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//3
//				inv_kine(front_left,90+beta[0],10,leg-3); //mundur /
//				inv_kine(front_right,90+beta[3],7,leg); //mundur /
//				inv_kine(middle_left,90-beta[1],7,leg); //maju /
//				inv_kine(middle_right,90-beta[4],10.5,leg-3); //maju /
//				inv_kine(rear_left,90+beta[2],10,leg-3); //mundur /
//				inv_kine(rear_right,90+beta[5],7,leg); //mundur /
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//4
//				inv_kine(front_left,90+beta[0],7,leg); //mundur /
//				inv_kine(front_right,90+beta[3],7,leg); //mundur /
//				inv_kine(middle_left,90-beta[1],7,leg); //maju /
//				inv_kine(middle_right,90-beta[4],7,leg); //maju /
//				inv_kine(rear_left,90+beta[2],7,leg); //mundur /
//				inv_kine(rear_right,90+beta[5],7,leg); //mundur /
//				delay_ms(SPEED);
//
//			}break;
//
//		case FAR:
//			{
//				generate_movement_data(0,STEP,10);
//				delay_ms(50);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//gait_mode(ROTATE_LEFT, SPEED);
//				//1
//				inv_kine(front_left,90-beta[0],7,leg); //maju /
//				inv_kine(front_right,90-beta[3],10,leg-3); //maju
//				inv_kine(middle_left,90+beta[1],10,leg-3); //mundur /
//				inv_kine(middle_right,90+beta[4],7,leg); //mundur /
//				inv_kine(rear_left,90-beta[2],7,leg); //maju /
//				inv_kine(rear_right,90-beta[5],10,leg-3); //maju /
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//2
//				inv_kine(front_left,90-beta[0],7,leg); //maju /
//				inv_kine(front_right,90-beta[3],7,leg); //maju /
//				inv_kine(middle_left,90+beta[1],7,leg); //mundur /
//				inv_kine(middle_right,90+beta[4],7,leg); //mundur /
//				inv_kine(rear_left,90-beta[2],7,leg); //maju /
//				inv_kine(rear_right,90-beta[5],7,leg); //maju /
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//3
//				inv_kine(front_left,90+beta[0],10,leg-3); //mundur /
//				inv_kine(front_right,90+beta[3],7,leg); //mundur /
//				inv_kine(middle_left,90-beta[1],7,leg); //maju /
//				inv_kine(middle_right,90-beta[4],10.5,leg-3); //maju /
//				inv_kine(rear_left,90+beta[2],10,leg-3); //mundur /
//				inv_kine(rear_right,90+beta[5],7,leg); //mundur /
//				delay_ms(SPEED);
//
//				Get_TPA81();
//				if(FIRE==1) YUME_Found_Fire();
//				//4
//				inv_kine(front_left,90+beta[0],7,leg); //mundur /
//				inv_kine(front_right,90+beta[3],7,leg); //mundur /
//				inv_kine(middle_left,90-beta[1],7,leg); //maju /
//				inv_kine(middle_right,90-beta[4],7,leg); //maju /
//				inv_kine(rear_left,90+beta[2],7,leg); //mundur /
//				inv_kine(rear_right,90+beta[5],7,leg); //mundur /
//				delay_ms(SPEED);
//
//			}break;
//		default: break;
//	}
//}
//
//
//void Send_Location (void)
//{
//
//	Sendto_PC(USART1,"\r\r||===========YUME LOCATION STATUS===========||\r");
//	if(YUME_LOCATION[LAST_LOC]==LOCATION_ROOM) Sendto_PC(USART1,"LAST LOCATION: ROOM \r");
//	else if(YUME_LOCATION[LAST_LOC]==LOCATION_CORRIDOR) Sendto_PC(USART1,"LAST LOCATION: CORRIDOR \r");
//
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) Sendto_PC(USART1,"PRESENT LOCATION: ROOM \r");
//	else if(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR) Sendto_PC(USART1,"PRESENT LOCATION: CORRIDOR \r \r");
//	Sendto_PC(USART1,"||==========================================||\r\r");
//}
//
//
/////*
//// *  FOLLOW RIGHT COUNTER
//// *
//// */
////
////void follow_right_counter(int limit)
////{
////	int counter;
////	//int limit=15;
////	for(counter=1;counter<=limit;counter++)
////	{
////		if (Ping[PING_FRONT]<=10)
////		{
////			if (Ping[PING_RIGHT]<=20)
////			{
////				Sendto_PC(USART1,"YUME ROTATE LEFT \r");
////				mov_rot_left(FAST, FAR);
////			}
////
////			if (Ping[PING_RIGHT]>20)
////			{
////				Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
////				mov_rot_right(FAST, FAR);
////			}
////		}
////		else
////		{
////			PID_follow_right_counter();
////		}
////	}
////
////
////
////}
////
/////* func      : void PID_follow_tracer_right(void)
//// * brief     : Wall following using PID controller until YUME detects TRACER LINE
//// * param     : N/A
//// * retval    : N/A
//// * Ver       : 1
//// * written By: Ryan (Monday, October 19th 2015)
//// * Revised BY: N/A
//// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
//// *
//// */
////void PID_follow_right_counter(void)
////{
////	//int limit= *COMMAND_LOOP;
////	int OVERRIDE=0;
////
////	PID_Calc();
////
////	while(OVERRIDE==0)
////	{
////		if(OVERRIDE==0)
////		{
////			//KONDISI ROBOT SESUAI
////			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
////			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
////				{
////					if (Ping[PING_FRONT]<=10)
////					{
////						if (Ping[PING_RIGHT]<=15)
////						{
////
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_RIGHT]>15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
////					}
////
////					if(OVERRIDE==1){break;}
////
////					if (OVERRIDE==0)
////					{
////						Sendto_PC(USART1,"YUME FORWARD \r");
////						mov_fwd_5cm(5, FAST_LEVEL_3);
////						OVERRIDE=1;
////					}
////				}
////
////			//KONDISI ROBOT JAUH DARI DINDING
////			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
////				{
////					if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
////
////					if (Ping[PING_FRONT]<=10)
////					{
////						if (Ping[PING_RIGHT]<=15)
////						{
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_RIGHT]>15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
////					}
////
////					if(OVERRIDE==1){break;}
////
////					if (OVERRIDE==0)
////					{
////						curve_right_counter(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
////						OVERRIDE=1;
////					}
////
////				}
////
////			//KONDISI ROBOT DEKAT DENGAN DINDING
////			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
////				{
////					if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
////
////					if (Ping[PING_FRONT]<=10)
////					{
////						if (Ping[PING_RIGHT]<=15)
////						{
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_RIGHT]>15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
////					}
////
////					if(OVERRIDE==1){break;}
////
////					if (OVERRIDE==0)
////					{
////						curve_left_counter(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
////						OVERRIDE=1;
////					}
////
////				}
////		}
////	}
////
////}
////
////void follow_left_counter(int limit)
////{
////	int counter;
////	//int limit=15;
////	for(counter=1;counter<=limit;counter++)
////	{
////		if (Ping[PING_FRONT]<=10)
////		{
////			if (Ping[PING_LEFT]>=20)
////			{
////				Sendto_PC(USART1,"YUME ROTATE LEFT \r");
////				mov_rot_left(FAST, FAR);
////			}
////
////			if (Ping[PING_LEFT]<20)
////			{
////				Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
////				mov_rot_right(FAST, FAR);
////			}
////		}
////		else
////		{
////			PID_follow_left_counter();
////		}
////	}
////
////
////
////}
////
/////* func      : void PID_follow_tracer_right(void)
//// * brief     : Wall following using PID controller until YUME detects TRACER LINE
//// * param     : N/A
//// * retval    : N/A
//// * Ver       : 1
//// * written By: Ryan (Monday, October 19th 2015)
//// * Revised BY: N/A
//// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
//// *
//// */
////void PID_follow_left_counter(void)
////{
////	//int limit= *COMMAND_LOOP;
////	int OVERRIDE=0;
////
////	PID_Calc_LeftRule();
////
////	while(OVERRIDE==0)
////	{
////		if(OVERRIDE==0)
////		{
////			//KONDISI ROBOT SESUAI
////			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
////			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
////				{
////					if (Ping[PING_FRONT]<=10)
////					{
////						if (Ping[PING_LEFT]>=15)
////						{
////
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_LEFT]<15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
////					}
////
////					if(OVERRIDE==1){break;}
////
////					if (OVERRIDE==0)
////					{
////						Sendto_PC(USART1,"YUME FORWARD \r");
////						mov_fwd_5cm(5, FAST_LEVEL_3);
////						OVERRIDE=1;
////					}
////				}
////
////			//KONDISI ROBOT JAUH DARI DINDING
////			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
////				{
////					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP
////
////					if (Ping[PING_FRONT]<=10)
////					{
////						if (Ping[PING_LEFT]>=15)
////						{
////
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_LEFT]<15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
////					}
////
////					if(OVERRIDE==1){break;}
////
////					if (OVERRIDE==0)
////					{
////						curve_right_counter(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
////						OVERRIDE=1;
////					}
////
////				}
////
////			//KONDISI ROBOT DEKAT DENGAN DINDING
////			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
////				{
////					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP
////
////					if (Ping[PING_FRONT]<=10)
////					{
////						if (Ping[PING_LEFT]>=15)
////						{
////
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_LEFT]<15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
////					}
////
////					if(OVERRIDE==1){break;}
////
////					if (OVERRIDE==0)
////					{
////						curve_left_counter(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
////						OVERRIDE=1;
////					}
////
////				}
////		}
////	}
////
////}
////
////void curve_right_counter(int SPEED, int STEP, float *COMMAND_LOOP)
////{
////	Sendto_PC(USART1,"YUME Curve Right Counter \r");
////	generate_movement_data(0,STEP,10);
////	delay_ms(50);
////
////	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
////	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
////	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
////	//unsigned int DELTA_MR;
////	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
////	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);
////
////	//1
////	inv_kine(front_left,90,7,leg);
////	inv_kine(front_right,90+beta[3],10,leg-3);
////	inv_kine(middle_left,90+beta[1],10,leg-3);
////	inv_kine(middle_right,90,7,leg);
////	inv_kine(rear_left,90,7,leg);
////	inv_kine(rear_right,90+beta[5],10,leg-3);
////	delay_ms(SPEED);
////
////	//2
////	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
////	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
////	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
////	inv_kine(middle_right,90+beta[4],7,leg);
////	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
////	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
////	delay_ms(SPEED);
////
////	//3
////	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
////	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
////	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
////	inv_kine(middle_right,90+beta[4],7,leg);
////	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
////	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
////	delay_ms(SPEED);
////
////	//4
////	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
////	inv_kine(front_right,90,7,leg);
////	inv_kine(middle_left,90,7,leg);
////	inv_kine(middle_right,90+beta[4],10.5,leg-3);
////	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
////	inv_kine(rear_right,90,7,leg);
////	delay_ms(SPEED);
////
////	//5
////	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
////	inv_kine(front_right,90+beta[3],7,leg);
////	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
////	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
////	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
////	inv_kine(rear_right,90+beta[5],7,leg);
////	delay_ms(SPEED);
////
////	//6
////	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
////	inv_kine(front_right,90+beta[3],7,leg);
////	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
////	inv_kine(middle_right,90-beta[4]+10,7,leg);
////	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
////	inv_kine(rear_right,90+beta[5],7,leg);
////	delay_ms(SPEED);
////}
////
////
////void curve_left_counter(int SPEED, int STEP, float *COMMAND_LOOP)
////{
////	Sendto_PC(USART1,"YUME Curve Left Counter \r");
////	generate_movement_data(0,STEP,10);
////	delay_ms(50);
////
////	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
////	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
////	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
////	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
////	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
////	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);
////
////	//1
////	inv_kine(front_left,90,7,leg);
////	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
////	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
////	inv_kine(middle_right,90,7,leg);
////	inv_kine(rear_left,90,7,leg);
////	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
////	delay_ms(SPEED);
////
////	//2
////	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
////	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
////	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
////	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
////	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
////	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
////	delay_ms(SPEED);
////
////	//3
////	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
////	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
////	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
////	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
////	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
////	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
////	delay_ms(SPEED);
////
////	//4
////	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
////	inv_kine(front_right,90,7,leg);
////	inv_kine(middle_left,90,7,leg);
////	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
////	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
////	inv_kine(rear_right,90,7,leg);
////	delay_ms(SPEED);
////
////	//5
////	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
////	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
////	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
////	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
////	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
////	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
////	delay_ms(SPEED);
////
////	//6
////	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
////	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
////	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
////	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
////	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
////	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
////	delay_ms(SPEED);
////}
//
//
//
///* func      : void folltracer_curve_right(int SPEED, int STEP, float *COMMAND_LOOP)
// * brief     : convert control signal to actuating signal in follow right until tracer
// * param     : int SPEED, int STEP, float *COMMAND_LOOP (pid_value[0])
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding PID wall following function
// *
// */
//void curve_right_room(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	Sendto_PC(USART1,"YUME Curve Right in ROOM \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
//	//unsigned int DELTA_MR;
//	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);
//
//	//gait_mode(CURVE_RIGHT, SPEED);
//	YUME_Tracer_Check();
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3],10,leg-3);
//	inv_kine(middle_left,90+beta[1],10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5],10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//2
//	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//3
//	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//4
//	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4],10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//5
//	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//6
//	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,7,leg);
//	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: CORRIDOR  \r");
//	}
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: ROOM  \r");
//	}
//}
//
///* func      : void folltracer_curve_left(int SPEED, int STEP, float *COMMAND_LOOP)
// * brief     : convert control signal to actuating signal in follow right until tracer
// * param     : int SPEED, int STEP, float *COMMAND_LOOP (pid_value[0])
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding PID wall following function
// *
// */
//void curve_left_room(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	Sendto_PC(USART1,"YUME Curve Left in ROOM \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);
//
////	YUME_TCS3200_Check(MID_TCS3200, YUME_CROSS_MODE);
////	if(TRACER_STAT==1){YUME_Success();}
//
//	//gait_mode(CURVE_LEFT, SPEED);
//	YUME_Tracer_Check();
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//    YUME_Tracer_Check();
//	//2
//	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//3
//	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
//	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//4
//	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//5
//	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//	//6
//	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
//	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	YUME_Tracer_Check();
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: CORRIDOR  \r");
//	}
//
//	if (YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME_LOCATION: ROOM  \r");
//	}
//}
//
//
//
///*
// *  YUME FOLLOW RIGHT UNTIL CARPET FUNCTION
// */
//
///* func      : void FollowCarpet_Right(int CARPET, int INV_STAT)
// * brief     : Wall following algorithm using PID controller until YUME Detecting designated carpet
// * param     : int CARPET ( COLOUR_BLACK, COLOUR_WHITE, COLOUR_BLUE, COLOUR_RED )
// *                  -> function active as long as designated carpet detected
// * 			   int INV_STAT ( NORMAL, INVERSE )
// * 			        -> switching between function active while detect certain carpet or active as long as certain carpet not detected
// * 			        i.e. NORMAL  -> while(COLOUR_STAT==CARPET)
// * 			             INVERSE -> while(COLOUR_STAT!=CARPET)
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Tuesday, November 3rd 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void FollowCarpet_Right(unsigned int *CARPET, unsigned int *INV_STAT)
//{
//	Sendto_PC(USART1,"\r YUME FOLLOW CARPET RIGHT RULE \r");
//
//	//FOLLOW CARPET FLAG ACTIVATED
//	FOLLOW_CARPET_FLAG=FOLLOW_CARPET_ENABLED;
//
//
//	Evade_Wall();
//	if(*INV_STAT==NORMAL)
//	{
//		while( (M_DETECTED_COLOUR==*CARPET)  && (CAT_SHIFT_FOLLOW!=SHIFT_FOLLOW) )
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
////			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//
//			if (Ping[PING_FRONT]<=10)
//			{
////				if (Ping[PING_RIGHT]<=20)
////				{
////					Evade_Wall();
////					Sendto_PC(USART1,"YUME ROTATE LEFT \r");
////					mov_rot_left(FAST_LEVEL_3, FAR);
////					YUME_Tracer_Check();
//////					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////				}
////				if (Ping[PING_RIGHT]>20)
////				{
////					Evade_Wall();
////					Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
////					mov_rot_right(FAST_LEVEL_3, FAR);
////					YUME_Tracer_Check();
//////					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////				}
//
//				Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT \r");
//				mov_rot_left(MED, FAR);
//				mov_rot_left(MED, FAR);
//				mov_rot_left(MED, FAR);
//
//				Cat_Avoider();
//				Evade_Wall();
//				YUME_Tracer_Check();
//
//
//			}
//			else
//			{
//				Cat_Avoider();
//				Evade_Wall();
//				YUME_Tracer_Check();
////				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				PID_FollowCarpet_Right(& *CARPET,& *INV_STAT);
//			}
//		}
//	}
//
//	else if(*INV_STAT==INVERSE)
//	{
//		while( (M_DETECTED_COLOUR!= *CARPET) && (CAT_SHIFT_FOLLOW!=SHIFT_FOLLOW) )
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
////			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//
//			if (Ping[PING_FRONT]<=10)
//			{
////				if (Ping[PING_RIGHT]<=20)
////				{
////					Evade_Wall();
////					Sendto_PC(USART1,"YUME ROTATE LEFT \r");
////					mov_rot_left(FAST_LEVEL_3, FAR);
////					YUME_Tracer_Check();
//////					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////				}
////				if (Ping[PING_RIGHT]>20)
////				{
////					Evade_Wall();
////					Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
////					mov_rot_right(FAST_LEVEL_3, FAR);
////					YUME_Tracer_Check();
//////					if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////				}
//				Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT \r");
//				mov_rot_left(MED, FAR);
//				mov_rot_left(MED, FAR);
//				mov_rot_left(MED, FAR);
//
//				Cat_Avoider();
//				Evade_Wall();
//				YUME_Tracer_Check();
//
//			}
//			else
//			{
//				Cat_Avoider();
//				Evade_Wall();
//				YUME_Tracer_Check();
////				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				PID_FollowCarpet_Right(& *CARPET,& *INV_STAT);
//			}
//		}
//	}
//
//
//
//}
//
///* func      : void PID_FollowCarpet_Right(int *CARPET, int *INV_STAT)
// * brief     : Wall following algorithm using PID controller until YUME Detecting designated carpet
// * param     : int CARPET ( COLOUR_BLACK, COLOUR_WHITE, COLOUR_BLUE, COLOUR_RED )
// *                  -> function active as long as designated carpet detected
// * 			   int INV_STAT ( NORMAL, INVERSE )
// * 			        -> switching between function active while detect certain carpet or active as long as certain carpet not detected
// * 			        i.e. NORMAL  -> while(COLOUR_STAT==CARPET)
// * 			             INVERSE -> while(COLOUR_STAT!=CARPET)
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Tuesday, November 3rd 2015)
// * Revised BY: N/A
// * programmer's Note: THIS FUNCTION MUST BE CALLED IN THE FollowCarpet_Right(int CARPET, int INV_STAT) function
// *
// */
//void PID_FollowCarpet_Right(unsigned int *CARPET, unsigned int *INV_STAT)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//
//
//	if(*INV_STAT==NORMAL)
//	{
//		while( (M_DETECTED_COLOUR==*CARPET) && (CAT_SHIFT_FOLLOW!=SHIFT_FOLLOW) )
//		{
//			PID_Calc();
//			if(OVERRIDE==0)
//			{
//				Evade_Wall();
//				Cat_Avoider();
//				YUME_Tracer_Check();
////				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//
//				//KONDISI ROBOT SESUAI
//				//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//				if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_RIGHT]<=15)
////							{
////								YUME_Tracer_Check();
//////								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_RIGHT]>15)
////							{
////								YUME_Tracer_Check();
//////								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE LEFT OVERRIDE \r");
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							Evade_Wall();
//							YUME_Tracer_Check();
////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							Sendto_PC(USART1,"YUME FORWARD \r");
//							mov_fwd_5cm(5, FAST_LEVEL_3);
//							//Mov_Fwd_Trace();
//						}
//						Cat_Avoider();
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//				//KONDISI ROBOT JAUH DARI DINDING
//				else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP
//						Cat_Avoider();
//
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_RIGHT]<=15)
////							{
////
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_RIGHT]>15)
////							{
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE LEFT OVERRIDE \r");
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							Evade_Wall();
//							YUME_Tracer_Check();
////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							curve_right_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						}
//
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						Cat_Avoider();
//					}
//
//				//KONDISI ROBOT DEKAT DENGAN DINDING
//				else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP
//
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_RIGHT]<=15)
////							{
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_RIGHT]>15)
////							{
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							YUME_Tracer_Check();
//////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////							Cat_Avoider();
//							Evade_Wall();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE LEFT OVERRIDE \r");
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							Evade_Wall();
//							YUME_Tracer_Check();
////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							curve_left_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						}
//
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						Cat_Avoider();
//					}
//
//				Evade_Wall();
//				YUME_Tracer_Check();
////				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				Cat_Avoider();
//			}
//		}
//	}
//
//	else if(*INV_STAT==INVERSE)
//	{
//		while( (M_DETECTED_COLOUR!=*CARPET) && (CAT_SHIFT_FOLLOW!=SHIFT_FOLLOW) )
//		{
//			if(OVERRIDE==0)
//			{
//				Evade_Wall();
//				Cat_Avoider();
//				YUME_Tracer_Check();
////				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//
//				//KONDISI ROBOT SESUAI
//				//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//				if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_RIGHT]<=15)
////							{
////								YUME_Tracer_Check();
//////								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_RIGHT]>15)
////							{
////								YUME_Tracer_Check();
//////								if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//							Evade_Wall();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE LEFT OVERRIDE \r");
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							Evade_Wall();
//							YUME_Tracer_Check();
////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							Sendto_PC(USART1,"YUME FORWARD \r");
//							mov_fwd_5cm(5, FAST_LEVEL_3);
//							//Mov_Fwd_Trace();
//						}
//						Cat_Avoider();
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//					}
//
//				//KONDISI ROBOT JAUH DARI DINDING
//				else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP
//						Cat_Avoider();
//
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_RIGHT]<=15)
////							{
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_RIGHT]>15)
////							{
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//							Evade_Wall();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE LEFT OVERRIDE \r");
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							Evade_Wall();
//							YUME_Tracer_Check();
////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							curve_right_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						}
//
//						YUME_Tracer_Check();
//						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						Evade_Wall();
//						Cat_Avoider();
//					}
//
//				//KONDISI ROBOT DEKAT DENGAN DINDING
//				else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						if (PID_F_R.pid_value[0]>10) PID_F_R.pid_value[0]=10; //WINDUP
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_RIGHT]<=15)
////							{
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_RIGHT]>15)
////							{
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							YUME_Tracer_Check();
//////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////							Cat_Avoider();
//							Evade_Wall();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE LEFT OVERRIDE \r");
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							mov_rot_left(MED, FAR);
//							OVERRIDE=1;
//
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							Evade_Wall();
//							YUME_Tracer_Check();
////							if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//							curve_left_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						}
//
//						Evade_Wall();
//						YUME_Tracer_Check();
////						if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//						Cat_Avoider();
//					}
//
//				Evade_Wall();
//				YUME_Tracer_Check();
////				if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//				Cat_Avoider();
//			}
//		}
//	}
//
//}
//
//
//
///*
// *  YUME FOLLOW LEFT UNTIL CARPET FUNCTION
// */
//
///* func      :void FollowCarpet_Left(int CARPET, int INV_STAT)
// * brief     : Wall following algorithm using PID controller until YUME Detecting designated carpet
// * param     : int CARPET ( COLOUR_BLACK, COLOUR_WHITE, COLOUR_BLUE, COLOUR_RED )
// *                  -> function active as long as designated carpet detected
// * 			   int INV_STAT ( NORMAL, INVERSE )
// * 			        -> switching between function active while detect certain carpet or active as long as certain carpet not detected
// * 			        i.e. NORMAL  -> while(COLOUR_STAT==CARPET)
// * 			             INVERSE -> while(COLOUR_STAT!=CARPET)
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Tuesday, November 3rd 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void FollowCarpet_Left(unsigned int *CARPET, unsigned int *INV_STAT)
//{
//	Sendto_PC(USART1,"\r YUME FOLLOW CARPET LEFT RULE \r");
//
//	//FOLLOW CARPET FLAG ACTIVATED
//	FOLLOW_CARPET_FLAG=FOLLOW_CARPET_ENABLED;
//
//
//	YUME_Tracer_Check();
//	if(*INV_STAT==NORMAL)
//	{
//		while( (M_DETECTED_COLOUR==*CARPET) && (CAT_SHIFT_FOLLOW!=SHIFT_FOLLOW) )
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			if (Ping[PING_FRONT]<=10)
//			{
////				if (Ping[PING_LEFT]>=20)
////				{
////					Evade_Wall();
////					Sendto_PC(USART1,"YUME ROTATE LEFT \r");
////					mov_rot_left(FAST_LEVEL_3, FAR);
////					YUME_Tracer_Check();
////				}
////				if (Ping[PING_LEFT]<20)
////				{
////					Evade_Wall();
////					Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
////					mov_rot_right(FAST_LEVEL_3, FAR);
////					YUME_Tracer_Check();
////				}
//				Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//				mov_rot_right(MED, FAR);
//				mov_rot_right(MED, FAR);
//				mov_rot_right(MED, FAR);
//
//				Cat_Avoider();
//				Evade_Wall();
//				YUME_Tracer_Check();
//			}
//			else
//			{
//				Cat_Avoider();
//				Evade_Wall();
//				YUME_Tracer_Check();
//				PID_FollowCarpet_Left(& *CARPET,& *INV_STAT);
//			}
//		}
//	}
//
//	else if(*INV_STAT==INVERSE)
//	{
//		while( (M_DETECTED_COLOUR!=*CARPET) && (CAT_SHIFT_FOLLOW!=SHIFT_FOLLOW) )
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			if (Ping[PING_FRONT]<=10)
//			{
////				if (Ping[PING_LEFT]>=20)
////				{
////					Evade_Wall();
////					Sendto_PC(USART1,"YUME ROTATE LEFT \r");
////					mov_rot_left(MED, FAR);
////					YUME_Tracer_Check();
////				}
////				if (Ping[PING_LEFT]<20)
////				{
////					Evade_Wall();
////					Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
////					mov_rot_right(MED, FAR);
////					YUME_Tracer_Check();
////				}
//				Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//				mov_rot_right(MED, FAR);
//				mov_rot_right(MED, FAR);
//				mov_rot_right(MED, FAR);
//
//				Cat_Avoider();
//				Evade_Wall();
//				YUME_Tracer_Check();
//
//			}
//			else
//			{
//				Cat_Avoider();
//				Evade_Wall();
//				YUME_Tracer_Check();
//				PID_FollowCarpet_Left(& *CARPET,& *INV_STAT);
//			}
//		}
//	}
//}
//
///* func      : void PID_FollowCarpet_Left(int *CARPET, int *INV_STAT)
// * brief     : Wall following algorithm using PID controller until YUME Detecting designated carpet
// * param     : int CARPET ( COLOUR_BLACK, COLOUR_WHITE, COLOUR_BLUE, COLOUR_RED )
// *                  -> function active as long as designated carpet detected
// * 			   int INV_STAT ( NORMAL, INVERSE )
// * 			        -> switching between function active while detect certain carpet or active as long as certain carpet not detected
// * 			        i.e. NORMAL  -> while(COLOUR_STAT==CARPET)
// * 			             INVERSE -> while(COLOUR_STAT!=CARPET)
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Tuesday, November 3rd 2015)
// * Revised BY: N/A
// * programmer's Note: THIS FUNCTION MUST BE CALLED IN THE FollowCarpet_Left(int CARPET, int INV_STAT) function
// *
// */
//void PID_FollowCarpet_Left(unsigned int *CARPET, unsigned int *INV_STAT)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//	PID_Calc_LeftRule();
//
//	if(*INV_STAT==NORMAL)
//	{
//		while( (M_DETECTED_COLOUR==*CARPET) && (CAT_SHIFT_FOLLOW!=SHIFT_FOLLOW) )
//		{
//			if(OVERRIDE==0)
//			{
//				Evade_Wall();
//				Cat_Avoider();
//				YUME_Tracer_Check();
//
//				//KONDISI ROBOT SESUAI
//				//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//				if ( (Ping[PING_ASKEW_LEFT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_R.set_point_lower) )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_LEFT]>15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_LEFT]<=15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE RIGHT OVERRIDE \r");
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FORWARD \r");
//							mov_fwd_5cm(5, FAST_LEVEL_3);
//							//Mov_Fwd_Trace();
//						}
//						Cat_Avoider();
//						YUME_Tracer_Check();
//					}
//
//				//KONDISI ROBOT JAUH DARI DINDING
//				else if ( Ping[PING_ASKEW_LEFT]>PID_F_R.set_point )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
//						if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//						Cat_Avoider();
//
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_LEFT]>15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_LEFT]<=15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE RIGHT OVERRIDE \r");
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							YUME_Tracer_Check();
//							curve_left_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						}
//
//						YUME_Tracer_Check();
//						Cat_Avoider();
//					}
//
//				//KONDISI ROBOT DEKAT DENGAN DINDING
//				else if ( Ping[PING_ASKEW_LEFT]<PID_F_R.set_point )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
//						if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_LEFT]>15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_LEFT]<=15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE RIGHT OVERRIDE \r");
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							YUME_Tracer_Check();
//							curve_right_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						}
//
//						YUME_Tracer_Check();
//						Cat_Avoider();
//					}
//
//				Evade_Wall();
//				YUME_Tracer_Check();
//				Cat_Avoider();
//			}
//		}
//	}
//
//	else if(*INV_STAT==INVERSE)
//	{
//		while( (M_DETECTED_COLOUR!=*CARPET) && (CAT_SHIFT_FOLLOW!=SHIFT_FOLLOW) )
//		{
//			if(OVERRIDE==0)
//			{
//				Evade_Wall();
//				Cat_Avoider();
//				YUME_Tracer_Check();
//
//				//KONDISI ROBOT SESUAI
//				//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//				if ( (Ping[PING_ASKEW_LEFT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_R.set_point_lower) )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_LEFT]>15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_LEFT]<=15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE RIGHT OVERRIDE \r");
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FORWARD \r");
//							mov_fwd_5cm(5, FAST_LEVEL_3);
//							//Mov_Fwd_Trace();
//						}
//						Cat_Avoider();
//						YUME_Tracer_Check();
//					}
//
//				//KONDISI ROBOT JAUH DARI DINDING
//				else if ( Ping[PING_ASKEW_LEFT]>PID_F_R.set_point )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
//						if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//						Cat_Avoider();
//
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_LEFT]>15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_LEFT]<=15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE RIGHT OVERRIDE \r");
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							YUME_Tracer_Check();
//							curve_left_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						}
//
//						YUME_Tracer_Check();
//						Cat_Avoider();
//					}
//
//				//KONDISI ROBOT DEKAT DENGAN DINDING
//				else if ( Ping[PING_ASKEW_LEFT]<PID_F_R.set_point )
//					{
//						Evade_Wall();
//						YUME_Tracer_Check();
//						if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//
//						if (Ping[PING_FRONT]<=10)
//						{
////							if (Ping[PING_LEFT]>15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								mov_rot_left(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							if (Ping[PING_LEFT]<=15)
////							{
////								YUME_Tracer_Check();
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								mov_rot_right(FAST_LEVEL_3, FAR);
////								OVERRIDE=1;
////							}
////							Cat_Avoider();
//							YUME_Tracer_Check();
//							Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE RIGHT OVERRIDE \r");
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							mov_rot_right(MED, FAR);
//							OVERRIDE=1;
//
//							Cat_Avoider();
//							Evade_Wall();
//						}
//
//						if(OVERRIDE==1){break;}
//
//						if (OVERRIDE==0)
//						{
//							YUME_Tracer_Check();
//							curve_right_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						}
//
//						YUME_Tracer_Check();
//						Cat_Avoider();
//					}
//
//				Evade_Wall();
//				YUME_Tracer_Check();
//				Cat_Avoider();
//			}
//		}
//	}
//
//}
//
//
//void Escape_Warzone(void)
//{
//	UV_state=1;
//	UV_Lock=0;
//	//mov_fwd_5cm(15,FAST_LEVEL_3);
//	Get_IR();
//
//	YUME_Tracer_Check();
//
//	if(F_DETECTED_COLOUR==COLOUR_RED)
//	{
//		Sendto_PC(USART1,"YUME ESCAPING RED WARZONE \r");
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//		FollowExit_Right();
//	}
//
//	else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//	{
//		Sendto_PC(USART1,"YUME ESCAPING BLUE WARZONE \r");
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
//
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
//		FollowExit_Left();
//	}
//
//
//}
//
//void ReturnTo_Room(void)
//{
//	if(INITIAL_ZONE==ZONE_BLUE)
//	{
//		Sendto_PC(USART1,"YUME Returnto_Room BLUE ZONE \r");
//		Get_IR();
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//		mov_fwd_5cm(10,FAST);
//	}
//
//	else if(INITIAL_ZONE==ZONE_RED)
//	{
//		Sendto_PC(USART1,"YUME Returnto_Room RED ZONE \r");
//		Get_IR();
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
//
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
//		mov_fwd_5cm(10,FAST);
//	}
//	RETURN_COUNTER++;
//
//	if(RETURN_COUNTER>=2)
//	{
//		YUME_Buzz(4);
//		if(INITIAL_ZONE==ZONE_RED)
//		{
//			if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
//			{
//				followfire_left_new();
//			}
//			else
//			{
//				followfire_right_new();
//
//			}
//
//		}
//		else if(INITIAL_ZONE==ZONE_BLUE)
//		{
//			if(VARIABLE_DOOR==VAR_DOOR_DETECTED)
//			{
//				followfire_right_new();
//			}
//			else
//			{
//				followfire_left_new();
//			}
//
//		}
//	}
//
//}
//
//void Home_Detection_Blue(void)
//{
//	unsigned int HOME;
//
//	HOME=1;
//	if (HOME==1)
//	{
//
//		if (Ping[PING_FRONT]>30)
//		{
//			YUME_Buzz(1);
//			if( Ping[PING_LEFT]>15 || Ping[PING_ASKEW_LEFT]>15)
//			{
//				mov_rot_left(MED,FAR); //adjust to correct position
//				mov_rot_left(MED,FAR); //adjust to correct position
//				mov_rot_left(MED,FAR); //adjust to correct position
//				while(
//						(Ping[PING_LEFT]>=15) && (Ping[PING_ASKEW_LEFT]>=15)
//					 )
//				{
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//					mov_rot_left(MED,FAR);
//					if(Ping[PING_FRONT]<=13 )
//					{
//						mov_bwd(5,FAST);
//					}
//
//				}
//			}
//
//		}
//
//		else if(Ping[PING_FRONT]<=30)
//		{
//			YUME_Buzz(2);
//
//			while(
//				   ( (Ping[PING_FRONT]<=30) && (Ping[PING_LEFT]>=15) ) ||
//				   ( (Ping[PING_FRONT]<=30 && Ping[PING_LEFT]<=15)   )
//				 )
//			{
//				if(Ping[PING_FRONT]<=13 )
//				{
//					mov_bwd(5,FAST);
//				}
//				mov_rot_right(MED,FAR);
//			}
//			while(Ping[PING_ASKEW_LEFT]<=14)
//			{
//				mov_rot_right(MED,FAR);
//				mov_rot_right(MED,FAR);
//			}
//		}
//
//	}
//
//}
//
///* func      : void Home_Detection_Red(void)
// * brief     : Detecting Home in RED Zone
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Wednesday, November 25th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void Home_Detection_Red(void)
//{
//	unsigned int HOME;
//
//	HOME=1;
//	if (HOME==1)
//	{
//
//		if (Ping[PING_FRONT]>30)
//		{
//			YUME_Buzz(1);
//
//			if( Ping[PING_RIGHT]>15 || Ping[PING_ASKEW_RIGHT]>15)
//			{
//				mov_rot_right(MED,FAR); //adjust to correct position
//				mov_rot_right(MED,FAR); //adjust to correct position
//				mov_rot_right(MED,FAR); //adjust to correct position
//				while(
//						(Ping[PING_RIGHT]>=15) && (Ping[PING_ASKEW_RIGHT]>=15)
//					 )
//				{
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					mov_rot_right(MED,FAR);
//					if(Ping[PING_FRONT]<=13 )
//					{
//						mov_bwd(5,FAST);
//					}
//
//				}
//			}
//
//		}
//
//		else if(Ping[PING_FRONT]<=30)
//		{
//			YUME_Buzz(2);
//
//			while(
//				   ( (Ping[PING_FRONT]<=30) && (Ping[PING_RIGHT]>=15) ) ||
//				   ( (Ping[PING_FRONT]<=30 && Ping[PING_RIGHT]<=15)   )
//				 )
//			{
//				if(Ping[PING_FRONT]<=13 )
//				{
//					mov_bwd(5,FAST);
//				}
//				mov_rot_left(MED,FAR);
//			}
//			while(Ping[PING_ASKEW_RIGHT]<=15)
//			{
//				mov_rot_left(MED,FAR);
//			}
//		}
//
//	}
//}
//
//void YUME_Celebrate(void)
//{
//	Sendto_PC(USART1,"YUME Celebrate Movement \r");
//
//	mov_static();
//	delay_ms(1000);
//	int counter=0;
//	int adder;
//	//STATIC
//
//	inv_kine(front_left,30,11,leg-5);
//	inv_kine(front_right,30,11,leg-5);
//	inv_kine(middle_left,60,7,leg);
//	inv_kine(middle_right,60,7,leg);
//	inv_kine(rear_left,120,9,leg-2);
//	inv_kine(rear_right,120,10,leg-3);
//	delay_ms(300);
//	YUME_Buzz(3);
//
//	for(counter=0;counter<=8;counter++)
//	{
//		inv_kine(front_left,30,11,leg-5);
//		inv_kine(front_right,30,7,leg);
//		inv_kine(middle_left,60,7,leg);
//		inv_kine(middle_right,60,7,leg);
//		inv_kine(rear_left,120,9,leg-2);
//		inv_kine(rear_right,120,10,leg-3);
//		delay_ms(50);
//		YUME_Buzz(3);
//
//		inv_kine(front_left,30,7,leg);
//		inv_kine(front_right,30,11,leg-5);
//		inv_kine(middle_left,60,7,leg);
//		inv_kine(middle_right,60,7,leg);
//		inv_kine(rear_left,120,9,leg-2);
//		inv_kine(rear_right,120,10,leg-3);
//		delay_ms(50);
//		YUME_Buzz(3);
//	}
//
//
//
//
//	for(adder=30;adder<=150;adder+=5)
//	{
//		inv_kine(front_left,adder,11,leg-5);
//		inv_kine(front_right,adder,11,leg-5);
//		inv_kine(middle_left,60,7,leg);
//		inv_kine(middle_right,60,7,leg);
//		inv_kine(rear_left,120,9,leg-2);
//		inv_kine(rear_right,120,10,leg-3);
//		delay_ms(10);
//	}
//	YUME_Buzz(3);
//	delay_ms(200);
//
////	YUME_BLDC_ON;
////	delay_ms(2000);
////	YUME_BLDC_OFF;
//
//	delay_ms(2000);
//
//	for(adder=150;adder>=30;adder-=5)
//	{
//		inv_kine(front_left,adder,11,leg-5);
//		inv_kine(front_right,adder,11,leg-5);
//		inv_kine(middle_left,60,7,leg);
//		inv_kine(middle_right,60,7,leg);
//		inv_kine(rear_left,120,9,leg-2);
//		inv_kine(rear_right,120,10,leg-3);
//		delay_ms(10);
//	}
//	delay_ms(200);
//	YUME_Buzz(3);
//
//	mov_static();
//	delay_ms(200);
//
//	//YUME_Extinguisher();
//
////	while(1)
////	{
////		mov_static();
////		delay_ms(100);
////		YUME_Buzz(8);
////	}
//}
//
///* func      : void FollowCrossing_Right(void)
// * brief     : Wall following right rule using PID controller until YUME crossing the borderline
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Friday, November 27th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void FollowCrossing_Right(void)
//{
//	Sendto_PC(USART1,"YUME FollowCrossing_Right! \r");
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//	while(YUME_CROSSING_STATUS==NO_CROSSING)
//	{
//		if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//		else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//		{
//			YUME_CROSSING_STATUS=CROSSING_FAILED;
//			break;
//		}
//
//		Evade_Wall();
//		YUME_Tracer_Check();
//
//		if (Ping[PING_FRONT]<=10)
//		{
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT \r");
//			mov_rot_left(MED, FAR);
//			mov_rot_left(MED, FAR);
//			mov_rot_left(MED, FAR);
//
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//			else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//			{
//				YUME_CROSSING_STATUS=CROSSING_FAILED;
//				break;
//			}
//
//
//		}
//		else
//		{
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			PID_FollowCrossing_Right();
//			if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//			else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//			{
//				YUME_CROSSING_STATUS=CROSSING_FAILED;
//				break;
//			}
//		}
//	}
//
//}
//
///* func      : void PID_FollowCrossing_Right(void)
// * brief     : Wall following right rule using PID controller until YUME crossing the borderline
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Friday, November 27th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_FollowCrossing_Right(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//	OVERRIDE=0;
//
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//	while(YUME_CROSSING_STATUS==NO_CROSSING)
//	{
//		OVERRIDE=0;
//		while(OVERRIDE==0)
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			PID_Calc();
//			YUME_Tracer_Check();
//
//
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//				{
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Evade_Wall();
//
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//
//					}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//					else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//				{
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//					if (PID_F_R.pid_value[0]>15) PID_F_R.pid_value[0]=15; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Evade_Wall();
//
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						curve_right_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//					else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//				{
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//					if (PID_F_R.pid_value[0]>15) PID_F_R.pid_value[0]=15; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Evade_Wall();
//
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						curve_left_new(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//					else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//				}
//
//			Evade_Wall();
//			YUME_Tracer_Check();
//			OVERRIDE=0;
//		}
//		OVERRIDE=0;
//		if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//		else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//		{
//			YUME_CROSSING_STATUS=CROSSING_FAILED;
//			break;
//		}
//	}
//	OVERRIDE=0;
//
//}
//
//
///* func      : void FollowCrossing_Left(void)
// * brief     : Wall following right rule using PID controller until YUME crossing the borderline
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Friday, November 27th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void FollowCrossing_Left(void)
//{
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//	while(YUME_CROSSING_STATUS==NO_CROSSING)
//	{
//		if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//		else if(F_DETECTED_COLOUR==COLOUR_RED)
//		{
//			YUME_CROSSING_STATUS=CROSSING_FAILED;
//			break;
//		}
//		else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//		{
//			YUME_CROSSING_STATUS=CROSSING_FAILED;
//			break;
//		}
//
//		Evade_Wall();
//		YUME_Tracer_Check();
//
//		if (Ping[PING_FRONT]<=10)
//		{
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT \r");
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//			else if(F_DETECTED_COLOUR==COLOUR_RED)
//			{
//				YUME_CROSSING_STATUS=CROSSING_FAILED;
//				break;
//			}
//			else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//			{
//				YUME_CROSSING_STATUS=CROSSING_FAILED;
//				break;
//			}
//
//
//		}
//		else
//		{
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			PID_FollowCrossing_Left();
//			if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//			else if(F_DETECTED_COLOUR==COLOUR_RED)
//			{
//				YUME_CROSSING_STATUS=CROSSING_FAILED;
//				break;
//			}
//			else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//			{
//				YUME_CROSSING_STATUS=CROSSING_FAILED;
//				break;
//			}
//		}
//	}
//
//}
//
///* func      : void PID_FollowCrossing_Right(void)
// * brief     : Wall following right rule using PID controller until YUME crossing the borderline
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Friday, November 27th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_FollowCrossing_Left(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//	OVERRIDE=0;
//
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//	while(YUME_CROSSING_STATUS==NO_CROSSING)
//	{
//		OVERRIDE=0;
//		while(OVERRIDE==0)
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			PID_Calc_LeftRule();
//			YUME_Tracer_Check();
//
//
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//				{
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Evade_Wall();
//
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_RED)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//
//					}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_RED)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//					else if(F_DETECTED_COLOUR==COLOUR_RED)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//					else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//				{
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Evade_Wall();
//
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_RED)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						curve_right_new(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_RED)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//					else if(F_DETECTED_COLOUR==COLOUR_RED)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//					else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//				{
//					Evade_Wall();
//					YUME_Tracer_Check();
//
//					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Evade_Wall();
//
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_RED)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5, FAST_LEVEL_3);
//						curve_left_new(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//						if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//						else if(F_DETECTED_COLOUR==COLOUR_RED)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//						else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//						{
//							YUME_CROSSING_STATUS=CROSSING_FAILED;
//							break;
//						}
//					}
//
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//					else if(F_DETECTED_COLOUR==COLOUR_RED)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//					else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//					{
//						YUME_CROSSING_STATUS=CROSSING_FAILED;
//						break;
//					}
//				}
//
//			Evade_Wall();
//			YUME_Tracer_Check();
//			OVERRIDE=0;
//		}
//		OVERRIDE=0;
//		if(YUME_CROSSING_STATUS==CROSSING_SUCCESS) break;
//		else if(F_DETECTED_COLOUR==COLOUR_RED)
//		{
//			YUME_CROSSING_STATUS=CROSSING_FAILED;
//			break;
//		}
//		else if(F_DETECTED_COLOUR==COLOUR_BLUE)
//		{
//			YUME_CROSSING_STATUS=CROSSING_FAILED;
//			break;
//		}
//	}
//	OVERRIDE=0;
//
//}
//
//
///* func      : void ReturnTo_Zone(void)
// * brief     : Return to initial zone after crossing the borderline
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Friday, November 27th 2015)
// * Revised BY: N/A
// * programmer's Note:
// */
//void ReturnTo_Zone(void)
//{
//	RETURN_FLAG=RETURN_ENABLED;
//
//	if(INITIAL_ZONE==ZONE_RED)
//	{
//		Sendto_PC(USART1,"YUME Return to RED ZONE \r");
//		Get_IR();
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
////			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
////		mov_fwd_5cm(25,FAST);
////		Evade_Wall_Room_Red();
////		YUME_PID_Init();
////		FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//		YUME_PID_Init();
//
//		FollowCarpet_Right(&COLOUR_RED,&INVERSE);
//		RETURN_FLAG=RETURN_DISABLED;
//		FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//	}
//
//	else if(INITIAL_ZONE==ZONE_BLUE)
//	{
//		Sendto_PC(USART1,"YUME Return to BLUE ZONE \r");
//		Get_IR();
//		while ( (Ping[PING_FRONT]>=30) && (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) )
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
//
//		Get_IR();
//		while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
////			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
////		YUME_PID_Init();
////		FollowCarpet_Left(&COLOUR_BLACK,&INVERSE);
//		YUME_PID_Init();
//		FollowCarpet_Left(&COLOUR_BLUE,&INVERSE);
//		RETURN_FLAG=RETURN_DISABLED;
//		FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
////		Evade_Wall_Room_Blue();
//	}
//}
//
//void ReturnTo_BlueWarzone(void)
//{
//	Sendto_PC(USART1,"YUME Return to BLUE WARZONE \r");
//	Get_IR();
//	while ( (Ping[PING_FRONT]>=30) || ( (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) ) )
//	{
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		Get_IR();
//	}
//	Get_IR();
//	while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//	{
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		Get_IR();
//	}
//
//	YUME_Buzz(1);
//	YUME_PID_Init();
//	follow_right_counter(7);
//}
//
//void ReturnTo_RedWarzone(void)
//{
//	Sendto_PC(USART1,"YUME Return to BLUE WARZONE \r");
//	Get_IR();
//	while ( (Ping[PING_FRONT]>=30) || ( (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)) )
//	{
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		Get_IR();
//	}
//	Get_IR();
//	while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//	{
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		Get_IR();
//	}
//
//	YUME_Buzz(1);
//	YUME_PID_Init();
//	follow_left_counter(7);
//}
//
//
//void ReturnTo_RedZone(void)
//{
//	RETURN_FLAG=RETURN_ENABLED;
//
//	Sendto_PC(USART1,"YUME Return to RED ZONE \r");
//	Get_IR();
//	while ( (Ping[PING_FRONT]>=30) || ((INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED)) )
//	{
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		Get_IR();
//	}
//	Get_IR();
//	while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//	{
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		Get_IR();
//	}
//
//	YUME_Buzz(1);
//	YUME_PID_Init();
//	follow_right_counter(10);
//
//	YUME_Buzz(1);
//	YUME_PID_Init();
//	FollowCarpet_Right(&COLOUR_RED,&INVERSE);
//
//	RETURN_FLAG=RETURN_DISABLED;
//	FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//}
//
//void ReturnTo_BlueZone(void)
//{
//	RETURN_FLAG=RETURN_ENABLED;
//
//	Sendto_PC(USART1,"YUME Return to BLUE ZONE \r");
//	Get_IR();
//	while ( (Ping[PING_FRONT]>=30) || ( (INFRARED[IR_FRONT_LEFT]==IR_NOT_DETECTED) && (INFRARED[IR_FRONT_RIGHT]==IR_NOT_DETECTED) ) )
//	{
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		Get_IR();
//	}
//
//	Get_IR();
//	while ( Ping[PING_FRONT]<=30 || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED))
//	{
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		Get_IR();
//	}
//
//	YUME_Buzz(1);
//	YUME_PID_Init();
//	follow_left_counter(10);
//
//	YUME_Buzz(1);
//	YUME_PID_Init();
//	FollowCarpet_Left(&COLOUR_BLUE,&INVERSE);
//
//	RETURN_FLAG=RETURN_DISABLED;
//	FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//}
//
//
///*
// *  FOLLOW EVADE HOME CIRCLE
// */
//
//
//void FollowEvade_HomeCircle_Right(int limit)
//{
//	int counter;
//	//int limit=15;
//	Cat_Avoider();
//	Evade_Wall();
//
//	for(counter=1;counter<=limit;counter++)
//	{
//		Cat_Avoider();
//		Evade_Wall();
//
//		if (Ping[PING_FRONT]<=10)
//		{
//
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE LEFT \r");
//			mov_rot_left(MED, FAR);
//			mov_rot_left(MED, FAR);
//			mov_rot_left(MED, FAR);
//
//			Cat_Avoider();
//			Evade_Wall();
//
////			if (Ping[PING_RIGHT]<=20)
////			{
////				Sendto_PC(USART1,"YUME ROTATE LEFT \r");
////				mov_rot_left(FAST, FAR);
////			}
////
////			if (Ping[PING_RIGHT]>20)
////			{
////				Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
////				mov_rot_right(FAST, FAR);
////			}
//		}
//		else
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			PID_FollowEvade_HomeCircle_Right();
//		}
//	}
//
//
//
//}
//
///* func      : void PID_follow_tracer_right(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_FollowEvade_HomeCircle_Right(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//	Cat_Avoider();
//	Evade_Wall();
//
//
//	PID_Calc();
//
//	while(OVERRIDE==0)
//	{
//		Cat_Avoider();
//		Evade_Wall();
//
//		if(OVERRIDE==0)
//		{
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//			if ( (Ping[PING_ASKEW_RIGHT]<=PID_F_R.set_point_upper) && (Ping[PING_ASKEW_RIGHT]>=PID_F_R.set_point_lower) )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					if (Ping[PING_FRONT]<=10)
//					{
//						Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
////						if (Ping[PING_RIGHT]<=15)
////						{
////
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						else if (Ping[PING_RIGHT]>15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
//						OVERRIDE=1;
//					}
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_RIGHT]>PID_F_R.set_point )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
////						if (Ping[PING_RIGHT]<=15)
////						{
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						else if (Ping[PING_RIGHT]>15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//						curve_right_evade(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						OVERRIDE=1;
//					}
//
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_RIGHT]<PID_F_R.set_point )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					if (PID_F_R.pid_value[0]>5) PID_F_R.pid_value[0]=5; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//						Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE LEFT OVERRIDE \r");
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						mov_rot_left(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
////						if (Ping[PING_RIGHT]<=15)
////						{
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_RIGHT]>15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//						curve_left_evade(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						OVERRIDE=1;
//					}
//
//				}
//		}
//	}
//
//}
//
//void FollowEvade_HomeCircle_Left(int limit)
//{
//	int counter;
//	Cat_Avoider();
//	Evade_Wall();
//	//int limit=15;
//	for(counter=1;counter<=limit;counter++)
//	{
//		Cat_Avoider();
//		Evade_Wall();
//		if (Ping[PING_FRONT]<=10)
//		{
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//
//			Cat_Avoider();
//			Evade_Wall();
//
////			Cat_Avoider();
////			Evade_Wall();
////			if (Ping[PING_LEFT]>=20)
////			{
////				Sendto_PC(USART1,"YUME ROTATE LEFT \r");
////				mov_rot_left(FAST, FAR);
////			}
////
////			if (Ping[PING_LEFT]<20)
////			{
////				Sendto_PC(USART1,"YUME ROTATE RIGHT \r");
////				mov_rot_right(FAST, FAR);
////			}
//		}
//		else
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			PID_FollowEvade_HomeCircle_Left();
//		}
//	}
//
//
//
//}
//
///* func      : void PID_follow_tracer_right(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_FollowEvade_HomeCircle_Left(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//	Cat_Avoider();
//	Evade_Wall();
//
//	PID_Calc_LeftRule();
//
//	while(OVERRIDE==0)
//	{
//		Cat_Avoider();
//		Evade_Wall();
//		if(OVERRIDE==0)
//		{
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					if (Ping[PING_FRONT]<=10)
//					{
//						Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
////						if (Ping[PING_LEFT]>=15)
////						{
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_LEFT]<15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_5cm(5, FAST_LEVEL_3);
//						OVERRIDE=1;
//					}
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//
//						Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
////						if (Ping[PING_LEFT]>=15)
////						{
////
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_LEFT]<15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//						curve_right_evade(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						OVERRIDE=1;
//					}
//
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					if (PID_F_L.pid_value[0]>5) PID_F_L.pid_value[0]=5; //WINDUP
//
//					if (Ping[PING_FRONT]<=10)
//					{
//
//
//						Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
////						if (Ping[PING_LEFT]>=15)
////						{
////
////							mov_rot_left(FAST, FAR);
////							mov_rot_left(FAST, FAR);
////							OVERRIDE=1;
////						}
////						if (Ping[PING_LEFT]<15)
////						{
////							mov_rot_right(FAST, FAR);
////							mov_rot_right(FAST, FAR);
////							OVERRIDE=1;
////						}
//					}
//
//					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//						curve_left_evade(FAST_LEVEL_3, FAR, &PID_F_R.pid_value[0]);
//						OVERRIDE=1;
//					}
//
//				}
//		}
//	}
//
//}
//
//void curve_right_evade(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	Sendto_PC(USART1,"YUME Curve Right Counter \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	unsigned int DELTA_FL=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_FR=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_ML=15+ (1 * *COMMAND_LOOP);
//	//unsigned int DELTA_MR;
//	unsigned int DELTA_RL=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RR=10+ (1 * *COMMAND_LOOP);
//
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3],10,leg-3);
//	inv_kine(middle_left,90+beta[1],10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5],10,leg-3);
//	delay_ms(SPEED);
//
//	//2
//	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]+DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90-beta[1]-DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]+DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	//3
//	inv_kine(front_left,90+beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90-beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90+beta[4],7,leg);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	//4
//	inv_kine(front_left,90+beta[0]+DELTA_FL,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4],10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]+DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	//5
//	inv_kine(front_left,90-beta[0]-DELTA_FL,10,leg-3);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]-DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//
//	//6
//	inv_kine(front_left,90-beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90+beta[3],7,leg);
//	inv_kine(middle_left,90+beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]+10,7,leg);
//	inv_kine(rear_left,90-beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(SPEED);
//}
//
//
//void curve_left_evade(int SPEED, int STEP, float *COMMAND_LOOP)
//{
//	Sendto_PC(USART1,"YUME Curve Left Counter \r");
//	generate_movement_data(0,STEP,10);
//	delay_ms(50);
//
//	unsigned int DELTA_FL=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_FR=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_ML=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_MR=15+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RL=10+ (1 * *COMMAND_LOOP);
//	unsigned int DELTA_RR=15+ (1 * *COMMAND_LOOP);
//
//	//1
//	inv_kine(front_left,90,7,leg);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90,7,leg);
//	inv_kine(rear_left,90,7,leg);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	//2
//	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]-DELTA_FR,10,leg-3);
//	inv_kine(middle_left,90-beta[1]+DELTA_ML,10,leg-3);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]-DELTA_RR,10,leg-3);
//	delay_ms(SPEED);
//
//	//3
//	inv_kine(front_left,90+beta[0]-DELTA_FL,7,leg);
//	inv_kine(front_right,90-beta[3]-DELTA_FR,7,leg);
//	inv_kine(middle_left,90-beta[1]+DELTA_ML,7,leg);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,7,leg);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,7,leg);
//	inv_kine(rear_right,90-beta[5]-DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	//4
//	inv_kine(front_left,90+beta[0]-DELTA_FL,10,leg-3);
//	inv_kine(front_right,90,7,leg);
//	inv_kine(middle_left,90,7,leg);
//	inv_kine(middle_right,90+beta[4]+DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90+beta[2]-DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(SPEED);
//
//	//5
//	inv_kine(front_left,90-beta[0]+DELTA_FL,10,leg-3);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]-DELTA_MR,10.5,leg-3);
//	inv_kine(rear_left,90-beta[2]+DELTA_RL,10,leg-3);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//
//	//6
//	inv_kine(front_left,90-beta[0]+DELTA_FL,7,leg);
//	inv_kine(front_right,90+beta[3]+DELTA_FR,7,leg);
//	inv_kine(middle_left,90+beta[1]-DELTA_ML,7,leg);
//	inv_kine(middle_right,90-beta[4]-DELTA_MR,7,leg);
//	inv_kine(rear_left,90-beta[2]+DELTA_RL,7,leg);
//	inv_kine(rear_right,90+beta[5]+DELTA_RR,7,leg);
//	delay_ms(SPEED);
//}
//
//void YUME_CrossingTo_RedZone(void)
//{
//
//
//	YUME_FireScan();
//	Get_UV();
//
//	//STEAL CANDLE IN ROOM 3 RED ZONE
//	if( (UV_state==1) && (EXTINGUISHED_FIRE>=1) )
//	{
//		ENEMY_ZONE_STAT=ENEMY_ZONE;
//		YUME_Buzz(4);
//
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//		mov_rot_left(MED,FAR);
//
//		Get_IR();
//		while( (Ping[PING_FRONT]<=10) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//		{
//			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//
//		CAT_SHIFT_FOLLOW=NO_SHIFT;
//		while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//		{
//			CAT_SHIFT_FOLLOW=NO_SHIFT;
//			Sendto_PC(USART1,"\rYUME FOLLOW LEFT UNTIL TRACER DETECTED\r");
//			YUME_PID_Init();
//			followtracer_left();
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		}
//
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//			YUME_Buzz(4);
//
//			ROOM_COUNTER++;
//			while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//			{
//				Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//				YUME_ENEMY_ROOM_RED();
//				if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//			}
//
//		}
//
//		YUME_Buzz(1);
//		while((Ping[PING_FRONT]>=15))
//		{
//			mov_fwd_5cm(5,FAST);
//		}
//
//		Get_IR();
//		while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//		{
//			mov_rot_right(MED,FAR);
//			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
//
//		follow_left_counter(15);
//
//	}
//
//
//	//DEFAULT
//	else
//	{
//		YUME_Buzz(1);
//		mov_fwd_5cm(30,FAST);
//		ReturnTo_BlueZone();
//
//	}
//
//	ENEMY_ZONE_STAT=COMFORT_ZONE;
//
//
//
//}
//
//void YUME_CrossingTo_BlueZone(void)
//{
//	YUME_FireScan();
//	Get_UV();
//
//	//STEAL CANDLE IN ROOM 3 BLUE ZONE
//	if( (UV_Lock==1) && (EXTINGUISHED_FIRE>=1) )
//	{
//		ENEMY_ZONE_STAT=ENEMY_ZONE;
//		YUME_Buzz(4);
//
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//		mov_rot_right(MED,FAR);
//
//		Get_IR();
//		while( (Ping[PING_FRONT]<=10) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//		{
//			mov_rot_right(MED,FAR);
//			Get_IR();
//		}
//
//
//		CAT_SHIFT_FOLLOW=NO_SHIFT;
//		while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//		{
//			CAT_SHIFT_FOLLOW=NO_SHIFT;
//			Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//			YUME_PID_Init();
//			follow_right_new();
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		}
//
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//			YUME_Buzz(4);
//
//			ROOM_COUNTER++;
//			while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//			{
//				Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//				YUME_ENEMY_ROOM_BLUE();
//				if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//			}
//		}
//
//		//YUME ON BLUE ZONE CORRIDOR
//		YUME_Buzz(1);
//		while((Ping[PING_FRONT]>=15))
//		{
//			mov_fwd_5cm(5,FAST);
//		}
//
//		Get_IR();
//		while( (Ping[PING_FRONT]<=25) || (INFRARED[IR_FRONT_RIGHT]==IR_DETECTED) || (INFRARED[IR_FRONT_LEFT]==IR_DETECTED) )
//		{
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			Get_IR();
//		}
//
//		follow_right_counter(15);
//
//	}
//
//
//
//
////	//FAILED TO EXTINGUISH CANDLE IN ROOM 3 BUT DETECT FIRE IN REDZONE
////	else if (UV_Lock==1)
////	{
////		YUME_Buzz(2);
////		mov_fwd_5cm(25,FAST);
////
////	}
//
//	//DEFAULT
//	else
//	{
//		YUME_Buzz(1);
//		mov_fwd_5cm(30,FAST);
//		ReturnTo_RedZone();
//
//	}
//
//
//
//
//	ENEMY_ZONE_STAT=COMFORT_ZONE;
//
//}
//
//
//
//void YUME_ENEMY_ROOM_RED(void)
//{
//	FIRE_PUTOFF=0;
//	WARZONE_FLAG=0;
//	UV_state=1;
//	UV_Lock=0;
//	firetrack_counter=0;
//
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		YUME_Buzz(2);
//		Get_UV();
//		Get_UV();
//
//		if( (UV_state==FIRE_DETECTED)||(UV_Lock==1) )
//		{
//			YUME_Buzz(1);
//			Sendto_PC(USART1,"YUME ON ENEMY FIRE ROOM RED ZONE \r");
//
//			YUME_FireFight_EnemyRed();
//		}
//	}
//}
//
//void YUME_ENEMY_ROOM_BLUE(void)
//{
//	FIRE_PUTOFF=0;
//	WARZONE_FLAG=0;
//	UV_state=1;
//	UV_Lock=0;
//	firetrack_counter=0;
//
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		YUME_Buzz(2);
//		Get_UV();
//		Get_UV();
//
//		if( (UV_state==FIRE_DETECTED)||(UV_Lock==1) )
//		{
//			YUME_Buzz(1);
//			Sendto_PC(USART1,"YUME ON ENEMY FIRE ROOM BLUE ZONE \r");
//
//			YUME_FireFight_EnemyBlue();
//		}
//	}
//}
//
//void YUME_FireFight_EnemyRed(void)
//{
//	FIRE_PUTOFF=0;
//	firetrack_counter=0;
//	Get_UV();
//	Get_IR();
//	Get_TPA81();
//	led_off_counter=0;
//
//	while( (UV_Lock==1) )
//	{
//		YUME_LED_BLINK_ON;
//		Get_UV();
//		Get_TPA81();
//
//		if(FIRE==1)YUME_Found_Fire();
//
//		YUME_FireTracker();
//		YUME_PID_Init();
//
//		followfire_left_new();
//
//		if(FIRE_PUTOFF==1) break;
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//
//	Get_UV();
//	if(UV_state==NO_FIRE)
//	{
//		UV_Lock=0;
//		led_off_counter=1;
//	}
//
//	Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER LEFT RULE=== \r\r");
//	YUME_PID_Init();
//	follow_left_counter(10);
//
//	FRONT_Sum_Colour();
//	F_TRACER= TRACER_STAT;
//	MID_Sum_Colour();
//	M_TRACER= TRACER_STAT;
//	while( (F_TRACER==TRACER_DETECTED)||(M_TRACER==TRACER_DETECTED) )
//	{
//		FRONT_Sum_Colour();
//		F_TRACER= TRACER_STAT;
//		MID_Sum_Colour();
//		M_TRACER= TRACER_STAT;
//		Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER LEFT RULE=== \r\r");
//		YUME_PID_Init();
//		follow_left_counter(5);
//	}
//
//	Sendto_PC(USART1,"\r\r ===YUME FOLLOW EXIT LEFT RULE=== \r\r");
//	YUME_PID_Init();
//	FollowExit_Left();
//
//	YUME_LED_BLINK_OFF;
//
//	//UPDATE VARIABLES
//	STEAL_FIRE_STAT= STEALFIRE_SUCCESS;
//	STEAL_FIRE_COUNTER++;
//
//}
//
//void YUME_FireFight_EnemyBlue(void)
//{
//	FIRE_PUTOFF=0;
//	firetrack_counter=0;
//	Get_UV();
//	Get_IR();
//	Get_TPA81();
//	led_off_counter=0;
//
//	while( (UV_Lock==1) )
//	{
//		YUME_LED_BLINK_ON;
//		Get_UV();
//		Get_TPA81();
//
//		if(FIRE==1)YUME_Found_Fire();
//
//		YUME_FireTracker();
//		YUME_PID_Init();
//
//		followfire_right_new();
//
//		if(FIRE_PUTOFF==1) break;
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//
//	Get_UV();
//	if(UV_state==NO_FIRE)
//	{
//		UV_Lock=0;
//		led_off_counter=1;
//	}
//
//	Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER RIGHT RULE=== \r\r");
//	YUME_PID_Init();
//	follow_right_counter(10);
//
//	FRONT_Sum_Colour();
//	F_TRACER= TRACER_STAT;
//	MID_Sum_Colour();
//	M_TRACER= TRACER_STAT;
//	while( (F_TRACER==TRACER_DETECTED)||(M_TRACER==TRACER_DETECTED) )
//	{
//		FRONT_Sum_Colour();
//		F_TRACER= TRACER_STAT;
//		MID_Sum_Colour();
//		M_TRACER= TRACER_STAT;
//		Sendto_PC(USART1,"\r\r ===YUME FOLLOW COUNTER RIGHT RULE=== \r\r");
//		YUME_PID_Init();
//		follow_right_counter(5);
//	}
//
//	Sendto_PC(USART1,"\r\r ===YUME FOLLOW EXIT RIGHT RULE=== \r\r");
//	YUME_PID_Init();
//	FollowExit_Right();
//
//	YUME_LED_BLINK_OFF;
//
//	STEAL_FIRE_STAT= STEALFIRE_SUCCESS;
//	STEAL_FIRE_COUNTER++;
//
//}
//
//
///* func      : void followtracer_left(void)
// * brief     : Wall following left rule algorithm using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 28th 2015)
// * Revised BY: N/A
// * programmer's Note:
// *
// */
//void followhome_left(void)
//{
//	Cat_Avoider();
//	Evade_Wall();
//	YUME_Tracer_Check();
//	Sendto_PC(USART1,"followtracer_left \r");
//	Sendto_PC(USART1,"YUME_LOCATION[PRESENT_LOC]: %d \r",YUME_LOCATION[PRESENT_LOC]);
//	Sendto_PC(USART1,"CAT_SHIFT_FOLLOW: %d \r",CAT_SHIFT_FOLLOW);
//	CAT_SHIFT_FOLLOW=0;
//
//	while( (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//			&& (CAT_SHIFT_FOLLOW==NO_SHIFT)
//			&& RETURN_TRIP_FLAG==RETURN_ENABLED)
//	{
//		Cat_Avoider();
//		Evade_Wall();
//		YUME_Tracer_Check();
//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//
//		if (Ping[PING_FRONT]<=15)
//		{
//			Sendto_PC(USART1,"YUME FACING WALL - ROTATE RIGHT \r");
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//			mov_rot_right(MED, FAR);
//
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//			if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//		}
//		else
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			YUME_Tracer_Check();
//
//			PID_followhome_left();
//			if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//			if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//		}
//	}
//
//}
//
///* func      : void PID_followtracer_left(void)
// * brief     : Wall following using PID controller until YUME detects TRACER LINE
// * param     : N/A
// * retval    : N/A
// * Ver       : 1
// * written By: Ryan (Monday, October 19th 2015)
// * Revised BY: N/A
// * programmer's Note: This function MUST be called int the corresponding wall following algorithm
// *
// */
//void PID_followhome_left(void)
//{
//	//int limit= *COMMAND_LOOP;
//	int OVERRIDE=0;
//	OVERRIDE=0;
//
//	Cat_Avoider();
//	Evade_Wall();
//	YUME_Tracer_Check();
//
//	while( (YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//			&& (CAT_SHIFT_FOLLOW==NO_SHIFT)
//			&& RETURN_TRIP_FLAG==RETURN_ENABLED)
//	{
//		OVERRIDE=0;
//		while(OVERRIDE==0)
//		{
//			Cat_Avoider();
//			Evade_Wall();
//			PID_Calc_LeftRule();
//
//			YUME_Tracer_Check();
//			//KONDISI ROBOT SESUAI
//			//if ( Ping[PING_ASKEW_RIGHT]==PID_F_R.set_point )
//			if ( (Ping[PING_ASKEW_LEFT]<=PID_F_L.set_point_upper) && (Ping[PING_ASKEW_LEFT]>=PID_F_L.set_point_lower) )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if (Ping[PING_FRONT]<=15)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL == SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FORWARD \r");
//						mov_fwd_trace(5,FAST_LEVEL_3);
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//					}
//					Cat_Avoider();
//					Evade_Wall();
//					YUME_Tracer_Check();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//				}
//
//			//KONDISI ROBOT JAUH DARI DINDING
//			else if ( Ping[PING_ASKEW_LEFT]<PID_F_L.set_point )
//				{
//					Cat_Avoider();
//					Evade_Wall();
//
//					YUME_Tracer_Check();
//					if (PID_F_L.pid_value[0]>8) PID_F_L.pid_value[0]=8; //WINDUP
//
//					if (Ping[PING_FRONT]<=15)
//					{
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL < SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						Evade_Wall();
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//
//						YUME_Tracer_Check();
//						curve_right_new(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//					}
//
//					YUME_Tracer_Check();
//					Cat_Avoider();
//					Evade_Wall();
//
////					if(OVERRIDE==1){break;}
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//				}
//
//			//KONDISI ROBOT DEKAT DENGAN DINDING
//			else if ( Ping[PING_ASKEW_LEFT]>PID_F_L.set_point )
//				{
//					YUME_Tracer_Check();
//					if (PID_F_L.pid_value[0]>8) PID_F_L.pid_value[0]=8; //WINDUP
//
//					if (Ping[PING_FRONT]<=15)
//					{
//
//						YUME_Tracer_Check();
//						Sendto_PC(USART1,"YUME FACING WALL > SP - ROTATE RIGHT OVERRIDE \r");
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						mov_rot_right(MED, FAR);
//						OVERRIDE=1;
//
//						Cat_Avoider();
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//					}
//
////					if(OVERRIDE==1){break;}
//
//					if (OVERRIDE==0)
//					{
//						Cat_Avoider();
//						Evade_Wall();
//						YUME_Tracer_Check();
//
//						curve_left_new(FAST_LEVEL_3, FAR, &PID_F_L.pid_value[0]);
//
//						if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//						if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//					}
//
//					YUME_Tracer_Check();
//					Cat_Avoider();
//					if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//					if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//				}
//
//			YUME_Tracer_Check();
//			Cat_Avoider();
//			OVERRIDE=0;
//		}
//		OVERRIDE=0;
//		if(CAT_SHIFT_FOLLOW==SHIFT_FOLLOW) break;
//		if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//
//	}
//	OVERRIDE=0;
//}
//
//void YUME_Action_A(void)
//{
//	Sendto_PC(USART1,"YUME Hexapod Search Fire Sequences \r");
//
//	static int right=90,left=90;
//
//	generate_movement_data(0,0,10);
//	delay_ms(50);
//
//	while(right>=20&&left<=160&&UV_state==0)
//	{
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(20);
//		right-=5;
//		left+=5;
//		if(UV_state==1) break;
//	}
//	delay_ms(100);
//
//	while(right<=90&&left>=90&&UV_state==0)
//	{
//	    inv_kine(front_left,left,7,leg);
//	    inv_kine(front_right,right,7,leg);
//	    inv_kine(middle_left,left,7,leg);
//	    inv_kine(middle_right,right,7,leg);
//	    inv_kine(rear_left,left,7,leg);
//	    inv_kine(rear_right,right,7,leg);
//	    delay_ms(20);
//	    right+=5;
//	    left-=5;
//	    if(UV_state==1) break;
//	}
//	delay_ms(100);
//
//	while(right<=160&&left>=20&&UV_state==0)
//	{
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(20);
//		right+=5;
//		left-=5;
//		if(UV_state==1) break;
//	}
//	delay_ms(100);
//
//	while(right>=90&&left<=90&&UV_state==0)
//	{
//		inv_kine(front_left,left,7,leg);
//		inv_kine(front_right,right,7,leg);
//		inv_kine(middle_left,left,7,leg);
//		inv_kine(middle_right,right,7,leg);
//		inv_kine(rear_left,left,7,leg);
//		inv_kine(rear_right,right,7,leg);
//		delay_ms(20);
//		right-=5;
//		left+=5;
//		if(UV_state==1) break;
//	}
//	delay_ms(100);
//
//
//
//
//}
//
//void YUME_TRIAL_A(void)
//{
//	YUME_Buzz(2);
//	Sendto_PC(USART1,"\r YUME READY TO FIGHT!!! \r");
//	Sendto_PC(USART1,"YUME RED FIGHTER! \r");
//
//	YUME_LOCATION[LAST_LOC]=LOCATION_CORRIDOR;
//	YUME_LOCATION[PRESENT_LOC]=LOCATION_CORRIDOR;
//	ZONE=ZONE_RED;
//	INITIAL_ZONE=ZONE_RED;
//
//	Home_Detection_Red();
//
////	YUME_Buzz(4);
//	Escape_Home();
//	Evade_Wall();
//
////	YUME_Buzz(1);
////	Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL BLACK FLOOR DETECTED \r");
////	YUME_PID_Init();
////	FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
////	FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
////
//	Cat_Avoider();
//	YUME_PID_Init();
//
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		CAT_SHIFT_FOLLOW=0;
//		Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//		YUME_PID_Init();
//		follow_right_new();
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//	}
////	YUME_Buzz(3);
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//		YUME_Buzz(4);
//		ROOM_COUNTER++;
//		while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//			YUME_ROOM();
//			if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//		}
//
//	}
//	RETURN_TRIP_FLAG=RETURN_ENABLED;
//
//
//
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		YUME_Buzz(4);
//		Get_IR();
//		while(  ( (Ping[PING_FRONT]<=30)   || (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED) )==1
//			 )
//		{
//			Get_IR();
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//		}
//		mov_fwd_5cm(15,FAST_LEVEL_3);
//
//		YUME_Buzz(4);
//		while(RETURN_TRIP_FLAG==RETURN_ENABLED)
//		{
//			YUME_PID_Init();
//			followhome_left();
//			if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//		}
//
//		mov_fwd_5cm(15,MED);
//		YUME_Buzz(4);
//		while(1)
//		{
//			YUME_Celebrate();
////			mov_static();
////			YUME_Buzz(2);
//		}
//
//	}
//
//
//
//
//}
//
//void YUME_TRIAL_B(void)
//{
//	YUME_Buzz(2);
//	Sendto_PC(USART1,"\r YUME READY TO FIGHT!!! \r");
//	Sendto_PC(USART1,"YUME RED FIGHTER! \r");
//	Sendto_PC(USART1,"\r YUME ARBITRARY START! \r");
//
//	YUME_LOCATION[LAST_LOC]=LOCATION_CORRIDOR;
//	YUME_LOCATION[PRESENT_LOC]=LOCATION_ROOM;
//	ZONE=ZONE_BLUE;
//	INITIAL_ZONE=ZONE_BLUE;
//
//	YUME_Buzz(3);
//
//	Home_Detection_Red();
//
//	YUME_Buzz(1);
//	Escape_Home();
//	Evade_Wall();
//
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		YUME_PID_Init();
//		FollowExit_Right();
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		YUME_Buzz(1);
//		Get_IR();
//		while(  ( (Ping[PING_FRONT]<=30)   ||
////			     INFRARED[IR_FRONT_LEFT]  ||
////			     INFRARED[IR_FRONT_RIGHT] ||
//			     (INFRARED[IR_FRONT_MIDDLE]==IR_DETECTED)
//			     )==1
//			  )
//		{
//			Get_IR();
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//			mov_rot_left(MED,FAR);
//		}
//
//		follow_right_counter(22);
//
//		YUME_Buzz(1);
//		Evade_Wall();
//		Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL RED CARPET DETECTED \r");
//		YUME_PID_Init();
//		FollowCarpet_Right(&COLOUR_GRAY,&INVERSE);
//		FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//		YUME_Buzz(1);
//		Evade_Wall();
//		Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL RED CARPET DETECTED \r");
//		YUME_PID_Init();
//		FollowCarpet_Right(&COLOUR_BLACK,&INVERSE);
//		FOLLOW_CARPET_FLAG=FOLLOW_CARPET_DISABLED;
//
//		YUME_Buzz(1);
//		Evade_Wall();
//		CAT_SHIFT_FOLLOW=NO_SHIFT;
//		while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//		{
//			YUME_PID_Init();
//			followtracer_left();
//			if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//		}
//
//	}
//
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//		YUME_Buzz(4);
//		ROOM_COUNTER++;
//		while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//			YUME_ROOM();
//			if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//		}
//
//	}
//
//
//	YUME_Buzz(1);
//
//	mov_rot_right(MED,FAR);
//	mov_rot_right(MED,FAR);
//	mov_rot_right(MED,FAR);
//	mov_rot_right(MED,FAR);
//	mov_rot_right(MED,FAR);
//	mov_rot_right(MED,FAR);
//	mov_rot_right(MED,FAR);
//
//	Evade_Wall();
//	mov_fwd_5cm(15,FAST_LEVEL_3);
//
//	RETURN_TRIP_FLAG=RETURN_ENABLED;
//	YUME_Buzz(1);
//	Evade_Wall();
//	while(RETURN_TRIP_FLAG==RETURN_ENABLED)
//	{
//		YUME_PID_Init();
//		followhome_left();
//		if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//	}
//
//	mov_fwd_5cm(10,MED);
//	YUME_Buzz(4);
//	while(1)
//	{
//		YUME_Celebrate();
//	}
//
////	YUME_Buzz(4);
////	Evade_Wall();
////	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
////	{
////		YUME_PID_Init();
////		followtracer_left();
////		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
////	}
////
////	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
////	{
////
////	}
//
//}
//
//void YUME_TRIAL_C (void)
//{
//	YUME_Buzz(2);
//	Sendto_PC(USART1,"\r YUME READY TO FIGHT!!! \r");
//	Sendto_PC(USART1,"YUME RED FIGHTER! \r");
//	Sendto_PC(USART1,"\r YUME ARBITRARY START! \r");
//
//	YUME_LOCATION[LAST_LOC]=LOCATION_CORRIDOR;
//	YUME_LOCATION[PRESENT_LOC]=LOCATION_ROOM;
//	ZONE=ZONE_BLUE;
//	INITIAL_ZONE=ZONE_BLUE;
//
//	YUME_Buzz(3);
//
//	Home_Detection_Red();
//
//	YUME_Buzz(1);
//	Escape_Home();
//	Evade_Wall();
//
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		YUME_PID_Init();
//		FollowExit_Right();
//		if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//	}
//
//	YUME_Buzz(2);
//	while(YUME_LOCATION[PRESENT_LOC]==LOCATION_CORRIDOR)
//	{
//		CAT_SHIFT_FOLLOW=0;
//		Sendto_PC(USART1,"\rYUME FOLLOW RIGHT UNTIL TRACER DETECTED\r");
//		YUME_PID_Init();
//		follow_right_new();
//		if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM) break;
//	}
//
//	YUME_Buzz(2);
//	if(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//	{
//		Sendto_PC(USART1,"YUME SWITCH LOCATION TO: ROOM \r");
//		YUME_Buzz(4);
//		ROOM_COUNTER++;
//		while(YUME_LOCATION[PRESENT_LOC]==LOCATION_ROOM)
//		{
//			Sendto_PC(USART1,"\r YUME ROOM COUNTER: %d ===\r",ROOM_COUNTER);
//			YUME_ROOM();
//			if(YUME_LOCATION[PRESENT_LOC]== LOCATION_CORRIDOR) break;
//		}
//
//	}
//
//	RETURN_TRIP_FLAG=RETURN_ENABLED;
//	YUME_Buzz(2);
//	Evade_Wall();
//	while(RETURN_TRIP_FLAG==RETURN_ENABLED)
//	{
//		YUME_PID_Init();
//		followhome_left();
//		if(RETURN_TRIP_FLAG==RETURN_SUCCESS)break;
//	}
//
//	mov_fwd_5cm(10,MED);
//	YUME_Buzz(4);
//	while(1)
//	{
//		YUME_Celebrate();
//	}
//
//
//}
