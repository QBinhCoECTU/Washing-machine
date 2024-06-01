#include "wash.h"
#include "EOS.h"
#include "led7seg.h"
#include "keypad.h"

static system_state current_state = INIT; //initial state 
static unsigned char Detergent[10] = {1,1,0,0,0,1,0,1,1,0};
static unsigned char Heat[10] = {1,0,1,0,0,1,0,1,1,0};
static unsigned int wash_mode = 0;
static unsigned int time_in_state = 0; // time (s) in each state
unsigned int x = 0;
void WASHER_Update(void) // Call once per second by EOS_ISR
{
x++;//Dem thoi gian state
switch (current_state) {
		case INIT:
		{
			INIT_ON;
			DRAIN2_OFF;
			MO_CUA;
			VALVE_OFF;
			MOTOR_OFF;
			switch(keyscanEOS()){
				case 0: { wash_mode = 0;	break;}
				case 1: { wash_mode = 1;	break;}
				case 2: { wash_mode = 2;	break;}
				case 3: { wash_mode = 3;	break;}
				case 4: { wash_mode = 4;	break;}
				case 5: { wash_mode = 5;	break;}
				case 6: { wash_mode = 6;	break;}
				case 7: { wash_mode = 7;	break;}
				case 8: { wash_mode = 8;	break;}
				case 9: { wash_mode = 9;	break;}
			}
			print_7seg(wash_mode);
			if((GPIOA->IDR&GPIO_PIN_3) == 0) //BUTTON_START
			{
				current_state = START;
				x = 0; // reset bien dem, bat dau dem len 1s
			}
			break;
		}
		case START:
		{
			if(x == 200) //dem vua du 1s
			{
				START_ON
				INIT_OFF
				KHOA_CUA
				VALVE_ON
				if (Detergent[wash_mode] == 1) BOT_GIAT_ON
				current_state = FILL1;
				x=0;
				time_in_state = 0;
			}
			break;
		}
		case FILL1:{
			if(x == 200) //counter 1s
			{
				x=0;
				time_in_state++;
				FILL1_ON;
				START_OFF;
				BOT_GIAT_OFF;
			}
			if(time_in_state >= MAX_FILL_DURATION) {current_state = ERR; x = 0;time_in_state=0;}
			if((GPIOA->IDR&GPIO_PIN_4) == 0){
				VALVE_OFF;
				if(Heat[wash_mode]==1){
					current_state = HEAT;
					time_in_state = 0;
					x = 0;
				} else {
					current_state = WASH;
					time_in_state = 0;
					x = 0;
				}
			}
			break;
		}
		case HEAT:
		{
			if(x == 200) //dem vua du 1s
			{
				x=0;
				time_in_state++;
				HEAT_ON
				FILL1_OFF
				DUN_NUOC_ON
			}
			if(time_in_state >= MAX_HEAT_DURATION) {current_state = ERR; x = 0;time_in_state=0;}
			if((GPIOA->IDR&GPIO_PIN_6) == 0) //SENSOR_TEMP
			{
				DUN_NUOC_OFF;
				current_state = WASH;
				time_in_state=0;
				x = 0;
			}
			break;
		}
		case WASH:
		{
			if(x == 200) //dem vua du 1s
			{
				x=0;
				time_in_state++;
				WASH_ON;
				FILL1_OFF;
				HEAT_OFF;
				MOTOR_ON;
			}
			if(time_in_state >= 20) //Thoi gian quay motor long giat (20s)
			{
				MOTOR_OFF;
				current_state = DRAIN1;
				x = 0;
				time_in_state = 0;
			}
			break;
		}
		case DRAIN1:
		{
			if(x == 200) //dem vua du 1s
			{
				x=0;
				time_in_state++;
				DRAIN1_ON;
				WASH_OFF;
				BOM_NUOC_ON;
			}
			if(time_in_state >= MAX_DRAIN_DURATION) {current_state = ERR; x = 0; time_in_state=0;}
			if((GPIOA->IDR&GPIO_PIN_5) == 0) //OUT_OF_WATER
			{
				BOM_NUOC_OFF;
				current_state = FILL2;
				x = 0;
			}
			break;
		}
		//---------------------------------------------------------
		case FILL2:{
			if(x == 200) //dem vua du 1s
			{
				x=0;
				time_in_state++;
				FILL2_ON;
				DRAIN1_OFF;
				VALVE_ON;
			}
			if(time_in_state >= MAX_FILL_DURATION) {current_state = ERR; x = 0;time_in_state=0;}
			if((GPIOA->IDR&GPIO_PIN_4) == 0){ //SENSOR_TEMP
				VALVE_OFF;
				current_state = RINSE;
				time_in_state = 0;
				x = 0;
			}
			break;
		}
		//---------------------------------------------------------
		case RINSE:
			{
			if(x == 200) //dem vua du 1s
			{
				x=0;
				time_in_state++;
				RINSE_ON;
				FIlL2_OFF;
				MOTOR_ON;
			}
			if(time_in_state >= 20) //Thoi gian quay motor long giat de xa do (20)
			{
				MOTOR_OFF;
				current_state = DRAIN2;
				x = 0;
				time_in_state = 0;
			}
			break;
		}
		case DRAIN2:
		{
			if(x == 200) //dem vua du 1s
			{
				x=0;
				time_in_state++;
				DRAIN2_ON;
				RINSE_OFF;
				BOM_NUOC_ON;
			}if(time_in_state >= MAX_DRAIN_DURATION) {current_state = ERR; x = 0;time_in_state=0;}
			if((GPIOA->IDR&GPIO_PIN_5) == 0) //OUT_OF_WATER
			{
				BOM_NUOC_OFF;
				current_state = INIT;
				x = 0;
				time_in_state=0;
			}
			break;
		}
		case ERR:
		{
			ERR_ON;
			BOM_NUOC_OFF;
			VALVE_OFF;
			DUN_NUOC_OFF;
			break;
		}
	}
}
