#include "main.h"
#include "keypad.h"
#include "led7seg.h"

int key;
int kq;
int keybuf[3]={255,255,255};
int keyscanEOS(void);
int keyscanEOS(void){
	int key = keyPad4x3(); //Read keypad
	keybuf[0] = keybuf[1]; //Store data
  keybuf[1] = keybuf[2];
	keybuf[2] = key;
	if ((keybuf[0] == keybuf[1])&&(keybuf[2] == 255)) kq = keybuf[0];
	return kq;
}

int keyPad4x3(){
	key = 255; //no key pressed
	//-------------------------------------------------------------------------------
	KEYPAD_PORT->BSRR = H1_PIN<<16u|H2_PIN|H3_PIN|H4_PIN; //Quet hang 1
	/*Hang 1 - Cot 1*/
	if((KEYPAD_PORT->IDR&C1_PIN)==0) key = 1;
	/*Hang 1 - Cot 2*/
	if((KEYPAD_PORT->IDR&C2_PIN)==0) key = 2;
	/*Hang 1 - Cot 3*/
	if((KEYPAD_PORT->IDR&C3_PIN)==0) key = 3;
	//-------------------------------------------------------------------------------
	KEYPAD_PORT->BSRR = H1_PIN|H2_PIN<<16u|H3_PIN|H4_PIN; //Quet hang 2
	/*Hang 2 - Cot 1*/
	if((KEYPAD_PORT->IDR&C1_PIN)==0) key = 4;
	/*Hang 2 - Cot 2*/
	if((KEYPAD_PORT->IDR&C2_PIN)==0) key = 5;
	/*Hang 2 - Cot 3*/
	if((KEYPAD_PORT->IDR&C3_PIN)==0) key = 6;
	//-------------------------------------------------------------------------------
	KEYPAD_PORT->BSRR = H1_PIN|H2_PIN|H3_PIN<<16u|H4_PIN; //Quet hang 3
		/*Hang 3 - Cot 1*/
	if((KEYPAD_PORT->IDR&C1_PIN)==0) key = 7;
	/*Hang 3 - Cot 2*/
	if((KEYPAD_PORT->IDR&C2_PIN)==0) key = 8;
	/*Hang 3 - Cot 3*/
	if((KEYPAD_PORT->IDR&C3_PIN)==0) key = 9;
	//-------------------------------------------------------------------------------
	KEYPAD_PORT->BSRR = H1_PIN|H2_PIN|H3_PIN|H4_PIN<<16u; //Quet hang 4
		/*Hang 4 - Cot 1*///Nút *
	if((KEYPAD_PORT->IDR&C1_PIN)==0) key = 10;
	/*Hang 4 - Cot 2*/
	if((KEYPAD_PORT->IDR&C2_PIN)==0) key = 0;
	/*Hang 4 - Cot 3*///Nut #
	if((KEYPAD_PORT->IDR&C3_PIN)==0) key = 11;
	return key;
}
