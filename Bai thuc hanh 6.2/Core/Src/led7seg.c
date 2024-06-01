#include "main.h"
#include "led7seg.h"

uint8_t hex7seg[16] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};

void print_7seg(unsigned int number){
	read_Hex_1_Byte(hex7seg[number]);
}

void read_Hex_1_Byte(unsigned int hexCode){
  for(int i = 0; i < 8; i++) { //Lay bit tu vi tri ben trai qua phai(MSB --> LSB)
		if((hexCode & 0x80) == 0x80) PORT_DATA->BSRR = PIN_DATA;
			else PORT_DATA->BSRR = PIN_DATA<<16u; //Lay bit trong so cao nhat(MSB) trong 1 byte
    PORT_CLOCK->BSRR = PIN_CLOCK;
    PORT_CLOCK->BSRR = PIN_CLOCK<<16u;
    hexCode = hexCode << 1; //Dich trai de lay bit o vi tri ke tiep
  }
	PORT_LATCH->BSRR = PIN_LATCH;
	PORT_LATCH->BSRR = PIN_LATCH<<16u;
}
