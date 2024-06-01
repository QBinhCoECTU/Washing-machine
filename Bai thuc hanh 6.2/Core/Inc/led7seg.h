#ifndef  __LED7SEG_H__
#define  __LED7SEG_H__

#include "main.h"

#define PORT_CLOCK 	GPIOA
#define PORT_DATA 	GPIOA
#define PORT_LATCH 	GPIOA

#define PIN_CLOCK 	GPIO_PIN_12
#define PIN_DATA		GPIO_PIN_11
#define PIN_LATCH 	GPIO_PIN_13

void LED_7SEG_Write_Byte(uint16_t hex);
void print_7seg(unsigned int num);
void read_Hex_1_Byte(unsigned int hexCode);

#endif
