/*==============================================================================================
								   PROJECT YUME 2016 Ver.1.0
								     YUME ALGORITHM LIBRARY
===============================================================================================*/



#ifndef YUME2016_ALGORITHM_H
#define YUME2016_ALGORITHM_H

#include "main.h"

/*==============================================================================================
							LEGACY FEATURES FROM YUME Ver.1.0
===============================================================================================*/

/*
 * YUME FOLLOW CARPET COMMAND CODE
 */
#define NORMAL 	1
#define INVERSE 2


/*
 * YUME FLAME FOLLOWER VARIABLES
 */
extern unsigned int FlameSense[2];
extern unsigned int FollowFlame_Flag;
extern unsigned int FlameTrack_Flag;
extern unsigned int FlameScan_Flag;
extern unsigned int FlameExtinguish_Flag;
extern unsigned int FlameApproach_Flag;

#define FLAG_INACTIVE 0
#define FLAG_ACTIVE   1


/*
 * YUME PING))) RECEIVER VARIABLES
 */
extern unsigned int Ping[9];
extern unsigned int usart_count;

//YUME UV-TRON STATE VARIABLES
extern unsigned int UV_state;
extern unsigned int UV_Lock;

//YUME ROOM AND CORRIDOR VARIABLES
extern unsigned int YUME_LOCATION[];
extern unsigned int LOCATION_CORRIDOR;
extern unsigned int LOCATION_ROOM;
#define PRESENT_LOC 0
#define LAST_LOC 1

//UV TRON CONDITION
extern unsigned int FIRE;
#define FIRE_DETECTED 0
#define NO_FIRE 1

//ADDITIONAL FLAME SENSOR
extern unsigned int FLAME_SIDE;

//INFRARED PROXIMITY VARIABLES
extern int INFRARED[];
//#define MID_LEFT 2
//#define MID_RIGHT 3
//#define IR_FRONT_LEFT    0
//#define IR_FRONT_RIGHT   1
//#define IR_MID_LEFT      2
//#define IR_MID_RIGHT     3
//#define IR_FRONT_SUB     5

/*
 *  YUME BUMPER VARIABLES;
 */
extern unsigned int BUMPER[];

/*
 * YUME FOLLOW CARPET VARIABLES
 */
//extern unsigned int NORMAL;
//extern unsigned int INVERSE;
#define NORMAL 1
#define INVERSE 2

/*
 * YUME CAT OBSTACLE VARIABLES
 */
extern unsigned int CAT_FOUND[];
#define CAT_PREVIOUS 1
#define CAT_PRESENT  0
extern unsigned int CAT_SHIFT_FOLLOW;
extern unsigned int SHIFT_FOLLOW;
extern unsigned int NO_SHIFT;

extern unsigned int CAT_FLAG;
extern unsigned int CAT_DETECTED;
extern unsigned int CAT_NOT_DETECTED;

/*
 * YUME ROOM COUNTER
 */
extern unsigned int ROOM_COUNTER;

/*
 * YUME WARZONE FLAG
 */
extern unsigned int WARZONE_FLAG;
extern unsigned int SPECIAL_ZONE_FLAG;

/*
 * YUME HOME CIRCLE FLAG
 */
extern unsigned int HOME_CIRCLE_FLAG;
extern unsigned int HOME_CIRCLE_DETECTED;
extern unsigned int HOME_CIRCLE_NOT_DETECTED;

/*
 * YUME FOLLOWHOME FLAG
 */
extern unsigned int FOLLOWHOME_FLAG;
extern unsigned int FOLLOWHOME_INACTIVE;
extern unsigned int FOLLOWHOME_ACTIVE;

/*
 * YUME CAT OBSTACLE VARIABLES
 */
extern unsigned int CAT_FOUND[];
#define CAT_PREVIOUS 1
#define CAT_PRESENT  0
extern unsigned int CAT_SHIFT_FOLLOW;
extern unsigned int SHIFT_FOLLOW;
extern unsigned int NO_SHIFT;

