
#include "yume_global_var.h"

/*
 * YUME TCS3200 GLOBAL VARIABLES
 */

char tcs3200;

/*
 * LEGACY COLOUR CODE (used in yume_tcs3200 library)
 */
//unsigned int COLOUR_NONE  = 0;
//unsigned int COLOUR_BLACK = 1;
//unsigned int COLOUR_WHITE = 2;
//unsigned int COLOUR_RED   = 3;
//unsigned int COLOUR_BLUE  = 4;
//unsigned int COLOUR_GRAY  = 5;

/*
 * YUME Ver 2.0 Colour Code (used in yume_tcs3200_receiver library)
 */
unsigned int COLUR_NONE		= 0;
unsigned int COLOUR_BLACK	= 1;
unsigned int COLOUR_GRAY	= 2;
unsigned int COLOUR_WHITE	= 3;
unsigned int COLOUR_RED	    = 4;
unsigned int COLOUR_BLUE    = 5;


unsigned int F_DETECTED_COLOUR=0;
unsigned int M_DETECTED_COLOUR=0;

float F_sum_red=0, F_sum_blue=0, F_sum_white=0,F_sum_green, F_THRESHOLD=0, F_TOTAL_SUM=0;
float M_sum_red=0, M_sum_blue=0, M_sum_white=0,M_sum_green, M_THRESHOLD=0, M_TOTAL_SUM=0;

//TCS3200 MODE
unsigned int FRONT_TCS3200 = 1;
unsigned int MID_TCS3200   = 2;

//TRACER FLAG
//unsigned int TRACER_STAT=0;
unsigned int COLOUR_STAT;
unsigned int CANDLE_CIRCLE_FLAG = 0;
unsigned int CANDLE_CIRCLE_DETECTED =1;

int F_TRACER,M_TRACER,TRACER_FLAG;

/*
 * YUME FOLLOW CARPET MACROS
 */
//unsigned int NORMAL  = 1;
//unsigned int INVERSE = 2;

/*
 *  YUME HOME AND ZONE FLAG
 */


unsigned int INITIAL_ZONE=0;
unsigned int ZONE=0;

unsigned int ZONE_BLACK = 1;
unsigned int ZONE_RED   = 2;
unsigned int ZONE_BLUE  = 3;
unsigned int TRACER     = 4;

unsigned int YUME_CROSS_MODE = 0;

//YUME START MODE
unsigned int START_MODE=0;
enum YUME_START_MODE {NON_ARBITRARY_START = 1, ARBITRARY_START = 2};


/*
 * YUME ROOM AND CORRIDOR VARIABLES
 */
unsigned int YUME_LOCATION[2]={0,0};
unsigned int LOCATION_CORRIDOR=0;
unsigned int LOCATION_ROOM=1;

/*
 * YUME FIRE FIGHTING VARIABLES
 */
unsigned int EXTINGUISHED_FIRE= 0;
unsigned int FIRE_PUTOFF=0;



/*
 * YUME ROTARY SWITCH GLOBAL VARIABLES
 */
uint16_t rot_switch_mode;

/*
 * YUME CAT OBSTACLE VARIABLES
 */
unsigned int CAT_FOUND[2]={0,0};
unsigned int CAT_SHIFT_FOLLOW=0;
unsigned int SHIFT_FOLLOW=1;
unsigned int NO_SHIFT=0;

unsigned int CAT_FLAG			= 0;
unsigned int CAT_DETECTED 		= 1;
unsigned int CAT_NOT_DETECTED 	= 0;
/*
 * YUME INFRARED PROXIMITY SENSOR
 */

int INFRARED[8];

/*
 * YUME SOUND ACTIVATION VARIABLES
 */
uint16_t YUME_Sound_Activate=0;

/*
 * YUME REGULAR ACTIVATION VARIABLES
 */
uint16_t YUME_START=0;
/*
 * YUME HAMAMATSU UV-TRON GLOBAL VARIABLES
 */
unsigned int UV_state;

