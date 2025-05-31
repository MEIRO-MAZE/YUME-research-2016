///*==============================================================================================
//								  	  PROJECT YUME Ver.1.0
//								 YUME ALGORITHM LIBRARY
//==============================================================================================*/
//
//#ifndef YUME_ALGORITHM_H
//#define YUME_ALGORITHM_H
//
//#include "main.h"
//
//extern unsigned int Ping[9];
//extern unsigned int usart_count;
//
////YUME TPA81 STATE VARIABLES
//extern unsigned int FIRE;
//
////YUME UV-TRON STATE VARIABLES
//extern unsigned int UV_state;
//extern unsigned int UV_Lock;
//
//// YUME ZONE VARIABLES
//#define RED_ZONE 2
//#define BLUE_ZONE 3
//
//extern unsigned int INITIAL_ZONE;
//extern unsigned int ZONE;
//
//extern unsigned int ZONE_BLACK;
//extern unsigned int ZONE_RED;
//extern unsigned int ZONE_BLUE;
//extern unsigned int TRACER;
//
////YUME START MODE VARIABLES
//
//extern unsigned int START_MODE;
//
//
//extern int F_TRACER;
//extern int M_TRACER;
//extern int TRACER_FLAG;
//extern unsigned int CANDLE_CIRCLE_FLAG;
//extern unsigned int CANDLE_CIRCLE_DETECTED;
//extern unsigned int EXTINGUISHED_FIRE;
//
////TCS3200 MODE
//#define FRONT_TCS3200_MODE 1
//#define MID_TCS3200_MODE   2
//extern unsigned int FRONT_TCS3200;
//extern unsigned int MID_TCS3200;
//extern unsigned int CROSS_MODE;
//
////YUME CROSSING ZONE MODE
//extern unsigned int YUME_CROSS_MODE;
//#define CROSS_OFF 0
//#define CROSS_ON 1
//
//
////YUME ALGORITHM FUNCTION PROTOTYPE
//
//void YUME_Dimension_Check(void);
//
//void YUME_Home_Detection(void);
//void Home_Detection_Red(void);
//void Home_Detection_Blue(void);
//void Cat_Avoider(void);
//
//void Zone_Check(unsigned int *INITIAL_ZONE);
//
//void Evade_Wall(void);
//
//
///*
// *  YUME FIGHTER MODE
// */
//void RedFighter_Non_Arbitrary(void);
//void RedFighter_Arbitrary(void);
//void BlueFighter_Non_Arbitrary(void);
//void BlueFighter_Arbitrary(void);
//
//
///*
// * YUME SEND LOCATION
// */
//void Send_Location (void);
//
//void Mov_Fwd_Trace (int distance, int SPEED);
//
//void YUME_Success(void);
//
//void mov_curve_left_trace(int SPEED, int STEP);
//void mov_curve_right_trace(int SPEED, int STEP);
//
///*
// *  YUME RETURN TO ROOM
// */
//void ReturnTo_Room(void);
//
///*
// *  YUME EXIT NO FIRE
// */
//void Exit_No_Fire(void);
//
///*
// *  YUME PID WALL FOLLOWING UNTIL TRACER NEW ALGORITHM
// */
//void follow_right_new(void);
//void PID_follow_right_new(void);
//void curve_left_new(int SPEED, int STEP, float *COMMAND_LOOP);
//void curve_right_new(int SPEED, int STEP, float *COMMAND_LOOP);
//
//
//
////YUME FOLLOW RIGHT UNTIL DETECT TRACER
//void follow_tracer_right(void);
//void PID_follow_tracer_right(void);
//void folltracer_curve_right(int SPEED, int STEP, float *COMMAND_LOOP);
//void folltracer_curve_left(int SPEED, int STEP, float *COMMAND_LOOP);
//
///*
// *  YUME FOLLOW FIRE
// */
//
//
////OBSOLETE ALGORITHM (PID VALUE MANIPULATES HOW MANY STEP WILL BE EXECUTED)
//void PID_follow_fire_right(void);
//void SearchFire_curve_left(int SPEED, int STEP, float *COMMAND_LOOP);
//void SearchFire_curve_right(int SPEED, int STEP, float *COMMAND_LOOP);
//void mov_curve_left_fire(int SPEED, int STEP);
//void mov_curve_right_fire(int SPEED, int STEP);
//void PID_follow_fire_left(void);
//void YUME_FireTracker(void);
//
////NEW ALGORITHM (PID VALUE MANIPULATES INVERSE KINEMATICS THETA VALUE)
//void followfire_right_new(void);
//void PID_followfire_right_new(void);
//void followfire_left_new(void);
//void PID_followfire_left_new(void);
//void curve_left_fire_new(int SPEED, int STEP, float *COMMAND_LOOP);
//void curve_right_fire_new(int SPEED, int STEP, float *COMMAND_LOOP);
//void mov_rotright_fire(int SPEED, int STEP);
//void mov_rotleft_fire(int SPEED, int STEP);
//
///*
// * YUME IN ROOM ROUTINES
// */
//void YUME_ROOM(void);
//
///*
// *  YUME FOUND FIRE PROTOTYPE
// */
//void YUME_Found_Fire(void);
//
///*
// *  YUME SEARCH FIRE SEQUENCES
// */
//void YUME_Search_Fire(void);
//
///*
// * YUME EXIT NO FIRE
// */
//void Exit_No_Fire_Blue(void);
//void Exit_No_Fire_Red(void);
//
//
///*
// *  YUME FOLLOW COUNTER RIGHT RULE
// */
//void follow_right_counter(int limit);
//void PID_follow_right_counter(void);
//void curve_right_counter(int SPEED, int STEP, float *COMMAND_LOOP);
//void curve_left_counter(int SPEED, int STEP, float *COMMAND_LOOP);
//
//void follow_left_counter(int limit);
//void PID_follow_left_counter(void);
//
///*
// *  YUME FOLLOW EXIT RIGHT RULE
// */
//void FollowExit_Right(void);
//void PID_FollowExit_Right(void);
//
//void FollowExit_Left(void);
//void PID_FollowExit_Left(void);
//
//
///*
// * YUME FOLLOW IN ROOM (USED IN FOLLOW EXIT RIGHT RULE
// */
//void curve_right_room(int SPEED, int STEP, float *COMMAND_LOOP);
//void curve_left_room(int SPEED, int STEP, float *COMMAND_LOOP);
//
//
///*
// * YUME FOLLOW CARPET FUNCTION PROTOTYPE
// */
//void FollowCarpet_Right(unsigned int *CARPET, unsigned int *INV_STAT);
//void PID_FollowCarpet_Right(unsigned int *CARPET, unsigned int *INV_STAT);
//
//void FollowCarpet_Left(unsigned int *CARPET, unsigned int *INV_STAT);
//void PID_FollowCarpet_Left(unsigned int *CARPET, unsigned int *INV_STAT);
//
///*
// * YUME FOLLOW TRACER LEFT RULE
// */
//void followtracer_left(void);
//void PID_followtracer_left(void);
//
//
///*
// * YUME ESCAPE WARZONE
// */
//void Escape_Warzone(void);
//
///*
// * YUME RETTURN TO ZONE
// */
//void ReturnTo_Zone(void);
//
///*
// *  YUME SEND LOCATION ROUTINES
// */
//void Send_TCS3200_Status(void);
//
///*
// *  YUME FOLLOW EVADE HOME CIRCLE
// */
//void FollowEvade_HomeCircle_Right(int limit);
//void PID_FollowEvade_HomeCircle_Right(void);
//void FollowEvade_HomeCircle_Left(int limit);
//void PID_FollowEvade_HomeCircle_Left(void);
//void curve_right_evade(int SPEED, int STEP, float *COMMAND_LOOP);
//void curve_left_evade(int SPEED, int STEP, float *COMMAND_LOOP);
//
//
///*
// * YUME CROSSING BORDERLINE ROUTINES
// */
//void FollowCrossing_Right(void);
//void PID_FollowCrossing_Right(void);
//
//void FollowCrossing_Left(void);
//void PID_FollowCrossing_Left(void);
//
//void YUME_CrossingTo_RedZone(void);
//void YUME_CrossingTo_BlueZone(void);
//void ReturnTo_BlueZone(void);
//void ReturnTo_RedZone(void);
//void ReturnTo_BlueWarzone(void);
//void ReturnTo_RedWarzone(void);
//
//
///*
// * YUME ENEMY TERITORY
// */
//void YUME_FireFight_EnemyBlue(void);
//void YUME_FireFight_EnemyRed(void);
//void YUME_ENEMY_ROOM_RED(void);
//void YUME_ENEMY_ROOM_BLUE(void);
//
//
////YUME ROOM AND CORRIDOR VARIABLES
//extern unsigned int YUME_LOCATION[];
//extern unsigned int LOCATION_CORRIDOR;
//extern unsigned int LOCATION_ROOM;
//#define PRESENT_LOC 0
//#define LAST_LOC 1
//
////UV TRON CONDITION
//#define FIRE_DETECTED 0
//#define NO_FIRE 1
//
//
////INFRARED PROXIMITY VARIABLES
//extern int INFRARED[];
//#define MID_LEFT 2
//#define MID_RIGHT 3
//#define IR_FRONT_LEFT    0
//#define IR_FRONT_RIGHT   1
//#define IR_MID_LEFT      2
//#define IR_MID_RIGHT     3
//#define IR_FRONT_MIDDLE  4
//#define IR_FRONT_SUB     5
//
//
////YUME FIRE FIGHTING FLAG
//extern unsigned int FIRE_PUTOFF;
//
//extern unsigned int COLOUR_BLACK;
//extern unsigned int COLOUR_WHITE;
//extern unsigned int COLOUR_RED;
//extern unsigned int COLOUR_BLUE;
//
//extern unsigned int COLOUR_STAT;
//
//extern unsigned int ZONE;
//extern unsigned int ZONE_RED;
//extern unsigned int ZONE_BLUE;
//
//
///*
// * YUME FOLLOW CARPET VARIABLES
// */
//extern unsigned int NORMAL;
//extern unsigned int INVERSE;
//
///*
// * YUME CAT OBSTACLE VARIABLES
// */
//extern unsigned int CAT_FOUND[];
//#define CAT_PREVIOUS 1
//#define CAT_PRESENT  0
//extern unsigned int CAT_SHIFT_FOLLOW;
//extern unsigned int SHIFT_FOLLOW;
//extern unsigned int NO_SHIFT;
//
///*
// * YUME ROOM COUNTER
// */
//extern unsigned int ROOM_COUNTER;
//
///*
// * YUME WARZONE FLAG
// */
//extern unsigned int WARZONE_FLAG;
//
///*
// * YUME HOME CIRCLE FLAG
// */
//extern unsigned int HOME_CIRCLE_FLAG;
//unsigned int HOME_CIRCLE_DETECTED;
//
///*
// *  YUME LED COUNTER
// */
//extern uint16_t led_off_counter;
//
///*
// * YUME FIRETRACK COUNTER
// */
//extern unsigned int firetrack_counter;
//
///*
// * YUME FOUND FIRE OVERRIDE
// */
//extern unsigned int YUME_FOUND_FIRE_OVERRIDE;
//
///*
// *  YUME EXTINGUISHER FLAG
// */
//extern unsigned int EXTINGUISHER_FLAG;
//
///*
// * YUME ROOM 1 FLAG
// */
//extern unsigned int ROOM1_FLAG;
//
///*
// *  YUME WARZONE COUNTER
// */
//extern unsigned int WARZONE_COUNTER;
//
///*
// * YUME GLOBAL COUNTER
// */
//extern unsigned int global_counter;
//
///*
// * YUME CROSS_ZONE VARIABLES
// */
//extern unsigned int YUME_CROSSING_AUTHORITY;
//extern unsigned int CROSS_DISABLED;
//extern unsigned int CROSS_ENABLED;
//extern unsigned int YUME_CROSSING_STATUS;
//extern unsigned int NO_CROSSING;
//extern unsigned int CROSSING_SUCCESS;
//extern unsigned int CROSSING_FAILED;
//
///*
// *  YUME STEAL ENEMY FIRE VARIABLES
// */
//extern unsigned int STEAL_FIRE_STAT;
//extern unsigned int STEAL_FIRE_COUNTER;
//extern unsigned int STEALFIRE_SUCCESS;
//extern unsigned int STEALFIRE_FAILED;
//extern unsigned int ENEMY_ZONE_STAT;
//extern unsigned int ENEMY_ZONE;
//extern unsigned int COMFORT_ZONE;
//
///*
// * YUME SPECIAL CONDITION FLAG
// */
//extern unsigned int SPECIAL_CONDITION_FLAG;
//extern unsigned int SPECIAL_CONDITION_ENABLED;
//extern unsigned int SPECIAL_CONDITION_DISABLED;
//extern unsigned int SPECIAL_CONDITION_COUNTER;
///*
// * YUME ROOM FLAG
// */
//extern unsigned int ROOM_FLAG[];
//extern unsigned int PRESENT_ROOM;
//extern unsigned int PREVIOUS_ROOM;
//extern unsigned int OTHER_ROOM;
//extern unsigned int ROOM_ONE;
//extern unsigned int WARZONE;
//
///*
// * YUME VARIABLE DOOR
// */
//extern unsigned int VARIABLE_DOOR;
//extern unsigned int VAR_DOOR_NOT_DETECTED;
//extern unsigned int VAR_DOOR_DETECTED;
//extern unsigned int VAR_DOOR_SCAN;
//
///*
// * FIRST CAT ENCOUNTER
// */
//extern unsigned int FIRST_CAT_ENCOUNTER;
//extern unsigned int CAT_NOT_DETECTED;
//extern unsigned int CAT_DETECTED;
//
///*
// * RETURN COUNTER
// */
//extern unsigned int RETURN_COUNTER;
//
///*
// * FOLLOW CARPET FLAG
// */
//extern unsigned int FOLLOW_CARPET_FLAG;
//extern unsigned int FOLLOW_CARPET_ENABLED;
//extern unsigned int FOLLOW_CARPET_DISABLED;
//extern unsigned int FOLLOW_CARPET_ESCAPE_TRAP;
//
///*
// * RETURN FLAG
// */
//extern unsigned int RETURN_FLAG;
//extern unsigned int RETURN_ENABLED;
//extern unsigned int RETURN_DISABLED;
//
///*
// * RETURN TRIP FLAG
// */
//extern unsigned int RETURN_TRIP_FLAG;
//#define RETURN_DISABLED 0
//#define RETURN_ENABLED  1
//#define RETURN_SUCCESS  2
//#endif