/*
 * FIRST CAT ENCOUNTER
 */
extern unsigned int FIRST_CAT_ENCOUNTER;
extern unsigned int CAT_NOT_DETECTED;
extern unsigned int CAT_DETECTED;

//NEW COMMAND DATA
extern unsigned int TCS_CMD_SEND_FRONT;
extern unsigned int TCS_CMD_SEND_MIDDLE;
extern unsigned int TCS_CMD_SEND_CONCLUSION;
extern unsigned int TCS_CMD_SAVE_EEPROM;
extern unsigned int TCS_CMD_SHOW_EEPROM;

//CARPET CODE
extern unsigned int COLOUR_NONE;
extern unsigned int COLOUR_BLACK;
extern unsigned int COLOUR_GRAY;
extern unsigned int COLOUR_WHITE;
extern unsigned int COLOUR_RED;
extern unsigned int COLOUR_BLUE;

/*
 * RETURN COUNTER
 */
extern unsigned int RETURN_COUNTER;

/*
 * YUME VARIABLE DOOR
 */
extern unsigned int VARIABLE_DOOR;
extern unsigned int VAR_DOOR_NOT_DETECTED;
extern unsigned int VAR_DOOR_DETECTED;
extern unsigned int VAR_DOOR_SCAN;





/*
 * TRACER DETECTED IN BUMPER HANDLER ROUTINES
 */

extern unsigned int TRACER_IN_BUMPER;
extern unsigned int TRC_BMP_ACTIVE;
extern unsigned int TRC_BMP_INACTIVE;

/*
 * TRACER STATUS VARIABLES
 */
extern unsigned int TRACER_STAT;
extern unsigned int TRACER_ACTIVE;
extern unsigned int TRACER_INACTIVE;


/*
 *	NAVIGATION MACRO
 */
#define NAV_HALLWAY_SC 	0
#define NAV_ROOM_1A		1
#define NAV_ROOM_1B		2
#define NAV_ROOM_1C		3
#define NAV_ROOM_2A		4
#define NAV_ROOM_2B		5
#define NAV_ROOM_3		6
#define NAV_ROOM_4A		7
#define NAV_ROOM_4B		8

/*
 * ROOM IDENTIFIER VARIABLES
 */
extern unsigned int HOME;

extern unsigned int ROOM[];

extern unsigned int ROOM_1A;
extern unsigned int ROOM_1B;
extern unsigned int ROOM_1C;

extern unsigned int ROOM_2A;
extern unsigned int ROOM_2B;

extern unsigned int ROOM_3;

extern unsigned int ROOM_4A;
extern unsigned int ROOM_4B;

extern unsigned int HALLWAY_SC;

extern unsigned int ROOM_TYPE;
extern unsigned int NORMAL_ROOM;
extern unsigned int GRAY_ROOM;


/*
 * YUME FIRE FIGHTING VARIABLES
 */
extern unsigned int EXTINGUISHED_FIRE;
extern unsigned int FIRE_PUTOFF;


extern unsigned int FLAME_SENSOR[];

/*
 *  YUME ROOM COUNTER
 */
extern unsigned int ROOM_COUNTER;


//PRE-TRIAL FUNCTIONS
void YUME_Dimension_Check(void);

/*
 *  YUME RETURN TO ROOM
 */
void ReturnTo_Room(void);

/*
 *  YUME EXIT NO FIRE
 */
void Exit_No_Fire(void);


/*
 * YUME EVADE WALL
 */
void Evade_Wall(void);


void YUME_Home_Detection(void);
void Escape_Home(void);
void Home_HallwaySC_Detector(void);
void RoomTypeDetector(void);



/*
 *  YUME PID WALL FOLLOWING UNTIL TRACER NEW ALGORITHM
 */