unsigned int UV_Lock=0;
/*
 * YUME ROTARY SWITCH
 */
unsigned int ADCResult;

/*
 * YUME LED BLINK INTERRUPT
 */
uint16_t led_counter=1;
uint16_t led_off_counter=0;

//--------Variable TPA n Servo---------//
int DATA;
int sudut_servo=0;

//--------Variable UV tpa---------//
unsigned char sensor_UV_front=1,sensor_UV_back=1;
unsigned char sensor_UV_lock=0;
unsigned char fight=0;
unsigned char hitung=0;
unsigned int panas=0;
int regs;
int i=0, temp=0;
unsigned char suhu_ruang=0, suhu_pixel[7], pixel[10];



unsigned int FIRE=0;


//USART COMM VARIABLES
char received_string[MAX_STRLEN],buf[16],data1_lcd[16],data2_lcd[16],tampil_adc[16];
unsigned int Ping[9],USART_Count=0;
unsigned int USARTFlame_Counter=0;
unsigned int USARTFlameDigi_Counter=0;
unsigned int USART_Bluetooth_Count=0;
unsigned int COMMAND_FLAG_A = 0x3C;
unsigned int COMMAND_FLAG_B = 0x3E;
unsigned int COMMAND_COMPLETED = 0x7C;
unsigned int COMMAND_NOT_RECEIVED = 0x3F;
char command_code[5];

//SHARP IR RANGEFINDER
unsigned int SHARP[3];


//TCS3200 RAW VALUE FLAG
unsigned int RAW_VAL_FLAG = 0x52;

/*
 * YUME HEXAPOD VARIABLES
 */

uint32_t CCR1_Val, CCR2_Val, CCR3_Val;
uint32_t Count;
uint32_t nCount;

int sudut_target[18],sudut_awal[18],x=0,z_A[18],pembagi,y_A[18],sudut_tahap1[18],sudut_tahap2[18];

//float gamma[6];
int leg;
int ww[6];
float beta[6];
float leg_next[6];
float A_body;			// translasi pusat badan
float A_leg[6];			// translasi setiap pangkal kaki
float P_body;			// jarak titik pusat robot ke titik imajiner putar
int epsilon_body;		// besar sudut vektor hadap thdp vektor poros-imajiner
float phi[6];
float lambpsi[6];		//lambda / psi temporal
float P_leg[6];			// jarak titik pusat kaki ke titik imajiner putar
float epsilon[6];		// epsilon tiap N

unsigned int sudut[18]= {4915,4915,4915,4915,4915,4915,    	//3615 == 1 ms   4915 == 1,5 ms
						 4915,4915,4915,4915,4915,4915,			//6550 == 2 ms
						 4915,4915,4915,4915,4915,4915};

