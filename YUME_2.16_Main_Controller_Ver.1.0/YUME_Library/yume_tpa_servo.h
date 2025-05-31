/*==============================================================================================
								  PROJECT YUME Ver.1.0
							THERMOPHILE ARRAY AND SERVO LIBRARY
==============================================================================================*/
#ifndef YUME_TPA_SERVO_H
#define YUME_TPA_SERVO_H

//Linking Global Libraries
#include "main.h"
#include "yume_hexapod_cmd.h"


#define PWM_servo 	TIM12->CCR2
#define PWM4_Servo	TIM4->CCR1

//aktivasi i2c
#define MPU_ACTIVE_MODE 1

extern unsigned char sensor_UV_lock;
extern unsigned char fight;
extern unsigned char hitung;
extern unsigned int panas;
extern int regs;
extern int i, temp;
extern unsigned char suhu_ruang, suhu_pixel[7], pixel[10];
extern int DATA;
extern unsigned int FIRE;

//SERVO CONTROLLER SPEED PARAMETER
extern unsigned int SPEED_SLOW ;
extern unsigned int SPEED_MED  ;
extern unsigned int SPEED_FAST ;



//SERVO CONTROLLER STEP PARAMETER
extern unsigned int STEP_NARROW ;
extern unsigned int STEP_FAR    ;



//I2C
void Setup_I2C();
void Write_I2C(int Address, int Register, int Data);
void Read_I2C(int Address, int Register);


//TPA Servo
void TIM12_PWM_Configuration(void);
void Set_Servo(int sudut);

unsigned char YUME_TPA_Check(char val_or_flag);unsigned char YUME_TPA_Check(char val_or_flag);
//TPA Init
void YUME_Thermopile_Init(void);
unsigned char YUME_TPA_Check(char val_or_flag);
void Get_TPA81(void);

//YUME Search Fire Sequences
//unsigned int YUME_Search_Fire(void);

extern uint8_t    I2C1_DATA[];
//--------------------------------------------------------------
// MultiByte defines
//--------------------------------------------------------------
#define    I2C1_MULTIBYTE_MAX   10
extern uint8_t    I2C1_DATA[];

#define ALPHA 0.5

//--------------------------------------------------------------
// I2C TIMEOUT Defines
//--------------------------------------------------------------
#define   I2C1_TIMEOUT     0x3000


#define TPA81_ADDRESS					0xD0 //Default CMPS-11 DEVICE ADDRESS
#define TPA81_TEMPERATURE				0x01
#define TPA81_REQUESTED_BYTE			9

#endif
