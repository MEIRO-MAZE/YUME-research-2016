/*==============================================================================================
								 PROJECT YUME Ver.1.0
								  	 MAIN LIBRARY
==============================================================================================*/

#ifndef MAIN_H
#define MAIN_H

/*
 * YUME STANDARD LIBRARY
 */
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_i2c.h"
#include "misc.h"
#include "math.h"


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"


//-------------------------------------KRPAI Library-------------------------------------------//
//#include "delay.h"
//#include "lcd.h"

//ESSENTIAL GLOBALLY
#include <yume_macro_lib.h>
#include <yume_global_var.h>
#include <yume_systick_delay.h>

//USER INTERFACES
#include <yume_user_interface.h>
#include <yume_rotary_switch.h>
#include <yume_lcd.h>

//COLOUR AND LINE SENSOR
//#include <yume_tracer_decoder.h>
#include <yume_tcs3200.h>

//YUME SOUND ACTIVATION
#include "yume_sound_activation.h"

//ULTRASONIC/SONAR AND INFRARED PROXIMITY SENSOR
#include <yume_infrared_proximity.h>

//CONTACT BUMPER
#include "yume_bumper.h"

//FLAME SENSOR AND THERMOPHILE ARRAY
#include <yume_UV-TRON.h>
#include <yume_tpa_servo.h>

//BRUSHLESS DC FAN
#include <yume_bldc_fan.h>

//Hydro Pump Extinguisher
#include "yume_extinguisher.h"

#include "yume_ping_variables.h"
#include "yume_pid_var.h"
//OTHER
//#include <yume_easy_init.h>

//YUME PING))) RECEIVER
#include "yume_ping_receiver.h"

//YUME HEXAPOD COMMAND
#include "yume_hexapod_cmd.h"

//YUME USART COMMUNICATION
#include "yume_usart_comm.h"

//YUME MPU6050 IMU
//#include "yume_mpu6050.h"
//#include "yume_gy_85.h"
#include "yume_cmps11.h"

//PID CONTROLLER
#include <yume_pid_controller.h>

//YUME UTILITIES
#include "yume_utilities.h"

//YUME DYNAMIXEL XL-320
#include "yume_dynamixel_xl_320.h"

//YUME ARTICULATED MANIPULATOR
//#include "yume_articulated_manipulator.h"

//YUME SHARP INFRARED SENSOR
#include "yume_sharp_ir.h"

//YUME I2C LCD
//#include "yume_i2c_lcd.h";

#include "yume_algorithm.h"
#include "yume2016_algorithm.h"

//YUME ADDITIONAL FLAME SENSOR SIDE
#include "yume_flame_sensor.h"

//Global Typedef
GPIO_InitTypeDef  			GPIO_InitStructure, GPIO_I2C,GPIO_InitStructure;
I2C_InitTypeDef  			I2C_InitStructure;
TIM_TimeBaseInitTypeDef     TIM_TimeBaseStructure;
TIM_OCInitTypeDef           TIM_OCInitStructure;

#define YUME_MODE_DEFAULT 0
#define YUME_MODE_1 1
#define YUME_MODE_2 2
#define YUME_MODE_3 3
#define YUME_MODE_4 4
#define YUME_MODE_5 5
#define YUME_MODE_6 6


extern unsigned int YUME_LOCATION[];
extern unsigned int LOCATION_CORRIDOR;
extern unsigned int LOCATION_ROOM;
#define PRESENT_LOC 0
#define LAST_LOC 1


extern unsigned int INITIAL_ZONE;
extern unsigned int ZONE;

extern unsigned int ZONE_BLACK;
extern unsigned int ZONE_RED;
extern unsigned int ZONE_BLUE;
extern unsigned int TRACER;
extern unsigned int FIRE_PUTOFF;

extern unsigned int COLOUR_STAT;

extern unsigned int ZONE;
extern unsigned int ZONE_RED;
extern unsigned int ZONE_BLUE;

/*
 * YUME FOLLOW CARPET VARIABLES
 */
//extern unsigned int NORMAL;
//extern unsigned int INVERSE;

/*
 * YUME CAT COLLISION SHIFT FOLLOW
 */
extern unsigned int CAT_SHIFT_FOLLOW;
extern unsigned int SHIFT_FOLLOW;
extern unsigned int NO_SHIFT;

extern uint16_t led_off_counter;

/*
 * YUME CROSS_ZONE VARIABLES
 */
extern unsigned int YUME_CROSSING_AUTHORITY;
extern unsigned int CROSS_DISABLED;
extern unsigned int CROSS_ENABLED;
extern unsigned int YUME_CROSSING_STATUS;
extern unsigned int NO_CROSSING;
extern unsigned int CROSSING_SUCCESS;
extern unsigned int CROSSING_FAILED;


/*
 * YUME SOUND SCAN
 */
#define SOUND_SCAN   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)


//CARPET CODE
extern unsigned int COLOUR_NONE;
extern unsigned int COLOUR_BLACK;
extern unsigned int COLOUR_GRAY;
extern unsigned int COLOUR_WHITE;
extern unsigned int COLOUR_RED;
extern unsigned int COLOUR_BLUE;


//FIRE FLAG
extern unsigned int FIRE;

#endif