unsigned char y,a,b,c,d,v,index_bantu,index_servo;
uint32_t PrescalerValue;

    const float A_const[18] ={26.68,26.68,26.68,26.68,26.68,26.68,
    		 	 	 	 	  26.68,26.68,26.68,26.68,26.68,26.68,
    		 	 	 	 	  26.68,26.68,26.68,26.68,26.68,26.68
    						  /*13.33,50,13.33,13.33,50,13.33,
                              18.18,18.18,18.18,18.18,18.18,18.18,
                              18.18,18.18,18.18,18.18,18.18,18.18*/ };

    const int B_const[18]   ={2681.14,2681.14,2681.14,2681.14,2681.14,2681.14,
    						  2681.14,2681.14,2681.14,2681.14,2681.14,2681.14,
    						  2681.14,2681.14,2681.14,2681.14,2681.14,2681.14
			  	  	  	  	  /*1800,-1500,1800
							  ,1800,-1500,1800,
                              1364,1364,1364,1364,1364,1364,
                              1364,1364,1364,1364,1364,1364*/};

    //LAST REVISED BY RYAN: MON, APRIL 2nd, 2015
     float correct[18]        ={/*0,0,0,0,0,0,					0,0,0,0,0,0
			  	  	  	  	  0,0,0,0,0,0,						100,35,93,43,105,37
			  	  	  	  	  0,0,0,0,0,0						121,41,103,37,102,30*/
    							/*
    		    				* LEFT SECTION
    		    				* Coxa,Femur,Tibia
    		    				* Coxa ditambah makin ke belakang
    		    				* Femur ditambah makin turun
    		    				* Tibia ditambah makin masuk ke dalam
    		    				*
    		    				*/
    		 	 	 	 	 	39,17,92,  //FRONT LEFT LEG
//    		 	 	 	 	 	39,13,94,  //FRONT LEFT LEG
//    		 	 	 	 	 	57,13,104,  //FRONT LEFT LEG

//    		 	 	 	 	 	62,13,107,  //FRONT LEFT LEG // LAST DATA
//								27,11,107,  //FRONT LEFT LEG //
//
    		 	 	 	 	 	17,38,19,//MIDDLE LEFT LEG //
//								25,37,14,//MIDDLE LEFT LEG // LAST DATA

    		 	 	 	 	 	56,35,109,//REAR LEFT LEG //
//								28,35,109,//REAR LEFT LEG // LAST DATA

//	  	  	  					27,11,110,  //FRONT LEFT LEG //
//	  	  	  					25,22,92,//MIDDLE LEFT LEG //
//	  	  	  					13,35,112,//REAR LEFT LEG //

//			  	  	  			27,11,107,  //FRONT LEFT LEG //
//			  	  	  			25,22,90,//MIDDLE LEFT LEG //
//			  	  	  			95,35,112,//REAR LEFT LEG //

								//CALIBRATING LEFT SIDE
//								90,11,107,  //FRONT LEFT LEG //
//								25,22,90,//MIDDLE LEFT LEG //
//								-55,35,112,//REAR LEFT LEG //

            					//CALIBRATING LEFT SIDE
			  	  	  	  	  	//90,11,107,  //FRONT LEFT LEG //FIX
			  	  	  	  	  	//25,22,118,//MIDDLE LEFT LEG //FIX
			  	  	  	  	  	//-55,29,114,//REAR LEFT LEG //FIX
			  	  	  	        //95,29,114,//REAR LEFT LEG //REAR LEFT DITARIK KE BELAKANG

    							  //27,8,107,  //FRONT LEFT LEG //
    							  //25,19.5,118,//MIDDLE LEFT LEG //
    							  //15,29,114,//REAR LEFT LEG //


    		    		 	 	 /* RIGHT SECTION
    		    		 	 	 * Coxa,Femur,Tibia
    		    		 	 	 * Coxa ditambah makin ke belakang
    		    		 	 	 * Femur ditambah makin turun
    		    		 	 	 * Tibia ditambah makin masuk ke dalam
    		    		 	 	 */

    		 	 	 	 	 	 27,27,23, //FRONT RIGHT LEG //
//								 27,24,19, //FRONT RIGHT LEG // LAST DATA

    		 	 	 	 	 	 17,32,80, //MIDDLE RIGHT LEG
//								 24,27,84, //MIDDLE RIGHT LEG // LAST DATA


//								 17,26,30  //REAR RIGHT LEG // OLD TIBIA

    		 	 	 	 	 	 62,28,34,  //REAR RIGHT LEG
//								 30,26,34,  //REAR RIGHT LEG //NEW TIBIA LAST DATA

//    		    		         27,27,117, //FRONT RIGHT LEG //
//    		    		         24,20,88, //MIDDLE RIGHT LEG //
//    		    		         12,49,65  //REAR RIGHT LEG //
//    		    		         100,20,110  //REAR RIGHT LEG //

   							     //CALIBRATING RIGHT SIDE
//     		    		         95,27,117, //FRONT RIGHT LEG //
//     		    		         20,20,90 , //MIDDLE RIGHT LEG //
//     		    		         -50,20,110  //REAR RIGHT LEG //
     		    		         //100,20,104  //REAR RIGHT LEG //COXA REAR DITARIK KE BELAKANG

     		    		         //30,31,112, //FRONT RIGHT LEG //
     		    		         //20,24,123, //MIDDLE RIGHT LEG //
     		    		         //17,24,104  //REAR RIGHT LEG //
    						  };

    const float leg_1[6]	=	{8.2802,4.5,8.2802,8.2802,4.5,8.2802};	//L1
    const float leg_norm[6]	=	{9.5,9.5,9.5,9.5,9.5,9.5};				//L2
    const float alpha[6]	=	{30,90,150,30,90,150};					//alpha