void follow_right_new(void);
void PID_follow_right_new(void);
void curve_left_new(int SPEED, int STEP, float *COMMAND_LOOP);
void curve_right_new(int SPEED, int STEP, float *COMMAND_LOOP);

/*
 *  YUME FOLLOW COUNTER RIGHT RULE
 */
void follow_right_counter(int limit);
void PID_follow_right_counter(void);
void curve_right_counter(int SPEED, int STEP, float *COMMAND_LOOP);
void curve_left_counter(int SPEED, int STEP, float *COMMAND_LOOP);

void follow_left_counter(int limit);
void PID_follow_left_counter(void);



void FlameSense_PID_Init(void);
void FlameSense_PID_Calc(void);
void FlameTracking(void);
void PID_FlameTracking(void);
void Rot_Right_PID(int SPEED, int STEP, float *COMMAND_LOOP);
void Rot_Left_PID(int SPEED, int STEP, float *COMMAND_LOOP);

void YUME_FlameSense(void);
void YUME_FlameScanning(void);
void YUME_FlameExtinguish(int PRESENT_LEFT, int PRESENT_RIGHT);

void FollowFlame_Left(void);
void PID_FollowFlame_Left(void);
void CurveRight_FlameSense(int SPEED, int STEP, float *COMMAND_LOOP);
void CurveLeft_FlameSense(int SPEED, int STEP, float *COMMAND_LOOP);

void YUME_FireFollow(void);
int FollowFlame_Left_New(void);
void PID_FollowFlame_Left_New(void);
void CurveRight_FlameSense_New(int SPEED, int STEP, float *COMMAND_LOOP);
void CurveLeft_FlameSense_New(int SPEED, int STEP, float *COMMAND_LOOP);


void YUME_CandleScanExecute(void);

/*
 * NEW ALGORITHM
 */

int FlameTracking_New(void);
int PID_FlameTracking_New(void);

int FlameApproach(void);
int PID_FlameApproach(void);
void CurveRight_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP);
void CurveLeft_FlameApproach(int SPEED, int STEP, float *COMMAND_LOOP);

void RotRight_Angle(void);
void RotLeft_Angle(void);


/*
 *  YUME FOLLOWTRACER
 */
void FollowTracer_Right(void);
void PID_FollowTracer_Right(void);

void FollowTracer_Left();
void PID_FollowTracer_Left(void);

/*
 * YUME FOLLOW CARPET
 */
void FollowCarpet_Right(int CARPET_CODE, int FOLLOW_MODE);
void PID_FollowCarpet_Right(void);

void PID_FollowCarpet_Left(void);
void FollowCarpet_Left(int CARPET_CODE, int FOLLOW_MODE);

/*
 *  YUME FOLLOW HOME
 */
void PID_FollowHome_Right(void);
void PID_FollowHome_Left(void);


/*
 * YUME NAVIGATION FUNCTION PROTOTYPE
 */
void YUME_Navi(int STARTING_POINT, int DESTINATION);

//STARTING POINT = HALLWAY SC
void Nav_HallwaySC_To_3(void);
void Nav_HallwaySC_To_2(void);
void Nav_HallwaySC_To_4B(void);
void Nav_HallwaySC_To_4A(void);
void Nav_HallwaySC_To_1A(int OPTION);
void Nav_HallwaySC_To_1B(void);

//STARTING POINT = 1A
void Nav_1A_To_HallwaySC(void);
void Nav_1A_To_2(void);
void Nav_1A_To_3(void);
void Nav_1A_To_4B(void);
void Nav_1A_To_4A(void);

//STARTING POINT = 1B
void Nav_1B_To_2(void);

//STARTING POINT = 1C
void Nav_1C_To_HallwaySC(void);
void Nav_1C_To_2(void);
void Nav_1C_To_3(void);
void Nav_1C_To_4A(void);
void Nav_1C_To_4B(void);

