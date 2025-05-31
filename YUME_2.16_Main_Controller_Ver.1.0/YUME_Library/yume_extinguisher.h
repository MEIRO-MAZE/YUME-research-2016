/*========================================================================================
								   PROJECT YUME 2.16 Ver.1.0
								  YUME Hydro Extinguisher Library
==============================================================================================*/
#ifndef YUME_EXTINGUISHER_H
#define YUME_EXTINGUISHER_H

#include "main.h"
/*
 * YUME BUZZER
 */
#define RCC_AHB1Periph_EXTINGUISHER RCC_AHB1Periph_GPIOB
#define EXTINGUISHER_PORT GPIOB
#define EXTINGUISHER_PIN GPIO_Pin_15
#define EXTINGUISHER_ON GPIO_ResetBits (EXTINGUISHER_PORT, EXTINGUISHER_PIN);
#define EXTINGUISHER_OFF GPIO_SetBits(EXTINGUISHER_PORT, EXTINGUISHER_PIN);


void YUME_Extinguisher_Init(void);
void Pump_GPIOInit(void);
extern uint16_t YUME_START;

#endif