float c1,c2;
float Lsem,c3,c4;
int i;
float temp_var,temp_var2;


/*
 * MPU6050 GYRO ACCELEROMETER VARIABLES
 */

unsigned int MPU6050_PWR_MGMT_1  = 0x6B;
unsigned int MPU6050_GYRO_CONFIG = 0x1B;
unsigned int MPU6050_ACCEL_CONFIG = 0x1C;
float Gyro_Mult;
//GYROSCOPE SENSITIVITY
unsigned int Gyro_Sensitivity_250s = 0x00;  /*!< Range is +- 250 degrees/s */
unsigned int Gyro_Sensitivity_500s = 0x01;  /*!< Range is +- 500 degrees/s */
const unsigned int Gyro_Sensitivity_1000s = 0x02; /*!< Range is +- 1000 degrees/s */
const unsigned int Gyro_Sensitivity_2000s = 0x03;  /*!< Range is +- 2000 degrees/s */

//ACCELEROMETER RANGE
unsigned int Accelerometer_Range = 0x00;
float Acce_Mult;

float ACCEL_DEG;
float GYRO_DEG;

/*
 * CALCULATING DISTANCE
 */
double PI = 3.1415926535897932384626433832795;
double GRAVITY = 9806.65;

float dummy_correct[18];
unsigned int TEST = 0x5A;

/*
 * YUME RUNTIME CALIBRATION VARIABLES
 */
int CALIBRATION_STAT=1;

/*
 *  YUME ROOM COUNTER
 */

unsigned int ROOM_COUNTER=0;

/*
 * YUME WARZONE FLAG
 */
unsigned int WARZONE_FLAG=0;
unsigned int SPECIAL_ZONE_FLAG=0;

/*
 * YUME HOME CIRCLE
 */
unsigned int HOME_CIRCLE_FLAG 			= 0;
unsigned int HOME_CIRCLE_DETECTED 		= 1;
unsigned int HOME_CIRCLE_NOT_DETECTED 	= 0;

/*
 * FOLLOW HOME FLAG
 */
unsigned int FOLLOWHOME_FLAG			= 0;
unsigned int FOLLOWHOME_INACTIVE		= 0;
unsigned int FOLLOWHOME_ACTIVE			= 1;


/*
 * YUME FIRE TRACKER COUNTER
 */
unsigned int firetrack_counter=0;


/*
 * YUME FOUND FIRE OVERRIDE
 */
unsigned int YUME_FOUND_FIRE_OVERRIDE=0;

/*
 * YUME EXTINGUISHER FLAG
 */
unsigned int EXTINGUISHER_FLAG=0;

/*
 * YUME ROOM 1 FLAG
 */
unsigned int ROOM1_FLAG=0;

/*
 * YUME WARZONE COUNTER
 */
unsigned int WARZONE_COUNTER=0;

/*
 * YUME GLOBAL COUNTER
 */
unsigned int global_counter=0;

/*
 * YUME CROSS_ZONE VARIABLES
 */
unsigned int YUME_CROSSING_AUTHORITY=0;
unsigned int CROSS_DISABLED=0;
unsigned int CROSS_ENABLED=1;
unsigned int YUME_CROSSING_STATUS=0;
unsigned int NO_CROSSING=0;
unsigned int CROSSING_SUCCESS=1;
unsigned int CROSSING_FAILED=2;

