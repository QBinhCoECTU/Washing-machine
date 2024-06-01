#ifndef __WASH_H__
#define __WASH_H__

#include "main.h"

#define MOTOR_ON 			GPIOA->BSRR = GPIO_PIN_14;
#define MOTOR_OFF 		GPIOA->BSRR = GPIO_PIN_14<<16u;
#define KHOA_CUA 			GPIOA->BSRR = GPIO_PIN_15;
#define MO_CUA				GPIOA->BSRR = GPIO_PIN_15<<16u;
#define DUN_NUOC_ON 	GPIOB->BSRR = GPIO_PIN_0;
#define DUN_NUOC_OFF	GPIOB->BSRR = GPIO_PIN_0<<16u;
#define VALVE_ON 			GPIOB->BSRR = GPIO_PIN_1;
#define VALVE_OFF 		GPIOB->BSRR = GPIO_PIN_1<<16;
#define BOM_NUOC_ON 	GPIOB->BSRR = GPIO_PIN_2;
#define BOM_NUOC_OFF 	GPIOB->BSRR = GPIO_PIN_2<<16u;
#define BOT_GIAT_ON 	GPIOB->BSRR = GPIO_PIN_3;
#define BOT_GIAT_OFF 	GPIOB->BSRR = GPIO_PIN_3<<16u;

//================LED các trang thai hien tai===============
#define INIT_ON 		GPIOB->BSRR = GPIO_PIN_4;
#define INIT_OFF 		GPIOB->BSRR = GPIO_PIN_4<<16u;
#define START_ON 		GPIOB->BSRR = GPIO_PIN_5;
#define START_OFF		GPIOB->BSRR = GPIO_PIN_5<<16u;
#define FILL1_ON 		GPIOB->BSRR = GPIO_PIN_6;
#define FILL1_OFF 	GPIOB->BSRR = GPIO_PIN_6<<16u;
#define HEAT_ON 		GPIOB->BSRR = GPIO_PIN_7;
#define HEAT_OFF 		GPIOB->BSRR = GPIO_PIN_7<<16u;
#define WASH_ON 		GPIOB->BSRR = GPIO_PIN_8;
#define WASH_OFF 		GPIOB->BSRR = GPIO_PIN_8<<16u;
#define DRAIN1_ON 	GPIOB->BSRR = GPIO_PIN_9;
#define DRAIN1_OFF 	GPIOB->BSRR = GPIO_PIN_9<<16u;
#define FILL2_ON 		GPIOB->BSRR = GPIO_PIN_10;
#define FIlL2_OFF 	GPIOB->BSRR = GPIO_PIN_10<<16u;
#define RINSE_ON 		GPIOB->BSRR = GPIO_PIN_11;
#define RINSE_OFF 	GPIOB->BSRR = GPIO_PIN_11<<16u;
#define DRAIN2_ON 	GPIOB->BSRR = GPIO_PIN_12;
#define DRAIN2_OFF 	GPIOB->BSRR = GPIO_PIN_12<<16u;
#define ERR_ON 			GPIOB->BSRR = GPIO_PIN_13;
#define ERR_OFF 		GPIOB->BSRR = GPIO_PIN_13<<16u;	
//===================================================

typedef enum {INIT,START,FILL1,HEAT,WASH,DRAIN1,FILL2,RINSE,DRAIN2,ERR} system_state;
#define MAX_FILL_DURATION  20		
#define MAX_HEAT_DURATION  20		
#define MAX_DRAIN_DURATION 20		

void WASHER_Update(void);
#endif
