/*==============================================================================================
								 	 PROJECT YUME Ver.1.0
								  	 USER INTERFACE LIBRARY
==============================================================================================*/



#ifndef YUME_USER_INTERFACE_H
#define YUME_USER_INTERFACE_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "yume_macro_lib.h"
//#include "yume_global_var.h"
#include <yume_systick_delay.h>

/*
 * YUME START BUTTON
 */
#define RCC_AHB1Periph_BUTTON RCC_AHB1Periph_GPIOA
#define BUTTON_PORT GPIOA
#define BUTTON_PIN GPIO_Pin_1
#define YUME_BUTTON_INPUT GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)
#define YUME_BUTTON_CLICKED GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==1
#define YUME_BUTTON_UNCLICKED   GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)==0




void Button_Init(void);

void StartButton_Init(void);
void UserButton_Init(void);

void FIRE_LED_Init(void);
void YUME_LED_Interrupt_Init(void);


/*
 * YUME USER BUTTON
 */
//USER BUTTON A
#define RCC_AHB1Periph_USERBUTTON_A 	RCC_AHB1Periph_GPIOE
#define USERBUTTON_A_PORT 				GPIOE
#define USERBUTTON_A_PIN 				GPIO_Pin_2
#define BUTTON_A_INPUT 					GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)
#define BUTTON_A_CLICKED 				GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==1
#define BUTTON_A_UNCLICKED   			GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==0

//USER BUTTON B
#define RCC_AHB1Periph_USERBUTTON_B 	RCC_AHB1Periph_GPIOA
#define USERBUTTON_B_PORT 				GPIOA
#define USERBUTTON_B_PIN 				GPIO_Pin_10
#define BUTTON_B_INPUT 					GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)
#define BUTTON_B_CLICKED 				GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)==1
#define BUTTON_B_UNCLICKED   			GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)==0

#define BUTTON_IDLE (YUME_BUTTON_INPUT|BUTTON_A_INPUT|BUTTON_B_INPUT)==0


/*
 * YUME BUZZER
 */
#define RCC_AHB1Periph_BUZZER 			RCC_AHB1Periph_GPIOD
#define BUZZER_PORT 					GPIOD
#define BUZZER_PIN 						GPIO_Pin_13
#define BUZZ_ON 						GPIO_SetBits(BUZZER_PORT, BUZZER_PIN);
#define BUZZ_OFF 						GPIO_ResetBits (BUZZER_PORT, BUZZER_PIN);


void Buzzer_Init(void);
void YUME_Buzz(int counter);

/*
 * YUME LED
 */
#define RCC_AHB1Periph_LED RCC_AHB1Periph_GPIOD
#define LED_PORT 	GPIOD
#define LED_PIN 	GPIO_Pin_13

#define YUME_LED_ON GPIO_SetBits(LED_PORT, LED_PIN);
#define YUME_LED_OFF GPIO_ResetBits(LED_PORT, LED_PIN);

#define YUME_LED_BLINK_ON TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
#define YUME_LED_BLINK_OFF TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);
void LED_Init(void);

/*
 * YUME FIRE INDICATOR LED (RED LED)
 */
#define RCC_AHB1Periph_FIRE_LED RCC_AHB1Periph_GPIOD
#define FIRE_LED_PORT GPIOD
#define FIRE_LED_PIN GPIO_Pin_14

#define FIRE_LED_ON GPIO_SetBits(FIRE_LED_PORT, FIRE_LED_PIN);
#define FIRE_LED_OFF GPIO_ResetBits(FIRE_LED_PORT, FIRE_LED_PIN);

#define FIRE_LED_BLINK_ON TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
#define FIRE_LED_BLINK_OFF TIM_ITConfig(TIM5, TIM_IT_Update, DISABLE);

/*
 * YUME SOUND ACTIVATION INDICATOR (BLUE LED)
 */
#define RCC_AHB1Periph_SND_ACT_LED 	RCC_AHB1Periph_GPIOD
#define SND_ACT_LED_PORT 			GPIOD
#define SND_ACT_LED_PIN 			GPIO_Pin_15

#define SND_ACT_LED_ON 	GPIO_SetBits(SND_ACT_LED_PORT, SND_ACT_LED_PIN);
#define SND_ACT_LED_OFF GPIO_ResetBits(SND_ACT_LED_PORT, SND_ACT_LED_PIN);

/*
 * YUME SOUND ACTIVATION INDICATOR (BLUE LED)
 */
#define RCC_AHB1Periph_SND_ACT_LED 	RCC_AHB1Periph_GPIOD
#define SND_ACT_LED_PORT 			GPIOD
#define SND_ACT_LED_PIN 			GPIO_Pin_15

#define SND_ACT_LED_ON 	GPIO_SetBits(SND_ACT_LED_PORT, SND_ACT_LED_PIN);
#define SND_ACT_LED_OFF GPIO_ResetBits(SND_ACT_LED_PORT, SND_ACT_LED_PIN);

/*
 * YUME COMPUTER VISION INDICATOR (GREEN LED)
 */
#define RCC_AHB1Periph_COMVISION_LED 	RCC_AHB1Periph_GPIOD
#define COMVISION_LED_PORT 				GPIOD
#define COMVISION_LED_PIN 				GPIO_Pin_13

#define COMVISION_LED_ON 	GPIO_SetBits(COMVISION_LED_PORT, COMVISION_LED_PIN);
#define COMVISION_LED_OFF 	GPIO_ResetBits(COMVISION_LED_PORT, COMVISION_LED_PIN);


extern uint16_t led_counter;
extern uint16_t led_off_counter;
extern unsigned int UV_state;;
extern unsigned int UV_Lock;


#endif