/*
 *  YUME STEAL ENEMY FIRE VARIABLES
 */
unsigned int STEAL_FIRE_STAT=0;
unsigned int STEAL_FIRE_COUNTER=0;
unsigned int STEALFIRE_SUCCESS=1;
unsigned int STEALFIRE_FAILED=2;
unsigned int ENEMY_ZONE_STAT=0;
unsigned int ENEMY_ZONE=1;
unsigned int COMFORT_ZONE=0;

/*
 * YUME SPECIAL_CONDITION_FLAG
 */
unsigned int SPECIAL_CONDITION_FLAG=0;
unsigned int SPECIAL_CONDITION_ENABLED=1;
unsigned int SPECIAL_CONDITION_DISABLED=0;
unsigned int SPECIAL_CONDITION_COUNTER=0;
/*
 * YUME ROOM FLAG
 */
//DEFAULT: PREVIOUS & PRESENT: OTHER ROOM
unsigned int ROOM_FLAG[2]={1,1};
unsigned int PRESENT_ROOM=0;
unsigned int PREVIOUS_ROOM=1;
unsigned int OTHER_ROOM=1;
unsigned int ROOM_ONE=2;
unsigned int WARZONE=3;

/*
 * YUME VARIABLE DOOR
 */
unsigned int VARIABLE_DOOR=0;
unsigned int VAR_DOOR_NOT_DETECTED=0;
unsigned int VAR_DOOR_DETECTED=1;
unsigned int VAR_DOOR_SCAN=2;

/*
 * FIRST CAT ENCOUNTER
 */
unsigned int FIRST_CAT_ENCOUNTER=0;


/*
 * RETURN COUNTER
 */
unsigned int RETURN_COUNTER=0;

/*
 * FOLLOW CARPET FLAG
 */
unsigned int FOLLOW_CARPET_FLAG=0;
unsigned int FOLLOW_CARPET_ENABLED=1;
unsigned int FOLLOW_CARPET_DISABLED=0;
unsigned int FOLLOW_CARPET_ESCAPE_TRAP=2;

/*
 * RETURN
 */
//unsigned int RETURN_FLAG;
//unsigned int RETURN_ENABLED;
//unsigned int RETURN_DISABLED;


/*
 * YUME ARTICULATED MANIPULATOR VARIABLES
 */

int Arm_Angle[3]={0,0,0};
int Arm_Correction[3]= {0,0,0};

uint32_t ARM_CCR1_Val, ARM_CCR2_Val, ARM_CCR3_Val;

/*
 * I2C MULTIBYTE READ
 */
uint8_t    I2C1_DATA[10];
uint8_t    I2C2_DATA[10];
uint8_t	   I2C3_DATA[10];
/*
 * CMPS11 VARIABLES
 */
/*
 *  CMPS-11 SERIAL COMMANDS
 */

unsigned int GET_VERSION 			= 0x11;
unsigned int GET_ANGLE_8_BIT 		= 0x12;
unsigned int GET_ANGLE_16_BIT		= 0x13;
unsigned int GET_PITCH 				= 0x14;
unsigned int GET_ROLL 				= 0x15;
unsigned int GET_PITCH_NO_KF 		= 0x16;
unsigned int GET_ROLL_NO_KF 		= 0x17;
unsigned int GET_MAG_RAW 			= 0x19;
unsigned int GET_ACCEL_RAW 			= 0x20;
unsigned int GET_GYRO_RAW 			= 0x21;
unsigned int GET_TEMP     		   	= 0x22;
unsigned int GET_ALL      		   	= 0x23;
unsigned int CALIBRATE_BYTE_1 	   	= 0xF0;
unsigned int CALIBRATE_BYTE_2 	   	= 0xF5;
unsigned int CALIBRATE_BYTE_3_FULL 	= 0xF6;
unsigned int CALIBRATE_BYTE_3_FLAT 	= 0xF7;
unsigned int CALIBRATE_EXIT       	= 0xF8;
unsigned int RESTORE_1             	= 0x6A;
unsigned int RESTORE_2             	= 0x7C;
unsigned int RESTORE_3             	= 0x81;
unsigned int BAUD_19200            	= 0xA0;
unsigned int BAUD_38400            	= 0xA1;