//STARTING POINT = 2
void Nav_2_To_HallwaySC(void);
void Nav_2B_To_1BC(void);
void Nav_2_To_1A(void);
void Nav_2_To_1BC(void);
void Nav_2_To_3(void);
void Nav_2_To_4A(void);
void Nav_2_To_4B(void);

//STARTING POINT = 3
void Nav_3_To_HallwaySC(void);
void Nav_2A_To_1BC(void);
void Nav_3_To_1A(void);
void Nav_3_To_1BC(void);
void Nav_3_To_2(void);
void Nav_3_To_4A(void);
void Nav_3_To_4B(void);


//STARTING POINT = 4A
void Nav_4A_To_HallwaySC(void);
void Nav_4A_To_3(void);
void Nav_4A_To_1A(void);
void Nav_4A_To_2(void);

//STARTING POINT = 4B
void Nav_4B_To_HallwaySC(void);
void Nav_4B_To_1A(void);
void Nav_4B_To_1BC(void);
void Nav_4B_To_2(void);
void Nav_4B_To_3(void);


//TCS3200 SLAVE STATUS CHECK
void TCSlave_Check(void);

void Stabilize_After_Exit(void);
void YUME_Room(void);
void YUME_Strategy(void);
int YUME_ReturnTrip(void);


void RoomType_Init(void);

void YUME_FlameCheck(void);

void HomeCircle_Detector(void);
void YUME_FireFight_Ver2(void);

void UVLock_Refresh(void);
void FireFight_CandleStickDetector(void);
void FireFight_CandleFireDetector(void);

void YUME_FlameDemo(void);

/*
 *  YUME CANDLE TRACKER VARIABLES;
 */
extern unsigned int CANDLE_STAT;
extern unsigned int CANDLE_STICK;
extern unsigned int CANDLE_FIRE;
extern unsigned int CANDLE_STAT;


/*
 *  ROOM 2 FLAG
 */

extern unsigned int ROOM1_FLAG;
extern unsigned int ROOM1FLAG_ACTIVE;
extern unsigned int ROOM1FLAG_INACTIVE;

/*
 * ROOM 4A FLAG
 */
extern unsigned int ROOM4A_FLAG;
extern unsigned int ROOM4AFLAG_ACTIVE;
extern unsigned int ROOM4AFLAG_INACTIVE;

/*
 * ROOM1A SPECIAL EXIT FLAG
 */
extern unsigned int ROOM1A_SP_EXIT_FLAG;
extern unsigned int ROOM1A_SP_EXIT_FLAG_ACTIVE;
extern unsigned int ROOM1A_SP_EXIT_FLAG_INACTIVE;


/*
 * ROOM4A CAT AVOIDER
 */
extern unsigned int ROOM4A_CAT_AVOIDER;
extern unsigned int ROOM4A_CAT_AVOIDER_ACTIVE;
extern unsigned int ROOM4A_CAT_AVOIDER_INACTIVE;


/*
 * CAT SHIFT ALGORITHM FLAG
 */
extern unsigned int SHIFT_ALGORITHM_FLAG;
extern unsigned int SHIFT_ALGORITHM_ACTIVE;
extern unsigned int SHIFT_ALGORITHM_INACTIVE;

/*
 *  DEFLECT WALL OVERFLOW COUNTER
 */
extern int RIGHT_OVERFLOW_COUNTER;
extern int LEFT_OVERFLOW_COUNTER;

/*
 * SPECIAL ROUTE FOR RETURN TRIP R2 TO R4A
 * HOME: R4A
 * FIRE ROOM: R2
 * CAT CONFIG: A
 */
extern unsigned int R2TO4A_SP_ROUTE;
extern unsigned int R2TO4A_SP_ACTIVE;
extern unsigned int R2TO4A_SP_INACTIVE;


/*
 *  YUME TURNAROUND NAVIGATION
 */
extern unsigned int TURN_LEFT;
extern unsigned int TURN_RIGHT;


//SHARP IR RANGEFINDER
extern unsigned int SHARP[];

#endif