unsigned int USART2_DATA[6]={0,0,0,0,0,0};
unsigned int CMPS11_COMPASS_ANGLE =0;

/*
 * RETURN TRIP FLAG
 */
unsigned int RETURN_TRIP_FLAG=0;

/*
 * FLAME SENSOR VARIABLES
 */
unsigned int FlameSense[2]={0,0};
unsigned int FollowFlame_Flag=0,FlameTrack_Flag=0,FlameScan_Flag=0,FlameExtinguish_Flag=0,FlameApproach_Flag=0;

unsigned int FlameSenseDigi[2]={0,0};
unsigned int FlameFrontDigi[2]={0,0};

/*
 * 	YUME CONTACT BUMPER
 */
unsigned int BUMPER[2]={0,0};


/*
 * YUME TCS3200 SLAVE VARIABLES
 */

unsigned int TCS3200_SLV_CNT=0;
unsigned int TCS3200_SLV_STAT[4]={0,0,0,0};
unsigned int FRONT_PRESENT        = 0;
unsigned int FRONT_PREVIOUS       = 1;
unsigned int MIDDLE_PRESENT       = 2;
unsigned int MIDDLE_PREVIOUS      = 3;
unsigned int TCS3200_SLV_DATA[11]={0,0,0,0,0,0,0,0,0,0,0};
unsigned int DUMMY_DATA_A= 0x41;
unsigned int DUMMY_DATA_G= 0x47;

unsigned int TCS3200_CMD_CODE[5]={0,0,0,0,0};

const int TCS_CALIBRATE_WHITE           = 0x46;
const int TCS_CALIBRATE_BLACK           = 0x47;
const int TCS_CALIBRATE_GRAY            = 0x48;
const int TCS_CALIBRATE_GETRULE         = 0x49;

const int TCS_FRONT_SHOW_THRESHOLD      = 0x4A;
const int TCS_MIDDLE_SHOW_THRESHOLD     = 0x4B;

unsigned int TRIAL_MODE			= 0x41;
unsigned int CALIBRATION_MODE	= 0x42;

//unsigned int CALIBRATE_BLACK    = 0x43;
//unsigned int CALIBRATE_GRAY     = 0x44;
//unsigned int CALIBRATE_WHITE	= 0x45;

unsigned int START_BUTTON_CMD	= 0x53;
unsigned int BUTTON_A			= 0x41;
unsigned int BUTTON_B			= 0x42;
unsigned int CMD_COMPLETED		= 0x58;
unsigned int CMD_IDLE			= 0x5E;

//SENT COMMAND DATA
//unsigned int TCS_CMD_SEND_FRONT  	 = 0x41;
//unsigned int TCS_CMD_SEND_MIDDLE 	 = 0x42;
unsigned int TCS_CMD_SEND_RAW		 = 0x41;
unsigned int TRACER_CMD_SEND_RAW	 = 0x42;
unsigned int TCS_CMD_SEND_CONCLUSION = 0x43;
unsigned int TCS_CMD_SAVE_EEPROM     = 0x5A;


unsigned int HYBRID_CMD_SEND_THRESHOLD    = 0x58;


/*
 *  PHOTODIODE TRACER CALIBRATION COMMAND
 */

//BLACK/WHITE PHOTODIODE TRACER PROCESSOR COMMAND
const int TRACER_CALIBRATE_GRAY             = 0x4A;
const int TRACER_CALIBRATE_WHITE            = 0x4B;
const int TRACER_CALIBRATE_GETRULE          = 0x4C;

//RECEIVED DATA
unsigned int RCV_IDLE  		= 94;
unsigned int RCV_START 		= 53;
unsigned int RCV_BUTTON_A 	= 41;
unsigned int RCV_BUTTON_B	= 42;



/*
 * ROOM IDENTIFIER VARIABLES
 */

unsigned int HOME;

//ROOM[0] == DUMMY DATA / UNUSED
unsigned int ROOM[6]={99,13,13,13,13,13};

unsigned int HALLWAY_SC = 0;

unsigned int ROOM_1A 	= 1;
unsigned int ROOM_1B	= 2;
unsigned int ROOM_1C	= 3;

unsigned int ROOM_2A 	= 4;
unsigned int ROOM_2B	= 5;

unsigned int ROOM_3 	= 6;

unsigned int ROOM_4A 	= 7;
unsigned int ROOM_4B	= 8;





unsigned int ROOM_TYPE		= 0;
unsigned int NORMAL_ROOM	= 1;
unsigned int GRAY_ROOM 		= 2;


/*
 * TRACER DETECTED IN BUMPER HANDLER ROUTINES
 */
unsigned int TRACER_IN_BUMPER;
unsigned int TRC_BMP_ACTIVE=1;
unsigned int TRC_BMP_INACTIVE=0;

/*
 * TRACER STATUS VARIABLES
 */
unsigned int TRACER_STAT=0;
unsigned int TRACER_ACTIVE=1;
unsigned int TRACER_INACTIVE=0;

/*
 * FOLLOW TRACER FLAG VARIABLES
 */
unsigned int FOLLOWTRACER_FLAG=0;
unsigned int FOLLOWTRACER_ENABLE=1;
unsigned int FOLLOWTRACER_DISABLE=0;

/*
 * FLAME SENSOR VARIABLES
 */

unsigned int FLAME_SENSOR[2];

/*
 * MOV FLAME SENSOR SIDE
 */
unsigned int FLAME_SIDE;

/*
 * CANDLE STATUS
 */
unsigned int CANDLE_STICK=0;
unsigned int CANDLE_FIRE=0;
unsigned int CANDLE_STAT=0;


/*
 *  ROOM 2 FLAG
 */
unsigned int ROOM1_FLAG;
unsigned int ROOM1FLAG_ACTIVE=1;
unsigned int ROOM1FLAG_INACTIVE=0;

/*
 * ROOM 4A FLAG
 */
unsigned int ROOM4A_FLAG;
unsigned int ROOM4AFLAG_ACTIVE=1;
unsigned int ROOM4AFLAG_INACTIVE=0;

/*
 * ROOM1A SPECIAL EXIT FLAG
 */
unsigned int ROOM1A_SP_EXIT_FLAG;
unsigned int ROOM1A_SP_EXIT_FLAG_ACTIVE=1;
unsigned int ROOM1A_SP_EXIT_FLAG_INACTIVE=0;

/*
 * ROOM4A CAT AVOIDER
 */
unsigned int ROOM4A_CAT_AVOIDER;
unsigned int ROOM4A_CAT_AVOIDER_ACTIVE = 1;
unsigned int ROOM4A_CAT_AVOIDER_INACTIVE = 0;


/*
 * SPECIAL ROUTE FOR RETURN TRIP R2 TO R4A
 * HOME: R4A
 * FIRE ROOM: R2
 * CAT CONFIG: A
 */
unsigned int R2TO4A_SP_ROUTE=0;
unsigned int R2TO4A_SP_ACTIVE=1;
unsigned int R2TO4A_SP_INACTIVE=0;


/*
 * CAT SHIFT ALGORITHM FLAG
 */
unsigned int SHIFT_ALGORITHM_FLAG;
unsigned int SHIFT_ALGORITHM_ACTIVE=1;
unsigned int SHIFT_ALGORITHM_INACTIVE=0;


/*
 *  DEFLECT WALL OVERFLOW COUNTER
 */

int RIGHT_OVERFLOW_COUNTER=0;
int LEFT_OVERFLOW_COUNTER=0;

/*
 *  YUME TURNAROUND NAVIGATION
 */
unsigned int TURN_LEFT  = 1;
unsigned int TURN_RIGHT = 2;
